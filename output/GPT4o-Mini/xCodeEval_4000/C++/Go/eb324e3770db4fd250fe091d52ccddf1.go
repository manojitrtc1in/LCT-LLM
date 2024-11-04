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

func add(x *int, y int) {
	*x += y
	if *x >= mod {
		*x -= mod
	}
}

func sub(x *int, y int) {
	*x -= y
	if *x < 0 {
		*x += mod
	}
}

func powlog2(v int) int {
	return 1 << (31 - bits.LeadingZeros32(uint32(v)))
}

func solve2(x, y, k, bonus int) int {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	if (x&(x-1)) == 0 && (y&(y-1)) == 0 {
		k = min(k, x)
		return k * y % mod * (k + 1 + bonus*2) % mod
	}
	ty := powlog2(y)
	tx := powlog2(x)
	res := 0
	txk := min(tx, k)
	if tx == ty {
		res = txk * ty % mod * (txk + 1 + bonus*2) % mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = txk * y % mod * (txk + 1 + bonus*2) % mod
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
		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2, mod) % mod)
	}
}

func powmod(x, n, m int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = (res * x) % m
		}
		x = (x * x) % m
		n >>= 1
	}
	return res
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
