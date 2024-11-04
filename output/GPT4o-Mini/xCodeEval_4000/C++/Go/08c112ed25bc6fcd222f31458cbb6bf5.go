package main

import (
	"fmt"
	"math"
)

const (
	INF      = 1011111111
	LLINF    = 1000111000111000111
	T9       = 1000000000
	PI       = 3.14159265358979323846264
)

var a [1010101]int

func solve() int {
	var n int
	fmt.Scan(&n)
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
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
					ans = int(math.Min(float64(ans), float64(j+r)))
					break
				}
			}
		}
	}
	if ans == INF {
		ans = 0
	}
	fmt.Println(ans - 1)
	return 0
}

func main() {
	solve()
}
