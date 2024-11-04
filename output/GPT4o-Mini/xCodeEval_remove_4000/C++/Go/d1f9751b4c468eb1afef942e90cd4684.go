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

func (s *Solver) readInts(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(s.in, &arr[i])
	}
	return arr
}

func (s *Solver) max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func (s *Solver) doCopy(dpi int) {
	copy(s.dps[dpi+1], s.dps[dpi])
}

func (s *Solver) addToKnap(i, dpi int) {
	v := s.sums[i]
	k1 := len(s.arrs[i])
	for j := s.k; j >= k1; j-- {
		s.dps[dpi][j] = s.max(s.dps[dpi][j], s.dps[dpi][j-k1]+v)
	}
}

func (s *Solver) rec(l, r, dpi int) int64 {
	ans := int64(0)
	carr := s.arrs[l]
	dp := s.dps[dpi]

	if l+1 == r {
		ans = s.max(ans, dp[s.k])
		sum := int64(0)
		for i := 0; i < int(math.Min(float64(s.k), float64(len(carr)))); i++ {
			sum += carr[i]
			ans = s.max(ans, dp[s.k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		s.doCopy(dpi)
		for i := l; i < m; i++ {
			s.addToKnap(i, dpi+1)
		}
		ans = s.max(ans, s.rec(m, r, dpi+1))
		s.doCopy(dpi)
		for i := m; i < r; i++ {
			s.addToKnap(i, dpi+1)
		}
		ans = s.max(ans, s.rec(l, m, dpi+1))
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
		s.arrs[i] = s.readInts(t)
		if t > s.k {
			s.arrs[i] = s.arrs[i][:s.k]
		}
		s.sums[i] = 0
		for _, val := range s.arrs[i] {
			s.sums[i] += val
		}
	}

	s.dps = make([][]int64, 13)
	for i := range s.dps {
		s.dps[i] = make([]int64, s.k+1)
	}

	fmt.Fprintln(s.out, s.rec(0, n, 0))
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := &Solver{in: in, out: out}
	solver.solve()
}
