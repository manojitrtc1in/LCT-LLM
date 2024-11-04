package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, k int
	fmt.Fscan(reader, &n, &k)

	sums := make([]int, n)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		var t int
		fmt.Fscan(reader, &t)
		arrs[i] = make([]int, t)
		for j := 0; j < t; j++ {
			fmt.Fscan(reader, &arrs[i][j])
		}
		sort.Ints(arrs[i])
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		for _, num := range arrs[i] {
			sums[i] += num
		}
	}

	dps := make([][]int, 13)
	for i := 0; i < 13; i++ {
		dps[i] = make([]int, k+1)
	}

	var rec func(l, r, dpi int) int
	rec = func(l, r, dpi int) int {
		ans := 0
		carr := arrs[l]
		dp := dps[dpi]
		if l+1 == r {
			if k < len(carr) {
				ans = dp[k]
				sum := 0
				for i := 0; i < k; i++ {
					sum += carr[i]
					if dp[k-i-1]+sum > ans {
						ans = dp[k-i-1] + sum
					}
				}
			} else {
				ans = dp[k]
			}
		} else {
			m := (l + r) / 2
			copy(dps[dpi+1], dps[dpi])
			for i := l; i < m; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					if dp[j-k1]+v > dp[j] {
						dp[j] = dp[j-k1] + v
					}
				}
			}
			if res := rec(m, r, dpi+1); res > ans {
				ans = res
			}
			copy(dps[dpi+1], dps[dpi])
			for i := m; i < r; i++ {
				v := sums[i]
				k1 := len(arrs[i])
				for j := k; j >= k1; j-- {
					if dp[j-k1]+v > dp[j] {
						dp[j] = dp[j-k1] + v
					}
				}
			}
			if res := rec(l, m, dpi+1); res > ans {
				ans = res
			}
		}
		return ans
	}

	fmt.Fprintln(writer, rec(0, n, 0))
}
