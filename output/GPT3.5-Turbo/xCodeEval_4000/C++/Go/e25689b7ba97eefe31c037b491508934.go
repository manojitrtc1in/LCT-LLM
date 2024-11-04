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
	x, _ := s.readInt64()
	return int(x)
}

func (s *Solver) readInt64() (int64, error) {
	var x int64
	var err error
	for {
		x, err = s.in.ReadInt64()
		if err == nil {
			break
		}
	}
	return x, err
}

func (s *Solver) readInts(n int) []int {
	a := make([]int, n)
	for i := 0; i < n; i++ {
		a[i] = s.readInt()
	}
	return a
}

func (s *Solver) readInt64s(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i], _ = s.readInt64()
	}
	return a
}

func (s *Solver) solve() {
	n := s.readInt()
	k := s.readInt()
	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		t := s.readInt()
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = s.readInt64()
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int64, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int64, k+1)
	}

	var rec func(l, r, dpi int) int64
	rec = func(l, r, dpi int) int64 {
		ans := int64(0)
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			if dp[k] > ans {
				ans = dp[k]
			}
			sum := int64(0)
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
			if v := rec(m, r, dpi+1); v > ans {
				ans = v
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
			if v := rec(l, m, dpi+1); v > ans {
				ans = v
			}
		}
		return ans
	}

	s.out.Write([]byte(strconv.FormatInt(rec(0, n, 0), 10)))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(arr []int64) int64 {
	var s int64
	for _, v := range arr {
		s += v
	}
	return s
}

func main() {
	s := NewSolver(os.Stdin, os.Stdout)
	s.solve()
}
