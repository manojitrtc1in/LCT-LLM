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
var ve [maxn * 2]bool
var g [maxn * 2][][2]int

var xStart, yStart, now int

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

func invMod(a, m int) int {
	x, y := 0, 0
	g := id1(a, m, &x, &y)
	if x < 0 {
		return x + m
	}
	return x
}

func id1(a, b int, x, y *int) int {
	if b == 0 {
		*x = 1
		*y = 0
		return a
	}
	g := id1(b, a%b, y, x)
	*y -= (a / b) * (*x)
	return g
}

func dfs(u int) (int, int) {
	ret := [2]int{1, 0}
	visit[u] = true
	for _, vv := range g[u] {
		if ve[vv[1]] {
			continue
		}
		ret[1]++
		ve[vv[1]] = true
		if visit[vv[0]] {
			continue
		}
		p := dfs(vv[0])
		ret[0] += p[0]
		ret[1] += p[1]
	}
	return ret[0], ret[1]
}

func main() {
	fmt.Scan(&n)

	trans := [2]map[int]int{make(map[int]int), make(map[int]int)}
	for i := 0; i < n; i++ {
		fmt.Scan(&pts[i][0], &pts[i][1])
		for j := 0; j < 2; j++ {
			if _, ok := trans[j][pts[i][j]]; !ok {
				s := len(trans[j])
				trans[j][pts[i][j]] = s
			}
			pts[i][j] = trans[j][pts[i][j]]
		}
	}

	xStart = now
	now += len(trans[0])
	yStart = now
	now += len(trans[1])
	if now >= maxn*2 {
		panic("Exceeded maximum size")
	}
	for i := 0; i < n; i++ {
		x := xStart + pts[i][0]
		y := yStart + pts[i][1]
		g[x] = append(g[x], [2]int{y, i})
		g[y] = append(g[y], [2]int{x, i})
	}
	ans := 1
	for i := 0; i < now; i++ {
		if !visit[i] {
			k, p := dfs(i)
			if p < k {
				ans = mulMod(ans, (powMod(2, k, MOD) - 1 + MOD) % MOD)
			} else {
				ans = mulMod(ans, powMod(2, k, MOD))
			}
		}
	}
	fmt.Println(ans)
}
