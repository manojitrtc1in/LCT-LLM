package main

import (
	"fmt"
	"math"
)

const mod = 1e9 + 7
const error = 2e-6
const PI = math.Acos(-1)

func MOD(x, m int64) int64 {
	y := x % m
	if y >= 0 {
		return y
	}
	return y + m
}

const inf = 1e9
const infl = 1061109567
const nmax = 1000 + 10

func popCount(x int64) int {
	count := 0
	for x > 0 {
		count += int(x & 1)
		x >>= 1
	}
	return count
}

func main() {
	var n, p int64
	fmt.Scan(&n, &p)

	if p == 0 {
		fmt.Println(popCount(n))
		return
	}

	if p > 0 {
		for i := int64(1); i <= 35; i++ {
			n -= p
			if n < 0 {
				fmt.Println(-1)
				return
			}
			if popCount(n) <= int(i) && popCount(n) != 0 {
				if popCount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
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
			if popCount(n) <= int(i) && popCount(n) != 0 {
				if popCount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
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
