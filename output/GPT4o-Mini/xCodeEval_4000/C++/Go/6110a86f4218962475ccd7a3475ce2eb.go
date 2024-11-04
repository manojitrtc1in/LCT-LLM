package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	x, y int
}

type Item struct {
	value    int
	priority int
	index    int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
	pq[i].index = i
	pq[j].index = j
}

func (pq *PriorityQueue) Push(x interface{}) {
	n := len(*pq)
	item := x.(*Item)
	item.index = n
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

const INF = int(1e9)
const INF64 = int64(1e18)
const MOD = INF + 7
const EPS = 1e-9
const PI = math.Acos(-1.0)

var n, m, k int
var h int64
var a []Pair
var used []bool
var mn []int64
var pq PriorityQueue

func read() bool {
	if _, err := fmt.Scan(&h, &n, &m, &k); err != nil {
		return false
	}
	a = make([]Pair, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
	}
	return true
}

func add(x int64) {
	queue := make([]int, 0, k)
	for i := 0; i < k; i++ {
		queue = append(queue, i)
	}
	for len(queue) > 0 {
		v := queue[0]
		queue = queue[1:]
		if mn[v]+x < mn[(v+int(x))%k] {
			mn[(v+int(x))%k] = mn[v] + x
			queue = append(queue, (v+int(x))%k)
		}
	}
}

func recalc() {
	pq = make(PriorityQueue, 0)
	for i := 0; i < n; i++ {
		if !used[i] && mn[a[i].x%k] <= a[i].x {
			heap.Push(&pq, &Item{value: a[i].y, priority: -i})
		}
	}
}

func solve() {
	mn = make([]int64, k)
	for i := 0; i < k; i++ {
		mn[i] = h + 1
	}
	mn[1] = 1
	used = make([]bool, n)
	recalc()
	for i := 0; i < m; i++ {
		var t int
		fmt.Scan(&t)
		if t == 1 {
			var x int64
			fmt.Scan(&x)
			add(x)
			recalc()
		} else if t == 2 {
			var x, y int
			fmt.Scan(&x, &y)
			x--
			if mn[a[x].x%k] <= a[x].x {
				pq = removeItem(pq, -x)
			}
			a[x].y -= y
			if mn[a[x].x%k] <= a[x].x {
				heap.Push(&pq, &Item{value: a[x].y, priority: -x})
			}
		} else if len(pq) > 0 {
			item := heap.Pop(&pq).(*Item)
			fmt.Println(item.value)
			used[-item.priority] = true
		} else {
			fmt.Println(0)
		}
	}
}

func removeItem(pq PriorityQueue, index int) PriorityQueue {
	for i, item := range pq {
		if item.index == index {
			pq = append(pq[:i], pq[i+1:]...)
			heap.Init(&pq)
			break
		}
	}
	return pq
}

func main() {
	for read() {
		solve()
	}
}
