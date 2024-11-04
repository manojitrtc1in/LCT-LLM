package main

import (
	"fmt"
)

type mint struct {
	v int
}

func (m *mint) add(a mint) {
	m.v += a.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
}

func (m *mint) sub(a mint) {
	m.v += m.mod() - a.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
}

func (m *mint) mul(a mint) {
	m.v = (m.v * a.v) % m.mod()
}

func (m *mint) div(a mint) {
	m.mul(a.inv())
}

func (m *mint) inv() mint {
	return m.pow(m.mod() - 2)
}

func (m *mint) pow(n int) mint {
	x := *m
	r := mint{1}
	for n > 0 {
		if n&1 == 1 {
			r.mul(x)
		}
		x.mul(x)
		n >>= 1
	}
	return r
}

func (m *mint) mod() int {
	return 998244353
}

func get(i, z int) int {
	l := i * z
	r := (i + i) * z

	ans := l

	for l <= r {
		m := (l + r) / 2
		if m/z > i {
			r = m - 1
		} else {
			ans = max(ans, m)
			l = m + 1
		}
	}

	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	dp := make([]mint, n+1)
	p1 := make([]mint, n+1)

	dp[n] = mint{1}
	p1[n] = mint{1}

	for i := n - 1; i >= 1; i-- {
		dp[i].add(p1[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
			dp[i].add(p1[l])
			if r <= n {
				dp[i].sub(p1[r])
			}
		}

		p1[i] = p1[i+1]
		p1[i].add(dp[i])
	}

	fmt.Println(dp[1].v)
}

func main() {
	solve()
}
