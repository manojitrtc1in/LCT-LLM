package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007

var a [10]int
var b [10]int
var s string
var r, rr, x, y, xx, yy, zero int

func calc(x int) {
	y := 10 - x
	if a[x] == 0 || a[y] == 0 {
		return
	}
	r := 1
	for i := 0; i < 10; i++ {
		r += int(math.Min(float64(a[i]-(boolToInt(i == x))), float64(a[9-i]-(boolToInt(9-i == y)))))
	}
	if r > rr {
		rr = r
		xx = x
		yy = y
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	fmt.Scan(&s)
	for _, char := range s {
		a[char-'0']++
	}

	r = 0
	x = y = int(s[0] - '0')
	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		rr = 0
		xx = yy = int(s[0] - '0')
		for j := 1; j <= 5; j++ {
			calc(j)
		}
		if rr+i > r {
			r = rr + i
			zero = i
			x = xx
			y = yy
		}
		a[0] += i
	}

	if x == 0 {
		zero--
	}
	a[0] -= zero
	copy(b[:], a[:])
	a[x]--
	b[y]--

	for i := 0; i < 10; i++ {
		for j := 0; j < a[i]-int(math.Min(float64(a[i]), float64(b[9-i]))); j++ {
			fmt.Print(i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < int(math.Min(float64(a[i]), float64(b[9-i]))); j++ {
			fmt.Print(i)
		}
	}
	if a[x] >= 0 {
		fmt.Print(x)
	}
	for i := 0; i < zero; i++ {
		fmt.Print("0")
	}
	fmt.Println()

	for i := 0; i < 10; i++ {
		for j := 0; j < b[9-i]-int(math.Min(float64(a[i]), float64(b[9-i]))); j++ {
			fmt.Print(9 - i)
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < int(math.Min(float64(a[i]), float64(b[9-i]))); j++ {
			fmt.Print(9 - i)
		}
	}
	if b[y] >= 0 {
		fmt.Print(y)
	}
	for i := 0; i < zero; i++ {
		fmt.Print("0")
	}
	fmt.Println()
}
