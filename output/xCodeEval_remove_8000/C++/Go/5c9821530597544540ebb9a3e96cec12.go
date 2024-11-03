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
	in  *bufio.Reader
	out io.Writer
}

func NewSolver(in io.Reader, out io.Writer) *Solver {
	return &Solver{
		in:  bufio.NewReader(in),
		out: out,
	}
}

func (s *Solver) readInt() int {
	token, _ := s.in.ReadBytes('\n')
	num, _ := strconv.Atoi(string(token[:len(token)-1]))
	return num
}

func (s *Solver) readInts(n int) []int {
	ints := make([]int, n)
	for i := 0; i < n; i++ {
		ints[i] = s.readInt()
	}
	return ints
}

func (s *Solver) sum(arr []int) int {
	sum := 0
	for _, num := range arr {
		sum += num
	}
	return sum
}

func (s *Solver) max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (s *Solver) rec(l, r, k int, arrs [][]int, sums []int, dp [][]int) int {
	if l+1 == r {
		if k >= len(arrs[l]) {
			return dp[l][k]
		}
		sum := 0
		ans := dp[l][k]
		for i := 0; i < k && i < len(arrs[l]); i++ {
			sum += arrs[l][i]
			ans = s.max(ans, dp[l][k-i-1]+sum)
		}
		return ans
	}

	m := (l + r) / 2
	dp1 := make([][]int, len(dp))
	for i := range dp {
		dp1[i] = make([]int, len(dp[i]))
		copy(dp1[i], dp[i])
	}

	for i := l; i < m; i++ {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dp1[i+1][j] = s.max(dp1[i+1][j], dp1[i][j-k1]+v)
		}
	}

	ans := s.rec(m, r, k, arrs, sums, dp1)

	for i := m; i < r; i++ {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dp1[i+1][j] = s.max(dp1[i+1][j], dp1[i][j-k1]+v)
		}
	}

	ans = s.max(ans, s.rec(l, m, k, arrs, sums, dp1))

	return ans
}

func (s *Solver) Solve() {
	n, k := s.readInt(), s.readInt()
	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := s.readInt()
		arrs[i] = s.readInts(t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = s.sum(arrs[i])
	}

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, k+1)
	}

	fmt.Fprintln(s.out, s.rec(0, n, k, arrs, sums, dp))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
