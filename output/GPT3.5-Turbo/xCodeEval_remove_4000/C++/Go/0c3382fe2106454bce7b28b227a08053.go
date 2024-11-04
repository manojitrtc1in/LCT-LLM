package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAXN = 3005
	INT_INF = int(1e9)
	LL_INF = int(1e18)
)

type pair struct {
	first  int
	second int64
}

func max(a *pair, b pair) {
	if b.first > a.first || (b.first == a.first && b.second > a.second) {
		*a = b
	}
}

func dfs(v int, prev int, dp [][]pair, adj [][]int, B []int, W []int) int {
	SZV := 1
	dp[v][0] = pair{0, int64(W[v] - B[v])}
	for _, w := range adj[v] {
		if w != prev {
			SZW := dfs(w, v, dp, adj, B, W)
			for i := SZW; i >= 1; i-- {
				max(&dp[w][i], pair{dp[w][i-1].first + 1, 0})
			}
			merged := make([]pair, SZV+SZW)
			for i := 0; i < SZV; i++ {
				for j := 0; j <= SZW; j++ {
					max(&merged[i+j], pair{dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second})
				}
			}
			copy(dp[v], merged)
			SZV += SZW
		}
	}
	return SZV
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscan(reader, &T)
	for ti := 0; ti < T; ti++ {
		var N, M int
		fmt.Fscan(reader, &N, &M)
		B := make([]int, N)
		W := make([]int, N)
		for i := 0; i < N; i++ {
			fmt.Fscan(reader, &B[i])
		}
		for i := 0; i < N; i++ {
			fmt.Fscan(reader, &W[i])
		}
		adj := make([][]int, N)
		for i := 0; i < N-1; i++ {
			var a, b int
			fmt.Fscan(reader, &a, &b)
			adj[a-1] = append(adj[a-1], b-1)
			adj[b-1] = append(adj[b-1], a-1)
		}
		dp := make([][]pair, N)
		for i := 0; i < N; i++ {
			dp[i] = make([]pair, N+1)
			for j := 0; j <= N; j++ {
				dp[i][j] = pair{-INT_INF, -LL_INF}
			}
		}
		dfs(0, -1, dp, adj, B, W)
		fmt.Fprintln(writer, dp[0][M-1].first+1)
	}
}
