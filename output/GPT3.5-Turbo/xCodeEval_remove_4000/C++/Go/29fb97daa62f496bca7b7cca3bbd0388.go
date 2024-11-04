package main

import (
	"fmt"
)

type Modular struct {
	value int
	MOD   int
}

func NewModular(v int, mod int) *Modular {
	return &Modular{
		value: v % mod,
		MOD:   mod,
	}
}

func (m *Modular) Add(o *Modular) *Modular {
	return NewModular((m.value+o.value)%m.MOD, m.MOD)
}

func (m *Modular) Subtract(o *Modular) *Modular {
	return NewModular((m.value-o.value+m.MOD)%m.MOD, m.MOD)
}

func (m *Modular) Multiply(o *Modular) *Modular {
	return NewModular((m.value*o.value)%m.MOD, m.MOD)
}

func (m *Modular) Divide(o *Modular) *Modular {
	return m.Multiply(o.Inverse())
}

func (m *Modular) Increment() *Modular {
	return NewModular((m.value+1)%m.MOD, m.MOD)
}

func (m *Modular) Decrement() *Modular {
	return NewModular((m.value-1+m.MOD)%m.MOD, m.MOD)
}

func (m *Modular) Exponentiate(k int) *Modular {
	res := NewModular(1, m.MOD)
	a := NewModular(m.value, m.MOD)
	for k > 0 {
		if k&1 == 1 {
			res = res.Multiply(a)
		}
		a = a.Multiply(a)
		k >>= 1
	}
	return res
}

func (m *Modular) Inverse() *Modular {
	return m.Exponentiate(m.MOD - 2)
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

type Pair struct {
	first  int
	second int
}

func NewPair(f, s int) *Pair {
	return &Pair{
		first:  f,
		second: s,
	}
}

func (p *Pair) Add(o *Pair) *Pair {
	return NewPair(p.first+o.first, p.second+o.second)
}

func (p *Pair) Subtract(o *Pair) *Pair {
	return NewPair(p.first-o.first, p.second-o.second)
}

func (p *Pair) Multiply(m int) *Pair {
	return NewPair(p.first*m, p.second*m)
}

func (p *Pair) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type Solver struct {
	INF  int
	LINF int
	M    int
	C    int
}

func NewSolver() *Solver {
	return &Solver{
		INF:  1e9,
		LINF: 1e18,
		M:    1e9 + 7,
		C:    20,
	}
}

func (s *Solver) Dag(g [][]int, cur []int) int {
	get := func(v int) int {
		for i := 0; i < len(cur); i++ {
			if cur[i] == v {
				return i
			}
		}
		return -1
	}

	n := len(cur)
	dp := make([]bool, 1<<n)
	reach := make([]int, n)

	for i := 0; i < n; i++ {
		for _, s := range g[cur[i]] {
			reach[i] |= 1 << get(s)
		}
	}

	res := 0
	dp[0] = true
	for m := 1; m < 1<<n; m++ {
		for i := 0; i < n; i++ {
			if m&(1<<i) != 0 {
				dp[m] = dp[m] || (dp[m^(1<<i)] && (reach[i]&m) == 0)
			}
		}
		if dp[m] {
			res = max(res, pct(m))
		}
	}

	return res
}

func (s *Solver) Solve() int {
	n := si()
	s := ss(n)
	t := ss(n)
	get := func(c byte) int {
		return int(c - 'a')
	}

	G := make([][]int, s)
	g := make([][]int, s)
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(s[i])
			b := get(t[i])
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			g[a] = append(g[a], b)
		}
	}

	cur := make([]int, 0)
	vis := make([]bool, s)
	dfs := func(v int) {
		vis[v] = true
		cur = append(cur, v)
		for _, s := range G[v] {
			if !vis[s] {
				dfs(s)
			}
		}
	}

	res := 0
	for i := 0; i < s; i++ {
		if !vis[i] {
			cur = make([]int, 0)
			dfs(i)
			s := s.Dag(g, cur)
			res += 2*len(cur) - 1 - s
		}
	}

	return res
}

func main() {
	t := si()
	for t > 0 {
		print(solve())
		t--
	}
}

func si() int {
	var x int
	fmt.Scan(&x)
	return x
}

func ss(n int) string {
	var x string
	fmt.Scan(&x)
	return x
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func pct(x int) int {
	res := 0
	for x > 0 {
		if x&1 == 1 {
			res++
		}
		x >>= 1
	}
	return res
}

func print(a ...interface{}) {
	fmt.Println(a...)
}
