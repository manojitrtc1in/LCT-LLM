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
	total := 0
	for _, num := range arr {
		total += num
	}
	return total
}

func (s *Solver) max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func (s *Solver) rec(l, r, k int, arrs [][]int, sums []int, dp [][]int) int {
	if l+1 == r {
		ans := 0
		carr := arrs[l]
		for i := 0; i <= k && i <= len(carr); i++ {
			sum := s.sum(carr[:i])
			ans = s.max(ans, dp[k-i][l]+sum)
		}
		return ans
	} else {
		m := (l + r) / 2
		dp1 := make([][]int, k+1)
		for i := range dp1 {
			dp1[i] = make([]int, r-l+1)
			copy(dp1[i], dp[i])
		}
		for i := l; i < m; i++ {
			carr := arrs[i]
			v := sums[i]
			for j := k; j >= len(carr); j-- {
				dp1[j] = append(dp1[j], dp1[j-len(carr)]+v)
			}
		}
		ans := s.rec(m, r, k, arrs, sums, dp1)
		dp2 := make([][]int, k+1)
		for i := range dp2 {
			dp2[i] = make([]int, r-l+1)
			copy(dp2[i], dp[i])
		}
		for i := m; i < r; i++ {
			carr := arrs[i]
			v := sums[i]
			for j := k; j >= len(carr); j-- {
				dp2[j] = append(dp2[j], dp2[j-len(carr)]+v)
			}
		}
		ans = s.max(ans, s.rec(l, m, k, arrs, sums, dp2))
		return ans
	}
}

func (s *Solver) Solve() {
	n, k := s.readInt(), s.readInt()
	arrs := make([][]int, n)
	sums := make([]int, n)
	for i := 0; i < n; i++ {
		t := s.readInt()
		arrs[i] = s.readInts(t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = s.sum(arrs[i])
	}
	dp := make([][]int, k+1)
	for i := range dp {
		dp[i] = make([]int, n+1)
	}
	fmt.Fprintln(s.out, s.rec(0, n, k, arrs, sums, dp))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
