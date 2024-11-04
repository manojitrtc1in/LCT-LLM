package main

import (
	"fmt"
	"math"
)

type IntABC struct {
	a, b, c int
}

func doit(a []int, b []int, path []int, res *[]IntABC, pos, vol, diff int) {
	if pos+1 >= len(path) {
		return
	}
	tgt := path[pos+1]
	before := int(math.Min(float64(diff), float64(vol-a[tgt])))
	src := path[pos]
	if before > 0 {
		*res = append(*res, IntABC{src + 1, tgt + 1, before})
	}
	doit(a, b, path, res, pos+1, vol, diff)
	after := diff - before
	if after > 0 {
		*res = append(*res, IntABC{src + 1, tgt + 1, after})
	}
}

func solve() {
	var n, vol, e int
	fmt.Scan(&n, &vol, &e)

	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}

	ee := make([][2]int, e)
	for i := 0; i < e; i++ {
		fmt.Scan(&ee[i][0], &ee[i][1])
	}

	// Placeholder for graph initialization
	// graphBiElist(G, n, ee)

	ee2 := make([][2]int, 0)
	markers := make([]int, n)

	// Placeholder for graph processing
	// CurGraph(G)
	// id6(G, G.vertices(), V0, V0, V0, E_(ee2.push_back(int_uv(u+1, e.v+1))), E0, E0, markers)

	// Placeholder for graph initialization
	// graphBiElist(G2, n, ee2)

	res := []IntABC{}
	for q := 0; q < n; q++ {
		for i := 0; i < n; i++ {
			if a[i] != b[i] {
				path := []int{}
				// Placeholder for path finding
				// CurGraph(G2)
				// if !pathFrom(G2, i, func(v int) bool { return (a[v]-b[v])*(a[i]-b[i]) < 0 }, path, markers) {
				// 	fmt.Println("NO")
				// 	return
				// }

				if a[path[0]] < b[path[0]] {
					// Placeholder for reversing path
					// reverse(path)
				}

				src := path[0]
				tgt := path[len(path)-1]
				diff := int(math.Min(float64(abs(a[src]-b[src])), float64(abs(a[tgt]-b[tgt]))))
				doit(a, b, path, &res, 0, vol, diff)
				a[src] -= diff
				a[tgt] += diff
			}
		}
	}
	fmt.Println(len(res))
	for _, x := range res {
		fmt.Printf("%d %d %d\n", x.a, x.b, x.c)
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	solve()
}
