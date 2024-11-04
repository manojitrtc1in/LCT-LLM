package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func initIO() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func scanInt() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func scanLong() int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func scanString() string {
	scanner.Scan()
	return scanner.Text()
}

func println(a ...interface{}) {
	fmt.Fprintln(writer, a...)
}

func main() {
	initIO()
	run()
	flush()
}

func run() {
	// Your code here
}

func mul(a, b, p int64) int64 {
	res := int64(0)
	base := a
	for b > 0 {
		if (b & 1) > 0 {
			res = (res + base) % p
		}
		base = (base + base) % p
		b >>= 1
	}
	return res
}

func modPow(k, n, p int64) int64 {
	res := int64(1)
	temp := k
	for n != 0 {
		if (n & 1) == 1 {
			res = (res * temp) % p
		}
		temp = (temp * temp) % p
		n = n >> 1
	}
	return res % p
}

