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

func rec(l, r, k int, dps [][]int, sums []int, arrs [][]int) int {
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
		dps[dpi+1] = make([]int, k+1)
		copy(dps[dpi+1], dps[dpi])
		for i := l; i < m-1; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(m, r, k, dps, sums, arrs))
		copy(dps[dpi+1], dps[dpi])
		for i := m; i < r-1; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(l, m, k, dps, sums, arrs))
	}
	return ans
}

func DSum(reader io.Reader, writer io.Writer) {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)

	// Read n and k
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())
	scanner.Scan()
	k, _ := strconv.Atoi(scanner.Text())

	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		// Read t
		scanner.Scan()
		t, _ := strconv.Atoi(scanner.Text())

		// Read arr
		arr := make([]int, t)
		for j := 0; j < t; j++ {
			scanner.Scan()
			arr[j], _ = strconv.Atoi(scanner.Text())
		}

		// Sort arr in descending order
		sort.Sort(sort.Reverse(sort.IntSlice(arr)))

		// Truncate arr to length k
		if t > k {
			arr = arr[:k]
		}

		// Calculate sum of arr
		sums[i] = sum(arr)

		// Store arr
		arrs[i] = arr
	}

	// Initialize DPS array
	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	// Call recursive function to solve the problem
	ans := rec(0, n, k, dps, sums, arrs)

	// Write the answer to the output
	fmt.Fprintln(writer, ans)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
