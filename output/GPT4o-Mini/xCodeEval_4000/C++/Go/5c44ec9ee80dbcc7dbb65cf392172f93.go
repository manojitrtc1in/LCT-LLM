package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007
const maxn = 100005

var n int
var pts [maxn][2]int
var visit [maxn * 2]bool
var g [maxn * 2][]int

func gcd(a, b int) int {
	for a != 0 {
		b %= a
		if b == 0 {
			return a
		}
		a %= b
	}
	return b
}

func mulMod(a, b, m int) int {
	return (a * b) % m
}

func powMod(a, p, m int) int {
	r := 1
	a %= m
	for p > 0 {
		if p&1 == 1 {
			r = mulMod(r, a, m)
		}
		a = mulMod(a, a, m)
		p >>= 1
	}
	return r
}

func dfs(u int) (int, int) {
	ret := 1
	edges := len(g[u])
	visit[u] = true
	for _, v := range g[u] {
		if !visit[v] {
			p1, p2 := dfs(v)
			ret += p1
			edges += p2
		}
	}
	return ret, edges
}

func main() {
	fmt.Scan(&n)

	trans := [2]map[int]int{{}, {}}
	for i := 0; i < n; i++ {
		fmt.Scan(&pts[i][0], &pts[i][1])
		for j := 0; j < 2; j++ {
			if trans[j][pts[i][j]] == 0 {
				trans[j][pts[i][j]] = 0
			}
		}
	}

	cnt := 0
	for j := 0; j < 2; j++ {
		for k := range trans[j] {
			trans[j][k] = cnt
			cnt++
		}
	}

	for i := 0; i < n; i++ {
		x := trans[0][pts[i][0]]
		y := trans[1][pts[i][1]]
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	ans := 1
	for i := 0; i < cnt; i++ {
		if !visit[i] {
			vers, edges := dfs(i)
			edges /= 2
			if edges == vers-1 {
				ans = mulMod(ans, (powMod(2, vers, MOD) - 1 + MOD) % MOD)
			} else {
				ans = mulMod(ans, powMod(2, vers, MOD))
			}
		}
	}
	fmt.Println(ans)
}
