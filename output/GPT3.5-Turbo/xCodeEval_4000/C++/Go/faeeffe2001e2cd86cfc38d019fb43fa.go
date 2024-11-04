package main

import (
	"fmt"
	"math/big"
)

func alpha(n int) *big.Int {
	cnt := big.NewInt(10)
	res := big.NewInt(1)
	for i := 0; i < min(n, 11); i++ {
		res.Mul(res, cnt)
		cnt.Sub(cnt, big.NewInt(1))
		if cnt.Cmp(big.NewInt(0)) == -1 {
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
		if cnt.Cmp(big.NewInt(0)) == -1 {
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
		return new(big.Int).Mul(new(big.Int).Mul(x, x), n)
	} else {
		return new(big.Int).Mul(x, x)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var s string
	fmt.Scan(&s)

	bits := big.NewInt(0)
	cnt := 0
	leading := s[0]
	lead := true
	if isDigit(leading) {
		lead = false
	}

	for i := 0; i < len(s); i++ {
		if isAlpha(s[i]) {
			bits.SetBit(bits, int(s[i]-'A'), 1)
		} else if s[i] == '?' {
			cnt++
		}
	}

	var res *big.Int

	if !lead {
		res = new(big.Int).Mul(alpha(bits.BitLen()), power(big.NewInt(10), cnt))
	} else {
		if leading == '?' {
			res = new(big.Int).Mul(alpha(bits.BitLen()), power(big.NewInt(10), cnt-1))
			res.Mul(res, big.NewInt(9))
		} else {
			res = new(big.Int).Mul(beta(bits.BitLen()), power(big.NewInt(10), cnt))
		}
	}

	fmt.Println(res)
}
