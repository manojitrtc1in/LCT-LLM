package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	N     = 4 * 1000 * 1000 + 13
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = 3.141592653589793
)

var (
	n   int
	mod int
	dp  [N]int
	pr  [N]int
)

func add(a, b int) int {
	a += b
	if a >= mod {
		a -= mod
	}
	if a < 0 {
		a += mod
	}
	return a
}

func solve() {
	for i := range dp {
		dp[i] = 0
	}
	for i := range pr {
		pr[i] = 0
	}
	pr[1] = 1
	pr[2] = mod - 1
	for i := 1; i <= n; i++ {
		dp[i] = pr[i]
		pr[i+1] = add(pr[i+1], dp[i])
		for j := 2; j*i <= n; j++ {
			pr[j*i] = add(pr[j*i], dp[i])
			if j*(i+1) < N {
				pr[j*(i+1)] = add(pr[j*(i+1)], -dp[i])
			}
		}
		pr[i+1] = add(pr[i+1], pr[i])
	}
	fmt.Println(dp[n])
}

func read() bool {
	_, err := fmt.Scan(&n, &mod)
	return err == nil
}

func main() {
	rand.Seed(time.Now().UnixNano())

	for read() {
		solve()
	}
}
