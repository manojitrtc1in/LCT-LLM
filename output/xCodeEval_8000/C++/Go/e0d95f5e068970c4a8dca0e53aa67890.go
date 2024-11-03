package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func add_item(knapsack []int64, size int, sum int64) {
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
		*best = max(*best, knapsack[len(knapsack)-1])

		for prefix := 1; prefix <= len(A[start]); prefix++ {
			sum += A[start][prefix-1]
			*best = max(*best, sum+knapsack[len(knapsack)-prefix-1])
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		add_item(state, len(A[i]), A_sum[i])
	}

	recurse(mid, end, state, A, A_sum, best)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		add_item(state, len(A[i]), A_sum[i])
	}

	recurse(start, mid, state, A, A_sum, best)
}

func solve(input io.Reader, output io.Writer) {
	reader := bufio.NewReader(input)
	writer := bufio.NewWriter(output)
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

		A_sum[i] = 0
		for j := 0; j < len(A[i]); j++ {
			A_sum[i] += A[i][j]
		}
	}

	best := int64(0)
	knapsack := make([]int64, K+1)
	recurse(0, N, knapsack, A, A_sum, &best)

	fmt.Fprintln(writer, best)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
