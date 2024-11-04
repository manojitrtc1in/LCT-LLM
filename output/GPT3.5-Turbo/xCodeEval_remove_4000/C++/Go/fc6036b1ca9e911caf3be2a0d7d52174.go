package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

type DSum struct{}

func (ds *DSum) solve(input io.Reader, output io.Writer) {
	scanner := bufio.NewScanner(input)
	scanner.Split(bufio.ScanWords)

	N := nextInt(scanner)
	K := nextInt(scanner)

	A := make([][]int64, N)
	A_sum := make([]int64, N)

	for i := 0; i < N; i++ {
		t := nextInt(scanner)
		A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			A[i][j] = nextInt64(scanner)
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

	var add_item func(knapsack []int64, size int, sum int64)
	add_item = func(knapsack []int64, size int, sum int64) {
		for k := K - size; k >= 0; k-- {
			knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
		}
	}

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
			add_item(state, len(A[i]), A_sum[i])
		}

		recurse(mid, end, state)
		state = make([]int64, K+1)
		copy(state, knapsack)

		for i := mid; i < end; i++ {
			add_item(state, len(A[i]), A_sum[i])
		}

		recurse(start, mid, state)
	}

	recurse(0, N, knapsack)
	fmt.Fprintln(output, best)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func main() {
	ds := &DSum{}
	ds.solve(os.Stdin, os.Stdout)
}
