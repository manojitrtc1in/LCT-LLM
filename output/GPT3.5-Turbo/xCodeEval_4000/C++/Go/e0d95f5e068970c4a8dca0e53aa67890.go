package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N, K int
	fmt.Fscan(reader, &N, &K)

	A := make([][]int64, N)
	A_sum := make([]int64, N)

	for i := 0; i < N; i++ {
		var t int
		fmt.Fscan(reader, &t)
		A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &A[i][j])
		}

		if t > K {
			A[i] = A[i][:K]
		}

		sort.Slice(A[i], func(a, b int) bool {
			return A[i][a] > A[i][b]
		})

		for j := 1; j < len(A[i]); j++ {
			A[i][j] += A[i][j-1]
		}

		if len(A[i]) > 0 {
			A_sum[i] = A[i][len(A[i])-1]
		}
	}

	best := int64(0)
	knapsack := make([]int64, K+1)

	var recurse func(start, end int, knapsack []int64)
	recurse = func(start, end int, knapsack []int64) {
		if start >= end {
			return
		}

		if end-start == 1 {
			sum := int64(0)
			best = max(best, knapsack[K])

			for prefix := 1; prefix <= len(A[start]); prefix++ {
				sum += A[start][prefix-1]
				best = max(best, sum+knapsack[K-prefix])
			}

			return
		}

		mid := (start + end) / 2
		state := make([]int64, K+1)
		copy(state, knapsack)

		for i := start; i < mid; i++ {
			addItem(state, len(A[i]), A_sum[i])
		}

		recurse(mid, end, state)
		state = make([]int64, K+1)
		copy(state, knapsack)

		for i := mid; i < end; i++ {
			addItem(state, len(A[i]), A_sum[i])
		}

		recurse(start, mid, state)
	}

	recurse(0, N, knapsack)
	fmt.Fprintln(writer, best)
}

func addItem(knapsack []int64, size int, sum int64) {
	for k := len(knapsack) - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
