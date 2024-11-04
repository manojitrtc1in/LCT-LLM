package main

import (
	"fmt"
	"math"
)

const N = 3005

type edge struct {
	v    int
	next *edge
}

var (
	pool   [3 * N]edge
	h      [N]*edge
	n, m   int
	top    int
	a      [N]int
	size   [N]int
	f      [N][N][2]int
	tmp_f  [N][2]int
	nil    = [2]int{0, -math.MaxInt64}
)

func addedge(u, v int) {
	top++
	pool[top].v = v
	pool[top].next = h[u]
	h[u] = &pool[top]
}

func dfs(u, pre int) {
	size[u] = 1
	f[u][1] = [2]int{0, a[u]}
	for tmp := h[u]; tmp != nil; tmp = tmp.next {
		v := tmp.v
		if v == pre {
			continue
		}
		dfs(v, u)
		for i := 1; i <= size[u]; i++ {
			tmp_f[i] = f[u][i]
			f[u][i] = nil
		}
		for i := 1; i <= size[u]; i++ {
			for j := 1; j <= size[v]; j++ {
				if i+j-1 > m {
					break
				}
				f[u][i+j] = max(f[u][i+j], add(tmp_f[i], f[v][j], f[v][j][1] > 0))
				f[u][i+j-1] = max(f[u][i+j-1], add(tmp_f[i], f[v][j], false))
			}
		}
		size[u] += size[v]
	}
}

func add(x, y [2]int, condition bool) [2]int {
	if condition {
		return [2]int{x[0] + y[0], x[1] + y[1]}
	}
	return [2]int{x[0] + y[0], x[1]}
}

func max(x, y [2]int) [2]int {
	if x[0] > y[0] || (x[0] == y[0] && x[1] > y[1]) {
		return x
	}
	return y
}

func initGraph() {
	var x, y int
	fmt.Scan(&n, &m)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&x)
		a[i] = x - a[i]
	}
	for i := 1; i < n; i++ {
		fmt.Scan(&x, &y)
		addedge(x, y)
		addedge(y, x)
	}
	for i := 1; i <= n+1; i++ {
		for j := 1; j <= m+1; j++ {
			f[i][j] = nil
		}
	}
	dfs(1, 0)
	fmt.Println(f[1][m][0] + boolToInt(f[1][m][1] > 0))
	top = -1
	for i := 1; i <= n+1; i++ {
		h[i] = nil
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		initGraph()
	}
}
