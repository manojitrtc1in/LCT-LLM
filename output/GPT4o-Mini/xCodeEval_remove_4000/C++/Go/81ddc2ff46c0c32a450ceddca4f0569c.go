package main

import (
	"fmt"
)

type Mint struct {
	v  uint32
	m  uint32
}

func NewMint(m uint32) *Mint {
	return &Mint{m: m}
}

func (m *Mint) SetMod(mod uint32) {
	m.m = mod
}

func (m *Mint) Val() uint32 {
	return m.v
}

func (m *Mint) Add(rhs *Mint) {
	m.v += rhs.v
	if m.v >= m.m {
		m.v -= m.m
	}
}

func (m *Mint) Sub(rhs *Mint) {
	m.v += m.m - rhs.v
	if m.v >= m.m {
		m.v -= m.m
	}
}

func (m *Mint) Mul(rhs *Mint) {
	m.v = (m.v * rhs.v) % m.m
}

func (m *Mint) Pow(n uint64) *Mint {
	res := NewMint(m.m)
	res.v = 1
	x := *m
	for n > 0 {
		if n&1 == 1 {
			res.Mul(&x)
		}
		x.Mul(&x)
		n >>= 1
	}
	return res
}

func (m *Mint) Inv() *Mint {
	// Using Fermat's Little Theorem for prime mod
	return m.Pow(uint64(m.m - 2))
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mint := NewMint(uint32(m))

	dp := make([]*Mint, n+1)
	p := make([]*Mint, n+1)

	for i := range dp {
		dp[i] = NewMint(uint32(m))
		p[i] = NewMint(uint32(m))
	}

	dp[n].v = 1
	p[n].v = 1

	for i := n - 1; i >= 1; i-- {
		dp[i].Add(p[i+1])

		for z := 2; uint64(z)*uint64(i) <= uint64(n); z++ {
			r := i*z + z
			l := 1 * z * i
			dp[i].Add(p[l])
			if r <= n {
				dp[i].Sub(p[r])
			}
		}

		p[i].Add(dp[i])
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
