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
	var s int64
	for _, num := range arr {
		s += num
	}
	return s
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
		for i := l; i < m-1; i++ {
			addToKnap(i, dps, k+1)
		}
		ans = max(ans, rec(m, r, k, dps, sums, arrs))
		doCopy(dps, k, k+1)
		for i := m; i < r-1; i++ {
			addToKnap(i, dps, k+1)
		}
		ans = max(ans, rec(l, m, k, dps, sums, arrs))
	}
	return ans
}

func doCopy(dps [][]int64, src, dest int) {
	copy(dps[dest], dps[src])
}

func addToKnap(i int, dps [][]int64, k int) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[k][j] = max(dps[k][j], dps[k][j-k1]+v)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	var n, k int
	readInt(scanner, &n)
	readInt(scanner, &k)

	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		readInt(scanner, &t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			readInt(scanner, &arrs[i][j])
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

	fmt.Fprintln(writer, rec(0, n, k, dps, sums, arrs))
}

func readInt(scanner *bufio.Scanner, x *int) {
	scanner.Scan()
	*x, _ = strconv.Atoi(scanner.Text())
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(reader, writer)
}
