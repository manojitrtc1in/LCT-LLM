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

type pii struct{ first, second int }
type pll struct{ first, second ll }
type pdb struct{ first, second db }
type pldb struct{ first, second ldb }
type pil struct{ first int; second ll }
type pli struct{ first ll; second int }

type vi []int
type vl []ll
type vs []string
type vc []rune
type vdb []db
type vpldb []pldb
type vpdb []pdb
type vpii []pii
type vpll []pll
type vpil []pil
type vpli []pli

const INF = 1e9
const LINF = 1e18
const M = 1e9 + 7

const C = 20
var G [C]vi
var cur vi
var masks [C]int
var dp [1 << C]bool
var vis [C]bool
var mask int

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
	for m := 0; m < (1 << C); m++ {
		if m&mask != 0 {
			sub = append(sub, m)
		}
	}
	
	res := 0
	for _, m := range sub {
		for _, v := range cur {
			if m&(1<<v) != 0 {
				dp[m] = dp[m] || (dp[m^(1<<v)] && ((m&masks[v]&mask) == 0))
			}
		}
		if dp[m] {
			res = max(res, pct(m))
		}
	}
	return res
}

func solve() int {
	var n int
	fmt.Scan(&n)
	s := make([]rune, n)
	t := make([]rune, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%c", &s[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%c", &t[i])
	}

	get := func(c rune) int {
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
			cur = nil
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

func pct(m int) int {
	// Placeholder for actual implementation
	return 0
}

func init() {
	rand.Seed(time.Now().UnixNano())
}
