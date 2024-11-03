package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func sum(arr []int64) int64 {
	var s int64
	for _, num := range arr {
		s += num
	}
	return s
}

func rec(l, r, k int, dps [][]int64, sums []int64, arrs [][]int64) int64 {
	var ans int64
	carr := arrs[l]
	dp := dps[k]
	if l+1 == r {
		ans = max(ans, dp[k])
		var sum int64
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		dpi := make([]int64, k+1)
		copy(dpi, dp)
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(m, r, k, dps, sums, arrs))
		copy(dp, dpi)
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(l, m, k, dps, sums, arrs))
	}
	return ans
}

func solve(r io.Reader, w io.Writer) {
	var n, k int
	fmt.Fscan(r, &n, &k)
	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(r, &t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(r, &arrs[i][j])
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
	fmt.Fprintln(w, rec(0, n, k, dps, sums, arrs))
}

func main() {
	solve(os.Stdin, os.Stdout)
}
