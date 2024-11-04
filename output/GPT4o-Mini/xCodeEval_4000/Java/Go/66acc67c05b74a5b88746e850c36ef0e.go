package main

import (
	"bufio"
	"fmt"
	"os"
)

var mod int64 = 1000000007

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

func gcd(x, y int64) int64 {
	if x%y == 0 {
		return y
	}
	return gcd(y, x%y)
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

func nextPowerOf2(a int) int {
	b := 1
	for b < a {
		b <<= 1
	}
	return b
}

func maxSubArraySum(a []int) int {
	size := len(a)
	maxSoFar := int(^uint(0) >> 1) // Integer.MIN_VALUE
	maxEndingHere := 0

	for i := 0; i < size; i++ {
		maxEndingHere += a[i]
		if maxSoFar < maxEndingHere {
			maxSoFar = maxEndingHere
		}
		if maxEndingHere < 0 {
			maxEndingHere = 0
		}
	}
	return maxSoFar
}

func radixSort(f []int) []int {
	n := len(f)
	to := make([]int, n)

	// Sort by lower 16 bits
	b := make([]int, 65537)
	for i := 0; i < n; i++ {
		b[1+(f[i]&0xffff)]++
	}
	for i := 1; i <= 65536; i++ {
		b[i] += b[i-1]
	}
	for i := 0; i < n; i++ {
		to[b[f[i]&0xffff]] = f[i]
		b[f[i]&0xffff]++
	}
	f, to = to, f

	// Sort by upper 16 bits
	b = make([]int, 65537)
	for i := 0; i < n; i++ {
		b[1+(f[i]>>16)]++
	}
	for i := 1; i <= 65536; i++ {
		b[i] += b[i-1]
	}
	for i := 0; i < n; i++ {
		to[b[f[i]>>16]] = f[i]
		b[f[i]>>16]++
	}
	return to
}
