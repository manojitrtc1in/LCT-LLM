package main

import (
	"fmt"
	"math"
)

const (
	INF     = int(1e9)
	INF64   = int64(1e18)
	MOD     = int(1e9) + 7
	CR      = 7
	BITS    = 15
)

var n int64
var dp [CR][BITS+1][CR][1 << BITS]int64
var cnt [CR][CR][1 << BITS]int64
var dp2 [5][CR]int64

func read() bool {
	_, err := fmt.Scan(&n)
	return err == nil
}

func precalc() {
	for i := range dp {
		for j := range dp[i] {
			for k := range dp[i][j] {
				for l := range dp[i][j][k] {
					dp[i][j][k][l] = 0
				}
			}
		}
	}

	for i := 0; i < CR; i++ {
		dp[i][0][i][0] = 1
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
}

func solve() {
	for i := range dp2 {
		for j := range dp2[i] {
			dp2[i][j] = 0
		}
	}

	dp2[0][0] = 1
	for i := 0; i < 4; i++ {
		x := int(n & ((1 << BITS) - 1))
		n >>= BITS
		for j := 0; j < CR; j++ {
			for k := 0; k < CR; k++ {
				dp2[i+1][k] += dp2[i][j] * cnt[j][k][x]
			}
		}
	}
	fmt.Println(dp2[4][0])
}

func main() {
	precalc()

	var tc int
	if _, err := fmt.Scan(&tc); err == nil {
		for i := 0; i < tc; i++ {
			if read() {
				solve()
			}
		}
	} else {
		for read() {
			solve()
		}
	}
}