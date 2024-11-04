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
	dps := make([][]int, n+1)
	for i := range dps {
		dps[i] = make([]int, k+1)
	}

	sums := make([]int, n)
	for i := 0; i < n; i++ {
		sums[i] = sum(arrs[i])
	}

	for l := 0; l < n; l++ {
		carr := arrs[l]
		dp := dps[l]
		if l+1 == n {
			for i := 0; i <= k; i++ {
				dps[l+1][i] = dp[i]
			}
			sum := 0
			for i := 0; i < min(k, len(carr)); i++ {
				sum += carr[i]
				dps[l+1][k-i-1] = max(dps[l+1][k-i-1], dp[k-i-1]+sum)
			}
		} else {
			m := (l + n) / 2
			for i := 0; i <= k; i++ {
				dps[l+1][i] = dp[i]
			}
			for i := l + 1; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dps[l+1][j] = max(dps[l+1][j], dp[j-k1]+v)
				}
			}
			knap := make([]int, k+1)
			for i := m; i < n; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := 0; j <= k; j++ {
					knap[j] = max(knap[j], dp[j])
				}
				for j := k; j >= k1; j-- {
					knap[j] = max(knap[j], knap[j-k1]+v)
				}
			}
			for i := 0; i <= k; i++ {
				dps[l+1][i] = max(dps[l+1][i], knap[i])
			}
		}
	}

	return dps[n][k]
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
	}

	sort.Slice(arrs, func(i, j int) bool {
		return sum(arrs[i]) > sum(arrs[j])
	})

	ans := knapsack(arrs, k)
	fmt.Fprintln(w, ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
