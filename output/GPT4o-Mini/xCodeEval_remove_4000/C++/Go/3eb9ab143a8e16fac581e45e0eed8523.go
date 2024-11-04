package main

import (
	"fmt"
)

type Mint struct {
	v   uint32
	mod uint32
}

func NewMint(mod uint32) *Mint {
	return &Mint{mod: mod}
}

func (m *Mint) SetMod(mod uint32) {
	m.mod = mod
}

func (m *Mint) Raw(v int) *Mint {
	x := uint32(v % int(m.mod))
	if x < 0 {
		x += m.mod
	}
	m.v = x
	return m
}

func (m *Mint) Val() uint32 {
	return m.v
}

func (m *Mint) Add(rhs *Mint) *Mint {
	m.v += rhs.v
	if m.v >= m.mod {
		m.v -= m.mod
	}
	return m
}

func (m *Mint) Sub(rhs *Mint) *Mint {
	m.v += m.mod - rhs.v
	if m.v >= m.mod {
		m.v -= m.mod
	}
	return m
}

func (m *Mint) Mul(rhs *Mint) *Mint {
	m.v = (m.v * rhs.v) % m.mod
	return m
}

func (m *Mint) Pow(n int64) *Mint {
	x := *m
	r := NewMint(m.mod).Raw(1)
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
	// Extended Euclidean Algorithm to find the modular inverse
	a, b := m.v, m.mod
	m0, x0, x1 := b, 0, 1
	if b == 1 {
		return NewMint(m.mod).Raw(0)
	}
	for a > 1 {
		q := a / b
		a, b = b, a%b
		x0, x1 = x1-q*x0, x0
	}
	if x1 < 0 {
		x1 += m0
	}
	return NewMint(m.mod).Raw(int(x1))
}

type TaskB struct{}

func (t *TaskB) Solve(n, m int) {
	ways := make([]*Mint, n+1)
	extras := make([]*Mint, n+1)
	for i := range ways {
		ways[i] = NewMint(uint32(m)).Raw(0)
		extras[i] = NewMint(uint32(m)).Raw(0)
	}
	ways[1].Raw(1)
	sum := NewMint(uint32(m)).Raw(0)
	extra := NewMint(uint32(m)).Raw(0)

	for i := 1; i <= n; i++ {
		ways[i].Add(sum)
		extra.Add(extras[i])
		ways[i].Add(extra)

		for j := 2; i*j <= n; j++ {
			extras[i*j].Add(ways[i])
			if (i+1)*j <= n {
				extras[(i+1)*j].Sub(ways[i])
			}
		}
		sum.Add(ways[i])
	}
	fmt.Println(ways[n].Val())
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	solver := &TaskB{}
	solver.Solve(n, m)
}
