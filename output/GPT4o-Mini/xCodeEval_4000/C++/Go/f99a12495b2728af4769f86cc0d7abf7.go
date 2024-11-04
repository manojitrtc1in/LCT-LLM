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
	x = (x % MOD + MOD) % MOD
	return ModInt{x}
}

func (a ModInt) Val() int {
	return a.x
}

func (a *ModInt) Add(b ModInt) {
	a.x = (a.x + b.x) % MOD
}

func (a *ModInt) Sub(b ModInt) {
	a.x = (a.x - b.x + MOD) % MOD
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

type NumberTheoreticTransform struct {
	dw    []ModInt
	idw   []ModInt
	maxBase int
	root  ModInt
}

func NewNumberTheoreticTransform() *NumberTheoreticTransform {
	ntt := &NumberTheoreticTransform{}
	ntt.maxBase = 0
	ntt.root = NewModInt(2)

	for (MOD-1)&1 == 0 {
		MOD >>= 1
		ntt.maxBase++
	}

	for ntt.root.Pow((MOD - 1) >> 1).Val() == 1 {
		ntt.root.Add(NewModInt(1))
	}

	ntt.dw = make([]ModInt, ntt.maxBase)
	ntt.idw = make([]ModInt, ntt.maxBase)

	for i := 0; i < ntt.maxBase; i++ {
		ntt.dw[i] = NewModInt(-ntt.root.Pow((MOD - 1) >> (i + 2)).Val())
		ntt.idw[i] = NewModInt(1).Inv().Mul(ntt.dw[i])
	}

	return ntt
}

func (ntt *NumberTheoreticTransform) NTT(a []ModInt) {
	n := len(a)
	for m := n; m >>= 1; {
		w := NewModInt(1)
		for s, k := 0, 0; s < n; s += 2 * m {
			for i, j := s, s+m; i < s+m; i, j = i+1, j+1 {
				x := a[i]
				y := NewModInt(0).Mul(a[j]).Mul(w)
				a[i].Add(y)
				a[j].Sub(y)
			}
			w.Mul(ntt.dw[__builtin_ctz(k)])
		}
	}
}

func (ntt *NumberTheoreticTransform) INT(a []ModInt, f bool) {
	n := len(a)
	for m := 1; m < n; m *= 2 {
		w := NewModInt(1)
		for s, k := 0, 0; s < n; s += 2 * m {
			for i, j := s, s+m; i < s+m; i, j = i+1, j+1 {
				x := a[i]
				y := a[j]
				a[i].Add(y)
				a[j].Mul(w).Sub(y)
			}
			w.Mul(ntt.idw[__builtin_ctz(k)])
		}
	}
	if f {
		invSz := NewModInt(1).Inv().Mul(NewModInt(n))
		for i := 0; i < n; i++ {
			a[i].Mul(invSz)
		}
	}
}

func (ntt *NumberTheoreticTransform) Multiply(a, b []ModInt) []ModInt {
	need := len(a) + len(b) - 1
	nbase := 1
	for (1 << nbase) < need {
		nbase++
	}
	sz := 1 << nbase
	a = append(a, make([]ModInt, sz-len(a))...)
	b = append(b, make([]ModInt, sz-len(b))...)
	ntt.NTT(a)
	ntt.NTT(b)
	invSz := NewModInt(1).Inv().Mul(NewModInt(sz))
	for i := 0; i < sz; i++ {
		a[i].Mul(b[i]).Mul(invSz)
	}
	ntt.INT(a, false)
	return a[:need]
}

type FormalPowerSeries []ModInt

func (fps FormalPowerSeries) Add(r FormalPowerSeries) FormalPowerSeries {
	ret := make(FormalPowerSeries, len(fps))
	copy(ret, fps)
	for i := range r {
		if i < len(ret) {
			ret[i].Add(r[i])
		} else {
			ret = append(ret, r[i])
		}
	}
	return ret
}

func (fps FormalPowerSeries) Sub(r FormalPowerSeries) FormalPowerSeries {
	ret := make(FormalPowerSeries, len(fps))
	copy(ret, fps)
	for i := range r {
		if i < len(ret) {
			ret[i].Sub(r[i])
		} else {
			ret = append(ret, NewModInt(0).Sub(r[i]))
		}
	}
	return ret
}

func (fps FormalPowerSeries) Mul(r FormalPowerSeries) FormalPowerSeries {
	ret := make(FormalPowerSeries, len(fps)+len(r)-1)
	ntt := NewNumberTheoreticTransform()
	return ret
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

	res := NewModInt(k).Pow(cnt)
	sum := NewModInt(0)

	f := make(FormalPowerSeries, 2*d+1)
	f[0] = NewModInt(1)
	f[1] = NewModInt(k - 2)
	f[2] = NewModInt(1)
	f = f.Pow(d)

	for i := d + 1; i <= 2*d; i++ {
		sum.Add(f[i])
	}

	fmt.Println(res.Mul(sum))
}
