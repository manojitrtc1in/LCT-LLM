package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct{}

func (d *DSum) solve(in *Input) int64 {
	n, k := in.ReadInt(), in.ReadInt()
	sums := make([]int64, n)
	arrs := make([][]int64, n)

	for i := 0; i < n; i++ {
		t := in.ReadInt()
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = in.ReadInt64()
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

	return d.rec(0, n, 0, k, sums, arrs, dps)
}

func (d *DSum) rec(l, r, dpi, k int, sums []int64, arrs [][]int64, dps [][]int64) int64 {
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
	total := int64(0)
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

type Input struct {
	data []string
	index int
}

func (in *Input) ReadInt() int {
	val := in.ReadString()
	return int(val[0] - '0')
}

func (in *Input) ReadInt64() int64 {
	val := in.ReadString()
	return int64(val[0] - '0')
}

func (in *Input) ReadString() string {
	if in.index >= len(in.data) {
		return ""
	}
	val := in.data[in.index]
	in.index++
	return val
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	in := &Input{data: make([]string, n)}
	solver := &DSum{}
	fmt.Println(solver.solve(in))
}
