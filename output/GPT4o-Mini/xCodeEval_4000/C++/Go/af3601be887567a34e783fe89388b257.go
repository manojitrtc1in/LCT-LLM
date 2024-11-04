package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	INF    = int(1e9)
	INF64  = int64(1e18)
	MOD    = INF + 7
	EPS    = 1e-9
	PI     = 3.141592653589793
	N      = 3000 + 7
)

type Pair struct {
	x int
	y int64
}

var (
	n, k int
	a, b [N]int
	g    [N][]int
	dp   [N][N]Pair
	val  [N]int64
	siz  [N]int
)

func read() bool {
	if _, err := fmt.Scan(&n, &k); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		g[i] = nil
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < n-1; i++ {
		var v, u int
		fmt.Scan(&v, &u)
		v--
		u--
		g[v] = append(g[v], u)
		g[u] = append(g[u], v)
	}
	return true
}

func dfs(v, p int) {
	val[v] = int64(b[v] - a[v])
	for i := 0; i <= n; i++ {
		dp[v][i] = Pair{-INF, -INF64}
	}
	dp[v][0] = Pair{0, val[v]}
	siz[v] = 1
	for _, u := range g[v] {
		if u != p {
			dfs(u, v)
			tmp := make([]Pair, siz[v]+siz[u])
			for i := 0; i < siz[v]; i++ {
				for j := 0; j <= siz[u]; j++ {
					nw := Pair{dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y}
					if nw.x > tmp[i+j].x || (nw.x == tmp[i+j].x && nw.y > tmp[i+j].y) {
						tmp[i+j] = nw
					}
				}
			}
			for i := range tmp {
				dp[v][i] = tmp[i]
			}
			siz[v] += siz[u]
			val[v] += val[u]
		}
	}

	for i := siz[v] - 1; i >= 0; i-- {
		dp[v][i+1] = max(dp[v][i+1], Pair{dp[v][i].x + boolToInt(dp[v][i].y > 0), 0})
	}
}

func boolToInt(b bool) int64 {
	if b {
		return 1
	}
	return 0
}

func max(a, b Pair) Pair {
	if a.x > b.x || (a.x == b.x && a.y > b.y) {
		return a
	}
	return b
}

func solve() {
	dfs(0, -1)
	fmt.Println(dp[0][k-1].x + boolToInt(dp[0][k-1].y > 0))
}

func main() {
	rand.Seed(time.Now().UnixNano())

	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		tc--
		if !read() {
			break
		}
		solve()
	}
}
