package main

import (
	"fmt"
	"math"
)

const mod = 1e9 + 7

func MOD(x, m int64) int64 {
	y := x % m
	if y >= 0 {
		return y
	}
	return y + m
}

func main() {
	var n, p int64
	fmt.Scan(&n, &p)
	if p == 0 {
		fmt.Println(math/builtin_popcount(n))
		return
	}
	if p > 0 {
		for i := int64(1); i <= 35; i++ {
			n -= p
			if n < 0 {
				fmt.Println(-1)
				return
			}
			if math/builtin_popcount(n) <= i && math/builtin_popcount(n) != 0 {
				if math/builtin_popcount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
					fmt.Println(-1)
					return
				}
				fmt.Println(i)
				return
			}
		}
		fmt.Println(-1)
		return
	}

	if p < 0 {
		for i := int64(1); i <= 35; i++ {
			n += -p
			if n < 0 {
				continue
			}
			if math/builtin_popcount(n) <= i && math/builtin_popcount(n) != 0 {
				if math/builtin_popcount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
					fmt.Println(-1)
					return
				}
				fmt.Println(i)
				return
			}
		}
		fmt.Println(-1)
		return
	}
}
