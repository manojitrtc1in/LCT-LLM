package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readIntArray(scanner *bufio.Scanner, n int) []int {
	scanner.Scan()
	line := scanner.Text()
	arr := make([]int, n)
	for i, s := range line[:len(line)-1] {
		arr[i], _ = strconv.Atoi(string(s))
	}
	return arr
}

func sum(arr []int) int {
	total := 0
	for _, num := range arr {
		total += num
	}
	return total
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
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
		dps[dpi+1] = make([]int, k+1)
		copy(dps[dpi+1], dps[dpi])
		for i := l; i < m-1; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(m, r, dpi+1))
		dps[dpi+1] = make([]int, k+1)
		copy(dps[dpi+1], dps[dpi])
		for i := m; i < r-1; i++ {
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := readInt(scanner)
	k := readInt(scanner)

	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(scanner)
		arrs[i] = readIntArray(scanner, t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	fmt.Println(rec(0, n, 0, arrs, sums, dps))
}
