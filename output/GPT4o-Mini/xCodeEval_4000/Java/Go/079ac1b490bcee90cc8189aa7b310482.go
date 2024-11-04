package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const mod = 1000000007

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (fs *FastScanner) Next() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	var x int
	fmt.Sscanf(fs.Next(), "%d", &x)
	return x
}

func (fs *FastScanner) NextLong() int64 {
	var x int64
	fmt.Sscanf(fs.Next(), "%d", &x)
	return x
}

type Fraction struct {
	x, y int64
}

func (f *Fraction) norm() {
	g := gcd(f.x, f.y)
	f.x /= g
	f.y /= g
}

func (f Fraction) CompareTo(o Fraction) int {
	if f.x > o.x {
		return 1
	}
	if f.x < o.x {
		return -1
	}
	if f.y > o.y {
		return 1
	}
	if f.y < o.y {
		return -1
	}
	return 0
}

func sum(a, b Fraction) Fraction {
	c := Fraction{a.x*b.y + a.y*b.x, a.y * b.y}
	c.norm()
	return c
}

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

type Pair struct {
	x, y int
}

func (p Pair) CompareTo(o Pair) int {
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

func mult1(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[i^k] * b[k]
			c[i] %= mod
		}
	}
	return c
}

func mult(a, b [][]int64) [][]int64 {
	n := len(a)
	c := make([][]int64, n)
	for i := range c {
		c[i] = make([]int64, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				c[i][j] += a[i][k] * b[k][j]
				c[i][j] %= mod
			}
		}
	}
	return c
}

func pow(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		n := len(x)
		e := make([][]int64, n)
		for i := range e {
			e[i] = make([]int64, n)
			e[i][i] = 1
		}
		return e
	}
	ans := pow(x, p/2)
	ans = mult(ans, ans)
	if p%2 == 1 {
		ans = mult(ans, x)
	}
	return ans
}

func modInv(x int64) int64 {
	return powLong(x, mod-2)
}

func powLong(x, p int64) int64 {
	if p <= 0 {
		return 1
	}
	ans := powLong(x, p/2)
	ans = (ans * ans) % mod
	if p%2 == 1 {
		ans = (ans * x) % mod
	}
	return ans
}

func main() {
	fs := NewFastScanner()
	s := fs.Next()
	l, r := 0, 100001
	for {
		sz := (l + r) >> 1
		a := make([]int, sz)
		for i := 0; i < sz; i++ {
			a[i] = i
		}
		x := 0
		b := make([]int, sz)
		if !mergeSort(s, a, 0, sz, &x, b) {
			r = sz
			continue
		}
		if x < len(s) {
			l = sz
			continue
		}
		a = rev(a)
		fmt.Println(sz)
		for i := 0; i < len(a); i++ {
			fmt.Print(a[i]+1, " ")
		}
		return
	}
}

func mergeSort(s string, a []int, l, r int, x *int, b []int) bool {
	if r-l <= 1 {
		return true
	}
	m := (l + r) >> 1
	if !mergeSort(s, a, l, m, x, b) {
		return false
	}
	if !mergeSort(s, a, m, r, x, b) {
		return false
	}
	i, j, k := l, m, l
	for i < m && j < r {
		if *x == len(s) {
			return false
		}
		if s[*x] == '0' {
			b[k] = a[i]
			i++
		} else {
			b[k] = a[j]
			j++
		}
		k++
		(*x)++
	}
	for i < m {
		b[k] = a[i]
		i++
		k++
	}
	for j < r {
		b[k] = a[j]
		j++
		k++
	}
	for p := l; p < r; p++ {
		a[p] = b[p]
	}
	return true
}

func rev(a []int) []int {
	res := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		res[a[i]] = i
	}
	return res
}
