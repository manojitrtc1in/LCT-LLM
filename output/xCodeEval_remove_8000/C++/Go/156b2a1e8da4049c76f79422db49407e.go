package main

import (
	"fmt"
	"math"
)

const (
	eps = 1e-9
)

func solve(id int, p []float64, n, k int) {
	if p[id] <= eps {
		fmt.Print("0 ")
		return
	}

	subret := make([]float64, k+1)
	dp := make([]float64, 1<<n)
	dp[0] = p[id]
	subret[0] = dp[0]
	for i := 1; i < (1 << n); i++ {
		dp[i] = 0
		if i&(1<<id) != 0 {
			continue
		}
		sum := 0.0
		for j := 0; j < n; j++ {
			if i&(1<<j) != 0 {
				sum += p[j]
				dp[i] += dp[i^(1<<j)] * p[j]
			}
		}
		dp[i] /= 1 - sum
		subret[bits(i)] += dp[i]
	}

	ret := 0.0
	for i := 0; i < k; i++ {
		ret += subret[i]
	}

	fmt.Printf("%.10f ", ret)
}

func bits(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	p := make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}

	for i := 0; i < n; i++ {
		solve(i, p, n, k)
	}
	fmt.Println()
}
