package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)

	CR   = 7
	BITS = 15
)

type pt struct {
	x, y int
}

type Mint struct {
	val int
}

func newMint(v int64) Mint {
	if v < 0 {
		v = v%MOD + MOD
	}
	if v >= MOD {
		v %= MOD
	}
	return Mint{int(v)}
}

func newMintFromUint(v uint64) Mint {
	if v >= MOD {
		v %= MOD
	}
	return Mint{int(v)}
}

func newMintFromInt(v int) Mint {
	return newMint(int64(v))
}

func newMintFromUint(v uint) Mint {
	return newMintFromUint(uint64(v))
}

func (m Mint) invMod(a int, m int) int {
	g := m
	r := a
	x := 0
	y := 1

	for r != 0 {
		q := g / r
		g %= r
		g, r = r, g
		x -= q * y
		x, y = y, x
	}

	if x < 0 {
		x += m
	}
	return x
}

func (m Mint) inv() Mint {
	return newMint(m.invMod(m.val, MOD))
}

func (m Mint) pow(p int64) Mint {
	if p < 0 {
		return m.inv().pow(-p)
	}

	a := m
	result := newMintFromInt(1)

	for p > 0 {
		if p&1 == 1 {
			result *= a
		}
		a *= a
		p >>= 1
	}

	return result
}

func (m Mint) toInt() int {
	return m.val
}

func (m Mint) toUint() uint {
	return uint(m.val)
}

func (m Mint) toInt64() int64 {
	return int64(m.val)
}

func (m Mint) toUint64() uint64 {
	return uint64(m.val)
}

func (m Mint) toFloat64() float64 {
	return float64(m.val)
}

func (m Mint) toFloat80() float80 {
	return float80(m.val)
}

func (m Mint) add(other Mint) Mint {
	m.val -= MOD - other.val
	if m.val < 0 {
		m.val += MOD
	}
	return m
}

func (m Mint) sub(other Mint) Mint {
	m.val -= other.val
	if m.val < 0 {
		m.val += MOD
	}
	return m
}

func (m Mint) mul(other Mint) Mint {
	m.val = fastMod(uint64(m.val)*uint64(other.val))
	return m
}

func (m Mint) div(other Mint) Mint {
	return m.mul(other.inv())
}

func (m Mint) inc() Mint {
	m.val = (m.val + 1) % MOD
	return m
}

func (m Mint) dec() Mint {
	m.val = (m.val - 1 + MOD) % MOD
	return m
}

func (m Mint) neg() Mint {
	if m.val == 0 {
		return Mint{0}
	}
	return Mint{MOD - m.val}
}

func (m Mint) equals(other Mint) bool {
	return m.val == other.val
}

func (m Mint) notEquals(other Mint) bool {
	return m.val != other.val
}

func (m Mint) lessThan(other Mint) bool {
	return m.val < other.val
}

func (m Mint) greaterThan(other Mint) bool {
	return m.val > other.val
}

func (m Mint) lessThanOrEqual(other Mint) bool {
	return m.val <= other.val
}

func (m Mint) greaterThanOrEqual(other Mint) bool {
	return m.val >= other.val
}

func (m Mint) String() string {
	return fmt.Sprintf("%d", m.val)
}

func fastMod(x uint64, m int) uint {
	return uint(x % uint64(m))
}

func fastMod(x uint64) uint {
	return fastMod(x, MOD)
}

func precalc() [CR][CR][1 << BITS]Mint {
	dp := [CR][BITS + 1][CR][1 << BITS]Mint{}
	cnt := [CR][CR][1 << BITS]Mint{}

	for i := 0; i < CR; i++ {
		dp[i][0][i][0] = newMintFromInt(1)
	}

	for cs := 0; cs < CR; cs++ {
		for i := 0; i < BITS; i++ {
			for ct := 0; ct < CR; ct++ {
				for x := 0; x < 1<<BITS; x++ {
					if dp[cs][i][ct][x] != 0 {
						for cc := 0; cc < CR+1; cc++ {
							dp[cs][i+1][(ct+cc)/2][(((ct+cc)%2)<<i)|x] += dp[cs][i][ct][x]
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

	return cnt
}

func solve(n int64, cnt [CR][CR][1 << BITS]Mint) int {
	dp2 := [5][CR]Mint{}
	dp2[0][0] = newMintFromInt(1)

	for i := 0; i < 4; i++ {
		x := n & ((1 << BITS) - 1)
		n >>= BITS

		for j := 0; j < CR; j++ {
			for k := 0; k < CR; k++ {
				dp2[i+1][k] += dp2[i][j].mul(cnt[j][k][x])
			}
		}
	}

	return dp2[4][0].toInt()
}

func main() {
	rand.Seed(time.Now().UnixNano())

	precalc := precalc()

	var tc int
	fmt.Scan(&tc)

	for tc > 0 {
		var n int64
		fmt.Scan(&n)

		result := solve(n, precalc)
		fmt.Println(result)

		tc--
	}
}
