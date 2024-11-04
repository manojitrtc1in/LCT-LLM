package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x int
	y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v []int) String() string {
	result := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			result += ", "
		}
		result += fmt.Sprintf("%d", v[i])
	}
	return result + "]"
}

var rnd *rand.Rand

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = 998244353
	EPS   = 1e-9
	PI    = math.Acos(-1.0)
)

const (
	N = 50 + 7
	M = 3000 + 7
)

var (
	n, m int
	a    [N]int
	w    [N]int
)

func read() bool {
	if _, err := fmt.Scanf("%d%d", &n, &m); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &w[i])
	}
	return true
}

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

var dp [N][N][2*N]int
var rev [M]int

func solve() {
	sum := 0
	for i := 0; i < n; i++ {
		sum += w[i]
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
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				for k := 0; k < 2*N; k++ {
					dp[i][j][k] = 0
				}
			}
		}
		dp[0][0][w[z]] = 1
		for i := 0; i < m; i++ {
			for pos := 0; pos <= i; pos++ {
				for val := 0; val < 2*N; val++ {
					if dp[i][pos][val] != 0 {
						p := mul(val, rev[sum+pos-(i-pos)])
						pneg := mul(neg-(a[z] == 0)*val-(i-pos), rev[sum+pos-(i-pos)])
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
				if dp[m][pos][val] != 0 {
					ans = add(ans, mul(dp[m][pos][val], val))
				}
			}
		}
		fmt.Println(ans)
	}
}

func main() {
	rnd = rand.New(rand.NewSource(time.Now().UnixNano()))

	tt := time.Now()

	for read() {
		solve()
	}

	fmt.Println("TIME =", time.Since(tt))
}
