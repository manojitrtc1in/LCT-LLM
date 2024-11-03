package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var scanner *bufio.Scanner
var writer *bufio.Writer

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	g := readInt()
	sh := readInt()
	j := readInt()
	p := readInt()
	priceFirst := readInt()
	priceSecond := readInt()
	answer := int64(0)
	if priceFirst <= priceSecond {
		answer = min(min(sh, j), p)
		p -= answer
		answer *= int64(priceSecond)
		answer += int64(min(p, g) * priceFirst)
	} else {
		answer = int64(min(g, p))
		p -= answer
		answer *= int64(priceFirst)
		answer += int64(min(min(sh, j), p) * priceSecond)
	}
	fmt.Println(answer)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readInts() []int {
	scanner.Scan()
	nums := strings.Split(scanner.Text(), " ")
	res := make([]int, len(nums))
	for i, num := range nums {
		res[i], _ = strconv.Atoi(num)
	}
	return res
}
