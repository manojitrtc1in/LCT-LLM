package main

import (
	"fmt"
)

type Mint struct {
	v uint32
	m uint32
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

func (m *Mint) Add(rhs *Mint) *Mint {
	m.v += rhs.v
	if m.v >= m.m {
		m.v -= m.m
	}
	return m
}

func (m *Mint) Sub(rhs *Mint) *Mint {
	m.v += m.m - rhs.v
	if m.v >= m.m {
		m.v -= m.m
	}
	return m
}

func (m *Mint) Mul(rhs *Mint) *Mint {
	m.v = (m.v * rhs.v) % m.m
	return m
}

func (m *Mint) Pow(n int64) *Mint {
	x := *m
	r := NewMint(m.m)
	r.v = 1
	for n > 0 {
		if n&1 == 1 {
			r.Mul(&x)
		}
		x.Mul(&x)
		n >>= 1
	}
	return r
}

func (m *Mint) Inv() *Mint {
	return m.Pow(int64(m.m - 2))
}

func safeMod(x, m int64) int64 {
	x %= m
	if x < 0 {
		x += m
	}
	return x
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

	mint := NewMint(uint32(m))

	dp := make([]*Mint, n+1)
	p1 := make([]*Mint, n+1)

	for i := range dp {
		dp[i] = NewMint(uint32(m))
		p1[i] = NewMint(uint32(m))
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
