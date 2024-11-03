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

func (s *Solver) solve(input io.Reader, output io.Writer) {
	reader := bufio.NewReader(input)
	writer := bufio.NewWriter(output)
	defer writer.Flush()

	fmt.Fscan(reader, &s.N, &s.K)
	s.A = make([][]int64, s.N)
	s.ASum = make([]int64, s.N)

	for i := 0; i < s.N; i++ {
		var t int
		fmt.Fscan(reader, &t)
		s.A[i] = make([]int64, t)

		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &s.A[i][j])
		}

		if t > s.K {
			s.A[i] = s.A[i][:s.K]
		}

		sort.Slice(s.A[i], func(a, b int) bool {
			return s.A[i][a] > s.A[i][b]
		})

		for j := 1; j < len(s.A[i]); j++ {
			s.A[i][j] += s.A[i][j-1]
		}

		s.ASum[i] = s.A[i][len(s.A[i])-1]
	}

	s.Best = 0
	knapsack := make([]int64, s.K+1)
	s.recurse(0, s.N, knapsack)

	fmt.Fprintln(writer, s.Best)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	solver := Solver{}
	solver.solve(os.Stdin, os.Stdout)
}
