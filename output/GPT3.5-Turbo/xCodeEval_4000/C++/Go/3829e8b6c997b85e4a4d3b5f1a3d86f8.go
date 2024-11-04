package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)
	N     = 32
)

type pt struct {
	x, y int
}

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

type mat [N][N]int

func matMul(a, b mat) mat {
	var c mat
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			c[i][j] = 0
			for t := 0; t < N; t++ {
				c[i][j] = add(c[i][j], mul(a[i][t], b[t][j]))
			}
		}
	}
	return c
}

var amat [62][N]mat

func solve(n int64, k int) {
	num := make([]int, 0)
	for n > 0 {
		num = append(num, int(n%int64(k)))
		n /= int64(k)
	}

	for d := 0; d < k; d++ {
		for i := 0; i < k+1; i++ {
			for j := 0; j < k+1; j++ {
				amat[0][d][i][j] = 0
			}
		}
		for i := 0; i < k+1; i++ {
			amat[0][d][i][i] = 1
		}
		for i := 0; i < k+1; i++ {
			amat[0][d][i][d] = 1
		}
	}

	for r := 1; r < len(num); r++ {
		pr := make([]mat, 0)
		pr = append(pr, mat{})
		for i := 0; i < k+1; i++ {
			for j := 0; j < k+1; j++ {
				pr[0][i][j] = i == j
			}
		}
		for i := 0; i < k; i++ {
			pr = append(pr, matMul(pr[len(pr)-1], amat[r-1][i]))
		}
		for sh := 0; sh < k; sh++ {
			amat[r][sh] = pr[0]
			for i := 0; i < k-sh; i++ {
				amat[r][sh] = matMul(amat[r][sh], amat[r-1][(i+sh)%k])
			}
			amat[r][sh] = matMul(amat[r][sh], pr[sh])
		}
	}

	var dp mat
	for i := 0; i < k+1; i++ {
		for j := 0; j < k+1; j++ {
			dp[i][j] = 0
		}
	}
	dp[0][k] = 1

	rem := 0
	for i := len(num) - 1; i >= 0; i-- {
		for num[i] > 0 {
			dp = matMul(dp, amat[i][rem])
			rem = (rem + 1) % k
			num[i]--
		}
	}

	ans := 0
	for i := 0; i < k+1; i++ {
		ans = add(ans, dp[0][i])
	}
	fmt.Println(ans)
}

func main() {
	rand.Seed(time.Now().UnixNano())

	var n int64
	var k int
	for {
		_, err := fmt.Scan(&n, &k)
		if err != nil {
			break
		}
		solve(n, k)
	}
}
