package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func sum(arr []int64) int64 {
	var total int64
	for _, num := range arr {
		total += num
	}
	return total
}

func knapsack(arrs [][]int64, sums []int64, k int) int64 {
	n := len(arrs)
	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}

	var rec func(l, r, dpi int) int64
	rec = func(l, r, dpi int) int64 {
		ans := int64(0)
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

func solve(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			scanner.Scan()
			arrs[i][j], _ = strconv.ParseInt(scanner.Text(), 10, 64)
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	sort.Slice(arrs, func(i, j int) bool {
		return sums[i] > sums[j]
	})

	result := knapsack(arrs, sums, k)
	fmt.Fprintln(writer, result)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
