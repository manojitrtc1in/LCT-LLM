package main

import (
	"container/heap"
	"fmt"
)

type Pair struct {
	first, second int64
}

type PriorityQueue []int64

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i] > pq[j] } // Max-heap
func (pq PriorityQueue) Swap(i, j int)      { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(int64))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

var adj [][]Pair
var vis []int64
var q PriorityQueue
var n, m, t, c int64

func solve(ind int64) {
	if ind == n {
		heap.Push(&q, c)
		if int64(len(q)) > t {
			heap.Pop(&q)
		}
		return
	}
	solve(ind + 1)
	for _, neighbor := range adj[ind] {
		if vis[neighbor.first] == 0 {
			vis[neighbor.first] = 1
			c += neighbor.second
			if int64(len(q)) < t || c < q[0] {
				solve(ind + 1)
			}
			c -= neighbor.second
			vis[neighbor.first] = 0
		}
	}
}

func main() {
	var r, s, x, i, j, k, l int64
	const mod = 1e9 + 7
	fmt.Scan(&n, &m, &t)
	adj = make([][]Pair, n)
	vis = make([]int64, n)

	for m > 0 {
		var x, y, w int64
		fmt.Scan(&x, &y, &w)
		x--
		y--
		adj[x] = append(adj[x], Pair{y, w})
		m--
	}
	heap.Init(&q)
	solve(0)
	fmt.Println(q[0])
}
