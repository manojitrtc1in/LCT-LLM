package main

import (
	"fmt"
)

type mint int

const mod int = 998244353

func inv(x int) mint {
	return mint(x).pow(mod - 2)
}

func (x mint) pow(n int) mint {
	ans := mint(1)
	for n > 0 {
		if n&1 == 1 {
			ans *= x
		}
		x *= x
		n >>= 1
	}
	return ans
}

func main() {
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
			inv[d+m] = inv[s+d].inv()
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
				p := mint(dz+1)*eps + mint(dz+1)*eps + mint(dz+1)*eps
				ndp[nz][dz+1] += dp[z][dz+1] * p
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