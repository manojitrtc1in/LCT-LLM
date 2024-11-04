package main

import (
	"fmt"
	"math"
)

const MOD7 = 1000000007
const MOD9 = 1000000009
const MODF = 998244353

var mod int

type ModInt struct {
	n int
}

func NewModInt(n int) ModInt {
	if n < 0 {
		n += mod
	}
	return ModInt{n % mod}
}

func (a ModInt) Add(b ModInt) ModInt {
	return NewModInt(a.n + b.n)
}

func (a ModInt) Sub(b ModInt) ModInt {
	return NewModInt(a.n - b.n)
}

func (a ModInt) Mul(b ModInt) ModInt {
	return NewModInt(a.n * b.n)
}

func (a ModInt) Inverse() ModInt {
	x, y, g := gcd(a.n, mod)
	if g != 1 {
		panic("not inversable")
	}
	return NewModInt(x)
}

func gcd(a, b int) (int, int, int) {
	if a == 0 {
		return 0, 1, b
	}
	x1, y1, g := gcd(b%a, a)
	x := y1 - (b/a)*x1
	y := x1
	return x, y, g
}

type FenwickTree struct {
	value []ModInt
}

func NewFenwickTree(size int) *FenwickTree {
	return &FenwickTree{value: make([]ModInt, size)}
}

func (ft *FenwickTree) Add(at int, v ModInt) {
	for at < len(ft.value) {
		ft.value[at] = ft.value[at].Add(v)
		at |= at + 1
	}
}

func (ft *FenwickTree) Get(to int) ModInt {
	result := ModInt{0}
	for to >= 0 {
		result = result.Add(ft.value[to])
		to = (to & (to + 1)) - 1
	}
	return result
}

func (ft *FenwickTree) GetRange(from, to int) ModInt {
	if from >= to {
		return ModInt{0}
	}
	return ft.Get(to - 1).Sub(ft.Get(from - 1))
}

type BVerkhnyayaYacheika struct{}

func (solver *BVerkhnyayaYacheika) Solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mod = m
	ft := NewFenwickTree(n + 1)
	ft.Add(n, NewModInt(1))
	for i := n; i >= 1; i-- {
		res := ft.GetRange(i+1, n+1)
		for z := 2; z*i <= n; z++ {
			res = res.Add(ft.GetRange(z*i, z*i+z))
		}
		ft.Add(i, res)
	}
	fmt.Println(ft.GetRange(1, 2).n)
}

func main() {
	var solver BVerkhnyayaYacheika
	solver.Solve()
}
