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

func (m *Mint) Val() uint {
	return m.v
}

func (m *Mint) Add(rhs *Mint) {
	m.v += rhs.v
	if m.v >= uint(m.m) {
		m.v -= uint(m.m)
	}
}

func (m *Mint) Sub(rhs *Mint) {
	m.v += uint(m.m) - rhs.v
	if m.v >= uint(m.m) {
		m.v -= uint(m.m)
	}
}

func (m *Mint) Mul(rhs *Mint) {
	m.v = (m.v * rhs.v) % uint(m.m)
}

func (m *Mint) Inv() *Mint {
	return m.Pow(uint(m.m - 2))
}

func (m *Mint) Pow(n uint) *Mint {
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

func get(i, z int) int {
	l := i * z
	r := (i + i) * z
	ans := l

	for l <= r {
		m := (l + r) / 2
		if m/z > i {
			r = m - 1
		} else {
			if ans < m {
				ans = m
			}
			l = m + 1
		}
	}

	return ans
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mint := NewMint(m)

	dp := make([]*Mint, n+1)
	p1 := make([]*Mint, n+1)

	for i := range dp {
		dp[i] = NewMint(m)
		p1[i] = NewMint(m)
	}

	dp[n].v = 1
	p1[n].v = 1

	for i := n - 1; i >= 1; i-- {
		dp[i].Add(p1[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
			dp[i].Add(p1[l])
			if r <= n {
				dp[i].Sub(p1[r])
			}
		}

		p1[i].Add(dp[i])
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
