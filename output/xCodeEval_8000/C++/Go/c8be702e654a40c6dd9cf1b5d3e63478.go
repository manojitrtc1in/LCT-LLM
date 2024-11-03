package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

type Solver struct {
	N     int
	K     int
	A     [][]int64
	ASum  []int64
	Best  int64
}

func NewSolver(N, K int, A [][]int64) *Solver {
	return &Solver{
		N:    N,
		K:    K,
		A:    A,
		ASum: make([]int64, N),
		Best: 0,
	}
}

func (s *Solver) addItems(knapsack []int64, size int, sum int64) {
	for k := s.K - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func (s *Solver) recurse(start, end int, knapsack []int64) {
	if start >= end {
		return
	}

	if end-start == 1 {
		sum := int64(0)
		s.Best = max(s.Best, knapsack[s.K])

		for prefix := 1; prefix <= len(s.A[start]); prefix++ {
			sum += s.A[start][prefix-1]
			s.Best = max(s.Best, sum+knapsack[s.K-prefix])
		}

		return
	}

	mid := (start + end) / 2
	state := make([]int64, s.K+1)
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		s.addItems(state, len(s.A[i]), s.ASum[i])
	}

	s.recurse(mid, end, state)
	state = make([]int64, s.K+1)
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		s.addItems(state, len(s.A[i]), s.ASum[i])
	}

	s.recurse(start, mid, state)
}

func (s *Solver) Solve() int64 {
	for i := 0; i < s.N; i++ {
		t := len(s.A[i])
		if t > s.K {
			t = s.K
		}
		s.A[i] = s.A[i][:t]
		s.ASum[i] = 0
		for _, a := range s.A[i] {
			s.ASum[i] += a
		}
	}

	knapsack := make([]int64, s.K+1)
	s.recurse(0, s.N, knapsack)

	return s.Best
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

	var N, K int
	fmt.Fscan(reader, &N, &K)

	A := make([][]int64, N)
	for i := 0; i < N; i++ {
		var t int
		fmt.Fscan(reader, &t)
		A[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &A[i][j])
		}
	}

	solver := NewSolver(N, K, A)
	fmt.Fprintln(writer, solver.Solve())
}
