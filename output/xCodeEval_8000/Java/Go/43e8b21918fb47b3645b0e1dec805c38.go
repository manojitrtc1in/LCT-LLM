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

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func nextInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func nextLong() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func nextDouble() float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func main() {
	initIO()
	defer flush()

	const gigamod = 1000000007

	t := 1
	epsilon := 0.00000001

	for tc := 0; tc < t; tc++ {
		n := nextInt()
		mod := nextLong()

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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
