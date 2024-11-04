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

func rec(l, r, k int, dps [][]int64, sums []int64, arrs [][]int64) int64 {
	var ans int64
	carr := arrs[l]
	dp := dps[k]
	if l+1 == r {
		ans = max(ans, dp[k])
		var sum int64
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		doCopy(dps, k, k+1)
		for i := l; i < m; i++ {
			addToKnap(i, dps, k+1)
		}
		ans = max(ans, rec(m, r, k, dps, sums, arrs))
		doCopy(dps, k, k+1)
		for i := m; i < r; i++ {
			addToKnap(i, dps, k+1)
		}
		ans = max(ans, rec(l, m, k, dps, sums, arrs))
	}
	return ans
}

func doCopy(dps [][]int64, from, to int) {
	copy(dps[to], dps[from])
}

func addToKnap(i int, dps [][]int64, dpi int) {
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

	dps := make([][]int64, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int64, k+1)
	}

	// Solve the problem
	ans := rec(0, n, k, dps, sums, arrs)

	// Write output
	fmt.Fprintln(writer, ans)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
