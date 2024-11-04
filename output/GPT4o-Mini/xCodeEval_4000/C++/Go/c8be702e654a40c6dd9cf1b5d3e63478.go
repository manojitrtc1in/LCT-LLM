package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"sort"
)

type DSum struct{}

func (d *DSum) solve(in io.Reader, out io.Writer) {
	reader := bufio.NewReader(in)
	writer := bufio.NewWriter(out)
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
		A_sum[i] = sum(A[i])
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

	recurse(0, N, knapsack)
	fmt.Fprintln(writer, best)
}

func addItem(knapsack []int64, size int, sum int64) {
	for k := len(knapsack) - size - 1; k >= 0; k-- {
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
	var solver DSum
	solver.solve(os.Stdin, os.Stdout)
}
