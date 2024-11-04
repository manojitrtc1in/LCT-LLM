package main

import (
	"fmt"
	"math/big"
)

const md = 1e9 + 7

type Mint struct {
	value *big.Int
}

func NewMint(x int64) Mint {
	m := new(big.Int).SetInt64(x % md)
	if m.Sign() < 0 {
		m.Add(m, big.NewInt(md))
	}
	return Mint{value: m}
}

func (m Mint) Add(other Mint) Mint {
	return NewMint(m.value.Add(m.value, other.value).Int64())
}

func (m Mint) Sub(other Mint) Mint {
	return NewMint(m.value.Sub(m.value, other.value).Int64())
}

func (m Mint) Mul(other Mint) Mint {
	return NewMint(m.value.Mul(m.value, other.value).Int64())
}

func (m Mint) Value() int64 {
	return m.value.Int64()
}

func main() {
	var tt int
	fmt.Scan(&tt)

	for i := 0; i < tt; i++ {
		var m int64
		fmt.Scan(&m)

		d := make([]int, 123)
		len := 0
		for m > 0 {
			d[len] = int(m & 1)
			m >>= 1
			len++
		}

		dp := make([]Mint, 7)
		newDp := make([]Mint, 7)
		dp[0] = NewMint(1)

		for it := len - 1; it >= 0; it-- {
			if d[it] == 0 {
				newDp[0] = dp[0].Add(dp[1]).Add(dp[2]).Add(dp[3])
				newDp[1] = newDp[2].Add(dp[1]).Add(dp[2]).Add(dp[3]).Add(dp[4])
				newDp[3] = newDp[4].Add(dp[2]).Add(dp[3]).Add(dp[4]).Add(dp[5])
				newDp[5] = newDp[6].Add(dp[3]).Add(dp[4]).Add(dp[5]).Add(dp[6])
			} else {
				newDp[0] = newDp[1].Add(dp[0]).Add(dp[1]).Add(dp[2]).Add(dp[3])
				newDp[2] = newDp[3].Add(dp[1]).Add(dp[2]).Add(dp[3]).Add(dp[4])
				newDp[4] = newDp[5].Add(dp[2]).Add(dp[3]).Add(dp[4]).Add(dp[5])
				newDp[6] = dp[3].Add(dp[4]).Add(dp[5]).Add(dp[6])
			}
			dp, newDp = newDp, dp
		}
		fmt.Println(dp[0].Value())
	}
}
