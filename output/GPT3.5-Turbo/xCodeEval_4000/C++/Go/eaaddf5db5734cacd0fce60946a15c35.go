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

type Field struct {
	v int
}

func NewField(x int) *Field {
	return &Field{v: x}
}

func (f *Field) pow(a, p int) int {
	r := 1
	e := a
	for p > 0 {
		if p&1 == 1 {
			r = (r * e) % f.v
		}
		e = (e * e) % f.v
		p >>= 1
	}
	return r
}

func (f *Field) inv(a int) int {
	return f.pow(a, f.v-2)
}

type Hash1 struct {
	p Field
	h []int
}

func NewHash1(t string) *Hash1 {
	h := make([]int, len(t))
	cp := p1
	h[0] = int(t[0])
	for i := 1; i < len(t); i++ {
		h[i] = (h[i-1] + int(t[i])*cp) % p1.v
		cp *= p1
	}
	return &Hash1{
		p: p1,
		h: h,
	}
}

type Hash2 struct {
	p Field
	h []int
}

func NewHash2(t string) *Hash2 {
	h := make([]int, len(t))
	cp := p2
	h[0] = int(t[0])
	for i := 1; i < len(t); i++ {
		h[i] = (h[i-1] + int(t[i])*cp) % p2.v
		cp *= p2
	}
	return &Hash2{
		p: p2,
		h: h,
	}
}

type LSegTree struct {
	n         int
	nullValue int
	nullTag   int
	T         []Pair
}

type Pair struct {
	X int
	Y int
}

func NewLSegTree(data []int, nullValue, nullTag int) *LSegTree {
	n := 1 << logceil(len(data))
	T := make([]Pair, 2*n)
	for i := 0; i < len(data); i++ {
		T[n+i].X = data[i]
	}
	for i := n - 1; i > 0; i-- {
		T[i].X = combineValues(T[i<<1].X, T[i<<1|1].X)
	}
	return &LSegTree{
		n:         n,
		nullValue: nullValue,
		nullTag:   nullTag,
		T:         T,
	}
}

func (t *LSegTree) put(x, v int) {
	t.putInner(x, x, v, 1, t.n)
}

func (t *LSegTree) putInner(from, to, v, i, s int) {
	Q := make([]int, 0)
	r := i
	for {
		if from == 0 && to == s-1 {
			applyTag(&T[i].X, v, s)
			combineTag(&T[i].Y, v)
			break
		}
		pushTagDown(i, s)
		s >>= 1
		i <<= 1
		if from&s != 0 {
			from ^= s
			to ^= s
			i ^= 1
		} else if to&s != 0 {
			t.putInner(0, to^s, v, i|1, s)
			to = s - 1
		}
	}

	for i != r {
		T[i>>1].X = combineValues(T[i].X, T[i^1].X)
		i >>= 1
	}
}

func (t *LSegTree) get(x int) int {
	return t.getInner(x, x)
}

func (t *LSegTree) getInner(from, to, i, s int) int {
	for {
		if from == 0 && to == s-1 {
			return T[i].X
		}
		pushTagDown(i, s)
		s >>= 1
		i <<= 1
		if to&s != 0 {
			to ^= s
			if from&s != 0 {
				from ^= s
				i |= 1
			} else {
				a := getInner(from, s-1, i, s)
				b := getInner(0, to, i|1, s)
				return combineValues(a, b)
			}
		}
	}
}

func (t *LSegTree) pushTagDown(i, s int) {
	applyTag(&T[i<<1].X, T[i].Y, s>>1)
	applyTag(&T[i<<1|1].X, T[i].Y, s>>1)
	combineTag(&T[i<<1].Y, T[i].Y)
	combineTag(&T[i<<1|1].Y, T[i].Y)
	T[i].Y = nullTag
}

func combineValues(a, b int) int {
	return a + b
}

func applyTag(a *int, v, s int) {
	*a += v * s
}

func combineTag(a *int, v int) {
	*a += v
}

func logceil(x int) int {
	return 8*32 - __builtin_clz(x)
}

func gcd(a, b int) int {
	if a < b {
		a, b = b, a
	}
	if b != 0 {
		return gcd(b, a%b)
	}
	return a
}

func in(a, b, c int) bool {
	return a <= b && b < c
}

func longestSuffix(x int, pred func(int) bool) int {
	value := nullValue
	return longestSuffixInner2(x, 1, 0, n, value, pred)
}

func longestSuffixInner(i, l, r int, curValue *int, pred func(int) bool) int {
	if l+1 != r {
		pushTagDown(i, r-l)
	}
	nextValue := combineValues(T[i].X, *curValue)
	if pred(nextValue) {
		*curValue = nextValue
		return l
	}
	if l+1 == r {
		return r
	}
	s := longestSuffixInner(i<<1|1, (l+r)/2, r, curValue, pred)
	if s == (l+r)/2 {
		return longestSuffixInner(i<<1, l, (l+r)/2, curValue, pred)
	}
	return s
}

func longestSuffixInner2(x, i, l, r int, curValue *int, pred func(int) bool) int {
	if x >= r-1 {
		return longestSuffixInner(i, l, r, curValue, pred)
	}

	if l+1 == r {
		nextValue := combineValues(T[i].X, *curValue)
		if pred(nextValue) {
			*curValue = nextValue
			return r
		}
		return l
	}

	pushTagDown(i, r-l)
	m := (l+r)/2
	if x < m {
		return longestSuffixInner2(x, i<<1, l, (l+r)/2, curValue, pred)
	}
	s := longestSuffixInner2(x, i<<1|1, (l+r)/2, r, curValue, pred)
	if s == (l+r)/2 {
		return longestSuffixInner(i<<1, l, (l+r)/2, curValue, pred)
	}
	return s
}

func longestPrefix(x int, pred func(int) bool) int {
	value := nullValue
	return longestPrefixInner2(x, 1, 0, n, value, pred) - 1
}

func longestPrefixInner(i, l, r int, curValue *int, pred func(int) bool) int {
	if l+1 != r {
		pushTagDown(i, r-l)
	}
	nextValue := combineValues(T[i].X, *curValue)
	if pred(nextValue) {
		*curValue = nextValue
		return r
	}
	if l+1 == r {
		return l
	}
	s := longestPrefixInner(i<<1, l, (l+r)/2, curValue, pred)
	if s == (l+r)/2 {
		return longestPrefixInner(i<<1|1, (l+r)/2, r, curValue, pred)
	}
	return s
}

func longestPrefixInner2(x, i, l, r int, curValue *int, pred func(int) bool) int {
	if x <= l {
		return longestPrefixInner(i, l, r, curValue, pred)
	}

	if l+1 == r {
		nextValue := combineValues(T[i].X, *curValue)
		if pred(nextValue) {
			*curValue = nextValue
			return r
		}
		return l
	}

	pushTagDown(i, r-l)
	m := (l+r)/2
	if x >= m {
		return longestPrefixInner2(x, i<<1|1, m, r, curValue, pred)
	}
	s := longestPrefixInner2(x, i<<1, l, m, curValue, pred)
	if s == m {
		return longestPrefixInner(i<<1|1, m, r, curValue, pred)
	}
	return s
}

type DDostizhimieStroki struct{}

func (d *DDostizhimieStroki) solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	s := make([]byte, n)
	fmt.Fscan(in, &s)
	n = len(s)

	s = append([]byte{'0'}, append(s, '0')...)

	t := make([]byte, 0)
	st := make([]int, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == '1' && s[i+1] == '1' {
			i++
			continue
		}
		t = append(t, s[i])
		st[i] = len(t) - 1
	}

	p := make([]int, len(s))
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

	f := make([]int, len(s))
	f[len(s)-1] = 0
	for i := len(s) - 2; i >= 0; i-- {
		if s[i] == '0' {
			f[i] = 0
		} else {
			f[i] = f[i+1] + 1
		}
	}

	h1 := NewHash1(string(t))
	h2 := NewHash2(string(t))

	var q int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		var a, b, c int
		fmt.Fscan(in, &a, &b, &c)

		hm1a, hm2a, lena := getH(h1, h2, st, p, f, a, a+c-1)
		hm1b, hm2b, lenb := getH(h1, h2, st, p, f, b, b+c-1)

		if hm1a == hm1b && hm2a == hm2b && lena == lenb {
			fmt.Fprintln(out, "Yes")
		} else {
			fmt.Fprintln(out, "No")
		}
	}

	out.Flush()
}

func getH(h1 *Hash1, h2 *Hash2, st, p, f []int, l, r int) (int, int, int) {
	if l+f[l]-1 >= r {
		return -1, -1, -1
	}

	b := st[l+f[l]]
	e := st[r-p[r]]

	len := e - b + 1

	hm1 := (h1.h[e] - h1.h[b-1]) / h1.p.pow(b)
	if p[r]%2 == 1 {
		len++
		hm1 += h1.p.pow(e - b + 1)
	}

	if f[l]%2 == 1 {
		len++
		hm1 = 1 + hm1*h1.p
	}

	hm2 := (h2.h[e] - h2.h[b-1]) / h2.p.pow(b)
	if p[r]%2 == 1 {
		hm2 += h2.p.pow(e - b + 1)
	}

	if f[l]%2 == 1 {
		hm2 = 1 + hm2*h2.p
	}

	return hm1, hm2, len
}

func main() {
	d := &DDostizhimieStroki{}
	d.solve(bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout))
}
