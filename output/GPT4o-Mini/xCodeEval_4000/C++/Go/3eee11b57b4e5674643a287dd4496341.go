package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	INF = math.MaxInt64
	MOD = 1000000007
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
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
		a[i]--
	}

	sum := make([][]int64, 100)
	for i := range sum {
		sum[i] = make([]int64, n+1)
	}

	b := make([][]int, 100)
	for i := 0; i < n; i++ {
		sum[a[i]][i+1]++
		b[a[i]] = append(b[a[i]], i)
	}

	for i := 0; i < 100; i++ {
		for j := 0; j < n; j++ {
			sum[i][j+1] += sum[i][j]
		}
	}

	find := func() int {
		mx := int64(0)
		ret := -1
		for i := 0; i < 100; i++ {
			if sum[i][n] > mx {
				mx = sum[i][n]
				ret = i
			}
		}
		return ret
	}

	i := find()
	ans := 0
	mp := make([]int, 404040)
	for j := range mp {
		mp[j] = -1
	}

	for j := 0; j < 100; j++ {
		if i == j {
			continue
		}
		if len(b[i]) == 0 || len(b[j]) == 0 {
			continue
		}
		x, y := 0, 0
		now := 202020
		mp[202020] = 0
		era := []int{}

		for {
			nex := func(x, y int) (int, int) {
				if x < len(b[i]) && y < len(b[j]) {
					if b[i][x] < b[j][y] {
						return 1, b[i][x]
					}
					return -1, b[j][y]
				} else if x < len(b[i]) {
					return 1, b[i][x]
				} else if y < len(b[j]) {
					return -1, b[j][y]
				}
				return -2, 0
			}
			tmp := nex(x, y)
			if tmp[0] == -2 {
				break
			}
			if tmp[0] == 1 {
				x++
			} else {
				y++
			}
			now += tmp[0]
			if mp[now] != -1 {
				tmp = nex(x, y)
				if tmp[0] == -2 {
					ans = max(ans, n-mp[now])
				} else {
					ans = max(ans, tmp[1]-mp[now])
				}
			} else {
				mp[now] = tmp[1] + 1
				era = append(era, now)
			}
		}
		for _, e := range era {
			mp[e] = -1
		}
	}
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
