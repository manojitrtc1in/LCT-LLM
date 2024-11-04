package main

import (
	"fmt"
	"math"
	"os"
	"time"
)

const (
	Mod      = 1000000007
	INF      = 1e9
	LINF     = 1e18
	Pi       = 3.141592653589793116
	EPS      = 1e-9
	Gold     = (1 + math.Sqrt(5)) / 2
)

var (
	x int64
)

func funcCalc(m, n, s int64) (int64, int64) {
	if m == 0 {
		return n, s
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(funcCalc(m-x, n+1, s+x), funcCalc(x-y-1, n+1, s+y))
}

func max(a, b (int64, int64)) (int64, int64) {
	if a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]) {
		return a
	}
	return b
}

func input() {
	fmt.Scan(&x)
}

func solve() {
	n, s := funcCalc(x, 0, 0)
	fmt.Println(n, s)
}

func main() {
	start := time.Now()

	input()
	solve()

	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %v seconds.\n", elapsed.Seconds())
}
