package main

import (
	"fmt"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)
	dp := make([][]int, len(s)+1)
	for i := range dp {
		dp[i] = make([]int, len(t)+1)
	}
	for i := 0; i < len(s); i++ {
		for j := 0; j < len(t); j++ {
			if s[i] == t[j] {
				dp[i+1][j+1] = (dp[i+1][j] + dp[i][j] + 1) % 1000000007
			} else {
				dp[i+1][j+1] = dp[i+1][j]
			}
		}
	}
	re := 0
	for i := 0; i < len(s); i++ {
		re = (re + dp[i+1][len(t)]) % 1000000007
	}
	fmt.Println(re)
}
