package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func sum(arr []int) int {
	res := 0
	for _, num := range arr {
		res += num
	}
	return res
}

func rec(l, r, dpi int, dps [][]int, sums []int, arrs [][]int, k int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[dpi]
	if l+1 == r {
		ans = max(ans, dp[k])
		sum := 0
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		doCopy(dpi, dps)
		for i := l; i < m; i++ {
			addToKnap(i, dpi+1, dps, sums, arrs, k)
		}
		ans = max(ans, rec(m, r, dpi+1, dps, sums, arrs, k))
		doCopy(dpi, dps)
		for i := m; i < r; i++ {
			addToKnap(i, dpi+1, dps, sums, arrs, k)
		}
		ans = max(ans, rec(l, m, dpi+1, dps, sums, arrs, k))
	}
	return ans
}

func doCopy(dpi int, dps [][]int) {
	copy(dps[dpi+1], dps[dpi])
}

func addToKnap(i, dpi int, dps [][]int, sums []int, arrs [][]int, k int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func solve(r io.Reader, w io.Writer) {
	var n, k int
	fmt.Fscan(r, &n, &k)
	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(r, &t)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(r, &arrs[i][j])
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}
	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}
	fmt.Fprintln(w, rec(0, n, 0, dps, sums, arrs, k))
}

func main() {
	solve(os.Stdin, os.Stdout)
}
