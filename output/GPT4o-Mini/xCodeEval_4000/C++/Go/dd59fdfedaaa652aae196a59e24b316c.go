package main

import (
	"fmt"
)

func solve() int {
	var x, y, k, res int
	var ch byte
	fmt.Scanf("%c\n", &ch)

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
	fmt.Scanf("%c\n", &ch)
	y = solve()
	fmt.Scanf("%c", &ch)

	for i := 0; i < 16; i++ {
		if (x & (1 << i)) != 0 {
			for j := 0; j < 16; j++ {
				if (y & (1 << j)) != 0 {
					if ch == '^' {
						k = i ^ j
					}
					if ch == '&' {
						k = i & j
					}
					if ch == '|' {
						k = i | j
					}
					res |= (1 << k)
				}
			}
		}
	}

	return res
}

func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	if (^0x8421 & solve()) != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
