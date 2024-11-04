package main

import (
	"fmt"
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
		if !isOne(x, i) {
			continue
		}
		for j := 0; j < 16; j++ {
			if !isOne(y, j) {
				continue
			}
			var k int
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
	return res
}

func isOne(x int, i int) bool {
	return x&(1<<i) != 0
}

func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	if ^0x8421&solve() != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
