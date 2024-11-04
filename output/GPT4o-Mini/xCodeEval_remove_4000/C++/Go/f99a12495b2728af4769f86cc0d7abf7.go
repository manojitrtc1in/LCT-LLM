package main

import (
	"fmt"
	"math/rand"
)

const MOD = 998244353

type ModInt struct {
	x int
}

func NewModInt(x int) ModInt {
	if x < 0 {
		x += MOD
	}
	return ModInt{x % MOD}
}

func (a ModInt) Val() int {
	return a.x
}

func (a *ModInt) Add(b ModInt) {
	a.x += b.x
	if a.x >= MOD {
		a.x -= MOD
	}
}

func (a *ModInt) Sub(b ModInt) {
	a.x -= b.x
	if a.x < 0 {
		a.x += MOD
	}
}

func (a *ModInt) Mul(b ModInt) {
	a.x = (int64(a.x) * int64(b.x)) % MOD
}

func (a *ModInt) Inv() ModInt {
	return a.Pow(MOD - 2)
}

func (a *ModInt) Pow(n int) ModInt {
	res := NewModInt(1)
	base := a
	for n > 0 {
		if n&1 == 1 {
			res.Mul(*base)
		}
		base.Mul(*base)
		n >>= 1
	}
	return res
}

type FPS []ModInt

func (f FPS) Add(g FPS) FPS {
	n := len(f)
	if len(g) > n {
		n = len(g)
	}
	res := make(FPS, n)
	for i := 0; i < n; i++ {
		if i < len(f) {
			res[i].Add(f[i])
		}
		if i < len(g) {
			res[i].Add(g[i])
		}
	}
	return res
}

func (f FPS) Mul(g FPS) FPS {
	res := make(FPS, len(f)+len(g)-1)
	for i := 0; i < len(f); i++ {
		for j := 0; j < len(g); j++ {
			res[i+j].Add(f[i].Mul(g[j]))
		}
	}
	return res
}

func (f FPS) Pow(n int) FPS {
	res := FPS{NewModInt(1)}
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(f)
		}
		f = f.Mul(f)
		n >>= 1
	}
	return res
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	h := make([]int, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}
	h[n] = h[0]

	cnt := 0
	for i := 0; i < n; i++ {
		if h[i] == h[i+1] {
			cnt++
		}
	}
	d := n - cnt

	res := NewModInt(1).Pow(cnt)
	sum := NewModInt(0)

	f := make(FPS, 2*d+1)
	f[0] = NewModInt(1)
	f[1] = NewModInt(k - 2)
	f[2] = NewModInt(1)
	f = f.Pow(d)

	for i := d + 1; i <= 2*d; i++ {
		sum.Add(f[i])
	}

	fmt.Println(res.Mul(sum).Val())
}
