package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	mod   = 1e9 + 7
	gmod  = 2
	inf   = 1039074182
	eps   = 1e-9
	llinf = 1 << 62
)

type Pair struct {
	first, second int
}

var (
	n, v, m int
	a       [305]int
	b       [305]int
	edges   [305][]int
	c       [305]int
	visit   [305]int
	cnt     int
	s       [305]int64
	res     []Pair
	dist    [305]int
)

func chmin(x *int, b int) {
	if b < *x {
		*x = b
	}
}

func chmax(x *int, b int) {
	if b > *x {
		*x = b
	}
}

func chadd(x *int, b int) {
	*x += b - mod
	*x += (*x >> 31) & mod
}

func mabs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func dfs(x int) {
	visit[x] = 1
	c[x] = cnt
	for _, u := range edges[x] {
		if visit[u] == 1 {
			continue
		}
		dfs(u)
	}
}

func bfs(src int) {
	for i := range visit {
		visit[i] = 0
	}
	visit[src] = 1
	dist[src] = 0
	que := []int{src}
	for len(que) > 0 {
		x := que[0]
		que = que[1:]
		for _, u := range edges[x] {
			if visit[u] == 1 {
				continue
			}
			dist[u] = dist[x] + 1
			visit[u] = 1
			que = append(que, u)
		}
	}
}

func liu(x, y, flow int) {
	if flow < 0 {
		panic("flow must be non-negative")
	}
	a[x] -= flow
	if a[x] < 0 {
		panic("a[x] must be non-negative")
	}
	a[y] += flow
	if a[y] > v {
		panic("a[y] must not exceed v")
	}
	res = append(res, Pair{first: x, second: y})
}

func adjust(x, y int) {
	if a[x] == b[x] || a[y] == b[y] {
		panic("a[x] or a[y] must not equal b[x] or b[y]")
	}

	if a[x] < b[x] {
		x, y = y, x
	}
	flow := int(math.Min(float64(mabs(a[x]-b[x])), float64(mabs(a[y]-b[y]))))
	bfs(x)
	routes := []int{y}
	for y != x {
		step := dist[y]
		nxt := -1
		for _, ny := range edges[y] {
			if dist[ny] != step-1 {
				continue
			}
			nxt = ny
			break
		}
		y = nxt
		routes = append(routes, y)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(routes)))
	notEq := 0
	for _, x := range routes {
		if a[x] != b[x] {
			notEq++
		}
	}
	liu(0, flow, routes)
	for _, x := range routes {
		if a[x] != b[x] {
			notEq--
		}
	}
	if notEq < 1 {
		panic("notEq must be at least 1")
	}
}

func main() {
	fmt.Scan(&n, &v, &m)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 0; i < m; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		x--
		y--
		edges[x] = append(edges[x], y)
		edges[y] = append(edges[y], x)
	}
	for i := 0; i < n; i++ {
		if visit[i] == 1 {
			continue
		}
		dfs(i)
		cnt++
	}
	for i := 0; i < n; i++ {
		s[c[i]] += int64(a[i])
		s[c[i]] -= int64(b[i])
	}
	for i := 0; i < n; i++ {
		if s[i] != 0 {
			fmt.Println("NO")
			return
		}
	}
	for i := 0; i < n; i++ {
		if a[i] == b[i] {
			continue
		}
		for j := i + 1; j < n; j++ {
			if c[i] != c[j] {
				continue
			}
			if a[j] == b[j] {
				continue
			}
			if a[i] < b[i] && a[j] < b[j] {
				continue
			}
			if a[i] > b[i] && a[j] > b[j] {
				continue
			}
			adjust(i, j)
			break
		}
		if a[i] != b[i] {
			i--
		}
	}
	fmt.Println(len(res))
	for _, e := range res {
		fmt.Printf("%d %d %d\n", e.first+1, e.second+1, e.second)
	}
}
