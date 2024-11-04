package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	N    = 32
	INF  = int(1e9)
	INF64 = int64(1e18)
	MOD  = int(1e9) + 7
	PI   = 3.141592653589793
)

type mat [N][N]int

var (
	n   int64
	k   int
	amat [62][N]mat
)

func add(a, b int) int {
	a += b
	if a >= MOD {
		a -= MOD
	}
	return a
}

func mul(a, b int) int {
	return a * b % MOD
}

func (a mat) multiply(b mat) mat {
	var c mat
	for i := 0; i <= k; i++ {
		for j := 0; j <= k; j++ {
			c[i][j] = 0
			for t := 0; t <= k; t++ {
				c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]))
			}
		}
	}
	return c
}

func solve() {
	var num []int
	for n > 0 {
		num = append(num, int(n%int64(k)))
		n /= int64(k)
	}

	for d := 0; d < k; d++ {
		for i := 0; i <= k; i++ {
			for j := 0; j <= k; j++ {
				amat[0][d][i][j] = 0
			}
			amat[0][d][i][i] = 1
			amat[0][d][i][d] = 1
		}
	}

	for r := 1; r < len(num); r++ {
		pr := make([]mat, 0)
		var identity mat
		for i := 0; i <= k; i++ {
			for j := 0; j <= k; j++ {
				identity[i][j] = 0
			}
			identity[i][i] = 1
		}
		pr = append(pr, identity)

		for i := 0; i < k; i++ {
			pr = append(pr, pr[len(pr)-1].multiply(amat[r-1][i]))
		}

		for sh := 0; sh < k; sh++ {
			amat[r][sh] = pr[0]
			for i := 0; i < k-sh; i++ {
				amat[r][sh] = amat[r][sh].multiply(amat[r-1][(i+sh)%k])
			}
			amat[r][sh] = amat[r][sh].multiply(pr[sh])
		}
	}

	var dp mat
	for i := 0; i <= k; i++ {
		for j := 0; j <= k; j++ {
			dp[i][j] = 0
		}
	}
	dp[0][k] = 1

	rem := 0
	for i := len(num) - 1; i >= 0; i-- {
		for num[i] > 0 {
			dp = dp.multiply(amat[i][rem])
			rem = (rem + 1) % k
			num[i]--
		}
	}

	ans := 0
	for i := 0; i <= k; i++ {
		ans = add(ans, dp[0][i])
	}
	fmt.Println(ans)
}

func read() bool {
	_, err := fmt.Scan(&n, &k)
	return err == nil
}

func main() {
	rand.Seed(time.Now().UnixNano())

	for read() {
		solve()
	}
}
