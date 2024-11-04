package main

import (
	"fmt"
)

type mint struct {
	v uint
}

var mod uint

func setMod(m int) {
	mod = uint(m)
}

func (m mint) val() uint {
	return m.v
}

func (m *mint) add(rhs mint) {
	m.v += rhs.v
	if m.v >= mod {
		m.v -= mod
	}
}

func (m *mint) sub(rhs mint) {
	m.v += mod - rhs.v
	if m.v >= mod {
		m.v -= mod
	}
}

func (m *mint) mul(rhs mint) {
	m.v = (m.v * rhs.v) % mod
}

func (m *mint) pow(n int64) mint {
	x := *m
	r := mint{1}
	for n > 0 {
		if n&1 == 1 {
			r.mul(x)
		}
		x.mul(x)
		n >>= 1
	}
	return r
}

func (m *mint) inv() mint {
	return m.pow(int64(mod - 2))
}

func get(i, z int) uint {
	l1 := uint(i * z)
	r1 := uint((i + i) * z)

	ans := l1

	for l1 <= r1 {
		m := (l1 + r1) / 2
		if m/z > uint(i) {
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

	setMod(m)

	dp := make([]mint, n+1)
	p := make([]mint, n+1)

	dp[n] = mint{1}
	p[n] = mint{1}
	for i := n - 1; i >= 1; i-- {
		dp[i].add(p[i+1])

		for z := 2; z*i <= n; z++ {
			r := get(i, z) + 1
			l := z * i
			dp[i].add(p[l])
			if r <= n {
				dp[i].sub(p[r])
			}
		}

		p[i].add(dp[i])
	}

	fmt.Println(dp[1].val())
}

func main() {
	var t int = 1
	for t > 0 {
		solve()
		t--
	}
}
