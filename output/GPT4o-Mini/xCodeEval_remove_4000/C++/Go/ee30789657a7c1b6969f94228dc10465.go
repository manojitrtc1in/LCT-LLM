package main

import (
	"fmt"
	"math/rand"
	"time"
)

const mod = 1000000007
const MAX = 500050

type mint struct {
	x int64
}

func newMint(x int64) mint {
	return mint{(x%mod + mod) % mod}
}

func (a mint) neg() mint {
	return newMint(-a.x)
}

func (a *mint) add(b mint) {
	a.x += b.x
	if a.x >= mod {
		a.x -= mod
	}
}

func (a *mint) sub(b mint) {
	a.x += mod - b.x
	if a.x >= mod {
		a.x -= mod
	}
}

func (a *mint) mul(b mint) {
	a.x = (a.x * b.x) % mod
}

func (a mint) addConst(b mint) mint {
	res := newMint(a.x)
	res.add(b)
	return res
}

func (a mint) subConst(b mint) mint {
	res := newMint(a.x)
	res.sub(b)
	return res
}

func (a mint) mulConst(b mint) mint {
	res := newMint(a.x)
	res.mul(b)
	return res
}

func (a mint) pow(t int64) mint {
	if t == 0 {
		return newMint(1)
	}
	res := a.pow(t >> 1)
	res.mul(res)
	if t&1 == 1 {
		res.mul(a)
	}
	return res
}

func (a mint) inv() mint {
	return a.pow(mod - 2)
}

func (a *mint) div(b mint) {
	a.mul(b.inv())
}

var dp [65][2][2][2]int64

func solve() {
	var t int64
	fmt.Scan(&t)

	for i := 0; i < 61; i++ {
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				for l := 0; l < 2; l++ {
					dp[i][j][k][l] = 0
				}
			}
		}
	}
	dp[0][0][0][0] = 1

	for i := 0; i < 60; i++ {
		f2 := (t>>i)&1 == 1
		if f2 {
			dp[i+1][0][0][0] += dp[i][0][0][0]
			dp[i+1][1][0][0] += dp[i][0][0][0]
			dp[i+1][0][1][0] += dp[i][0][0][0]
			dp[i+1][1][1][0] += dp[i][0][0][0]
			dp[i+1][0][1][0] += dp[i][0][0][1]
			dp[i+1][1][1][0] += dp[i][0][0][1]
			dp[i+1][0][0][1] += dp[i][0][0][1]
			dp[i+1][1][0][1] += dp[i][0][0][1]
			dp[i+1][1][0][0] += dp[i][0][1][0]
			dp[i+1][0][1][0] += dp[i][0][1][0]
			dp[i+1][1][1][0] += dp[i][0][1][0]
			dp[i+1][0][0][1] += dp[i][0][1][0]
			dp[i+1][1][1][0] += dp[i][0][1][1]
			dp[i+1][0][0][1] += dp[i][0][1][1]
			dp[i+1][1][0][1] += dp[i][0][1][1]
			dp[i+1][0][1][1] += dp[i][0][1][1]
			dp[i+1][0][0][0] += dp[i][1][0][0]
			dp[i+1][1][0][0] += dp[i][1][0][0]
			dp[i+1][0][1][0] += dp[i][1][0][0]
			dp[i+1][1][1][0] += dp[i][1][0][0]
			dp[i+1][0][1][0] += dp[i][1][0][1]
			dp[i+1][1][1][0] += dp[i][1][0][1]
			dp[i+1][0][0][1] += dp[i][1][0][1]
			dp[i+1][1][0][1] += dp[i][1][0][1]
			dp[i+1][1][0][0] += dp[i][1][1][0]
			dp[i+1][0][1][0] += dp[i][1][1][0]
			dp[i+1][1][1][0] += dp[i][1][1][0]
			dp[i+1][0][0][1] += dp[i][1][1][0]
			dp[i+1][1][1][0] += dp[i][1][1][1]
			dp[i+1][0][0][1] += dp[i][1][1][1]
			dp[i+1][1][0][1] += dp[i][1][1][1]
			dp[i+1][0][1][1] += dp[i][1][1][1]
		} else {
			dp[i+1][0][0][0] += dp[i][0][0][0]
			dp[i+1][1][0][0] += dp[i][0][0][0]
			dp[i+1][0][1][0] += dp[i][0][0][0]
			dp[i+1][1][1][0] += dp[i][0][0][0]
			dp[i+1][0][1][0] += dp[i][0][0][1]
			dp[i+1][1][1][0] += dp[i][0][0][1]
			dp[i+1][0][0][1] += dp[i][0][0][1]
			dp[i+1][1][0][1] += dp[i][0][0][1]
			dp[i+1][1][0][0] += dp[i][0][1][0]
			dp[i+1][0][1][0] += dp[i][0][1][0]
			dp[i+1][1][1][0] += dp[i][0][1][0]
			dp[i+1][0][0][1] += dp[i][0][1][0]
			dp[i+1][1][1][0] += dp[i][0][1][1]
			dp[i+1][0][0][1] += dp[i][0][1][1]
			dp[i+1][1][0][1] += dp[i][0][1][1]
			dp[i+1][0][1][1] += dp[i][0][1][1]
			dp[i+1][1][0][0] += dp[i][1][0][0]
			dp[i+1][0][1][0] += dp[i][1][0][0]
			dp[i+1][1][1][0] += dp[i][1][0][0]
			dp[i+1][0][0][1] += dp[i][1][0][0]
			dp[i+1][1][1][0] += dp[i][1][0][1]
			dp[i+1][0][0][1] += dp[i][1][0][1]
			dp[i+1][1][0][1] += dp[i][1][0][1]
			dp[i+1][0][1][1] += dp[i][1][0][1]
			dp[i+1][0][1][0] += dp[i][1][1][0]
			dp[i+1][1][1][0] += dp[i][1][1][0]
			dp[i+1][0][0][1] += dp[i][1][1][0]
			dp[i+1][1][0][1] += dp[i][1][1][0]
			dp[i+1][0][0][1] += dp[i][1][1][1]
			dp[i+1][1][0][1] += dp[i][1][1][1]
			dp[i+1][0][1][1] += dp[i][1][1][1]
			dp[i+1][1][1][1] += dp[i][1][1][1]
		}
		for j := 0; j < 2; j++ {
			for k := 0; k < 2; k++ {
				for l := 0; l < 2; l++ {
					dp[i+1][j][k][l] %= mod
				}
			}
		}
	}

	fmt.Println(dp[60][0][0][0])
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var q int
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		solve()
	}
}
