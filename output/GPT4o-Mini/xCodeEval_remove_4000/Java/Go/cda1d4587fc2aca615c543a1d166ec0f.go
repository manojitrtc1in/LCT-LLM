package main

import (
	"fmt"
	"math"
	"os"
)

type Modular struct {
	m int
}

func NewModular(m int) Modular {
	return Modular{m: m}
}

func (mod Modular) valueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod Modular) mul(x, y int) int {
	return mod.valueOf(x * y)
}

type Power struct {
	modular Modular
}

func NewPower(modular Modular) Power {
	return Power{modular: modular}
}

func (p Power) pow(x, n int) int {
	if n == 0 {
		return p.modular.valueOf(1)
	}
	r := p.pow(x, n>>1)
	r = p.modular.valueOf(r * r)
	if n&1 == 1 {
		r = p.modular.valueOf(r * x)
	}
	return r
}

type FCards struct {
	mod Modular
}

func NewFCards() FCards {
	return FCards{mod: NewModular(998244353)}
}

func (solver FCards) solve(n, m, k int) int {
	pm := NewCachedPow(m, solver.mod)
	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = NewPower(solver.mod).pow(i, k)
	}

	ans := 0
	bc := NewId1(n, k, solver.mod)
	for t := 0; t <= k; t++ {
		p1 := bc.get(t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := NewComposite(t, i, solver.mod)
			contrib = solver.mod.mul(contrib, xk[t-i])
			if i%2 == 1 {
				contrib = solver.mod.valueOf(-contrib)
			}
			p2 = solver.mod.valueOf(p2 + contrib)
		}
		p3 := pm.inverse(t)

		contrib := solver.mod.mul(p1, p2)
		contrib = solver.mod.mul(contrib, p3)
		ans = solver.mod.valueOf(ans + contrib)
	}

	return ans
}

type CachedPow struct {
	first  []int
	second []int
	mod    Modular
}

func NewCachedPow(x, maxExp int, mod Modular) CachedPow {
	k := int(math.Max(1, math.Sqrt(float64(maxExp))))
	first := make([]int, k)
	second := make([]int, maxExp/k+1)
	first[0] = 1
	for i := 1; i < k; i++ {
		first[i] = mod.mul(x, first[i-1])
	}
	second[0] = 1
	step := mod.mul(x, first[k-1])
	for i := 1; i < len(second); i++ {
		second[i] = mod.mul(second[i-1], step)
	}
	return CachedPow{first: first, second: second, mod: mod}
}

func (cp CachedPow) pow(exp int) int {
	return cp.mod.mul(cp.first[exp%len(cp.first)], cp.second[exp/len(cp.first)])
}

func (cp CachedPow) inverse(exp int) int {
	return cp.pow(-exp)
}

type Id1 struct {
	m   int
	mod Modular
	id8 []int
}

func NewId1(n, m int, mod Modular) Id1 {
	id8 := make([]int, m+1)
	id8[0] = 1
	for i := 1; i <= n; i++ {
		id8[i] = mod.valueOf(id8[i-1] * i)
	}
	return Id1{m: m, mod: mod, id8: id8}
}

func (id Id1) get(i int) int {
	return id.id8[i]
}

func main() {
	var n, m, k int
	fmt.Scan(&n, &m, &k)

	solver := NewFCards()
	ans := solver.solve(n, m, k)
	fmt.Println(ans)
}
