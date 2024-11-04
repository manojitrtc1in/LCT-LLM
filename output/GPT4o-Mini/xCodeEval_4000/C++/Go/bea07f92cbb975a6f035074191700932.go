package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type DSum struct{}

type Solver struct {
	in   *bufio.Reader
	out  *bufio.Writer
	k    int
	dps  [][]int64
	sums []int64
	arrs [][]int64
}

func (s *Solver) readInt() int {
	var x int
	fmt.Fscan(s.in, &x)
	return x
}

func (s *Solver) readInt64() int64 {
	var x int64
	fmt.Fscan(s.in, &x)
	return x
}

func (s *Solver) print(args ...interface{}) {
	fmt.Fprint(s.out, args...)
}

func (s *Solver) printLn(args ...interface{}) {
	fmt.Fprintln(s.out, args...)
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
		m := (l + r) / 2
		s.doCopy(dpi)
		for i := l; i < m; i++ {
			s.addToKnap(i, dpi+1)
		}
		ans = max(ans, s.rec(m, r, dpi+1))
		s.doCopy(dpi)
		for i := m; i < r; i++ {
			s.addToKnap(i, dpi+1)
		}
		ans = max(ans, s.rec(l, m, dpi+1))
	}
	return ans
}

func (s *Solver) solve() {
	n := s.readInt()
	s.k = s.readInt()
	s.sums = make([]int64, n)
	s.arrs = make([][]int64, n)
	for i := 0; i < n; i++ {
		t := s.readInt()
		s.arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			s.arrs[i][j] = s.readInt64()
		}
		if t > s.k {
			s.arrs[i] = s.arrs[i][:s.k]
		}
		s.sums[i] = sum(s.arrs[i])
	}
	s.dps = make([][]int64, 13)
	for i := range s.dps {
		s.dps[i] = make([]int64, s.k+1)
	}
	s.printLn(s.rec(0, n, 0))
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := &Solver{in: in, out: out}
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
