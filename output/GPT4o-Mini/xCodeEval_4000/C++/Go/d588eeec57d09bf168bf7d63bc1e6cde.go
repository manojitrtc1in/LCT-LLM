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
var g [maxn * 2][]struct {
	first  int
	second int
}

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

func addxMod(u, v, m int) int {
	r := u + v
	if r >= m {
		r -= m
	}
	return r
}

func subxMod(u, v, m int) int {
	r := u - v
	if r < 0 {
		r += m
	}
	return r
}

func dfs(u int) (int, int) {
	ret := [2]int{1, 0}
	visit[u] = true
	for _, vv := range g[u] {
		if ve[vv.second] {
			continue
		}
		ret[1]++
		ve[vv.second] = true
		if visit[vv.first] {
			continue
		}
		p := dfs(vv.first)
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

	for i := 0; i < n; i++ {
		x := xStart + pts[i][0]
		y := yStart + pts[i][1]
		g[x] = append(g[x], struct {
			first  int
			second int
		}{y, i})
		g[y] = append(g[y], struct {
			first  int
			second int
		}{x, i})
	}

	ans := 1
	for i := 0; i < now; i++ {
		if !visit[i] {
			k, p := dfs(i)
			if p < k {
				ans = mulMod(ans, subxMod(powMod(2, k, MOD), 1, MOD), MOD)
			} else {
				ans = mulMod(ans, powMod(2, k, MOD), MOD)
			}
		}
	}
	fmt.Println(ans)
}
