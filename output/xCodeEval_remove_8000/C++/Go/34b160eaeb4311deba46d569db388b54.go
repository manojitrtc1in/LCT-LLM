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

func rec(l, r, k int, arrs [][]int, sums []int, dps [][]int) int {
	ans := 0
	carr := arrs[l]
	dp := dps[k]
	if l+1 == r {
		ans = max(ans, dp[k])
		sum := 0
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		dpi := make([]int, k+1)
		copy(dpi, dp)
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dpi[j] = max(dpi[j], dpi[j-k1]+v)
			}
		}
		ans = max(ans, rec(m, r, k, arrs, sums, dpi))
		copy(dpi, dp)
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dpi[j] = max(dpi[j], dpi[j-k1]+v)
			}
		}
		ans = max(ans, rec(l, m, k, arrs, sums, dpi))
	}
	return ans
}

func DSum(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Read input
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())
	arrs := make([][]int, n)
	sums := make([]int, n)
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
		sums[i] = sum(arrs[i])
	}

	// Initialize dp array
	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	// Solve the problem
	ans := rec(0, n, k, arrs, sums, dps)

	// Write output
	fmt.Fprintln(writer, ans)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
