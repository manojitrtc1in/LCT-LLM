package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := 310000000
	m := 100000

	l := nextInt(scanner)
	r := nextInt(scanner) + 1
	res := calc(r) - calc(l)
	fmt.Println(res)
}

func calc(l int) int64 {
	m := 100000
	to := l / m
	var res int64 = 0
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
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
