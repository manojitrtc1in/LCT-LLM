package main

import (
	"fmt"
	"math/big"
	"sort"
)

const mod = 998244353

type ModInt struct {
	x uint32
}

func NewModInt(val int64) ModInt {
	return ModInt{reduce(uint64(val) * r2)}
}

func (m ModInt) Get() int {
	return int(reduce(uint64(m.x))) % mod
}

func (m ModInt) Add(other ModInt) ModInt {
	m.x += other.x
	if int(m.x) >= 2*mod {
		m.x -= 2 * mod
	}
	return m
}

func (m ModInt) Sub(other ModInt) ModInt {
	m.x -= other.x
	if int(m.x) < 0 {
		m.x += 2 * mod
	}
	return m
}

func (m ModInt) Mul(other ModInt) ModInt {
	m.x = reduce(uint64(m.x) * uint64(other.x))
	return m
}

func (m ModInt) Pow(n int64) ModInt {
	ret := NewModInt(1)
	mul := m
	for n > 0 {
		if n&1 == 1 {
			ret = ret.Mul(mul)
		}
		mul = mul.Mul(mul)
		n >>= 1
	}
	return ret
}

func (m ModInt) Inverse() ModInt {
	return m.Pow(mod - 2)
}

func reduce(w uint64) uint32 {
	return uint32(w >> 32) + mod - uint32((uint64(uint32(w)*inv)*mod)>>32)
}

var inv uint32
var r2 uint32

func init() {
	inv = mulInv(mod)
	r2 = uint32(-int64(mod) % mod)
}

func mulInv(n uint32) uint32 {
	x := uint32(1)
	for e := 5; e > 0; e-- {
		x = x * (2 - x*n)
	}
	return x
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
	gcd := gcd(abs(n), abs(d))
	return Fraction{n / gcd, d / gcd}
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func (f Fraction) Add(other Fraction) Fraction {
	return NewFraction(f.num*other.dom+other.num*f.dom, f.dom*other.dom)
}

func (f Fraction) Sub(other Fraction) Fraction {
	return NewFraction(f.num*other.dom-other.num*f.dom, f.dom*other.dom)
}

func (f Fraction) Mul(other Fraction) Fraction {
	return NewFraction(f.num*other.num, f.dom*other.dom)
}

func (f Fraction) Div(other Fraction) Fraction {
	return NewFraction(f.num*other.dom, f.dom*other.num)
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
	return SegmentTree{sz: sz, seg: seg, f: f, m1: m1}
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
		if a&1 != 0 {
			L = st.f(L, st.seg[a])
			a++
		}
	}
	for b += st.sz; b > 0; b >>= 1 {
		if b&1 != 0 {
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

func (m *Matrix) Mul(other Matrix) Matrix {
	var C Matrix
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				C.A[i][j] = C.A[i][j].Add(m.A[i][k].Mul(other.A[k][j]))
			}
		}
	}
	return C
}

func (m *Matrix) Pow(k int64) Matrix {
	B := NewMatrix()
	B.Identity()
	for k > 0 {
		if k&1 == 1 {
			B = B.Mul(*m)
		}
		*m = m.Mul(*m)
		k >>= 1
	}
	return B
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

	mat := NewMatrix()
	mat.Identity()
	seg := NewSegmentTree(N, func(a, b Matrix) Matrix {
		return a.Mul(b)
	}, mat)

	for i := 0; i < N; i++ {
		u := NewMatrix()
		u.Identity()
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
	fmt.Println(ret.Get())
}
