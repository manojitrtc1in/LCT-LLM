package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	br       *bufio.Reader
	st       []string
	tokenIdx int
}

func NewFastScanner(f *os.File) *FastScanner {
	return &FastScanner{
		br: bufio.NewReader(f),
	}
}

func (fs *FastScanner) NextLine() string {
	str, _ := fs.br.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func (fs *FastScanner) Next() string {
	if fs.tokenIdx >= len(fs.st) {
		fs.st = strings.Split(fs.NextLine(), " ")
		fs.tokenIdx = 0
	}
	fs.tokenIdx++
	return fs.st[fs.tokenIdx-1]
}

func (fs *FastScanner) NextInt() int {
	n, _ := strconv.Atoi(fs.Next())
	return n
}

func (fs *FastScanner) NextLong() int64 {
	n, _ := strconv.ParseInt(fs.Next(), 10, 64)
	return n
}

func (fs *FastScanner) NextDouble() float64 {
	n, _ := strconv.ParseFloat(fs.Next(), 64)
	return n
}

type F struct {
	in       *FastScanner
	out      *bufio.Writer
	systemIO bool
}

func NewF() *F {
	return &F{
		in:       NewFastScanner(os.Stdin),
		out:      bufio.NewWriter(os.Stdout),
		systemIO: true,
	}
}

func (f *F) pow(x, p, mod int64) int64 {
	if p <= 0 {
		return 1
	}
	th := f.pow(x, p/2, mod)
	th *= th
	th %= mod
	if p%2 == 1 {
		th *= x
	}
	return th
}

type Fraction struct {
	x int64
	y int64
}

func NewFraction(x, y int64) *Fraction {
	return &Fraction{
		x: x,
		y: y,
	}
}

func (frac *Fraction) norm() {
	gcd := f.gcd(frac.x, frac.y)
	frac.x /= gcd
	frac.y /= gcd
}

func (frac *Fraction) CompareTo(other *Fraction) int {
	if frac.x > other.x {
		return 1
	}
	if frac.x < other.x {
		return -1
	}
	if frac.y > other.y {
		return 1
	}
	if frac.y < other.y {
		return -1
	}
	return 0
}

func (f *F) sum(a, b *Fraction) *Fraction {
	c := NewFraction(a.x*b.y+a.y*b.x, a.y*b.y)
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
	x int
	y int
}

func NewPair(x, y int) *Pair {
	return &Pair{
		x: x,
		y: y,
	}
}

func (p *Pair) Clone() *Pair {
	return &Pair{
		x: p.x,
		y: p.y,
	}
}

func (p *Pair) CompareTo(other *Pair) int {
	if p.x > other.x {
		return 1
	}
	if p.x < other.x {
		return -1
	}
	if p.y > other.y {
		return 1
	}
	if p.y < other.y {
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
			c[i] %= mod
		}
	}
	return c
}

func (f *F) mult(a, b [][]int64) [][]int64 {
	n := len(a)
	c := make([][]int64, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int64, n)
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				c[i][j] += a[i][k] * b[k][j]
				c[i][j] %= mod
			}
		}
	}
	return c
}

func (f *F) powMatrix(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		e := make([][]int64, len(x))
		for i := 0; i < len(e); i++ {
			e[i] = make([]int64, len(x))
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

func (f *F) mult(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[k] * b[k^i]
			c[i] %= mod
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
	ans = f.mult(ans, ans)
	if p%2 == 1 {
		ans = f.mult(ans, x)
	}
	return ans
}

func (f *F) pow(x, p int64) int64 {
	if p <= 0 {
		return 1
	}
	ans := f.pow(x, p/2)
	ans = (ans * ans) % mod
	if p%2 == 1 {
		ans = (ans * x) % mod
	}
	return ans
}

func (f *F) modInv(x int64) int64 {
	return f.pow(x, mod-2)
}

type Circle struct {
	x int
	y int
	r int
}

func NewCircle(x, y, r int) *Circle {
	return &Circle{
		x: x,
		y: y,
		r: r,
	}
}

func (c *Circle) Clone() *Circle {
	return &Circle{
		x: c.x,
		y: c.y,
		r: c.r,
	}
}

func (c *Circle) CompareTo(other *Circle) int {
	if c.r != other.r {
		return c.r - other.r
	}
	if c.x != other.x {
		return c.x - other.x
	}
	return c.y - other.y
}

func (f *F) inside(small, big *Circle) bool {
	return (small.x-big.x)*(small.x-big.x)+(small.y-big.y)*(small.y-big.y) <= (big.r-small.r)*(big.r-small.r)
}

func (f *F) tangent(c1, c2 *Circle) []float64 {
	a := c1.Clone()
	b := c2.Clone()
	minr := int(math.Min(float64(a.r), float64(b.r)))
	a.r -= minr
	b.r -= minr
	b.x -= a.x
	b.y -= a.y
	a0 := math.Atan2(float64(b.y), float64(b.x))
	len := math.Sqrt(float64(b.x*b.x + b.y*b.y))
	da := 0.0
	if a.r == 0 {
		da = math.Asin(float64(b.r) / len) + math.Pi/2
	} else {
		da = math.Acos(float64(a.r) / len)
	}
	ans := []float64{a0 - da, a0 + da}
	return norm(ans)
}

func norm(ans []float64) []float64 {
	for i := 0; i < len(ans); i++ {
		for ans[i] < 0 {
			ans[i] += 2 * math.Pi
		}
		for ans[i] > 2*math.Pi {
			ans[i] -= 2 * math.Pi
		}
	}
	if ans[0] > ans[1] {
		answer := []float64{0, ans[1], ans[0], 2 * math.Pi}
		return answer
	}
	return ans
}

func (f *F) inside(min, max, x int) int {
	if x == min || x == max {
		return 1
	}
	if x > min && x < max {
		return 2
	}
	return 0
}

func (f *F) sum(x, y int) int {
	if x+y >= mod {
		return x + y - mod
	}
	return x + y
}

func (f *F) mult(x, y int64) int64 {
	return x * y % mod
}

func (f *F) div(x, y int64) int64 {
	return x * f.modInv(y) % mod
}

const mod = 1000000007

func (f *F) solve() {
	s := f.in.Next()
	for sz := 1; ; sz++ {
		a := make([]int, sz)
		for i := 0; i < len(a); i++ {
			a[i] = i
		}
		x := 0
		b := make([]int, sz)
		if !f.mergeSort(s, a, 0, sz) {
			continue
		}
		if x < len(s) {
			continue
		}
		a = rev(a)
		f.out.Println(sz)
		for i := 0; i < len(a); i++ {
			f.out.Print(a[i]+1, " ")
		}
		f.out.Flush()
		return
	}
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
	i := l
	j := m
	k := l
	for i < m && j < r {
		if x == len(s) {
			return false
		}
		if s[x] == '0' {
			b[k] = a[i]
			i++
		} else {
			b[k] = a[j]
			j++
		}
		k++
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

func main() {
	f := NewF()
	f.solve()
}
