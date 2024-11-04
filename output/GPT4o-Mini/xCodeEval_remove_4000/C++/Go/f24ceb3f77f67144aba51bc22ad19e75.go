package main

import (
	"fmt"
	"math"
	"os"
)

const MOD7 = 1000000007
const MOD9 = 1000000009
const MODF = 998244353

var mod int64 = MOD7

func gcd(a, b int64) (int64, int64, int64) {
	if a == 0 {
		return 0, 1, b
	}
	x, y, d := gcd(b%a, a)
	x -= (b / a) * y
	return x, y, d
}

type ModInt struct {
	n int64
}

func NewModInt(n int64) ModInt {
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

func (a ModInt) Div(b ModInt) ModInt {
	if b.n == 0 {
		panic("Division by zero")
	}
	return a.Mul(b.Inverse())
}

func (a ModInt) Inverse() ModInt {
	x, _, g := gcd(a.n, mod)
	if g != 1 {
		panic("not inversable")
	}
	return NewModInt(x)
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

func (ft *FenwickTree) Get(from, to int) ModInt {
	if from >= to {
		return NewModInt(0)
	}
	return ft.get(to - 1).Sub(ft.get(from - 1))
}

func (ft *FenwickTree) get(to int) ModInt {
	result := NewModInt(0)
	for to >= 0 {
		result = result.Add(ft.value[to])
		to = (to & (to + 1)) - 1
	}
	return result
}

type BVerkhnyayaYacheika struct{}

func (solver *BVerkhnyayaYacheika) Solve() {
	var n, m int
	fmt.Scan(&n, &m)

	mod = int64(m)
	ft := NewFenwickTree(n + 1)
	ft.Add(n, NewModInt(1))
	for i := n; i >= 1; i-- {
		res := ft.Get(i+1, n+1)
		for z := 2; z*i <= n; z++ {
			res = res.Add(ft.Get(z*i, z*i+z))
		}
		ft.Add(i, res)
	}
	fmt.Println(ft.Get(1, 2).n)
}

func main() {
	f, _ := os.Open("input.txt")
	defer f.Close()
	fmt.SetScan(f)

	solver := BVerkhnyayaYacheika{}
	solver.Solve()
}
