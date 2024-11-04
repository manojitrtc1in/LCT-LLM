package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const (
	MOD   = 1000000007
	maxn  = 100005
	maxn2 = maxn * 2
)

var (
	n     int
	pts   [maxn][2]int
	visit [maxn2]bool
	g     [maxn2][]int
)

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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)

	trans := [2]map[int]int{}
	for i := 0; i < 2; i++ {
		trans[i] = make(map[int]int)
	}

	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &pts[i][0], &pts[i][1])
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
				ans = mulMod(ans, subMod(powMod(2, vers), 1))
			} else {
				ans = mulMod(ans, powMod(2, vers))
			}
		}
	}

	fmt.Fprintln(writer, ans)
}

func mulMod(a, b int) int {
	p := int64(a)
	p = (p * int64(b)) % MOD
	return int(p)
}

func powMod(a, p int) int {
	r := 1
	a %= MOD
	for p > 0 {
		if p&1 == 1 {
			r = mulMod(r, a)
		}
		a = mulMod(a, a)
		p >>= 1
	}
	return r
}

func subMod(a, b int) int {
	r := a - b
	if r < 0 {
		r += MOD
	}
	return r
}
