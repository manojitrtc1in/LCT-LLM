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

func funcGo(m, n, s int64) pii {
	if m == 0 {
		return pii{n, s}
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(funcGo(m-x, n+1, s+x), funcGo(x-y-1, n+1, s+y))
}

func max(a, b pii) pii {
	if a.first > b.first {
		return a
	}
	if a.first < b.first {
		return b
	}
	if a.second > b.second {
		return a
	}
	return b
}

func Input() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func Solve(x int64) {
	Token := funcGo(x, 0, 0)
	fmt.Println(Token.first, Token.second)
}

func main() {
	start := time.Now()

	x := Input()
	Solve(x)

	elapsed := time.Since(start)
	fmt.Printf("\nTime elapsed: %s\n", elapsed)
}
