package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct {
	k    int
	arrs [][]int
	sums []int64
	dps  [][]int64
}

func (solver *DSum) doCopy(dpi int) {
	copy(solver.dps[dpi+1], solver.dps[dpi])
}

func (solver *DSum) addToKnap(i, dpi int) {
	v := solver.sums[i]
	k1 := len(solver.arrs[i])
	for j := solver.k; j >= k1; j-- {
		solver.dps[dpi][j] = max(solver.dps[dpi][j], solver.dps[dpi][j-k1]+v)
	}
}

func (solver *DSum) rec(l, r, dpi int) int64 {
	ans := int64(0)
	carr := solver.arrs[l]
	dp := solver.dps[dpi]
	if l+1 == r {
		ans = max(ans, dp[solver.k])
		sum := int64(0)
		for i := 0; i < min(solver.k, len(carr)); i++ {
			sum += int64(carr[i])
			ans = max(ans, dp[solver.k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		solver.doCopy(dpi)
		for i := l; i < m; i++ {
			solver.addToKnap(i, dpi+1)
		}
		ans = max(ans, solver.rec(m, r, dpi+1))
		solver.doCopy(dpi)
		for i := m; i < r; i++ {
			solver.addToKnap(i, dpi+1)
		}
		ans = max(ans, solver.rec(l, m, dpi+1))
	}
	return ans
}

func (solver *DSum) solve() {
	var n int
	fmt.Scan(&n, &solver.k)
	solver.sums = make([]int64, n)
	solver.arrs = make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		solver.arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Scan(&solver.arrs[i][j])
		}
		if t > solver.k {
			solver.arrs[i] = solver.arrs[i][:solver.k]
		}
		solver.sums[i] = sum(solver.arrs[i])
	}
	solver.dps = make([][]int64, 13)
	for i := range solver.dps {
		solver.dps[i] = make([]int64, solver.k+1)
	}
	fmt.Println(solver.rec(0, n, 0))
}

func sum(arr []int) int64 {
	var total int64
	for _, v := range arr {
		total += int64(v)
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
	solver.solve()
}
