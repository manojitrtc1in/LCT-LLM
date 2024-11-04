package main

import (
	"fmt"
)

type mint struct {
	v int
}

func (m mint) add(a mint) mint {
	m.v += a.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m mint) sub(a mint) mint {
	m.v += m.mod() - a.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m mint) mul(a mint) mint {
	m.v = m.v * a.v % m.mod()
	return m
}

func (m mint) div(a mint) mint {
	return m.mul(a.inv())
}

func (m mint) inv() mint {
	return m.pow(m.mod() - 2)
}

func (m mint) pow(n int) mint {
	res := mint{1}
	for n > 0 {
		if n&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		n >>= 1
	}
	return res
}

func (m mint) mod() int {
	return 998244353
}

func solve(n, m int) int {
	ways := make([]mint, n+1)
	extras := make([]mint, n+1)
	ways[1] = mint{1}
	sum := mint{0}
	extra := mint{0}
	for i := 1; i <= n; i++ {
		ways[i] = ways[i].add(sum)
		extra = extra.add(extras[i])
		ways[i] = ways[i].add(extra)
		for j := 2; i*j <= n; j++ {
			extras[i*j] = extras[i*j].add(ways[i])
			if (i+1)*j <= n {
				extras[(i+1)*j] = extras[(i+1)*j].sub(ways[i])
			}
		}
		sum = sum.add(ways[i])
	}
	return ways[n].v
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	ans := solve(n, m)
	fmt.Println(ans)
}
