package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func readInt(r *bufio.Reader) int {
	str, _ := r.ReadString('\n')
	num, _ := strconv.Atoi(str[:len(str)-1])
	return num
}

func readInts(r *bufio.Reader, n int) []int {
	str, _ := r.ReadString('\n')
	str = str[:len(str)-1]
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		strs[i] = str[:len(str)/n]
		str = str[len(str)/n:]
	}
	nums := make([]int, n)
	for i, s := range strs {
		nums[i], _ = strconv.Atoi(s)
	}
	return nums
}

func sum(arr []int) int {
	s := 0
	for _, num := range arr {
		s += num
	}
	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve(n, k int, sums []int, arrs [][]int) int {
	dps := make([][]int, 13)
	for i := range dps {
		dps[i] = make([]int, k+1)
	}
	for i := 0; i < n; i++ {
		carr := arrs[i]
		dp := dps[0]
		if i == 0 {
			for j := 0; j <= k; j++ {
				if j < len(carr) {
					dp[j] = sums[i]
				}
			}
		} else {
			for j := k; j >= 0; j-- {
				dp[j] = dp[j]
				if j >= len(carr) {
					dp[j] = max(dp[j], dp[j-len(carr)]+sums[i])
				}
			}
		}
	}
	return dps[0][k]
}

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	n, k := readInt(r), readInt(r)
	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(r)
		arrs[i] = readInts(r, t)
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	ans := solve(n, k, sums, arrs)
	fmt.Fprintln(w, ans)
}
