package main

import (
	"fmt"
	"math/big"
)

type Mint struct {
	value *big.Int
	mod   *big.Int
}

func NewMint(x int64, mod int64) *Mint {
	return &Mint{value: big.NewInt(x % mod), mod: big.NewInt(mod)}
}

func (m *Mint) Add(other *Mint) *Mint {
	return NewMint(m.value.Add(m.value, other.value).Mod(m.value, m.mod).Int64(), m.mod.Int64())
}

func (m *Mint) Set(x int64) {
	m.value.SetInt64(x % m.mod.Int64())
}

func (m *Mint) Get() int64 {
	return m.value.Int64()
}

func main() {
	var tt int
	fmt.Scan(&tt)

	for tt > 0 {
		tt--

		var m int64
		fmt.Scan(&m)

		d := make([]int, 123)
		len := 0
		for m > 0 {
			d[len] = int(m & 1)
			m >>= 1
			len++
		}

		dp := make([]*Mint, 7)
		newDp := make([]*Mint, 7)
		for i := 0; i <= 6; i++ {
			dp[i] = NewMint(0, 1_000_000_007)
			newDp[i] = NewMint(0, 1_000_000_007)
		}
		dp[0].Set(1)

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
			for i := 0; i <= 6; i++ {
				dp[i] = newDp[i]
			}
		}
		fmt.Println(dp[0].Get())
	}
}
