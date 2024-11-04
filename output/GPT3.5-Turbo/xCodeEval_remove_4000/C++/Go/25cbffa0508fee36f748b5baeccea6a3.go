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

func NewSolver() *Solver {
	return &Solver{}
}

func (s *Solver) ReadInput(r io.Reader) error {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)

	if !scanner.Scan() {
		return fmt.Errorf("failed to read N")
	}
	N, err := strconv.Atoi(scanner.Text())
	if err != nil {
		return fmt.Errorf("failed to parse N: %w", err)
	}
	s.N = N

	if !scanner.Scan() {
		return fmt.Errorf("failed to read K")
	}
	K, err := strconv.Atoi(scanner.Text())
	if err != nil {
		return fmt.Errorf("failed to parse K: %w", err)
	}
	s.K = K

	s.A = make([][]int64, N)
	s.ASum = make([]int64, N)

	for i := 0; i < N; i++ {
		if !scanner.Scan() {
			return fmt.Errorf("failed to read A[%d] length", i)
		}
		t, err := strconv.Atoi(scanner.Text())
		if err != nil {
			return fmt.Errorf("failed to parse A[%d] length: %w", i, err)
		}

		s.A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			if !scanner.Scan() {
				return fmt.Errorf("failed to read A[%d][%d]", i, j)
			}
			a, err := strconv.Atoi(scanner.Text())
			if err != nil {
				return fmt.Errorf("failed to parse A[%d][%d]: %w", i, j, err)
			}
			s.A[i][j] = int64(a)
		}

		if t > K {
			s.A[i] = s.A[i][:K]
		}

		s.ASum[i] = sum(s.A[i])
	}

	return nil
}

func (s *Solver) Solve() {
	s.Best = 0
	knapsack := make([]int64, s.K+1)

	s.recurse(0, s.N, knapsack)

	fmt.Println(s.Best)
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
	state := make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := start; i < mid; i++ {
		s.addItem(state, len(s.A[i]), s.ASum[i])
	}

	s.recurse(mid, end, state)
	state = make([]int64, len(knapsack))
	copy(state, knapsack)

	for i := mid; i < end; i++ {
		s.addItem(state, len(s.A[i]), s.ASum[i])
	}

	s.recurse(start, mid, state)
}

func (s *Solver) addItem(knapsack []int64, size int, sum int64) {
	for k := s.K - size; k >= 0; k-- {
		knapsack[k+size] = max(knapsack[k+size], knapsack[k]+sum)
	}
}

func sum(arr []int64) int64 {
	var s int64
	for _, v := range arr {
		s += v
	}
	return s
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	solver := NewSolver()
	err := solver.ReadInput(os.Stdin)
	if err != nil {
		fmt.Fprintf(os.Stderr, "failed to read input: %v\n", err)
		os.Exit(1)
	}
	solver.Solve()
}
