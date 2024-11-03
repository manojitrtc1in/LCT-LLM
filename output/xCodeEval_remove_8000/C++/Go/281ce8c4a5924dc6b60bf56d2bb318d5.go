package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
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

func solve(scanner *bufio.Scanner, writer *bufio.Writer) {
	scanner.Split(bufio.ScanWords)

	n := readInt(scanner)
	k := readInt(scanner)

	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(scanner)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = readInt(scanner)
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
	}

	sums := make([]int, n)
	for i := 0; i < n; i++ {
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	doCopy := func(dpi int) {
		copy(dps[dpi+1], dps[dpi])
	}

	id14 := func(i, dpi int) {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
		}
	}

	var rec func(l, r, dpi int) int
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
				doCopy(dpi)
				for i := l1; i < r1-1; i++ {
					id14(i, dpi+1)
				}
				return rec(l2, r2, dpi+1)
			}
			m := (l + r) / 2
			ans = max(ans, doSplit(l, m, m, r))
			ans = max(ans, doSplit(m, r, l, m))
		}
		return ans
	}

	fmt.Fprintln(writer, rec(0, n, 0))
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	solve(scanner, writer)
}
