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

func (s *Solver) rec(l, r, k int, arrs [][]int, sums []int, dps [][]int) int {
	ans := 0
	if l+1 == r {
		for i := 0; i <= k && i <= len(arrs[l]); i++ {
			sum := s.sum(arrs[l][:i])
			if i < k {
				ans = max(ans, dps[k-i-1]+sum)
			} else {
				ans = max(ans, dps[k]+sum)
			}
		}
	} else {
		m := (l + r) / 2
		dps1 := make([][]int, len(dps))
		copy(dps1, dps)
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dps1[j] = max(dps1[j], dps[j-k1]+v)
			}
		}
		ans = max(ans, s.rec(m, r, k, arrs, sums, dps1))
		copy(dps1, dps)
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dps1[j] = max(dps1[j], dps[j-k1]+v)
			}
		}
		ans = max(ans, s.rec(l, m, k, arrs, sums, dps1))
	}
	return ans
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
	dps := make([][]int, k+1)
	for i := 0; i <= k; i++ {
		dps[i] = make([]int, k+1)
	}
	ans := s.rec(0, n, k, arrs, sums, dps)
	fmt.Fprintln(s.out, ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.Solve()
}
