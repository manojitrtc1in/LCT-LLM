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
	dp := make([][]int64, n+1)
	for i := range dp {
		dp[i] = make([]int64, k+1)
	}

	for i := 0; i < n; i++ {
		carr := arrs[i]
		v := sums[i]
		k1 := len(carr)
		for j := k; j >= k1; j-- {
			dp[i+1][j] = max(dp[i+1][j], dp[i][j-k1]+v)
		}
	}

	ans := int64(0)
	for i := 0; i < n; i++ {
		carr := arrs[i]
		v := sums[i]
		k1 := len(carr)
		sum := int64(0)
		for j := 0; j < min(k, len(carr)); j++ {
			sum += carr[j]
			ans = max(ans, dp[i][k-j-1]+sum)
		}
	}

	return ans
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

	ans := knapsack(arrs, sums, k)
	fmt.Fprintln(w, ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
