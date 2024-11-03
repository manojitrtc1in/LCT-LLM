package main

import (
	"fmt"
)

type Idx2 struct {
	i, j int
}

type Range struct {
	a, b int
}

type Range2 struct {
	a, b, c, d int
}

type Mul int

func (m Mul) Do(a int, b int) int {
	return int(m) * a * b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func pathFrom(g map[int][]int, v0 int, f func(int) bool, path *[]int, markers map[int]int) bool {
	if f(v0) {
		*path = append(*path, v0)
		return true
	}
	markers[v0] = 1
	res := false
	for _, v := range g[v0] {
		if markers[v] == 0 && pathFrom(g, v, f, path, markers) {
			*path = append(*path, v0)
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

	ee := make([]Idx2, e)
	for i := 0; i < e; i++ {
		fmt.Scan(&ee[i].i, &ee[i].j)
	}

	G := make(map[int][]int)
	for _, edge := range ee {
		u, v := edge.i, edge.j
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	ee2 := make([]Idx2, 0)
	markers := make(map[int]int)
	for u, edges := range G {
		for _, v := range edges {
			ee2 = append(ee2, Idx2{u + 1, v + 1})
			markers[v] = 0
		}
	}

	G2 := make(map[int][]int)
	for _, edge := range ee2 {
		u, v := edge.i, edge.j
		G2[u] = append(G2[u], v)
		G2[v] = append(G2[v], u)
	}

	type IntABC struct {
		a, b, c int
	}

	res := make([]IntABC, 0)

	for q := 0; q < n; q++ {
		for i := 0; i < n; i++ {
			if a[i] != b[i] {
				path := make([]int, 0)
				if !pathFrom(G2, i, func(v int) bool {
					return (a[v]-b[v])%(a[i]-b[i]) < 0
				}, &path, markers) {
					fmt.Println("NO")
					return
				}

				if a[path[0]] < b[path[0]] {
					for i, j := 0, len(path)-1; i < j; i, j = i+1, j-1 {
						path[i], path[j] = path[j], path[i]
					}
				}

				src, tgt := path[0], path[len(path)-1]
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

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func doIt(a, b, path []int, res *[]IntABC, pos, vol, diff int) {
	if pos+1 >= len(path) {
		return
	}
	tgt := path[pos+1]
	before := min(diff, vol-a[tgt])
	src := path[pos]
	if before > 0 {
		*res = append(*res, IntABC{src + 1, tgt + 1, before})
	}
	doIt(a, b, path, res, pos+1, vol, diff)
	after := diff - before
	if after > 0 {
		*res = append(*res, IntABC{src + 1, tgt + 1, after})
	}
}

func main() {
	solve()
}
