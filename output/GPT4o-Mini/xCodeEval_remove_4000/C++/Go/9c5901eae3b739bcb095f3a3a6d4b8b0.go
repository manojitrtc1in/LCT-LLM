package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = 998244353
	EPS     = 1e-9
	PI      = 3.141592653589793
	N       = 300*1000 + 13
)

var (
	n   int
	g   [N][]int
	dp  [N][3]int
)

func add(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	if a < 0 {
		a += MOD
	}
	return a
}

func mul(a, b int) int {
	return a * b % MOD
}

func dfs(v, p int) {
	dp[v][0] = 1
	dp[v][1] = 1
	vals := []int{}
	init := []int{}

	for _, u := range g[v] {
		if u != p {
			dfs(u, v)
			vals = append(vals, add(dp[u][1], add(dp[u][2], dp[u][2])))
			init = append(init, add(dp[u][0], dp[u][1]))
			dp[v][0] = mul(dp[v][0], add(dp[u][1], add(dp[u][2], dp[u][2])))
			dp[v][1] = mul(dp[v][1], add(dp[u][1], dp[u][2]))
		}
	}
	dp[v][0] = add(dp[v][0], -dp[v][1])

	pr := []int{1}
	su := []int{1}
	for _, it := range vals {
		pr = append(pr, mul(pr[len(pr)-1], it))
	}
	for i := len(vals) - 1; i >= 0; i-- {
		su = append(su, mul(su[len(su)-1], vals[i]))
	}
	reverse(su)

	dp[v][2] = 0
	for i := range vals {
		dp[v][2] = add(dp[v][2], mul(init[i], mul(pr[i], su[i+1])))
	}
}

func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func read() bool {
	if _, err := fmt.Scan(&n); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		g[i] = []int{}
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

func solve() {
	dfs(0)
	fmt.Println(add(dp[0][1], dp[0][2]))
}

func main() {
	rand.Seed(time.Now().UnixNano())

	start := time.Now()

	for read() {
		solve()
		fmt.Printf("TIME = %v\n", time.Since(start))
		start = time.Now()
	}
}
