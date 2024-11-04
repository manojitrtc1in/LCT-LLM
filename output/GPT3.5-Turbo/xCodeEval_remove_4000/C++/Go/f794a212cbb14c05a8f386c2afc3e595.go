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

func rec(l, r, dpi int, dps [][]int, sums []int, arrs [][]int, k int) int {
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
		doCopy(dpi, dps)
		for i := l; i < m-1; i++ {
			addToKnap(i, dpi+1, dps, arrs, k)
		}
		ans = max(ans, rec(m, r, dpi+1, dps, sums, arrs, k))
		doCopy(dpi, dps)
		for i := m; i < r-1; i++ {
			addToKnap(i, dpi+1, dps, arrs, k)
		}
		ans = max(ans, rec(l, m, dpi+1, dps, sums, arrs, k))
	}
	return ans
}

func doCopy(dpi int, dps [][]int) {
	copy(dps[dpi+1], dps[dpi])
}

func addToKnap(i, dpi int, dps [][]int, arrs [][]int, k int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func DSum(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Read input
	var n, k int
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ = strconv.Atoi(scanner.Text())

	sums := make([]int, n)
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
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	// Solve
	ans := rec(0, n, 0, dps, sums, arrs, k)

	// Write output
	fmt.Fprintln(writer, ans)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
