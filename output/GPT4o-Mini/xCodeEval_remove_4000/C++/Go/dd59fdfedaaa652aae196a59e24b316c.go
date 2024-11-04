package main

import (
	"fmt"
	"math"
)

const MOD = 1000000007
const INF = 0x3f3f3f3f
const id0 = 0x3f3f3f3f3f3f3f3f
const EPS = 1e-8
const OO = 1e15
const PI = math.Pi

func checkMin(a *int, b int) {
	if b < *a {
		*a = b
	}
}

func checkMax(a *int, b int) {
	if b > *a {
		*a = b
	}
}

func lowBit(x int) int {
	return x & -x
}

func highBit(x int) int {
	p := lowBit(x)
	for p != x {
		x -= p
		p = lowBit(x)
	}
	return p
}

func countBits(x int) int {
	x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1)
	x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2)
	x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4)
	x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8)
	x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16)
	return x
}

func solve() int {
	var x, y int
	var ch byte
	fmt.Scanf("%c", &ch)
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
	fmt.Scanf("%c", &ch)
	y = solve()
	fmt.Scanf("%c")

	res := 0
	for i := 0; i < 16; i++ {
		if (x & (1 << i)) != 0 {
			for j := 0; j < 16; j++ {
				if (y & (1 << j)) != 0 {
					var k int
					switch ch {
					case '^':
						k = i ^ j
					case '&':
						k = i & j
					case '|':
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
	var n int
	fmt.Scanf("%d", &n)
	if ^0x8421&solve() != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
