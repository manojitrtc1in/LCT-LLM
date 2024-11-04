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
	return &Solver{
		in:  bufio.NewReader(r),
		out: w,
	}
}

func (s *Solver) readInt() int {
	word, _ := s.in.ReadString('\n')
	num, _ := strconv.Atoi(word[:len(word)-1])
	return num
}

func (s *Solver) readInts(n int) []int {
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		nums[i] = s.readInt()
	}
	return nums
}

func (s *Solver) sum(arr []int) int {
	total := 0
	for _, num := range arr {
		total += num
	}
	return total
}

func (s *Solver) max(a, b int) int {
	if a > b {
		return a
	}
	return b
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
	for i := range dps {
		dps[i] = make([]int, k+1)
	}

	var rec func(l, r, dpi int) int
	rec = func(l, r, dpi int) int {
		ans := 0
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			ans = s.max(ans, dp[k])
			sum := 0
			for i := 0; i < s.min(k, len(carr)); i++ {
				sum += carr[i]
				ans = s.max(ans, dp[k-i-1]+sum)
			}
		} else {
			m := (l + r) / 2
			copy(dps[dpi+1], dps[dpi])
			for i := l; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = s.max(dp[j], dp[j-k1]+v)
				}
			}
			ans = s.max(ans, rec(m, r, dpi+1))
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = s.max(dp[j], dp[j-k1]+v)
				}
			}
			ans = s.max(ans, rec(l, m, dpi+1))
		}
		return ans
	}

	fmt.Fprintln(s.out, rec(0, n, 0))
}

func main() {
	s := NewSolver(os.Stdin, os.Stdout)
	s.solve()
}
