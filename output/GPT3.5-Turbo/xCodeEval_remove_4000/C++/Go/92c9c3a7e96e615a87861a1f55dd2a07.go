package main

import (
	"container/heap"
	"fmt"
)

type pair struct {
	first  int
	second int
}

type priorityQueue []int

func (pq priorityQueue) Len() int           { return len(pq) }
func (pq priorityQueue) Less(i, j int) bool { return pq[i] > pq[j] }
func (pq priorityQueue) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *priorityQueue) Push(x interface{}) {
	item := x.(int)
	*pq = append(*pq, item)
}

func (pq *priorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func solve(ind int, adj [][]pair, vis []int, c *int, q *priorityQueue, t int) {
	if ind == len(adj) {
		heap.Push(q, *c)
		if q.Len() > t {
			heap.Pop(q)
		}
		return
	}
	solve(ind+1, adj, vis, c, q, t)
	for i := 0; i < len(adj[ind]); i++ {
		if vis[adj[ind][i].first] == 0 {
			vis[adj[ind][i].first] = 1
			*c += adj[ind][i].second
			if q.Len() < t || *c < (*q)[0] {
				solve(ind+1, adj, vis, c, q, t)
			}
			*c -= adj[ind][i].second
			vis[adj[ind][i].first] = 0
		}
	}
}

func main() {
	var n, m, t, c int
	fmt.Scan(&n, &m, &t)
	adj := make([][]pair, n)
	for i := 0; i < m; i++ {
		var x, y, w int
		fmt.Scan(&x, &y, &w)
		x--
		y--
		adj[x] = append(adj[x], pair{y, w})
	}
	vis := make([]int, n)
	q := make(priorityQueue, 0)
	solve(0, adj, vis, &c, &q, t)
	fmt.Println(q[0])
}
