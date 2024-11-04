package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	mod   = 998244353
	INF   = math.MaxInt64
	MAXN  = 100005
)

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	(*G)[from] = append((*G)[from], Edge{to, cap, int64(len((*G)[to])) + int64(from == to)})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, revCap, int64(len((*G)[from])) - 1})
	}
}

func maxFlowDFS(G *Graph, v, t int, f int64, used []bool) int64 {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := (*G)[v][i]
		if !used[e.to] && e.cap > 0 {
			d := maxFlowDFS(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int) int64 {
	flow := int64(0)
	for {
		used := make([]bool, len(*G))
		f := maxFlowDFS(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func bellmanFord(G *Graph, s int, d []int64, negative []bool) {
	d = make([]int64, len(*G))
	negative = make([]bool, len(*G))
	for i := range d {
		d[i] = INF
	}
	d[s] = 0
	for k := 0; k < len(*G)-1; k++ {
		for i := 0; i < len(*G); i++ {
			for j := 0; j < len((*G)[i]); j++ {
				if d[i] != INF && d[(*G)[i][j].to] > d[i]+(*G)[i][j].cap {
					d[(*G)[i][j].to] = d[i] + (*G)[i][j].cap
				}
			}
		}
	}
	for k := 0; k < len(*G)-1; k++ {
		for i := 0; i < len(*G); i++ {
			for j := 0; j < len((*G)[i]); j++ {
				if d[i] != INF && d[(*G)[i][j].to] > d[i]+(*G)[i][j].cap {
					d[(*G)[i][j].to] = d[i] + (*G)[i][j].cap
					negative[(*G)[i][j].to] = true
				}
				if negative[i] {
					negative[(*G)[i][j].to] = true
				}
			}
		}
	}
}

func dijkstra(G *Graph, s int, d []int64) {
	d = make([]int64, len(*G))
	for i := range d {
		d[i] = INF
	}
	d[s] = 0
	q := &PriorityQueue{}
	heap.Push(q, &Item{value: s, priority: 0})
	for q.Len() > 0 {
		a := heap.Pop(q).(*Item)
		if d[a.value] < a.priority {
			continue
		}
		for i := 0; i < len((*G)[a.value]); i++ {
			e := (*G)[a.value][i]
			if d[e.to] > d[a.value]+e.cap {
				d[e.to] = d[a.value] + e.cap
				heap.Push(q, &Item{value: e.to, priority: d[e.to]})
			}
		}
	}
}

func warshallFloyd(G *Graph, d [][]int64) {
	d = make([][]int64, len(*G))
	for i := range d {
		d[i] = make([]int64, len(*G))
		for j := range d[i] {
			if i != j {
				d[i][j] = INF
			} else {
				d[i][j] = 0
			}
		}
	}
	for i := 0; i < len(*G); i++ {
		for j := 0; j < len((*G)[i]); j++ {
			chmin(&d[i][(*G)[i][j].to], (*G)[i][j].cap)
		}
	}
	for i := 0; i < len(*G); i++ {
		for j := 0; j < len(*G); j++ {
			for k := 0; k < len(*G); k++ {
				chmin(&d[j][k], d[j][i]+d[i][k])
			}
		}
	}
}

func chmin(a *int64, b int64) {
	if *a > b {
		*a = b
	}
}

func tsort(graph Graph, order []int) bool {
	n := len(graph)
	k := 0
	in := make([]int, n)
	for _, es := range graph {
		for _, e := range es {
			in[e.to]++
		}
	}
	que := &PriorityQueue{}
	for i := 0; i < n; i++ {
		if in[i] == 0 {
			heap.Push(que, i)
		}
	}
	for que.Len() > 0 {
		v := heap.Pop(que).(int)
		order = append(order, v)
		for _, e := range graph[v] {
			if in[e.to]--; in[e.to] == 0 {
				heap.Push(que, e.to)
			}
		}
	}
	return len(order) == n
}

type Item struct {
	value    int
	priority int64
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	a := make([][]int64, n)
	for i := int64(0); i < n; i++ {
		var t int64
		fmt.Scan(&t)
		for j := int64(0); j < t; j++ {
			var tmp int64
			fmt.Scan(&tmp)
			if len(a[i]) < int(k) {
				a[i] = append(a[i], tmp)
			}
		}
	}
	w := make([]int64, n)
	for i := int64(0); i < n; i++ {
		for j := int64(0); j < int64(len(a[i])); j++ {
			w[i] += a[i][j]
		}
	}
	ans := int64(0)
