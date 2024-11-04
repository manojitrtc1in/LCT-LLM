package main

import (
	"fmt"
	"strings"
)

const (
	maxn    = int(1.5 * 1e7)
	inf     = ^uint(0) >> 1
	ll_inf  = 1e18 + 420
	eps     = 1e-4
	N       = 1e6 + 7
	MAX     = 2e5 + 9
	MOD     = 1e9 + 7
	pi      = 3.14159265359
)

func main() {
	var b, d int
	var a, c string
	fmt.Scanf("%d%d", &b, &d)
	fmt.Scanf("%s%s", &a, &c)

	s := 0
	n := len(c)
	t := make([]int, 128)

	for i := 0; i < n; i++ {
		k := &t[i]
		for j := 0; j < len(a); j++ {
			if a[j] == c[(i+*k)%n] {
				*k++
			}
		}
	}

	for i := 0; i < b; i++ {
		s += t[s%n]
	}

	fmt.Println(s / n / d)
}
