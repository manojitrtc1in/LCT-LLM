package main

import (
	"fmt"
	"math/bits"
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

func goFunc(n int) {
	var p [10][10]int64 // Adjust size as needed
	i100 := powe(100, mod-2)

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			var x int64
			fmt.Scan(&x)
			p[i][j] = x * i100 % mod
		}
	}

	x := make(map[[1 << 10]uint8]int64) // Adjust size as needed
	var init [1 << 10]uint8
	x[init] = 1

	for turn := 0; turn < n; turn++ {
		newx := make(map[[1 << 10]uint8]int64) // Adjust size as needed
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
					if (k&s) != 0 && c[k] < bits.OnesCount(uint(k)) {
						c[k]++
					}
				}
				add := true
				for k := 0; k < (1 << n); k++ {
					if c[k]+(n-turn-1) < bits.OnesCount(uint(k)) {
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

	var fin [1 << 10]uint8 // Adjust size as needed
	for i := 0; i < (1 << n); i++ {
		fin[i] = uint8(bits.OnesCount(uint(i)))
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
