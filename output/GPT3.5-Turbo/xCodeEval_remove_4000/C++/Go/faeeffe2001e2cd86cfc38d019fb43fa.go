package main

import (
	"fmt"
	"math/big"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)

	leading := s[0]

	var bits [30]bool
	var cnt int
	lead := true

	if isDigit(leading) {
		lead = false
	}

	for _, ch := range s {
		if isAlpha(ch) {
			bits[ch-'A'] = true
		} else if ch == '?' {
			cnt++
		}
	}

	var res big.Int

	if !lead {
		res.Mul(alpha(countBits(bits[:])), power(big.NewInt(10), cnt))
	} else {
		if leading == '?' {
			res.Mul(alpha(countBits(bits[:])), power(big.NewInt(10), cnt-1))
			res.Mul(&res, big.NewInt(9))
		} else {
			res.Mul(beta(countBits(bits[:])), power(big.NewInt(10), cnt))
		}
	}

	fmt.Println(&res)
}

func isDigit(ch byte) bool {
	return ch >= '0' && ch <= '9'
}

func isAlpha(ch byte) bool {
	return ch >= 'A' && ch <= 'Z'
}

func countBits(bits []bool) int {
	count := 0
	for _, bit := range bits {
		if bit {
			count++
		}
	}
	return count
}

func alpha(n int) *big.Int {
	cnt := big.NewInt(10)
	res := big.NewInt(1)
	for i := 0; i < min(n, 11); i++ {
		res.Mul(res, cnt)
		cnt.Sub(cnt, big.NewInt(1))
		if cnt.Cmp(big.NewInt(0)) < 0 {
			cnt.SetInt64(0)
		}
	}
	return res
}

func beta(n int) *big.Int {
	cnt := big.NewInt(9)
	res := big.NewInt(9)
	for i := 0; i < min(n-1, 11); i++ {
		res.Mul(res, cnt)
		cnt.Sub(cnt, big.NewInt(1))
		if cnt.Cmp(big.NewInt(0)) < 0 {
			cnt.SetInt64(0)
		}
	}
	return res
}

func power(n *big.Int, p int) *big.Int {
	if p <= 0 {
		return big.NewInt(1)
	}

	x := power(n, p/2)

	if p&1 == 1 {
		return x.Mul(x, x).Mul(x, n)
	} else {
		return x.Mul(x, x)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
