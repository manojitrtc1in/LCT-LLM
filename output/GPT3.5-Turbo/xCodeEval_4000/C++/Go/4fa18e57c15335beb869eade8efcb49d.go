package main

import (
	"fmt"
)

type int_uv struct {
	u int
	v int
}

type int_abc struct {
	a int
	b int
	c int
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func reverse(path []int) {
	n := len(path)
	for i := 0; i < n/2; i++ {
		path[i], path[n-i-1] = path[n-i-1], path[i]
	}
}

func pathFrom(a, b []int, path []int, markers []int) bool {
	v0 := path[0]
	if a[v0] < b[v0] {
		reverse(path)
	}
	src := path[0]
	tgt := path[len(path)-1]
	diff := min(abs(a[src]-b[src]), abs(a[tgt]-b[tgt]))
	doIt(a, b, path, &res, 0, vol, diff)
	a[src] -= diff
	a[tgt] += diff
	return true
}

func doIt(a, b []int, path []int, res *[]int_abc, pos, vol, diff int) {
	if pos+1 >= len(path) {
		return
	}
	tgt := path[pos+1]
	before := min(diff, vol-a[tgt])
	src := path[pos]
	if before > 0 {
		*res = append(*res, int_abc{src + 1, tgt + 1, before})
	}
	doIt(a, b, path, res, pos+1, vol, diff)
	after := diff - before
	if after > 0 {
		*res = append(*res, int_abc{src + 1, tgt + 1, after})
	}
}

func solve() {
	var n, vol, e int
	fmt.Scan(&n, &vol, &e)

	a := make([]int, n)
	b := make([]int, n)
	ee := make([]int_uv, e)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < e; i++ {
		fmt.Scan(&ee[i].u, &ee[i].v)
	}

	G := make([][]int_uv, n)
	for _, edge := range ee {
		G[edge.u-1] = append(G[edge.u-1], int_uv{edge.u, edge.v})
		G[edge.v-1] = append(G[edge.v-1], int_uv{edge.v, edge.u})
	}

	G2 := make([][]int_uv, n)
	markers := make([]int, n)
	for i := 0; i < n; i++ {
		G2[i] = make([]int_uv, len(G[i]))
		copy(G2[i], G[i])
	}
	for i := 0; i < n; i++ {
		if markers[i] == 0 {
			G2[i] = dfs(G2, i, i, i, i, ee2)
		}
	}

	res := make([]int_abc, 0)
	for q := 0; q < n; q++ {
		for i := 0; i < n; i++ {
			if a[i] != b[i] {
				path := make([]int, 0)
				if !pathFrom(G2, i, func(v int) bool {
					return (a[v]-b[v])%(a[i]-b[i]) < 0
				}, path, markers) {
					fmt.Println("NO")
					return
				}
				if a[path[0]] < b[path[0]] {
					reverse(path)
				}
				src := path[0]
				tgt := path[len(path)-1]
				diff := min(abs(a[src]-b[src]), abs(a[tgt]-b[tgt]))
				doIt(a, b, path, &res, 0, vol, diff)
				a[src] -= diff
				a[tgt] += diff
			}
		}
	}

	fmt.Print(len(res))
	for _, r := range res {
		fmt.Printf(" %d %d %d", r.a, r.b, r.c)
	}
	fmt.Println()
}

func main() {
	solve()
}
