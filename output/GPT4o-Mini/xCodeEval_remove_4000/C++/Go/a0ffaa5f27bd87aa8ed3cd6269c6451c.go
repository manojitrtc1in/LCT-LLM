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
	return Mint{v: v % mod, mod: mod}
}

func (m Mint) Val() uint64 {
	return m.v
}

func (m Mint) Add(rhs Mint) Mint {
	return NewMint(m.v+rhs.v, m.mod)
}

func (m Mint) Sub(rhs Mint) Mint {
	return NewMint(m.v+rhs.mod-rhs.v, m.mod)
}

func (m Mint) Mul(rhs Mint) Mint {
	return NewMint(m.v*rhs.v, m.mod)
}

func (m Mint) Pow(n uint64) Mint {
	res := NewMint(1, m.mod)
	x := m
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(x)
		}
		x = x.Mul(x)
		n >>= 1
	}
	return res
}

func (m Mint) Inv() Mint {
	return m.Pow(m.mod - 2)
}

func BinomialCoefficient(n, k int, mod uint64) Mint {
	if k > n {
		return NewMint(0, mod)
	}
	if k == 0 || k == n {
		return NewMint(1, mod)
	}
	num := big.NewInt(1)
	den := big.NewInt(1)
	for i := 0; i < k; i++ {
		num.Mul(num, big.NewInt(int64(n-i)))
		den.Mul(den, big.NewInt(int64(i+1)))
	}
	return NewMint(new(big.Int).Mod(num, big.NewInt(int64(mod))).Uint64(), mod).
		Mul(NewMint(new(big.Int).Mod(den, big.NewInt(int64(mod))).Uint64(), mod))
}

func main() {
	var n, m, mod int
	fmt.Scan(&n, &m, &mod)

	C := make([][]Mint, n+1)
	for i := range C {
		C[i] = make([]Mint, n+1)
	}
	C[0][0] = NewMint(1, uint64(mod))
	for i := 1; i <= n; i++ {
		C[i][0] = NewMint(1, uint64(mod))
		for j := 1; j <= n; j++ {
			C[i][j] = C[i-1][j-1].Add(C[i-1][j])
		}
	}

	g := make([]Mint, n+1)
	for i := 0; i <= n; i++ {
		g[i] = NewMint(uint64(i*(i+1)/2), uint64(mod))
	}

	f := make([][2]Mint, n+1)
	f[0] = [2]Mint{NewMint(1, uint64(mod)), NewMint(0, uint64(mod))}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			z := f[j][0].Mul(f[i-1-j][0]).Mul(C[i-1][j])
			f[i][0] = f[i][0].Add(z.Mul(NewMint(uint64(i+1), uint64(mod))))
			f[i][1] = f[i][1].Add(z.Mul(g[j].Add(g[i-1-j])))
			f[i][1] = f[i][1].Add(f[i-1-j][0].Mul(f[j][1]).Add(f[j][0].Mul(f[i-1-j][1])).Mul(C[i-1][j]).Mul(NewMint(uint64(i+1), uint64(mod))))
		}
	}

	dp := make([][2]Mint, m+1)
	dp[0] = [2]Mint{NewMint(1, uint64(mod)), NewMint(0, uint64(mod))}
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
