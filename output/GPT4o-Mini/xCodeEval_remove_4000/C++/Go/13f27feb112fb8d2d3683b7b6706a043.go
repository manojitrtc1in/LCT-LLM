package main

import (
	"fmt"
	"math"
)

const N = 1000009

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

	for i := 0; i < 16; i++ {
		if x&^(1<<i) != 0 {
			continue
		}
		for j := 0; j < 16; j++ {
			if y&^(1<<j) != 0 {
				continue
			}
			switch ch {
			case '^':
				k = i ^ j
			case '&':
				k = i & j
			case '|':
				k = i | j
			}
			res |= 1 << k
		}
	}
	return res
}

func main() {
	var N int
	fmt.Scanf("%d\n", &N)
	res := ^0x8241 & solve()
	if res != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
