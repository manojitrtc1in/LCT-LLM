package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

const mod = 998244353

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, 26)
	for i := 0; i < 26; i++ {
		fmt.Scan(&a[i])
	}
	all := (26 * 26 * pow(25, int64(n-2), mod)) % mod

	dp := make([][][]int64, 3)
	for i := range dp {
		dp[i] = make([][]int64, n+1)
		for j := range dp[i] {
			dp[i][j] = make([]int64, n+1)
		}
	}
	dp[0][1][0] = 1
	dp[1][0][1] = 1
	dp[2][0][0] = 1

	for i := 0; i < n-1; i++ {
		ndp := make([][][]int64, 3)
		for j := range ndp {
			ndp[j] = make([][]int64, n+1)
			for k := range ndp[j] {
				ndp[j][k] = make([]int64, n+1)
			}
		}
		if i == (n+1)/2-1 {
			for j := 0; j <= n; j++ {
				for k := 0; j+k <= n; k++ {
					if j+1 <= n {
						ndp[0][j+1][k] = (ndp[0][j+1][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24) % mod
					}
					if k+1 <= n {
						ndp[1][j][k+1] = (ndp[1][j][k+1] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24) % mod
					}
					ndp[2][j][k] = (ndp[2][j][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*24) % mod
				}
			}
		} else {
			for j := 0; j <= n; j++ {
				for k := 0; j+k <= n; k++ {
					if j+1 <= n {
						ndp[0][j+1][k] = (ndp[0][j+1][k] + dp[1][j][k] + dp[2][j][k]*24) % mod
					}
					if k+1 <= n {
						ndp[1][j][k+1] = (ndp[1][j][k+1] + dp[0][j][k] + dp[2][j][k]*24) % mod
					}
					ndp[2][j][k] = (ndp[2][j][k] + dp[0][j][k] + dp[1][j][k] + dp[2][j][k]*23) % mod
				}
			}
		}
		dp = ndp
	}

	sdp := make([]int64, n+1)
	for i := 0; i <= n; i++ {
		for j := 0; j <= n; j++ {
			sdp[i] = (sdp[i] + dp[0][i][j] + dp[1][i][j] + dp[2][i][j]*24) % mod
		}
	}

	for i := 0; i < 26; i++ {
		for k := a[i] + 1; k <= n; k++ {
			all = (all - sdp[k] + mod) % mod
		}
	}

	for i := 0; i < 26; i++ {
		for j := i + 1; j < 26; j++ {
			for k := a[i] + 1; k <= n; k++ {
				for l := a[j] + 1; l+k <= n; l++ {
					all = (all + dp[0][k][l] + dp[1][k][l] + dp[2][k][l]*24) % mod
				}
			}
		}
	}
	all = (all + mod) % mod

	fmt.Println(all)
}

func pow(a, n, mod int64) int64 {
	ret := int64(1)
	for n > 0 {
		if n%2 == 1 {
			ret = (ret * a) % mod
		}
		a = (a * a) % mod
		n /= 2
	}
	return ret
}
