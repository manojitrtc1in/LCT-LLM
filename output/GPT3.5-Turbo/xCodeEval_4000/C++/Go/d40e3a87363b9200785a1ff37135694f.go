package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type modint int

func newModInt(x int64) modint {
	x %= int64(mod)
	if x < 0 {
		x += int64(mod)
	}
	return modint(x)
}

func (a modint) add(b modint) modint {
	c := int64(a) + int64(b)
	if c >= int64(mod) {
		c -= int64(mod)
	}
	return modint(c)
}

func (a modint) sub(b modint) modint {
	c := int64(a) - int64(b)
	if c < 0 {
		c += int64(mod)
	}
	return modint(c)
}

func (a modint) mul(b modint) modint {
	return modint(int64(a) * int64(b) % int64(mod))
}

func (a modint) inv() modint {
	b, u, v := int64(mod), int64(1), int64(0)
	for b > 0 {
		t := a / modint(b)
		a -= t * modint(b)
		a, b = modint(b), a
		u -= t * modint(v)
		u, v = modint(v), u
	}
	if u < 0 {
		u += modint(mod)
	}
	return modint(u)
}

func (a modint) div(b modint) modint {
	return a.mul(b.inv())
}

func (a modint) pow(b int64) modint {
	if b < 0 {
		a = a.inv()
		b = -b
	}
	res := modint(1)
	pow := a
	for b > 0 {
		if b&1 == 1 {
			res = res.mul(pow)
		}
		pow = pow.mul(pow)
		b >>= 1
	}
	return res
}

func (a modint) equal(b modint) bool {
	return a == b
}

func (a modint) notEqual(b modint) bool {
	return a != b
}

func (a modint) lessThan(b modint) bool {
	return a < b
}

func (a modint) lessThanOrEqual(b modint) bool {
	return a <= b
}

func (a modint) greaterThan(b modint) bool {
	return a > b
}

func (a modint) greaterThanOrEqual(b modint) bool {
	return a >= b
}

func (a modint) String() string {
	return fmt.Sprintf("%d", int64(a))
}

type fraction struct {
	num, dom int64
}

func newFraction(n, d int64) fraction {
	if d < 0 {
		n *= -1
		d *= -1
	}
	g := gcd(abs(n), abs(d))
	n /= g
	d /= g
	return fraction{n, d}
}

func (a fraction) add(b fraction) fraction {
	num := a.num*b.dom + b.num*a.dom
	dom := a.dom * b.dom
	return newFraction(num, dom)
}

func (a fraction) sub(b fraction) fraction {
	num := a.num*b.dom - b.num*a.dom
	dom := a.dom * b.dom
	return newFraction(num, dom)
}

func (a fraction) mul(b fraction) fraction {
	num := a.num * b.num
	dom := a.dom * b.dom
	return newFraction(num, dom)
}

func (a fraction) div(b fraction) fraction {
	num := a.num * b.dom
	dom := a.dom * b.num
	return newFraction(num, dom)
}

func (a fraction) mulInt(k int64) fraction {
	num := a.num * k
	return newFraction(num, a.dom)
}

func (a fraction) divInt(k int64) fraction {
	dom := a.dom * k
	return newFraction(a.num, dom)
}

func (a fraction) equal(b fraction) bool {
	return a.num*b.dom == b.num*a.dom
}

func (a fraction) notEqual(b fraction) bool {
	return a.num*b.dom != b.num*a.dom
}

func (a fraction) lessThan(b fraction) bool {
	return a.num*b.dom < b.num*a.dom
}

func (a fraction) lessThanOrEqual(b fraction) bool {
	return a.num*b.dom <= b.num*a.dom
}

func (a fraction) greaterThan(b fraction) bool {
	return a.num*b.dom > b.num*a.dom
}

func (a fraction) greaterThanOrEqual(b fraction) bool {
	return a.num*b.dom >= b.num*a.dom
}

func (a fraction) String() string {
	return fmt.Sprintf("%d/%d", a.num, a.dom)
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
	mat := matrix{}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				mat.A[i][j] = 1
			} else {
				mat.A[i][j] = 0
			}
		}
	}
	return mat
}

func (a matrix) add(b matrix) matrix {
	c := matrix{}
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			c.A[i][j] = a.A[i][j].add(b.A[i][j])
		}
	}
	return c
}

func (a matrix) sub(b matrix) matrix {
	c := matrix{}
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			c.A[i][j] = a.A[i][j].sub(b.A[i][j])
		}
	}
	return c
}

func (a matrix) mul(b matrix) matrix {
	c := matrix{}
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			for k := 0; k < 4; k++ {
				c.A[i][j] = c.A[i][j].add(a.A[i][k].mul(b.A[k][j]))
			}
		}
	}
	return c
}

func (a matrix) pow(k int64) matrix {
	b := newMatrix(4)
	for k > 0 {
		if k&1 == 1 {
			b = b.mul(a)
		}
		a = a.mul(a)
		k >>= 1
	}
	return b
}

func (a matrix) String() string {
	res := ""
	for i := 0; i < 4; i++ {
		res += "["
		for j := 0; j < 4; j++ {
			res += fmt.Sprintf("%d", a.A[i][j])
			if j != 3 {
				res += ","
			}
		}
		res += "]\n"
	}
	return res
}

type node struct {
	right int
	typ   int
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
		Q[i] = newModInt(1).sub(P[i])
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

	type segmentTree struct {
		sz  int
		seg []matrix
	}

	newSegmentTree := func(n int) segmentTree {
		sz := 1
		for sz < n {
			sz <<= 1
		}
		seg := make([]matrix, 2*sz)
		return segmentTree{sz, seg}
	}

	st := newSegmentTree(N)
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
		st.seg[i+st.sz] = u
	}
	for k := st.sz - 1; k > 0; k-- {
		st.seg[k] = st.seg[2*k].mul(st.seg[2*k+1])
	}

	ret := newModInt(0)
	for p, vs := range ev {
		for _, tt := range vs {
			now := st.seg[tt.right]
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
			st.seg[tt.right] = now
		}
		uku := st.seg[1]
		sum := uku.A[0][2].add(uku.A[0][3])
		ret = ret.add(newModInt(p.num).divInt(p.dom).mul(sum))
		for _, tt := range vs {
			now := st.seg[tt.right]
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
			st.seg[tt.right] = now
		}
	}
	fmt.Println(ret)
}
