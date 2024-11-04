package main

import (
	"fmt"
)

type Mint struct {
	v uint32
	m uint32
}

func NewMint(m int) *Mint {
	return &Mint{m: uint32(m)}
}

func (m *Mint) SetMod(mod int) {
	m.m = uint32(mod)
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

func (m *Mint) Pow(n int64) *Mint {
	res := NewMint(int(m.m))
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
	// Extended Euclidean Algorithm to find modular inverse
	a, b := m.v, m.m
	x0, x1 := uint32(0), uint32(1)
	if m.v == 0 {
		return NewMint(int(m.m))
	}
	for a > 1 {
		q := a / b
		a, b = b, a%b
		x0, x1 = x1-q*x0, x0
	}
	if x1 < 0 {
		x1 += m.m
	}
	return &Mint{v: x1}
}

type TaskB struct{}

func (t *TaskB) Solve(n, m int) {
	mint := NewMint(m)
	ways := make([]*Mint, n+1)
	extras := make([]*Mint, n+1)
	for i := range ways {
		ways[i] = NewMint(m)
		extras[i] = NewMint(m)
	}
	ways[1].v = 1
	sum := NewMint(m)
	extra := NewMint(m)

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
	solver := TaskB{}
	solver.Solve(n, m)
}
