package main

import (
	"fmt"
	"math"
)

const MAXN = 3005
const INT_INF = 0x3f3f3f3f
const LL_INF = 0x3f3f3f3f3f3f3f3f

type Pill struct {
	first  int64
	second int64
}

var (
	T, N, M int
	B, W    [MAXN]int
	dp      [MAXN][MAXN]Pill
	merged  [MAXN]Pill
	adj     [MAXN][]int
)

func dfs(v, prev int) int {
	SZV := 1
	dp[v][0] = Pill{0, int64(W[v] - B[v])}
	for _, w := range adj[v] {
		if w != prev {
			SZW := dfs(w, v)
			for i := SZW; i >= 1; i-- {
				dp[w][i] = max(dp[w][i], Pill{dp[w][i-1].first + int64(dp[w][i-1].second > 0), 0})
			}
			for i := 0; i < SZV+SZW; i++ {
				merged[i] = Pill{-INT_INF, -LL_INF}
			}
			for i := 0; i < SZV; i++ {
				for j := 0; j <= SZW; j++ {
					merged[i+j] = max(merged[i+j], Pill{dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second})
				}
			}
			copy(dp[v][:], merged[:SZV+SZW])
			SZV += SZW
		}
	}
	return SZV
}

func max(a, b Pill) Pill {
	if a.first > b.first {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&T)
	for ti := 0; ti < T; ti++ {
		fmt.Scan(&N, &M)
		for i := 0; i < N; i++ {
			fmt.Scan(&B[i])
		}
		for i := 0; i < N; i++ {
			fmt.Scan(&W[i])
		}
		for i := 0; i < N-1; i++ {
			var a, b int
			fmt.Scan(&a, &b)
			adj[a-1] = append(adj[a-1], b-1)
			adj[b-1] = append(adj[b-1], a-1)
		}
		for i := 0; i < N; i++ {
			for j := 0; j <= N; j++ {
				dp[i][j] = Pill{-INT_INF, -LL_INF}
			}
		}
		dfs(0, -1)
		fmt.Println(dp[0][M-1].first + int64(dp[0][M-1].second > 0))
		for i := 0; i < N; i++ {
			adj[i] = nil
		}
	}
}
