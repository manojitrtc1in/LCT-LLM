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
	s := 0
	for _, num := range arr {
		s += num
	}
	return s
}

func knapsack(arrs [][]int, sums []int, k int) int {
	n := len(arrs)
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, k+1)
	}

	for l := 0; l < n; l++ {
		carr := arrs[l]
		for i := 0; i <= k; i++ {
			dp[l+1][i] = dp[l][i]
		}
		for i := 0; i < len(carr); i++ {
			v := sums[l]
			if i+1 > k {
				break
			}
			dp[l+1][k-i-1] = max(dp[l+1][k-i-1], dp[l][k-i-1]+v)
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
