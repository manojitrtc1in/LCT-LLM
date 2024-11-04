package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type DSum struct {
	N, K   int
	A      [][]int64
	A_sum  []int64
	best   int64
}

func (solver *DSum) addItem(knapsack []int64, size int, sum int64) {
	for k := solver.K - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func (solver *DSum) recurse(start, end int, knapsack []int64) {
	if start >= end {
		return
	}

	if end-start == 1 {
		sum := int64(0)
		solver.best = max(solver.best, knapsack[solver.K])

		for prefix := 1; prefix <= len(solver.A[start]); prefix++ {
			sum += solver.A[start][prefix-1]
			solver.best = max(solver.best, sum+knapsack[solver.K-prefix])
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		solver.addItem(state, len(solver.A[i]), solver.A_sum[i])
	}

	solver.recurse(mid, end, state)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		solver.addItem(state, len(solver.A[i]), solver.A_sum[i])
	}

	solver.recurse(start, mid, state)
}

func (solver *DSum) solve() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscan(reader, &solver.N, &solver.K)
	solver.A = make([][]int64, solver.N)
	solver.A_sum = make([]int64, solver.N)

	for i := 0; i < solver.N; i++ {
		var t int
		fmt.Fscan(reader, &t)
		solver.A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &solver.A[i][j])
		}

		if t > solver.K {
			solver.A[i] = solver.A[i][:solver.K]
		}

		solver.A_sum[i] = sum(solver.A[i])
	}

	solver.best = 0
	knapsack := make([]int64, solver.K+1)
	solver.recurse(0, solver.N, knapsack)
	fmt.Println(solver.best)
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
	solver := DSum{}
	solver.solve()
}
