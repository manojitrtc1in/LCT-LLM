package main

import (
	"fmt"
	"math/big"
	"strings"
)

type InfInt struct {
	val *big.Int
}

func NewInfInt(value string) *InfInt {
	n := new(big.Int)
	n.SetString(value, 10)
	return &InfInt{val: n}
}

func (n *InfInt) String() string {
	return n.val.String()
}

func (n *InfInt) Multiply(other *InfInt) *InfInt {
	result := new(big.Int).Mul(n.val, other.val)
	return &InfInt{val: result}
}

func (n *InfInt) Power(exp int) *InfInt {
	result := new(big.Int).Exp(n.val, big.NewInt(int64(exp)), nil)
	return &InfInt{val: result}
}

func alpha(n int) *InfInt {
	cnt := big.NewInt(10)
	res := big.NewInt(1)
	for i := 0; i < min(n, 11); i++ {
		res.Mul(res, cnt)
		cnt.Sub(cnt, big.NewInt(1))
		if cnt.Cmp(big.NewInt(0)) < 0 {
			cnt.SetInt64(0)
		}
	}
	return &InfInt{val: res}
}

func beta(n int) *InfInt {
	cnt := big.NewInt(9)
	res := big.NewInt(9)
	for i := 0; i < min(n-1, 11); i++ {
		res.Mul(res, cnt)
		cnt.Sub(cnt, big.NewInt(1))
		if cnt.Cmp(big.NewInt(0)) < 0 {
			cnt.SetInt64(0)
		}
	}
	return &InfInt{val: res}
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

	var bits [30]bool
	cnt := 0
	leading := s[0]
	lead := true

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

	var res *InfInt
	if !lead {
		res = alpha(countTrue(bits[:])) .Multiply(NewInfInt("10").Power(cnt))
	} else {
		if leading == '?' {
			res = alpha(countTrue(bits[:])).Multiply(NewInfInt("10").Power(cnt - 1)).Multiply(NewInfInt("9"))
		} else {
			res = beta(countTrue(bits[:])).Multiply(NewInfInt("10").Power(cnt))
		}
	}

	fmt.Println(res.String())
}

func isDigit(c byte) bool {
	return c >= '0' && c <= '9'
}

func isAlpha(c rune) bool {
	return c >= 'A' && c <= 'Z'
}

func countTrue(bits []bool) int {
	count := 0
	for _, b := range bits {
		if b {
			count++
		}
	}
	return count
}
