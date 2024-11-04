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

	out.Println(rec(0, n, 0, k, arrs, sums, dps))
}

func sum(a []int64) int64 {
	var total int64
	for _, v := range a {
		total += v
	}
	return total
}

func doCopy(dpi int, dps [][]int64, k int) {
	copy(dps[dpi+1], dps[dpi])
}

func addToKnap(i, dpi int, k int, arrs [][]int64, sums []int64, dps [][]int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func rec(l, r, dpi, k int, arrs [][]int64, sums []int64, dps [][]int64) int64 {
	var ans int64
	carr := arrs[l]
	dp := dps[dpi]

	if l+1 == r {
		ans = max(ans, dp[k])
		var sum int64
		for i := 0; i < int(math.Min(float64(k), float64(len(carr)))); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		doCopy(dpi, dps, k)
		for i := l; i < m; i++ {
			addToKnap(i, dpi, k, arrs, sums, dps)
		}
		ans = max(ans, rec(m, r, dpi+1, k, arrs, sums, dps))
		doCopy(dpi, dps, k)
		for i := m; i < r; i++ {
			addToKnap(i, dpi, k, arrs, sums, dps)
		}
		ans = max(ans, rec(l, m, dpi+1, k, arrs, sums, dps))
	}
	return ans
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	ds := DSum{}
	ds.solve(fmt.Scan, fmt.Println)
}
