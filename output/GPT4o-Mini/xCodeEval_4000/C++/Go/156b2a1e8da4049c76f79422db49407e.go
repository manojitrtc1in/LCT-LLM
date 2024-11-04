package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"time"
)

const (
	eps   = 1e-9
	mod   = 1000000007
	_     = 200010
	__    = 1000000
	LOG   = 18
)

var (
	n, k int
	p     [22]float64
	subret [22]float64
	dp     [1 << 20]float64
)

func solve(id int) {
	if p[id] <= eps {
		fmt.Println(0)
		return
	}
	for i := range subret {
		subret[i] = 0
	}
	subret[0] = dp[0] = p[id]
	for i := 1; i < (1 << n); i++ {
		dp[i] = 0
		if (i & (1 << id)) != 0 {
			continue
		}
		sum := 0.0
		for j := 0; j < n; j++ {
			if (i & (1 << j)) != 0 {
				sum += p[j]
				dp[i] += dp[i^(1<<j)] * p[j]
			}
		}
		dp[i] /= 1 - sum
		subret[countBits(i)] += dp[i]
	}
	ret := 0.0
	for i := 0; i < k; i++ {
		ret += subret[i]
	}
	fmt.Printf("%.10f\n", ret)
}

func countBits(x int) int {
	count := 0
	for x > 0 {
		count += x & 1
		x >>= 1
	}
	return count
}

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Scan(&n, &k)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i])
	}
	for i := 0; i < n; i++ {
		solve(i)
	}
}

func generateTestCase() {
	n := 1000
	// Additional test case generation logic can be added here
	os.Exit(0)
}
