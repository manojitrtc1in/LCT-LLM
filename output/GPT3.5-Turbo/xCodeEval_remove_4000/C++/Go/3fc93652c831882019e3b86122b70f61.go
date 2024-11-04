package main

import (
	"fmt"
	"io"
	"os"
)

func addItems(knapsack []int64, size int, sum int64) {
	for k := len(knapsack) - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func recurse(start, end int, knapsack []int64, A [][]int64, A_sum []int64, best *int64) {
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
	state := make([]int64, K+1)
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		addItems(state, len(A[i]), A_sum[i])
	}

	recurse(mid, end, state, A, A_sum, best)
	state = make([]int64, K+1)
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		addItems(state, len(A[i]), A_sum[i])
	}

	recurse(start, mid, state, A, A_sum, best)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func DSum(in io.Reader, out io.Writer) {
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

		for _, a := range A[i] {
			A_sum[i] += a
		}
	}

	best := int64(0)
	knapsack := make([]int64, K+1)
	recurse(0, N, knapsack, A, A_sum, &best)

	fmt.Fprintln(out, best)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
