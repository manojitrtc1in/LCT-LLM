package main

import (
	"bytes"
	"fmt"
	"io"
	"math"
)

const mod = 998244353
const G = 3

var big = (math.MaxInt64/mod/mod-1)*mod*mod

func main() {
	var n int
	fmt.Scan(&n)

	g := make([][]bool, 10)
	for i := range g {
		g[i] = make([]bool, 10)
	}

	var m int
	fmt.Scan(&m)
	for m > 0 {
		m--
		var x, y int
		fmt.Scan(&x, &y)
		g[x][y] = true
		g[y][x] = true
	}
	for i := 0; i < 10; i++ {
		g[i][i] = true
	}

	njs := make([][]int, 1<<9)
	for j := range njs {
		njs[j] = make([]int, 10)
		for k := 0; k < 10; k++ {
			if j<<^k >= 0 {
				nj := j
				for l := 0; l < 10; l++ {
					if g[k][l] {
						if k > l {
							nj |= 1 << l
						}
					} else {
						nj &= ^(1 << l)
					}
				}
				njs[j][k] = nj
			}
		}
	}

	dp := make([]int64, 1<<9)
	dp[0] = 1
	for i := 1; i <= n; i++ {
		ndp := make([]int64, 1<<9)
		for j := 0; j < 1<<9; j++ {
			for k := 0; k < 10; k++ {
				if j<<^k >= 0 {
					nj := njs[j][k]
					ndp[nj] += dp[j]
					if ndp[nj] >= mod {
						ndp[nj] -= mod
					}
				}
			}
		}
		dp = ndp
	}
	ans := sum(dp) % mod
	fmt.Println(ans)
}

func sum(a []int64) int64 {
	var ret int64
	for _, v := range a {
		ret += v
	}
	return ret
}

func mul(a, b []int64) []int64 {
	if len(a) == 0 && len(b) == 0 {
		return []int64{}
	}
	if len(a)+len(b) >= 300 {
		return convolve(a, b)
	} else {
		return mulNaive(a, b)
	}
}

func convolve(a, b []int64) []int64 {
	// Implementation of NTT convolution
	// Placeholder for actual implementation
	return nil
}

func mulNaive(a, b []int64) []int64 {
	c := make([]int64, len(a)+len(b)-1)
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			c[i+j] += a[i] * b[j]
			if c[i+j] >= big {
				c[i+j] -= big
			}
		}
	}
	for i := range c {
		c[i] %= mod
	}
	return c
}

func C(n, r int, mod int, fif [][]int) int64 {
	if n < 0 || r < 0 || r > n {
		return 0
	}
	return (int64(fif[0][n]) * int64(fif[1][r]) % int64(mod) * int64(fif[1][n-r]) % int64(mod)) % int64(mod)
}

func enumFIF(n, mod int) [][]int {
	f := make([]int, n+1)
	invf := make([]int, n+1)
	f[0] = 1
	for i := 1; i <= n; i++ {
		f[i] = (f[i-1] * i) % mod
	}
	a := f[n]
	b := mod
	p, q := int64(1), int64(0)
	for b > 0 {
		c := a / b
		d := a
		a = b
		b = d % b
		d = p
		p = q
		q = d - c*q
	}
	invf[n] = int(p % int64(mod))
	for i := n - 1; i >= 0; i-- {
		invf[i] = (invf[i+1] * (i + 1)) % mod
	}
	return [][]int{f, invf}
}