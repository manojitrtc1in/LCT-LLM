package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() int {
	var x, y, i, j, k, res int
	ch := getChar()
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
	ch = getChar()
	y = solve()

	for i = 0; i < 16; i++ {
		if x&(1<<i) == 0 {
			continue
		}
		for j = 0; j < 16; j++ {
			if y&(1<<j) == 0 {
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
	getChar()
	return res
}

func getChar() byte {
	reader := bufio.NewReader(os.Stdin)
	ch, _ := reader.ReadByte()
	return ch
}

func main() {
	var T int
	fmt.Scan(&T)
	for T > 0 {
		T--
		if (~0x8421 & solve()) != 0 {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}
