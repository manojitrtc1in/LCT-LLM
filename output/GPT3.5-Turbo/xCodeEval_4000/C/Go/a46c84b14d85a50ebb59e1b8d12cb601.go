package main

import (
	"fmt"
)

type Dinic struct {
	n         int
	to        []*Vector
	cap       []*Vector
	rev       []*Vector
	minCost   *Vector
	iter      *Vector
}

func (d *Dinic) addEdge(from, to int, cap int64) {
	d.rev[from].push(int64(len(d.to[to])))
	d.rev[to].push(int64(len(d.to[from])))
	d.to[from].push(int64(to))
	d.to[to].push(int64(from))
	d.cap[from].push(cap)
	d.cap[to].push(0)
}

func (d *Dinic) bfs(s, t int) bool {
	init := -1
	for i := 0; i < d.n; i++ {
		d.minCost.set(i, int64(init))
	}
	q := NewVector(1, 4)
	d.minCost.set(s, 0)
	q.push(int64(s))
	head := 0
	for head != q.size() && d.minCost.get(t) == -1 {
		p := q.get(head)
		head++
		for i := 0; i < d.to[p].size(); i++ {
			to := d.to[p].get(i)
			if d.cap[p].get(i) > 0 && d.minCost.get(to) == -1 {
				cost := d.minCost.get(p) + 1
				d.minCost.set(to, cost)
				q.push(int64(to))
			}
		}
	}
	return d.minCost.get(t) != -1
}

func (d *Dinic) dfs(idx, t int, flow int64) int64 {
	if idx == t {
		return flow
	}
	for i := d.iter.get(idx); i < d.cap[idx].size(); i++ {
		d.iter.set(idx, int64(i))
		cap := d.cap[idx].get(i)
		to := d.to[idx].get(i)
		if cap > 0 && d.minCost.get(idx) < d.minCost.get(to) {
			delta := d.dfs(to, t, min(flow, cap))
			if delta > 0 {
				cap -= delta
				d.cap[idx].set(i, cap)
				rev := d.rev[idx].get(i)
				revCap := d.cap[to].get(rev) + delta
				d.cap[to].set(rev, revCap)
				return delta
			}
		}
	}
	return 0
}

func (d *Dinic) maxFlow(s, t int) int64 {
	flow := int64(0)
	for d.bfs(s, t) {
		for i := 0; i < d.n; i++ {
			d.iter.set(i, 0)
		}
		f := int64(0)
		for f = d.dfs(s, t, INF); f > 0; f = d.dfs(s, t, INF) {
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

	ma := min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
	d := &Dinic{
		n:       8,
		to:      make([]*Vector, 8),
		cap:     make([]*Vector, 8),
		rev:     make([]*Vector, 8),
		minCost: NewVector(8, 8),
		iter:    NewVector(8, 8),
	}
	for i := 0; i < 8; i++ {
		d.to[i] = NewVector(1, 4)
		d.cap[i] = NewVector(1, 8)
		d.rev[i] = NewVector(1, 4)
	}
	d.addEdge(6, 0, a[0])
	d.addEdge(6, 1, a[1])
	d.addEdge(6, 2, a[2])
	d.addEdge(0, 3, INF)
	d.addEdge(0, 5, INF)
	d.addEdge(1, 3, INF)
	d.addEdge(1, 4, INF)
	d.addEdge(2, 4, INF)
	d.addEdge(2, 5, INF)
	d.addEdge(3, 7, b[0])
	d.addEdge(4, 7, b[1])
	d.addEdge(5, 7, b[2])

	fmt.Println(n - d.maxFlow(6, 7), ma)
}

func main() {
	T := 1

	for i := 0; i < T; i++ {
		solve()
	}
}
