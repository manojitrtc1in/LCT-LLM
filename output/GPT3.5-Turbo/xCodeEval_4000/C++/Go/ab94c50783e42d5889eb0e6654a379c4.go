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

func (s *Solver) rec(l, r, k int, arrs [][]int, sums []int, dp [][]int) int {
	ans := 0
	if l+1 == r {
		ans = s.max(ans, dp[k][k])
		sum := 0
		for i := 0; i < s.min(k, len(arrs[l])); i++ {
			sum += arrs[l][i]
			ans = s.max(ans, dp[k][k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		ans = s.max(ans, s.doSplit(l, m, m, r, k, arrs, sums, dp))
		ans = s.max(ans, s.doSplit(m, r, l, m, k, arrs, sums, dp))
	}
	return ans
}

func (s *Solver) doSplit(l1, r1, l2, r2, k int, arrs [][]int, sums []int, dp [][]int) int {
	for i := l1; i < r1; i++ {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dp[i+1][j] = s.max(dp[i+1][j], dp[i][j-k1]+v)
		}
	}
	return s.rec(l2, r2, k, arrs, sums, dp)
}

func (s *Solver) solve() {
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

	dp := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dp[i] = make([]int, k+1)
	}

	fmt.Fprintln(s.out, s.rec(0, n, k, arrs, sums, dp))
}

func main() {
	solver := NewSolver(os.Stdin, os.Stdout)
	solver.solve()
}
