package main

import (
	"fmt"
)

type Mint int64

const MOD Mint = 1000000007

func (m Mint) Val() int64 {
	return int64(m)
}

func (m Mint) Mul(n Mint) Mint {
	return (m * n) % MOD
}

func (m Mint) Add(n Mint) Mint {
	return (m + n) % MOD
}

func main() {
	var q int64
	fmt.Scan(&q)
	for q > 0 {
		q--
		var n int64
		fmt.Scan(&n)
		M := n/4 + 1
		m := Mint(M)
		if n%4 <= 1 {
			fmt.Println(m.Mul(m).Val())
		} else {
			fmt.Println(m.Mul(m.Add(1)).Val())
		}
	}
}
