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

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

var n, m int64

func modPow(a, b, M int64) int64 {
	if b == 0 {
		return 1
	}
	tmp := modPow(a, b/2, M)
	if b%2 == 0 {
		return (tmp * tmp) % M
	}
	return (((tmp * tmp) % M) * a) % M
}

func input() {
	fmt.Scan(&n, &m)
}

func solve() {
	A := (modPow(3, n, m) + m - 1) % m
	fmt.Println(A)
}

func controlIO(args []string) {
	if len(args) > 1 {
		file, err := os.Open(args[1])
		if err != nil {
			panic(err)
		}
		defer file.Close()
		os.Stdin = file
	}
	if len(args) > 2 {
		file, err := os.Create(args[2])
		if err != nil {
			panic(err)
		}
		defer file.Close()
		os.Stdout = file
	}
}

func timerStart() time.Time {
	return time.Now()
}

func timerStop(start time.Time) {
	elapsed := time.Since(start)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", elapsed.Seconds())
}

func main() {
	start := timerStart()
	controlIO(os.Args)

	var T int
	fmt.Scan(&T)
	for i := 0; i < T; i++ {
		input()
		solve()
	}
	timerStop(start)
}
