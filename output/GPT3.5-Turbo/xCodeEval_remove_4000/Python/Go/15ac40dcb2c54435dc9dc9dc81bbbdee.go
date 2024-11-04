package main

import (
	"fmt"
)

func main() {
	var n, mod int
	fmt.Scan(&n, &mod)

	M := int(math.Sqrt(float64(n))) + 10

	dp := make([]int, n+1)
	imos := make([]int, n+1)
	dp[1] = 1
	for i := 1; i < n; i++ {
		imos[i] = (imos[i] + imos[i-1]) % mod
		dp[i] += imos[i]
		dp[i] %= mod

		imos[i+1] += dp[i]
		imos[i+1] %= mod

		for j := 2; j <= n; j++ {
			if i*j > n {
				break
			}

			imos[i*j] += dp[i]
			imos[i*j] %= mod
			if (i+1)*j <= n {
				imos[(i+1)*j] -= dp[i]
				imos[(i+1)*j] %= mod
			}
		}
	}

	res := dp[n] + imos[n] + imos[n-1]
	res %= mod
	fmt.Println(res)
}
