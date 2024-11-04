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
	a    [N]int
	size [N]int
	f    [N][N][2]int
	nil  = [2]int{0, -int(3e18)}
)

func addedge(u, v int) {
	tmp := &pool[u]
	tmp.v = v
	tmp.next = h[u]
	h[u] = tmp
}

func max(a, b [2]int) [2]int {
	if a[0] > b[0] {
		return a
	} else if a[0] < b[0] {
		return b
	} else {
		if a[1] > b[1] {
			return a
		} else {
			return b
		}
	}
}

func dfs(u, pre int) {
	size[u] = 1
	f[u][1] = [2]int{0, int(a[u])}
	for tmp := h[u]; tmp != nil; tmp = tmp.next {
		v := tmp.v
		if v == pre {
			continue
		}
		dfs(v, u)
		tmp_f := [N][2]int{}
		for i := 1; i <= size[u]; i++ {
			tmp_f[i] = f[u][i]
			f[u][i] = nil
		}
		for i := 1; i <= size[u]; i++ {
			for j := 1; j <= size[v]; j++ {
				if i+j-1 > m {
					break
				}
				f[u][i+j] = max(f[u][i+j], max(tmp_f[i], f[v][j]))
				f[u][i+j-1] = max(f[u][i+j-1], max(tmp_f[i], f[v][j]))
			}
		}
		size[u] += size[v]
	}
}

func init() {
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
	fmt.Println(f[1][m][0] + 1)
}

func main() {
	var T int
	fmt.Scan(&T)
	for i := 1; i <= T; i++ {
		init()
	}
}
