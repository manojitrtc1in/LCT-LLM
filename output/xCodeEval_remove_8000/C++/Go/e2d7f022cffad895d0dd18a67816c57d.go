package main

import (
	"fmt"
)

type Op struct {
	u, v, d int
}

func main() {
	var n, UP, e int
	fmt.Scan(&n, &UP, &e)

	A := make([]int, n)
	B := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&A[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&B[i])
	}

	adj := make([][]int, n)
	for i := 0; i < e; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		adj[x] = append(adj[x], y)
		adj[y] = append(adj[y], x)
	}

	op := make([]Op, 0)
	path := make([]int, 0)
	vis := make([]bool, n)

	var dfs func(int) bool
	dfs = func(u int) bool {
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

	for i := 0; i < n; i++ {
		for A[i] > B[i] {
			vis = make([]bool, n)
			path = path[:0]
			if !dfs(i) {
				fmt.Println("NO")
				return
			}

			f := min(A[i]-B[i], B[path[len(path)-1]]-A[path[len(path)-1]])

			for j := len(path) - 2; j >= 0; j-- {
				u, v := path[j], path[j+1]
				d := min(f, A[u], UP-A[v])
				t := f - d
				if d > 0 {
					op = append(op, Op{u, v, d})
				}
			}

			for j := len(path) - 2; j >= 0; j-- {
				u, v := path[j], path[j+1]
				d := t[j]
				if d > 0 {
					op = append(op, Op{u, v, d})
				}
			}
		}
	}

	for i := 0; i < n; i++ {
		if A[i] != B[i] {
			fmt.Println("NO")
			return
		}
	}

	fmt.Println(len(op))
	for _, o := range op {
		fmt.Println(o.u, o.v, o.d)
	}
}

func min(a, b, c int) int {
	if a < b {
		if a < c {
			return a
		}
		return c
	}
	if b < c {
		return b
	}
	return c
}
