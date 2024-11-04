package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type modint int

func (m modint) add(x modint) modint {
	m += x
	if m >= mod {
		m -= mod
	}
	return m
}

func (m modint) sub(x modint) modint {
	m -= x
	if m < 0 {
		m += mod
	}
	return m
}

func (m modint) mul(x modint) modint {
	return modint(int64(m) * int64(x) % mod)
}

func (m modint) pow(n int64) modint {
	res := modint(1)
	for n > 0 {
		if n&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		n >>= 1
	}
	return res
}

func (m modint) inv() modint {
	return m.pow(int64(mod - 2))
}

func (m modint) div(x modint) modint {
	return m.mul(x.inv())
}

func (m modint) equal(x modint) bool {
	return m == x
}

func (m modint) notEqual(x modint) bool {
	return m != x
}

func (m modint) less(x modint) bool {
	return m < x
}

func (m modint) lessEqual(x modint) bool {
	return m <= x
}

func (m modint) greater(x modint) bool {
	return m > x
}

func (m modint) greaterEqual(x modint) bool {
	return m >= x
}

func (m modint) get() int {
	return int(m)
}

func (m modint) String() string {
	return fmt.Sprintf("%d", m.get())
}

type fraction struct {
	num int64
	dom int64
}

func newFraction(n, d int64) fraction {
	g := gcd(abs(n), abs(d))
	n /= g
	d /= g
	if d < 0 {
		n *= -1
		d *= -1
	}
	return fraction{num: n, dom: d}
}

func (f fraction) add(a fraction) fraction {
	return newFraction(f.num*a.dom+a.num*f.dom, f.dom*a.dom)
}

func (f fraction) sub(a fraction) fraction {
	return newFraction(f.num*a.dom-a.num*f.dom, f.dom*a.dom)
}

func (f fraction) mul(a fraction) fraction {
	return newFraction(f.num*a.num, f.dom*a.dom)
}

func (f fraction) div(a fraction) fraction {
	return newFraction(f.num*a.dom, f.dom*a.num)
}

func (f fraction) mulInt(k int64) fraction {
	return newFraction(f.num*k, f.dom)
}

func (f fraction) divInt(k int64) fraction {
	return newFraction(f.num, f.dom*k)
}

func (f fraction) less(a fraction) bool {
	return f.num*a.dom < a.num*f.dom
}

func (f fraction) greater(a fraction) bool {
	return f.num*a.dom > a.num*f.dom
}

func (f fraction) equal(a fraction) bool {
	return f.num*a.dom == a.num*f.dom
}

func (f fraction) notEqual(a fraction) bool {
	return f.num*a.dom != a.num*f.dom
}

func (f fraction) lessEqual(a fraction) bool {
	return f.num*a.dom <= a.num*f.dom
}

func (f fraction) greaterEqual(a fraction) bool {
	return f.num*a.dom >= a.num*f.dom
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

type matrix struct {
	A [4][4]modint
}

func newMatrix(n int) matrix {
	m := matrix{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				m.A[i][j] = 1
			} else {
				m.A[i][j] = 0
			}
		}
	}
	return m
}

func (m matrix) height() int {
	return len(m.A)
}

func (m matrix) width() int {
	return len(m.A[0])
}

func (m matrix) add(B matrix) matrix {
	n := m.height()
	m1 := newMatrix(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			m1.A[i][j] = m.A[i][j].add(B.A[i][j])
		}
	}
	return m1
}

func (m matrix) sub(B matrix) matrix {
	n := m.height()
	m1 := newMatrix(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			m1.A[i][j] = m.A[i][j].sub(B.A[i][j])
		}
	}
	return m1
}

func (m matrix) mul(B matrix) matrix {
	n := m.height()
	m1 := newMatrix(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				m1.A[i][j] = m1.A[i][j].add(m.A[i][k].mul(B.A[k][j]))
			}
		}
	}
	return m1
}

func (m matrix) pow(k int64) matrix {
	n := m.height()
	res := newMatrix(n)
	for k > 0 {
		if k&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		k >>= 1
	}
	return res
}

func (m matrix) determinant() modint {
	n := m.height()
	B := newMatrix(n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			B.A[i][j] = m.A[i][j]
		}
	}
	res := modint(1)
	for i := 0; i < n; i++ {
		idx := -1
		for j := i; j < n; j++ {
			if B.A[j][i] != 0 {
				idx = j
			}
		}
		if idx == -1 {
			return 0
		}
		if i != idx {
			res = res.mul(modint(-1))
			B.A[i], B.A[idx] = B.A[idx], B.A[i]
		}
		res = res.mul(B.A[i][i])
		vv := B.A[i][i]
		for j := 0; j < n; j++ {
			B.A[i][j] = B.A[i][j].div(vv)
		}
		for j := i + 1; j < n; j++ {
			a := B.A[j][i]
			for k := 0; k < n; k++ {
				B.A[j][k] = B.A[j][k].sub(B.A[i][k].mul(a))
			}
		}
	}
	return res
}

func main() {
	var N int
	fmt.Scan(&N)
	X := make([]int, N)
	V := make([]int, N)
	P := make([]modint, N)
	Q := make([]modint, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&X[i], &V[i], &P[i])
		P[i] = P[i].divInt(100)
		Q[i] = modint(1).sub(P[i])
	}

	type node struct {
		right int
		typ   int
	}
	ev := make(map[fraction][]node)
	for i := 1; i < N; i++ {
		if V[i-1] < V[i] {
			ev[newFraction(int64(X[i-1]-X[i]), int64(V[i-1]-V[i]))] = append(ev[newFraction(int64(X[i-1]-X[i]), int64(V[i-1]-V[i]))], node{i, 0})
		}
		ev[newFraction(int64(X[i]-X[i-1]), int64(V[i-1]+V[i]))] = append(ev[newFraction(int64(X[i]-X[i-1]), int64(V[i-1]+V[i]))], node{i, 2})
		if V[i-1] > V[i] {
			ev[newFraction(int64(X[i-1]-X[i]), int64(V[i]-V[i-1]))] = append(ev[newFraction(int64(X[i-1]-X[i]), int64(V[i]-V[i-1]))], node{i, 1})
		}
	}

	type F func(a, b matrix) matrix
	f := func(a, b matrix) matrix {
		return a.mul(b)
	}

	seg := make([]matrix, N)
	for i := 0; i < N; i++ {
		u := newMatrix(4)
		u.A[0][0] = Q[i]
		u.A[1][0] = Q[i]
		u.A[2][2] = Q[i]
		u.A[3][2] = Q[i]
		u.A[0][1] = P[i]
		u.A[1][1] = P[i]
		u.A[2][3] = P[i]
		u.A[3][3] = P[i]
		seg[i] = u
	}

	ret := modint(0)

	for p, vs := range ev {
		for _, tt := range vs {
			now := seg[tt.right]
			if tt.typ == 0 {
				now.A[0][0] = 0
				now.A[0][2] = Q[tt.right]
			} else if tt.typ == 1 {
				now.A[1][1] = 0
				now.A[1][3] = P[tt.right]
			} else {
				now.A[1][0] = 0
				now.A[1][2] = Q[tt.right]
			}
			seg[tt.right] = now
		}
		uku := seg[1]
		sum := uku.A[0][2].add(uku.A[0][3])
		ret = ret.add(modint(p.num).divInt(p.dom).mul(sum))
		for _, tt := range vs {
			now := seg[tt.right]
			if tt.typ == 0 {
				now.A[0][2] = 0
				now.A[2][2] = 0
			} else if tt.typ == 1 {
				now.A[1][3] = 0
				now.A[3][3] = 0
			} else {
				now.A[1][2] = 0
				now.A[3][2] = 0
			}
			seg[tt.right] = now
		}
	}

	fmt.Println(ret)
}
