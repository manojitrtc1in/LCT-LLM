package main

import (
	"fmt"
	"math"
	"time"
)

var TimeStart time.Time
var TimeEnd time.Time

const Mod int64 = 1000000007
const INF int64 = 1e9
const LINF int64 = 1e18
const Pi float64 = 3.141592653589793116
const EPS float64 = 1e-9
const Gold float64 = (1 + math.Sqrt(5)) / 2

var keymod = []int64{1000000007, 1000000009, 1000000021, 1000000033}
var keyCount = len(keymod)

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

func Input() {
	var n, m int64
	fmt.Scan(&n, &m)
}

func Solve() {
	var n, m int64
	A := (modPow(3, n, m) + m - 1) % m
	fmt.Println(A)
}

func main() {
	ControlIO()
	Input()
	TimerStart()
	Solve()
	TimerStop()
}

func ControlIO() {
	// Add your code here for any specific IO control
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}

func Exit() {
	TimerStop()
}
