package main

import (
	"fmt"
)

const mod int = STATIC_MOD

type ModInt struct {
	x int
}

func (m ModInt) Value() int {
	return m.x
}

func add(l, r ModInt) ModInt {
	x := l.Value() + r.Value()
	if x >= mod {
		x -= mod
	}
	return ModInt{x}
}

func mul(l, r ModInt) ModInt {
	return ModInt{(l.Value() * r.Value()) % mod}
}

func pow(a ModInt, x int) ModInt {
	ret := ModInt{1}
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
	a, b, u, v := x.Value(), mod, 1, 0
	for b != 0 {
		t := a / b
		a, b = a-t*b, t
		u, v = u-t*v, v
	}
	if u < 0 {
		u += mod
	}
	return ModInt{u}
}

func sub(x ModInt) ModInt {
	return add(ModInt{mod}, ModInt{-x.Value()})
}

func main() {
	var p, s, r int
	fmt.Scanf("%d%d%d", &p, &s, &r)
	ret := ModInt{0}
	for top := r; top <= s; top++ {
		tot := ModInt{0}
		for q := 0; q < p; q++ {
			if top*q > s-top {
				break
			}
			tot = add(tot, mul(mul(factorial.combination(p-1, q), factorial.multiChoose(p-q-1, s-top-top*q, top-1)), inv(ModInt{q + 1})))
		}
		ret = add(ret, tot)
	}
	ret = mul(ret, inv(factorial.multiChoose(p, s-r)))
	fmt.Println(ret.Value())
}
