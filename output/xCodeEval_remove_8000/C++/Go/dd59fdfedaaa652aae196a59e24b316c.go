package main

import (
	"fmt"
)

func solve() int {
	var x, y, k, res int
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
	getchar()

	for i := 0; i < 16; i++ {
		if _1(x, i) {
			for j := 0; j < 16; j++ {
				if _1(y, j) {
					if ch == '^' {
						k = i ^ j
					}
					if ch == '&' {
						k = i & j
					}
					if ch == '|' {
						k = i | j
					}
					res |= _1(k)
				}
			}
		}
	}

	return res
}

func main() {
	RD()
	if ^0x8421&solve() != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
