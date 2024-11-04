package main

import (
	"fmt"
	"math"
)

func solve() int {
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

	x := solve()
	fmt.Scanf("%c\n", &ch)
	y := solve()

	res := 0
	for i := 0; i < 16; i++ {
		if x&^(1<<i) == 0 {
			continue
		}
		for j := 0; j < 16; j++ {
			if y&^(1<<j) == 0 {
				continue
			}
			var k int
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
	var n int
	fmt.Scan(&n)
	if ^0x8421&solve() != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
