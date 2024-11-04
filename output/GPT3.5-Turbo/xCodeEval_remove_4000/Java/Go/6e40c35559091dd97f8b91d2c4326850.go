package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int64
	var k int
	fmt.Fscan(reader, &n)
	fmt.Fscan(reader, &k)

	fib := make([]int, 200)
	fib[0] = 1
	fib[1] = 2
	a := make([]int, 200)
	for i := 2; i < 200; i++ {
		fib[i] = (fib[i-1] + fib[i-2]) % mod
	}
	for i := 0; i < 200; i++ {
		a[i] = (fib[i] * pow(i+1, k)) % mod
		if i > 0 {
			a[i] = (a[i] + a[i-1]) % mod
		}
	}

	seq := make([]int, len(a))
	copy(seq, a)
	ans := solve(n-1, seq)

	fmt.Fprintln(writer, ans)
}

func solve(k int64, a []int) int {
	if k < int64(len(a)) {
		return a[k]
	}

	coe := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		coe[i] = -a[i]
	}

	p := make([]int, len(coe)+1)
	for i := len(coe) - 1; i >= 0; i-- {
		p[i] = coe[i]
	}
	p[len(p)-1] = 1

	remainder := make([]int, len(coe))
	for i := 0; i < len(coe); i++ {
		remainder[i] = coe[i]
	}

	for i := len(coe) - 1; i <= int(k); i++ {
		dn := estimateDelta(coe, remainder)
		if dn == 0 {
			break
		}

		buf := make([]int, len(p))
		copy(buf, p)

		factor := (dn * pow(dm, mod-2)) % mod

		for j := i - m; j < i-m+len(coe); j++ {
			buf[j] = (buf[j] - (factor * coe[j-(i-m)])%mod + mod) % mod
		}

		if len(coe) < len(buf) {
			coe, p = p, coe
			m = i
			dm = dn
		} else {
			coe = buf
		}
	}

	return solve(a, coe)
}

func estimateDelta(coe, remainder []int) int {
	n := len(coe) - 1
	ans := 0
	for i := 0; i < len(remainder); i++ {
		ans = (ans + (coe[i]*remainder[n-i])%mod + mod) % mod
	}
	return ans
}

func solve(a, coe []int) int {
	ans := 0
	for i := 0; i < len(coe); i++ {
		ans = (ans + (coe[i]*a[i])%mod + mod) % mod
	}
	return ans
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = (r * r) % mod
	if n&1 == 1 {
		r = (r * x) % mod
	}
	return r
}
