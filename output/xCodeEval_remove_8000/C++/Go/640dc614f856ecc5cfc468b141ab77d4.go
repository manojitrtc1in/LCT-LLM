package main

import (
	"fmt"
	"math"
	"time"
)

type pii struct {
	first  int64
	second int64
}

var TimeStart time.Time
var TimeEnd time.Time

var x int64

func func1(m, n, s int64) pii {
	if m == 0 {
		return pii{n, s}
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(func1(m-x, n+1, s+x), func1(x-y-1, n+1, s+y))
}

func Input() {
	fmt.Scan(&x)
}

func Solve() {
	Token := func1(x, 0, 0)
	fmt.Println(Token.first, Token.second)
}

func main() {
	Input()
	TimerStart()
	Solve()
	TimerStop()
}

func TimerStart() {
	TimeStart = time.Now()
}

func TimerStop() {
	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}

func max(a, b pii) pii {
	if a.first > b.first {
		return a
	} else if a.first < b.first {
		return b
	} else {
		if a.second > b.second {
			return a
		} else {
			return b
		}
	}
}
