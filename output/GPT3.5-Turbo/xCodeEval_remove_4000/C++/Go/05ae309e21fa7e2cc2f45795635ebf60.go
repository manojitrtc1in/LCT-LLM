package main

import (
	"fmt"
)

type graph struct {
	N    int
	edge [][]int
	es   []int
}

type wgraph struct {
	cost [][]int
	g    graph
	N    int
	edge [][]int
	es   []int
}

func (g *graph) setEdge(N int, M int, A []int, B []int, mem *[]interface{}) {
	g.N = N
	g.es = make([]int, N)
	for i := 0; i < N; i++ {
		g.es[i] = 0
	}
	g.edge = make([][]int, N)
	for i := 0; i < N; i++ {
		g.edge[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		g.es[A[i]]++
		g.es[B[i]]++
	}
	for i := 0; i < N; i++ {
		g.edge[i] = make([]int, g.es[i])
	}
	for i := 0; i < N; i++ {
		g.es[i] = 0
	}
	for i := 0; i < M; i++ {
		g.edge[A[i]][g.es[A[i]]] = B[i]
		g.edge[B[i]][g.es[B[i]]] = A[i]
		g.es[A[i]]++
		g.es[B[i]]++
	}
}

func (g *wgraph) setEdge(N int, M int, A []int, B []int, C []int, mem *[]interface{}) {
	g.N = N
	g.es = make([]int, N)
	for i := 0; i < N; i++ {
		g.es[i] = 0
	}
	g.edge = make([][]int, N)
	for i := 0; i < N; i++ {
		g.edge[i] = make([]int, 0)
	}
	g.cost = make([][]int, N)
	for i := 0; i < N; i++ {
		g.cost[i] = make([]int, 0)
	}
	for i := 0; i < M; i++ {
		g.es[A[i]]++
	}
	for i := 0; i < N; i++ {
		g.edge[i] = make([]int, g.es[i])
		g.cost[i] = make([]int, g.es[i])
	}
	for i := 0; i < N; i++ {
		g.es[i] = 0
	}
	for i := 0; i < M; i++ {
		g.edge[A[i]][g.es[A[i]]] = B[i]
		g.cost[A[i]][g.es[A[i]]] = C[i]
		g.es[A[i]]++
	}
	g.g.N = N
	g.g.es = g.es
	g.g.edge = g.edge
}

func dfs2(n int, b int, g *graph) int {
	res := 1
	for i := 0; i < len(g.edge[n]); i++ {
		k := g.edge[n][i]
		if k == b {
			continue
		}
		res += dfs2(k, n, g)
	}
	return res
}

func dfs(n int, b int, d int, m int, dm int, g *graph, cnt *int) {
	for i := 0; i < len(g.edge[n]); i++ {
		if n == r && ok[i] == dm {
			continue
		}
		k := g.edge[n][i]
		if k == b {
			continue
		}
		*cnt++
		g.cost[n][i] = m * (*cnt - d)
		dfs(k, n, *cnt, m, dm, g, cnt)
	}
}

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N-1)
	B := make([]int, N-1)
	for i := 0; i < N-1; i++ {
		fmt.Scan(&A[i])
		A[i]--
		fmt.Scan(&B[i])
		B[i]--
	}
	g := graph{}
	g.setEdge(N, N-1, A, B, nil)
	for r := 0; r < N; r++ {
		as := 0
		for i := 0; i < len(g.edge[r]); i++ {
			as = append(as, dfs2(g.edge[r][i], r, &g))
		}
		dp := make([]int, N+1)
		back := make([]int, N+1)
		dp[0] = 1
		for i := 0; i < len(as); i++ {
			for j := N; j >= as[i]; j-- {
				if dp[j] == 0 && dp[j-as[i]] == 1 {
					dp[j] = 1
					back[j] = i
				}
			}
		}
		p := 0
		for p = 0; p < N+1; p++ {
			if dp[p] == 1 && (p+1)*(N-p)-1 >= 2*N*N/9 {
				break
			}
		}
		if p == N+1 {
			continue
		}
		k := p
		for k > 0 {
			ok[back[k]] = 1
			k -= as[back[k]]
		}
		cnt := 0
		dfs(r, -1, 0, 1, 0, &g, &cnt)
		cnt = 0
		dfs(r, -1, 0, p+1, 1, &g, &cnt)
		break
	}
	for i := 0; i < N; i++ {
		for j := 0; j < len(g.edge[i]); j++ {
			k := g.edge[i][j]
			r := g.cost[i][j]
			if r > 0 {
				fmt.Println(i+1, k+1, r)
			}
		}
	}
}
