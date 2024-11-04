package main

import (
	"fmt"
	"math"
)

const MOD = 1e9 + 7

var dp [61][8]int64
var n int64

func solve() {
	fmt.Scan(&n)

	for i := range dp {
		for j := range dp[i] {
			dp[i][j] = 0
		}
	}

	dp[0][0] = 1
	for i := 0; i < 60; i++ {
		bit := (n >> i) & 1

		for j := 0; j < (1 << 3); j++ {
			if dp[i][j] == 0 {
				continue
			}

			for k := (j%2) ^ bit; k < 8; k += 2 {
				lol := j + k

				dp[i+1][lol/2] += dp[i][j]
				if dp[i+1][lol/2] >= MOD {
					dp[i+1][lol/2] -= MOD
				}
			}
		}
	}

	fmt.Println(dp[60][0])
}

func main() {
	var tests int
	fmt.Scan(&tests)

	for tests > 0 {
		solve()
		tests--
	}
}
