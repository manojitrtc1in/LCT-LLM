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
	numStr, _ := s.read()
	num, _ := strconv.Atoi(numStr)
	return num
}

func (s *Solver) read() (string, error) {
	str, err := s.in.ReadString('\n')
	if err != nil {
		return "", err
	}
	return str[:len(str)-1], nil
}

func (s *Solver) write(str string) {
	fmt.Fprint(s.out, str)
}

func (s *Solver) writeLine(str string) {
	fmt.Fprintln(s.out, str)
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
			if k < len(carr) {
				ans = max(ans, dp[k])
				sum := 0
				for i := 0; i < min(k, len(carr)); i++ {
					sum += carr[i]
					ans = max(ans, dp[k-i-1]+sum)
				}
			} else {
				ans = max(ans, dp[len(carr)])
			}
		} else {
			m := (l + r) / 2
			copy(dps[dpi+1], dps[dpi])
			for i := l; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = max(dp[j], dp[j-k1]+v)
				}
			}
			ans = max(ans, rec(m, r, dpi+1))
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = max(dp[j], dp[j-k1]+v)
				}
			}
			ans = max(ans, rec(l, m, dpi+1))
		}
		return ans
	}

	s.writeLine(strconv.Itoa(rec(0, n, 0)))
}

func max(a, b int) int {
	if a > b {
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
