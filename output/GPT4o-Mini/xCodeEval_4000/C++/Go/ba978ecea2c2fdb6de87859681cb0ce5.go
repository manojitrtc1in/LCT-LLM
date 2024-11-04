package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct{}

func (ds *DSum) solve(in *fmt.Scanner, out *fmt.Writer) {
	var n, k int
	in.Scan(&n, &k)

	sums := make([]int64, n)
	arrs := make([][]int64, n)

	for i := 0; i < n; i++ {
		var t int
		in.Scan(&t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			in.Scan(&arrs[i][j])
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}

	result := rec(arrs, sums, 0, n, 0, k, dps)
	fmt.Fprintln(out, result)
}

func sum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += v
	}
	return total
}

func rec(arrs [][]int64, sums []int64, l, r, dpi, k int, dps [][]int64) int64 {
	ans := int64(0)
	carr := arrs[l]
	dp := dps[dpi]

	if l+1 == r {
		ans = max(ans, dp[k])
		sum := int64(0)
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		doCopy(dpi, dps, k)

		for i := l; i < m; i++ {
			addToKnap(i, dpi, arrs, sums, dp)
		}
		ans = max(ans, rec(arrs, sums, m, r, dpi+1, k, dps))

		doCopy(dpi, dps, k)
		for i := m; i < r; i++ {
			addToKnap(i, dpi, arrs, sums, dp)
		}
		ans = max(ans, rec(arrs, sums, l, m, dpi+1, k, dps))
	}
	return ans
}

func doCopy(dpi int, dps [][]int64, k int) {
	copy(dps[dpi+1], dps[dpi])
}

func addToKnap(i, dpi int, arrs [][]int64, sums []int64, dp []int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dp[j] = max(dp[j], dp[j-k1]+v)
	}
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

func main() {
	var solver DSum
	solver.solve(fmt.NewScanner(os.Stdin), os.Stdout)
}
