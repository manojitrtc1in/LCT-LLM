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
	total := 0
	for _, num := range arr {
		total += num
	}
	return total
}

func knapsack(arrs [][]int, sums []int, k int) int {
	n := len(arrs)
	dps := make([][]int, 13)
	for i := range dps {
		dps[i] = make([]int, k+1)
	}

	var rec func(l, r, dpi int) int
	rec = func(l, r, dpi int) int {
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
			copy(dps[dpi+1], dps[dpi])
			for i := l; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dps[dpi+1][j] = max(dps[dpi+1][j], dps[dpi][j-k1]+v)
				}
			}
			ans = max(ans, rec(m, r, dpi+1))
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dps[dpi+1][j] = max(dps[dpi+1][j], dps[dpi][j-k1]+v)
				}
			}
			ans = max(ans, rec(l, m, dpi+1))
		}
		return ans
	}

	return rec(0, n, 0)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(r io.Reader, w io.Writer) {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)

	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			scanner.Scan()
			arrs[i][j], _ = strconv.Atoi(scanner.Text())
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	sort.Slice(arrs, func(i, j int) bool {
		return sums[i] > sums[j]
	})

	fmt.Fprintln(w, knapsack(arrs, sums, k))
}

func main() {
	solve(os.Stdin, os.Stdout)
}
