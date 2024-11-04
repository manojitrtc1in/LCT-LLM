package main

import (
	"fmt"
	"math/big"
)

const mod = 1_000_000_007

type Triple[T1 any, T2 any, T3 any] struct {
	a T1
	b T2
	c T3
}

func (t Triple[T1, T2, T3]) Less(t2 Triple[T1, T2, T3]) bool {
	if t.a != t2.a {
		return t.a < t2.a
	} else if t.b != t2.b {
		return t.b < t2.b
	}
	return t.c < t2.c
}

func bitsCount(v int) int {
	v = v - ((v >> 1) & 0x55555555)
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
	return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24
}

func bitsCountLL(v int64) int {
	t := v >> 32
	p := v & ((1 << 32) - 1)
	return bitsCount(int(t)) + bitsCount(int(p))
}

func reverseBits(x uint32) uint32 {
	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)
	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)
	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)
	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)
	return (x >> 16) | (x << 16)
}

func sign[T comparable](x T) int {
	if x > 0 {
		return 1
	} else if x < 0 {
		return -1
	}
	return 0
}

func isPrime[T int | int64](x T) bool {
	if x < 2 {
		return false
	}
	for i := T(2); i*i <= x; i++ {
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

func id6(x, y, m int64) int64 {
	res := x + y
	if res >= m {
		res -= m
	}
	return res
}

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

func id3(v int) int {
	return 1 << (31 - bitsCount(v))
}

func solve2(x, y, k, bonus int) int {
	if x <= 0 || y <= 0 || k <= 0 {
		return 0
	}
	if x < y {
		x, y = y, x
	}
	ty := id3(y)
	tx := id3(x)
	res := 0
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
		var x1, y1, x2, y2, k int
		fmt.Scan(&x1, &y1, &x2, &y2, &k)
		ans := solve2(x2, y2, k) - solve2(x1-1, y2, k) - solve2(x2, y1-1, k) + solve2(x1-1, y1-1, k)
		ans %= mod
		if ans < 0 {
			ans += mod
		}
		fmt.Println(ans * powMod(2, mod-2, mod) % mod)
	}
}
