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
	for i, v := range line {
		arr[i], _ = strconv.Atoi(string(v))
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
		doSplit := func(l1, r1, l2, r2 int) int {
			for i := l1; i < r1-1; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					dp[j] = max(dp[j], dp[j-k1]+v)
				}
			}
			return rec(l2, r2, k, arrs, sums, dps)
		}
		m := (l + r) / 2
		ans = max(ans, doSplit(l, m, m, r))
		ans = max(ans, doSplit(m, r, l, m))
	}
	return ans
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func DSum(scanner *bufio.Scanner) {
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

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	DSum(scanner)
}
