package main

import (
	"fmt"
	"math/big"
)

var mod int64 = 1e9 + 7

type Triple struct {
	a, b, c int64
}

func bitsCount(v int) int {
	v = v - ((v >> 1) & 0x55555555)
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
	return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24
}

func reverseBits(x uint32) uint32 {
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)
	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)
	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)
	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)
	return (x >> 16) | (x << 16)
}

func sign(x int) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

func isPrime(x int64) bool {
	if x < 2 {
		return false
	}
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func normmod(x *int64, m int64) {
	*x %= m
	if *x < 0 {
		*x += m
	}
}

func id5(x, y, m int64) int64 {
	res := x + y
	if res >= m {
		res -= m
	}
	return res
}

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

func solve2(x, y, k, bonus int64) int64 {
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
		res = (txk * (txk + 1) % mod * ty) % mod
		res = (res + bonus*txk*2%mod*ty) % mod
		add(&res, solve2(x-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(y-tx, tx, k-tx, bonus+tx))
		add(&res, solve2(x-tx, y-tx, k, bonus))
	} else {
		res = (txk * (txk + 1) % mod * y) % mod
		res = (res + bonus*txk*2%mod*y) % mod
		add(&res, solve2(x-tx, y, k-tx, bonus+tx))
	}
	return res
}

func powmod(x, n, m int64) int64 {
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
