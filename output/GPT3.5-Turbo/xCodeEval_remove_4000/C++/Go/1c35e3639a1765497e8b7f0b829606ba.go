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

func (m ModInt) Subtract(b ModInt) ModInt {
	return NewModInt((m.v + m.mod - b.v) % m.mod, m.mod)
}

func (m ModInt) Negate() ModInt {
	return NewModInt((m.mod - m.v) % m.mod, m.mod)
}

func (m ModInt) Multiply(b ModInt) ModInt {
	return NewModInt((uint64(m.v)*uint64(b.v))%uint64(m.mod), m.mod)
}

func (m ModInt) Divide(b ModInt) ModInt {
	return m.Multiply(b.Inverse())
}

func (m ModInt) Inverse() ModInt {
	var x, y int64
	extgcd(int64(m.v), int64(m.mod), &x, &y)
	return NewModInt((x + int64(m.mod)) % int64(m.mod), m.mod)
}

func (m ModInt) Pow(p int64) ModInt {
	if p < 0 {
		return m.Inverse().Pow(-p)
	}
	a := NewModInt(1, m.mod)
	x := m
	for p > 0 {
		if p&1 == 1 {
			a = a.Multiply(x)
		}
		x = x.Multiply(x)
		p >>= 1
	}
	return a
}

func (m ModInt) Equals(b ModInt) bool {
	return m.v == b.v
}

func (m ModInt) NotEquals(b ModInt) bool {
	return m.v != b.v
}

func (m ModInt) String() string {
	return fmt.Sprintf("%d", m.v)
}

type Poly struct {
	v []ModInt
}

func NewPoly(N int) Poly {
	return Poly{v: make([]ModInt, N)}
}

func (p Poly) Size() int {
	return len(p.v)
}

func (p Poly) At(i int) ModInt {
	if i < p.Size() {
		return p.v[i]
	}
	return NewModInt(0, 0)
}

func (p *Poly) Set(i int, x ModInt) {
	if i >= p.Size() && x.v == 0 {
		return
	}
	for i >= p.Size() {
		p.v = append(p.v, NewModInt(0, 0))
	}
	p.v[i] = x
	p.Shrink()
}

func (p *Poly) Shrink() {
	for len(p.v) > 0 && p.v[len(p.v)-1].v == 0 {
		p.v = p.v[:len(p.v)-1]
	}
}

func (p Poly) Add(r Poly) Poly {
	N := max(p.Size(), r.Size())
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Add(r.At(i)))
	}
	return ret
}

func (p Poly) Subtract(r Poly) Poly {
	N := max(p.Size(), r.Size())
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Subtract(r.At(i)))
	}
	return ret
}

func (p Poly) Negate() Poly {
	N := p.Size()
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Negate())
	}
	return ret
}

func (p Poly) Multiply(r Poly) Poly {
	if p.Size() == 0 || r.Size() == 0 {
		return NewPoly(0)
	}
	return p.MulFFT(r)
}

func (p Poly) MultiplyScalar(r ModInt) Poly {
	N := p.Size()
	ret := NewPoly(N)
	for i := 0; i < N; i++ {
		ret.Set(i, p.At(i).Multiply(r))
	}
	return ret
}

func (p Poly) Divide(y Poly) Poly {
	return p.DivFast(y)
}

func (p Poly) Mod(y Poly) Poly {
	return p.RemFast(y)
}

func (p Poly) ShiftLeft(n int) Poly {
	if n < 0 {
		return NewPoly(0)
	}
	N := p.Size()
	ret := NewPoly(N + n)
	for i := 0; i < N; i++ {
		ret.Set(i+n, p.At(i))
	}
	return ret
}

func (p Poly) ShiftRight(n int) Poly {
	if n < 0 {
		return NewPoly(0)
	}
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

func (p Poly) Equals(y Poly) bool {
	if p.Size() != y.Size() {
		return false
	}
	for i := 0; i < p.Size(); i++ {
		if p.At(i) != y.At(i) {
			return false
		}
	}
	return true
}

func (p Poly) NotEquals(y Poly) bool {
	return !p.Equals(y)
}

func (p *Poly) AddAssign(r Poly) {
	*p = p.Add(r)
}

func (p *Poly) SubtractAssign(r Poly) {
	*p = p.Subtract(r)
}

func (p *Poly) MultiplyAssign(r Poly) {
	*p = p.Multiply(r)
}

func (p *Poly) MultiplyScalarAssign(r ModInt) {
	*p = p.MultiplyScalar(r)
}

func (p *Poly) ModAssign(y Poly) {
	*p = p.Mod(y)
}

func (p *Poly) ShiftLeftAssign(n int) {
	*p = p.ShiftLeft(n)
}

func (p *Poly) ShiftRightAssign(n int) {
	*p = p.ShiftRight(n)
}

func (p Poly) MulNaive(r Poly) Poly {
	N := p.Size()
	M := r.Size()
	ret := NewPoly(N + M - 1)
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			ret.Set(i+j, ret.At(i+j).Add(p.At(i).Multiply(r.At(j))))
		}
	}
	return ret
}

func (p Poly) MulFFT(r Poly) Poly {
	ret := make([]ModInt, len(p.v)+len(r.v)-1)
	copy(ret, p.v)
	fft(false, ret)
	return NewPoly(len(ret)).SetV(ret).Shrink()
}

func (p Poly) DivFastWithInv(inv Poly, B int) Poly {
	return p.Multiply(inv).ShiftRight(B - 1)
}

func (p Poly) DivFast(y Poly) Poly {
	if p.Size() < y.Size() {
		return NewPoly(0)
	}
	n := p.Size()
	return p.DivFastWithInv(y.Inv(n), n)
}

func (p Poly) RemNaive(y Poly) Poly {
	x := p
	for y.Size() <= x.Size() {
		N := x.Size()
		M := y.Size()
		coef := x.At(N-1).Divide(y.At(M-1))
		x = x.Subtract(y.ShiftLeft(N - M).MultiplyScalar(coef))
	}
	return x
}

func (p Poly) RemFast(y Poly) Poly {
	return p.Subtract(y.Multiply(p.DivFast(y)))
}

func (p Poly) Strip(n int) Poly {
	res := make([]ModInt, len(p.v))
	copy(res, p.v)
	if n < len(res) {
		res = res[:n]
	}
	return NewPoly(len(res)).SetV(res)
}

func (p Poly) Rev(n int) Poly {
	res := make([]ModInt, len(p.v))
	copy(res, p.v)
	if n != -1 && n < len(res) {
		res = res[:n]
	}
	for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
		res[i], res[j] = res[j], res[i]
	}
	return NewPoly(len(res)).SetV(res)
}

func (p Poly) Inv(n int) Poly {
	N := p.Size()
	if N < 1 {
		return NewPoly(0)
	}
	if n < N-1 {
		return NewPoly(0)
	}
	coef := p.At(N - 1).Inverse()
	a := p.Rev(-1)
	g := NewPoly(1).Set(0, coef)
	for i := 1; (i+N-2) < n; i *= 2 {
		g = g.Multiply(NewPoly([]ModInt{2}).Subtract(a.Multiply(g)).Strip(2 * i))
	}
	return g.Rev(n + 1 - N)
}

func (p Poly) String() string {
	if p.Size() == 0 {
		return "0"
	}
	res := ""
	for i := 0; i < p.Size(); i++ {
		if p.v[i].v != 0 {
			res += fmt.Sprintf("%d", p.v[i].v) + "x^" + fmt.Sprintf("%d", i)
			if i != p.Size()-1 {
				res += " + "
			}
		}
	}
	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func fft(typ bool, c []ModInt) {
	buf := make([]ModInt, 30)
	N := len(c)
	s := bsr(N)
	if len(buf[s]) == 0 {
		buf[s] = make([]ModInt, N)
		for i := 0; i < N; i++ {
			buf[s][i] = NewModInt(1, N).Pow(int64(i*2*math.Pi/N))
		}
	}
	a := make([]ModInt, N)
	b := make([]ModInt, N)
	copy(a, c)
	for i := 1; i <= s; i++ {
		W := 1 << (s - i)
		for y := 0; y < N/2; y += W {
			now := buf[s][y]
			if typ {
				now = now.Conjugate()
			}
			for x := 0; x < W; x++ {
				l := a[y<<1|x]
				r := now.Multiply(a[y<<1|x|W])
				b[y|x] = l.Add(r)
				b[y|x|N>>1] = l.Subtract(r)
			}
		}
		a, b = b, a
	}
	copy(c, a)
}

func bsr(x int) int {
	return 31 - int(math.Log2(float64(x)))
}

func multiplyFFT(x, y []ModInt) []ModInt {
	return id4(x, y)
}

func id4(x, y []ModInt) []ModInt {
	B := 15
	S := len(x) + len(y) - 1
	N := 2 << bsr(S-1)
	a := make([]ModInt, N)
	b := make([]ModInt, N)
	for t := 0; t < 2; t++ {
		for i := 0; i < len(x); i++ {
			a[i] = x[i]
		}
		for i := 0; i < len(y); i++ {
			b[i] = y[i]
		}
		fft(false, a)
		fft(false, b)
	}
	z := make([]ModInt, S)
	c := make([]ModInt, N)
	base := NewModInt(1, 998244353)
	for t := 0; t < 3; t++ {
		for i := 0; i < N; i++ {
			c[i] = NewModInt(0, 998244353)
		}
		for xt := max(t-1, 0); xt <= min(1, t); xt++ {
			yt := t - xt
			for i := 0; i < N/2; i++ {
				now := NewModInt(1, 998244353)
				if typ {
					now = now.Conjugate()
				}
				for x := 0; x < W; x++ {
					l := a[y<<1|x]
					r := now.Multiply(a[y<<1|x|W])
					b[y|x] = l.Add(r)
					b[y|x|N>>1] = l.Subtract(r)
				}
			}
		}
		swap(a, b)
	}
	for i := 0; i < S; i++ {
		c[i] = c[i].Multiply(NewModInt(1, N))
		z[i] = z[i].Add(NewModInt(int64(round(c[i].Real())), 998244353)).Multiply(base)
	}
	return z
}

func round(x float64) int {
	if x < 0 {
		return int(x - 0.5)
	}
	return int(x + 0.5)
}

func id3(terms []ModInt, deg, ord int, verify bool) [][]ModInt {
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
		error(deg, ord)
	}

	mat := make([][]ModInt, R)
	for y := 0; y < R; y++ {
		mat[y] = make([]ModInt, C)
		for b := 0; b < B; b++ {
			v := terms[y+b]
			for d := 0; d <= deg; d++ {
				mat[y][b*(deg+1)+d] = v
				v = v.Multiply(NewModInt(int64(y+b), 998244353))
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
		inv := mat[rank][x].Inverse()
		for x2 := x; x2 < C; x2++ {
			mat[rank][x2] = mat[rank][x2].Multiply(inv)
		}
		for y := rank + 1; y < R; y++ {
			if mat[y][x].v != 0 {
				c := mat[y][x].Negate()
				for x2 := x; x2 < C; x2++ {
					mat[y][x2] = mat[y][x2].Add(mat[rank][x2].Multiply(c))
				}
			}
		}
		rank++
	}

	if rank == C {
		error(B-1, deg)
	}

	for y := rank - 1; y >= 0; y-- {
		if mat[y][rank].v != 0 {
			coef := mat[y][rank].Negate()
			for y2 := 0; y2 < y; y2++ {
				mat[y2][rank] = mat[y2][rank].Add(mat[y2][y].Multiply(coef))
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
		ret[k][d] = ret[k][d].Subtract(mat[y][rank])
	}

	if verify {
		extendedTerms := extended(n-1, ret, terms[:order])
		for i := 0; i < len(terms); i++ {
			if terms[i] != extendedTerms[i] {
				error(B-1, deg)
			}
		}
	}

	verbose := func() {
		last := n - 1
		if verify {
			last = order + R - 1
		}
		fmt.Printf("[ Found a recurrence relation ]\n")
		fmt.Printf("- order %d\n", order)
		fmt.Printf("- degree %d\n", deg)
		fmt.Printf("- verified up to a(%d) (number of non-trivial terms: %d)\n", last, (last+1)-((deg+2)*(order+1)-2))
		fmt.Printf("{\n")
		for k := 0; k <= order; k++ {
			fmt.Printf("  {")
			for d := 0; d <= deg; d++ {
				if d > 0 {
					fmt.Printf(", ")
				}
				fmt.Printf("%d", ret[k][d].v)
			}
			fmt.Printf("}%s\n", func() string {
				if k == order {
					return ""
				}
				return ","
			}())
		}
		fmt.Printf("}\n\n")
	}
	verbose()

	return ret
}

func error(order, deg int) {
	fmt.Printf("Error: Could not find a recurrence relation of order <= %d and degree <= %d.\n\n", order, deg)
	panic("error")
}

func extended(n int, coeffs [][]ModInt, terms []ModInt) []ModInt {
	ret := make([]ModInt, max(n+1, len(terms)))
	copy(ret, terms)
	order := len(coeffs) - 1
	deg := len(coeffs[0]) - 1
	for m := len(terms); m <= n; m++ {
		s := NewModInt(0, 998244353)
		for i := 1; i <= order; i++ {
			k := m - i
			t := ret[k]
			for d := 0; d <= deg; d++ {
				s = s.Add(t.Multiply(coeffs[i][d]))
				t = t.Multiply(NewModInt(int64(k), 998244353))
			}
		}
		denom := NewModInt(0, 998244353)
		mpow := NewModInt(1, 998244353)
		for d := 0; d <= deg; d++ {
			denom = denom.Add(mpow.Multiply(coeffs[0][d]))
			mpow = mpow.Multiply(NewModInt(int64(m), 998244353))
		}
		ret[m] = s.Divide(denom).Negate()
	}
	return ret
}

func id1(n int, terms []ModInt, degree int, order int) {
	coeffs := id3(terms, degree, order, true)
	extendedTerms := extended(n, coeffs, terms)
	for i := 0; i < len(extendedTerms); i++ {
		fmt.Printf("%d %d\n", i, extendedTerms[i].v)
	}
	fmt.Println()
}

func id2(n int, terms []ModInt, degree int, order int) []ModInt {
	coeffs := id3(terms, degree, order, true)
	return extended(n, coeffs, terms)
}

func main() {
	N := 0
	fmt.Scan(&N)

	solve := func(N int) ModInt {
		res := NewModInt(0, 998244353)
		for i := 0; i <= N; i++ {
			if i == 0 {
				for j := 1; j <= N; j++ {
					res = res.Add(NewModInt(-1, 998244353).Pow(int64(i+j)).Multiply(Choose(N, j)).Multiply(NewModInt(3, 998244353).Pow(j+N*(N-j))))
				}
			} else {
				res = res.Add(NewModInt(-1, 998244353).Pow(int64(i)).Multiply(Choose(N, i)).Multiply(NewModInt(3, 998244353).Pow((N-i)*(N-j))).Multiply(NewModInt(3, 998244353).Pow(i+N*(N-i))))
			}
		}
		return res.Negate()
	}

	fmt.Println(solve(N))
}

func Choose(a, b int) ModInt {
	if b < 0 || a < b {
		return NewModInt(0, 0)
	}
	return fact[a].Multiply(ifact[b]).Multiply(ifact[a-b])
}

func InitFact(N int) {
	fact = make([]ModInt, N)
	ifact = make([]ModInt, N)
	fact[0] = NewModInt(1, 998244353)
	for i := 1; i < N; i++ {
		fact[i] = fact[i-1].Multiply(NewModInt(uint(i), 998244353))
	}
	ifact[N-1] = fact[N-1].Inverse()
	for i := N - 2; i >= 0; i-- {
		ifact[i] = ifact[i+1].Multiply(NewModInt(uint(i+1), 998244353))
	}
}

func extgcd(a, b int64, x, y *int64) int64 {
	p := []int64{a, 1, 0}
	q := []int64{b, 0, 1}
	for q[0] != 0 {
		t := p[0] / q[0]
		for i := 0; i < 3; i++ {
			p[i], q[i] = p[i]-t*q[i], p[i]
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

var fact, ifact []ModInt

func main() {
	InitFact(2000010)

	brute := func(N int) ModInt {
		res := NewModInt(0, 998244353)
		for i := 0; i <= N; i++ {
			for j := 0; j <= N; j++ {
				if i > j {
					i, j = j, i
				}
				if j == 0 {
					continue
				}
				if i == 0 {
					res = res.Add(NewModInt(-1, 998244353).Pow(int64(i+j)).Multiply(Choose(N, j)).Multiply(NewModInt(3, 998244353).Pow(j+N*(N-j))))
				} else {
					res = res.Add(NewModInt(-1, 998244353).Pow(int64(i+j)).Multiply(Choose(N, i)).Multiply(Choose(N, j)).Multiply(NewModInt(3, 998244353)).Multiply(NewModInt(3, 998244353).Pow((N-i)*(N-j))))
				}
			}
		}
		return res.Negate()
	}

	solve := func(N int64) ModInt {
		res := NewModInt(0, 998244353)
		for i := int64(0); i <= N; i++ {
			if i == 0 {
				for j := int64(1); j <= N; j++ {
					res = res.Add(NewModInt(-1, 998244353).Pow(i+j).Multiply(Choose(int(N), int(j))).Multiply(NewModInt(3, 998244353).Pow(j+N*(N-j))))
				}
			} else {
				res = res.Add(NewModInt(-1, 998244353).Pow(i).Multiply(Choose(int(N), int(i))).Multiply(NewModInt(3, 998244353).Pow((N-i)*(N-i))).Multiply(NewModInt(3, 998244353).Pow(i+N*(N-i))))
			}
		}
		return res.Negate()
	}

	var N int64
	fmt.Scan(&N)

	fmt.Println(solve(N))
}
