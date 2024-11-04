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
		var sum int64
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

func (s *Solver) Solve() {
	s.Best = 0
	knapsack := make([]int64, s.K+1)
	s.recurse(0, s.N, knapsack)
	fmt.Println(s.Best)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Split(bufio.ScanWords)

	N := readInt(s)
	K := readInt(s)
	A := make([][]int64, N)
	for i := 0; i < N; i++ {
		t := readInt(s)
		A[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			A[i][j] = readInt64(s)
		}
		if t > K {
			A[i] = A[i][:K]
		}
	}

	solver := NewSolver(N, K, A)
	solver.Solve()
}

func readInt(s *bufio.Scanner) int {
	s.Scan()
	n, _ := strconv.Atoi(s.Text())
	return n
}

func readInt64(s *bufio.Scanner) int64 {
	s.Scan()
	n, _ := strconv.ParseInt(s.Text(), 10, 64)
	return n
}
