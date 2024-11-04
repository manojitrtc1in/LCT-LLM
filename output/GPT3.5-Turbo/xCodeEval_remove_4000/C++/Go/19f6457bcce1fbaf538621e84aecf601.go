package main

import (
	"fmt"
)

const mod = 1e9 + 7

func powe(b, e int64) int64 {
	r := int64(1)
	for e != 0 {
		if e&1 != 0 {
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

func goFunc(n int) {
	p := make([][]int64, n)
	for i := 0; i < n; i++ {
		p[i] = make([]int64, n)
		for j := 0; j < n; j++ {
			var x int64
			fmt.Scan(&x)
			p[i][j] = x * powe(100, mod-2) % mod
		}
	}

	type state [1 << n]uint8

	x := make(map[state]int64)
	init := state{}
	for i := 0; i < (1 << n); i++ {
		init[i] = 0
	}
	x[init] = 1

	for turn := 0; turn < n; turn++ {
		newx := make(map[state]int64)
		for s := 0; s < (1 << n); s++ {
			mul := int64(1)
			for i := 0; i < n; i++ {
				if s>>i&1 != 0 {
					mul = mul * p[i][turn] % mod
				} else {
					mul = mul * (1 - p[i][turn]) % mod
				}
			}
			for c, val := range x {
				for k := 0; k < (1 << n); k++ {
					if k&s != 0 && c[k] < popc(k) {
						c[k]++
					}
				}
				add := true
				for k := 0; k < (1 << n); k++ {
					if c[k]+(n-turn-1) < popc(k) {
						add = false
					}
				}
				if add {
					admul(&newx[c], mul, val)
				}
			}
		}
		x = newx
	}

	fin := state{}
	for i := 0; i < (1 << n); i++ {
		fin[i] = popc(i)
	}

	ans := x[fin]
	ans %= mod
	if ans < 0 {
		ans += mod
	}
	fmt.Println(ans)
}

func main() {
	var n int
	fmt.Scan(&n)
	goFunc(n)
}

func popc(x int) int {
	count := 0
	for x != 0 {
		x &= x - 1
		count++
	}
	return count
}
