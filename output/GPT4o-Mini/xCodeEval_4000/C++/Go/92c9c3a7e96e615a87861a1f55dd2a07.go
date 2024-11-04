package main

import (
	"container/heap"
	"fmt"
)

type Pair struct {
	first  int64
	second int64
}

type PriorityQueue []int64

func (pq PriorityQueue) Len() int           { return len(pq) }
func (pq PriorityQueue) Less(i, j int) bool { return pq[i] > pq[j] } // max-heap
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
var n, m, t, c int64

func solve(ind int64, pq *PriorityQueue) {
	if ind == n {
		heap.Push(pq, c)
		if int64(pq.Len()) > t {
			heap.Pop(pq)
		}
		return
	}
	solve(ind+1, pq)
	for i := int64(0); i < int64(len(adj[ind])); i++ {
		if vis[adj[ind][i].first] == 0 {
			vis[adj[ind][i].first] = 1
			c += adj[ind][i].second
			if int64(pq.Len()) < t || c < (*pq)[0] {
				solve(ind+1, pq)
			}
			c -= adj[ind][i].second
			vis[adj[ind][i].first] = 0
		}
	}
}

func main() {
	var r, s, x, i, j, k, l int64
	fmt.Scan(&n, &m, &t)
	adj = make([][]Pair, n)
	vis = make([]int64, n)
	pq := &PriorityQueue{}
	heap.Init(pq)

	for m > 0 {
		m--
		var x, y, w int64
		fmt.Scan(&x, &y, &w)
		x--
		y--
		adj[x] = append(adj[x], Pair{y, w})
	}
	solve(0, pq)
	fmt.Println((*pq)[0])
}
