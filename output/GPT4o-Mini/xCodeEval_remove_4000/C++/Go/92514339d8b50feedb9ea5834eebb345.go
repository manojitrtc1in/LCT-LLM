package main

import (
	"fmt"
	"math/bits"
)

const mod = 1e9 + 7

type Triple struct {
	a, b, c int64
}

func bitsCount(v int) int {
	return bits.OnesCount(uint(v))
}

func bitsCountLL(v int64) int {
	return bits.OnesCount(uint(v >> 32)) + bits.OnesCount(uint(v))
}

func reverseBits(x uint32) uint32 {
	x = (x>>1)&0x55555555 | (x&0x55555555)<<1
	x = (x>>2)&0x33333333 | (x&0x33333333)<<2
	x = (x>>4)&0x0f0f0f0f | (x&0x0f0f0f0f)<<4
	x = (x>>8)&0x00ff00ff | (x&0x00ff00ff)<<8
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

func normMod(x *int64, m int64) {
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

func pow2(v int64) int64 {
	return 1 << (63 - bits.LeadingZeros64(uint64(v)))
}

func solve2(x, y, k, bonus int64) int64 {
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

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func powMod(x, n, m int64) int64 {
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
		fmt.Println(ans * powMod(2, mod-2, mod) % mod)
	}
}
