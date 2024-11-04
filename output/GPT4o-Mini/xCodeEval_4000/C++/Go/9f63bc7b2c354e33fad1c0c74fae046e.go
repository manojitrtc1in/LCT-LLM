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

func (m *Mint) Inv() *Mint {
	return m.Pow(m.m - 2)
}

func (m *Mint) Pow(n int) *Mint {
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

var l1, r1 uint

func get(i, z int) uint {
	l1 = uint(i * z)
	r1 = uint((i + i) * z)

	ans := l1

	for l1 <= r1 {
		m := (l1 + r1) / 2
		if m/uint(z) > uint(i) {
			r1 = m - 1
		} else {
			if ans < m {
				ans = m
			}
			l1 = m + 1
		}
	}

	return ans
}

func solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mint := NewMint(m)

	dp := make([]*Mint, n+1)
	p := make([]*Mint, n+1)

	dp[n] = mint.Raw(1)
	p[n] = mint.Raw(1)

	for i := n - 1; i >= 1; i-- {
		dp[i] = dp[i].Add(p[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
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
