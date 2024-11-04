package main

import (
	"container/heap"
	"fmt"
	"math"
)

type DSum struct{}

type Solver struct {
	in  *Reader
	out *Writer
}

func (s *Solver) read(args ...interface{}) {
	s.in.Read(args...)
}

func (s *Solver) print(args ...interface{}) {
	s.out.Write(args...)
}

func (s *Solver) println(args ...interface{}) {
	s.out.WriteLine(args...)
}

func (s *Solver) solve() {
	var n, k int
	s.read(&n, &k)

	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		s.read(&t)
		arrs[i] = make([]int, t)
		s.read(&arrs[i])
		if t > k {
			arrs[i] = arrs[i][:k]
		}
	}

	sums := make([]int64, n)
	for i := 0; i < n; i++ {
		for _, v := range arrs[i] {
			sums[i] += int64(v)
		}
	}

	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}

	var doCopy func(int)
	doCopy = func(dpi int) {
		copy(dps[dpi+1], dps[dpi])
	}

	id14 := func(i, dpi int) {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
		}
	}

	s.println(id13(func(rec func(int, int, int) int64, l, r, dpi int) int64 {
		ans := int64(0)
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			ans = max(ans, dp[k])
			sum := int64(0)
			for i := 0; i < min(k, len(carr)); i++ {
				sum += int64(carr[i])
				ans = max(ans, dp[k-i-1]+sum)
			}
		} else {
			doSplit := func(l1, r1, l2, r2 int) int64 {
				doCopy(dpi)
				for i := l1; i < r1; i++ {
					id14(i, dpi+1)
				}
				return rec(l2, r2, dpi+1)
			}
			m := (l + r) / 2
			ans = max(ans, doSplit(l, m, m, r))
			ans = max(ans, doSplit(m, r, l, m))
		}
		return ans
	})(0, n, 0))
}

func (d *DSum) Solve(in *Reader, out *Writer) {
	solver := &Solver{in: in, out: out}
	solver.solve()
}

func main() {
	in := NewReader()
	out := NewWriter()
	solver := &DSum{}
	solver.Solve(in, out)
}

// Utility functions and types

type Reader struct {
	// Implementation for reading input
}

func NewReader() *Reader {
	// Initialize and return a new Reader
	return &Reader{}
}

type Writer struct {
	// Implementation for writing output
}

func NewWriter() *Writer {
	// Initialize and return a new Writer
	return &Writer{}
}

func (w *Writer) Write(args ...interface{}) {
	// Implementation for writing output
}

func (w *Writer) WriteLine(args ...interface{}) {
	// Implementation for writing a line of output
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

func id13(rec func(func(int, int, int) int64, int, int, int) int64) int64 {
	// Implementation for id13 function
	return 0
}
