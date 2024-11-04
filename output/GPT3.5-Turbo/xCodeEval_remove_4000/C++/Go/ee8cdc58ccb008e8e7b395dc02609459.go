package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sc = bufio.NewScanner(os.Stdin)

func scanString() string {
	sc.Scan()
	return sc.Text()
}

func scanInt() int {
	x, _ := strconv.Atoi(scanString())
	return x
}

func scanInt64() int64 {
	x, _ := strconv.ParseInt(scanString(), 10, 64)
	return x
}

func scanFloat() float64 {
	x, _ := strconv.ParseFloat(scanString(), 64)
	return x
}

func printString(s string) {
	fmt.Println(s)
}

func printInt(x int) {
	fmt.Println(x)
}

func printInt64(x int64) {
	fmt.Println(x)
}

func printFloat(x float64) {
	fmt.Println(x)
}

func main() {
	n := scanInt()
	fact := make([]int64, n+101)
	fact[0] = 1
	for i := 0; i < n+100; i++ {
		fact[i+1] = fact[i] * int64(i+1)
	}
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = scanInt()
		for j := 2; j*j <= v[i]; j++ {
			for v[i]%j == 0 && (v[i]/j)%j == 0 {
				v[i] /= j
				v[i] /= j
			}
		}
	}
	cnt := make(map[int]int)
	for _, x := range v {
		cnt[x]++
	}
	c := make([]int, 0)
	for _, val := range cnt {
		c = append(c, val)
	}

	dp := make([]int64, n+10)
	dp[0] = 1
	for _, x := range c {
		ndp := make([]int64, n+10)
		for i := 0; i < len(dp); i++ {
			if dp[i] != 0 {
				for j := 0; j < x; j++ {
					dist := x - j
					ndp[i+dist] += dp[i] * binom(x-1, j) * binom(i+dist, dist)
				}
			}
		}
		dp = ndp
	}

	conds := n - len(c)

	final := int64(0)
	sign := int64(1)
	for i := 0; i <= conds; i++ {
		final += sign * dp[n-i]
		sign = int64(-1) * sign
	}
	for _, x := range c {
		final *= fact[x]
	}
	printInt64(final)
}

func binom(n, k int) int64 {
	if k > n {
		return int64(0)
	}
	return fact[n] / (fact[n-k] * fact[k])
}
