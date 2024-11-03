package main

import (
	"fmt"
	"math"
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

func pathFrom(a, b []int, v int, f func(int) bool, path []int, markers []int) bool {
	if f(v) {
		path = append(path, v)
		return true
	}
	markers[v] = 1
	res := false
	for _, e := range path[v] {
		if markers[e.v] == 0 && pathFrom(a, b, e.v, f, path, markers) {
			path = append(path, v)
			res = true
			break
		}
	}
	return res
}

func solve() {
	var n, vol, e int
	fmt.Scan(&n, &vol, &e)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}

	ee := make([]int_uv, e)
	for i := 0; i < e; i++ {
		fmt.Scan(&ee[i].u, &ee[i].v)
	}

	G := make([][]int_uv, n)
	for _, edge := range ee {
		u, v := edge.u-1, edge.v-1
		G[u] = append(G[u], int_uv{u + 1, v + 1})
		G[v] = append(G[v], int_uv{v + 1, u + 1})
	}

	G2 := make([][]int_uv, n)
	markers := make([]int, n)
	for i := 0; i < n; i++ {
		G2[i] = make([]int_uv, len(G[i]))
		copy(G2[i], G[i])
	}

	ee2 := make([]int_uv, 0)
	for i := 0; i < n; i++ {
		if a[i] != b[i] {
			path := make([]int, 0)
			if !pathFrom(a, b, i, func(v int) bool { return (a[v]-b[v])%(a[i]-b[i]) < 0 }, path, markers) {
				fmt.Println("NO")
				return
			}
			if a[path[0]] < b[path[0]] {
				reverse(path)
			}

			src := path[0]
			tgt := path[len(path)-1]
			diff := min(abs(a[src]-b[src]), abs(a[tgt]-b[tgt]))
			doit(a, b, path, res, 0, vol, diff)
			a[src] -= diff
			a[tgt] += diff
		}
	}

	fmt.Print(len(res))
	for _, x := range res {
		fmt.Printf("%d %d %d", x.a, x.b, x.c)
	}
}

func main() {
	solve()
}
