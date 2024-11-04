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
	s := 0
	for _, num := range arr {
		s += num
	}
	return s
}

func rec(l, r, k int, dps [][]int, sums []int, arrs [][]int) int {
	if l+1 == r {
		ans := dps[k][k]
		sum := 0
		for i := 0; i < min(k, len(arrs[l])); i++ {
			sum += arrs[l][i]
			ans = max(ans, dps[k-i-1][k]+sum)
		}
		return ans
	} else {
		m := (l + r) / 2
		dpi := make([][]int, len(dps))
		for i := 0; i < len(dps); i++ {
			dpi[i] = make([]int, len(dps[i]))
			copy(dpi[i], dps[i])
		}
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dpi[k][j] = max(dpi[k][j], dpi[k][j-k1]+v)
			}
		}
		ans := rec(m, r, k, dpi, sums, arrs)
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dpi[k][j] = max(dpi[k][j], dpi[k][j-k1]+v)
			}
		}
		ans = max(ans, rec(l, m, k, dpi, sums, arrs))
		return ans
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

	// Initialize dp array
	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	// Solve the problem using recursion
	result := rec(0, n, k, dps, sums, arrs)

	// Write output
	fmt.Fprintln(writer, result)
}

func main() {
	DSum(os.Stdin, os.Stdout)
}
