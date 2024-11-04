package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(scanner *bufio.Scanner) int {
	ch := scanner.Scan()
	if ch == "0" {
		return 1 << 0
	}
	if ch == "1" {
		return 1 << 15
	}
	if ch == "?" {
		return (1 << 3) | (1 << 12)
	}

	x := solve(scanner)
	ch = scanner.Scan()
	y := solve(scanner)

	res := 0
	for i := 0; i < 16; i++ {
		if x&(1<<i) == 0 {
			continue
		}
		for j := 0; j < 16; j++ {
			if y&(1<<j) == 0 {
				continue
			}
			if ch == "^" {
				res |= i ^ j
			}
			if ch == "&" {
				res |= i & j
			}
			if ch == "|" {
				res |= i | j
			}
		}
	}
	scanner.Scan()
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var N int
	fmt.Scan(&N)

	e := solve(scanner)
	if ^0x8241&e != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
