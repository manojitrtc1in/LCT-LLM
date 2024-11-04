package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	a, b int
}

type Triple struct {
	a, b, c int
}

var (
	g    [202020]map[int]struct{}
	ct   int
	c    []int
	sz   [202020]int
	used [202020]int
	n    int
	ans  []Triple
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

var st []Pair

func dfs2(cur, p int) {
	used[cur] = 1
	for to := range g[cur] {
		if used[to] == 0 {
			dfs2(to, cur)
		}
	}
	st = append(st, Pair{cur, p})
}

func solve(cur int) {
	st = nil
	dfs2(cur, -1)
	st = st[:len(st)-1]
	last := cur
	for _, p := range st {
		v := p.a
		par := p.b
		if par != cur {
			ans = append(ans, Triple{ct, last, v})
			ans = append(ans, Triple{v, par, cur})
			last = v
		}
	}
	if last != cur {
		ans = append(ans, Triple{ct, last, cur})
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
	for i := range used {
		used[i] = 0
	}
	if len(c) == 0 {
		panic("no centroid found")
	}
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
	if len(ans) > 2*n {
		panic("too many answers")
	}
	for _, t := range ans {
		fmt.Printf("%d %d %d\n", t.a, t.b, t.c)
	}
}
