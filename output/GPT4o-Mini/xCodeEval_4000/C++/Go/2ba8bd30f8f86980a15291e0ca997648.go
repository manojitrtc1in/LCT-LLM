package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
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

	fmt.Fprintln(out, rec(arrs, sums, 0, n, 0, k, dps))
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

func addToKnap(i, dpi int, arrs [][]int64, sums []int64, k int, dps [][]int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func rec(arrs [][]int64, sums []int64, l, r, dpi, k int, dps [][]int64) int64 {
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
			addToKnap(i, dpi, arrs, sums, k, dps)
		}
		ans = max(ans, rec(arrs, sums, m, r, dpi+1, k, dps))
		doCopy(dpi, dps, k)
		for i := m; i < r; i++ {
			addToKnap(i, dpi, arrs, sums, k, dps)
		}
		ans = max(ans, rec(arrs, sums, l, m, dpi+1, k, dps))
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	ds := DSum{}
	ds.solve(reader, writer)
}