package main

import (
	"fmt"
)

func solve() int {
	var n int
	fmt.Scan(&n)

	a := make([]int, n+2)
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
					ans = min(ans, j+r)
					break
				}
			}
		}
	}

	if ans == INF {
		ans = 0
	}

	return ans - 1
}

func main() {
	fmt.Println(solve())
}
