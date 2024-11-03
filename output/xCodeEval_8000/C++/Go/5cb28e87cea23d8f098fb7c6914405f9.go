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

func solve(n, k int, sums []int64, arrs [][]int64) int64 {
	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}

	var rec func(l, r, dpi int) int64
	rec = func(l, r, dpi int) int64 {
		ans := int64(0)
		carr := arrs[l]
		dp := dps[dpi]

		if l+1 == r {
			ans = max(ans, dp[k])
			var sum int64
			for i := 0; i < min(k, len(carr)); i++ {
				sum += carr[i]
				ans = max(ans, dp[k-i-1]+sum)
			}
		} else {
			m := (l + r) / 2
			copy(dps[dpi+1], dps[dpi])
			for i := l; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dps[dpi+1][j] = max(dps[dpi+1][j], dps[dpi][j-k1]+v)
				}
			}
			ans = max(ans, rec(m, r, dpi+1))
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dps[dpi+1][j] = max(dps[dpi+1][j], dps[dpi][j-k1]+v)
				}
			}
			ans = max(ans, rec(l, m, dpi+1))
		}

		return ans
	}

	return rec(0, n, 0)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(reader, &t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &arrs[i][j])
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	sort.Slice(sums, func(i, j int) bool {
		return sums[i] > sums[j]
	})

	fmt.Fprintln(writer, solve(n, k, sums, arrs))
}
