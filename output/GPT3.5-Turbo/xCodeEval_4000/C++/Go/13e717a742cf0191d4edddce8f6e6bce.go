package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	a := make([]int, 10)
	for _, c := range s {
		a[c-'0']++
	}

	r := -1
	x := int(s[0] - '0')
	y := x
	zero := 0

	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		rr := 0
		xx := x
		yy := y
		calc(&a, &rr, &xx, &yy)
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
	b := make([]int, 10)
	copy(b, a)
	a[x]--
	b[y]--

	ans1 := ""
	ans2 := ""

	for i := 0; i < 10; i++ {
		for j := 0; j < a[i]-min(a[i], b[9-i]); j++ {
			ans1 += fmt.Sprintf("%d", i)
		}
		for j := 0; j < min(a[i], b[9-i]); j++ {
			ans1 += fmt.Sprintf("%d", i)
		}
	}

	if a[x] >= 0 {
		ans1 += fmt.Sprintf("%d", x)
	}

	for i := 0; i < zero; i++ {
		ans1 += "0"
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < b[9-i]-min(a[i], b[9-i]); j++ {
			ans2 += fmt.Sprintf("%d", 9-i)
		}
		for j := 0; j < min(a[i], b[9-i]); j++ {
			ans2 += fmt.Sprintf("%d", 9-i)
		}
	}

	if b[y] >= 0 {
		ans2 += fmt.Sprintf("%d", y)
	}

	for i := 0; i < zero; i++ {
		ans2 += "0"
	}

	fmt.Println(ans1)
	fmt.Println(ans2)
}

func calc(a *[]int, rr *int, xx *int, yy *int) {
	for x := 1; x <= 5; x++ {
		y := 10 - x
		if (*a)[x] == 0 || (*a)[y] == 0 {
			continue
		}
		r := 1
		for i := 0; i < 10; i++ {
			r += min((*a)[i]-(i == x), (*a)[9-i]-(9-i == y))
		}
		if r > *rr {
			*rr = r
			*xx = x
			*yy = y
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
