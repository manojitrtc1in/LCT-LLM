package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pair struct {
	first  int
	second int
}

type triple struct {
	a int
	b int
	c int
}

var g [202020]map[int]bool
var ct int
var c []int
var sz [202020]int
var used [202020]int
var n int
var ans []triple

func go(cur int, iter int) {
	sz[cur] = 1
	used[cur] = iter
	t := 0
	for to := range g[cur] {
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

func dfs2(cur int, p int) {
	used[cur] = 1
	for to := range g[cur] {
		if used[to] == 0 {
			dfs2(to, cur)
		}
	}
}

func solve(cur int) {
	st := make([]pair, 0)
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n = nextInt(scanner)
	for i := 0; i < n-1; i++ {
		x := nextInt(scanner)
		y := nextInt(scanner)

		if g[x] == nil {
			g[x] = make(map[int]bool)
		}
		g[x][y] = true

		if g[y] == nil {
			g[y] = make(map[int]bool)
		}
		g[y][x] = true
	}

	go(1, 1)
	used = [202020]int{}
	if len(c) > 0 {
		for _, x := range c {
			used[x] = 1
		}
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
		fmt.Println(t.a, t.b, t.c)
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
