package main

import (
	"fmt"
)

func solve() int {
	var x, y, i, j, k, res int
	ch := getchar()
	if ch == '0' {
		return 1 << 0
	}
	if ch == '1' {
		return 1 << 15
	}
	if ch == '?' {
		return (1 << 3) | (1 << 12)
	}

	x = solve()
	ch = getchar()
	y = solve()

	for i = 0; i < 16; i++ {
		if !_1(x, i) {
			continue
		}
		for j = 0; j < 16; j++ {
			if !_1(y, j) {
				continue
			}
			if ch == '^' {
				k = i ^ j
			}
			if ch == '&' {
				k = i & j
			}
			if ch == '|' {
				k = i | j
			}
			res |= 1 << k
		}
	}
	getchar()
	return res
}

func main() {
	var T int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		if ~0x8421&solve() != 0 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
