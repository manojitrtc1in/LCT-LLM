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

	n, _ := strconv.Atoi(scan(scanner))
	k, _ := strconv.Atoi(scan(scanner))

	sums := make([]int, n)
	arrs := make([][]int, n)

	for i := 0; i < n; i++ {
		t, _ := strconv.Atoi(scan(scanner))
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			arrs[i][j], _ = strconv.Atoi(scan(scanner))
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int, 13)
	for i := range dps {
		dps[i] = make([]int, k+1)
	}

	var rec func(int, int, int) int
	rec = func(l, r, dpi int) int {
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
			doSplit := func(l1, r1, l2, r2 int) int {
				copy(dps[dpi+1], dps[dpi])
				for i := l1; i < r1-1; i++ {
					addToKnap(i, dpi+1)
				}
				return rec(l2, r2, dpi+1)
			}

			m := (l + r) / 2
			ans = max(ans, doSplit(l, m, m, r))
			ans = max(ans, doSplit(m, r, l, m))
		}

		return ans
	}

	addToKnap := func(i, dpi int) {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dp := dps[dpi]
			dp[j] = max(dp[j], dp[j-k1]+v)
		}
	}

	fmt.Println(rec(0, n, 0))
}

func scan(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}

func sum(arr []int) int {
	sum := 0
	for _, num := range arr {
		sum += num
	}
	return sum
}

func max(a, b int) int {
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
