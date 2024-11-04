package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type pt struct {
	x, y int
}

func (a pt) String() string {
	return fmt.Sprintf("(%d, %d)", a.x, a.y)
}

func (v pt) String() string {
	out := "["
	for i := 0; i < len(v); i++ {
		if i > 0 {
			out += ", "
		}
		out += fmt.Sprint(v[i])
	}
	return out + "]"
}

var rnd = rand.New(rand.NewSource(time.Now().UnixNano()))

const (
	INF   = int(1e9)
	INF64 = int64(1e18)
	MOD   = int(1e9) + 7
	EPS   = 1e-9
	PI    = math.Acos(-1.0)

	CR   = 7
	BITS = 15
)

var n int64

func read() bool {
	_, err := fmt.Scan(&n)
	return err == nil
}

type mint struct {
	val int
}

func newMint(v int64) mint {
	if v < 0 {
		v = v%MOD + MOD
	}
	if v >= MOD {
		v %= MOD
	}
	return mint{int(v)}
}

func (a mint) invMod(m int) int {
	g, r, x, y := m, a.val, 0, 1

	for r != 0 {
		q := g / r
		g, r = r, g-q*r
		x, y = y, x-q*y
	}

	if x < 0 {
		x += m
	}
	return x
}

func (a mint) inv() mint {
	return newMint(int64(a.invMod(MOD)))
}

func (a mint) pow(p int64) mint {
	if p < 0 {
		return a.inv().pow(-p)
	}

	res := mint{1}
	for p > 0 {
		if p&1 == 1 {
			res = res.mul(a)
		}
		a = a.mul(a)
		p >>= 1
	}
	return res
}

func (a mint) add(b mint) mint {
	res := a.val + b.val
	if res >= MOD {
		res -= MOD
	}
	return mint{res}
}

func (a mint) sub(b mint) mint {
	res := a.val - b.val
	if res < 0 {
		res += MOD
	}
	return mint{res}
}

func (a mint) mul(b mint) mint {
	return mint{int(int64(a.val) * int64(b.val) % int64(MOD))}
}

func (a mint) div(b mint) mint {
	return a.mul(b.inv())
}

func (a mint) inc() mint {
	a.val++
	if a.val == MOD {
		a.val = 0
	}
	return a
}

func (a mint) dec() mint {
	if a.val == 0 {
		a.val = MOD - 1
	} else {
		a.val--
	}
	return a
}

func (a mint) neg() mint {
	if a.val == 0 {
		return mint{0}
	}
	return mint{MOD - a.val}
}

func (a mint) equal(b mint) bool {
	return a.val == b.val
}

func (a mint) notEqual(b mint) bool {
	return a.val != b.val
}

func (a mint) lessThan(b mint) bool {
	return a.val < b.val
}

func (a mint) greaterThan(b mint) bool {
	return a.val > b.val
}

func (a mint) lessThanOrEqual(b mint) bool {
	return a.val <= b.val
}

func (a mint) greaterThanOrEqual(b mint) bool {
	return a.val >= b.val
}

func (a mint) String() string {
	return fmt.Sprint(a.val)
}

var dp [CR][BITS + 1][CR][1 << BITS]mint
var cnt [CR][CR][1 << BITS]mint

func precalc() {
	for i := 0; i < CR; i++ {
		for j := 0; j <= BITS; j++ {
			for k := 0; k < CR; k++ {
				for x := 0; x < 1<<BITS; x++ {
					dp[i][j][k][x] = mint{0}
				}
			}
		}
	}

	for i := 0; i < CR; i++ {
		dp[i][0][i][0] = mint{1}
	}

	for cs := 0; cs < CR; cs++ {
		for i := 0; i < BITS; i++ {
			for ct := 0; ct < CR; ct++ {
				for x := 0; x < 1<<BITS; x++ {
					if dp[cs][i][ct][x].val != 0 {
						for cc := 0; cc <= CR; cc++ {
							dp[cs][i+1][(ct+cc)/2][(((ct+cc)%2)<<i)|x] = dp[cs][i+1][(ct+cc)/2][(((ct+cc)%2)<<i)|x].add(dp[cs][i][ct][x])
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

var dp2 [5][CR]mint

func solve() {
	for i := 0; i < 5; i++ {
		for j := 0; j < CR; j++ {
			dp2[i][j] = mint{0}
		}
	}
	dp2[0][0] = mint{1}

	for i := 0; i < 4; i++ {
		x := n & ((1 << BITS) - 1)
		n >>= BITS
		for j := 0; j < CR; j++ {
			for k := 0; k < CR; k++ {
				dp2[i+1][k] = dp2[i+1][k].add(dp2[i][j].mul(cnt[j][k][x]))
			}
		}
	}

	fmt.Println(int(dp2[4][0]))
}

func main() {
	rand.Seed(time.Now().UnixNano())

	var tc int
	fmt.Scan(&tc)

	for tc > 0 {
		read()
		solve()
		tc--
	}
}
