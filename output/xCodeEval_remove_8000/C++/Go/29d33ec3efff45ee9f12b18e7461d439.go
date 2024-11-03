package main

import (
	"fmt"
	"math"
	"strings"
	"time"
)

type i64 int64
type ld float64

const (
	Mod  int64     = 1000000007
	INF  int64     = 1e9
	LINF int64     = 1e18
	Pi   float64   = 3.141592653589793116
	EPS  float64   = 1e-9
	Gold float64   = (1 + math.Sqrt(5)) / 2
)

var (
	keymod   = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount = len(keymod)
)

func getbit(s int64, i int) int {
	return int((s >> i) & 1)
}

func onbit(s int64, i int) int64 {
	return s | (1 << i)
}

func offbit(s int64, i int) int64 {
	return s &^ (1 << i)
}

func cntbit(s int64) int {
	return strings.Count(fmt.Sprintf("%b", s), "1")
}

var TimeStart time.Time
var TimeEnd time.Time

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}

func main() {
	TimerStart()

	// Your code here

	TimerStop()
}
