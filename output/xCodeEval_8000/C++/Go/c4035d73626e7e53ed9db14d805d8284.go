package main

import (
	"fmt"
	"math"
)

func main() {
	var n, p int64
	fmt.Scan(&n, &p)
	if p == 0 {
		fmt.Println(popcount(n))
		return
	}
	if p > 0 {
		for i := int64(1); i <= 35; i++ {
			n -= p
			if n < 0 {
				fmt.Println(-1)
				return
			}
			if popcount(n) <= i && popcount(n) != 0 {
				if popcount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
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
			if popcount(n) <= i && popcount(n) != 0 {
				if popcount(n) == 1 && i > int64(math.Log2(float64(n)))+1 {
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

func popcount(n int64) int64 {
	count := int64(0)
	for n > 0 {
		count += n & 1
		n >>= 1
	}
	return count
}
