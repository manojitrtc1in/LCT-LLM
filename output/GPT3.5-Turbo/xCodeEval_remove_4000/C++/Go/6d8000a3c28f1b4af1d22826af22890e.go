package main

import (
	"fmt"
)

func mulmod(a, b, MOD int64) int64 {
	if b == 0 {
		return 0
	}
	res := mulmod(a, b>>1, MOD)
	res += res
	res %= MOD
	if b&1 == 1 {
		return (a + res) % MOD
	}
	return res
}

func gcd(a, b int) int {
	for a != 0 && b != 0 {
		if a > b {
			a %= b
		} else {
			b %= a
		}
	}
	return a + b
}

func gcd64(a, b int64) int64 {
	for a != 0 && b != 0 {
		if a > b {
			a %= b
		} else {
			b %= a
		}
	}
	return a + b
}

func main() {
