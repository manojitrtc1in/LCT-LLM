package main

import (
	"fmt"
	"math"
)

const INF = math.MaxInt32

func countBits(v uint) int {
	v = v - ((v >> 1) & 0x55555555)
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
	return int(((v + (v >> 4)) & 0xF0F0F0F) * 0x1010101 >> 24)
}

func readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func main() {
	n := readInt()
	a := make([]int, n+2)
	for i := 1; i <= n; i++ {
		a[i] = readInt()
	}
	a[0] = -INF
	a[n+1] = INF + INF
	ans := INF

	for i := 1; i <= n; i++ {
		s := a[i]
		for j := 2; j <= 50 && i+j-1 <= n; j++ {
			s ^= a[i+j-1]
			z := 0
			for r := 0; r < 50 && i+j+r <= n+1; r++ {
				z ^= a[i+j+r]
				if a[i-1] > s || s > z {
					ans = min(ans, j+r)
					break
				}
			}
		}
	}
	if ans == INF {
		ans = 0
	}
	fmt.Println(ans - 1)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
