package main

import (
	"bytes"
	"fmt"
	"os"
)

const MOD = 1000000007

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	DP := make([]int, n+5)
	CUM := make([]int, n+5)
	CUM[1] = 0
	DP[1] = 1

	S := 1

	for i := 2; i <= n; i++ {
		CUM[i] = (CUM[i-1] + CUM[i]) % m
		DP[i] = (S + CUM[i]) % m
		S = (S + DP[i]) % m

		for j := i + i; j <= n; j += i {
			CUM[j] = (CUM[j] + DP[i] - DP[i-1]) % m
		}
	}

	fmt.Println(DP[n])
}
