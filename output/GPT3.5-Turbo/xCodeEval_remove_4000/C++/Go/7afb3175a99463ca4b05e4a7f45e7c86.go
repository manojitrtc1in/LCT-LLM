package main

import (
	"fmt"
	"math"
)

const (
	MOD = int(1e9) + 7
)

func sum(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	return a
}

func pdt(a, b int) int {
	return (a * b) % MOD
}

func gcd(m, n int) (int, int, int) {
	x, y := 1, 0
	xx, yy := 0, 1
	for {
		q := m / n
		m, n = m%n, m
		if m == 0 {
			return n, x, y
		}
		x, xx = xx-q*x, x
		y, yy = yy-q*y, y
	}
}

func _I(b int) int {
	a := MOD
	x1, x2 := 0, 1
	for {
		q := a / b
		a, b = b%a, b
		if a == 0 {
			return x2
		}
		x1, x2 = x2-q*x1, x1
	}
}

type Int struct {
	val int
}

func NewInt(v int) Int {
	v %= MOD
	if v < 0 {
		v += MOD
	}
	return Int{val: v}
}

func (a Int) Add(b int) Int {
	return NewInt(sum(a.val, b))
}

func (a Int) Sub(b int) Int {
	return NewInt(a.val - b)
}

func (a Int) Mul(b int) Int {
	return NewInt(pdt(a.val, b))
}

func (a Int) Div(b int) Int {
	return NewInt(pdt(a.val, _I(b)))
}

func (a Int) Neg() Int {
	return NewInt(MOD - a.val)
}

func (a Int) Int() int {
	return a.val
}

func pow(a int, b int64) int {
	c := 1
	for b > 0 {
		if b&1 == 1 {
			c = pdt(c, a)
		}
		a = pdt(a, a)
		b >>= 1
	}
	return c
}

func main() {
	var n int
	fmt.Scan(&n)

	S := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&S[i])
	}

	m := len(S[0])

	f := make([]int, 1<<m)
	ok := make([]int, m+1)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j {
				s := 0
				for k := 0; k < m; k++ {
					if S[i][k] == S[j][k] {
						s |= 1 << k
					}
				}
				f[s] |= 1 << i
			}
		}
	}

	for s := (1 << m) - 1; s >= 0; s-- {
		for i := 0; i < m; i++ {
			if s&(1<<i) == 0 {
				f[s^1<<i] |= f[s]
			}
		}
	}

	for s := 0; s < 1<<m; s++ {
		step := int(math.Log2(float64(s))) + 1
		for i := 0; i < m; i++ {
			if s&(1<<i) == 0 {
				d := f[s|1<<i] ^ f[s]
				ok[step] += bitsCount(d)
			}
		}
	}

	ans := NewInt(0)
	for i := 0; i < m; i++ {
		if ok[i] != 0 {
			t := NewInt(ok[i])
			for j := i - 1; j >= 0; j-- {
				t = t.Mul(j)
			}
			for j := m - i + 1; j <= m; j++ {
				t = t.Div(j)
			}
			ans = ans.Add(t.Int())
		}
	}

	ans = ans.Div(n)
	fmt.Println(ans.Int())
}

func bitsCount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}
