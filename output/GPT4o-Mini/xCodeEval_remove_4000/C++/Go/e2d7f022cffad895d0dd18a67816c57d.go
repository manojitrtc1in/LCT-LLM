package main

import (
	"fmt"
	"math"
)

const N = int(3e2) + 9

var (
	adj [N][]int
	A   [N]int
	B   [N]int
	t   [N]int
	n   int
	e   int
	UP  int
)

type Op struct {
	u, v, d int
}

var op []Op

func (o Op) output() {
	fmt.Printf("%d %d %d\n", o.u, o.v, o.d)
}

var path []int
var vis [N]bool

func dfs(u int) bool {
	if vis[u] {
		return false
	}
	vis[u] = true
	path = append(path, u)
	if A[u] < B[u] {
		return true
	}
	for _, v := range adj[u] {
		if dfs(v) {
			return true
		}
	}
	path = path[:len(path)-1]
	return false
}

func main() {
	var x, y int

	fmt.Scan(&n, &UP, &e)

	for i := 1; i <= n; i++ {
		fmt.Scan(&A[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&B[i])
	}

	for i := 0; i < e; i++ {
		fmt.Scan(&x, &y)
		adj[x] = append(adj[x], y)
		adj[y] = append(adj[y], x)
	}

	for i := 1; i <= n; i++ {
		for A[i] > B[i] {
			vis = [N]bool{}
			path = path[:0]
			if !dfs(i) {
				fmt.Println("NO")
				return
			}

			f := int(math.Min(float64(A[i]-B[i]), float64(B[path[len(path)-1]]-A[path[len(path)-1]])))

			for j := 0; j < len(path)-1; j++ {
				u := path[j]
				v := path[j+1]
				d := int(math.Min(float64(f), float64(A[u]), float64(UP-A[v])))
				t[j] = f - d
				if d > 0 {
					op = append(op, Op{u, v, d})
				}
			}
			for j := len(path) - 2; j >= 0; j-- {
				u := path[j]
				v := path[j+1]
				d := t[j]
				if d > 0 {
					op = append(op, Op{u, v, d})
				}
			}
		}
	}

	for i := 1; i <= n; i++ {
		if A[i] != B[i] {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println(len(op))
	for _, it := range op {
		it.output()
	}
}
