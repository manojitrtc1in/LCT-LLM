package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const mod = 998244353

type ModInt struct {
	x int
}

func NewModInt(y int) ModInt {
	return ModInt{(mod + y%mod) % mod}
}

func (m ModInt) Add(n ModInt) ModInt {
	return NewModInt(m.x + n.x)
}

func (m ModInt) Mul(n ModInt) ModInt {
	return NewModInt(m.x * n.x % mod)
}

func (m ModInt) Pow(x int64) ModInt {
	ret := NewModInt(1)
	a := m
	for x > 0 {
		if x&1 == 1 {
			ret = ret.Mul(a)
		}
		a = a.Mul(a)
		x >>= 1
	}
	return ret
}

func (m ModInt) Inv() ModInt {
	a := m.x
	b := mod
	u := 1
	v := 0
	for b != 0 {
		t := a / b
		a, b = a-t*b, t
		u, v = u-t*v, t
	}
	return NewModInt(u)
}

func (m ModInt) Neg() ModInt {
	return NewModInt(mod - m.x)
}

func (m ModInt) Sub(n ModInt) ModInt {
	return m.Add(n.Neg())
}

func (m ModInt) Equal(n ModInt) bool {
	return m.x == n.x
}

func (m ModInt) Int64() int64 {
	return int64(m.x)
}

func (m ModInt) String() string {
	return strconv.Itoa(m.x)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	p := nextInt(scanner)
	s := nextInt(scanner)
	r := nextInt(scanner)

	ret := NewModInt(0)
	for top := r; top <= s; top++ {
		tot := NewModInt(0)
		for q := 0; q < p; q++ {
			if top*q > s-top {
				break
			}
			tot = tot.Add(
				combination(p-1, q).
					Mul(multiChoose(p-q-1, s-top-top*q, top-1)).
					Mul(NewModInt(q+1).Inv()),
			)
		}
		ret = ret.Add(tot)
	}

	ret = ret.Mul(multiChoose(p, s-r).Inv())
	fmt.Println(ret.Int64())
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func combination(n, k int) ModInt {
	if k < 0 || k > n {
		return NewModInt(0)
	}
	return factorial(n).Mul(factorialInv(k)).Mul(factorialInv(n - k))
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
		ret = ret.Add(
			NewModInt((i&1)*mod-1).
				Mul(combination(n, i)).
				Mul(multiChoose(n, r-i*(lim+1), top-1)),
		)
	}
	return ret
}

func factorial(n int) ModInt {
	f := NewModInt(1)
	for i := 2; i <= n; i++ {
		f = f.Mul(NewModInt(i))
	}
	return f
}

func factorialInv(n int) ModInt {
	f := NewModInt(1)
	for i := 2; i <= n; i++ {
		f = f.Mul(NewModInt(i).Inv())
	}
	return f
}
