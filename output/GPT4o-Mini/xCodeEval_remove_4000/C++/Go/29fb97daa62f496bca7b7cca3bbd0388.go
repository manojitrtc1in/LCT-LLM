package main

import (
	"fmt"
	"math/rand"
	"time"
)

type ll int64
type db float64
type ldb float64
type str string

type pii struct {
	first, second int
}
type pll struct {
	first, second ll
}
type pdb struct {
	first, second db
}
type pldb struct {
	first, second ldb
}
type pil struct {
	first int
	second ll
}
type pli struct {
	first ll
	second int
}

type vi []int
type vl []ll
type vs []string
type vc []rune
type vb []bool
type vdb []db
type vldb []ldb
type vpii []pii
type vpll []pll
type vpdb []pdb
type vpldb []pldb
type vpil []pil
type vpli []pli
type vvi [][]int

const INF = 1e9
const LINF = 1e18
const M = 1e9 + 7
const C = 20

func dag(g vvi, cur vi) int {
	get := func(v int) int {
		for i, val := range cur {
			if val == v {
				return i
			}
		}
		return -1
	}
	n := len(cur)
	dp := make([]bool, 1<<n)
	reach := make(vi, n)

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
			res = max(res, popcount(m))
		}
	}

	return res
}

func solve() int {
	var n int
	fmt.Scan(&n)
	var s, t str
	fmt.Scan(&s, &t)

	get := func(c rune) int {
		return int(c - 'a')
	}

	G := make([]vi, C)
	g := make([]vi, C)
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(rune(s[i]))
			b := get(rune(t[i]))
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			g[a] = append(g[a], b)
		}
	}

	var cur vi
	vis := make(vb, C)
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

func popcount(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func init() {
	rand.Seed(time.Now().UnixNano())
}
