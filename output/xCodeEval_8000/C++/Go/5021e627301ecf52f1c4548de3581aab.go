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

func (s *Solver) rec(l, r, dpi int, dps [][]int, sums []int, arrs [][]int, k int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[dpi]
	if l+1 == r {
		if k > len(carr) {
			k = len(carr)
		}
		for i := 0; i <= k; i++ {
			sum := 0
			for j := 0; j < i; j++ {
				sum += carr[j]
			}
			if dp[k-i-1]+sum > ans {
				ans = dp[k-i-1] + sum
			}
		}
	} else {
		m := (l + r) / 2
		copy(dps[dpi+1], dps[dpi])
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				if dps[dpi+1][j] < dps[dpi+1][j-k1]+v {
					dps[dpi+1][j] = dps[dpi+1][j-k1] + v
				}
			}
		}
		if rec := s.rec(m, r, dpi+1, dps, sums, arrs, k); rec > ans {
			ans = rec
		}
		copy(dps[dpi+1], dps[dpi])
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				if dps[dpi+1][j] < dps[dpi+1][j-k1]+v {
					dps[dpi+1][j] = dps[dpi+1][j-k1] + v
				}
			}
		}
		if rec := s.rec(l, m, dpi+1, dps, sums, arrs, k); rec > ans {
			ans = rec
		}
	}
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

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	fmt.Fprintln(s.out, s.rec(0, n, 0, dps, sums, arrs, k))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
