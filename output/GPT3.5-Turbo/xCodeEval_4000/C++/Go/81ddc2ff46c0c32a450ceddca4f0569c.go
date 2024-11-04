package main

import (
	"fmt"
)

type mint struct {
	v int
}

func staticModint(m int) mint {
	return mint{v: m}
}

func (m mint) mod() int {
	return m.v
}

func (m mint) raw(v int) mint {
	return mint{v: v}
}

func (m mint) val() int {
	return m.v
}

func (m *mint) increment() {
	m.v++
	if m.v == m.mod() {
		m.v = 0
	}
}

func (m *mint) decrement() {
	if m.v == 0 {
		m.v = m.mod()
	}
	m.v--
}

func (m mint) add(rhs mint) mint {
	m.v += rhs.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m mint) subtract(rhs mint) mint {
	m.v += m.mod() - rhs.v
	if m.v >= m.mod() {
		m.v -= m.mod()
	}
	return m
}

func (m mint) multiply(rhs mint) mint {
	m.v = (m.v * rhs.v) % m.mod()
	return m
}

func (m mint) divide(rhs mint) mint {
	return m.multiply(rhs.inverse())
}

func (m mint) inverse() mint {
	a, b := m.v, m.mod()
	u, v := 1, 0
	for b != 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	if u < 0 {
		u += m.mod() / a
	}
	return mint{v: u}
}

func (m mint) pow(n int) mint {
	result := mint{v: 1}
	x := m
	for n > 0 {
		if n&1 == 1 {
			result = result.multiply(x)
		}
		x = x.multiply(x)
		n >>= 1
	}
	return result
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	mod := staticModint(m)

	dp := make([]mint, n+1)
	p := make([]mint, n+1)

	dp[n] = mint{v: 1}
	p[n] = mint{v: 1}
	for i := n - 1; i >= 1; i-- {
		dp[i] = dp[i].add(p[i+1])

		for z := 2; uint(z*i) <= uint(n); z++ {
			r := i*z + z
			l := z * i
			dp[i] = dp[i].add(p[l])
			if r <= n {
				dp[i] = dp[i].subtract(p[r])
			}
		}

		p[i] = p[i+1].add(dp[i])
	}

	fmt.Println(dp[1].val())
}
