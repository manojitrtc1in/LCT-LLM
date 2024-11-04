package main

import (
	"fmt"
	"math"
)

type Mint struct {
	v uint
	mod uint
}

func NewMint(val uint, mod uint) Mint {
	return Mint{v: val % mod, mod: mod}
}

func (m Mint) Add(other Mint) Mint {
	return NewMint(m.v + other.v, m.mod)
}

func (m Mint) Sub(other Mint) Mint {
	return NewMint(m.v + m.mod - other.v, m.mod)
}

func (m Mint) Mul(other Mint) Mint {
	return NewMint(m.v * other.v % m.mod, m.mod)
}

func (m Mint) Inv() Mint {
	return NewMint(Inverse(m.v, m.mod), m.mod)
}

func Inverse(a, mod uint) uint {
	m0, y, x := mod, uint(0), uint(1)
	if mod == 1 {
		return 0
	}
	for a > 1 {
		q := a / mod
		m0, a, mod = a, mod, a%mod
		y, x = x-y*q, m0-y*q
	}
	if x < 0 {
		x += m0
	}
	return x
}

func Popcount(u uint) uint {
	return uint(math.PopCount(uint64(u)))
}

func main() {
	const mod = 998244353
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

	inv := make([]Mint, 2*m+1)
	for d := -m; d <= m; d++ {
		if s+d > 0 {
			inv[d+m] = NewMint(1, s+d)
		}
	}

	dp := make([][]Mint, m+1)
	for i := range dp {
		dp[i] = make([]Mint, 2)
	}
	dp[0][0] = NewMint(1, mod)

	for i := 0; i < m; i++ {
		ndp := make([][]Mint, m+1)
		for j := range ndp {
			ndp[j] = make([]Mint, 2)
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
				nz := z - dz
				if nwz < 0 {
					continue
				}
				eps := inv[wz+wo-s+m]
				p := Mint{v: 0, mod: mod}
				if dz == -1 {
					p = Mint{v: wz, mod: mod}.Mul(eps)
				} else {
					p = Mint{v: wo, mod: mod}.Mul(eps)
				}
				ndp[nz][-dz] = ndp[nz][-dz].Add(dp[z][-dz].Mul(p))
				ndp[nz][1+dz] = ndp[nz][1+dz].Add(p.Add(Mint{v: uint(2*dz + 1), mod: mod}.Mul(eps)).Mul(dp[z][1+dz]))
			}
		}
		dp = ndp
	}

	cz, co := Mint{v: 0, mod: mod}, Mint{v: 0, mod: mod}
	for i := 0; i <= m; i++ {
		cz = cz.Add(dp[i][0])
		co = co.Add(dp[i][1])
	}

	for i := 0; i < n; i++ {
		if a[i] {
			fmt.Println(w[i] * co.v)
		} else {
			fmt.Println(w[i] * cz.v)
		}
	}
}
