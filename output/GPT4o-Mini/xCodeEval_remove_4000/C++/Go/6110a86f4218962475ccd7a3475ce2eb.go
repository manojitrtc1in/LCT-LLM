package main

import (
	"container/heap"
	"fmt"
	"math"
	"math/rand"
	"os"
	"time"
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
var a [100013]Pair
var used [100013]bool
var mn [100013]int64
var cur PriorityQueue

func read() bool {
	_, err := fmt.Scan(&h, &n, &m, &k)
	if err != nil {
		return false
	}
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
	cur = PriorityQueue{}
	heap.Init(&cur)
	for i := 0; i < n; i++ {
		if !used[i] && mn[a[i].x%k] <= a[i].x {
			heap.Push(&cur, &Item{value: a[i].y, priority: -i})
		}
	}
}

func solve() {
	for i := 0; i < k; i++ {
		mn[i] = h + 1
	}
	mn[1] = 1
	for i := range used {
		used[i] = false
	}
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
				for j := 0; j < len(cur); j++ {
					if cur[j].index == -x {
						heap.Remove(&cur, j)
						break
					}
				}
			}
			a[x].y -= y
			if mn[a[x].x%k] <= a[x].x {
				heap.Push(&cur, &Item{value: a[x].y, priority: -x})
			}
		} else if len(cur) > 0 {
			item := heap.Pop(&cur).(*Item)
			fmt.Println(item.value)
			used[-item.priority] = true
		} else {
			fmt.Println(0)
		}
	}
}

func main() {
	file, err := os.Open("input.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	rand.Seed(time.Now().UnixNano())
	start := time.Now()

	for read() {
		solve()
		fmt.Printf("TIME = %v\n", time.Since(start))
		start = time.Now()
	}
}
