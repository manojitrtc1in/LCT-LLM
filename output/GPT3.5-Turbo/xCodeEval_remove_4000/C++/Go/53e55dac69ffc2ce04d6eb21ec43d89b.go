package main

import (
	"bufio"
	"fmt"
	"os"
)

type triple struct {
	a, b, c int
}

var (
	g    [][]int
	ct   int
	c    []int
	sz   []int
	used []int
	n    int
	ans  []triple
)

func go(cur, iter int) {
	sz[cur] = 1
	used[cur] = iter
	t := 0
	for _, to := range g[cur] {
		if used[to] != iter {
			go(to, iter)
			sz[cur] += sz[to]
			if sz[to] > t {
				t = sz[to]
			}
		}
	}
	if n-sz[cur] > t {
		t = n - sz[cur]
	}
	if t*2 <= n {
		ct = cur
		c = append(c, cur)
	}
}

func dfs2(cur, p int) {
	used[cur] = 1
	for _, to := range g[cur] {
		if used[to] == 0 {
			dfs2(to, cur)
		}
	}
}

func solve(cur int) {
	st := make([][2]int, 0)
	dfs2(cur, -1)
	st = st[:len(st)-1]
	last := cur
	for _, p := range st {
		v := p[0]
		par := p[1]
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	fmt.Fscan(reader, &n)
	g = make([][]int, n+1)
	for i := 0; i < n-1; i++ {
		var x, y int
		fmt.Fscan(reader, &x, &y)
		g[x] = append(g[x], y)
		g[y] = append(g[y], x)
	}

	ct = 0
	c = make([]int, 0)
	sz = make([]int, n+1)
	used = make([]int, n+1)
	go(1, 0)
	used = make([]int, n+1)
	for _, x := range c {
		used[x] = 1
	}
	for _, x := range c {
		ct = x
		for _, to := range g[ct] {
			if used[to] == 0 {
				solve(to)
			}
		}
	}

	fmt.Fprintln(writer, len(ans))
	for _, t := range ans {
		fmt.Fprintln(writer, t.a, t.b, t.c)
	}
}
