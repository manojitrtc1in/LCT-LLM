package main

import (
	"bufio"
	"fmt"
	"os"
)

var (
	count, mod int64 = 0, 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	soln(reader, writer)
}

func soln(reader *bufio.Reader, writer *bufio.Writer) {
	var a, b, x, y, z int64
	fmt.Fscan(reader, &a, &b, &x, &y, &z)
	var ans int64 = 0

	if a < 2*x {
		ans += 2*x - a
		a = 0
	} else {
		a -= 2 * x
	}

	if b < 3*z {
		ans += 3*z - b
		b = 0
	} else {
		b -= 3 * z
	}

	if a < b {
		y -= a
		if y < 0 {
			y = 0
		}
		b -= a
		a = 0
	} else {
		y -= b
		if y < 0 {
			y = 0
		}
		b = a - b
		a = 0
	}

	if y > b {
		ans += b + 2*(y-b)
	} else {
		ans += y
	}

	fmt.Fprintln(writer, ans)
}

func isPrime(n int) bool {
	if n <= 1 {
		return false
	}
	if n <= 3 {
		return true
	}
	if n%2 == 0 || n%3 == 0 {
		return false
	}
	for i := 5; i*i <= n; i += 6 {
		if n%i == 0 || n%(i+2) == 0 {
			return false
		}
	}
	return true
}

func gcd(x, y int64) int64 {
	if x%y == 0 {
		return y
	}
	return gcd(y, x%y)
}

func pow(n, p, m int64) int64 {
	result := int64(1)
	if p == 0 {
		return 1
	}
	if p == 1 {
		return n
	}
	for p != 0 {
		if p%2 == 1 {
			result *= n
			if result >= m {
				result %= m
			}
		}
		p >>= 1
		n *= n
		if n >= m {
			n %= m
		}
	}
	return result
}

func reverseString(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}
