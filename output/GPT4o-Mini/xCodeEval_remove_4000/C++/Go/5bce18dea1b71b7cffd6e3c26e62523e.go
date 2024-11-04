package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = 998244353
	EPS     = 1e-9
	PI      = 3.141592653589793
	N       = 50 + 7
	M       = 3000 + 7
)

var (
	n, m int
	a    [N]int
	w    [N]int
	dp   [N][N][2 * N]int
	rev  [M]int
)

func add(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	if a < 0 {
		a += MOD
	}
	return a
}

func mul(a, b int) int {
	return a * b % MOD
}

func binpow(a, b int) int {
	res := 1
	for b > 0 {
		if b&1 == 1 {
			res = mul(res, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return res
}

func inv(x int) int {
	return binpow(x, MOD-2)
}

func read() bool {
	_, err := fmt.Scan(&n, &m)
	if err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	return true
}

func solve() {
	sum := 0
	for _, weight := range w {
		sum += weight
	}
	neg := 0
	for i := 0; i < n; i++ {
		if a[i] == 0 {
			neg += w[i]
		}
	}
	for i := 0; i < M; i++ {
		rev[i] = inv(i)
	}

	for z := 0; z < n; z++ {
		for i := range dp {
			for j := range dp[i] {
				for k := range dp[i][j] {
					dp[i][j][k] = 0
				}
			}
		}
		dp[0][0][w[z]] = 1
		for i := 0; i < m; i++ {
			for pos := 0; pos <= i; pos++ {
				for val := 0; val < 2*N; val++ {
					if dp[i][pos][val] > 0 {
						p := mul(val, rev[sum+pos-(i-pos)])
						pneg := mul(neg-(func() int {
							if a[z] == 0 {
								return val
							}
							return 0
						}())-(i-pos), rev[sum+pos-(i-pos)])
						ppos := add(1, -add(p, pneg))
						if a[z] == 0 && val > 0 {
							dp[i+1][pos][val-1] = add(dp[i+1][pos][val-1], mul(dp[i][pos][val], p))
						}
						if a[z] == 1 {
							dp[i+1][pos+1][val+1] = add(dp[i+1][pos+1][val+1], mul(dp[i][pos][val], p))
						}
						dp[i+1][pos+1][val] = add(dp[i+1][pos+1][val], mul(dp[i][pos][val], ppos))
						dp[i+1][pos][val] = add(dp[i+1][pos][val], mul(dp[i][pos][val], pneg))
					}
				}
			}
		}
		ans := 0
		for pos := 0; pos <= m; pos++ {
			for val := 0; val < 2*N; val++ {
				if dp[m][pos][val] > 0 {
					ans = add(ans, mul(dp[m][pos][val], val))
				}
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	rand.Seed(time.Now().UnixNano())
	tt := time.Now()

	for read() {
		solve()
		fmt.Printf("TIME = %v\n", time.Since(tt))
		tt = time.Now()
	}
}
