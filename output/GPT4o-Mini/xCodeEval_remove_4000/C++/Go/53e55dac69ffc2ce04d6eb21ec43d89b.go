package main

import (
	"fmt"
	"math"
)

type pii struct {
	first, second int
}

type triple struct {
	a, b, c int
}

var (
	g      [202020]map[int]struct{}
	ct     int
	c      []int
	sz     [202020]int
	used   [202020]int
	n      int
	ans    []triple
	st     []pii
)

func goFunc(cur, iter int) {
	sz[cur] = 1
	used[cur] = iter
	t := 0
	for to := range g[cur] {
		if used[to] != iter {
			goFunc(to, iter)
			sz[cur] += sz[to]
			t = max(t, sz[to])
		}
	}
	t = max(t, n-sz[cur])
	if t*2 <= n {
		ct = cur
		c = append(c, cur)
	}
}

func dfs2(cur, p int) {
	used[cur] = 1
	for to := range g[cur] {
		if used[to] == 0 {
			dfs2(to, cur)
		}
	}
	st = append(st, pii{cur, p})
}

func solve(cur int) {
	st = nil
	dfs2(cur, -1)
	st = st[:len(st)-1]
	last := cur
	for _, p := range st {
		v := p.first
		par := p.second
		if par != cur {
			ans = append(ans, triple{ct, last, v})
			ans = append(ans, triple{v, par, cur})
			last = v
		}
	}
	if last != cur {
		ans = append(ans, triple{ct, last, cur})
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&n)
	for i := 0; i < n-1; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		if g[x] == nil {
			g[x] = make(map[int]struct{})
		}
		if g[y] == nil {
			g[y] = make(map[int]struct{})
		}
		g[x][y] = struct{}{}
		g[y][x] = struct{}{}
	}
	goFunc(1, 1)
	for _, x := range c {
		used[x] = 1
	}
	for _, x := range c {
		ct = x
		for to := range g[ct] {
			if used[to] == 0 {
				solve(to)
			}
		}
	}
	fmt.Println(len(ans))
	for _, t := range ans {
		fmt.Printf("%d %d %d\n", t.a, t.b, t.c)
	}
}
