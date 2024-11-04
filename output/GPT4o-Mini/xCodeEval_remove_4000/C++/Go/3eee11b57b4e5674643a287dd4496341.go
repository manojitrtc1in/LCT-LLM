package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	MOD   = 1000000007
	INF   = 1 << 62
	EPS   = 1e-10
)

type P struct {
	first, second int64
}

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, len((*G)[to]) + (from == to), cap})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, len((*G)[from]) - 1, revCap})
	}
}

func id1(G *Graph, v, t int, f int64, used []bool) int64 {
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

func maxFlow(G *Graph, s, t int) int64 {
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

func findMaxIndex(sum [][]int64, n int) int {
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

	i := findMaxIndex(sum, n)
	ans := 0
	mp := make([]int, 404040)
	for i := range mp {
		mp[i] = -1
	}

	for j := 0; j < 100; j++ {
		if i == j || len(b[i]) == 0 || len(b[j]) == 0 {
			continue
		}
		x, y := 0, 0
		now := 202020
		mp[202020] = 0
		era := []int{}

		for {
			var tmp struct {
				first  int
				second int
			}
			if x < len(b[i]) && y < len(b[j]) {
				if b[i][x] < b[j][y] {
					tmp = struct {
						first  int
						second int
					}{1, b[i][x]}
				} else {
					tmp = struct {
						first  int
						second int
					}{-1, b[j][y]}
				}
			} else if x < len(b[i]) {
				tmp = struct {
					first  int
					second int
				}{1, b[i][x]}
			} else if y < len(b[j]) {
				tmp = struct {
					first  int
					second int
				}{-1, b[j][y]}
			} else {
				break
			}

			if tmp.first == 1 {
				x++
			} else {
				y++
			}
			now += int(tmp.first)

			if mp[now] != -1 {
				if tmp.first == 1 {
					tmp = struct {
						first  int
						second int
					}{1, b[i][x]}
				} else {
					tmp = struct {
						first  int
						second int
					}{-1, b[j][y]}
				}
				if tmp.first == -2 {
					ans = max(ans, n-mp[now])
				} else {
					ans = max(ans, tmp.second-mp[now])
				}
			} else {
				mp[now] = tmp.second + 1
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
