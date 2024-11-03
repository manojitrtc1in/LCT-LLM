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
		addItems(state, len(A[i]), A_sum[i])
	}

	recurse(mid, end, state, A, A_sum, best)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		addItems(state, len(A[i]), A_sum[i])
	}

	recurse(start, mid, state, A, A_sum, best)
}

func solve(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	N := scanInt(scanner)
	K := scanInt(scanner)

	A := make([][]int64, N)
	A_sum := make([]int64, N)

	for i := 0; i < N; i++ {
		t := scanInt(scanner)
		A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			A[i][j] = scanInt(scanner)
		}

		if t > K {
			A[i] = A[i][:K]
		}

		A_sum[i] = sum(A[i])
	}

	best := int64(0)
	knapsack := make([]int64, K+1)
	recurse(0, N, knapsack, A, A_sum, &best)

	fmt.Fprintln(writer, best)
}

func scanInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func sum(arr []int64) int64 {
	var total int64
	for _, num := range arr {
		total += num
	}
	return total
}

func main() {
	solve(os.Stdin, os.Stdout)
}
