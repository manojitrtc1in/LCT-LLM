package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MOD   = 1000000007
	maxn  = 100005
	xStart = 0
	yStart = maxn
)

var (
	n     int
	pts   [maxn][2]int
	visit [maxn * 2]bool
	ve    [maxn * 2]bool
	g     [maxn * 2][]pair
)

type pair struct {
	first, second int
}

func dfs(u int) pair {
	ret := pair{1, 0}
	visit[u] = true
	for _, vv := range g[u] {
		if ve[vv.second] {
			continue
		}
		ret.second++
		ve[vv.second] = true
		if visit[vv.first] {
			continue
		}
		p := dfs(vv.first)
		ret.first += p.first
		ret.second += p.second
	}
	return ret
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
			if _, ok := trans[j][pts[i][j]]; !ok {
				s := len(trans[j])
				trans[j][pts[i][j]] = s
			}
			pts[i][j] = trans[j][pts[i][j]]
		}
	}

	for i := 0; i < n; i++ {
		x := xStart + pts[i][0]
		y := yStart + pts[i][1]
		g[x] = append(g[x], pair{y, i})
		g[y] = append(g[y], pair{x, i})
	}

	ans := 1
	for i := 0; i < n*2; i++ {
		if !visit[i] {
			p := dfs(i)
			k := p.first
			if p.second < p.first {
				ans = (ans * (powMod(2, k) - 1)) % MOD
			} else {
				ans = (ans * powMod(2, k)) % MOD
			}
		}
	}

	fmt.Fprintln(writer, ans)
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
