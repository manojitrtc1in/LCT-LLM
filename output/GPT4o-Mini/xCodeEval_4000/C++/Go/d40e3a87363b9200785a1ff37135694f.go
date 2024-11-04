package main

import (
	"fmt"
	"math/big"
	"sort"
)

const mod = 998244353

type IoSetup struct{}

func (iosetup *IoSetup) init() {
	// No direct equivalent in Go, but we can set up input/output as needed
}

type ModInt struct {
	x int64
}

func NewModInt(y int64) ModInt {
	if y >= 0 {
		return ModInt{y % mod}
	}
	return ModInt{(mod - (-y % mod)) % mod}
}

func (a *ModInt) Add(b ModInt) ModInt {
	a.x += b.x
	if a.x >= mod {
		a.x -= mod
	}
	return *a
}

func (a *ModInt) Sub(b ModInt) ModInt {
	a.x += mod - b.x
	if a.x >= mod {
		a.x -= mod
	}
	return *a
}

func (a *ModInt) Mul(b ModInt) ModInt {
	x := (a.x * b.x) % mod
	return ModInt{x}
}

func (a *ModInt) Inv() ModInt {
	u, v := int64(1), int64(0)
	aVal, bVal := a.x, mod
	for bVal > 0 {
		t := aVal / bVal
		aVal -= t * bVal
		u -= t * v
		aVal, bVal = bVal, aVal
		u, v = v, u
	}
	return NewModInt(u)
}

func (a *ModInt) Pow(n int64) ModInt {
	ret := NewModInt(1)
	mul := *a
	for n > 0 {
		if n&1 != 0 {
			ret = ret.Mul(mul)
		}
		mul = mul.Mul(mul)
		n >>= 1
	}
	return ret
}

type Fraction struct {
	num, dom int64
}

func NewFraction(n, d int64) Fraction {
	if d == 0 {
		panic("denominator cannot be zero")
	}
	if d < 0 {
		n, d = -n, -d
	}
	gcd := GCD(abs(n), abs(d))
	return Fraction{n / gcd, d / gcd}
}

func GCD(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func (a Fraction) Add(b Fraction) Fraction {
	return NewFraction(a.num*b.dom+b.num*a.dom, a.dom*b.dom)
}

func (a Fraction) Sub(b Fraction) Fraction {
	return NewFraction(a.num*b.dom-b.num*a.dom, a.dom*b.dom)
}

func (a Fraction) Mul(b Fraction) Fraction {
	return NewFraction(a.num*b.num, a.dom*b.dom)
}

func (a Fraction) Div(b Fraction) Fraction {
	return NewFraction(a.num*b.dom, a.dom*b.num)
}

func (a Fraction) Less(b Fraction) bool {
	return a.num*b.dom < b.num*a.dom
}

func (a Fraction) Greater(b Fraction) bool {
	return a.num*b.dom > b.num*a.dom
}

func (a Fraction) Equal(b Fraction) bool {
	return a.num*b.dom == b.num*a.dom
}

type Matrix struct {
	A [4][4]ModInt
}

func NewMatrix() Matrix {
	return Matrix{}
}

func (m *Matrix) Identity() {
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			if i == j {
				m.A[i][j] = NewModInt(1)
			} else {
				m.A[i][j] = NewModInt(0)
			}
		}
	}
}

func (m *Matrix) Mul(b Matrix) Matrix {
	var C Matrix
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				C.A[i][j] = C.A[i][j].Add(m.A[i][k].Mul(b.A[k][j]))
			}
		}
	}
	return C
}

func (m *Matrix) Pow(k int64) Matrix {
	B := Matrix{}
	B.Identity()
	for k > 0 {
		if k&1 != 0 {
			B = B.Mul(*m)
		}
		*m = m.Mul(*m)
		k >>= 1
	}
	return B
}

type SegmentTree struct {
	sz  int
	seg []Matrix
	f   func(a, b Matrix) Matrix
	M1  Matrix
}

func NewSegmentTree(n int, f func(a, b Matrix) Matrix, M1 Matrix) SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	seg := make([]Matrix, 2*sz)
	for i := range seg {
		seg[i] = M1
	}
	return SegmentTree{sz, seg, f, M1}
}

func (st *SegmentTree) Set(k int, x Matrix) {
	st.seg[k+st.sz] = x
}

func (st *SegmentTree) Build() {
	for k := st.sz - 1; k > 0; k-- {
		st.seg[k] = st.f(st.seg[2*k], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Update(k int, x Matrix) {
	k += st.sz
	st.seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		st.seg[k] = st.f(st.seg[2*k], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Query(a, b int) Matrix {
	L, R := st.M1, st.M1
	for a += st.sz; b += st.sz; a < b; a >>= 1 {
		if a&1 != 0 {
			L = st.f(L, st.seg[a])
			a++
		}
		if b&1 != 0 {
			b--
			R = st.f(st.seg[b], R)
		}
	}
	return st.f(L, R)
}

func main() {
	var N int
	fmt.Scan(&N)
	X := make([]int, N)
	V := make([]int, N)
	P := make([]ModInt, N)
	Q := make([]ModInt, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&X[i], &V[i])
		var p int64
		fmt.Scan(&p)
		P[i] = NewModInt(p).Div(NewModInt(100))
		Q[i] = NewModInt(1).Sub(P[i])
	}

	type Node struct {
		right, typ int
	}
	ev := make(map[Fraction][]Node)

	for i := 1; i < N; i++ {
		if V[i-1] < V[i] {
			ev[NewFraction(int64(X[i-1]-X[i]), int64(V[i-1]-V[i]))] = append(ev[NewFraction(int64(X[i-1]-X[i]), int64(V[i-1]-V[i]))], Node{i, 0})
		}
		ev[NewFraction(int64(X[i]-X[i-1]), int64(V[i-1]+V[i]))] = append(ev[NewFraction(int64(X[i]-X[i-1]), int64(V[i-1]+V[i]))], Node{i, 2})
		if V[i-1] > V[i] {
			ev[NewFraction(int64(X[i-1]-X[i]), int64(V[i]-V[i-1]))] = append(ev[NewFraction(int64(X[i-1]-X[i]), int64(V[i]-V[i-1]))], Node{i, 1})
		}
	}

	e := Matrix{}
	e.Identity()
	f := func(a, b Matrix) Matrix {
		return a.Mul(b)
	}

	seg := NewSegmentTree(N, f, e)
	for i := 0; i < N; i++ {
		u := NewMatrix()
		u.A[0][0] = Q[i]
		u.A[1][0] = Q[i]
		u.A[2][2] = Q[i]
		u.A[3][2] = Q[i]
		u.A[0][1] = P[i]
		u.A[1][1] = P[i]
		u.A[2][3] = P[i]
		u.A[3][3] = P[i]
		seg.Set(i, u)
	}
	seg.Build()

	ret := NewModInt(0)

	for _, p := range ev {
		vs := p
		for _, tt := range vs {
			now := seg.seg[tt.right]
			if tt.typ == 0 {
				now.A[0][0] = NewModInt(0)
				now.A[0][2] = Q[tt.right]
			} else if tt.typ == 1 {
				now.A[1][1] = NewModInt(0)
				now.A[1][3] = P[tt.right]
			} else {
				now.A[1][0] = NewModInt(0)
				now.A[1][2] = Q[tt.right]
			}
			seg.Update(tt.right, now)
		}
		uku := seg.seg[1]
		sum := uku.A[0][2].Add(uku.A[0][3])
		ret = ret.Add(NewModInt(p.first.num).Div(p.first.dom).Mul(sum))
		for _, tt := range vs {
			now := seg.seg[tt.right]
			if tt.typ == 0 {
				now.A[0][2] = NewModInt(0)
				now.A[2][2] = NewModInt(0)
			} else if tt.typ == 1 {
				now.A[1][3] = NewModInt(0)
				now.A[3][3] = NewModInt(0)
			} else {
				now.A[1][2] = NewModInt(0)
				now.A[3][2] = NewModInt(0)
			}
			seg.Update(tt.right, now)
		}
	}
	fmt.Println(ret.x)
}
