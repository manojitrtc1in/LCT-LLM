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

func NewSolver(r io.Reader, w io.Writer) *Solver {
	return &Solver{in: bufio.NewReader(r), out: w}
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

func (s *Solver) solve() {
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

	var rec func(l, r, dpi int) int
	rec = func(l, r, dpi int) int {
		ans := 0
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			if dp[k] > ans {
				ans = dp[k]
			}
			sum := 0
			for i := 0; i < min(k, len(carr)); i++ {
				sum += carr[i]
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
					if dps[dpi+1][j] < dps[dpi][j-k1]+v {
						dps[dpi+1][j] = dps[dpi][j-k1] + v
					}
				}
			}
			if res := rec(m, r, dpi+1); res > ans {
				ans = res
			}
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					if dps[dpi+1][j] < dps[dpi][j-k1]+v {
						dps[dpi+1][j] = dps[dpi][j-k1] + v
					}
				}
			}
			if res := rec(l, m, dpi+1); res > ans {
				ans = res
			}
		}
		return ans
	}

	fmt.Fprintln(s.out, rec(0, n, 0))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.solve()
}
