package main

import (
	"fmt"
)

type Matrix [][]int

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(a Matrix, w []int, dp []int, l, r int) {
	if r-l == 1 {
		sum := 0
		for i := 0; i <= len(a[l]); i++ {
			ans = max(ans, dp[k-i]+sum)
			if i != len(a[l]) {
				sum += a[l][i]
			}
		}
		return
	}
	m := (r + l) / 2
	dp2 := make([]int, k+1)
	copy(dp2, dp)
	for i := m; i < r; i++ {
		for j := k - 1; j >= 0; j-- {
			if len(a[i])+j <= k {
				dp2[j+len(a[i])] = max(dp2[j+len(a[i])], dp2[j]+w[i])
			}
		}
	}
	solve(a, w, dp2, l, m)
	for i := l; i < m; i++ {
		for j := k - 1; j >= 0; j-- {
			if len(a[i])+j <= k {
				dp[j+len(a[i])] = max(dp[j+len(a[i])], dp[j]+w[i])
			}
		}
	}
	solve(a, w, dp, m, r)
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	a := make(Matrix, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		for j := 0; j < t; j++ {
			var tmp int
			fmt.Scan(&tmp)
			if len(a[i]) < k {
				a[i] = append(a[i], tmp)
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < len(a[i]); j++ {
			w[i] += a[i][j]
		}
	}
	ans := 0
	dp := make([]int, k+1)
	solve(a, w, dp, 0, n)
	fmt.Println(ans)
}
