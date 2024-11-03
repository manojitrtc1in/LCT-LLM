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
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, k+1)
	}

	for i := 0; i < n; i++ {
		carr := arrs[i]
		for j := k; j >= 0; j-- {
			if j == k {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j])
			} else {
				dp[i+1][j] = max(dp[i+1][j], dp[i][j])
				if len(carr) <= j {
					dp[i+1][j] = max(dp[i+1][j], dp[i][j-len(carr)]+sums[i])
				}
			}
		}
	}

	return dp[n][k]
}

func solve(r io.Reader, w io.Writer) {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)

	var n, k int
	fmt.Fscan(scanner, &n, &k)

	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(scanner, &t)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(scanner, &arrs[i][j])
		}
		sort.Ints(arrs[i])
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	ans := knapsack(arrs, sums, k)
	fmt.Fprintln(w, ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
