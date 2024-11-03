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

func (s *Solver) rec(l, r, k int, arrs [][]int, sums []int, dps [][]int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[k]
	if l+1 == r {
		if k > len(carr) {
			k = len(carr)
		}
		for i := 0; i <= k; i++ {
			sum := 0
			for j := 0; j < i; j++ {
				sum += carr[j]
			}
			if dp[k-i]+sum > ans {
				ans = dp[k-i] + sum
			}
		}
	} else {
		m := (l + r) / 2
		dps1 := make([][]int, len(dps))
		for i := 0; i < len(dps); i++ {
			dps1[i] = make([]int, len(dps[i]))
			copy(dps1[i], dps[i])
		}
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				if dps1[k][j-k1]+v > dps1[k][j] {
					dps1[k][j] = dps1[k][j-k1] + v
				}
			}
		}
		if rec := s.rec(m, r, k, arrs, sums, dps1); rec > ans {
			ans = rec
		}
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				if dps[k][j-k1]+v > dp[j] {
					dp[j] = dps[k][j-k1] + v
				}
			}
		}
		if rec := s.rec(l, m, k, arrs, sums, dps); rec > ans {
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
	dps := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		dps[i] = make([]int, k+1)
	}
	fmt.Fprintln(s.out, s.rec(0, n, k, arrs, sums, dps))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
