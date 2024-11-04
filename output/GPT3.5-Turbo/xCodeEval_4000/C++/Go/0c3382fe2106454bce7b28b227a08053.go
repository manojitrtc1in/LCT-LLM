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

type pill struct {
	first  int
	second int64
}

func MAX(a *pill, b pill) {
	if b.first > a.first || (b.first == a.first && b.second > a.second) {
		*a = b
	}
}

var (
	T, N, M int
	B, W    [MAXN]int
	dp      [MAXN][MAXN]pill
	merged  [MAXN]pill
	adj     [MAXN][]int
)

func dfs(v, prev int) int {
	SZV := 1
	dp[v][0] = pill{0, int64(W[v] - B[v])}
	for _, w := range adj[v] {
		if w != prev {
			SZW := dfs(w, v)
			for i := SZW; i >= 1; i-- {
				MAX(&dp[w][i], pill{dp[w][i-1].first + int(dp[w][i-1].second > 0), 0})
			}
			for i := 0; i < SZV+SZW; i++ {
				merged[i] = pill{-INT_INF, -LL_INF}
			}
			for i := 0; i < SZV; i++ {
				for j := 0; j <= SZW; j++ {
					MAX(&merged[i+j], pill{dp[v][i].first + dp[w][j].first, dp[v][i].second + dp[w][j].second})
				}
			}
			copy(dp[v][:], merged[:SZV+SZW])
			SZV += SZW
		}
	}
	return SZV
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscanf(reader, "%d\n", &T)
	for ti := 0; ti < T; ti++ {
		fmt.Fscanf(reader, "%d %d\n", &N, &M)
		for i := 0; i < N; i++ {
			fmt.Fscanf(reader, "%d", &B[i])
		}
		fmt.Fscanf(reader, "\n")
		for i := 0; i < N; i++ {
			fmt.Fscanf(reader, "%d", &W[i])
		}
		fmt.Fscanf(reader, "\n")
		for i := 0; i < N-1; i++ {
			var a, b int
			fmt.Fscanf(reader, "%d %d\n", &a, &b)
			adj[a-1] = append(adj[a-1], b-1)
			adj[b-1] = append(adj[b-1], a-1)
		}
		for i := 0; i < N; i++ {
			for j := 0; j <= N; j++ {
				dp[i][j] = pill{-INT_INF, -LL_INF}
			}
		}
		dfs(0, -1)
		fmt.Fprintln(writer, dp[0][M-1].first+int(dp[0][M-1].second > 0))
		for i := 0; i < N; i++ {
			adj[i] = adj[i][:0]
		}
	}
}
