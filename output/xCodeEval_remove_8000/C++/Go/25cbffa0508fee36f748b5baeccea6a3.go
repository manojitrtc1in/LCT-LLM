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
	for k := len(knapsack) - 1; k >= size; k-- {
		knapsack[k] = max(knapsack[k], knapsack[k-size]+sum)
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
			*best = max(*best, sum+knapsack[len(knapsack)-1-prefix])
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

func solve(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
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

		if len(A[i]) > K {
			A_sum[i] = A[i][K-1]
		} else {
			A_sum[i] = A[i][len(A[i])-1]
		}
	}

	best := int64(0)
	knapsack := make([]int64, K+1)
	recurse(0, N, knapsack, A, A_sum, &best)

	fmt.Fprintln(writer, best)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}
