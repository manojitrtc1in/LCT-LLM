package main

import (
	"fmt"
	"math"
)

type Long int64
type ULong uint64
type Uint uint
type Uchar byte
type PII struct{ X, Y int }
type pii struct{ X, Y int }
type FieldMod struct{ v uint }

func (f *FieldMod) pow(a, p uint) uint {
	r, e := uint(1), a
	for p > 0 {
		if p&1 == 1 {
			r = (r * e) % 1000000007
		}
		e = (e * e) % 1000000007
		p >>= 1
	}
	return r
}

func (f *FieldMod) inv(a uint) uint {
	return f.pow(a, 1000000007-2)
}

func (f *FieldMod) add(o FieldMod) FieldMod {
	if f.v+o.v >= 1000000007 {
		f.v += o.v - 1000000007
	} else {
		f.v += o.v
	}
	return *f
}

func (f *FieldMod) sub(o FieldMod) FieldMod {
	if f.v < o.v {
		f.v -= o.v - 1000000007
	} else {
		f.v -= o.v
	}
	return *f
}

func (f *FieldMod) mul(o FieldMod) FieldMod {
	f.v = (f.v * o.v) % 1000000007
	return *f
}

func (f *FieldMod) div(o FieldMod) FieldMod {
	return f.mul(FieldMod{f.inv(o.v)})
}

func (f *FieldMod) String() string {
	return fmt.Sprintf("%d", f.v)
}

const MAXN = 200200

var st [MAXN]int
var p [MAXN]int
var f [MAXN]int
var s, t string
var h1, h2 [MAXN]FieldMod
var p1, p2 FieldMod

func buildHash() {
	cp := p1
	h1[0] = FieldMod{uint(s[0])}
	for i := 1; i < len(t); i++ {
		h1[i] = h1[i-1].add(FieldMod{uint(t[i])}.mul(cp))
		cp = cp.mul(p1)
	}

	cp = p2
	h2[0] = FieldMod{uint(t[0])}
	for i := 1; i < len(t); i++ {
		h2[i] = h2[i-1].add(FieldMod{uint(t[i])}.mul(cp))
		cp = cp.mul(p2)
	}
}

func getH(l, r int) (PII, int) {
	if l+f[l]-1 >= r {
		return PII{-1, -1}, -1
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	length := e - b + 1

	hm1 := h1[e].sub(h1[b-1]).div(p1.pow(uint(b)))
	if p[r]%2 == 1 {
		length++
		hm1 = hm1.add(p1.pow(uint(e - b + 1)))
	}

	if f[l]%2 == 1 {
		length++
		hm1 = FieldMod{1}.add(hm1.mul(p1))
	}

	hm2 := h2[e].sub(h2[b-1]).div(p2.pow(uint(b)))
	if p[r]%2 == 1 {
		hm2 = hm2.add(p2.pow(uint(e - b + 1)))
	}

	if f[l]%2 == 1 {
		hm2 = FieldMod{1}.add(hm2.mul(p2))
	}

	return PII{int(hm1.v), int(hm2.v)}, length
}

func id6(l, r int) string {
	if l+f[l]-1 >= r {
		return "-1"
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	ans := t[b:e+1]
	if p[r]%2 == 1 {
		ans += "1"
	}
	if f[l]%2 == 1 {
		ans = "1" + ans
	}
	return ans
}

type DDostizhimieStroki struct{}

func (solver *DDostizhimieStroki) solve() {
	var n int
	fmt.Scan(&n, &s)
	n = len(s)

	s = "0" + s + "0"

	for i := 0; i < len(s); i++ {
		if s[i] == '1' && s[i+1] == '1' {
			i++
			continue
		}

		t += string(s[i])
		st[i] = len(t) - 1
	}

	p[0] = 0
	if s[0] == '1' {
		p[0] = 1
	}

	for i := 1; i < len(s); i++ {
		if s[i] == '0' {
			p[i] = 0
		} else {
			p[i] = p[i-1] + 1
		}
	}

	f[len(s)-1] = 0

	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == '0' {
			f[i] = 0
		} else {
			f[i] = f[i+1] + 1
		}
	}

	buildHash()

	var q int
	fmt.Scan(&q)

	for i := 0; i < q; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)

		if getH(a, a+c-1) == getH(b, b+c-1) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func main() {
	solver := DDostizhimieStroki{}
	solver.solve()
}
