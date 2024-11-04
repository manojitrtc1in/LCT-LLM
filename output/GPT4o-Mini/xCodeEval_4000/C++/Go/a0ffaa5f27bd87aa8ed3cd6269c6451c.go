package main

import (
	"fmt"
	"math/big"
)

type Mint struct {
	v   uint64
	mod uint64
}

func NewMint(v, mod uint64) Mint {
	if v >= mod {
		v %= mod
	}
	return Mint{v: v, mod: mod}
}

func (m Mint) Val() uint64 {
	return m.v
}

func (m Mint) Add(rhs Mint) Mint {
	res := m.v + rhs.v
	if res >= m.mod {
		res -= m.mod
	}
	return Mint{v: res, mod: m.mod}
}

func (m Mint) Sub(rhs Mint) Mint {
	res := m.v - rhs.v
	if res < 0 {
		res += m.mod
	}
	return Mint{v: res, mod: m.mod}
}

func (m Mint) Mul(rhs Mint) Mint {
	return NewMint(m.v*rhs.v, m.mod)
}

func (m Mint) Pow(exp uint64) Mint {
	res := Mint{v: 1, mod: m.mod}
	base := m
	for exp > 0 {
		if exp%2 == 1 {
			res = res.Mul(base)
		}
		base = base.Mul(base)
		exp /= 2
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(m.mod - 2)
}

func BinomialCoefficient(n, k int, mod uint64) Mint {
	if k > n {
		return Mint{v: 0, mod: mod}
	}
	if k == 0 || k == n {
		return Mint{v: 1, mod: mod}
	}

	fact := make([]Mint, n+1)
	fact[0] = Mint{v: 1, mod: mod}
	for i := 1; i <= n; i++ {
		fact[i] = fact[i-1].Mul(NewMint(uint64(i), mod))
	}

	return fact[n].Mul(fact[k].Inv()).Mul(fact[n-k].Inv())
}

func main() {
	var n, m, mod int
	fmt.Scan(&n, &m, &mod)
	mintMod := uint64(mod)

	C := make([][]Mint, n+1)
	for i := range C {
		C[i] = make([]Mint, n+1)
	}
	C[0][0] = NewMint(1, mintMod)
	for i := 1; i <= n; i++ {
		C[i][0] = NewMint(1, mintMod)
		for j := 1; j <= n; j++ {
			C[i][j] = C[i-1][j-1].Add(C[i-1][j])
		}
	}

	g := make([]Mint, n+1)
	for i := 0; i <= n; i++ {
		g[i] = NewMint(uint64(i*(i+1)/2), mintMod)
	}

	f := make([][2]Mint, n+1)
	f[0] = [2]Mint{NewMint(1, mintMod), NewMint(0, mintMod)}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			z := f[j][0].Mul(f[i-1-j][0]).Mul(C[i-1][j])
			f[i][0] = f[i][0].Add(z.Mul(NewMint(uint64(i+1), mintMod)))
			f[i][1] = f[i][1].Add(z.Mul(g[j].Add(g[i-1-j])))
			f[i][1] = f[i][1].Add(f[i-1-j][0].Mul(f[j][1]).Add(f[j][0].Mul(f[i-1-j][1])).Mul(C[i-1][j]).Mul(NewMint(uint64(i+1), mintMod)))
		}
	}

	dp := make([][2]Mint, n+2)
	dp[0] = [2]Mint{NewMint(1, mintMod), NewMint(0, mintMod)}

	for l := 0; l <= n; l++ {
		for r := l + 1; r <= n+1; r++ {
			di := r - l - 1
			for i := 0; i+di <= m; i++ {
				z := dp[l][i][0].Mul(f[di][0])
				dp[r][i+di][0] = dp[r][i+di][0].Add(z.Mul(C[i+di][di]))
				dp[r][i+di][1] = dp[r][i+di][1].Add(dp[l][i][1].Mul(f[di][0]).Add(dp[l][i][0].Mul(f[di][1])).Mul(C[i+di][di]))
			}
		}
	}

	fmt.Println(dp[n+1][m][1].Val())
}
