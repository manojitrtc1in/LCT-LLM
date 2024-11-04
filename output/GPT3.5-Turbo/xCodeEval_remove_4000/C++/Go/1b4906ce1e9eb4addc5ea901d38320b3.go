package main

import (
	"fmt"
)

const N = 3005

type edge struct {
	v    int
	next *edge
}

var (
	pool [3 * N]edge
	h    [N]*edge
	n, m int
	top  int
	a    [N]int
	size [N]int
	f    [N][N][2]int64
	nil  = [2]int64{0, -0x3f3f3f3f3f3f3f3f}
)

func addedge(u, v int) {
	tmp := &pool[top]
	tmp.v = v
	tmp.next = h[u]
	h[u] = tmp
}

func max(a, b [2]int64) [2]int64 {
	if a[0]+a[1] > b[0]+b[1] {
		return a
	}
	return b
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
		tmp_f := [N][2]int64{}
		for i := 1; i <= size[u]; i++ {
			tmp_f[i] = f[u][i]
			f[u][i] = [2]int64{0, -0x3f3f3f3f3f3f3f3f}
		}
		for i := 1; i <= size[u]; i++ {
			for j := 1; j <= size[v]; j++ {
				if i+j-1 > m {
					break
				}
				f[u][i+j] = max(f[u][i+j], [2]int64{tmp_f[i][0] + f[v][j][0] + int64(f[v][j][1] > 0), -f[v][j][1]})
				f[u][i+j-1] = max(f[u][i+j-1], [2]int64{tmp_f[i][0] + f[v][j][0], f[v][j][1]})
			}
		}
		size[u] += size[v]
	}
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
	fmt.Println(f[1][m][0] + int64(f[1][m][1] > 0))
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
