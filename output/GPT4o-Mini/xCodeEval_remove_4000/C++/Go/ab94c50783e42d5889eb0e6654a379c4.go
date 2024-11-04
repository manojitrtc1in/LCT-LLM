package main

import (
	"container/heap"
	"fmt"
	"math"
)

type DSum struct{}

type Solver struct {
	in   *Scanner
	out  *Writer
	k    int
	dps  [][]int64
	sums []int64
	arrs [][]int64
}

func (s *Solver) read(args ...interface{}) {
	s.in.Scan(args...)
}

func (s *Solver) print(args ...interface{}) {
	s.out.Write(args...)
}

func (s *Solver) println(args ...interface{}) {
	s.out.Write(args...)
	s.out.Write([]byte{'\n'})
}

func (s *Solver) doCopy(dpi int) {
	copy(s.dps[dpi+1], s.dps[dpi])
}

func (s *Solver) addToKnap(i, dpi int) {
	v := s.sums[i]
	k1 := len(s.arrs[i])
	for j := s.k; j >= k1; j-- {
		s.dps[dpi][j] = max(s.dps[dpi][j], s.dps[dpi][j-k1]+v)
	}
}

func (s *Solver) rec(l, r, dpi int) int64 {
	ans := int64(0)
	carr := s.arrs[l]
	dp := s.dps[dpi]
	if l+1 == r {
		ans = max(ans, dp[s.k])
		sum := int64(0)
		for i := 0; i < min(s.k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[s.k-i-1]+sum)
		}
	} else {
		doSplit := func(l1, r1, l2, r2 int) int64 {
			s.doCopy(dpi)
			for i := l1; i < r1; i++ {
				s.addToKnap(i, dpi+1)
			}
			return s.rec(l2, r2, dpi+1)
		}
		m := (l + r) / 2
		ans = max(ans, doSplit(l, m, m, r))
		ans = max(ans, doSplit(m, r, l, m))
	}
	return ans
}

func (s *Solver) solve() {
	var n int
	s.read(&n, &s.k)
	s.sums = make([]int64, n)
	s.arrs = make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		s.read(&t)
		s.arrs[i] = make([]int64, t)
		s.read(&s.arrs[i])
		if t > s.k {
			s.arrs[i] = s.arrs[i][:s.k]
		}
		s.sums[i] = sum(s.arrs[i])
	}
	s.dps = make([][]int64, 13)
	for i := range s.dps {
		s.dps[i] = make([]int64, s.k+1)
	}
	s.println(s.rec(0, n, 0))
}

func main() {
	var solver DSum
	solver.solve()
}

func sum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += v
	}
	return total
}

func max(a, b int64) int64 {
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

type Scanner struct {
	// Implementation of a scanner for input
}

func (s *Scanner) Scan(args ...interface{}) {
	// Implementation of scan method
}

type Writer struct {
	// Implementation of a writer for output
}

func (w *Writer) Write(args ...interface{}) {
	// Implementation of write method
}
