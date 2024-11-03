package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
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
	if l+1 == r {
		ans := dps[k][k]
		sum := int64(0)
		for i := 0; i < min(k, len(arrs[l])); i++ {
			sum += arrs[l][i]
			ans = max(ans, dps[k][k-i-1]+sum)
		}
		return ans
	} else {
		m := (l + r) / 2
		dps1 := make([][]int64, len(dps))
		for i := range dps {
			dps1[i] = make([]int64, len(dps[i]))
			copy(dps1[i], dps[i])
		}
		for i := l; i < m; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dps1[j] = append(dps1[j], dps1[j-k1]+v)
			}
		}
		ans := rec(m, r, k, dps1, sums, arrs)
		for i := range dps {
			copy(dps[i], dps1[i])
		}
		for i := m; i < r; i++ {
			v := sums[i]
			k1 := len(arrs[i])
			for j := k; j >= k1; j-- {
				dps[j] = append(dps[j], dps[j-k1]+v)
			}
		}
		ans = max(ans, rec(l, m, k, dps, sums, arrs))
		return ans
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(reader io.Reader, writer io.Writer) {
	var n, k int
	fmt.Fscan(reader, &n, &k)
	sums := make([]int64, n)
	arrs := make([][]int64, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(reader, &t)
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &arrs[i][j])
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}
	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}
	fmt.Fprint(writer, rec(0, n, k, dps, sums, arrs))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	solve(reader, writer)
	writer.Flush()
}
