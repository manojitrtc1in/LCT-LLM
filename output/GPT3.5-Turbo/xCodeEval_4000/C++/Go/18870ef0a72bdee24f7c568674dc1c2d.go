package main

import (
	"fmt"
	"math"
)

const SQ = 100 * 1000
const N = 3e8 + SQ

var l, r int
var res [N/SQ + 1]int

func prime(n int) bool {
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return n > 1
}

func check(n int) bool {
	if n == 2 {
		return true
	}
	if n%4 != 1 {
		return false
	}
	return prime(n)
}

func calc(l, r int) int {
	pl := l / SQ
	pr := r / SQ
	ans := 0

	if pl == pr {
		for i := l; i <= r; i++ {
			if check(i) {
				ans++
			}
		}
		return ans
	}

	for l < (pl+1)*SQ {
		if check(l) {
			ans++
		}
		l++
	}
	for r >= pr*SQ {
		if check(r) {
			ans++
		}
		r--
	}

	for i := pl + 1; i < pr; i++ {
		ans += res[i]
	}

	return ans
}

func main() {
	fmt.Scan(&l, &r)

	fmt.Println(calc(l, r))
}
