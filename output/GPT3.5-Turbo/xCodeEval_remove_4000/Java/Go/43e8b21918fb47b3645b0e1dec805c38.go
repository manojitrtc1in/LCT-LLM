package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextLong() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextDouble() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func main() {
	initIO()
	defer flush()

	// Your code here
}

func pow(x, y, p int64) int64 {
	res := int64(1)
	x = x % p

	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}

	return res
}

func modInverse(n, p int64) int64 {
	return pow(n, p-2, p)
}

func modDiv(a, b int64) int64 {
	return mod(a*modInverse(b, id32), id32)
}

func power(x, y, p int64) int64 {
	res := int64(1)
	x = x % p

	for y > 0 {
		if y&1 == 1 {
			res = (res * x) % p
		}
		y = y >> 1
		x = (x * x) % p
	}

	return res
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	} else {
		return gcd(b, a%b)
	}
}

func lcm(a, b int64) int64 {
	return (a * b) / gcd(a, b)
}

func isPrime(n int64) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := int64(5); i*i <= n; i = i + 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func main() {
	initIO()
	defer flush()

	// Your code here
}
