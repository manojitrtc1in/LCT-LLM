package main

import (
	"fmt"
	"math"
	"sort"
	"strconv"
	"strings"
)

type int64Slice []int64

func (s int64Slice) Len() int {
	return len(s)
}
func (s int64Slice) Less(i, j int) bool {
	return s[i] < s[j]
}
func (s int64Slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

type edgeType struct {
	v int
	w int64
}

type heap struct {
	data []edgeType
}

func (h *heap) push(e edgeType) {
	h.data = append(h.data, e)
	h.up(len(h.data) - 1)
}

func (h *heap) pop() edgeType {
	if len(h.data) == 0 {
		return edgeType{}
	}
	h.swap(0, len(h.data)-1)
	e := h.data[len(h.data)-1]
	h.data = h.data[:len(h.data)-1]
	h.down(0)
	return e
}

func (h *heap) up(i int) {
	for i > 0 {
		p := (i - 1) / 2
		if h.data[i].w >= h.data[p].w {
			break
		}
		h.swap(i, p)
		i = p
	}
}

func (h *heap) down(i int) {
	n := len(h.data)
	for {
		l := 2*i + 1
		if l >= n {
			break
		}
		r := l + 1
		if r < n && h.data[r].w < h.data[l].w {
			l = r
		}
		if h.data[i].w <= h.data[l].w {
			break
		}
		h.swap(i, l)
		i = l
	}
}

func (h *heap) swap(i, j int) {
	h.data[i], h.data[j] = h.data[j], h.data[i]
}

func dijkstra(n int, adj [][]edgeType) []int64 {
	const INF = math.MaxInt64
	dist := make([]int64, n)
	for i := range dist {
		dist[i] = INF
	}
	dist[0] = 0

	h := &heap{}
	h.push(edgeType{0, 0})

	for len(h.data) > 0 {
		u := h.pop()
		if dist[u.v] < u.w {
			continue
		}
		for _, e := range adj[u.v] {
			if u.w+e.w < dist[e.v] {
				dist[e.v] = u.w + e.w
				h.push(edgeType{e.v, dist[e.v]})
			}
		}
	}
	return dist
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	adj := make([][]edgeType, n)
	for j := 0; j < m; j++ {
		var u, v int
		var w int64
		fmt.Scan(&u, &v, &w)
		u--
		v--
		adj[u] = append(adj[u], edgeType{v, w})
		adj[v] = append(adj[v], edgeType{u, w})
	}

	dist := dijkstra(n, adj)

	if dist[n-1] != math.MaxInt64 {
		path := []int{}
		u := n - 1
		for u != 0 {
			path = append(path, u)
			for _, e := range adj[u] {
				if dist[e.v]+e.w == dist[u] {
					u = e.v
					break
				}
			}
		}
		path = append(path, 0)
		for i := len(path) - 1; i >= 0; i-- {
			fmt.Print(path[i] + 1)
			if i > 0 {
				fmt.Print(" ")
			}
		}
	} else {
		fmt.Println(-1)
	}
}
