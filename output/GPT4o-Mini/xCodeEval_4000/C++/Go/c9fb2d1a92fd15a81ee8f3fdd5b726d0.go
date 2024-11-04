package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct{}

func (ds *DSum) solve(in *Input, out *Output) {
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

	out.Println(ds.rec(arrs, sums, 0, n, 0, dps, k))
}

func (ds *DSum) rec(arrs [][]int64, sums []int64, l, r, dpi int, dps [][]int64, k int) int64 {
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
		ds.doCopy(dpi, dps, k)
		for i := l; i < m; i++ {
			ds.addToKnap(i, dpi, sums, arrs, dps)
		}
		ans = max(ans, ds.rec(arrs, sums, m, r, dpi+1, dps, k))
		ds.doCopy(dpi, dps, k)
		for i := m; i < r; i++ {
			ds.addToKnap(i, dpi, sums, arrs, dps)
		}
		ans = max(ans, ds.rec(arrs, sums, l, m, dpi+1, dps, k))
	}
	return ans
}

func (ds *DSum) doCopy(dpi int, dps [][]int64, k int) {
	copy(dps[dpi+1], dps[dpi])
}

func (ds *DSum) addToKnap(i, dpi int, sums []int64, arrs [][]int64, dps [][]int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
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

type Input struct {
	// Implementation of input reading
}

func (in *Input) ReadInt() int {
	// Implementation of reading an integer
	return 0
}

func (in *Input) ReadInt64() int64 {
	// Implementation of reading an int64
	return 0
}

type Output struct {
	// Implementation of output writing
}

func (out *Output) Println(args ...interface{}) {
	fmt.Println(args...)
}

func main() {
	in := &Input{}
	out := &Output{}
	solver := &DSum{}
	solver.solve(in, out)
}
