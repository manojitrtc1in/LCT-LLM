package main

import (
	"fmt"
	"math"
	"os"
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

func gcd(a int64, b int64) int64 {
	var t int64
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func solve2(x int64, y int64, k int64, bonus int64) int64 {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := int64(1)
	for ty*2 <= y {
		ty *= 2
	}
	tx := int64(1)
	for tx*2 <= x {
		tx *= 2
	}
	var res int64
	txk := min(tx, k)
	if tx == ty {
		res = (txk*(txk+1)%mod)*ty + (bonus*txk*2%mod)*ty
		res %= mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = (txk*(txk+1)%mod)*y + (bonus*txk*2%mod)*y
		res %= mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var q int
	fmt.Scan(&q)
	for q > 0 {
		q--
		var x1, y1, x2, y2, k int64
		fmt.Scan(&x1, &y1, &x2, &y2, &k)
		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powmod(2, mod-2, mod) % mod)
	}
}
