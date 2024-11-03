package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	inf  = 1e9 + 7
	eps  = 1e-9
	mod  = 1e9 + 7
	mod2 = 1e9 + 6
)

func solve(id int, p []float64, n int, k int) {
	if p[id] <= eps {
		fmt.Print("0 ")
		return
	}
	subret := make([]float64, 22)
	subret[0] = p[id]
	dp := make([]float64, 1<<20)
	dp[0] = p[id]
	for i := 1; i < (1 << n); i++ {
		dp[i] = 0
		if i&(1<<id) > 0 {
			continue
		}
		sum := 0.0
		for j := 0; j < n; j++ {
			if i&(1<<j) > 0 {
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
	cnt := 0
	for x > 0 {
		cnt++
		x &= x - 1
	}
	return cnt
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(scan(scanner))
	k, _ := strconv.Atoi(scan(scanner))
	p := make([]float64, n)
	for i := 0; i < n; i++ {
		p[i], _ = strconv.ParseFloat(scan(scanner), 64)
	}

	for i := 0; i < n; i++ {
		solve(i, p, n, k)
	}
	fmt.Println()
}

func scan(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}
