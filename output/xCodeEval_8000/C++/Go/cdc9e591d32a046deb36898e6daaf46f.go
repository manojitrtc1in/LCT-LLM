package main

import (
	"fmt"
	"math"
	"strings"
)

func b303() {
	var n, m, x, y, a, b int64
	fmt.Scan(&n, &m, &x, &y, &a, &b)

	g := gcd(a, b)
	a /= g
	b /= g

	k := min(m/b, n/a)
	width := k * a
	height := k * b

	x1 := max(x-(width+1)/2, int64(0))
	x2 := min(x1+width, n)
	x1 = x2 - width

	y1 := max(y-(height+1)/2, int64(0))
	y2 := min(y1+height, m)
	y1 = y2 - height

	soln := []int64{x1, y1, x2, y2}
	fmt.Println(strings.Trim(fmt.Sprint(soln), "[]"))
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	b303()
}
