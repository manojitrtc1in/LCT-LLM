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
		copy(d, p.c)
		for i := 0; i <= p.Deg(); i++ {
			d[i].Add(rhs.c[i])
		}
		p.c = d
	} else if rhs.Deg() < p.Deg() {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	} else {
		for i := 0; i <= p.Deg(); i++ {
			p.c[i].Add(rhs.c[i])
		}
	}
}

func (p *Poly) Sub(rhs Poly) {
	if rhs.Deg() > p.Deg() {
		d := make([]Mint, rhs.Deg()+1)
		copy(d, p.c)
		for i := 0; i <= p.Deg(); i++ {
			d[i].Sub(rhs.c[i])
		}
		p.c = d
	} else if rhs.Deg() < p.Deg() {
		for i := 0; i <= rhs.Deg(); i++ {
			p.c[i].Sub(rhs.c[i])
		}
	} else {
		for i := 0; i <= p.Deg(); i++ {
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
	if k > K+1 {
		k = K + 1
	}
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

func (p Poly) AddPoly(rhs Poly) Poly {
	r := p
	r.Add(rhs)
	return r
}

func (p Poly) SubPoly(rhs Poly) Poly {
	r := p
	r.Sub(rhs)
	return r
}

func (p Poly) MulPoly(rhs Poly) Poly {
	r := p
	r.Mul(rhs)
	return r
}

func (p Poly) ModPoly(rhs Poly) Poly {
	r := p
	r.Mod(rhs)
	return r
}

func (p *Poly) Mod(rhs Poly) {
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
	if k > K+1 {
		k = K + 1
	}
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
	im := Mint{(mod + 1) / 2}.Pow(k)
	dR := -1
	for i := 0; i < rhs.Deg(); i++ {
		d[i] = p.c[i].Sub(d[i].Mul(im))
		if !d[i].Eq(Mint{0}) {
			dR = i
		}
	}
	p.c = p.c[:dR+1]
}

func (p Poly) Log() Poly {
	n := p.Deg()
	if n < 0 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{0}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.LogPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.ExpPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) Exp() Poly {
	n := p.Deg()
	if n < 0 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{1}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.ExpPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.LogPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) Quotient(Q Poly) Poly {
	if Q.Deg() < 0 {
		return p
	}
	if p.Deg() < 0 {
		return p
	}
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return NewPoly(0)
	}
	dQ := Q.Deg()
	for dQ >= 0 && Q.c[dQ].Eq(Mint{0}) {
		dQ--
	}
	if Q.c[dQ].Eq(Mint{0}) {
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
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= dP-dQ; i++ {
		d[i] = p.c[dP-i]
	}
	RQ = RQ.InvPoly(dP - dQ)
	for i := 0; i <= dP-dQ; i++ {
		e[i] = RQ.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	p.c = make([]Mint, dP-dQ+1)
	im := Mint{(mod + 1) / 2}.Pow(k)
	for i := 0; i <= dP-dQ; i++ {
		p.c[i] = d[dP-dQ-i].Mul(im)
	}
	return p
}

func (p Poly) Inv(n int) Poly {
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return p
	}
	if n == -1 {
		n = dP
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = p.c[0].Inv()
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := Mint{mod - y}
	for i := 0; i < k; i++ {
		for jh := 0; jh < 1<<i; jh++ {
			wj := w[jh]
			for j := jh << i; j < jh<<i+1<<i; j++ {
				Ajv := wj.Mul(p.c[j+1])
				p.c[j+1] = p.c[j].Sub(Ajv)
				p.c[j] = p.c[j].Add(Ajv)
			}
		}
		u <<= 1
		v >>= 1
	}
	return r
}

func (p Poly) Isqrt(n int) Poly {
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return p
	}
	if n == -1 {
		n = dP
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k+1)
	e := make([]Mint, 1<<k+1)
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
		for jh := 0; jh < 1<<i; jh++ {
			wj := y[jh]
			for j := jh << i; j < jh<<i+1<<i; j++ {
				Ajv := p.c[j].Sub(p.c[j+1])
				p.c[j+1] = p.c[j].Add(p.c[j+1])
				p.c[j] = wj.Mul(Ajv)
			}
		}
		u >>= 1
		v <<= 1
	}
	return r
}

func (p Poly) Sqrt(n int) Poly {
	if n == -1 {
		n = p.Deg()
	}
	if n == -1 {
		return p
	}
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if dP < 0 {
		return NewPoly(0)
	}
	if dP == 0 {
		r := NewPoly(n)
		r.c[0] = Mint{1}
		return r
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{1}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.SqrtPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.LogPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) LogPoly() Poly {
	n := p.Deg()
	if n < 0 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{0}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.LogPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.ExpPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) ExpPoly() Poly {
	n := p.Deg()
	if n < 0 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{1}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.ExpPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.LogPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) InvPoly(n int) Poly {
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return p
	}
	if n == -1 {
		n = dP
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	r := NewPoly(n)
	r.c[0] = p.c[0].Inv()
	y := (mod + 1) / 2
	if y&1 == 1 {
		y += mod
	}
	y /= 2
	im := Mint{mod - y}
	for i := 0; i < k; i++ {
		for jh := 0; jh < 1<<i; jh++ {
			wj := w[jh]
			for j := jh << i; j < jh<<i+1<<i; j++ {
				Ajv := p.c[j+1].Mul(wj)
				p.c[j+1] = p.c[j].Sub(Ajv)
				p.c[j] = p.c[j].Add(Ajv)
			}
		}
		u <<= 1
		v >>= 1
	}
	return r
}

func (p Poly) IsqrtPoly(n int) Poly {
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return p
	}
	if n == -1 {
		n = dP
	}
	if n == -1 {
		return p
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k+1)
	e := make([]Mint, 1<<k+1)
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
		for jh := 0; jh < 1<<i; jh++ {
			wj := y[jh]
			for j := jh << i; j < jh<<i+1<<i; j++ {
				Ajv := p.c[j].Sub(p.c[j+1])
				p.c[j+1] = p.c[j].Add(p.c[j+1])
				p.c[j] = wj.Mul(Ajv)
			}
		}
		u >>= 1
		v <<= 1
	}
	return r
}

func (p Poly) SqrtPoly(n int) Poly {
	if n == -1 {
		n = p.Deg()
	}
	if n == -1 {
		return p
	}
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if dP < 0 {
		return NewPoly(0)
	}
	if dP == 0 {
		r := NewPoly(n)
		r.c[0] = Mint{1}
		return r
	}
	k := 32 - clz(n)
	if k > K {
		k = K
	}
	g := makeTree(p)
	A := NewPoly(1 << k)
	A.c[0] = Mint{1}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.SqrtPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i] = B.c[i].Mul(Mint{n})
	}
	C := B.LogPoly()
	ans := Mint{1}.Pow(n)
	for i := 0; i <= n; i++ {
		ans = ans.Sub(C.c[i])
	}
	ans = ans.Mul(Mint{n})
	return ans
}

func (p Poly) QuotientPoly(Q Poly) Poly {
	if Q.Deg() < 0 {
		return p
	}
	if p.Deg() < 0 {
		return p
	}
	dP := p.Deg()
	for dP >= 0 && p.c[dP].Eq(Mint{0}) {
		dP--
	}
	if p.c[dP].Eq(Mint{0}) {
		return NewPoly(0)
	}
	dQ := Q.Deg()
	for dQ >= 0 && Q.c[dQ].Eq(Mint{0}) {
		dQ--
	}
	if Q.c[dQ].Eq(Mint{0}) {
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
	if k > K {
		k = K
	}
	d := make([]Mint, 1<<k)
	e := make([]Mint, 1<<k)
	for i := 0; i <= dP-dQ; i++ {
		d[i] = p.c[dP-i]
	}
	RQ = RQ.InvPoly(dP - dQ)
	for i := 0; i <= dP-dQ; i++ {
		e[i] = RQ.c[i]
	}
	fft(d, k)
	fft(e, k)
	for i := 0; i < 1<<k; i++ {
		d[i].Mul(e[i])
	}
	ifft(d, k)
	p.c = make([]Mint, dP-dQ+1)
	im := Mint{(mod + 1) / 2}.Pow(k)
	for i := 0; i <= dP-dQ; i++ {
		p.c[i] = d[dP-dQ-i].Mul(im)
	}
	return p
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
	if k > K+1 {
		k = K + 1
	}
	T := makeTree(P)
	A := NewPoly(1 << k)
	A.c[0] = Mint{0}
	A.c[1] = Mint{(mod - 2) % mod}
	A.c[2] = Mint{1}
	B := A.LogPoly()
	for i := 0; i < len(B.c); i++ {
		B.c[i].Mul(Mint{m})
	}
	C := B.ExpPoly()
	return tupTree(C, T)
}

func (p Poly) Interpolation(a, b []Mint) Poly {
	m := len(a)
	if len(b) != m {
		panic("a and b must have the same length")
	}
	if m == 0 {
		return NewPoly(0)
	}
	return NewPoly(0)
}

func makeTree(P Poly) []Poly {
	m := P.Deg() + 1
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
		t := 1<<(k-_ls) + i
		T[t] = NewPoly(1<<_ls + 1)
		T[t].c[1<<_ls] = Mint{1}
		for j := 0; j < 1<<_ls; j++ {
			T[t].c[j] = Mint{1}
			for l := 0; l < 1<<_ls; l++ {
				T[t].c[j].Mul(w[j].Sub(Mint{P.At((i<<_ls)+l)}))
			}
			T[t].c[j].Sub(Mint{1})
		}
	}
	im := Mint{(mod + 1) / 2}.Pow(_ls)
	for i := _ls + 1; i <= k; i++ {
		for j := 0; j < 1<<(k-i); j++ {
			t := 1<<(k-i) + j
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
				FT[2*t][1<<(i-1)+l] = T[2*t].c[l].Mul(w[l<<(K-i+1)])
			}
			FT[2*t][1<<(i-1)].Sub(Mint{1})
			fft(FT[2*t][1<<(i-1):], i-1)

			FT[2*t+1] = make([]Mint, 1<<i)
			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t+1][l] = T[2*t+1].c[l].Add(Mint{1})
			}
			ifft(T[2*t+1].c, i-1)
			for l := 0; l < 1<<(i-1); l++ {
				T[2*t+1].c[l].Mul(im)
			}

			for l := 0; l < 1<<(i-1); l++ {
				FT[2*t+1][1<<(i-1)+l] = T[2*t+1].c[l].Mul(w[l<<(K-i+1)])
			}
			FT[2*t+1][1<<(i-1)].Sub(Mint{1})
			fft(FT[2*t+1][1<<(i-1):], i)

			for l := 0; l < 1<<i; l++ {
				T[t].c[l] = FT[2*t][l].Mul(FT[2*t+1][l]).Sub(Mint{1})
			}
		}
		if im.n&1 == 1 {
			im.n += mod
		}
		im.n /= 2
	}
	ifft(T[1].c, k)
	FT[1] = make([]Mint, 1<<k)
	for l := 0; l < 1<<k; l++ {
		FT[1][l] = T[1].c[l].Mul(im)
	}
	return T
}

func tupTree(B Poly, T []Poly) []Mint {
	m := B.Deg() + 1
	k := 32 - clz(m-1)
	C := make([]Poly, 1<<k)
	for i := 0; i < m; i++ {
		C[i] = NewPoly(1)
		C[i].c[0] = B.c[i]
	}
	for i := k; i > 0; i-- {
		for j := (1 << (k - i)) - 1; j >= 0; j-- {
			n := (1 << (i - 1)) - 1
			C[2*j+1] = middleProduct(n, T[(1<<(k-i+1))+2*j], C[2*j]).Add(middleProduct(n, T[(1<<(k-i+1))+2*j+1], C[2*j+1]))
			C[2*j] = middleProduct(n, T[(1<<(k-i+1))+2*j+1], C[2*j]).Add(middleProduct(n, T[(1<<(k-i+1))+2*j], C[2*j]))
		}
	}
	v := make([]Mint, m)
	for i := 0; i < m; i++ {
		v[i] = C[i].c[0]
	}
	return v
}

func middleProduct(n int, lhs, rhs Poly) Poly {
	dl := lhs.Deg()
	for dl >= 0 && lhs.c[dl].Eq(Mint{0}) {
		dl--
	}
	if dl < 0 {
		return NewPoly(0)
	}
	rdeg := dl + rhs.Deg()
	k := 32 - clz(rdeg)
	if k > K+1 {
		k = K + 1
	}
	P := NewPoly(1 << k)
	for i := 0; i <= dl; i++ {
		P.c[i] = lhs.c[dl-i]
	}
	Q := NewPoly(1 << k)
	for i := 0; i <= rhs.Deg(); i++ {
		Q.c[i] = rhs.c[i]
	}
	fft(P.c, k)
	fft(Q.c, k)
	for i := 0; i < 1<<k; i++ {
		P.c[i].Mul(Q.c[i])
	}
	ifft(P.c, k)
	im := Mint{(mod + 1) / 2}.Pow(k)
	Q.c = make([]Mint, n+1)
	for i := 0; i <= n; i++ {
		Q.c[i] = P.c[i+dl].Mul(im)
	}
	return Q
}

func fft(A []Mint, k int) {
	u := 1
	v := 1 << (k - 1)
	for i := k; i > 0; i-- {
		for jh := 0; jh < u; jh++ {
			wj := w[jh]
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := wj.Mul(A[j+v])
				A[j+v] = A[j].Sub(Ajv)
				A[j] = A[j].Add(Ajv)
			}
		}
		u <<= 1
		v >>= 1
	}
}

func ifft(A []Mint, k int) {
	u := 1 << (k - 1)
	v := 1
	for i := 1; i <= k; i++ {
		for jh := 0; jh < u; jh++ {
			wj := y[jh]
			for j := jh << i; j < jh<<i+v; j++ {
				Ajv := A[j].Sub(A[j+v])
				A[j] = A[j].Add(A[j+v])
				A[j+v] = wj.Mul(Ajv)
			}
		}
		u >>= 1
		v <<= 1
	}
}

func clz(x int) int {
	n := 0
	if x <= 0xffff {
		n += 16
		x <<= 16
	}
	if x <= 0xffffff {
		n += 8
		x <<= 8
	}
	if x <= 0x7fffffff {
		n += 4
		x <<= 4
	}
	if x <= 0x3fffffff {
		n += 2
		x <<= 2
	}
	if x <= 0x1fffffff {
		n++
		x <<= 1
	}
	return n
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

var w []Mint
var y []Mint
var u int
var v int

func init() {
	w = make([]Mint, 1<<K)
	y = make([]Mint, 1<<K)
	w[1] = Mint{1}
	fft(w, K)
	u = 1
	v = 1 << (K - 1)
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
	A.c[1] = NewMint(k-2).n
	A.c[2] = Mint{1}

	B := A.Log()
	for i := 0; i < len(B.c); i++ {
		B.c[i] *= NewMint(n - cnt).n
	}

