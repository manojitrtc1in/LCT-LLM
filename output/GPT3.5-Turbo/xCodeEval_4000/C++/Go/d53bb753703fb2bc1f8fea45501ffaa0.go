package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Modular struct {
	value int
	MOD   int
}

func NewModular(v, mod int) *Modular {
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

func (m *Modular) Exponent(k int) *Modular {
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
	return m.Exponent(m.MOD - 2)
}

func (m *Modular) String() string {
	return strconv.Itoa(m.value)
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

type Solver struct {
	G     [][]int
	cur   []int
	masks []int
	dp    []bool
	vis   []bool
	mask  int
}

func NewSolver() *Solver {
	s := &Solver{
		G:     make([][]int, 20),
		cur:   make([]int, 0),
		masks: make([]int, 20),
		dp:    make([]bool, 1<<20),
		vis:   make([]bool, 20),
		mask:  0,
	}
	for i := 0; i < 20; i++ {
		s.G[i] = make([]int, 0)
	}
	return s
}

func (s *Solver) dfs(v int) {
	s.vis[v] = true
	s.mask |= 1 << v
	s.cur = append(s.cur, v)
	for _, s := range s.G[v] {
		if !s.vis[s] {
			s.dfs(s)
		}
	}
}

func (s *Solver) count() int {
	sub := make([]int, 0)
	m := s.mask
	for m > 0 {
		sub = append(sub, m)
		m = (m - 1) & s.mask
	}
	for i := len(sub) - 1; i >= 0; i-- {
		m := sub[i]
		for _, v := range s.cur {
			if m&(1<<v) > 0 {
				s.dp[m] = s.dp[m] || (s.dp[m^(1<<v)] && ((m&s.masks[v]&s.mask) == 0))
			}
		}
	}
	res := 0
	for _, m := range sub {
		if s.dp[m] {
			res = max(res, bitCount(m))
		}
	}
	return res
}

func (s *Solver) Solve() int {
	n := si()
	s1 := ss(n)
	s2 := ss(n)

	get := func(c byte) int {
		return int(c - 'a')
	}

	for i := 0; i < n; i++ {
		if s1[i] != s2[i] {
			a := get(s1[i])
			b := get(s2[i])
			s.G[a] = append(s.G[a], b)
			s.G[b] = append(s.G[b], a)
			s.masks[a] |= 1 << b
		}
	}

	res := 0
	s.dp[0] = true
	for i := 0; i < 20; i++ {
		if !s.vis[i] {
			s.mask = 0
			s.cur = make([]int, 0)
			s.dfs(i)
			tmp := s.count()
			res += 2*len(s.cur) - 1 - tmp
		}
	}

	for i := 0; i < 20; i++ {
		s.vis[i] = false
		s.masks[i] = 0
		s.G[i] = make([]int, 0)
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func bitCount(x int) int {
	count := 0
	for x > 0 {
		count++
		x &= x - 1
	}
	return count
}

func main() {
	t := si()
	for t > 0 {
		print(solve())
		t--
	}
}

var scanner *bufio.Scanner

func init() {
	scanner = bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
}

func si() int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func ss(n int) string {
	scanner.Scan()
	return scanner.Text()
}

func solve() int {
	return NewSolver().Solve()
}

func print(a ...interface{}) {
	fmt.Println(a...)
}
