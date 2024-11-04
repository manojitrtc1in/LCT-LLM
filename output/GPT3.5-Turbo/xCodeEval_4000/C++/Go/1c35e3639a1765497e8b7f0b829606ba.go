package main

import (
	"fmt"
	"math"
)

type ModInt struct {
	v   uint
	mod uint
}

func NewModInt(v, mod uint) ModInt {
	return ModInt{v: v % mod, mod: mod}
}

func (m ModInt) Add(b ModInt) ModInt {
	return NewModInt((m.v + b.v) % m.mod, m.mod)
}

func (m ModInt) Sub(b ModInt) ModInt {
	return NewModInt((m.v + m.mod - b.v) % m.mod, m.mod)
}

func (m ModInt) Neg() ModInt {
	return NewModInt((m.mod - m.v) % m.mod, m.mod)
}

func (m ModInt) Mul(b ModInt) ModInt {
	return NewModInt((uint64(m.v)*uint64(b.v))%uint64(m.mod), m.mod)
}

func (m ModInt) Pow(p int) ModInt {
	if p < 0 {
		return m.Inv().Pow(-p)
	}
	a := NewModInt(1, m.mod)
	x := m
	for p > 0 {
		if p&1 == 1 {
			a = a.Mul(x)
		}
		x = x.Mul(x)
		p >>= 1
	}
	return a
}

func (m ModInt) Inv() ModInt {
	var x, y int64
	extgcd(int64(m.v), int64(m.mod), &x, &y)
	return NewModInt((uint(x) + uint(m.mod)) % m.mod, m.mod)
}

func extgcd(a, b int64, x, y *int64) int64 {
	p := []int64{a, 1, 0}
	q := []int64{b, 0, 1}
	for q[0] != 0 {
		t := p[0] / q[0]
		for i := 0; i < 3; i++ {
			p[i], q[i] = q[i], p[i]-t*q[i]
		}
	}
	if p[0] < 0 {
		for i := 0; i < 3; i++ {
			p[i] = -p[i]
		}
	}
	*x, *y = p[1], p[2]
	return p[0]
}

func Choose(a, b int) ModInt {
	if b < 0 || a < b {
		return NewModInt(0, 0)
	}
	return fact[a].Mul(ifact[b]).Mul(ifact[a-b])
}

func TEN(n int) int64 {
	if n == 0 {
		return 1
	}
	return 10 * TEN(n-1)
}

func bsr(x int) int {
	return 31 - int(math.BuiltinClz(uint(x)))
}

type Pc complex128

func fft(type bool, c []Pc) {
	buf := make([][]Pc, 30)
	N := len(c)
	s := bsr(N)
	if len(buf[s]) == 0 {
		buf[s] = make([]Pc, N)
		for i := 0; i < N; i++ {
			buf[s][i] = Pc(1, float64(i)*2*math.Pi/float64(N))
		}
	}
	a := make([]Pc, N)
	b := make([]Pc, N)
	copy(a, c)
	for i := 1; i <= s; i++ {
		W := 1 << (s - i)
		for y := 0; y < N/2; y += W {
			now := buf[s][y]
			if type {
				now = complex(real(now), -imag(now))
			}
			for x := 0; x < W; x++ {
				l := a[y<<1|x]
				r := now * a[y<<1|x|W]
				b[y|x] = l + r
				b[y|x|N>>1] = l - r
			}
		}
		a, b = b, a
	}
	copy(c, a)
}

func multiply_fft2(x, y []ModInt) []ModInt {
	const B = 15
	S := len(x) + len(y) - 1
	N := 2 << bsr(S-1)
	a := make([]Pc, N)
	b := make([]Pc, N)
	for t := 0; t < 2; t++ {
		a[t] = make([]Pc, N)
		b[t] = make([]Pc, N)
		for i := 0; i < len(x); i++ {
			a[t][i] = Pc(float64(x[i].v>>(t*B))&((1<<B)-1), 0)
		}
		for i := 0; i < len(y); i++ {
			b[t][i] = Pc(float64(y[i].v>>(t*B))&((1<<B)-1), 0)
		}
		fft(false, a[t])
		fft(false, b[t])
	}
	z := make([]ModInt, S)
	c := make([]Pc, N)
	base := ModInt(1, 998244353)
	for t := 0; t < 3; t++ {
		fill(c, Pc(0, 0))
		for xt := max(t-1, 0); xt <= min(1, t); xt++ {
			yt := t - xt
			for i := 0; i < N; i++ {
				c[i] += a[xt][i] * b[yt][i]
			}
		}
		fft(true, c)
		for i := 0; i < S; i++ {
			c[i] *= 1.0 / float64(N)
			z[i] += ModInt(int64(math.Round(real(c[i])))) * base
		}
		base *= 1 << B
	}
	return z
}

func multiply_fft(x, y []ModInt) []ModInt {
	return multiply_fft2(x, y)
}

type Poly struct {
	v []ModInt
}

func NewPoly(N int) *Poly {
	return &Poly{v: make([]ModInt, N)}
}

func NewPolyFromSlice(v []ModInt) *Poly {
	return &Poly{v: v}
}

func (p *Poly) Size() int {
	return len(p.v)
}

func (p *Poly) At(i int) ModInt {
	if i < p.Size() {
		return p.v[i]
	}
	return ModInt{0, 0}
}

func (p *Poly) Set(i int, x ModInt) {
	if i >= p.Size() && x.v == 0 {
		return
	}
	for i >= p.Size() {
		p.v = append(p.v, ModInt{0, 0})
	}
	p.v[i] = x
	p.Shrink()
}

func (p *Poly) Shrink() {
	for len(p.v) > 0 && p.v[len(p.v)-1].v == 0 {
		p.v = p.v[:len(p.v)-1]
	}
}

func (p *Poly) Add(r *Poly) *Poly {
	N := max(p.Size(), r.Size())
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Add(r.At(i)))
	}
	return ret
}

func (p *Poly) Sub(r *Poly) *Poly {
	N := max(p.Size(), r.Size())
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Sub(r.At(i)))
	}
	return ret
}

func (p *Poly) Neg() *Poly {
	N := p.Size()
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Neg())
	}
	return ret
}

func (p *Poly) Mul(r *Poly) *Poly {
	if p.Size() == 0 || r.Size() == 0 {
		return NewPoly(0)
	}
	return p.MulFFT(r)
}

func (p *Poly) MulScalar(r ModInt) *Poly {
	N := p.Size()
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Mul(r))
	}
	return ret
}

func (p *Poly) DivFastWithInv(inv *Poly, B int) *Poly {
	return p.Mul(inv).ShiftRight(B - 1)
}

func (p *Poly) DivFast(y *Poly) *Poly {
	if p.Size() < y.Size() {
		return NewPoly(0)
	}
	n := p.Size()
	return p.DivFastWithInv(y.Inv(n), n)
}

func (p *Poly) RemNaive(y *Poly) *Poly {
	x := p.Copy()
	for y.Size() <= x.Size() {
		N := x.Size()
		M := y.Size()
		coef := x.At(N-1).Div(y.At(M-1))
		x = x.Sub(y.ShiftLeft(N-M).MulScalar(coef))
	}
	return x
}

func (p *Poly) RemFast(y *Poly) *Poly {
	return p.Sub(y.Mul(p.DivFast(y)))
}

func (p *Poly) ShiftLeft(n int) *Poly {
	N := p.Size()
	ret := NewPoly(N + n)
	for i := 0; i < N; i++ {
		ret.Set(i+n, p.At(i))
	}
	return ret
}

func (p *Poly) ShiftRight(n int) *Poly {
	N := p.Size()
	if N <= n {
		return NewPoly(0)
	}
	ret := NewPoly(N - n)
	for i := 0; i < N-n; i++ {
		ret.Set(i, p.At(i+n))
	}
	return ret
}

func (p *Poly) Copy() *Poly {
	N := p.Size()
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i))
	}
	return ret
}

func (p *Poly) String() string {
	N := p.Size()
	if N == 0 {
		return "0"
	}
	res := ""
	for i := 0; i < N; i++ {
		if p.v[i].v != 0 {
			res += fmt.Sprintf("%d*x^%d", p.v[i].v, i)
			if i != N-1 {
				res += " + "
			}
		}
	}
	return res
}

var fact, ifact []ModInt

func InitFact(N int) {
	fact = make([]ModInt, N)
	ifact = make([]ModInt, N)
	fact[0] = NewModInt(1, 998244353)
	for i := 1; i < N; i++ {
		fact[i] = fact[i-1].Mul(NewModInt(uint(i), 998244353))
	}
	ifact[N-1] = fact[N-1].Inv()
	for i := N - 2; i >= 0; i-- {
		ifact[i] = ifact[i+1].Mul(NewModInt(uint(i+1), 998244353))
	}
}

func BerlekampMassey(u []ModInt) *Poly {
	N := len(u)
	b := []*Poly{NewPoly(1)}
	c := []*Poly{NewPoly(1)}
	y := NewModInt(1, 998244353)
	for n := 1; n <= N; n++ {
		L := len(c)
		M := len(b)
		x := NewModInt(0, 998244353)
		for i := 0; i < L; i++ {
			x = x.Add(c[i].At(n-L+i).Mul(u[n-L+i]))
		}
		b = append(b, NewPoly(M+1))
		M++
		if x.v == 0 {
			continue
		}
		coef := x.Div(y)
		if L < M {
			tmp := c
			c = make([]*Poly, M)
			for i := 0; i < M; i++ {
				c[M-1-i] = tmp[i].Copy()
				c[M-1-i] = c[M-1-i].Sub(b[M-1-i].Mul(coef))
			}
			b = tmp
			y = x
		} else {
			for i := 0; i < M; i++ {
				c[L-1-i] = c[L-1-i].Sub(b[M-1-i].Mul(coef))
			}
		}
	}
	return NewPolyFromSlice(c)
}

func Extended(n int, coeffs [][]ModInt, terms []ModInt) []ModInt {
	ret := make([]ModInt, max(n+1, len(terms)))
	copy(ret, terms)
	order := len(coeffs) - 1
	deg := len(coeffs[0]) - 1
	if len(terms) >= order {
		for m := len(terms); m <= n; m++ {
			s := NewModInt(0, 998244353)
			for i := 1; i <= order; i++ {
				k := m - i
				t := ret[k]
				for d := 0; d <= deg; d++ {
					s = s.Add(t.Mul(coeffs[i][d]))
					t = t.Mul(NewModInt(int64(k), 998244353))
				}
			}
			denom := NewModInt(0, 998244353)
			mpow := NewModInt(1, 998244353)
			for d := 0; d <= deg; d++ {
				denom = denom.Add(mpow.Mul(coeffs[0][d]))
				mpow = mpow.Mul(NewModInt(int64(m), 998244353))
			}
			ret[m] = s.Div(denom).Neg()
		}
	}
	return ret
}

func FindRecurrenceRelation(terms []ModInt, deg int, ord int, verify bool) [][]ModInt {
	if ord != -1 {
		n := (deg+1)*(ord+1) + ord - 1
		for len(terms) > n {
			terms = terms[:len(terms)-1]
		}
	}

	n := len(terms)
	B := (n + 2) / (deg + 2)
	C := B * (deg + 1)
	R := n - (B - 1)

	if B < 2 || R < C-1 {
		panic("Error: Could not find a recurrence relation")
	}

	mat := make([][]ModInt, R)
	for y := 0; y < R; y++ {
		mat[y] = make([]ModInt, C)
		for b := 0; b < B; b++ {
			v := terms[y+b]
			for d := 0; d <= deg; d++ {
				mat[y][b*(deg+1)+d] = v
				v = v.Mul(NewModInt(int64(y+b), 998244353))
			}
		}
	}

	rank := 0
	for x := 0; x < C; x++ {
		pivot := -1
		for y := rank; y < R; y++ {
			if mat[y][x].v != 0 {
				pivot = y
				break
			}
		}
		if pivot < 0 {
			break
		}
		if pivot != rank {
			mat[rank], mat[pivot] = mat[pivot], mat[rank]
		}
		inv := mat[rank][x].Inv()
		for x2 := x; x2 < C; x2++ {
			mat[rank][x2] = mat[rank][x2].Mul(inv)
		}
		for y := rank + 1; y < R; y++ {
			if mat[y][x].v != 0 {
				c := mat[y][x].Neg()
				for x2 := x; x2 < C; x2++ {
					mat[y][x2] = mat[y][x2].Add(mat[rank][x2].Mul(c))
				}
			}
		}
		rank++
	}

	if rank == C {
		panic("Error: Could not find a recurrence relation")
	}

	for y := rank - 1; y >= 0; y-- {
		if mat[y][rank].v != 0 {
			for y2 := 0; y2 < y; y2++ {
				mat[y2][rank] = mat[y2][rank].Add(mat[y2][y].Mul(mat[y][rank].Neg()))
			}
		}
	}

	order := rank / (deg + 1)

	ret := make([][]ModInt, order+1)
	for k := 0; k <= order; k++ {
		ret[k] = make([]ModInt, deg+1)
		ret[k][rank%(deg+1)] = NewModInt(1, 998244353)
	}
	for y := rank - 1; y >= 0; y-- {
		k := order - y/(deg+1)
		d := y % (deg + 1)
		ret[k][d] = ret[k][d].Sub(mat[y][rank])
	}

	if verify {
		extendedTerms := Extended(n-1, ret, terms[:order])
		for i := 0; i < len(terms); i++ {
			if terms[i].v != extendedTerms[i].v {
				panic("Error: Could not find a recurrence relation")
			}
		}
	}

	return ret
}

func main() {
	var N int
	fmt.Scan(&N)

	InitFact(2000010)

	solve := func(N int) ModInt {
		res := NewModInt(0, 998244353)
		for i := 0; i <= N; i++ {
			if i == 0 {
				for j := 1; j <= N; j++ {
					res = res.Add(NewModInt(-1, 998244353).Pow(i+j).Mul(Choose(N, j)).Mul(NewModInt(3, 998244353).Pow(j+N*(N-j))))
				}
			} else {
				res = res.Add(NewModInt(-1, 998244353).Pow(i).Mul(Choose(N, i)).Mul(NewModInt(3, 998244353).Pow(N-i).Sub(NewModInt(1, 998244353)).Pow(N).Sub(NewModInt(3, 998244353).Pow((N-i)*N))).Mul(NewModInt(3, 998244353).Pow(i+N*(N-i))))
			}
		}
		return res.Neg()
	}

	fmt.Println(solve(N))
}
