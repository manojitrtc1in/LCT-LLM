package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"time"
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

	fmt.Fprintln(out, rec(arrs, sums, dps, 0, n, 0, k))
}

func sum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += v
	}
	return total
}

func doCopy(dps [][]int64, dpi int) {
	copy(dps[dpi+1], dps[dpi])
}

func addToKnap(arrs [][]int64, sums []int64, dps [][]int64, i, dpi, k int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func rec(arrs [][]int64, sums []int64, dps [][]int64, l, r, dpi, k int) int64 {
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
		doCopy(dps, dpi)
		for i := l; i < m; i++ {
			addToKnap(arrs, sums, dps, i, dpi+1, k)
		}
		ans = max(ans, rec(arrs, sums, dps, m, r, dpi+1, k))
		doCopy(dps, dpi)
		for i := m; i < r; i++ {
			addToKnap(arrs, sums, dps, i, dpi+1, k)
		}
		ans = max(ans, rec(arrs, sums, dps, l, m, dpi+1, k))
	}
	return ans
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
	rand.Seed(time.Now().UnixNano())
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := DSum{}
	solver.solve(in, out)
}
