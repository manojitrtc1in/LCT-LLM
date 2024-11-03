package main

import (
	"fmt"
)

const MAX = 1200001

var dp [MAX]int
var pi [MAX]int

func sieve() {
	for i := 2; i < MAX; i++ {
		dp[i] = 1
	}
	for i := 2; i < MAX; i++ {
		if dp[i] != 0 {
			for j := 2 * i; j < MAX; j += i {
				dp[j] = 0
			}
		}
	}
	pi[1] = 0
	for i := 2; i <= MAX; i++ {
		if dp[i] != 0 {
			pi[i] = pi[i-1] + 1
		} else {
			pi[i] = pi[i-1]
		}
	}
}

