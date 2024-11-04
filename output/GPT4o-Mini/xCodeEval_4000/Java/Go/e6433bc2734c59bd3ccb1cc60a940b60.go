package main

import (
	"bytes"
	"fmt"
	"io"
	"os"
)

type G3 struct {
	mod   int64
	n     int
	a     []int
	all   int64
	dp    [][][]int64
	sdp   []int64
	fif   [][]int64
	inv   []int64
}

func main() {
	g := G3{}
	g.run()
}

func (g *G3) run() {
	g.mod = 998244353
	g.n = g.ni()
	g.a = g.na(26)
	g.all = 26 * 26 * g.pow(25, int64(g.n-2), g.mod) % g.mod

	g.dp = make([][][]int64, 3)
	for i := range g.dp {
		g.dp[i] = make([][]int64, g.n+1)
		for j := range g.dp[i] {
			g.dp[i][j] = make([]int64, g.n+1)
		}
	}
	g.dp[0][1][0] = 1
	g.dp[1][0][1] = 1
	g.dp[2][0][0] = 1

	for i := 0; i < g.n-1; i++ {
		ndp := make([][][]int64, 3)
		for j := range ndp {
			ndp[j] = make([][]int64, g.n+1)
			for k := range ndp[j] {
				ndp[j][k] = make([]int64, g.n+1)
			}
		}
		if i == (g.n+1)/2-1 {
			for j := 0; j <= g.n; j++ {
				for k := 0; j+k <= g.n; k++ {
					if j+1 <= g.n {
						ndp[0][j+1][k] += g.dp[0][j][k] + g.dp[1][j][k] + g.dp[2][j][k]*24
						ndp[0][j+1][k] %= g.mod
					}
					if k+1 <= g.n {
						ndp[1][j][k+1] += g.dp[0][j][k] + g.dp[1][j][k] + g.dp[2][j][k]*24
						ndp[1][j][k+1] %= g.mod
					}
					ndp[2][j][k] += g.dp[0][j][k] + g.dp[1][j][k] + g.dp[2][j][k]*24
					ndp[2][j][k] %= g.mod
				}
			}
		} else {
			for j := 0; j <= g.n; j++ {
				for k := 0; j+k <= g.n; k++ {
					if j+1 <= g.n {
						ndp[0][j+1][k] += g.dp[1][j][k] + g.dp[2][j][k]*24
						ndp[0][j+1][k] %= g.mod
					}
					if k+1 <= g.n {
						ndp[1][j][k+1] += g.dp[0][j][k] + g.dp[2][j][k]*24
						ndp[1][j][k+1] %= g.mod
					}
					ndp[2][j][k] += g.dp[0][j][k] + g.dp[1][j][k] + g.dp[2][j][k]*23
					ndp[2][j][k] %= g.mod
				}
			}
		}
		g.dp = ndp
	}

	g.sdp = make([]int64, g.n+1)
	for i := 0; i <= g.n; i++ {
		for j := 0; j <= g.n; j++ {
			g.sdp[i] += g.dp[0][i][j] + g.dp[1][i][j] + g.dp[2][i][j]*24
		}
		g.sdp[i] %= g.mod
	}

	for i := 0; i < 26; i++ {
		for k := g.a[i] + 1; k <= g.n; k++ {
			g.all -= g.sdp[k]
		}
	}

	for i := 0; i < 26; i++ {
		for j := i + 1; j < 26; j++ {
			for k := g.a[i] + 1; k <= g.n; k++ {
				for l := g.a[j] + 1; l+k <= g.n; l++ {
					g.all += (g.dp[0][k][l] + g.dp[1][k][l] + g.dp[2][k][l]*24)
				}
			}
			g.all %= g.mod
		}
	}
	g.all %= g.mod

	if g.all < 0 {
		g.all += g.mod
	}
	fmt.Println(g.all)
}

func (g *G3) pow(a, n, mod int64) int64 {
	ret := int64(1)
	x := 63 - bits.LeadingZeros64(uint64(n))
	for x >= 0 {
		ret = ret * ret % mod
		if n<<uint(63-x) < 0 {
			ret = ret * a % mod
		}
		x--
	}
	return ret
}

func (g *G3) ni() int {
	var num int
	fmt.Scan(&num)
	return num
}

func (g *G3) na(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = g.ni()
	}
	return arr
}
