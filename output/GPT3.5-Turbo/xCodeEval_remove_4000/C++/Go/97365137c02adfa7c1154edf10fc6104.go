package main

import (
	"fmt"
)

type Modular struct {
	value int
}

func NewModular(v int) *Modular {
	mod := &Modular{
		value: v % 7,
	}
	if mod.value < 0 {
		mod.value += 7
	}
	return mod
}

func (m *Modular) Add(o *Modular) *Modular {
	m.value += o.value
	if m.value >= 7 {
		m.value -= 7
	}
	return m
}

func (m *Modular) Subtract(o *Modular) *Modular {
	m.value -= o.value
	if m.value < 0 {
		m.value += 7
	}
	return m
}

func (m *Modular) Multiply(o *Modular) *Modular {
	m.value = (m.value * o.value) % 7
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
	return m.Exponentiate(7 - 2)
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

func (p *Pair) Multiply(mult int) *Pair {
	return NewPair(p.first*mult, p.second*mult)
}

func (p *Pair) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type Triple struct {
	first  int
	second int
	third  int
}

func NewTriple(f, s, t int) *Triple {
	return &Triple{
		first:  f,
		second: s,
		third:  t,
	}
}

func (t *Triple) String() string {
	return fmt.Sprintf("(%d, %d, %d)", t.first, t.second, t.third)
}

type Complex struct {
	real      float64
	imaginary float64
}

func NewComplex(r, i float64) *Complex {
	return &Complex{
		real:      r,
		imaginary: i,
	}
}

func (c *Complex) String() string {
	return fmt.Sprintf("(%f + %fi)", c.real, c.imaginary)
}

type String string

func NewString(s string) *String {
	str := String(s)
	return &str
}

func (s *String) String() string {
	return string(*s)
}

type IntPair struct {
	first  int
	second int
}

func NewIntPair(f, s int) *IntPair {
	return &IntPair{
		first:  f,
		second: s,
	}
}

func (p *IntPair) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type IntTriple struct {
	first  int
	second int
	third  int
}

func NewIntTriple(f, s, t int) *IntTriple {
	return &IntTriple{
		first:  f,
		second: s,
		third:  t,
	}
}

func (t *IntTriple) String() string {
	return fmt.Sprintf("(%d, %d, %d)", t.first, t.second, t.third)
}

type IntComplex struct {
	real      int
	imaginary int
}

func NewIntComplex(r, i int) *IntComplex {
	return &IntComplex{
		real:      r,
		imaginary: i,
	}
}

func (c *IntComplex) String() string {
	return fmt.Sprintf("(%d + %di)", c.real, c.imaginary)
}

type IntString string

func NewIntString(s string) *IntString {
	str := IntString(s)
	return &str
}

func (s *IntString) String() string {
	return string(*s)
}

type IntIntPair struct {
	first  int
	second int
}

func NewIntIntPair(f, s int) *IntIntPair {
	return &IntIntPair{
		first:  f,
		second: s,
	}
}

func (p *IntIntPair) String() string {
	return fmt.Sprintf("(%d, %d)", p.first, p.second)
}

type IntIntTriple struct {
	first  int
	second int
	third  int
}

func NewIntIntTriple(f, s, t int) *IntIntTriple {
	return &IntIntTriple{
		first:  f,
		second: s,
		third:  t,
	}
}

func (t *IntIntTriple) String() string {
	return fmt.Sprintf("(%d, %d, %d)", t.first, t.second, t.third)
}

type IntIntComplex struct {
	real      int
	imaginary int
}

func NewIntIntComplex(r, i int) *IntIntComplex {
	return &IntIntComplex{
		real:      r,
		imaginary: i,
	}
}

func (c *IntIntComplex) String() string {
	return fmt.Sprintf("(%d + %di)", c.real, c.imaginary)
}

type IntIntString string

func NewIntIntString(s string) *IntIntString {
	str := IntIntString(s)
	return &str
}

func (s *IntIntString) String() string {
	return string(*s)
}

func main() {
	var t int
	fmt.Scanf("%d", &t)
	for t > 0 {
		fmt.Println(solve())
		t--
	}
}

func solve() int {
	var n int
	fmt.Scanf("%d", &n)
	var s, t string
	fmt.Scanf("%s", &s)
	fmt.Scanf("%s", &t)

	get := func(c byte) int {
		return int(c - 'a')
	}

	G := make([][]int, 20)
	cur := make([]int, 0)
	masks := make([]int, 20)
	dp := make([]bool, 1<<20)
	vis := make([]bool, 20)
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
				if (m & (1 << v)) != 0 {
					dp[m] = dp[m^(1<<v)] && ((m & masks[v] & mask) == 0)
				}
			}
			if dp[m] {
				res = max(res, pct(m))
			}
		}
		return res
	}

	n = len(s)
	for i := 0; i < n; i++ {
		if s[i] != t[i] {
			a := get(s[i])
			b := get(t[i])
			G[a] = append(G[a], b)
			G[b] = append(G[b], a)
			masks[a] |= 1 << b
		}
	}

	res := 0
	dp[0] = true
	for i := 0; i < 20; i++ {
		if !vis[i] {
			mask = 0
			cur = cur[:0]
			dfs(i)
			tmp := count()
			res += 2*len(cur) - 1 - tmp
		}
	}

	for i := 0; i < 20; i++ {
		vis[i] = false
		masks[i] = 0
		G[i] = G[i][:0]
	}
	for i := 0; i < (1 << 20); i++ {
		dp[i] = false
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
