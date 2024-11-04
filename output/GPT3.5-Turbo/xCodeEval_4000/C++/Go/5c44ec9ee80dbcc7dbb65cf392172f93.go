package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const MOD = 1000000007
const maxn = 100005

var n int
var pts [maxn][2]int
var visit [maxn * 2]bool
var g [maxn * 2][]int

func dfs(u int) (int, int) {
	ret := [2]int{1, len(g[u])}
	visit[u] = true
	for _, v := range g[u] {
		if !visit[v] {
			p := dfs(v)
			ret[0] += p[0]
			ret[1] += p[1]
		}
	}
	return ret[0], ret[1]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	trans := [2]map[int]int{}
	for i := 0; i < 2; i++ {
		trans[i] = make(map[int]int)
	}

	for i := 0; i < n; i++ {
		scanner.Scan()
		pts[i][0], _ = strconv.Atoi(scanner.Text())
		scanner.Scan()
		pts[i][1], _ = strconv.Atoi(scanner.Text())

		for j := 0; j < 2; j++ {
			trans[j][pts[i][j]] = 0
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
			p := dfs(i)
			vers := p[0]
			edgs := p[1] / 2
			if edgs == vers-1 {
				ans = (ans * (powMod(2, vers) - 1)) % MOD
			} else {
				ans = (ans * powMod(2, vers)) % MOD
			}
		}
	}

	fmt.Println(ans)
}

func powMod(a, p int) int {
	r := 1
	a %= MOD
	for p > 0 {
		if p&1 == 1 {
			r = (r * a) % MOD
		}
		a = (a * a) % MOD
		p >>= 1
	}
	return r
}
