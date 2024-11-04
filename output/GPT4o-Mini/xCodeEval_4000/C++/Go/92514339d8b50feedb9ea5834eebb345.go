package main

import (
	"fmt"
	"math"
)

const (
	INF     = 1011111111
	LLINF   = 1000111000111000117
	EPS     = 1e-10
	mod     = 1000000007
	PI      = 3.14159265358979323
)

func add(x *int64, y int64) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func sub(x *int64, y int64) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func pow2(v int64) int64 {
	return 1 << (63 - bits.LeadingZeros64(uint64(v)))
}

func solve2(x int64, y int64, k int64, bonus int64) int64 {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := pow2(y)
	tx := pow2(x)
	var res int64
	txk := min(tx, k)
	if tx == ty {
		res = (txk * ty % mod * (txk + 1 + bonus*2)) % mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = (txk * y % mod * (txk + 1 + bonus*2)) % mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
}

func main() {
	var q int
	fmt.Scan(&q)
	for q > 0 {
		q--
		var x1, y1, x2, y2, k int
		fmt.Scan(&x1, &y1, &x2, &y2, &k)
		ans := solve2(int64(x2), int64(y2), int64(k)) -
			solve2(int64(x1-1), int64(y2), int64(k)) -
			solve2(int64(x2), int64(y1-1), int64(k)) +
			solve2(int64(x1-1), int64(y1-1), int64(k))
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2, mod) % mod)
	}
}

func powmod(x int64, n int64, m int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % m
		}
		x = (x * x) % m
		n >>= 1
	}
	return res
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
