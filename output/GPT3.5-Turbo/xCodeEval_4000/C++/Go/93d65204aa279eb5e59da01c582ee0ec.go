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

func knapsack(arrs [][]int, k int) int {
	n := len(arrs)
	dps := make([][]int, n+1)
	for i := range dps {
		dps[i] = make([]int, k+1)
	}
	sums := make([]int, n)
	for i, arr := range arrs {
		sums[i] = sum(arr)
	}

	for l := 0; l < n; l++ {
		carr := arrs[l]
		dp := dps[l]
		if l+1 == n {
			for i := k; i >= 0; i-- {
				if i < len(carr) {
					dp[i] = max(dp[i], sums[l])
				}
				for j := 0; j < len(carr) && i-j-1 >= 0; j++ {
					dp[i] = max(dp[i], dp[i-j-1]+sums[l]-sum(carr[:j+1]))
				}
			}
		} else {
			m := (l + n) / 2
			for i := 0; i <= k; i++ {
				dps[l+1][i] = dp[i]
			}
			for i := l + 1; i < m; i++ {
				for j := k; j >= len(arrs[i]); j-- {
					dps[l+1][j] = max(dps[l+1][j], dp[j-len(arrs[i])]+sums[i])
				}
			}
			knapsack(arrs[m:], k, dps[l+1])
			for i := m; i < n; i++ {
				for j := k; j >= len(arrs[i]); j-- {
					dps[l+1][j] = max(dps[l+1][j], dp[j-len(arrs[i])]+sums[i])
				}
			}
		}
	}

	return dps[n][k]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := readInt(scanner)
	k := readInt(scanner)

	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(scanner)
		arrs[i] = readIntArray(scanner, t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
	}

	sort.Slice(arrs, func(i, j int) bool {
		return sum(arrs[i]) > sum(arrs[j])
	})

	fmt.Println(knapsack(arrs, k))
}
