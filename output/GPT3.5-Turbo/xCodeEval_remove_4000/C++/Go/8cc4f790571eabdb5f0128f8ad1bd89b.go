package main

import (
	"fmt"
	"math"
)

type frac struct {
	n int
	d int
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func newFrac(n, d int) frac {
	g := gcd(int(math.Abs(float64(n))), d)
	n /= g
	d /= g
	return frac{n, d}
}

func (f frac) add(b frac) frac {
	return newFrac(f.n*b.d+b.n*f.d, f.d*b.d)
}

func (f frac) sub(b frac) frac {
	return newFrac(f.n*b.d-b.n*f.d, f.d*b.d)
}

func (f frac) mul(b frac) frac {
	return newFrac(f.n*b.n, f.d*b.d)
}

func (f frac) div(b frac) frac {
	return newFrac(f.n*b.d, f.d*b.n)
}

func (f frac) floor() int {
	return f.n / f.d
}

func (f frac) ceil() int {
	return f.n/f.d + 1
}

func (f frac) toCont() []int {
	if f.d == 0 {
		return []int{0}
	}
	cont := []int{}
	n := f.n
	d := f.d
	for {
		f := (n/d + 1) * d / n
		cont = append(cont, f)
		n = f*n - d
		d = d * f
		g := gcd(int(math.Abs(float64(n))), d)
		n /= g
		d /= g
		if n == 0 {
			break
		}
	}
	return cont
}

func fromCont(cont []int) frac {
	n := 1
	d := 0
	for i := len(cont) - 1; i >= 0; i-- {
		n, d = d, n
		n += d * cont[i]
	}
	return newFrac(n, d)
}

func bestIn(x, y frac) frac {
	if x.n == y.n && x.d == y.d {
		return frac{}
	}
	if x.n*y.d < y.n*x.d {
		return frac{}
	}
	x1 := x.toCont()
	y1 := y.toCont()
	x2 := make([]int, len(x1))
	copy(x2, x1)
	x2[len(x2)-1]--
	x2 = append(x2, 1)
	y2 := make([]int, len(y1))
	copy(y2, y1)
	y2[len(y2)-1]--
	y2 = append(y2, 1)

	z := func(a, b []int) frac {
		c := []int{}
		for i := 0; ; i++ {
			ai := 0
			if i < len(a) {
				ai = a[i]
			}
			bi := 0
			if i < len(b) {
				bi = b[i]
			}
			if ai != bi {
				c = append(c, min(ai, bi)+1)
				return fromCont(c)
			}
			c = append(c, ai)
		}
	}

	ans := frac{}
	for _, f := range []frac{z(x1, y1), z(x1, y2), z(x2, y1), z(x2, y2)} {
		if x.n < f.n && f.n < y.n && (ans.d == 0 || f.d < ans.d) {
			ans = f
		}
	}
	return ans
}

type modnum struct {
	v int
}

func newModnum(v int) modnum {
	if v < 0 {
		v += 998244353
	}
	return modnum{v: v % 998244353}
}

func (m modnum) add(b modnum) modnum {
	return newModnum(m.v + b.v)
}

func (m modnum) sub(b modnum) modnum {
	return newModnum(m.v - b.v)
}

func (m modnum) mul(b modnum) modnum {
	return newModnum(m.v * b.v)
}

func (m modnum) pow(e int) modnum {
	if e < 0 {
		return m.inv().pow(-e)
	}
	res := modnum{v: 1}
	for e > 0 {
		if e&1 == 1 {
			res = res.mul(m)
		}
		m = m.mul(m)
		e >>= 1
	}
	return res
}

func (m modnum) inv() modnum {
	g := 998244353
	x, y := 0, 1
	a, b := m.v, g
	for b != 0 {
		q := a / b
		a, b = b, a-q*b
		x, y = y, x-q*y
	}
	if x < 0 {
		x += 998244353
	}
	return modnum{v: x}
}

func (m modnum) div(b modnum) modnum {
	return m.mul(b.inv())
}

func (m modnum) toInt() int {
	return m.v
}

func (m modnum) toFrac() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toFloat() float64 {
	return float64(m.v)
}

func (m modnum) toDouble() float64 {
	return float64(m.v)
}

func (m modnum) toLong() int64 {
	return int64(m.v)
}

func (m modnum) toLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func (m modnum) toBigFraction() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigRational() frac {
	return newFrac(m.v, 1)
}

func (m modnum) toBigFloat() float64 {
	return float64(m.v)
}

func (m modnum) toBigDouble() float64 {
	return float64(m.v)
}

func (m modnum) toBigInt() int64 {
	return int64(m.v)
}

func (m modnum) toBigLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigLongLong() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigInteger() int64 {
	return int64(m.v)
}

func (m modnum) toBigBigDecimal() float64 {
	return float64(m.v)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type pipe struct {
	x int
	v int
	p int
}

type dir int

const (
	LL dir = iota
	RR
	RL
)

type event struct {
	i int
	d dir
	t frac
}

type node struct {
	p    [4]modnum
	noLL bool
	noRR bool
	noRL bool
	none bool
}

func main() {
	var N int
	fmt.Scan(&N)
	pipes := make([]pipe, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&pipes[i].x, &pipes[i].v, &pipes[i].p)
	}

	evs := []event{}
	for i := 0; i < N-1; i++ {
		dx := pipes[i+1].x - pipes[i].x
		dv := pipes[i+1].v - pipes[i].v

		evs = append(evs, event{i, RL, newFrac(dx, pipes[i+1].v+pipes[i].v)})

		if dv > 0 {
			evs = append(evs, event{i, LL, newFrac(dx, dv)})
		}
		if dv < 0 {
			evs = append(evs, event{i, RR, newFrac(dx, -dv)})
		}
	}

	sortBy(evs, func(a, b event) bool {
		return a.t.n*b.t.d < b.t.n*a.t.d
	})

	st := make([]node, 2*N)
	for i := 0; i < N; i++ {
		pR := newModnum(pipes[i].p).mul(newModnum(100).inv())
		c := node{}
		c.p = [4]modnum{newModnum(1).sub(pR), newModnum(0), newModnum(0), pR}
		c.none = false
		st[N+i] = c
	}

	for i := N - 1; i > 0; i-- {
		c := node{}
		c.none = true
		st[i] = nn(st[2*i], st[2*i+1])
	}

	ans := newModnum(0)
	prob := newModnum(1)
	for _, e := range evs {
		c := st[e.i]
		switch e.d {
		case LL:
			c.noLL = true
		case RR:
			c.noRR = true
		case RL:
			c.noRL = true
		}
		st[e.i] = c

		u := st[0]
		PROB := newModnum(0)
		for _, p := range u.p {
			PROB = PROB.add(p)
		}
		ans = ans.add(prob.sub(PROB).mul(newFrac(e.t.n, e.t.d)))
		prob = PROB
	}

	fmt.Println(ans.v)
}

func sortBy(a []event, less func(i, j event) bool) {
	n := len(a)
	b := make([]event, n)
	for k := 1; k < n; k *= 2 {
		for l := 0; l < n; l += 2 * k {
			m := min(l+k, n)
			r := min(l+2*k, n)
			p, q := l, m
			for i := l; i < r; i++ {
				if p < m && (q >= r || less(a[p], a[q])) {
					b[i] = a[p]
					p++
				} else {
					b[i] = a[q]
					q++
				}
			}
		}
		a, b = b, a
	}
}
