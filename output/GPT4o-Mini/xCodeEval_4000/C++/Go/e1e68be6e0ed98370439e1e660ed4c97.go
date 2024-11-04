package main

import (
	"fmt"
	"math/big"
)

const (
	DECIMAL_DIGITS = 10
	STATIC_MOD     = 998244353
)

var mod int

type ModInt struct {
	x int
}

func NewModInt(y int64) ModInt {
	return ModInt{int((mod + y%int64(mod)) % int64(mod))}
}

func (m ModInt) Value() int64 {
	return int64(m.x)
}

func add(l, r ModInt) ModInt {
	x := l.Value() + r.Value()
	return NewModInt(x)
}

func mul(l, r ModInt) ModInt {
	return NewModInt(l.Value() * r.Value() % int64(mod))
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
	a, b := x.Value(), int64(mod)
	u, v := int64(1), int64(0)
	for b != 0 {
		t := a / b
		a, b = b, a-t*b
		u, v = v, u-t*v
	}
	return NewModInt(u)
}

func (m *ModInt) Add(r int) {
	*m = add(*m, NewModInt(int64(r)))
}

func (m *ModInt) Sub(r int) {
	*m = add(*m, NewModInt(int64(mod-r)))
}

func (m *ModInt) Mul(r int) {
	*m = mul(*m, NewModInt(int64(r)))
}

func (m *ModInt) Div(r int) {
	*m = mul(*m, inv(NewModInt(int64(r))))
}

func combination(n, k int) ModInt {
	if k < 0 || k > n {
		return NewModInt(0)
	}
	return factorial[n].Mul(inverseFactorial[k]).Mul(inverseFactorial[n-k])
}

var factorial []ModInt
var inverseFactorial []ModInt

func buildFactorials(size int) {
	factorial = make([]ModInt, size)
	inverseFactorial = make([]ModInt, size)
	factorial[0] = NewModInt(1)
	for i := 1; i < size; i++ {
		factorial[i] = mul(factorial[i-1], NewModInt(int64(i)))
	}
	inverseFactorial[size-1] = inv(factorial[size-1])
	for i := size - 1; i >= 1; i-- {
		inverseFactorial[i-1] = mul(inverseFactorial[i], NewModInt(int64(i)))
	}
}

func multiChoose(n, r, lim int) ModInt {
	if n == 0 {
		if r == 0 {
			return NewModInt(1)
		}
		return NewModInt(0)
	}
	if lim <= 0 && r > 0 {
		return NewModInt(0)
	}
	if r == 0 {
		if lim < 0 {
			return NewModInt(0)
		}
		return NewModInt(1)
	}
	ret := NewModInt(0)
	for i := 0; i <= n; i++ {
		if i*(lim+1) > r {
			break
		}
		sign := 1
		if i&1 == 1 {
			sign = -1
		}
		ret.Add(sign * int(combination(n, i).Value()) * int(multiChoose(n, r-i*(lim+1)).Value()))
	}
	return ret
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
			tot.Add(factorial[p-1].Mul(combination(p-q-1, s-top-top*q)).Mul(inv(q + 1)))
		}
		ret.Add(tot)
	}
	ret = mul(ret, inv(multiChoose(p, s-r)))
	fmt.Println(ret.Value())
}
