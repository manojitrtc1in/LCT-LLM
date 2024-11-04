package main

import (
	"fmt"
	"math"
)

const (
	B  = 100 * 1000
	MN = 3e8 + 10
)

var is [MN]bool

func check(x int) bool {
	if x == 2 {
		return true
	}
	if x%4 != 1 {
		return false
	}

	F := false
	for d := 2; d*d <= x; d++ {
		if x%d == 0 {
			return false
		}
		if d*d != x && is[x-d*d] {
			F = true
		}
	}
	return F
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)
	ret := 0
	pl := l / B
	pr := r / B
	for d := 1; d*d < MN; d++ {
		is[d*d] = true
	}

	if l/B == r/B {
		for i := l; i <= r; i++ {
			if check(i) {
				ret++
			}
		}
		fmt.Println(ret)
		return
	}
	for i := pl + 1; i < pr; i++ {
		ret += prec[i]
	}
	for i := l; i/B == pl; i++ {
		if check(i) {
			ret++
		}
	}
	for i := r; i/B == pr; i-- {
		if check(i) {
			ret++
		}
	}
	fmt.Println(ret)
}
