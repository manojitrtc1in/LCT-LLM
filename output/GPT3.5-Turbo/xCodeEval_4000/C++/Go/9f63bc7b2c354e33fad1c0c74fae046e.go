package main

import (
	"fmt"
)

type mint struct {
	v int
}

func (m mint) val() int {
	return m.v
}

func (m *mint) increment() {
	m.v++
}

func (m *mint) decrement() {
	m.v--
}

func (m *mint) add(rhs mint) {
	m.v += rhs.v
}

func (m *mint) subtract(rhs mint) {
	m.v -= rhs.v
}

func (m *mint) multiply(rhs mint) {
	m.v *= rhs.v
}

func (m *mint) divide(rhs mint) {
	m.v /= rhs.v
}

func (m mint) pow(n int) mint {
	x := m
	r := mint{v: 1}
	for n > 0 {
		if n&1 == 1 {
			r.multiply(x)
		}
		x.multiply(x)
		n >>= 1
	}
	return r
}

func (m mint) inverse() mint {
	return m.pow(m.mod() - 2)
}

func (m mint) mod() int {
	return 998244353
}

func get(i, z int) int {
	l1 := 1 * i * z
	r1 := 1 * (i + i) * z

	ans := l1

	for l1 <= r1 {
		m := (l1 + r1) / 2
		if m/z > i {
			r1 = m - 1
		} else {
			ans = max(ans, m)
			l1 = m + 1
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
	p := make([]mint, n+1)

	dp[n] = mint{v: 1}
	p[n] = mint{v: 1}
	for i := n - 1; i >= 1; i-- {
		dp[i].add(p[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
			dp[i].add(p[l])
			if r <= n {
				dp[i].subtract(p[r])
			}
		}

		p[i].add(p[i+1])
		p[i].add(dp[i])
	}

	fmt.Println(dp[1].val())
}

func main() {
	solve()
}
