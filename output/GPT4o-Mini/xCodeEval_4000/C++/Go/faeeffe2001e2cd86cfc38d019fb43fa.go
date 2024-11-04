package main

import (
	"fmt"
	"math/big"
	"strings"
)

var (
	s      string
	bits   [30]bool
	cnt    int
	leading byte
	lead   = true
	res    *big.Int
)

func alpha(n int) *big.Int {
	cnt := big.NewInt(10)
	res := big.NewInt(1)
	for i := 0; i < min(n, 11); i++ {
		res.Mul(res, cnt)
		cnt = big.NewInt(max(cnt.Int64()-1, 0))
	}
	return res
}

func beta(n int) *big.Int {
	cnt := big.NewInt(9)
	res := big.NewInt(9)
	for i := 0; i < min(n-1, 11); i++ {
		res.Mul(res, cnt)
		cnt = big.NewInt(max(cnt.Int64()-1, 0))
	}
	return res
}

func power(n *big.Int, p int) *big.Int {
	if p <= 0 {
		return big.NewInt(1)
	}
	x := power(n, p/2)
	if p%2 == 1 {
		return new(big.Int).Mul(new(big.Int).Mul(x, x), n)
	}
	return new(big.Int).Mul(x, x)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Scan(&s)

	leading = s[0]

	if isDigit(leading) {
		lead = false
	}

	for _, char := range s {
		if isAlpha(char) {
			bits[char-'A'] = true
		} else if char == '?' {
			cnt++
		}
	}

	if !lead {
		res = new(big.Int).Mul(alpha(countTrue(bits[:])), power(big.NewInt(10), cnt))
	} else {
		if leading == '?' {
			res = new(big.Int).Mul(alpha(countTrue(bits[:])), power(big.NewInt(10), cnt-1))
			res.Mul(res, big.NewInt(9))
		} else {
			res = new(big.Int).Mul(beta(countTrue(bits[:])), power(big.NewInt(10), cnt))
		}
	}

	fmt.Println(res.String())
}

func isAlpha(c rune) bool {
	return c >= 'A' && c <= 'Z'
}

func isDigit(c byte) bool {
	return c >= '0' && c <= '9'
}

func countTrue(arr []bool) int {
	count := 0
	for _, v := range arr {
		if v {
			count++
		}
	}
	return count
}
