package main

import (
	"fmt"
	"math/big"
	"sort"
)

const mod = 998244353

type IoSetup struct{}

func (IoSetup) Init() {
	// No specific setup needed in Go
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
	return NewModInt(a.x * b.x % mod)
}

func (a *ModInt) Div(b ModInt) ModInt {
	return a.Mul(b.Inverse())
}

func (a *ModInt) Inverse() ModInt {
	return NewModInt(a.x) // Placeholder for actual inverse calculation
}

func (a *ModInt) Pow(n int64) ModInt {
	ret := NewModInt(1)
	mul := *a
	for n > 0 {
		if n&1 == 1 {
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
		n *= -1
		d *= -1
	}
	gcd := GCD(abs(n), abs(d))
	return Fraction{n / gcd, d / gcd}
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

type Node struct {
	right int
	typ   int
}

type Event struct {
	fraction Fraction
	nodes    []Node
}

type SegmentTree struct {
	sz  int
	seg []Matrix
	f   func(a, b Matrix) Matrix
	m1  Matrix
}

func NewSegmentTree(n int, f func(a, b Matrix) Matrix, m1 Matrix) SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	seg := make([]Matrix, 2*sz)
	for i := range seg {
		seg[i] = m1
	}
	return SegmentTree{sz, seg, f, m1}
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
	L, R := st.m1, st.m1
	for a += st.sz; a < b; a >>= 1 {
		if a&1 == 1 {
			L = st.f(L, st.seg[a])
			a++
		}
	}
	for b += st.sz; a < b; b >>= 1 {
		if b&1 == 1 {
			b--
			R = st.f(st.seg[b], R)
		}
	}
	return st.f(L, R)
}

type Matrix struct {
	A [4][4]ModInt
}

func NewMatrix() Matrix {
	return Matrix{}
}

func (m *Matrix) Height() int {
	return len(m.A)
}

func (m *Matrix) Width() int {
	return len(m.A[0])
}

func (m *Matrix) SetIdentity() {
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

func (m *Matrix) Add(b Matrix) Matrix {
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			m.A[i][j] = m.A[i][j].Add(b.A[i][j])
		}
	}
	return *m
}

func (m *Matrix) Sub(b Matrix) Matrix {
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			m.A[i][j] = m.A[i][j].Sub(b.A[i][j])
		}
	}
	return *m
}

func (m *Matrix) Mul(b Matrix) Matrix {
	var C [4][4]ModInt
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				C[i][j] = C[i][j].Add(m.A[i][k].Mul(b.A[k][j]))
			}
		}
	}
	m.A = C
	return *m
}

func (m *Matrix) Pow(k int64) Matrix {
	B := NewMatrix()
	B.SetIdentity()
	for k > 0 {
		if k&1 == 1 {
			B = B.Mul(*m)
		}
		*m = m.Mul(*m)
		k >>= 1
	}
	return B
}

func (m Matrix) String() string {
	return fmt.Sprintf("%v", m.A)
}

func GCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var N int
	fmt.Scan(&N)
	X := make([]int64, N)
	V := make([]int64, N)
	P := make([]ModInt, N)
	Q := make([]ModInt, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&X[i], &V[i], &P[i])
		P[i] = P[i].Div(NewModInt(100))
		Q[i] = NewModInt(1).Sub(P[i])
	}

	ev := make(map[Fraction][]Node)

	for i := 1; i < N; i++ {
		if V[i-1] < V[i] {
			ev[NewFraction(X[i-1]-X[i], V[i-1]-V[i])] = append(ev[NewFraction(X[i-1]-X[i], V[i-1]-V[i])], Node{i, 0})
		}
		ev[NewFraction(X[i]-X[i-1], V[i-1]+V[i])] = append(ev[NewFraction(X[i]-X[i-1], V[i-1]+V[i])], Node{i, 2})
		if V[i-1] > V[i] {
			ev[NewFraction(X[i-1]-X[i], V[i]-V[i-1])] = append(ev[NewFraction(X[i-1]-X[i], V[i]-V[i-1])], Node{i, 1})
		}
	}

	e := NewMatrix()
	e.SetIdentity()
	f := func(a, b Matrix) Matrix {
		return a.Mul(b)
	}

	seg := NewSegmentTree(N, f, e)
	for i := 0; i < N; i++ {
		u := NewMatrix()
		u.SetIdentity()
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
		for _, tt := range p {
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
		ret = ret.Add(NewModInt(p.fraction.num).Div(p.fraction.dom).Mul(sum))
		for _, tt := range p {
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
