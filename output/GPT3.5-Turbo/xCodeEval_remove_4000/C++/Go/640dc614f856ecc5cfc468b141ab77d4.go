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

var (
	Mod     int64 = 1000000007
	INF     int64 = 1e9
	LINF    int64 = 1e18
	Pi      float64 = 3.141592653589793116
	EPS     float64 = 1e-9
	Gold    float64 = (1 + math.Sqrt(5)) / 2
	keymod         = []int64{1000000007, 1000000009, 1000000021, 1000000033}
	keyCount       = len(keymod)
	TimeStart      time.Time
	TimeEnd        time.Time
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
	return int(math.Popcount(s))
}

func func(m, n, s int64) pii {
	if m == 0 {
		return pii{n, s}
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(func(m-x, n+1, s+x), func(x-y-1, n+1, s+y))
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

func Input() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func Solve(x int64) {
	Token := func(x, 0, 0)
	fmt.Println(Token.first, Token.second)
}

func main() {
	TimeStart = time.Now()

	x := Input()
	Solve(x)

	var T int
	fmt.Scan(&T)
	for T > 0 {
		x := Input()
		Solve(x)
		T--
	}

	TimeEnd = time.Now()
	ElapsedTime := TimeEnd.Sub(TimeStart)
	fmt.Printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime.Seconds())
}
