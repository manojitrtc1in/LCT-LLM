package main

import (
	"fmt"
	"math"
	"math/rand"
	"os"
	"time"
)

const (
	eps     = 1e-9
	pi      = 3.14159265358979323846264338327950288419716939937510
	mod     = 1000000007
	inf     = 0x3f3f3f3f
	_       = 2e5 + 10
	__      = 1e6 + 10
	LOG     = 18
)

var (
	n, k int
	p    [22]float64
	subret [22]float64
	dp    [1 << 20]float64
)

func solve(id int) {
	if p[id] <= eps {
		fmt.Print("0\n")
		return
	}
	for i := range subret {
		subret[i] = 0
	}
	subret[0] = dp[0] = p[id]
	for i := 1; i < (1 << n); i++ {
		dp[i] = 0
		if (i>>id)&1 == 1 {
			continue
		}
		sum := 0.0
		for j := 0; j < n; j++ {
			if (i>>j)&1 == 1 {
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
	file, err := os.Open("in.txt")
	if err != nil {
		panic(err)
	}
	defer file.Close()

	fmt.Fscanf(file, "%d %d", &n, &k)
	for i := 0; i < n; i++ {
		fmt.Fscanf(file, "%f", &p[i])
	}
	for i := 0; i < n; i++ {
		solve(i)
	}
	fmt.Println()

	id3()
	fmt.Printf("Time elapsed: %.2fs.\n", runTime())
}

func id3() {
	rand.Seed(time.Now().UnixNano())
	n := 1000
}

func runTime() float64 {
	// Placeholder for actual time calculation
	return float64(time.Now().UnixNano()) / 1e9
}
