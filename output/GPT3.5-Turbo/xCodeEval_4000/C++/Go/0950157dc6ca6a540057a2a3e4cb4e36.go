package main

import (
	"fmt"
)

const MOD = 10007

type Field int

func (f Field) Add(a, b Field) Field {
	return (a + b) % MOD
}

func (f Field) Subtract(a, b Field) Field {
	return (a - b + MOD) % MOD
}

func (f Field) Multiply(a, b Field) Field {
	return (a * b) % MOD
}

func (f Field) Power(a Field, n int) Field {
	if n == 0 {
		return 1
	}
	if n == 1 {
		return a
	}
	res := f.Power(a, n/2)
	res = f.Multiply(res, res)
	if n%2 == 1 {
		res = f.Multiply(res, a)
	}
	return res
}

func (f Field) Inverse(a Field) Field {
	return f.Power(a, MOD-2)
}

type Polynomial []Field

func (p Polynomial) Degree() int {
	return len(p) - 1
}

func (p Polynomial) Normalize() Polynomial {
	for len(p) > 0 && p[len(p)-1] == 0 {
		p = p[:len(p)-1]
	}
	return p
}

func (p Polynomial) Add(q Polynomial) Polynomial {
	n := len(p)
	m := len(q)
	res := make(Polynomial, max(n, m))
	for i := 0; i < n; i++ {
		res[i] = p[i]
	}
	for i := 0; i < m; i++ {
		res[i] = f.Add(res[i], q[i])
	}
	return res.Normalize()
}

func (p Polynomial) Subtract(q Polynomial) Polynomial {
	n := len(p)
	m := len(q)
	res := make(Polynomial, max(n, m))
	for i := 0; i < n; i++ {
		res[i] = p[i]
	}
	for i := 0; i < m; i++ {
		res[i] = f.Subtract(res[i], q[i])
	}
	return res.Normalize()
}

func (p Polynomial) Multiply(q Polynomial) Polynomial {
	n := len(p)
	m := len(q)
	res := make(Polynomial, n+m-1)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res[i+j] = f.Add(res[i+j], f.Multiply(p[i], q[j]))
		}
	}
	return res.Normalize()
}

func (p Polynomial) MultiplyScalar(a Field) Polynomial {
	n := len(p)
	res := make(Polynomial, n)
	for i := 0; i < n; i++ {
		res[i] = f.Multiply(p[i], a)
	}
	return res.Normalize()
}

func (p Polynomial) DivideScalar(a Field) Polynomial {
	n := len(p)
	res := make(Polynomial, n)
	for i := 0; i < n; i++ {
		res[i] = f.Multiply(p[i], f.Inverse(a))
	}
	return res.Normalize()
}

func (p Polynomial) ShiftLeft(k int) Polynomial {
	n := len(p)
	res := make(Polynomial, n+k)
	for i := 0; i < n; i++ {
		res[i+k] = p[i]
	}
	return res.Normalize()
}

func (p Polynomial) ShiftRight(k int) Polynomial {
	n := len(p)
	if k >= n {
		return Polynomial{}
	}
	res := make(Polynomial, n-k)
	for i := k; i < n; i++ {
		res[i-k] = p[i]
	}
	return res.Normalize()
}

func (p Polynomial) ModFunction() Polynomial {
	n := len(p)
	res := make(Polynomial, n+1)
	res[n] = 1
	for i := 0; i < n; i++ {
		res[i] = -p[n-i-1]
	}
	return res.Normalize()
}

func (p Polynomial) Compute(K int, n int) Polynomial {
	if n == 0 {
		return Polynomial{}
	}
	if n == 1 {
		return Polynomial{p[K]}
	}
	cons := min(n, len(p))
	res := make(Polynomial, cons)
	for j := 0; j < cons; j++ {
		acc := Field(0)
		for i := 0; i < len(p); i++ {
			if K+j-i-1 >= 0 && K+j-i-1 < len(p) {
				acc = f.Add(acc, f.Multiply(p[i], p[K+j-i-1]))
			}
		}
		res[j] = acc
	}
	return res.Normalize()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

var f Field

func go(left, right, i int) Field {
	if i < 0 {
		return 0
	}
	if i == 0 && left >= right {
		return 1
	}
	dp := make([][][]Field, N)
	ok := make([][][]bool, N)
	for i := 0; i < N; i++ {
		dp[i] = make([][]Field, N)
		ok[i] = make([][]bool, N)
		for j := 0; j < N; j++ {
			dp[i][j] = make([]Field, 10*N)
			ok[i][j] = make([]bool, 10*N)
		}
	}
	res := Field(0)
	if ok[left][right][i] {
		return dp[left][right][i]
	}
	res = 0
	if left >= right {
		res += go(left, right, max(i-2, 0)) * 26
	} else if left+1 == right {
		if i == 0 {
			res += go(left+1, right-1, i)
		} else {
			res += go(left+1, right, i-1)
		}
		res += go(left, right, i-2) * 25
	} else {
		if s[left] == s[right-1] {
			res += go(left+1, right-1, i)
			res += go(left, right, i-2) * 25
		} else {
			res += go(left+1, right, i-1)
			res += go(left, right-1, i-1)
			res += go(left, right, i-2) * 24
		}
	}
	ok[left][right][i] = true
	dp[left][right][i] = res
	return res
}

func main() {
	var s string
	fmt.Scan(&s)
	var n int
	fmt.Scan(&n)

	f = Field(0)
	base := make([]Field, 10*len(s))
	for i := 0; i < 10*len(s); i++ {
		base[i] = go(0, len(s), i)
	}

	fmt.Println(base)
}
