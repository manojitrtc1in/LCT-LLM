package main

import (
	"fmt"
)

type Idx2 struct {
	i int
	j int
}

type Range struct {
	a int
	b int
}

type ANMap struct {
	m map[int]int
}

func main() {
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

	G := make([][]int, n)
	for i := 0; i < n; i++ {
		G[i] = make([]int, 0)
	}

	for i := 0; i < e; i++ {
		u := ee[i].i - 1
		v := ee[i].j - 1
		G[u] = append(G[u], v)
		G[v] = append(G[v], u)
	}

	G2 := make([][]int, n)
	for i := 0; i < n; i++ {
		G2[i] = make([]int, 0)
	}

	for u := 0; u < n; u++ {
		for _, v := range G[u] {
			G2[u] = append(G2[u], v+1)
		}
	}

	res := make([]Idx2, 0)

	for q := 0; q < n; q++ {
		for i := 0; i < n; i++ {
			if a[i] != b[i] {
				path := make([]int, 0)
				if !pathFrom(G2, i, func(v int) bool {
					return (a[v]-b[v])%(a[i]-b[i]) < 0
				}, path) {
					fmt.Println("NO")
					return
				}

				if a[path[0]] < b[path[0]] {
					reverse(path)
				}

				src := path[0]
				tgt := path[len(path)-1]
				diff := min(abs(a[src]-b[src]), abs(a[tgt]-b[tgt]))
				doit(a, b, path, &res, 0, vol, diff)
				a[src] -= diff
				a[tgt] += diff
			}
		}
	}

	fmt.Print(len(res))
	for _, r := range res {
		fmt.Printf(" %d %d %d", r.i, r.j, r.k)
	}
	fmt.Println()
}

func doit(a []int, b []int, path []int, res *[]Idx2, pos int, vol int, diff int) {
	if pos+1 >= len(path) {
		return
	}

	tgt := path[pos+1]
	before := min(diff, vol-a[tgt])
	src := path[pos]
	if before > 0 {
		*res = append(*res, Idx2{src + 1, tgt + 1, before})
	}
	doit(a, b, path, res, pos+1, vol, diff)
	after := diff - before
	if after > 0 {
		*res = append(*res, Idx2{src + 1, tgt + 1, after})
	}
}

func reverse(path []int) {
	i := 0
	j := len(path) - 1
	for i < j {
		path[i], path[j] = path[j], path[i]
		i++
		j--
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func pathFrom(G [][]int, v0 int, f func(int) bool, path []int) bool {
	markers := make([]int, len(G))
	return dfs(G, v0, f, path, markers)
}

func dfs(G [][]int, v int, f func(int) bool, path []int, markers []int) bool {
	if f(v) {
		path = append(path, v)
		return true
	}

	markers[v] = 1
	res := false

	for _, u := range G[v] {
		if markers[u] == 0 && dfs(G, u, f, path, markers) {
			path = append(path, v)
			res = true
			break
		}
	}

	return res
}
