package main

import (
	"fmt"
)

const mod = 998244353
const K = 18

type Mint struct {
	n int
}

func NewMint(n int) Mint {
	return Mint{n: n}
}

func (m Mint) Negate() Mint {
	if m.n != 0 {
		return Mint{n: mod - m.n}
	}
	return Mint{n: 0}
}

func (m Mint) Increment() Mint {
	m.n++
	if m.n == mod {
		m.n = 0
	}
	return m
}

func (m Mint) Decrement() Mint {
	m.n--
	if m.n < 0 {
		m.n = mod - 1
	}
	return m
}

func (m *Mint) Subtract(rhs Mint) {
	if m.n >= rhs.n {
		m.n -= rhs.n
	} else {
		m.n = mod - (rhs.n - m.n)
	}
}

func (m *Mint) Add(rhs Mint) {
	m.n += rhs.n
	if m.n >= mod {
		m.n -= mod
	}
}

func (m *Mint) Multiply(rhs Mint) {
	m.n = (m.n * rhs.n) % mod
}

func (m *Mint) Divide(rhs Mint) {
	m.n = (m.n * rhs.Inverse().n) % mod
}

func (m Mint) Equal(rhs Mint) bool {
	return m.n == rhs.n
}

func (m Mint) NotEqual(rhs Mint) bool {
	return m.n != rhs.n
}

func (m Mint) Pow(n int) Mint {
	r := NewMint(1)
	x := m
	for n > 0 {
		if n&1 == 1 {
			r.Multiply(x)
		}
		x.Multiply(x)
		n >>= 1
	}
	return r
}

func (m Mint) Inverse() Mint {
	return m.Pow(mod - 2)
}

type Poly struct {
	c []Mint
}

func NewPoly(n int) Poly {
	c := make([]Mint, n+1)
	return Poly{c: c}
}

func (p Poly) Degree() int {
	return len(p.c) - 1
}

func (p Poly) At(n int) Mint {
	if n < len(p.c) {
		return p.c[n]
	}
	return NewMint(0)
}

func (p *Poly) Add(rhs Poly) {
	if rhs.Degree() > p.Degree() {
		d := make([]Mint, rhs.Degree()+1)
		copy(d, p.c)
		for i := 0; i <= p.Degree(); i++ {
			d[i].Add(rhs.c[i])
		}
		p.c = d
	} else if rhs.Degree() < p.Degree() {
		for i := 0; i <= rhs.Degree(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	} else {
		for i := 0; i <= p.Degree(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	}
}

func (p *Poly) Subtract(rhs Poly) {
	if rhs.Degree() > p.Degree() {
		d := make([]Mint, rhs.Degree()+1)
		copy(d, p.c)
		for i := 0; i <= p.Degree(); i++ {
			d[i].Subtract(rhs.c[i])
		}
		p.c = d
	} else if rhs.Degree() < p.Degree() {
		for i := 0; i <= rhs.Degree(); i++ {
			p.c[i].Subtract(rhs.c[i])
		}
	} else {
		for i := 0; i <= p.Degree(); i++ {
			p.c[i].Subtract(rhs.c[i])
		}
	}
}

func (p *Poly) Multiply(rhs Poly) {
	if p.Degree() < 0 || rhs.Degree() < 0 {
		p.c = make([]Mint, 0)
		return
	}
	rdeg := p.Degree() + rhs.Degree()
	k := 32 - clz(rdeg)
	if k > K+1 {
		k = K + 1
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= p.Degree(); i++ {
		d[i] = p.c[i]
	}
	for i := 0; i <= rhs.Degree(); i++ {
		e[i] = rhs.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Multiply(e[i])
	}
	ifft(d, k)
	p.c = make([]Mint, rdeg+1)
	im := NewMint((mod + 1) / 2).Pow(k)
	for i := 0; i <= rdeg; i++ {
		p.c[i] = d[i].Multiply(im)
	}
}

func (p Poly) AddPoly(rhs Poly) Poly {
	r := p
	r.Add(rhs)
	return r
}

func (p Poly) SubtractPoly(rhs Poly) Poly {
	r := p
	r.Subtract(rhs)
	return r
}

func (p Poly) MultiplyPoly(rhs Poly) Poly {
	r := p
	r.Multiply(rhs)
	return r
}

func (p Poly) ModPoly(rhs Poly) Poly {
	r := p
	r.Mod(rhs)
	return r
}

func (p *Poly) Mod(rhs Poly) {
	if rhs.Degree() > p.Degree() {
		return
	}
	if rhs.Degree() < 32 {
		dQ := rhs.Degree()
		for dQ > 0 && rhs.c[dQ].Equal(NewMint(0)) {
			dQ--
		}
		if rhs.c[dQ].Equal(NewMint(0)) {
			p.c = make([]Mint, 0)
			return
		}
		for i := p.Degree(); i >= dQ; i-- {
			if p.c[i].Equal(NewMint(0)) {
				continue
			}
			x := p.c[i].Divide(rhs.c[dQ])
			p.c[i] = NewMint(0)
			for j := 1; j <= dQ; j++ {
				p.c[i-j].Subtract(x.Multiply(rhs.c[dQ-j]))
			}
		}
		dP := dQ - 1
		for dP >= 0 && p.c[dP].Equal(NewMint(0)) {
			dP--
		}
		p.c = p.c[:dP+1]
		return
	}
	P := p.Quotient(rhs)
	k := 32 - clz(p.Degree())
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= p.Degree(); i++ {
		d[i] = p.c[i]
	}
	for i := 0; i <= rhs.Degree(); i++ {
		e[i] = rhs.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Multiply(e[i])
	}
	ifft(d, k)
	im := NewMint((mod + 1) / 2).Pow(k)
	dP := -1
	for i := 0; i < rhs.Degree(); i++ {
		d[i] = p.c[i].Subtract(d[i].Multiply(im))
		if !d[i].Equal(NewMint(0)) {
			dP = i
		}
	}
	p.c = p.c[:dP+1]
}

func (p Poly) Log() Poly {
	n := p.Degree()
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	c := make([]Mint, 1<<k)
	ee := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = NewMint(0)
	r.c[1] = p.c[1].Inverse()
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := NewMint(mod - y)
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(ee, i+1)
		for j := 0; j < 1<<i; j++ {
			ee[j] = ee[j].Multiply(im)
		}
		for j := 0; j < 1<<(i+1); j++ {
			c[j] = p.c[j].Subtract(ee[j].Multiply(ee[j]).Multiply(ee[j]))
		}
		ifft(c, i+1)
		for j := 1 << i; j < min(1<<(i+1), n+1); j++ {
			r.c[j] = c[j].Multiply(im)
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	return r
}

func (p Poly) Exp() Poly {
	n := p.Degree()
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	c := make([]Mint, 1<<k)
	ee := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = NewMint(1)
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := NewMint(y)
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(ee, i+1)
		for j := 0; j < 1<<i; j++ {
			ee[j] = ee[j].Multiply(im)
		}
		for j := 0; j < 1<<(i+1); j++ {
			c[j] = p.c[j].Subtract(ee[j])
		}
		ifft(c, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(ee, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			c[j] = c[j].Multiply(ee[j])
		}
		ifft(c, i+1)
		for j := 0; j < 1<<i; j++ {
			r.c[j+(1<<i)] = c[j].Multiply(im)
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	return r
}

func (p Poly) Quotient(Q Poly) Poly {
	dP := p.Degree()
	for dP >= 0 && p.c[dP].Equal(NewMint(0)) {
		dP--
	}
	if p.c[dP].Equal(NewMint(0)) {
		return NewPoly(0)
	}
	dQ := Q.Degree()
	for dQ >= 0 && Q.c[dQ].Equal(NewMint(0)) {
		dQ--
	}
	if Q.c[dQ].Equal(NewMint(0)) {
		return NewPoly(0)
	}
	if dQ > dP {
		return NewPoly(0)
	}
	RQ := NewPoly(min(dQ, dP-dQ))
	for j := 0; j <= min(dQ, dP-dQ); j++ {
		RQ.c[j] = Q.c[dQ-j]
	}
	k := 32 - clz(dP - dQ)
	if k > K+1 {
		k = K + 1
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= dP-dQ; i++ {
		d[i] = p.c[dP-i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Multiply(e[i])
	}
	ifft(d, k)
	p.c = make([]Mint, dP-dQ+1)
	im := NewMint((mod + 1) / 2).Pow(k)
	for i := 0; i <= dP-dQ; i++ {
		p.c[i] = d[i].Multiply(im)
	}
	return p
}

func (p Poly) Inverse() Poly {
	dP := p.Degree()
	for dP >= 0 && p.c[dP].Equal(NewMint(0)) {
		dP--
	}
	if p.c[dP].Equal(NewMint(0)) {
		return p
	}
	n := dP
	k := 32 - clz(n)
	c := make([]Mint, 1<<k)
	ee := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = p.c[0].Inverse()
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := NewMint(mod - y)
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(ee, i+1)
		for j := 0; j < 1<<i; j++ {
			ee[j] = ee[j].Multiply(im)
		}
		for j := 0; j < 1<<(i+1); j++ {
			c[j] = p.c[j].Subtract(ee[j])
		}
		ifft(c, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(ee, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			c[j] = c[j].Multiply(ee[j])
		}
		ifft(c, i+1)
		for j := 0; j < 1<<i; j++ {
			r.c[j+(1<<i)] = c[j].Multiply(im)
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	return r
}

func clz(x int) int {
	if x == 0 {
		return 32
	}
	return 31 - (31 ^ (x-1))
}

func fft(a []Mint, k int) {
	u := 1
	v := 1 << (k - 1)
	for i := k; i > 0; i-- {
		for jh := 0; jh < u; jh++ {
			wj := w[jh]
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := wj.Multiply(a[j+v])
				a[j+v] = a[j].Subtract(Ajv)
				a[j] = a[j].Add(Ajv)
			}
		}
		u <<= 1
		v >>= 1
	}
}

func ifft(a []Mint, k int) {
	u := 1 << (k - 1)
	v := 1
	for i := 1; i <= k; i++ {
		for jh := 0; jh < u; jh++ {
			wj := y[jh]
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := a[j].Subtract(a[j+v])
				a[j] = a[j].Add(a[j+v])
				a[j+v] = wj.Multiply(Ajv)
			}
		}
		u >>= 1
		v <<= 1
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	hs := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&hs[i])
	}

	cnt := 0
	for i := 0; i < n; i++ {
		if hs[i] == hs[(i+1)%n] {
			cnt++
		}
	}

	if cnt == n {
		fmt.Println(0)
		return
	}

	A := NewPoly(2e5 + 1000)
	A.c[0] = NewMint(1)
	A.c[1] = NewMint((k - 2) % mod)
	A.c[2] = NewMint(1)

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Multiply(NewMint(n - cnt))
	}

	C := B.Exp()

	ans := NewMint(k % mod).Pow(n - cnt)
	for i := 0; i <= n-cnt; i++ {
		ans = ans.Subtract(C.c[i])
	}

	ans = ans.Multiply(NewMint(k % mod).Pow(cnt))
	fmt.Println(ans.n)
}
