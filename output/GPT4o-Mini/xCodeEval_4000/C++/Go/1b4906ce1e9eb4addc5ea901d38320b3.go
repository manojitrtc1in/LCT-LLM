package main

import (
	"fmt"
	"math"
)

const N = 3005

type Edge struct {
	v    int
	next *Edge
}

var (
	pool   [3 * N]Edge
	h      [N]*Edge
	n, m   int
	top    int
	a      [N]int
	size   [N]int
	f      [N][N][2]int64
	tmp_f  [N][2]int64
	nil    = [2]int64{0, -math.MaxInt64}
)

func addEdge(u, v int) {
	top++
	pool[top].v = v
	pool[top].next = h[u]
	h[u] = &pool[top]
}

func dfs(u, pre int) {
	size[u] = 1
	f[u][1] = [2]int64{0, int64(a[u])}
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
				f[u][i+j] = max(f[u][i+j], [2]int64{tmp_f[i][0] + f[v][j][0], tmp_f[i][1] + f[v][j][1] + boolToInt64(f[v][j][1] > 0)})
				f[u][i+j-1] = max(f[u][i+j-1], [2]int64{tmp_f[i][0] + f[v][j][0], tmp_f[i][1] + f[v][j][1]})
			}
		}
		size[u] += size[v]
	}
}

func boolToInt64(b bool) int64 {
	if b {
		return -1
	}
	return 0
}

func max(x, y [2]int64) [2]int64 {
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
		addEdge(x, y)
		addEdge(y, x)
	}
	for i := 1; i <= n+1; i++ {
		for j := 1; j <= m+1; j++ {
			f[i][j] = nil
		}
	}
	dfs(1, 0)
	fmt.Println(f[1][m][0] + boolToInt64(f[1][m][1] > 0))
	top = -1
	for i := 1; i <= n+1; i++ {
		h[i] = nil
	}
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		initGraph()
	}
}
