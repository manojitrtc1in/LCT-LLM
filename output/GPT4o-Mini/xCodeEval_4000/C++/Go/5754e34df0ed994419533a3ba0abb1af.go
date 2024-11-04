package main

import (
	"bufio"
	"fmt"
	"math"
	"sort"
)

type DSum struct{}

func (ds *DSum) solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)

	arrs := make([][]int, n)
	sums := make([]int64, n)

	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(in, &t)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(in, &arrs[i][j])
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

	var rec func(int, int, int) int64
	rec = func(l, r, dpi int) int64 {
		ans := int64(0)
		carr := arrs[l]
		dp := dps[dpi]

		if l+1 == r {
			ans = max(ans, dp[k])
			sum := int64(0)
			for i := 0; i < min(k, len(carr)); i++ {
				sum += int64(carr[i])
				ans = max(ans, dp[k-i-1]+sum)
			}
		} else {
			m := (l + r) / 2
			doSplit := func(l1, r1, l2, r2 int) int64 {
				doCopy(dpi)
				for i := l1; i < r1; i++ {
					addToKnap(i, dpi+1)
				}
				return rec(l2, r2, dpi+1)
			}
			ans = max(ans, doSplit(l, m, m, r))
			ans = max(ans, doSplit(m, r, l, m))
		}
		return ans
	}

	fmt.Fprintln(out, rec(0, n, 0))
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
	reader := bufio.NewReaderSize(os.Stdin, 1024*1024)
	writer := bufio.NewWriterSize(os.Stdout, 1024*1024)
	defer writer.Flush()

	ds := DSum{}
	ds.solve(reader, writer)
}
