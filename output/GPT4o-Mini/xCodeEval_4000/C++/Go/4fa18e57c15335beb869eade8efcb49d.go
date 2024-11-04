package main

import (
	"fmt"
	"math"
)

type int_uv struct {
	u, v int
}

type int_abc struct {
	a, b, c int
}

func doit(a []int, b []int, path []int, res *[]int_abc, pos, vol, diff int) {
	if pos+1 >= len(path) {
		return
	}
	tgt := path[pos+1]
	before := int(math.Min(float64(diff), float64(vol-a[tgt])))
	src := path[pos]
	if before > 0 {
		*res = append(*res, int_abc{src + 1, tgt + 1, before})
	}
	doit(a, b, path, res, pos+1, vol, diff)
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
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}

	// Assuming graph_bi_elist and other graph functions are implemented
	// graph_bi_elist(G, n, ee)

	var ee2 []int_uv
	// graph_markers(int, G, markers)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i] != b[i] {
				var path []int
				// Assuming path_from is implemented
				// if !path_from(G2, i, func(v int) bool { return (a[v]-b[v])*(a[i]-b[i]) < 0 }, &path, markers) {
				// 	fmt.Println("NO")
				// 	return
				// }

				if a[path[0]] < b[path[0]] {
					// reverse(path)
				}

				src := path[0]
				tgt := path[len(path)-1]
				diff := int(math.Min(float64(abs(a[src]-b[src])), float64(abs(a[tgt]-b[tgt]))))
				var res []int_abc
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
