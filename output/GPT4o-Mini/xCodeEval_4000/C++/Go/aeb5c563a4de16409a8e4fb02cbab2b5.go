package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	mod   = 998244353
	INF   = math.MaxInt64
	MAXN  = 100005
)

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, cap, int64(len((*G)[to])) + int64(from == to)})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, revCap, int64(len((*G)[from])) - 1})
	}
}

func maxFlowDFS(G *Graph, v, t int, f int64, used []bool) int64 {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := &(*G)[v][i]
		if !used[e.to] && e.cap > 0 {
			d := maxFlowDFS(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int) int64 {
	flow := int64(0)
	for {
		used := make([]bool, len(*G))
		f := maxFlowDFS(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	a := make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		for j := 0; j < t; j++ {
			var tmp int64
			fmt.Scan(&tmp)
			if len(a[i]) < k {
				a[i] = append(a[i], tmp)
			}
		}
	}

	w := make([]int64, n)
	for i := 0; i < n; i++ {
		for _, val := range a[i] {
			w[i] += val
		}
	}

	ans := int64(0)
	solve := func(dp []int64, l, r int) {
		if r-l == 1 {
			sum := int64(0)
			for i := 0; i <= len(a[l]); i++ {
				ans = max(ans, dp[k-i]+sum)
				if i != len(a[l]) {
					sum += a[l][i]
				}
			}
			return
		}
		m := (r + l) / 2
		dp2 := make([]int64, len(dp))
		copy(dp2, dp)
		for i := m; i < r; i++ {
			for j := k - 1; j >= 0; j-- {
				if len(a[i])+j <= k {
					dp2[j+len(a[i])] = max(dp2[j+len(a[i])], dp2[j]+w[i])
				}
			}
		}
		solve(dp2, l, m)
		for i := l; i < m; i++ {
			for j := k - 1; j >= 0; j-- {
				if len(a[i])+j <= k {
					dp[j+len(a[i])] = max(dp[j+len(a[i])], dp[j]+w[i])
				}
			}
		}
		solve(dp, m, r)
	}

	dp := make([]int64, k+1)
	solve(dp, 0, n)
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
