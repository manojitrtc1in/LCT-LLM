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

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v pt) add(u pt) pt {
	return pt{v.x + u.x, v.y + u.y}
}

type pair struct {
	x int
	y int
}

func (a pair) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (out *pair) add(in pair) {
	out.x += in.x
	out.y += in.y
}

type vector []int

func (v vector) String() string {
	str := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			str += ", "
		}
		str += fmt.Sprintf("%d", v[i])
	}
	str += "]"
	return str
}

func max(a, b pair) pair {
	if a.x > b.x {
		return a
	}
	if a.x < b.x {
		return b
	}
	if a.y > b.y {
		return a
	}
	return b
}

func dfs(v int, p int, g [][]int, a, b []int, dp [][]pair, val []int, siz []int) {
	val[v] = b[v] - a[v]
	for i := 0; i < len(dp[v]); i++ {
		dp[v][i] = pair{-int(1e9), -int(1e18)}
	}
	dp[v][0] = pair{0, val[v]}
	siz[v] = 1
	for _, u := range g[v] {
		if u != p {
			dfs(u, v, g, a, b, dp, val, siz)
			tmp := make([]pair, siz[v]+siz[u])
			for i := 0; i < siz[v]; i++ {
				for j := 0; j <= siz[u]; j++ {
					nw := pair{dp[v][i].x + dp[u][j].x, dp[v][i].y + dp[u][j].y}
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
		if dp[v][i].y > 0 {
			dp[v][i+1].add(pair{dp[v][i].x, 0})
		}
	}
}

func solve() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	g := make([][]int, n)
	for i := 0; i < n-1; i++ {
		var v, u int
		fmt.Scan(&v, &u)
		v--
		u--
		g[v] = append(g[v], u)
		g[u] = append(g[u], v)
	}
	dp := make([][]pair, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]pair, n)
	}
	val := make([]int, n)
	siz := make([]int, n)
	dfs(0, -1, g, a, b, dp, val, siz)
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
	const INF = int(1e9)
	const INF64 = int(1e18)
	const MOD = INF + 7
	const EPS = 1e-9
	const PI = math.Acos(-1.0)
	const N = 3000 + 7
	var tt int = time.Now().Nanosecond()
	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		solve()
		tc--
	}
	fmt.Println("TIME =", time.Now().Nanosecond()-tt)
}
