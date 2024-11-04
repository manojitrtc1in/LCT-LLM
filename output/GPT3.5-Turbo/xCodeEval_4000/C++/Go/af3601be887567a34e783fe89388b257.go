package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x int
	y int
}

func sqr(a int) int {
	return a * a
}

func read() (int, int, []int, []int, [][]int) {
	var n, k int
	if _, err := fmt.Scanf("%d%d", &n, &k); err != nil {
		return 0, 0, nil, nil, nil
	}
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &b[i])
	}
	g := make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < n-1; i++ {
		var v, u int
		fmt.Scanf("%d%d", &v, &u)
		v--
		u--
		g[v] = append(g[v], u)
		g[u] = append(g[u], v)
	}
	return n, k, a, b, g
}

func dfs(v int, p int, g [][]int, a []int, b []int, dp [][]pt, val []int, siz []int) {
	val[v] = b[v] - a[v]
	for i := 0; i < len(dp[v]); i++ {
		dp[v][i] = pt{-int(1e9), -int(1e18)}
	}
	dp[v][0] = pt{0, val[v]}
	siz[v] = 1
	for _, u := range g[v] {
		if u != p {
			dfs(u, v, g, a, b, dp, val, siz)
			tmp := make([]pt, siz[v]+siz[u])
			for i := 0; i < siz[v]; i++ {
				for j := 0; j < siz[u]+1; j++ {
					nw := pt{dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y}
					if nw.x > tmp[i+j].x || (nw.x == tmp[i+j].x && nw.y > tmp[i+j].y) {
						tmp[i+j] = nw
					}
				}
			}
			for i := 0; i < len(tmp); i++ {
				dp[v][i] = tmp[i]
			}
			siz[v] += siz[u]
			val[v] += val[u]
		}
	}
	for i := siz[v] - 1; i >= 0; i-- {
		dp[v][i+1] = pt{int(math.Max(float64(dp[v][i+1].x), float64(dp[v][i].x+(dp[v][i].y > 0)))), 0}
	}
}

func solve() {
	var n, k int
	var a, b []int
	var g [][]int
	n, k, a, b, g = read()
	dp := make([][]pt, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]pt, n)
	}
	val := make([]int, n)
	siz := make([]int, n)
	dfs(0, -1, g, a, b, dp, val, siz)
	fmt.Printf("%d\n", dp[0][k-1].x+boolToInt(dp[0][k-1].y > 0))
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	rand.Seed(time.Now().UnixNano())
	tc := 0
	fmt.Scanf("%d", &tc)
	for tc > 0 {
		solve()
		tc--
	}
}
