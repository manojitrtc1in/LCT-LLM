package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct {
	N, K int
	A    [][]int64
	A_sum []int64
	best  int64
}

func (ds *DSum) addItem(knapsack []int64, size int, sum int64) {
	for k := ds.K - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func (ds *DSum) recurse(start, end int, knapsack []int64) {
	if start >= end {
		return
	}

	if end-start == 1 {
		sum := int64(0)
		ds.best = max(ds.best, knapsack[ds.K])

		for prefix := 1; prefix <= len(ds.A[start]); prefix++ {
			sum += ds.A[start][prefix-1]
			ds.best = max(ds.best, sum+knapsack[ds.K-prefix])
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		ds.addItem(state, len(ds.A[i]), ds.A_sum[i])
	}

	ds.recurse(mid, end, state)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		ds.addItem(state, len(ds.A[i]), ds.A_sum[i])
	}

	ds.recurse(start, mid, state)
}

func (ds *DSum) solve() {
	fmt.Scan(&ds.N, &ds.K)
	ds.A = make([][]int64, ds.N)
	ds.A_sum = make([]int64, ds.N)

	for i := 0; i < ds.N; i++ {
		var t int
		fmt.Scan(&t)
		ds.A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Scan(&ds.A[i][j])
		}

		if t > ds.K {
			ds.A[i] = ds.A[i][:ds.K]
		}

		ds.A_sum[i] = sum(ds.A[i])
	}

	ds.best = 0
	knapsack := make([]int64, ds.K+1)
	ds.recurse(0, ds.N, knapsack)
	fmt.Println(ds.best)
}

func sum(arr []int64) int64 {
	total := int64(0)
	for _, v := range arr {
		total += v
	}
	return total
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var solver DSum
	solver.solve()
}
