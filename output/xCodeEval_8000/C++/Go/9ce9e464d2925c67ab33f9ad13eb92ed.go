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
	numStr, _ := s.read()
	num, _ := strconv.Atoi(numStr)
	return num
}

func (s *Solver) read() (string, error) {
	return s.in.ReadString('\n')
}

func (s *Solver) print(args ...interface{}) {
	fmt.Fprint(s.out, args...)
}

func (s *Solver) println(args ...interface{}) {
	fmt.Fprintln(s.out, args...)
}

func (s *Solver) solve() {
	n := s.readInt()
	k := s.readInt()

	sums := make([]int, n)
	arrs := make([][]int, n)

	for i := 0; i < n; i++ {
		t := s.readInt()
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = s.readInt()
		}
		sort.Ints(arrs[i])
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	var rec func(int, int, int) int
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
					if dps[dpi+1][j] < dps[dpi+1][j-k1]+v {
						dps[dpi+1][j] = dps[dpi+1][j-k1] + v
					}
				}
			}
			if rec(m, r, dpi+1) > ans {
				ans = rec(m, r, dpi+1)
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
			if rec(l, m, dpi+1) > ans {
				ans = rec(l, m, dpi+1)
			}
		}

		return ans
	}

	s.println(rec(0, n, 0))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(arr []int) int {
	s := 0
	for _, num := range arr {
		s += num
	}
	return s
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.solve()
}
