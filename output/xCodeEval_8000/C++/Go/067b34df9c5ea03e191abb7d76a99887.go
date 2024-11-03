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

func (s *Solver) rec(l, r, dpi int, arrs [][]int, dps [][]int, sums []int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[dpi]
	if l+1 == r {
		if k < len(carr) {
			carr = carr[:k]
		}
		for i := 0; i <= k && i <= len(carr); i++ {
			sum := s.sum(carr[:i])
			if dp[k-i-1]+sum > ans {
				ans = dp[k-i-1] + sum
			}
		}
	} else {
		m := (l + r) / 2
		s.doCopy(dpi, dps)
		for i := l; i < m; i++ {
			s.addToKnap(i, dpi+1, dps, arrs)
		}
		if rec := s.rec(m, r, dpi+1, arrs, dps, sums); rec > ans {
			ans = rec
		}
		s.doCopy(dpi, dps)
		for i := m; i < r; i++ {
			s.addToKnap(i, dpi+1, dps, arrs)
		}
		if rec := s.rec(l, m, dpi+1, arrs, dps, sums); rec > ans {
			ans = rec
		}
	}
	return ans
}

func (s *Solver) doCopy(dpi int, dps [][]int) {
	copy(dps[dpi+1], dps[dpi])
}

func (s *Solver) addToKnap(i, dpi int, dps [][]int, arrs [][]int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		if dp := dps[dpi][j-k1] + v; dp > dps[dpi][j] {
			dps[dpi][j] = dp
		}
	}
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

	s.out.Write([]byte(strconv.Itoa(s.rec(0, n, 0, arrs, dps, sums))))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
