package main

import (
	"fmt"
)

type modint struct {
	v int
}

func (m modint) add(x modint) modint {
	m.v += x.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m modint) sub(x modint) modint {
	m.v += m.mod() - x.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m modint) mul(x modint) modint {
	m.v = m.v * x.v % m.mod()
	return m
}

func (m modint) div(x modint) modint {
	return m.mul(x.inv())
}

func (m modint) pow(n int) modint {
	res := modint{v: 1}
	x := m
	for n > 0 {
		if n&1 == 1 {
			res = res.mul(x)
		}
		x = x.mul(x)
		n >>= 1
	}
	return res
}

func (m modint) inv() modint {
	eg := m.extendedGCD(m.v, m.mod())
	return modint{v: eg.second}
}

func (m modint) mod() int {
	return 998244353
}

func (m modint) extendedGCD(a, b int) (int, int) {
	if b == 0 {
		return a, 1
	}
	d, y := m.extendedGCD(b, a%b)
	return d, y - a/b*y
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	dp := make([]modint, n+1)
	p := make([]modint, n+1)

	dp[n] = modint{v: 1}
	p[n] = modint{v: 1}
	for i := n - 1; i >= 1; i-- {
		dp[i] = dp[i].add(p[i+1])

		for z := 2; uint(z)*uint(i) <= uint(n); z++ {
			r := i*z + z
			l := uint(z) * uint(i)
			dp[i] = dp[i].add(p[l])
			if r <= n {
				dp[i] = dp[i].sub(p[r])
			}
		}

		p[i] = p[i+1].add(dp[i])
	}

	fmt.Println(dp[1].v)
}

func main() {
	solve()
}
