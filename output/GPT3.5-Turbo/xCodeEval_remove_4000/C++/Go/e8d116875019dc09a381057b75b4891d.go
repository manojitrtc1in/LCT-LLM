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

	r := 0
	x, y := int(s[0]-'0'), int(s[0]-'0')
	zero := 0
	for i := 0; i <= a[0]; i++ {
		a[0] -= i
		b := make([]int, len(a))
		copy(b, a)
		rr := 0
		xx, yy := x, y
		calc(&rr, &xx, &yy, 1, a)
		calc(&rr, &xx, &yy, 2, a)
		calc(&rr, &xx, &yy, 3, a)
		calc(&rr, &xx, &yy, 4, a)
		calc(&rr, &xx, &yy, 5, a)
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
	b := make([]int, len(a))
	copy(b, a)
	a[x]--
	b[y]--

	var res1, res2 strings.Builder
	for i := 0; i < 10; i++ {
		for j := 0; j < a[i]-min(a[i], b[9-i]); j++ {
			res1.WriteString(fmt.Sprintf("%d", i))
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(a[i], b[9-i]); j++ {
			res1.WriteString(fmt.Sprintf("%d", i))
		}
	}
	if a[x] >= 0 {
		res1.WriteString(fmt.Sprintf("%d", x))
	}
	for i := 0; i < zero; i++ {
		res1.WriteString("0")
	}

	for i := 0; i < 10; i++ {
		for j := 0; j < b[9-i]-min(a[i], b[9-i]); j++ {
			res2.WriteString(fmt.Sprintf("%d", 9-i))
		}
	}
	for i := 0; i < 10; i++ {
		for j := 0; j < min(a[i], b[9-i]); j++ {
			res2.WriteString(fmt.Sprintf("%d", 9-i))
		}
	}
	if b[y] >= 0 {
		res2.WriteString(fmt.Sprintf("%d", y))
	}
	for i := 0; i < zero; i++ {
		res2.WriteString("0")
	}

	fmt.Println(res1.String())
	fmt.Println(res2.String())
}

func calc(rr, xx, yy *int, x int, a []int) {
	y := 10 - x
	if a[x] == 0 || a[y] == 0 {
		return
	}
	r := 1
	for i := 0; i < 10; i++ {
		r += min(a[i]-(i == x), a[9-i]-(9-i == y))
	}
	if r > *rr {
		*rr = r
		*xx = x
		*yy = y
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
