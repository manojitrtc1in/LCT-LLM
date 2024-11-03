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
	str, _ := s.in.ReadString(' ')
	num, _ := strconv.Atoi(str[:len(str)-1])
	return num
}

func (s *Solver) readInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = s.readInt()
	}
	return arr
}

func (s *Solver) sum(arr []int) int {
	sum := 0
	for _, num := range arr {
		sum += num
	}
	return sum
}

func (s *Solver) rec(l, r, dpi int, arrs [][]int, sums []int, dps [][]int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[dpi]
	if l+1 == r {
		if k >= len(carr) {
			ans = max(ans, dp[k])
		}
		sum := 0
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		copy(dps[dpi+1], dps[dpi])
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, s.rec(m, r, dpi+1, arrs, sums, dps))
		copy(dps[dpi+1], dps[dpi])
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, s.rec(l, m, dpi+1, arrs, sums, dps))
	}
	return ans
}

func (s *Solver) Solve() {
	n := s.readInt()
	k := s.readInt()
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
	fmt.Fprintln(s.out, s.rec(0, n, 0, arrs, sums, dps))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
