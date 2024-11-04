package main

import (
	"fmt"
	"math"
	"sort"
)

type Dinic struct {
	n      int
	to     [][]int
	cap    [][]int64
	rev    [][]int
	minCost []int
	iter   []int
}

func NewDinic(n int) *Dinic {
	d := &Dinic{
		n:      n,
		to:     make([][]int, n),
		cap:    make([][]int64, n),
		rev:    make([][]int, n),
		minCost: make([]int, n),
		iter:   make([]int, n),
	}
	for i := 0; i < n; i++ {
		d.to[i] = make([]int, 0)
		d.cap[i] = make([]int64, 0)
		d.rev[i] = make([]int, 0)
	}
	return d
}

func (d *Dinic) AddEdge(from, to int, cap int64) {
	d.to[from] = append(d.to[from], to)
	d.to[to] = append(d.to[to], from)
	d.cap[from] = append(d.cap[from], cap)
	d.cap[to] = append(d.cap[to], 0)
	d.rev[from] = append(d.rev[from], len(d.to[to])-1)
	d.rev[to] = append(d.rev[to], len(d.to[from])-1)
}

func (d *Dinic) BFS(s, t int) bool {
	for i := range d.minCost {
		d.minCost[i] = -1
	}
	d.minCost[s] = 0
	queue := []int{s}
	head := 0
	for head < len(queue) && d.minCost[t] == -1 {
		p := queue[head]
		head++
		for i, to := range d.to[p] {
			if d.cap[p][i] > 0 && d.minCost[to] == -1 {
				d.minCost[to] = d.minCost[p] + 1
				queue = append(queue, to)
			}
		}
	}
	return d.minCost[t] != -1
}

func (d *Dinic) DFS(idx, t int, flow int64) int64 {
	if idx == t {
		return flow
	}
	for d.iter[idx] < len(d.to[idx]) {
		i := d.iter[idx]
		d.iter[idx]++
		cap := d.cap[idx][i]
		to := d.to[idx][i]
		if cap > 0 && d.minCost[idx] < d.minCost[to] {
			delta := d.DFS(to, t, min(flow, cap))
			if delta > 0 {
				d.cap[idx][i] -= delta
				d.cap[to][d.rev[idx][i]] += delta
				return delta
			}
		}
	}
	return 0
}

func (d *Dinic) MaxFlow(s, t int) int64 {
	flow := int64(0)
	for d.BFS(s, t) {
		for {
			for i := range d.iter {
				d.iter[i] = 0
			}
			f := d.DFS(s, t, math.MaxInt64)
			if f == 0 {
				break
			}
			flow += f
		}
	}
	return flow
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solve() {
	var n int64
	fmt.Scan(&n)

	a := make([]int64, 3)
	b := make([]int64, 3)
	for i := 0; i < 3; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < 3; i++ {
		fmt.Scan(&b[i])
	}
	ma := min(min(a[0], b[1])+min(a[1], b[2])+min(a[2], b[0]), math.MaxInt64)

	d := NewDinic(8)
	d.AddEdge(6, 0, a[0])
	d.AddEdge(6, 1, a[1])
	d.AddEdge(6, 2, a[2])
	d.AddEdge(0, 3, math.MaxInt64)
	d.AddEdge(0, 5, math.MaxInt64)
	d.AddEdge(1, 3, math.MaxInt64)
	d.AddEdge(1, 4, math.MaxInt64)
	d.AddEdge(2, 4, math.MaxInt64)
	d.AddEdge(2, 5, math.MaxInt64)
	d.AddEdge(3, 7, b[0])
	d.AddEdge(4, 7, b[1])
	d.AddEdge(5, 7, b[2])

	fmt.Printf("%d %d\n", n-d.MaxFlow(6, 7), ma)
}

func main() {
	T := 1
	for i := 0; i < T; i++ {
		solve()
	}
}
