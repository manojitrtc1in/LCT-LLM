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

func (m Mint) Neg() Mint {
	if m.n != 0 {
		return Mint{mod - m.n}
	}
	return Mint{0}
}

func (m Mint) Inc() Mint {
	m.n++
	if m.n == mod {
		m.n = 0
	}
	return m
}

func (m Mint) Dec() Mint {
	m.n--
	if m.n < 0 {
		m.n = mod - 1
	}
	return m
}

func (m *Mint) Sub(rhs Mint) {
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

func (m *Mint) Mul(rhs Mint) {
	m.n = (m.n * rhs.n) % mod
}

func (m *Mint) Div(rhs Mint) {
	m.n = (m.n * rhs.Inv().n) % mod
}

func (m Mint) Eq(rhs Mint) bool {
	return m.n == rhs.n
}

func (m Mint) Neq(rhs Mint) bool {
	return m.n != rhs.n
}

func (m Mint) Pow(n int) Mint {
	r := Mint{1}
	x := m
	for n > 0 {
		if n&1 == 1 {
			r.Mul(x)
		}
		x.Mul(x)
		n >>= 1
	}
	return r
}

func (m Mint) Inv() Mint {
	return m.Pow(mod - 2)
}

type Poly struct {
	c []Mint
}

func NewPoly(n int) Poly {
	return Poly{c: make([]Mint, n+1)}
}

func (p Poly) Deg() int {
	return len(p.c) - 1
}

func (p Poly) At(n int) Mint {
	if n < len(p.c) {
		return p.c[n]
	}
	return Mint{0}
}

func (p *Poly) Add(rhs Poly) {
	if rhs.Deg() > p.Deg() {
		d := make([]Mint, rhs.Deg()+1)
		for i := 0; i <= p.Deg(); i++ {
			d[i] = p.c[i]
		}
		p.c = d
	} else if rhs.Deg() < p.Deg() {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	} else {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	}
}

func (p *Poly) Sub(rhs Poly) {
	if rhs.Deg() > p.Deg() {
		d := make([]Mint, rhs.Deg()+1)
		for i := 0; i <= p.Deg(); i++ {
			d[i] = p.c[i]
		}
		p.c = d
	} else if rhs.Deg() < p.Deg() {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Sub(rhs.c[i])
		}
	} else {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Sub(rhs.c[i])
		}
	}
}

func (p *Poly) Mul(rhs Poly) {
	if p.Deg() < 0 || rhs.Deg() < 0 {
		p.c = make([]Mint, 0)
		return
	}
	rdeg := p.Deg() + rhs.Deg()
	k := 32 - clz(rdeg)
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= p.Deg(); i++ {
		d[i] = p.c[i]
	}
	for i := 0; i <= rhs.Deg(); i++ {
		e[i] = rhs.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	p.c = make([]Mint, rdeg+1)
	im := Mint{(mod + 1) / 2}.Pow(k)
	for i := 0; i <= rdeg; i++ {
		p.c[i] = d[i].Mul(im)
	}
}

func (p *Poly) Div(rhs Poly) {
	if rhs.Deg() > p.Deg() {
		return
	}
	if rhs.Deg() < 32 {
		dQ := rhs.Deg()
		for dQ > 0 && rhs.c[dQ].Eq(Mint{0}) {
			dQ--
		}
		if rhs.c[dQ].Eq(Mint{0}) {
			return
		}
		for i := p.Deg(); i >= dQ; i-- {
			if p.c[i].Eq(Mint{0}) {
				continue
			}
			x := p.c[i].Div(rhs.c[dQ])
			p.c[i] = Mint{0}
			for j := 1; j <= dQ; j++ {
				p.c[i-j].Sub(x.Mul(rhs.c[dQ-j]))
			}
		}
		dP := dQ - 1
		for dP >= 0 && p.c[dP].Eq(Mint{0}) {
			dP--
		}
		p.c = p.c[:dP+1]
		return
	}
	P := p.Quotient(rhs)
	k := 32 - clz(p.Deg())
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= p.Deg()-rhs.Deg(); i++ {
		d[i] = p.c[i]
	}
	for i := 0; i <= rhs.Deg(); i++ {
		e[i] = rhs.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	im := Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < rhs.Deg(); i++ {
		dR = i
		p.c[i] = p.c[i].Sub(d[i].Mul(im))
	}
	p.c = p.c[:dR+1]
}

func (p Poly) Quotient(Q Poly) Poly {
	if Q.Deg() < 0 {
		return p
	}
	if p.Deg() < 0 {
		return Poly{}
	}

	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return Poly{}
	}

	dQ := Q.Deg()
	for dQ >= 0 && Q.c[dQ].Eq(Mint{0}) {
		dQ--
	}
	if Q.c[dQ].Eq(Mint{0}) {
		return Poly{}
	}
	if dQ > dP {
		return Poly{}
	}
	RQ := NewPoly(min(dQ, dP-dQ))
	for j := 0; j <= min(dQ, dP-dQ); j++ {
		RQ.c[j] = Q.c[dQ-j]
	}

	k := 32 - clz(dP - dQ)
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= dP-dQ; i++ {
		d[i] = p.c[dP-i]
	}
	RQ = RQ.Inv(dP - dQ)

	for i := 0; i <= dP-dQ; i++ {
		e[i] = RQ.c[i]
	}
	fft(d, k)
	fft(e, k)

	d = mul(d, e, k)

	ifft(d, k)
	im := Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < dP-dQ; i++ {
		dR = i
		p.c[i] = d[dP-dQ-i].Mul(im)
	}
	p.c = p.c[:dR+1]
	return p
}

func (p Poly) Log() Poly {
	if p.c[0].Eq(Mint{1}) {
		return Poly{}
	}
	k := 32 - clz(p.Deg())
	B := NewPoly(1 << k)
	B.c[1] = Mint{(mod - 2) % mod}
	B.c[2] = Mint{1}

	B = B.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{p.Deg()})
	}

	C := B.Exp()
	ans := Mint{mod}.Pow(p.Deg())
	for i := 0; i <= p.Deg(); i++ {
		ans = ans.Sub(C.c[i])
	}

	ans = ans.Mul(Mint{mod}.Pow(p.Deg()))
	return Poly{c: []Mint{ans}}
}

func (p Poly) Exp() Poly {
	if p.c[0].Eq(Mint{0}) {
		return Poly{c: []Mint{Mint{1}}}
	}
	k := 32 - clz(p.Deg())
	A := NewPoly(2e5 + 1000)
	A.c[0] = Mint{1}
	A.c[1] = Mint{(k - 2) % mod}
	A.c[2] = Mint{1}

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{p.Deg()})
	}

	C := B.Exp()

	ans := Mint{mod}.Pow(p.Deg())
	for i := 0; i <= p.Deg(); i++ {
		ans = ans.Sub(C.c[i])
	}

	ans = ans.Mul(Mint{mod}.Pow(p.Deg()))
	return Poly{c: []Mint{ans}}
}

func (p Poly) Inv(n int) Poly {
	if p.c[0].Eq(Mint{0}) {
		return Poly{}
	}
	if n == -1 {
		n = p.Deg()
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	d := make([]Mint, 1<<k)
	ee := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = p.c[0].Inv()
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := Mint{mod - y}
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			ee[j] = r.c[j]
		}
		fft(d, i+1)
		fft(ee, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			d[j].Mul(ee[j])
		}
		ifft(d, i+1)
		for j := 0; j < 1<<i; j++ {
			d[j] = d[j+(1<<i)]
			d[j+(1<<i)] = Mint{0}
		}
		fft(d, i+1)
		for j := 0; j < 1<<(i+1); j++ {
			d[j].Mul(ee[j])
		}
		ifft(d, i+1)
		for j := 1 << i; j < min(1<<(i+1), n+1); j++ {
			r.c[j] = d[j].Mul(im)
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

func (p Poly) Sqrt(n int) Poly {
	if p.c[0].Eq(Mint{1}) {
		return Poly{c: []Mint{Mint{1}}}
	}
	if n == -1 {
		n = p.Deg()
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	g := NewPoly((1 << k) - 1)
	d := make([]Mint, 1<<(k+1))
	ee := make([]Mint, 1<<(k+1))
	r := NewPoly(n)
	r.c[0] = Mint{1}
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := Mint{mod - y}
	for i := 0; i < k; i++ {
		for j := 0; j < 1<<(i+1); j++ {
			d[j] = p.c[j]
		}
		fft(d, i+2)
		for j := 0; j < 1<<i; j++ {
			ee[j] = r.c[j]
		}
		for j := 0; j < 1<<(i+1); j++ {
			ee[j+(1<<i)] = Mint{0}
		}
		fft(ee, i+2)
		for j := 0; j < 1<<(i+2); j++ {
			d[j].Mul(ee[j].Mul(ee[j]))
		}
		ifft(d, i+2)
		for j := 1 << (i + 1); j < min(1<<(i+2), n+1); j++ {
			g.c[j] = d[j].Mul(im)
		}

		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	g = g.Inv(n)
	d = make([]Mint, 1<<k)
	ee = make([]Mint, 1<<k)
	for i := 0; i < min(1<<k, p.Deg()+1); i++ {
		g.c[i] = p.c[i]
	}
	for i := 0; i < min(1<<k, p.Deg()); i++ {
		d[i] = (i + 1) * p.c[i+1]
	}
	g = g.Inv(n)
	fft(d, k)
	fft(g.c, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(g.c[i])
	}
	ifft(d, k)
	im = Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < min(1<<k, p.Deg()); i++ {
		dR = i
		r.c[i] = d[i].Sub(d[i+(1<<k)].Mul(im))
	}
	r.c = r.c[:dR+1]
	return r
}

func (p Poly) Eval(x Mint) Mint {
	r := Mint{0}
	for i := p.Deg(); i >= 0; i-- {
		r.Mul(x)
		r.Add(p.c[i])
	}
	return r
}

func (p Poly) Eval2(P []Mint) []Mint {
	m := len(P)
	if m <= 1<<_ls {
		v := make([]Mint, m)
		for i := 0; i < m; i++ {
			v[i] = p.Eval(P[i])
		}
		return v
	}
	k := 32 - clz(m-1)
	T := genTree(P)
	A := NewPoly(1 << k)
	for i := 0; i <= 1<<k; i++ {
		A.c[i] = T[1].c[(1<<k)-i]
	}
	B := A.Inv(p.Deg())
	v := make([]Mint, m)
	for i := 0; i < m; i++ {
		v[i] = p.Eval(P[i])
	}
	return tuptree(B, T, v)
}

func (p Poly) Interpolation(a, b []Mint) Poly {
	m := len(a)
	if len(b) != m {
		panic("length of a and b must be the same")
	}
	if m == 0 {
		return Poly{}
	}
	k := 32 - clz(m-1)
	T := genTree(a)
	B := NewPoly(1 << k)
	for i := 0; i < m; i++ {
		B.c[i] = b[i]
	}
	fft(B.c, k)
	for i := 0; i < 1<<k; i++ {
		B.c[i].Mul(T[1].c[i])
	}
	ifft(B.c, k)
	return uptree(B.c, T)
}

func (p Poly) Quotient2(Q Poly) Poly {
	if Q.Deg() < 0 {
		return p
	}
	if p.Deg() < 0 {
		return Poly{}
	}

	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return Poly{}
	}

	dQ := Q.Deg()
	for dQ >= 0 && Q.c[dQ].Eq(Mint{0}) {
		dQ--
	}
	if Q.c[dQ].Eq(Mint{0}) {
		return Poly{}
	}
	if dQ > dP {
		return Poly{}
	}
	RQ := NewPoly(min(dQ, dP-dQ))
	for j := 0; j <= min(dQ, dP-dQ); j++ {
		RQ.c[j] = Q.c[dQ-j]
	}

	k := 32 - clz(dP - dQ)
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= dP-dQ; i++ {
		d[i] = p.c[dP-i]
	}
	RQ = RQ.Inv(dP - dQ)

	for i := 0; i <= dP-dQ; i++ {
		e[i] = RQ.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	im := Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < dP-dQ; i++ {
		dR = i
		p.c[i] = p.c[i].Sub(d[i].Mul(im))
	}
	p.c = p.c[:dR+1]
	return p
}

func (p *Poly) ModEq(Q Poly) {
	if Q.Deg() > p.Deg() {
		return
	}
	if Q.Deg() < 32 {
		dQ := Q.Deg()
		for dQ > 0 && Q.c[dQ].Eq(Mint{0}) {
			dQ--
		}
		if Q.c[dQ].Eq(Mint{0}) {
			return
		}
		for i := p.Deg(); i >= dQ; i-- {
			if p.c[i].Eq(Mint{0}) {
				continue
			}
			x := p.c[i].Div(Q.c[dQ])
			p.c[i] = Mint{0}
			for j := 1; j <= dQ; j++ {
				p.c[i-j].Sub(x.Mul(Q.c[dQ-j]))
			}
		}
		dP := dQ - 1
		for dP >= 0 && p.c[dP].Eq(Mint{0}) {
			dP--
		}
		p.c = p.c[:dP+1]
		return
	}
	P := p.Quotient2(Q)
	k := 32 - clz(p.Deg())
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= p.Deg()-Q.Deg(); i++ {
		d[i] = p.c[i]
	}
	for i := 0; i <= Q.Deg(); i++ {
		e[i] = Q.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	im := Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < p.Deg()-Q.Deg(); i++ {
		dR = i
		p.c[i] = d[i].Mul(im)
	}
	p.c = p.c[:dR+1]
}

func clz(x int) int {
	if x == 0 {
		return 32
	}
	return 31 - __builtin_clz(x)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func fft(a []Mint, k int) {
	u := 1
	v := 1 << (k - 1)
	for i := k; i > 0; i-- {
		for jh := 0; jh < u; jh++ {
			wj := Mint{a[jh]}
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := wj.Mul(a[j+v])
				a[j+v] = a[j].Sub(Ajv)
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
			wj := Mint{a[jh]}
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := a[j].Sub(a[j+v])
				a[j] = a[j].Add(a[j+v])
				a[j+v] = wj.Mul(Ajv)
			}
		}
		u >>= 1
		v <<= 1
	}
}

func genTree(P []Mint) []Poly {
	m := len(P)
	k := 32 - clz(m-1)
	T := make([]Poly, 1<<(k+1))
	FT := make([][]Mint, 1<<(k+1))
	w := make([]Mint, 1<<_ls)
	w[1] = Mint{1}
	fft(w, _ls)
	if _ls == 0 {
		w[0] = Mint{1}
	}

	for i := 0; i < 1<<(k-_ls); i++ {
		t := (1 << (k - _ls)) + i
		T[t] = NewPoly(1<<_ls + 1)
		T[t].c[1<<_ls] = Mint{1}
		for j := 0; j < 1<<_ls; j++ {
			T[t].c[j] = Mint{1}
			for l := 0; l < 1<<_ls; l++ {
				T[t].c[j].Mul(w[j].Sub(Mint{P[(i<<_ls)+l]}))
			}
			T[t].c[j].Sub(Mint{1})
		}
	}

	im := Mint{(mod + 1) / 2}.Pow(_ls)
	for i := _ls + 1; i <= k; i++ {
		for j := 0; j < 1<<(k-i); j++ {
			t := (1 << (k - i)) + j
			T[t] = NewPoly(1<<i + 1)
			T[t].c[1<<i] = Mint{1}

			FT[2*t] = make([]Mint, 1<<i)
			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t][l] = T[2*t].c[l].Add(Mint{1})
			}
			ifft(T[2*t].c, i-1)
			for l := 0; l < 1<<(i-1); l++ {
				T[2*t].c[l].Mul(im)
			}

			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t][(1<<(i-1))+l] = T[2*t].c[l].Mul(fft.v[l<<(K-i+1)])
			}
			FT[2*t][1<<(i-1)].Dec()
			fft(FT[2*t][(1<<(i-1)):], i-1)

			FT[2*t+1] = make([]Mint, 1<<i)
			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t+1][l] = T[2*t+1].c[l].Add(Mint{1})
			}
			ifft(T[2*t+1].c, i-1)
			for l := 0; l < 1<<(i-1); l++ {
				T[2*t+1].c[l].Mul(im)
			}

			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t+1][(1<<(i-1))+l] = T[2*t+1].c[l].Mul(fft.v[l<<(K-i+1)])
			}
			FT[2*t+1][1<<(i-1)].Dec()
			fft(FT[2*t+1][(1<<(i-1)):], i)

			for l := 0; l < 1<<i; l++ {
				T[t].c[l] = FT[2*t][l].Mul(FT[2*t+1][l]).Sub(Mint{1})
			}
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
		im.n += mod
		im.n /= 2
	}
	ifft(T[1].c, k)
	FT[1] = make([]Mint, 1<<k)
	for l := 0; l < 1<<k; l++ {
		FT[1][l] = T[1].c[l].Mul(im)
	}
	return T
}

func uptree(C []Mint, T []Poly) Poly {
	m := len(C)
	k := 32 - clz(m-1)
	C = append(C, make([]Mint, 1<<(k+1)-m)...)
	for i := 0; i < m; i++ {
		T[i] = Poly{c: []Mint{C[i]}}
	}
	for i := k; i > 0; i-- {
		for j := (1 << (k - i)) - 1; j >= 0; j-- {
			n := (1 << (i - 1)) - 1
			T[2*j+1] = middleProduct(n, T[(1<<(k-i+1))+2*j], T[2*j])
			T[2*j] = middleProduct(n, T[(1<<(k-i+1))+2*j+1], T[2*j+1])
		}
	}
	return T[0]
}

func tuptree(B Poly, T []Poly, v []Mint) []Mint {
	m := len(v)
	k := 32 - clz(m-1)
	C := make([]Poly, 1<<k)
	C[0] = B
	for i := k; i > 0; i-- {
		for j := (1 << (k - i)) - 1; j >= 0; j-- {
			n := (1 << (i - 1)) - 1
			C[2*j+1] = middleProduct(n, T[(1<<(k-i+1))+2*j], C[j])
			C[2*j] = middleProduct(n, T[(1<<(k-i+1))+2*j+1], C[j])
		}
	}
	r := make([]Mint, m)
	for i := 0; i < m; i++ {
		r[i] = C[i].c[0]
	}
	return r
}

func middleProduct(n int, lhs, rhs Poly) Poly {
	dl := lhs.Deg()
	for dl >= 0 && lhs.c[dl].Eq(Mint{0}) {
		dl--
	}
	if rhs.Deg() > n+dl {
		return Poly{}
	}
	k := 32 - clz(dl+n)
	P := NewPoly(1 << k)
	for i := 0; i <= dl; i++ {
		P.c[i] = lhs.c[dl-i]
	}
	for i := 0; i <= rhs.Deg(); i++ {
		P.c[i].Mul(rhs.c[i])
	}
	return P
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
	A.c[0] = Mint{1}
	A.c[1] = NewMint(k-2).n % mod
	A.c[2] = Mint{1}

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(NewMint(n - cnt).n)
	}

	C := B.Exp()

	ans := NewMint(k).Pow(n - cnt)
	for i := 0; i <= n-cnt; i++ {
		ans.Sub(C.c[i])
	}

	ans.Mul(NewMint(k).Pow(cnt))
	fmt.Println(ans.n)
}
