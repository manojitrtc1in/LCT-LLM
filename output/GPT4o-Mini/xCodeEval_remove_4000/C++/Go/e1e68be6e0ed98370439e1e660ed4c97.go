package main

import (
	"fmt"
	"math/big"
)

const mod = STATIC_MOD

type ModInt struct {
	x int
}

func NewModInt(y int) ModInt {
	return ModInt{x: (mod + y%mod) % mod}
}

func (m ModInt) Value() int {
	return m.x
}

func add(l, r ModInt) ModInt {
	x := int64(l.Value() + r.Value())
	if x >= mod {
		x -= mod
	}
	return NewModInt(int(x))
}

func mul(l, r ModInt) ModInt {
	return NewModInt((l.Value() * r.Value()) % mod)
}

func pow(a ModInt, x int64) ModInt {
	ret := NewModInt(1)
	for x > 0 {
		if x&1 == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		x >>= 1
	}
	return ret
}

func inv(x ModInt) ModInt {
	a, b := int64(x.Value()), int64(mod)
	u, v := int64(1), int64(0)
	for b > 0 {
		t := a / b
		a, b = b, a-t*b
		u, v = v, u-t*v
	}
	return NewModInt(int(u))
}

func (m *ModInt) Add(r int) {
	*m = add(*m, NewModInt(r))
}

func (m *ModInt) Sub(r int) {
	*m = add(*m, NewModInt(mod-r))
}

func (m *ModInt) Mul(r int) {
	*m = mul(*m, NewModInt(r))
}

func (m *ModInt) Div(r int) {
	*m = mul(*m, inv(NewModInt(r)))
}

var factorial []ModInt
var inverseFactorial []ModInt
var isBuild bool

func buildFactorials(size int) {
	isBuild = true
	factorial = make([]ModInt, size)
	inverseFactorial = make([]ModInt, size)
	factorial[0] = NewModInt(1)
	for i := 1; i < size; i++ {
		factorial[i] = mul(factorial[i-1], NewModInt(i))
	}
	inverseFactorial[size-1] = inv(factorial[size-1])
	for i := size - 1; i >= 1; i-- {
		inverseFactorial[i-1] = mul(inverseFactorial[i], NewModInt(i))
	}
}

func combination(n, k int) ModInt {
	if k < 0 || k > n {
		return NewModInt(0)
	}
	if !isBuild {
		buildFactorials(3123456)
	}
	return mul(factorial[n], mul(inverseFactorial[k], inverseFactorial[n-k]))
}

func multiChoose(n, r int) ModInt {
	if n == 0 {
		if r == 0 {
			return NewModInt(1)
		}
		return NewModInt(0)
	}
	return combination(n+r-1, r)
}

func main() {
	var p, s, r int
	fmt.Scan(&p, &s, &r)
	ret := NewModInt(0)

	for top := r; top <= s; top++ {
		tot := NewModInt(0)
		for q := 0; q < p; q++ {
			if top*q > s-top {
				break
			}
			tot.Add(mul(combination(p-1, q), mul(multiChoose(p-q-1, s-top-top*q), inv(q+1))))
		}
		ret.Add(tot)
	}
	ret.Mul(int(inv(multiChoose(p, s-r).Value())))
	fmt.Println(ret.Value())
}
