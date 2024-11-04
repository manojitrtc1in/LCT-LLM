package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type DSum struct{}

func (d *DSum) solve(in *bufio.Reader, out *bufio.Writer) {
	var N, K int
	fmt.Fscan(in, &N, &K)

	A := make([][]int64, N)
	A_sum := make([]int64, N)

	for i := 0; i < N; i++ {
		var t int
		fmt.Fscan(in, &t)
		A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Fscan(in, &A[i][j])
		}

		if t > K {
			A[i] = A[i][:K]
		}

		A_sum[i] = sum(A[i])
	}

	best := int64(0)
	knapsack := make([]int64, K+1)
	d.recurse(0, N, knapsack, A, A_sum, &best)
	fmt.Fprintln(out, best)
}

func (d *DSum) recurse(start, end int, knapsack []int64, A [][]int64, A_sum []int64, best *int64) {
	if start >= end {
		return
	}

	if end-start == 1 {
		sum := int64(0)
		*best = max(*best, knapsack[K])

		for prefix := 1; prefix <= len(A[start]); prefix++ {
			sum += A[start][prefix-1]
			*best = max(*best, sum+knapsack[K-prefix])
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		d.addItem(state, len(A[i]), A_sum[i])
	}

	d.recurse(mid, end, state, A, A_sum, best)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		d.addItem(state, len(A[i]), A_sum[i])
	}

	d.recurse(start, mid, state, A, A_sum, best)
}

func (d *DSum) addItem(knapsack []int64, size int, sum int64) {
	for k := K - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solver := DSum{}
	solver.solve(reader, writer)
}
