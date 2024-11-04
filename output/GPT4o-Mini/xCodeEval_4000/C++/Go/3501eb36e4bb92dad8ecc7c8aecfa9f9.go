package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct{}

func (d *DSum) solve(in *fmt.Scanner, out *fmt.Writer) {
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

	out.WriteString(fmt.Sprintf("%d\n", d.rec(0, n, 0, k, sums, arrs, dps)))
}

func (d *DSum) rec(l, r, dpi, k int, sums []int64, arrs [][]int64, dps [][]int64) int64 {
	var ans int64
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
		d.doCopy(dpi, dps)
		for i := l; i < m; i++ {
			d.addToKnap(i, dpi, sums, arrs, dps)
		}
		ans = max(ans, d.rec(m, r, dpi+1, k, sums, arrs, dps))
		d.doCopy(dpi, dps)
		for i := m; i < r; i++ {
			d.addToKnap(i, dpi, sums, arrs, dps)
		}
		ans = max(ans, d.rec(l, m, dpi+1, k, sums, arrs, dps))
	}
	return ans
}

func (d *DSum) doCopy(dpi int, dps [][]int64) {
	copy(dps[dpi+1], dps[dpi])
}

func (d *DSum) addToKnap(i, dpi int, sums []int64, arrs [][]int64, dps [][]int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := len(dps[dpi]) - 1; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func sum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += v
	}
	return total
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
	in := fmt.NewScanner(os.Stdin)
	out := fmt.NewWriter(os.Stdout)
	solver.solve(in, out)
}
