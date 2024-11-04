package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	sz1 := len(s)
	sz2 := len(t)
	dp := make([][]int, sz1+1)
	for i := range dp {
		dp[i] = make([]int, sz2+1)
	}
	for i := 0; i < sz1; i++ {
		for j := 0; j < sz2; j++ {
			if s[i] == t[j] {
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j] + 1) % 1000000007
			} else {
				dp[i+1][j+1] = dp[i+1][j]
			}
		}
	}
	re := 0
	for i := 0; i < sz1; i++ {
		re = (re + dp[i+1][sz2]) % 1000000007
	}
	fmt.Println(re)
}
