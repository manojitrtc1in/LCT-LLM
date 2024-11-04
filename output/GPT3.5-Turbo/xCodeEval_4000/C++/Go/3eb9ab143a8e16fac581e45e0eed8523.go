package main

import (
	"fmt"
)

type mint struct {
	v int
}

func (m *mint) add(x mint) {
	m.v += x.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
}

func (m *mint) sub(x mint) {
	m.v += m.mod() - x.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
}

func (m *mint) mul(x mint) {
	m.v = m.v * x.v % m.mod()
}

func (m *mint) div(x mint) {
	m.mul(x.inv())
}

func (m *mint) pow(n int) {
	res := mint{1}
	x := *m
	for n > 0 {
		if n&1 == 1 {
			res.mul(x)
		}
		x.mul(x)
		n >>= 1
	}
	m.v = res.v
}

func (m *mint) inv() mint {
	a, b := m.v, m.mod()
	u, v := 1, 0
	for b > 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	if u < 0 {
		u += m.mod() / a
	}
	return mint{u}
}

func (m *mint) mod() int {
	return 998244353
}

func solve(n, m int) int {
	ways := make([]mint, n+1)
	extras := make([]mint, n+1)
	ways[1] = mint{1}
	sum := mint{0}
	extra := mint{0}
	for i := 1; i <= n; i++ {
		ways[i].add(sum)
		extra.add(extras[i])
		ways[i].add(extra)
		for j := 2; i*j <= n; j++ {
			extras[i*j].add(ways[i])
			if (i+1)*j <= n {
				extras[(i+1)*j].sub(ways[i])
			}
		}
		sum.add(ways[i])
	}
	return ways[n].v
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	ans := solve(n, m)
	fmt.Println(ans)
}
