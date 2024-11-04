package main

import (
	"fmt"
)

type Mint struct {
	v uint
	m int
}

func NewMint(m int) *Mint {
	return &Mint{m: m}
}

func (m *Mint) SetMod(mod int) {
	m.m = mod
}

func (m *Mint) Raw(v int) *Mint {
	m.v = uint(v % m.m)
	if m.v < 0 {
		m.v += uint(m.m)
	}
	return m
}

func (m *Mint) Val() uint {
	return m.v
}

func (m *Mint) Add(rhs *Mint) *Mint {
	m.v += rhs.v
	if m.v >= uint(m.m) {
		m.v -= uint(m.m)
	}
	return m
}

func (m *Mint) Sub(rhs *Mint) *Mint {
	m.v += uint(m.m) - rhs.v
	if m.v >= uint(m.m) {
		m.v -= uint(m.m)
	}
	return m
}

func (m *Mint) Mul(rhs *Mint) *Mint {
	m.v = (m.v * rhs.v) % uint(m.m)
	return m
}

func (m *Mint) Pow(n int64) *Mint {
	if n < 0 {
		panic("negative exponent")
	}
	x := *m
	r := NewMint(m.m).Raw(1)
	for n > 0 {
		if n&1 == 1 {
			r = r.Mul(&x)
		}
		x = *x.Mul(&x)
		n >>= 1
	}
	return r
}

func (m *Mint) Inv() *Mint {
	return m.Pow(m.m - 2)
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mint := NewMint(m)

	dp := make([]*Mint, n+1)
	p := make([]*Mint, n+1)

	for i := range dp {
		dp[i] = mint.Raw(0)
	}
	for i := range p {
		p[i] = mint.Raw(0)
	}

	dp[n] = mint.Raw(1)
	p[n] = mint.Raw(1)

	for i := n - 1; i >= 1; i-- {
		dp[i] = dp[i].Add(p[i+1])

		for z := 2; uint(z)*uint(i) <= uint(n); z++ {
			r := i*z + z
			l := uint(z) * uint(i)
			dp[i] = dp[i].Add(p[l])
			if r <= n {
				dp[i] = dp[i].Sub(p[r])
			}
		}

		p[i] = p[i+1].Add(dp[i])
	}

	fmt.Println(dp[1].Val())
}

func main() {
	var t int = 1
	for t > 0 {
		solve()
		t--
	}
}
