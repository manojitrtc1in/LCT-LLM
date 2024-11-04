package main

import (
	"fmt"
	"math"
	"sort"
)

type int64Slice []int64

func (s int64Slice) Len() int {
	return len(s)
}

func (s int64Slice) Less(i, j int) bool {
	return s[i] < s[j]
}

func (s int64Slice) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func main() {
	var n, d int
	var x int64
	fmt.Scan(&n, &d, &x)

	a := make([]int64, n)
	b := make([]bool, n)
	for i := range a {
		a[i] = int64(i + 1)
	}

	for i := 0; i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		a[i], a[x%(int64(i)+1)] = a[x%(int64(i)+1)], a[i]
	}

	for i := 0; i < d; i++ {
		b[i] = true
	}
	for i := 0; i < n; i++ {
		x = (x*37 + 10007) % 1000000007
		c := b[i]
		b[i] = b[x%(int64(i)+1)]
		b[x%(int64(i)+1)] = c
	}

	soln := make([]int64, n)

	var idx []int
	for j := 0; j < n; j++ {
		if b[j] {
			idx = append(idx, j)
		}
	}

	type valueType struct {
		val int64
		idx int
	}

	minHeap := make([]valueType, 0)
	budget := int64(1000000)

	for j := 0; j < n; j++ {
		minHeap = append(minHeap, valueType{a[j], j})
		if int64(len(minHeap)) > budget/int64(len(idx)) {
			sort.Sort(int64Slice(minHeap))
			minHeap = minHeap[:len(minHeap)-1]
		}
	}

	heap := make([]valueType, 0)
	for len(minHeap) > 0 {
		sort.Sort(int64Slice(minHeap))
		heap = append(heap, minHeap[len(minHeap)-1])
		minHeap = minHeap[:len(minHeap)-1]
	}

	for len(heap) > 0 {
		sort.Sort(int64Slice(heap))
		val := heap[len(heap)-1].val
		i := heap[len(heap)-1].idx
		heap = heap[:len(heap)-1]

		for _, j := range idx {
			if j+i < n {
				soln[j+i] = max(soln[j+i], val)
			} else {
				break
			}
		}
	}

	for j := 0; j < n; j++ {
		if soln[j] == 0 {
			for _, i := range idx {
				if j < i {
					break
				} else {
					soln[j] = max(soln[j], a[j-i])
				}
			}
		}
	}

	for _, v := range soln {
		fmt.Println(v)
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
