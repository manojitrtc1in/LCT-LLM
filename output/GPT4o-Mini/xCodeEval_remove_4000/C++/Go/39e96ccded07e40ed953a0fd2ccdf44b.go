package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type DSum struct{}

func (ds *DSum) solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)

	sums := make([]int64, n)
	arrs := make([][]int64, n)

	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(in, &t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(in, &arrs[i][j])
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

	result := ds.rec(0, n, 0, k, arrs, sums, dps)
	fmt.Fprintln(out, result)
}

func (ds *DSum) rec(l, r, dpi, k int, arrs [][]int64, sums []int64, dps [][]int64) int64 {
	var ans int64
	carr := arrs[l]
	dp := dps[dpi]

	if l+1 == r {
		ans = max(ans, dp[k])
		sum := int64(0)
		for i := 0; i < int(math.Min(float64(k), float64(len(carr)))); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		ds.doCopy(dpi, dps)
		for i := l; i < m; i++ {
			ds.addToKnap(i, dpi+1, sums, arrs, dp, k)
		}
		ans = max(ans, ds.rec(m, r, dpi+1, k, arrs, sums, dps))
		ds.doCopy(dpi, dps)
		for i := m; i < r; i++ {
			ds.addToKnap(i, dpi+1, sums, arrs, dp, k)
		}
		ans = max(ans, ds.rec(l, m, dpi+1, k, arrs, sums, dps))
	}
	return ans
}

func (ds *DSum) doCopy(dpi int, dps [][]int64) {
	copy(dps[dpi+1], dps[dpi])
}

func (ds *DSum) addToKnap(i, dpi int, sums []int64, arrs [][]int64, dp []int64, k int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dp[j] = max(dp[j], dp[j-k1]+v)
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

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	ds := DSum{}
	ds.solve(reader, writer)
}