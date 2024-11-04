package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Pair struct {
	x int
	y int64
}

const INF = int(1e9)
const INF64 = int64(1e18)
const MOD = INF + 7
const EPS = 1e-9
const PI = 3.141592653589793

const N = 3000 + 7

var n, k int
var a [N]int
var b [N]int
var g [N][]int

var dp [N][N]Pair
var val [N]int64
var siz [N]int

func read() bool {
	if _, err := fmt.Scan(&n, &k); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		g[i] = []int{}
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
		if dp[v][i].y > 0 {
			dp[v][i+1] = Pair{dp[v][i].x + 1, 0}
		}
	}
}

func solve() {
	dfs(0, -1)
	fmt.Println(dp[0][k-1].x + boolToInt(dp[0][k-1].y > 0))
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
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
