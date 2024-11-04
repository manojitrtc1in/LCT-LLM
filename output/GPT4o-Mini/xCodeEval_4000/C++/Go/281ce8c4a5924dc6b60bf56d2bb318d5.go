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

	arrs := make([][]int, n)
	sums := make([]int64, n)

	for i := 0; i < n; i++ {
		var t int
		in.Scan(&t)
		arrs[i] = make([]int, t)
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

	var doCopy func(int)
	doCopy = func(dpi int) {
		copy(dps[dpi+1], dps[dpi])
	}

	var addToKnap func(int, int)
	addToKnap = func(i, dpi int) {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
		}
	}

	var yCombinator func(func(int, int, int) int64) func(int, int, int) int64
	yCombinator = func(f func(int, int, int) int64) func(int, int, int) int64 {
		return func(l, r, dpi int) int64 {
			if l+1 == r {
				ans := dps[dpi][k]
				carr := arrs[l]
				sum := int64(0)
				for i := 0; i < int(math.Min(float64(k), float64(len(carr)))); i++ {
					sum += int64(carr[i])
					ans = max(ans, dps[dpi][k-i-1]+sum)
				}
				return ans
			}
			ans := int64(0)
			m := (l + r) / 2
			doSplit := func(l1, r1, l2, r2 int) int64 {
				doCopy(dpi)
				for i := l1; i < r1; i++ {
					addToKnap(i, dpi+1)
				}
				return f(l2, r2, dpi+1)
			}
			ans = max(ans, doSplit(l, m, m, r))
			ans = max(ans, doSplit(m, r, l, m))
			return ans
		}
	}

	result := yCombinator(func(rec func(int, int, int) int64) func(int, int, int) int64 {
		return func(l, r, dpi int) int64 {
			return rec(l, r, dpi)
		}
	})(0, n, 0)

	fmt.Fprintln(out, result)
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

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	ds := &DSum{}
	ds.solve(fmt.Scan, fmt.Print)
}
