package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := 310000000
	m := 100000

	l := nextInt(scanner)
	r := nextInt(scanner) + 1
	res := calc(r, m) - calc(l, m)
	fmt.Println(res)
}

func calc(l, m int) int {
	to := l / m
	res := 0
	for i := 0; i < to; i++ {
		res += num[i]
	}
	for i := to * m; i < l; i++ {
		if isLucky(i) {
			res++
		}
	}
	return res
}

func isLucky(i int) bool {
	return i == 2 || isP(i) && i%4 == 1
}

func isP(i int) bool {
	if i < 2 {
		return false
	}
	for j := 2; j*j <= i; j++ {
		if i%j == 0 {
			return false
		}
	}
	return true
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num := 0
	for _, c := range scanner.Bytes() {
		num *= 10
		num += int(c - '0')
	}
	return num
}
