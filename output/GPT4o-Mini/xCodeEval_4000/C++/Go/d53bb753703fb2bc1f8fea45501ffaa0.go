package main

import (
	"fmt"
	"math/bits"
)

const (
	INF   = 1e9
	LINF  = 1e18
	M     = 1e9 + 7
	C     = 20
)

type Modular struct {
	value int64
}

var (
	G    [C][]int
	cur  []int
	masks [C]int
	dp   [1 << C]bool
	vis  [C]bool
	mask int
)

func (m *Modular) Add(o Modular) Modular {
	return Modular{(m.value + o.value) % M}
}

func (m *Modular) Sub(o Modular) Modular {
	return Modular{(m.value - o.value + M) % M}
}

func (m *Modular) Mul(o Modular) Modular {
	return Modular{(m.value * o.value) % M}
}

func (m *Modular) Inv() Modular {
	return m.Exp(M - 2)
}

func (m *Modular) Exp(k int64) Modular {
	res := Modular{1}
	a := *m
	for k > 0 {
		if k&1 == 1 {
			res = res.Mul(a)
		}
		a = a.Mul(a)
		k >>= 1
	}
	return res
}

func dfs(v int) {
	vis[v] = true
	mask |= 1 << v
	cur = append(cur, v)

	for _, s := range G[v] {
		if !vis[s] {
			dfs(s)
		}
	}
}

func count() int {
	sub := []int{}
	for m := mask; m > 0; m = (m - 1) & mask {
		sub = append(sub, m)
	}
	
	res := 0
	for _, m := range sub {
		for _, v := range cur {
			if m&(1<<v) != 0 {
				dp[m] = dp[m] || (dp[m^(1<<v)] && ((m&masks[v]&mask) == 0))
			}
		}
		if dp[m] {
			res = max(res, bits.OnesCount(uint(m)))
		}
	}
	return res
}

func solve() int {
	var n int
	fmt.Scan(&n)
	var s, t string
	fmt.Scan(&s, &t)

	get := func(c byte) int {
		return int(c - 'a')
	}

	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(s[i])
			b := get(t[i])
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			masks[a] |= 1 << b
		}
	}

	res := 0
	dp[0] = true
	for i := 0; i < C; i++ {
		if !vis[i] {
			mask = 0
			cur = []int{}
			dfs(i)
			tmp := count()
			res += 2*len(cur) - 1 - tmp
		}
	}

	for i := range vis {
		vis[i] = false
	}
	for i := range masks {
		masks[i] = 0
	}
	for i := range dp {
		dp[i] = false
	}
	for i := range G {
		G[i] = nil
	}

	return res
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		fmt.Println(solve())
		t--
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
