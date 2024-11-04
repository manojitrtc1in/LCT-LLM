package main

import (
	"fmt"
	"math"
)

const mod = 998244353

type mint int

func (m mint) norm() mint {
	return (m + mod) % mod
}

func (m mint) inv() mint {
	return pow(m, mod-2)
}

func pow(x mint, n int) mint {
	result := mint(1)
	for n > 0 {
		if n&1 == 1 {
			result = result * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return result
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]bool, n)
	for i := 0; i < n; i++ {
		var v int
		fmt.Scan(&v)
		a[i] = v != 0
	}

	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	zw, ow := 0, 0
	for i := 0; i < n; i++ {
		if a[i] {
			ow += w[i]
		} else {
			zw += w[i]
		}
	}
	s := zw + ow

	inv := make([]mint, 2*m+1)
	for d := -m; d <= m; d++ {
		if s+d > 0 {
			inv[d+m] = mint(1).inv() / mint(s + d)
		}
	}

	dp := make([][]mint, m+1)
	for i := range dp {
		dp[i] = make([]mint, 2)
	}
	dp[0][0] = 1

	for i := 0; i < m; i++ {
		ndp := make([][]mint, m+1)
		for j := range ndp {
			ndp[j] = make([]mint, 2)
		}
		for z := 0; z <= i; z++ {
			o := i - z
			wz := zw - z
			wo := ow + o
			if wz < 0 {
				continue
			}
			for dz := -1; dz <= 0; dz++ {
				nwz := wz + dz
				nz := z + (-dz)
				if nwz < 0 {
					continue
				}
				eps := inv[wz+wo-s+m]
				p := mint(0)
				if dz == -1 {
					p = mint(wz) * eps
				} else {
					p = mint(wo) * eps
				}
				ndp[nz][-dz] += dp[z][-dz] * p
				ndp[nz][1+dz] += (p + (2*dz+1)*eps) * dp[z][1+dz]
			}
		}
		dp = ndp
	}

	cz, co := mint(0), mint(0)
	for i := 0; i <= m; i++ {
		cz += dp[i][0]
		co += dp[i][1]
	}

	for i := 0; i < n; i++ {
		if a[i] {
			fmt.Println(w[i] * int(co))
		} else {
			fmt.Println(w[i] * int(cz))
		}
	}
}
