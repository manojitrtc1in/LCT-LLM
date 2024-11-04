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
	return Poly{c: make([]Mint, n+1)}
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
		for i := 0; i <= p.Degree(); i++ {
			d[i] = p.c[i]
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
		for i := 0; i <= p.Degree(); i++ {
			d[i] = p.c[i]
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
		for dQ >= 0 && rhs.c[dQ].Equal(NewMint(0)) {
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
	v := (1 << k) - 1
	A := middleProduct(v, B, *p)
	B.c = B.c[:v+1]
	for i := 0; i <= v; i++ {
		B.c[i] = A.c[v-i]
	}
}

func (p Poly) Log() Poly {
	n := p.Degree()
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	B := p
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Multiply(NewMint(n))
	}
	B.c = B.c[:n+1]
	B.c = B.c[1:]
	B.c = append(B.c, NewMint(0))
	B = B.Inverse(n)
	v := (1 << k) - 1
	A := middleProduct(v, B, p)
	B.c = B.c[:v+1]
	for i := 0; i <= v; i++ {
		B.c[i] = A.c[v-i]
	}
	return B
}

func (p Poly) Exp() Poly {
	n := p.Degree()
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	B := NewPoly(1 << k)
	B.c[0] = NewMint(1)
	B.c[1] = NewMint(n)
	B.c[2] = NewMint(1)
	B = B.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Multiply(NewMint(n))
	}
	B.c = B.c[:n+1]
	B = B.Exp()
	ans := NewMint(n).Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Subtract(B.c[i])
	}
	ans = ans.Multiply(NewMint(n).Pow(n))
	return ans
}

func (p Poly) Quotient(Q Poly) Poly {
	if Q.Degree() < 0 {
		return p
	}
	if p.Degree() < 0 {
		return p
	}

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
	v := (1 << k) - 1
	A := middleProduct(v, RQ, p)
	B := A.Inverse(dP - dQ)
	A = middleProduct(v, B, *p)
	B.c = B.c[:v+1]
	for i := 0; i <= v; i++ {
		B.c[i] = A.c[v-i]
	}

	return B
}

func (p *Poly) Modulo(rhs Poly) {
	if rhs.Degree() > p.Degree() {
		return
	}
	if rhs.Degree() < 32 {
		dQ := rhs.Degree()
		for dQ >= 0 && rhs.c[dQ].Equal(NewMint(0)) {
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
	v := (1 << k) - 1
	A := middleProduct(v, B, *p)
	B.c = B.c[:v+1]
	for i := 0; i <= v; i++ {
		B.c[i] = A.c[v-i]
	}
}

func (p Poly) Inverse(n int) Poly {
	if p.c[0].Equal(NewMint(0)) {
		return p
	}
	if n == -1 {
		n = p.Degree()
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	d := make([]Mint, 1<<k)
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
			d[j] = r.c[j]
			d[j] = d[j].Multiply(im)
		}
		fft(d, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			d[j] = d[j].Multiply(ee[j])
		}
		ifft(d, i+1)
		for j := 1 << i; j < min(1<<(i+1), n+1); j++ {
			r.c[j] = d[j].Multiply(im)
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

func (p Poly) Isqrt(n int) Poly {
	if p.c[0].Equal(NewMint(1)) {
		return p
	}
	if n == -1 {
		n = p.Degree()
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
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
	im := NewMint(mod - y)
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			r.c[j] = p.c[j]
		}
		fft(r.c, i+2)
		for j := 0; j < 1<<(i+1); j++ {
			r.c[j] = r.c[j].Multiply(im)
		}
		fft(r.c, i+2)
		for j := 0; j < 1<<(i+2); j++ {
			r.c[j] = r.c[j].Multiply(r.c[j])
		}
		ifft(r.c, i+2)
		for j := 1 << (i + 1); j < min(1<<(i+2), n+1); j++ {
			r.c[j] = r.c[j].Multiply(im)
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	return r
}

func (p Poly) Sqrt(n int) Poly {
	if n == -1 {
		n = p.Degree()
	}
	if n == -1 {
		return p
	}
	if p.c[0].Equal(NewMint(1)) {
		if n == 0 {
			r := NewPoly(0)
			r.c[0] = NewMint(1)
			return r
		}
		k := 32 - clz(n)
		g := NewPoly((1 << (k - 1)) - 1)
		d := make([]Mint, 1<<k)
		e := make([]Mint, 1<<(k-1))
		f := make([]Mint, 1<<k)
		gg := make([]Mint, 1<<k)
		for i := 0; i < min(1<<(k-1), p.Degree()+1); i++ {
			g.c[i] = p.c[i]
		}
		g = g.Isqrt()
		for i := 0; i < 1<<(k-1); i++ {
			gg[i] = g.c[i]
		}
		fft(gg, k)
		for i := 0; i < 1<<k; i++ {
			f[i] = gg[i]
		}
		im := NewMint((mod + 1) / 2).Pow(k)
		for i := 0; i < 1<<k; i++ {
			gg[i] = gg[i].Multiply(f[i]).Multiply(f[i]).Multiply(f[i])
		}
		ifft(gg, k)
		for i := 1 << (k - 1); i < min(1<<k, n+1); i++ {
			g.c[i] = gg[i].Multiply(im)
		}
		return g
	}
	if p.c[0].Equal(NewMint(0)) {
		return p
	}
	n = p.Degree()
	k := 32 - clz(n)
	g := NewPoly((1 << (k - 1)) - 1)
	d := make([]Mint, 1<<(k+1))
	for i := 0; i < min(1<<(k-1), p.Degree()+1); i++ {
		g.c[i] = p.c[i]
	}
	for i := 1; i <= k; i++ {
		for j := 0; j < 1<<(k-i); j++ {
			t := (1 << (k - i)) + j
			g.c[t] = NewMint(1)
			for l := 0; l < 1<<i; l++ {
