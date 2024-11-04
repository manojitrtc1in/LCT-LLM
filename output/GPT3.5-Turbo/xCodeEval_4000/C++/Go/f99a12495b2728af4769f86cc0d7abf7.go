package main

import (
	"fmt"
)

const MOD = 998244353

type ModInt struct {
	x int
}

func NewModInt(x int) ModInt {
	if x >= MOD {
		x -= MOD
	}
	return ModInt{x: x}
}

func (a ModInt) Add(b ModInt) ModInt {
	x := a.x + b.x
	if x >= MOD {
		x -= MOD
	}
	return ModInt{x: x}
}

func (a ModInt) Sub(b ModInt) ModInt {
	x := a.x - b.x
	if x < 0 {
		x += MOD
	}
	return ModInt{x: x}
}

func (a ModInt) Mul(b ModInt) ModInt {
	x := (a.x * b.x) % MOD
	return ModInt{x: x}
}

func (a ModInt) Pow(n int) ModInt {
	res := ModInt{x: 1}
	mul := a
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(mul)
		}
		mul = mul.Mul(mul)
		n >>= 1
	}
	return res
}

func (a ModInt) Inv() ModInt {
	return a.Pow(MOD - 2)
}

func (a ModInt) Div(b ModInt) ModInt {
	return a.Mul(b.Inv())
}

func (a ModInt) String() string {
	return fmt.Sprintf("%d", a.x)
}

type FormalPowerSeries []ModInt

func NewFormalPowerSeries(n int) FormalPowerSeries {
	return make(FormalPowerSeries, n)
}

func (a FormalPowerSeries) Add(b FormalPowerSeries) FormalPowerSeries {
	n := len(a)
	if len(b) > n {
		n = len(b)
	}
	res := NewFormalPowerSeries(n)
	for i := 0; i < len(a); i++ {
		res[i] = res[i].Add(a[i])
	}
	for i := 0; i < len(b); i++ {
		res[i] = res[i].Add(b[i])
	}
	return res
}

func (a FormalPowerSeries) Sub(b FormalPowerSeries) FormalPowerSeries {
	n := len(a)
	if len(b) > n {
		n = len(b)
	}
	res := NewFormalPowerSeries(n)
	for i := 0; i < len(a); i++ {
		res[i] = res[i].Add(a[i])
	}
	for i := 0; i < len(b); i++ {
		res[i] = res[i].Sub(b[i])
	}
	return res
}

func (a FormalPowerSeries) Mul(b FormalPowerSeries) FormalPowerSeries {
	n := len(a) + len(b) - 1
	res := NewFormalPowerSeries(n)
	for i := 0; i < len(a); i++ {
		for j := 0; j < len(b); j++ {
			res[i+j] = res[i+j].Add(a[i].Mul(b[j]))
		}
	}
	return res
}

func (a FormalPowerSeries) Pow(n int) FormalPowerSeries {
	res := NewFormalPowerSeries(len(a))
	res[0] = NewModInt(1)
	mul := a
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(mul)
		}
		mul = mul.Mul(mul)
		n >>= 1
	}
	return res
}

func (a FormalPowerSeries) String() string {
	res := ""
	for i := 0; i < len(a); i++ {
		res += fmt.Sprintf("%s ", a[i].String())
	}
	return res
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	h := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&h[i])
	}
	h = append(h, h[0])

	cnt := 0
	for i := 0; i < n; i++ {
		if h[i] == h[i+1] {
			cnt++
		}
	}
	d := n - cnt

	res := NewModInt(k).Pow(cnt)
	sum := NewModInt(0)

	f := NewFormalPowerSeries(2*d + 1)
	f[0] = NewModInt(1)
	f[1] = NewModInt(k - 2)
	f[2] = NewModInt(1)
	f = f.Pow(d)
	for i := d + 1; i < 2*d+1; i++ {
		sum = sum.Add(f[i])
	}

	res = res.Mul(sum)

	fmt.Println(res)
}
