package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	p1 = 7
	p2 = 13
)

type FieldMod int

func (f FieldMod) Pow(p int) FieldMod {
	res := FieldMod(1)
	e := f
	for p > 0 {
		if p&1 == 1 {
			res *= e
		}
		e *= e
		p >>= 1
	}
	return res
}

func (f FieldMod) Inv() FieldMod {
	return f.Pow(1000000007 - 2)
}

func (f FieldMod) String() string {
	return fmt.Sprintf("%d", int(f))
}

type Hash1 FieldMod
type Hash2 FieldMod

type Pair struct {
	X, Y int
}

type ID10 struct {
	n        int
	nullValue FieldMod
	nullTag   int
	T         []Pair
}

func NewID10(data []FieldMod, nullValue FieldMod, nullTag int) *ID10 {
	n := 1 << logceil(len(data))
	T := make([]Pair, 2*n)
	for i := 0; i < len(data); i++ {
		T[n+i].X = data[i]
	}
	for i := n - 1; i > 0; i-- {
		T[i].X = T[i<<1].X + T[i<<1|1].X
	}
	return &ID10{
		n:         n,
		nullValue: nullValue,
		nullTag:   nullTag,
		T:         T,
	}
}

func (id *ID10) Put(x int, v int) {
	id.PutInner(x, x, v, 1, id.n)
}

func (id *ID10) PutInner(from, to, v, i, s int) {
	Q := []int{}
	r := i
	for {
		if from == 0 && to == s-1 {
			id.ApplyTag(&id.T[i].X, v, s)
			id.CombineTag(&id.T[i].Y, v)
			break
		}
		id.PushTagDown(i, s)
		s >>= 1
		i <<= 1
		if from&s != 0 {
			from ^= s
			to ^= s
			i ^= 1
		} else if to&s != 0 {
			id.PutInner(0, to^s, v, i|1, s)
			to = s - 1
		}
	}

	for i != r {
		id.T[i>>1].X = id.CombineValues(id.T[i].X, id.T[i^1].X)
		i >>= 1
	}
}

func (id *ID10) Get(from, to int) FieldMod {
	return id.GetInner(from, to, 1, id.n)
}

func (id *ID10) GetInner(from, to, i, s int) FieldMod {
	for {
		if from == 0 && to == s-1 {
			return id.T[i].X
		}
		id.PushTagDown(i, s)
		s >>= 1
		i <<= 1
		if to&s != 0 {
			to ^= s
			if from&s != 0 {
				from ^= s
				i |= 1
			} else {
				a := id.GetInner(from, s-1, i, s)
				b := id.GetInner(0, to, i|1, s)
				return id.CombineValues(a, b)
			}
		}
	}
}

func (id *ID10) PushTagDown(i, s int) {
	id.ApplyTag(&id.T[i<<1].X, id.T[i].Y, s>>1)
	id.ApplyTag(&id.T[i<<1|1].X, id.T[i].Y, s>>1)
	id.CombineTag(&id.T[i<<1].Y, id.T[i].Y)
	id.CombineTag(&id.T[i<<1|1].Y, id.T[i].Y)
	id.T[i].Y = id.nullTag
}

func (id *ID10) ApplyTag(x *FieldMod, v, s int) {
	*x += FieldMod(v * s)
}

func (id *ID10) CombineTag(a *int, b int) {
	*a += b
}

func (id *ID10) CombineValues(a, b FieldMod) FieldMod {
	return a + b
}

func logceil(x int) uint {
	return uint(8*sizeof(int) - __builtin_clz(x))
}

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func in(a, b, c int) bool {
	return a <= b && b < c
}

func main() {
	fastIO()

	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)
	n = len(s)

	s = "0" + s + "0"

	st := make([]int, len(s))
	p := make([]int, len(s))
	f := make([]int, len(s))

	t := ""
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
	for i := len(s) - 2; i >= 0; i-- {
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

		h1a, h2a, lena := getH(a, a+c-1)
		h1b, h2b, lenb := getH(b, b+c-1)

		if h1a == h1b && h2a == h2b && lena == lenb {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func buildHash() {
	cp1 := p1
	h1[0] = Hash1(t[0])
	for i := 1; i < len(t); i++ {
		h1[i] = h1[i-1] + Hash1(t[i])*cp1
		cp1 *= p1
	}

	cp2 := p2
	h2[0] = Hash2(t[0])
	for i := 1; i < len(t); i++ {
		h2[i] = h2[i-1] + Hash2(t[i])*cp2
		cp2 *= p2
	}
}

func getH(l, r int) (Hash1, Hash2, int) {
	if l+f[l]-1 >= r {
		return -1, -1, -1
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	len := e - b + 1

	hm1 := (h1[e] - h1[b-1]) / p1.Pow(b)
	if p[r]%2 == 1 {
		len++
		hm1 += p1.Pow(e - b + 1)
	}

	if f[l]%2 == 1 {
		len++
		hm1 = 1 + hm1*p1
	}

	hm2 := (h2[e] - h2[b-1]) / p2.Pow(b)
	if p[r]%2 == 1 {
		hm2 += p2.Pow(e - b + 1)
	}

	if f[l]%2 == 1 {
		hm2 = 1 + hm2*p2
	}

	return hm1, hm2, len
}
