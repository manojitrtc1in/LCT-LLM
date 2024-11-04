package main

import (
	"fmt"
	"math"
	"sort"
)

type ll int64
type flow_t int64

const INF = math.MaxInt64
const MOD1 = 1e9 + 7

type AVLSet struct {
	val   ll
	diff  int
	cnt   int
	child [2]*AVLSet
}

type Vector struct {
	n        int
	max      int
	dataSize int
	data     []byte
}

type Dinic struct {
	n        int
	to       [][]int
	cap      [][]flow_t
	rev      [][]int
	minCost  []int
	iter     []int
}

func (v *Vector) push(x []byte) {
	if v.n == v.max {
		v.max *= 2
		v.data = append(v.data, make([]byte, v.max*v.dataSize)...)
	}
	if x == nil {
		copy(v.data[v.n*v.dataSize:], make([]byte, v.dataSize))
	} else {
		copy(v.data[v.n*v.dataSize:], x)
	}
	v.n++
}

func (v *Vector) set(idx int, x []byte) {
	if x == nil {
		copy(v.data[idx*v.dataSize:], make([]byte, v.dataSize))
	} else {
		copy(v.data[idx*v.dataSize:], x)
	}
}

func (v *Vector) get(idx int) ll {
	var ret ll
	if v.dataSize == 8 {
		ret = *(*ll)(unsafe.Pointer(&v.data[idx*v.dataSize]))
	} else if v.dataSize == 4 {
		ret = *(*int)(unsafe.Pointer(&v.data[idx*v.dataSize]))
	}
	return ret
}

func (d *Dinic) add(from, to int, cap flow_t) {
	d.rev[from] = append(d.rev[from], len(d.to[to]))
	d.rev[to] = append(d.rev[to], len(d.to[from]))
	d.to[from] = append(d.to[from], to)
	d.to[to] = append(d.to[to], from)
	d.cap[from] = append(d.cap[from], cap)
	d.cap[to] = append(d.cap[to], 0)
}

func (d *Dinic) maxFlow(s, t int) flow_t {
	flow := flow_t(0)
	for d.bfs(s, t) {
		for i := 0; i < d.n; i++ {
			d.iter[i] = 0
		}
		for f := d.dfs(s, t, INF); f > 0; f = d.dfs(s, t, INF) {
			flow += f
		}
	}
	return flow
}

func (d *Dinic) bfs(s, t int) bool {
	for i := 0; i < d.n; i++ {
		d.minCost[i] = -1
	}
	d.minCost[s] = 0
	queue := []int{s}
	for len(queue) > 0 {
		p := queue[0]
		queue = queue[1:]
		for i, to := range d.to[p] {
			if d.cap[p][i] > 0 && d.minCost[to] == -1 {
				d.minCost[to] = d.minCost[p] + 1
				queue = append(queue, to)
			}
		}
	}
	return d.minCost[t] != -1
}

func (d *Dinic) dfs(idx, t int, flow flow_t) flow_t {
	if idx == t {
		return flow
	}
	for i := d.iter[idx]; i < len(d.cap[idx]); i++ {
		d.iter[idx] = i
		cap := d.cap[idx][i]
		to := d.to[idx][i]
		if cap > 0 && d.minCost[idx] < d.minCost[to] {
			delta := d.dfs(to, t, min(flow, cap))
			if delta > 0 {
				d.cap[idx][i] -= delta
				d.cap[to][d.rev[idx][i]] += delta
				return delta
			}
		}
	}
	return 0
}

func newVector(n, dataSize int) *Vector {
	return &Vector{
		n:        0,
		max:      n,
		dataSize: dataSize,
		data:     make([]byte, n*dataSize),
	}
}

func newDinic(n int) *Dinic {
	d := &Dinic{
		n:       n,
		to:      make([][]int, n),
		cap:     make([][]flow_t, n),
		rev:     make([][]int, n),
		minCost: make([]int, n),
		iter:    make([]int, n),
	}
	for i := 0; i < n; i++ {
		d.to[i] = make([]int, 0)
		d.cap[i] = make([]flow_t, 0)
		d.rev[i] = make([]int, 0)
	}
	return d
}

func solve() {
	var n ll
	fmt.Scan(&n)

	a := make([]ll, 3)
	b := make([]ll, 3)
	for i := 0; i < 3; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < 3; i++ {
		fmt.Scan(&b[i])
	}
	ma := min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])

	d := newDinic(8)
	d.add(6, 0, a[0])
	d.add(6, 1, a[1])
	d.add(6, 2, a[2])

	d.add(0, 3, INF)
	d.add(0, 5, INF)
	d.add(1, 3, INF)
	d.add(1, 4, INF)
	d.add(2, 4, INF)
	d.add(2, 5, INF)

	d.add(3, 7, b[0])
	d.add(4, 7, b[1])
	d.add(5, 7, b[2])
	fmt.Printf("%d %d\n", n-d.maxFlow(6, 7), ma)
}

func main() {
	T := 1
	for i := 0; i < T; i++ {
		solve()
	}
}

func min(a, b ll) ll {
	if a < b {
		return a
	}
	return b
}
