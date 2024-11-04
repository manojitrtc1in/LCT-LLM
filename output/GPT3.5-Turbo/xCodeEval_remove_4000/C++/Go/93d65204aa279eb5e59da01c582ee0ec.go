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

func readInts(scanner *bufio.Scanner, n int) []int {
	scanner.Scan()
	line := scanner.Text()
	nums := make([]int, n)
	for i, str := range line[:len(line)-1] {
		nums[i], _ = strconv.Atoi(string(str))
	}
	return nums
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
		dpi := make([]int, k+1)
		copy(dpi, dp)
		for i := l; i < m-1; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dp[j] = max(dp[j], dp[j-k1]+v)
			}
		}
		ans = max(ans, rec(m, r, k, dps, sums, arrs))
		copy(dp, dpi)
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

func DSum(scanner *bufio.Scanner) {
	n := readInt(scanner)
	k := readInt(scanner)
	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(scanner)
		arrs[i] = readInts(scanner, t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}
	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}
	fmt.Println(rec(0, n, k, dps, sums, arrs))
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	DSum(scanner)
}
