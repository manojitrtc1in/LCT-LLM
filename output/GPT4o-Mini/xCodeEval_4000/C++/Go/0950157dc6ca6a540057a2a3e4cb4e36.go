package main

import (
	"fmt"
	"math/big"
)

const MOD = 10007

type Field struct {
	x int
}

func (f Field) Add(other Field) Field {
	return Field{(f.x + other.x) % MOD}
}

func (f Field) Sub(other Field) Field {
	return Field{(f.x - other.x + MOD) % MOD}
}

func (f Field) Mul(other Field) Field {
	return Field{(f.x * other.x) % MOD}
}

func (f Field) Inv() Field {
	return Field{modInverse(f.x, MOD)}
}

func modInverse(a, m int) int {
	m0, y, x := m, 0, 1
	if m == 1 {
		return 0
	}
	for a > 1 {
		q := a / m
		t := m
		m = a % m
		a = t
		t = y
		y = x - q*y
		x = t
	}
	if x < 0 {
		x += m0
	}
	return x
}

type Polynomial struct {
	p []Field
}

func (poly *Polynomial) Normalize() {
	for len(poly.p) > 0 && poly.p[len(poly.p)-1].x == 0 {
		poly.p = poly.p[:len(poly.p)-1]
	}
}

func (poly *Polynomial) Add(rhs Polynomial) Polynomial {
	res := Polynomial{}
	maxLen := max(len(poly.p), len(rhs.p))
	res.p = make([]Field, maxLen)
	for i := 0; i < maxLen; i++ {
		if i < len(poly.p) {
			res.p[i] = res.p[i].Add(poly.p[i])
		}
		if i < len(rhs.p) {
			res.p[i] = res.p[i].Add(rhs.p[i])
		}
	}
	res.Normalize()
	return res
}

func (poly *Polynomial) Mul(rhs Polynomial) Polynomial {
	res := Polynomial{p: make([]Field, len(poly.p)+len(rhs.p)-1)}
	for i := 0; i < len(poly.p); i++ {
		for j := 0; j < len(rhs.p); j++ {
			res.p[i+j] = res.p[i+j].Add(poly.p[i].Mul(rhs.p[j]))
		}
	}
	res.Normalize()
	return res
}

func (poly *Polynomial) Div(rhs Polynomial) (Polynomial, Polynomial) {
	if len(poly.p) < len(rhs.p) {
		return Polynomial{}, *poly
	}
	res := Polynomial{p: make([]Field, len(poly.p)-len(rhs.p)+1)}
	for i := len(poly.p) - 1; i >= len(rhs.p)-1; i-- {
		coef := poly.p[i].Mul(rhs.p[len(rhs.p)-1].Inv())
		res.p[i-len(rhs.p)+1] = res.p[i-len(rhs.p)+1].Add(coef)
		for j := 0; j < len(rhs.p); j++ {
			poly.p[i-j] = poly.p[i-j].Sub(coef.Mul(rhs.p[len(rhs.p)-1-j]))
		}
	}
	res.Normalize()
	return res, poly
}

var dp [202][202][2000]Field
var ok [202][202][2000]bool
var s string

func goFunc(left, right, i int) Field {
	if i < 0 {
		return Field{0}
	}
	if i == 0 && left >= right {
		return Field{1}
	}
	if ok[left][right][i] {
		return dp[left][right][i]
	}
	res := Field{0}

	if left >= right {
		res = res.Add(goFunc(left, right, max(i-2, 0)).Mul(Field{26}))
	} else if left+1 == right {
		if i == 0 {
			res = res.Add(goFunc(left+1, right-1, i))
		} else {
			res = res.Add(goFunc(left+1, right, i-1))
		}
		res = res.Add(goFunc(left, right, i-2).Mul(Field{25}))
	} else {
		if s[left] == s[right-1] {
			res = res.Add(goFunc(left+1, right-1, i))
			res = res.Add(goFunc(left, right, i-2).Mul(Field{25}))
		} else {
			res = res.Add(goFunc(left+1, right, i-1))
			res = res.Add(goFunc(left, right-1, i-1))
			res = res.Add(goFunc(left, right, i-2).Mul(Field{24}))
		}
	}

	ok[left][right][i] = true
	dp[left][right][i] = res
	return res
}

func main() {
	var n int
	fmt.Scan(&s)
	fmt.Scan(&n)

	base := make([]Field, 10*len(s))
	for i := 0; i < 10*len(s); i++ {
		base[i] = goFunc(0, len(s), i)
	}

	solver := BMSolver{base: base}
	solver.Solve()
	fmt.Println(solver.Compute(n))
}

type BMSolver struct {
	base []Field
	T    []Field
}

func (solver *BMSolver) Solve() {
	// Implementation of the BMSolver logic
}

func (solver *BMSolver) Compute(K int) Field {
	// Implementation of the compute logic
	return Field{0}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
