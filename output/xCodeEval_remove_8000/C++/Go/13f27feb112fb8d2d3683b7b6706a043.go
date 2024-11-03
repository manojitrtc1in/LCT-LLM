package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve() int {
	ch, _ := reader.ReadByte()
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
	ch, _ = reader.ReadByte()
	y := solve()

	var k, res int
	for i := 0; i < 16; i++ {
		if x&(1<<i) == 0 {
			continue
		}
		for j := 0; j < 16; j++ {
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
	reader.ReadByte()
	return res
}

func main() {
	var N int
	fmt.Scanln(&N)

	e := solve()
	if ^0x8241&e != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

var reader = bufio.NewReader(os.Stdin)
