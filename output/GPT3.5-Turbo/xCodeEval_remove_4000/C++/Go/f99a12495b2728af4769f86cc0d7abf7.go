package main

import (
	"fmt"
)

const MOD int = 998244353

type ModInt struct {
	x int
}

func NewModInt(x int) ModInt {
	if x < 0 {
		x += MOD
	}
	return ModInt{x: x % MOD}
}

func (a ModInt) Add(b ModInt) ModInt {
	return NewModInt(a.x + b.x)
}

func (a ModInt) Sub(b ModInt) ModInt {
	return NewModInt(a.x - b.x)
}

func (a ModInt) Mul(b ModInt) ModInt {
	return NewModInt(a.x * b.x)
}

func (a ModInt) Pow(n int) ModInt {
	res := NewModInt(1)
	for n > 0 {
		if n&1 == 1 {
			res = res.Mul(a)
		}
		a = a.Mul(a)
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

	f := make([]ModInt, 2*d+1)
	f[0] = NewModInt(1)
	f[1] = NewModInt(k - 2)
	f[2] = NewModInt(1)
	for i := 0; i < d; i++ {
		f = convolute(f, f)
	}
	for i := d + 1; i <= 2*d; i++ {
		sum = sum.Add(f[i])
	}

	fmt.Println(res.Mul(sum))
}

func convolute(a, b []ModInt) []ModInt {
	n := len(a)
	m := len(b)
	res := make([]ModInt, n+m-1)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			res[i+j] = res[i+j].Add(a[i].Mul(b[j]))
		}
	}
	return res
}
