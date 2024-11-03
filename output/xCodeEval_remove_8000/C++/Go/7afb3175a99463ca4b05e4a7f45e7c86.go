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
		m %= n
		if m == 0 {
			return n, x, y
		}
		x -= pdt(q, xx)
		y -= pdt(q, yy)
		q = n / m
		n %= m
		if n == 0 {
			return m, x, y
		}
		xx -= pdt(q, x)
		yy -= pdt(q, y)
	}
}

type Int struct {
	val int
}

func (i *Int) add(rhs int) {
	i.val = sum(i.val, rhs)
}

func (i Int) addInt(rhs int) Int {
	return Int{sum(i.val, rhs)}
}

func (i *Int) sub(rhs int) {
	i.val -= rhs
	if i.val < 0 {
		i.val += MOD
	}
}

func (i Int) subInt(rhs int) Int {
	return Int{pdt(i.val, rhs)}
}

func (i *Int) mul(rhs int) {
	i.val = pdt(i.val, rhs)
}

func (i Int) mulInt(rhs int) Int {
	return Int{pdt(i.val, rhs)}
}

func (i *Int) div(rhs int) {
	i.val = pdt(i.val, _I(rhs))
}

func (i Int) divInt(rhs int) Int {
	return Int{pdt(i.val, _I(rhs))}
}

func _I(b int) int {
	a := MOD
	x1, x2 := 0, 1
	for {
		q := a / b
		a %= b
		if a == 0 {
			return x2
		}
		x1 -= pdt(q, x2)
		q = b / a
		b %= a
		if b == 0 {
			return x1
		}
		x2 -= pdt(q, x1)
	}
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
			if s&(1<<i) != 0 {
				f[s^1<<i] |= f[s]
			}
		}
	}

	for s := 0; s < 1<<m; s++ {
		step := countBits(s) + 1
		for i := 0; i < m; i++ {
			if s&(1<<i) == 0 {
				d := f[s|1<<i] ^ f[s]
				ok[step] += countBits(d)
			}
		}
	}

	ans := 0.0
	for i := 0; i < m; i++ {
		if ok[i] != 0 {
			t := float64(ok[i] * i)
			for j := i - 1; j >= 0; j-- {
				t *= float64(j)
			}
			for j := m - i + 1; j <= m; j++ {
				t /= float64(j)
			}
			ans += t
		}
	}

	ans /= float64(n)
	fmt.Printf("%.15f\n", ans)
}

func countBits(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}
