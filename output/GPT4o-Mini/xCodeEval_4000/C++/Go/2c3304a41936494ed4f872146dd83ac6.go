package main

import (
	"fmt"
	"strings"
)

const M = 1000000007

func main() {
	var s, t string
	fmt.Scanln(&s)
	fmt.Scanln(&t)

	sz1 := len(s)
	sz2 := len(t)
	dp := make([][]int, sz1+1)
	for i := range dp {
		dp[i] = make([]int, sz2+1)
	}

	for i := 0; i < sz1; i++ {
		for j := 0; j < sz2; j++ {
			dp[i+1][j+1] = (dp[i+1][j] + (boolToInt(s[i] == t[j]) * (dp[i][j] + 1) % M)) % M) % M
		}
	}

	re := 0
	for i := 0; i < sz1; i++ {
		re = (re + dp[i+1][sz2]) % M
	}
	fmt.Println(re)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}