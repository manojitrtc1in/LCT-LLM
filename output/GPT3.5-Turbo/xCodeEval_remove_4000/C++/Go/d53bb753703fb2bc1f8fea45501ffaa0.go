package main

import (
	"fmt"
)

type Modular struct {
	value int
}

func NewModular(v int) *Modular {
	mod := &Modular{
		value: v,
	}
	return mod
}

func (m *Modular) Add(o *Modular) *Modular {
	m.value += o.value
	if m.value >= MOD {
		m.value -= MOD
	}
	return m
}

func (m *Modular) Subtract(o *Modular) *Modular {
	m.value -= o.value
	if m.value < 0 {
		m.value += MOD
	}
	return m
}

func (m *Modular) Multiply(o *Modular) *Modular {
	m.value = (m.value * o.value) % MOD
	return m
}

func (m *Modular) Divide(o *Modular) *Modular {
	return m.Multiply(o.Inverse())
}

func (m *Modular) Increment() *Modular {
	return m.Add(NewModular(1))
}

func (m *Modular) Decrement() *Modular {
	return m.Subtract(NewModular(1))
}

func (m *Modular) Exponentiate(k int) *Modular {
	res := NewModular(1)
	a := NewModular(m.value)
	for k > 0 {
		if k&1 == 1 {
			res.Multiply(a)
		}
		a.Multiply(a)
		k >>= 1
	}
	return res
}

func (m *Modular) Inverse() *Modular {
	return m.Exponentiate(MOD - 2)
}

func (m *Modular) Equals(o *Modular) bool {
	return m.value == o.value
}

func (m *Modular) NotEquals(o *Modular) bool {
	return m.value != o.value
}

func (m *Modular) String() string {
	return fmt.Sprintf("%d", m.value)
}

const (
	MOD = 7
)

func solve() int {
	var n int
	fmt.Scanf("%d", &n)
	var s, t string
	fmt.Scanf("%s", &s)
	fmt.Scanf("%s", &t)

	get := func(c byte) int {
		return int(c - 'a')
	}

	G := make([][]int, C)
	cur := make([]int, 0)
	masks := make([]int, C)
	dp := make([]bool, 1<<C)
	vis := make([]bool, C)
	mask := 0

	dfs := func(v int) {
		vis[v] = true
		mask |= 1 << v
		cur = append(cur, v)

		for _, s := range G[v] {
			if !vis[s] {
				dfs(s)
			}
		}
	}

	count := func() int {
		sub := make([]int, 0)
		for m := mask; m > 0; m-- {
			sub = append(sub, m)
		}

		res := 0
		for _, m := range sub {
			for _, v := range cur {
				if m&(1<<v) != 0 {
					dp[m] = dp[m^(1<<v)] && ((m&masks[v]&mask) == 0)
				}
			}
			if dp[m] {
				res = max(res, pct(m))
			}
		}
		return res
	}

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	n = 20
	s = "abcdefghijklmnopqrstuvwxyz"
	t = "abcdefghijklmnopqrstuvwxyz"

	res := 0
	dp[0] = true
	for i := 0; i < C; i++ {
		if !vis[i] {
			mask = 0
			cur = cur[:0]
			dfs(i)
			tmp := count()
			res += 2*len(cur) - 1 - tmp
		}
	}

	for i := 0; i < C; i++ {
		vis[i] = false
		masks[i] = 0
		G[i] = G[i][:0]
	}

	return res
}

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for t > 0 {
		fmt.Println(solve())
		t--
	}
}
