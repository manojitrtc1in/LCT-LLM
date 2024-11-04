package main

import (
	"container/heap"
	"fmt"
)

const maxn = 200007
const mod = 998244353

var n, t int
var c [maxn]int
var s [maxn]map[int]struct{}
var st [maxn]map[int]struct{}
var deg [3]priorityQueue
var degt [3]priorityQueue

type pair struct {
	F int
	S int
}

type priorityQueue []pair

func (pq priorityQueue) Len() int {
	return len(pq)
}

func (pq priorityQueue) Less(i, j int) bool {
	return pq[i].F < pq[j].F
}

func (pq priorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *priorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(pair))
}

func (pq *priorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func removeLeaf(s []map[int]struct{}, deg []priorityQueue, v int) {
	if len(s[v]) == 0 {
		deg[c[v]] = remove(deg[c[v]], pair{0, v})
		return
	}
	u := getFirst(s[v])

	if v == 0 {
		return
	}
	deg[c[v]] = remove(deg[c[v]], pair{len(s[v]), v})
	deg[c[u]] = remove(deg[c[u]], pair{len(s[u]), u})
	delete(s[u], v)
	delete(s[v], u)
	deg[c[u]] = insert(deg[c[u]], pair{len(s[u]), u})
}

func eraseGrey(s []map[int]struct{}, deg []priorityQueue) {
	for {
		if len(deg[0]) == 0 {
			break
		}
		ret := deg[0][0]
		if ret.F > 1 {
			break
		}
		removeLeaf(s, deg, ret.S)
	}
}

func solve(s []map[int]struct{}, deg []priorityQueue, beg int) int {
	res := 0
	eraseGrey(s, deg)
	for {
		if len(deg[0]) == 0 && len(deg[1]) == 0 && len(deg[2]) == 0 {
			break
		}
		if len(deg[beg]) == 0 {
			beg = 3 - beg
			continue
		}
		res++
		for {
			if len(deg[beg]) == 0 {
				break
			}
			ret := deg[beg][0]

			if ret.F > 1 {
				break
			}
			removeLeaf(s, deg, ret.S)
			eraseGrey(s, deg)
		}
		beg = 3 - beg
	}
	return res
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < maxn; i++ {
		s[i] = make(map[int]struct{})
		st[i] = make(map[int]struct{})
	}
	for i := 0; i < t; i++ {
		fmt.Scan(&n)
		for j := 1; j <= n; j++ {
			fmt.Scan(&c[j])
		}
		for j := 1; j < n; j++ {
			var u, v int
			fmt.Scan(&u, &v)
			s[u][v] = struct{}{}
			s[v][u] = struct{}{}
			st[u][v] = struct{}{}
			st[v][u] = struct{}{}
		}
		for j := 1; j <= n; j++ {
			deg[c[j]] = insert(deg[c[j]], pair{len(s[j]), j})
			degt[c[j]] = insert(degt[c[j]], pair{len(s[j]), j})
		}
		fmt.Printf("%d ", max(min(solve(s[:], deg[:], 1), solve(st[:], degt[:], 2)), 1))
	}
}

func getFirst(m map[int]struct{}) int {
	for k := range m {
		return k
	}
	return -1
}

func insert(pq priorityQueue, item pair) priorityQueue {
	heap.Push(&pq, item)
	return pq
}

func remove(pq priorityQueue, item pair) priorityQueue {
	for i, v := range pq {
		if v == item {
			pq = append(pq[:i], pq[i+1:]...)
			break
		}
	}
	return pq
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
