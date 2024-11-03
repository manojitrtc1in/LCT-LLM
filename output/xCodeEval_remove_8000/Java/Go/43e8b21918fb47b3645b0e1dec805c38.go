package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	t := 1
	for tc := 0; tc < t; tc++ {
		n := nextInt()
		mod := nextInt64()

		dp := make([]int64, n+1)
		dp[n] = 1

		for i := n - 1; i > 0; i-- {
			dp[i] += dp[i+1]
			dp[i] %= mod

			for div := int64(1); div*i <= int64(n); div++ {
				lb := int(div * i)
				ub := int(min(div*(i+1)-1, int64(n)))
				segSum := dp[lb]
				if ub+1 <= n {
					segSum -= dp[ub+1]
				}
				dp[i] += segSum
				dp[i] %= mod
			}

			dp[i] += dp[i+1]
			dp[i] %= mod
		}

		fmt.Fprintln(writer, (dp[1]-dp[2]+mod)%mod)
	}
}

func next() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	num, _ := strconv.Atoi(next())
	return num
}

func nextInt64() int64 {
	num, _ := strconv.ParseInt(next(), 10, 64)
	return num
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
