package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func readInt(r *bufio.Reader) int {
	str, _ := r.ReadString('\n')
	num, _ := strconv.Atoi(str[:len(str)-1])
	return num
}

func readInts(r *bufio.Reader) []int {
	str, _ := r.ReadString('\n')
	str = str[:len(str)-1]
	strs := []string{""}
	j := 0
	for i := 0; i < len(str); i++ {
		if str[i] == ' ' {
			j++
			strs = append(strs, "")
		} else {
			strs[j] += string(str[i])
		}
	}
	nums := make([]int, len(strs))
	for i := 0; i < len(strs); i++ {
		nums[i], _ = strconv.Atoi(strs[i])
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

func solve(r io.Reader, w io.Writer) {
	reader := bufio.NewReader(r)
	writer := bufio.NewWriter(w)

	n, k := readInt(reader), readInt(reader)
	arrs := make([][]int, n)
	for i := 0; i < n; i++ {
		t := readInt(reader)
		arrs[i] = readInts(reader)
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

	addToKnap := func(i, dpi int) {
		v := sums[i]
		k1 := len(arrs[i])
		for j := k; j >= k1; j-- {
			dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
		}
	}

	var rec func(int, int, int) int
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
				for i := l1; i < r1; i++ {
					addToKnap(i, dpi+1)
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
	writer.Flush()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	solve(os.Stdin, os.Stdout)
}
