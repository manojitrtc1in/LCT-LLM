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

func NewModular(v int64) Modular {
	return Modular{(v % M + M) % M}
}

func (a Modular) Add(b Modular) Modular {
	return NewModular(a.value + b.value)
}

func (a Modular) Sub(b Modular) Modular {
	return NewModular(a.value - b.value)
}

func (a Modular) Mul(b Modular) Modular {
	return NewModular(a.value * b.value)
}

func (a Modular) Inv() Modular {
	return a.Exp(M - 2)
}

func (a Modular) Exp(k int64) Modular {
	res := NewModular(1)
	for k > 0 {
		if k&1 == 1 {
			res = res.Mul(a)
		}
		a = a.Mul(a)
		k >>= 1
	}
	return res
}

func (a Modular) String() string {
	return fmt.Sprintf("%d", a.value)
}

func dag(g [][]int, cur []int) int {
	n := len(cur)
	dp := make([]bool, 1<<n)
	reach := make([]int, n)

	get := func(v int) int {
		for i, val := range cur {
			if val == v {
				return i
			}
		}
		return -1
	}

	for i := 0; i < n; i++ {
		for _, s := range g[cur[i]] {
			reach[i] |= 1 << get(s)
		}
	}

	res := 0
	dp[0] = true
	for m := 1; m < (1 << n); m++ {
		for i := 0; i < n; i++ {
			if m&(1<<i) != 0 {
				dp[m] = dp[m] || (dp[m^(1<<i)] && (reach[i]&m) == 0)
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
	s := make([]byte, n)
	t := make([]byte, n)
	fmt.Scan(&s)
	fmt.Scan(&t)

	G := make([][]int, C)
	g := make([][]int, C)

	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := int(s[i] - 'a')
			b := int(t[i] - 'a')
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			g[a] = append(g[a], b)
		}
	}

	var cur []int
	vis := make([]bool, C)

	var dfs func(int)
	dfs = func(v int) {
		vis[v] = true
		cur = append(cur, v)
		for _, s := range G[v] {
			if !vis[s] {
				dfs(s)
			}
		}
	}

	res := 0
	for i := 0; i < C; i++ {
		if !vis[i] {
			cur = nil
			dfs(i)
			s := dag(g, cur)
			res += 2*len(cur) - 1 - s
		}
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
