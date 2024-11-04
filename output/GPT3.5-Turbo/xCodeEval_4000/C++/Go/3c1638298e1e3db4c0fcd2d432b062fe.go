package main

import (
	"fmt"
)

const mod = 998244353

type Mint int

func (m Mint) inv() Mint {
	return m.pow(mod - 2)
}

func (m Mint) pow(n int) Mint {
	res := Mint(1)
	x := m
	for n > 0 {
		if n&1 == 1 {
			res *= x
		}
		x *= x
		n >>= 1
	}
	return res
}

func (m Mint) fact() Mint {
	res := Mint(1)
	for i := Mint(2); i <= m; i++ {
		res *= i
	}
	return res
}

func (m Mint) comb(n, k int) Mint {
	if k > n {
		return Mint(0)
	}
	numerator := Mint(1)
	denominator := Mint(1)
	for i := Mint(0); i < Mint(k); i++ {
		numerator *= Mint(n - i)
		denominator *= Mint(i + 1)
	}
	return numerator / denominator
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	if k >= n {
		fmt.Println(0)
		return
	}
	ans := Mint(0)
	for i := 0; i <= n-k; i++ {
		sign := Mint(1)
		if (n-k-i)%2 == 1 {
			sign = -1
		}
		ans += sign * Mint(i).pow(n) * Mint(n-k).comb(i)
	}
	fmt.Println(Mint(1+(k > 0)) * ans * Mint(n).comb(n-k))
}
