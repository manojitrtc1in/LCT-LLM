package main

import (
	"fmt"
	"math/big"
)

const mod = 1e9 + 7

func powe(b, e int64) int64 {
	r := int64(1)
	for e > 0 {
		if e&1 == 1 {
			r = r * b % mod
		}
		b = b * b % mod
		e >>= 1
	}
	return r
}

func admul(a *int64, b, c int64) {
	*a = (*a + b*c) % mod
}

type state [1 << 6]uint8 // Assuming n <= 6 for simplicity

func goFunc(n int) {
	p := [6][6]int64{}
	i100 := powe(100, mod-2)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var x int64
			fmt.Scan(&x)
			p[i][j] = x * i100 % mod
		}
	}

	x := make(map[state]int64)
	var init state
	for i := 0; i < (1 << n); i++ {
		init[i] = 0
	}
	x[init] = 1

	for turn := 0; turn < n; turn++ {
		newx := make(map[state]int64)
		for s := 0; s < (1 << n); s++ {
			mul := int64(1)
			for i := 0; i < n; i++ {
				if s>>i&1 == 1 {
					mul = mul * p[i][turn] % mod
				} else {
					mul = mul * (1 - p[i][turn]) % mod
				}
			}
			for c, count := range x {
				for k := 0; k < (1 << n); k++ {
					if (k&s) != 0 && c[k] < popCount(k) {
						c[k]++
					}
				}
				add := true
				for k := 0; k < (1 << n); k++ {
					if c[k]+(n-turn-1) < popCount(k) {
						add = false
					}
				}
				if add {
					admul(&newx[c], mul, count)
				}
			}
		}
		x = newx
	}

	var fin state
	for i := 0; i < (1 << n); i++ {
		fin[i] = popCount(i)
	}
	ans := x[fin]
	ans %= mod
	if ans < 0 {
		ans += mod
	}
	fmt.Println(ans)
}

func popCount(x int) uint8 {
	var count uint8
	for x > 0 {
		count += uint8(x & 1)
		x >>= 1
	}
	return count
}

func main() {
	var n int
	fmt.Scan(&n)
	switch n {
	case 1:
		goFunc(1)
	case 2:
		goFunc(2)
	case 3:
		goFunc(3)
	case 4:
		goFunc(4)
	case 5:
		goFunc(5)
	case 6:
		goFunc(6)
	}
}
