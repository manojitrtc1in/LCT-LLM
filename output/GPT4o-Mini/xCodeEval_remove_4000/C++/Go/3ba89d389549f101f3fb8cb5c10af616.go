package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const INF = 1 << 60

type Edge struct {
	to, cap, rev int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, cap, int64(len((*G)[to]))})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, revCap, int64(len((*G)[from]) - 1)})
	}
}

func id1(G *Graph, v, t, f int64, used []bool) int64 {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := (*G)[v][i]
		if !used[e.to] && e.cap > 0 {
			d := id1(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int64) int64 {
	flow := int64(0)
	for {
		used := make([]bool, len(*G))
		f := id1(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func dfs(G *Graph, v, t int64, st *map[int64]struct{}, used []int64, s int64) {
	used[v] = 1
	if v != s {
		(*st)[v] = struct{}{}
	}
	if v == t {
		return
	}
	if v != s {
		for _, e := range (*G)[v] {
			to := e.to
			if used[to] == 0 {
				dfs(G, to, t, st, used, s)
			} else if used[to] == 2 {
				(*st)[t] = struct{}{}
			}
		}
	} else {
		for _, e := range (*G)[v] {
			to := e.to
			if used[to] != 0 {
				continue
			}
			dfs(G, to, t, st, used, s)
			if _, found := (*st)[t]; found {
				for itr := range *st {
					used[itr] = 2
				}
			}
			*st = make(map[int64]struct{})
		}
	}
}

func solve() {
	var n, m, a, b int64
	fmt.Scan(&n, &m, &a, &b)
	a--
	b--
	G := make(Graph, n)
	for i := int64(0); i < m; i++ {
		var u, v int64
		fmt.Scan(&u, &v)
		u--
		v--
		addEdge(&G, u, v, 1, true, 1)
	}
	used := make([]int64, n)
	st := make(map[int64]struct{})
	dfs(&G, a, b, &st, used, a)
	s, t := int64(0), int64(0)
	for i := int64(0); i < n; i++ {
		if used[i] == 1 {
			s++
		} else if used[i] == 0 {
			t++
		}
	}
	s--
	fmt.Println(s * t)
}

func main() {
	var t int64
	fmt.Scan(&t)
	for i := int64(0); i < t; i++ {
		solve()
	}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
