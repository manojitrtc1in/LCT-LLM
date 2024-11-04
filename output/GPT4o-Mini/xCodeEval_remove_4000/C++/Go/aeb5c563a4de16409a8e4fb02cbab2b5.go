package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	mPi   = 3.1415926535897932
	MOD   = 1000000007
	INF   = 1 << 62
	EPS   = 1e-10
)

type Pair struct {
	first, second int64
}

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, len((*G)[to]) + int(from == to), cap})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, len((*G)[from]) - 1, revCap})
	}
}

func id0(G *Graph, v, t int, f int64, used []bool) int64 {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := (*G)[v][i]
		if !used[e.to] && e.cap > 0 {
			d := id0(G, e.to, t, min(f, e.cap), used)
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
		f := id0(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func Dijkstra(G *Graph, s int, d *[]int64) {
	*d = make([]int64, len(*G))
	for i := range *d {
		(*d)[i] = INF
	}
	(*d)[s] = 0
	q := &PriorityQueue{}
	heap.Push(q, Pair{0, int64(s)})
	for q.Len() > 0 {
		a := heap.Pop(q).(Pair)
		if (*d)[a.second] < a.first {
			continue
		}
		for i := 0; i < len((*G)[a.second]); i++ {
			e := (*G)[a.second][i]
			if (*d)[e.to] > (*d)[a.second]+e.cap {
				(*d)[e.to] = (*d)[a.second] + e.cap
				heap.Push(q, Pair{(*d)[e.to], e.to})
			}
		}
	}
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	a := make([][]int64, n)
	for i := range a {
		var t int64
		fmt.Scan(&t)
		for j := int64(0); j < t; j++ {
			var tmp int64
			fmt.Scan(&tmp)
			if len(a[i]) < int(k) {
				a[i] = append(a[i], tmp)
			}
		}
	}
	w := make([]int64, n)
	for i := range w {
		for _, val := range a[i] {
			w[i] += val
		}
	}
	ans := int64(0)
	solve := func(dp []int64, l, r int64) {
		if r-l == 1 {
			sum := int64(0)
			for i := int64(0); i <= int64(len(a[l])); i++ {
				ans = max(ans, dp[k-i]+sum)
				if i != int64(len(a[l])) {
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
				if int64(len(a[i]))+j <= k {
					dp2[j+int64(len(a[i]))] = max(dp2[j+int64(len(a[i]))], dp2[j]+w[i])
				}
			}
		}
		solve(dp2, l, m)
		for i := l; i < m; i++ {
			for j := k - 1; j >= 0; j-- {
				if int64(len(a[i]))+j <= k {
					dp[j+int64(len(a[i]))] = max(dp[j+int64(len(a[i]))], dp[j]+w[i])
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

type PriorityQueue []Pair

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].first < pq[j].first
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Pair))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}
