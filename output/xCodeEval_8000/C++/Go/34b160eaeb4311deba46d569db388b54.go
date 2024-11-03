package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	k := nextInt(scanner)

	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		t := nextInt(scanner)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = nextInt64(scanner)
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int64, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int64, k+1)
	}

	var rec func(l, r, dpi int) int64
	rec = func(l, r, dpi int) int64 {
		ans := int64(0)
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			ans = max(ans, dp[k])
			sum := int64(0)
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

	fmt.Println(rec(0, n, 0))
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextInt64(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func sum(arr []int64) int64 {
	var s int64
	for _, num := range arr {
		s += num
	}
	return s
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
