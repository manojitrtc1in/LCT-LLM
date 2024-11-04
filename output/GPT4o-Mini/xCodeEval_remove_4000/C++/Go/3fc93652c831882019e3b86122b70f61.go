package main

import (
	"fmt"
	"math"
	"sort"
)

var N, K int
var A [][]int64
var A_sum []int64
var best int64

func addItem(knapsack []int64, size int, sum int64) {
	for k := K - size; k >= 0; k-- {
		knapsack[k+size] = int64(math.Max(float64(knapsack[k+size]), float64(knapsack[k]+sum)))
	}
}

func recurse(start, end int, knapsack []int64) {
	if start >= end {
		return
	}

	if end-start == 1 {
		sum := int64(0)
		best = int64(math.Max(float64(best), float64(knapsack[K])))

		for prefix := 1; prefix <= len(A[start]); prefix++ {
			sum += A[start][prefix-1]
			best = int64(math.Max(float64(best), float64(sum+knapsack[K-prefix])))
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		addItem(state, len(A[i]), A_sum[i])
	}

	recurse(mid, end, state)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		addItem(state, len(A[i]), A_sum[i])
	}

	recurse(start, mid, state)
}

type DSum struct{}

func (d *DSum) solve() {
	var t int
	fmt.Scan(&N, &K)
	A = make([][]int64, N)
	A_sum = make([]int64, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&t)
		A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Scan(&A[i][j])
		}

		if t > K {
			A[i] = A[i][:K]
		}

		A_sum[i] = 0
		for _, a := range A[i] {
			A_sum[i] += a
		}
	}

	best = 0
	knapsack := make([]int64, K+1)
	recurse(0, N, knapsack)
	fmt.Println(best)
}

func main() {
	var solver DSum
	solver.solve()
}
