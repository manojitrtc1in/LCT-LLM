package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type F struct {
	in   *bufio.Reader
	out  *bufio.Writer
	mod  int64
	x    int
	b    []int
}

func NewF() *F {
	return &F{
		in:  bufio.NewReader(os.Stdin),
		out: bufio.NewWriter(os.Stdout),
		mod: 1000000007,
	}
}

func (f *F) pow(x, p, mod int64) int64 {
	if p <= 0 {
		return 1
	}
	th := f.pow(x, p/2, mod)
	th = (th * th) % mod
	if p%2 == 1 {
		th = (th * x) % mod
	}
	return th
}

type Fraction struct {
	x, y int64
}

func (fr *Fraction) norm() {
	gcd := f.gcd(fr.x, fr.y)
	fr.x /= gcd
	fr.y /= gcd
}

func (fr *Fraction) compareTo(o *Fraction) int {
	if fr.x > o.x {
		return 1
	}
	if fr.x < o.x {
		return -1
	}
	if fr.y > o.y {
		return 1
	}
	if fr.y < o.y {
		return -1
	}
	return 0
}

func (f *F) sum(a, b Fraction) Fraction {
	c := Fraction{a.x*b.y + a.y*b.x, a.y * b.y}
	c.norm()
	return c
}

func (f *F) gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	if x == 0 {
		return y
	}
	return f.gcd(y, x%y)
}

type Pair struct {
	x, y int
}

func (p *Pair) compareTo(o *Pair) int {
	if p.x > o.x {
		return 1
	}
	if p.x < o.x {
		return -1
	}
	if p.y > o.y {
		return 1
	}
	if p.y < o.y {
		return -1
	}
	return 0
}

func (f *F) mult1(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[i^k] * b[k]
			c[i] %= f.mod
		}
	}
	return c
}

func (f *F) mult(a, b [][]int64) [][]int64 {
	n := len(a)
	c := make([][]int64, n)
	for i := range c {
		c[i] = make([]int64, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				c[i][j] += a[i][k] * b[k][j]
				c[i][j] %= f.mod
			}
		}
	}
	return c
}

func (f *F) powMatrix(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		n := len(x)
		e := make([][]int64, n)
		for i := range e {
			e[i] = make([]int64, n)
			e[i][i] = 1
		}
		return e
	}
	ans := f.powMatrix(x, p/2)
	ans = f.mult(ans, ans)
	if p%2 == 1 {
		ans = f.mult(ans, x)
	}
	return ans
}

func (f *F) multArray(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[k] * b[k^i]
			c[i] %= f.mod
		}
	}
	return c
}

func (f *F) powArray(x []int64, p int64) []int64 {
	if p == 0 {
		e := make([]int64, len(x))
		e[0] = 1
		return e
	}
	ans := f.powArray(x, p/2)
	ans = f.multArray(ans, ans)
	if p%2 == 1 {
		ans = f.multArray(ans, x)
	}
	return ans
}

func (f *F) modInv(x int64) int64 {
	return f.pow(x, f.mod-2, f.mod)
}

func (f *F) sum(x, y int64) int64 {
	if x+y >= f.mod {
		return x + y - f.mod
	}
	return x + y
}

func (f *F) mult(x, y int64) int64 {
	return x * y % f.mod
}

func (f *F) div(x, y int64) int64 {
	return x * f.modInv(y) % f.mod
}

func (f *F) mergeSort(s string, a []int, l, r int) bool {
	if r-l <= 1 {
		return true
	}
	m := (l + r) >> 1
	if !f.mergeSort(s, a, l, m) {
		return false
	}
	if !f.mergeSort(s, a, m, r) {
		return false
	}
	i, j, k := l, m, l
	for i < m && j < r {
		if f.x == len(s) {
			return false
		}
		if s[f.x] == '0' {
			f.b[k] = a[i]
			i++
		} else {
			f.b[k] = a[j]
			j++
		}
		k++
	}
	for i < m {
		f.b[k] = a[i]
		i++
		k++
	}
	for j < r {
		f.b[k] = a[j]
		j++
		k++
	}
	for p := l; p < r; p++ {
		a[p] = f.b[p]
	}
	return true
}

func (f *F) rev(a []int) []int {
	res := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		res[a[i]] = i
	}
	return res
}

func (f *F) solve() {
	s, _ := f.in.ReadString('\n')
	s = s[:len(s)-1]
	l, r := 0, 100001
	for {
		sz := (l + r) >> 1
		a := make([]int, sz)
		for i := 0; i < sz; i++ {
			a[i] = i
		}
		f.x = 0
		f.b = make([]int, sz)
		if !f.mergeSort(s, a, 0, sz) {
			r = sz
			continue
		}
		if f.x < len(s) {
			l = sz
			continue
		}
		a = f.rev(a)
		fmt.Fprintln(f.out, sz)
		for i := 0; i < len(a); i++ {
			fmt.Fprint(f.out, a[i]+1, " ")
		}
		return
	}
}

func main() {
	f := NewF()
	defer f.out.Flush()
	f.solve()
}
