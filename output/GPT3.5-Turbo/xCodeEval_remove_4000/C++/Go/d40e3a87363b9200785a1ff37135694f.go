package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type modint struct {
	x int
}

func newModInt(y int64) modint {
	y %= int64(mod)
	if y < 0 {
		y += int64(mod)
	}
	return modint{int(y)}
}

func (a modint) add(b modint) modint {
	c := a.x + b.x
	if c >= mod {
		c -= mod
	}
	return modint{c}
}

func (a modint) sub(b modint) modint {
	c := a.x - b.x
	if c < 0 {
		c += mod
	}
	return modint{c}
}

func (a modint) mul(b modint) modint {
	return modint{int(int64(a.x) * int64(b.x) % mod)}
}

func (a modint) pow(n int64) modint {
	ret := modint{1}
	mul := a
	for n > 0 {
		if n&1 == 1 {
			ret = ret.mul(mul)
		}
		mul = mul.mul(mul)
		n >>= 1
	}
	return ret
}

func (a modint) inv() modint {
	return a.pow(int64(mod - 2))
}

func (a modint) div(b modint) modint {
	return a.mul(b.inv())
}

func (a modint) equal(b modint) bool {
	return a.x == b.x
}

func (a modint) notEqual(b modint) bool {
	return a.x != b.x
}

func (a modint) lessThan(b modint) bool {
	return a.x < b.x
}

func (a modint) lessThanOrEqual(b modint) bool {
	return a.x <= b.x
}

func (a modint) greaterThan(b modint) bool {
	return a.x > b.x
}

func (a modint) greaterThanOrEqual(b modint) bool {
	return a.x >= b.x
}

func (a modint) String() string {
	return fmt.Sprintf("%d", a.x)
}

type fraction struct {
	num int64
	dom int64
}

func newFraction(n, d int64) fraction {
	if d == 0 {
		panic("division by zero")
	}
	if d < 0 {
		n = -n
		d = -d
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

func (a fraction) lessThan(b fraction) bool {
	return a.num*b.dom < b.num*a.dom
}

func (a fraction) greaterThan(b fraction) bool {
	return a.num*b.dom > b.num*a.dom
}

func (a fraction) equal(b fraction) bool {
	return a.num*b.dom == b.num*a.dom
}

func (a fraction) notEqual(b fraction) bool {
	return a.num*b.dom != b.num*a.dom
}

func (a fraction) lessThanOrEqual(b fraction) bool {
	return a.num*b.dom <= b.num*a.dom
}

func (a fraction) greaterThanOrEqual(b fraction) bool {
	return a.num*b.dom >= b.num*a.dom
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
	var mat matrix
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i == j {
				mat.A[i][j] = modint{1}
			} else {
				mat.A[i][j] = modint{0}
			}
		}
	}
	return mat
}

func (a matrix) add(b matrix) matrix {
	var c matrix
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			c.A[i][j] = a.A[i][j].add(b.A[i][j])
		}
	}
	return c
}

func (a matrix) sub(b matrix) matrix {
	var c matrix
	for i := 0; i < 4; i++ {
		for j := 0; j < 4; j++ {
			c.A[i][j] = a.A[i][j].sub(b.A[i][j])
		}
	}
	return c
}

func (a matrix) mul(b matrix) matrix {
	var c matrix
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
	for i := 0; i < 4; i++ {
		b.A[i][i] = modint{1}
	}
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
	var res string
	for i := 0; i < 4; i++ {
		res += "["
		for j := 0; j < 4; j++ {
			res += fmt.Sprintf("%v", a.A[i][j])
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
		Q[i] = modint{1}.sub(P[i])
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

	seg := make([]matrix, 2*N)
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
		seg[i+N] = u
	}

	for i := N - 1; i > 0; i-- {
		seg[i] = f(seg[2*i], seg[2*i+1])
	}

	ret := modint{0}

	for p, vs := range ev {
		for _, tt := range vs {
			now := seg[tt.right]
			if tt.typ == 0 {
				now.A[0][0] = modint{0}
				now.A[0][2] = Q[tt.right]
			} else if tt.typ == 1 {
				now.A[1][1] = modint{0}
				now.A[1][3] = P[tt.right]
			} else {
				now.A[1][0] = modint{0}
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
				now.A[0][2] = modint{0}
				now.A[2][2] = modint{0}
			} else if tt.typ == 1 {
				now.A[1][3] = modint{0}
				now.A[3][3] = modint{0}
			} else {
				now.A[1][2] = modint{0}
				now.A[3][2] = modint{0}
			}
			seg[tt.right] = now
		}
	}

	fmt.Println(ret)
}
