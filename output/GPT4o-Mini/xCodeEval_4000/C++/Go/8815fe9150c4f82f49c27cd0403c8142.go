package main

import (
	"fmt"
	"math/big"
)

const mod = 998244353

type mint struct {
	v uint
}

func newMint(val int64) mint {
	return mint{norm(uint(val % int64(mod) + int64(mod)))}
}

func (m mint) add(n mint) mint {
	return newMint(int64(m.v+n.v) % int64(mod))
}

func (m mint) sub(n mint) mint {
	return newMint(int64(m.v+n.v) % int64(mod))
}

func (m mint) mul(n mint) mint {
	return newMint(int64(m.v) * int64(n.v) % int64(mod))
}

func (m mint) div(n mint) mint {
	return m.mul(inverse(n.v))
}

func (m mint) value() uint {
	return m.v
}

func norm(x uint) uint {
	if x < mod {
		return x
	}
	return x - mod
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func inverse(a uint) mint {
	return newMint(int64(1) / int64(a))
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]bool, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		a[i] = x != 0
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
			inv[d+m] = newMint(1) / newMint(s + d)
		}
	}

	dp := make([][]mint, m+1)
	for i := range dp {
		dp[i] = make([]mint, 2)
	}
	dp[0][0] = newMint(1)

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
				p := mint{0}.mul(mint{0}.add(mint{0}.mul(mint{0}, eps)))

				ndp[nz][-dz] = ndp[nz][-dz].add(dp[z][-dz].mul(p))
				ndp[nz][1+dz] = ndp[nz][1+dz].add((p.add(mint{0}.mul(mint{0}, eps))).mul(dp[z][1+dz]))
			}
		}
		dp = ndp
	}

	cz, co := mint{0}, mint{0}
	for i := 0; i <= m; i++ {
		cz = cz.add(dp[i][0])
		co = co.add(dp[i][1])
	}

	for i := 0; i < n; i++ {
		if a[i] {
			fmt.Println(w[i] * int(co.value()))
		} else {
			fmt.Println(w[i] * int(cz.value()))
		}
	}
}
