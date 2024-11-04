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

func knapsack(arrs [][]int, k int) int {
	n := len(arrs)
	sums := make([]int, n)
	for i := 0; i < n; i++ {
		sums[i] = sum(arrs[i])
	}

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
					dp[j] = max(dp[j], dp[j-k1]+v)
				}
			}
			ans = max(ans, rec(m, r, dpi+1))

			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = max(dp[j], dp[j-k1]+v)
				}
			}
			ans = max(ans, rec(l, m, dpi+1))
		}

		return ans
	}

	return rec(0, n, 0)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(reader, &t)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &arrs[i][j])
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
	}

	sort.Slice(arrs, func(i, j int) bool {
		return sum(arrs[i]) > sum(arrs[j])
	})

	ans := knapsack(arrs, k)
	fmt.Fprintln(writer, ans)
}
