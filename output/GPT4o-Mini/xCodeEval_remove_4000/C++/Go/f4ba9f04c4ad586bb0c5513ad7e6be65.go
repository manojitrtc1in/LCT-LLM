package main

import (
	"fmt"
	"math/rand"
	"time"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = int(1e9) + 7
	EPS     = 1e-9
	PI      = 3.141592653589793
	CR      = 7
	BITS    = 15
)

type Mint struct {
	val int
}

func NewMint(v int64) Mint {
	if v < 0 {
		v = v%int64(MOD) + int64(MOD)
	}
	if v >= int64(MOD) {
		v %= int64(MOD)
	}
	return Mint{val: int(v)}
}

func (m Mint) Inv() Mint {
	return NewMint(int64(invMod(m.val, MOD)))
}

func invMod(a, m int) int {
	g, r, x, y := m, a, 0, 1
	for r != 0 {
		q := g / r
		g, r = r, g%r
		x, y = y, x-q*y
	}
	if x < 0 {
		x += m
	}
	return x
}

func (m Mint) Pow(p int64) Mint {
	if p < 0 {
		return m.Inv().Pow(-p)
	}
	a, result := m, NewMint(1)
	for p > 0 {
		if p&1 != 0 {
			result = result.Mul(a)
		}
		a = a.Mul(a)
		p >>= 1
	}
	return result
}

func (m Mint) Mul(other Mint) Mint {
	return NewMint(int64(m.val) * int64(other.val) % int64(MOD))
}

func (m Mint) Add(other Mint) Mint {
	return NewMint(int64(m.val) + int64(other.val) - int64(MOD))
}

func (m Mint) Sub(other Mint) Mint {
	return NewMint(int64(m.val) - int64(other.val))
}

var (
	n   int64
	dp  [CR][BITS + 1][CR][1 << BITS]Mint
	cnt [CR][CR][1 << BITS]Mint
	dp2 [5][CR]Mint
)

func precalc() {
	for i := range dp {
		for j := range dp[i] {
			for k := range dp[i][j] {
				for l := range dp[i][j][k] {
					dp[i][j][k][l] = NewMint(0)
				}
			}
		}
	}
	for i := 0; i < CR; i++ {
		dp[i][0][i][0] = NewMint(1)
	}
	for cs := 0; cs < CR; cs++ {
		for i := 0; i < BITS; i++ {
			for ct := 0; ct < CR; ct++ {
				for x := 0; x < 1<<BITS; x++ {
					if dp[cs][i][ct][x].val != 0 {
						for cc := 0; cc <= CR; cc++ {
							dp[cs][i+1][(ct+cc)/2][(((ct+cc)%2)<<i)|x] = dp[cs][i+1][(ct+cc)/2][(((ct+cc)%2)<<i)|x].Add(dp[cs][i][ct][x])
						}
					}
				}
			}
		}
	}
	for i := 0; i < CR; i++ {
		for j := 0; j < CR; j++ {
			for x := 0; x < 1<<BITS; x++ {
				cnt[i][j][x] = dp[i][BITS][j][x]
			}
		}
	}
}

func solve() {
	for i := range dp2 {
		for j := range dp2[i] {
			dp2[i][j] = NewMint(0)
		}
	}
	dp2[0][0] = NewMint(1)
	for i := 0; i < 4; i++ {
		x := n & ((1 << BITS) - 1)
		n >>= BITS
		for j := 0; j < CR; j++ {
			for k := 0; k < CR; k++ {
				dp2[i+1][k] = dp2[i+1][k].Add(dp2[i][j].Mul(cnt[j][k][x]))
			}
		}
	}
	fmt.Println(dp2[4][0].val)
}

func read() bool {
	_, err := fmt.Scan(&n)
	return err == nil
}

func main() {
	rand.Seed(time.Now().UnixNano())
	precalc()

	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		tc--
		if read() {
			solve()
		}
	}
}
