package main

import (
	"fmt"
	"math"
	"sort"
)

var wmem []byte
var N int
var A, B, C []int
var g wgraph[int]
var arr [1001]int
var as int
var r int
var ok [1001]int
var dp [1001]int
var back [1001]int

func id1[T any](arr **[]T, x int) {
	skip := [16]int{0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	wmem = append(wmem, make([]byte, skip[int(uintptr(unsafe.Pointer(&wmem[0]))&15)])...)
	*arr = new([]T)
}

func rd() int {
	var x int
	fmt.Scan(&x)
	return x
}

func wt_L(a interface{}) {
	fmt.Print(a)
}

func chmin[S comparable](a *S, b S) {
	if *a > b {
		*a = b
	}
}

type DijkstraHeap[T any] struct {
	val    []T
	visited []bool
	hp     []int
	place  []int
	size   int
}

func (hp *DijkstraHeap[T]) malloc(N int) {
	hp.hp = make([]int, N)
	hp.place = make([]int, N)
	hp.visited = make([]bool, N)
	hp.val = make([]T, N)
}

func (hp *DijkstraHeap[T]) init(N int) {
	hp.size = 0
	for i := 0; i < N; i++ {
		hp.place[i] = -1
		hp.visited[i] = false
	}
}

func (hp *DijkstraHeap[T]) up(n int) {
	var m int
	for n > 0 {
		m = (n - 1) / 2
		if hp.val[hp.hp[m]] <= hp.val[hp.hp[n]] {
			break
		}
		hp.hp[m], hp.hp[n] = hp.hp[n], hp.hp[m]
		hp.place[hp.hp[m]], hp.place[hp.hp[n]] = hp.place[hp.hp[n]], hp.place[hp.hp[m]]
		n = m
	}
}

func (hp *DijkstraHeap[T]) down(n int) {
	var m int
	for {
		m = 2*n + 1
		if m >= hp.size {
			break
		}
		if m+1 < hp.size && hp.val[hp.hp[m]] > hp.val[hp.hp[m+1]] {
			m++
		}
		if hp.val[hp.hp[m]] >= hp.val[hp.hp[n]] {
			break
		}
		hp.hp[m], hp.hp[n] = hp.hp[n], hp.hp[m]
		hp.place[hp.hp[m]], hp.place[hp.hp[n]] = hp.place[hp.hp[n]], hp.place[hp.hp[m]]
		n = m
	}
}

func (hp *DijkstraHeap[T]) change(n int, v T) {
	if hp.visited[n] || (hp.place[n] >= 0 && hp.val[n] <= v) {
		return
	}
	hp.val[n] = v
	if hp.place[n] == -1 {
		hp.place[n] = hp.size
		hp.hp[hp.size] = n
		hp.size++
		hp.up(hp.place[n])
	} else {
		hp.up(hp.place[n])
	}
}

func (hp *DijkstraHeap[T]) pop() int {
	res := hp.hp[0]
	hp.place[res] = -1
	hp.size--
	if hp.size > 0 {
		hp.hp[0] = hp.hp[hp.size]
		hp.place[hp.hp[0]] = 0
		hp.down(0)
	}
	hp.visited[res] = true
	return res
}

type graph struct {
	N    int
	edge [][]int
	es   []int
}

func (g *graph) setEdge(N__, M int, A, B []int) {
	g.N = N__
	g.es = make([]int, N__)
	g.edge = make([][]int, N__)
	for i := 0; i < N__; i++ {
		g.es[i] = 0
	}
	for i := 0; i < M; i++ {
		g.es[A[i]]++
		g.es[B[i]]++
	}
	for i := 0; i < N__; i++ {
		g.edge[i] = make([]int, g.es[i])
	}
	for i := 0; i < N__; i++ {
		g.es[i] = 0
	}
	for i := 0; i < M; i++ {
		g.edge[A[i]][g.es[A[i]]] = B[i]
		g.edge[B[i]][g.es[B[i]]] = A[i]
		g.es[A[i]]++
		g.es[B[i]]++
	}
}

func dfs2(n, b int) int {
	res := 1
	for i := 0; i < len(g.edge[n]); i++ {
		k := g.edge[n][i]
		if k == b {
			continue
		}
		res += dfs2(k, n)
	}
	return res
}

func dfs(n, b, d, m, dm int) {
	for i := 0; i < len(g.edge[n]); i++ {
		if n == r && ok[i] == dm {
			continue
		}
		k := g.edge[n][i]
		if k == b {
			continue
		}
		cnt++
		g.cost[n][i] = m * (cnt - d)
		dfs(k, n, cnt, m, dm)
	}
}

func main() {
	wmem = make([]byte, 96000000)
	N = rd()
	A = make([]int, N-1)
	B = make([]int, N-1)
	for i := 0; i < N-1; i++ {
		A[i] = rd() - 1
		B[i] = rd() - 1
	}
	g.setEdge(N, N-1, A, B)
	for r = 0; r < N; r++ {
		as = 0
		for i := 0; i < len(g.edge[r]); i++ {
			arr[as] = dfs2(g.edge[r][i], r)
			as++
		}
		for i := 0; i < N+1; i++ {
			dp[i] = 0
		}
		dp[0] = 1
		for i := 0; i < as; i++ {
			for j := N; j >= arr[i]; j-- {
				if !dp[j] && dp[j-arr[i]] {
					dp[j] = 1
					back[j] = i
				}
			}
		}
		for p := 0; p < N+1; p++ {
			if dp[p] && (p+1)*(N-p)-1 >= 2*N*N/9 {
				break
			}
		}
		if p == N+1 {
			continue
		}
		k := p
		for k > 0 {
			ok[back[k]] = 1
			k -= arr[back[k]]
		}
		cnt = 0
		dfs(r, -1, 0, 1, 0)
		cnt = 0
		dfs(r, -1, 0, p+1, 1)
		break
	}
	for i := 0; i < N; i++ {
		for j := 0; j < len(g.edge[i]); j++ {
			k := g.edge[i][j]
			r := g.cost[i][j]
			if r > 0 {
				wt_L(i + 1)
				wt_L(" ")
				wt_L(k + 1)
				wt_L(" ")
				wt_L(r)
				wt_L("\n")
			}
		}
	}
}