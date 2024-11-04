package main

import (
	"fmt"
)

type mint int

func (m mint) inv() mint {
	return mint(1) / m
}

func (m mint) pow(n int) mint {
	res := mint(1)
	for n > 0 {
		if n&1 == 1 {
			res *= m
		}
		m *= m
		n >>= 1
	}
	return res
}

func main() {
	const mod = 998244353
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]bool, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		var ai int
		fmt.Scan(&ai)
		a[i] = ai == 1
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	zw := 0
	ow := 0
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
			inv[d+m] = mint(1).inv() / mint(s+d)
		}
	}

	dp := make([][]mint, m+1)
	for i := 0; i <= m; i++ {
		dp[i] = make([]mint, 2)
	}
	dp[0][0] = 1
	dp[0][1] = 1

	for i := 0; i < m; i++ {
		ndp := make([][]mint, m+1)
		for j := 0; j <= m; j++ {
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
				p := mint(dz+1)*eps

				ndp[nz][0] += dp[z][0] * p
				ndp[nz][1] += (p + mint(2*dz+1)*eps) * dp[z][1]
			}
		}

		dp = ndp
	}

	cz := mint(0)
	co := mint(0)
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
