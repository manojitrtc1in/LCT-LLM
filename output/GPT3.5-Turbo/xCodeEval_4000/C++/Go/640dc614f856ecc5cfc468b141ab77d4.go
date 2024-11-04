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

func funcGo(m, n, s int64) pii {
	if m == 0 {
		return pii{n, s}
	}
	k := int64(math.Cbrt(float64(m)))
	x := k * k * k
	y := (k - 1) * (k - 1) * (k - 1)
	return max(funcGo(m-x, n+1, s+x), funcGo(x-y-1, n+1, s+y))
}

func input() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func solve(x int64) {
	token := funcGo(x, 0, 0)
	fmt.Println(token.first, token.second)
}

func main() {
	x := input()
	start := time.Now()
	solve(x)
	elapsed := time.Since(start)
	fmt.Printf("\nTime elapsed: %s\n", elapsed)
}
