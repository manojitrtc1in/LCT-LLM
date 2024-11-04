package main

import (
	"fmt"
	"math/rand"
	"time"
)

const INF = int(1e9)
const INF64 = int64(1e18)
const MOD = int(1e9) + 7
const EPS = 1e-9
const PI = 3.141592653589793

const N = 4*1000*1000 + 13

var n, mod int
var dp [N]int
var pr [N]int

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

func mul(a, b int) int {
	return a * int64(b) % mod
}

func solve() {
	for i := range dp {
		dp[i] = 0
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

	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		tc--
		if !read() {
			break
		}
		solve()
	}
}
