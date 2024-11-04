package main

import (
	"fmt"
)

var n, m int
var a [55]int
var b [55]int
var dp [55][55][55]int
const Mod = 998244353
var nii [5555]int

func id0(a, b int) int {
	if b == 0 {
		return 1
	}
	x := id0(a, b>>1)
	x = (1LL * x * x) % Mod
	if b&1 == 1 {
		x = (1LL * x * a) % Mod
	}
	return x
}

func main() {
	fmt.Scan(&n, &m)
	for i := 1; i < 5555; i++ {
		nii[i] = id0(i, Mod-2)
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 1; i <= n; i++ {
		fmt.Scan(&b[i])
	}
	for i := 1; i <= n; i++ {
		for j := 0; j < 55; j++ {
			for k := 0; k < 55; k++ {
				dp[i][j][k] = 0
			}
		}
		proba := 0
		probb := 0
		for j := 1; j <= n; j++ {
			if a[j] == 0 {
				probb += b[j]
			} else {
				proba += b[j]
			}
		}
		dp[0][0][0]++
		for j := 0; j < m; j++ {
			for l := 0; l <= j; l++ {
				m := j - l
				for n := 0; n < 55; n++ {
					if a[i] == 1 {
						dp[j+1][l+1][n+1] += (1LL * dp[j][l][n] * (n + b[i]) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l+1][n+1] >= Mod {
							dp[j+1][l+1][n+1] -= Mod
						}
					} else {
						dp[j+1][l][n+1] += (1LL * dp[j][l][n] * (b[i] - n) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l][n+1] >= Mod {
							dp[j+1][l][n+1] -= Mod
						}
					}
					if a[i] == 1 {
						dp[j+1][l+1][n] += (1LL * dp[j][l][n] * (proba + l - n - b[i]) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l+1][n] >= Mod {
							dp[j+1][l+1][n] -= Mod
						}
						dp[j+1][l][n] += (1LL * dp[j][l][n] * (probb - m) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l][n] >= Mod {
							dp[j+1][l][n] -= Mod
						}
					} else {
						dp[j+1][l+1][n] += (1LL * dp[j][l][n] * (proba + l) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l+1][n] >= Mod {
							dp[j+1][l+1][n] -= Mod
						}
						dp[j+1][l][n] += (1LL * dp[j][l][n] * (probb - m - b[i] + n) % Mod * nii[proba+probb+l-m]) % Mod
						if dp[j+1][l][n] >= Mod {
							dp[j+1][l][n] -= Mod
						}
					}
				}
			}
		}
		all := 0
		for j := 0; j < 52; j++ {
			for k := 0; k < 52; k++ {
				all += (1LL * dp[m][j][k] * (a[i]*b[i] + k)) % Mod
				if all >= Mod {
					all -= Mod
				}
			}
		}
		fmt.Println(all)
	}
}
