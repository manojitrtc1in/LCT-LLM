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
	num, _ := strconv.Atoi(fs.Next())
	return num
}

func (fs *FastScanner) NextLong() int64 {
	num, _ := strconv.ParseInt(fs.Next(), 10, 64)
	return num
}

func (fs *FastScanner) NextDouble() float64 {
	num, _ := strconv.ParseFloat(fs.Next(), 64)
	return num
}

type Pair struct {
	x int
	y int
}

type Fraction struct {
	x int64
	y int64
}

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	if x == 0 {
		return y
	}
	return gcd(y, x%y)
}

func pow(x, p, mod int64) int64 {
	if p <= 0 {
		return 1
	}
	th := pow(x, p/2, mod)
	th *= th
	th %= mod
	if p%2 == 1 {
		th *= x
	}
	return th
}

func sum(a, b Fraction) Fraction {
	c := Fraction{
		x: a.x*b.y + a.y*b.x,
		y: a.y * b.y,
	}
	c.norm()
	return c
}

func (f *Fraction) norm() {
	gcd := gcd(f.x, f.y)
	f.x /= gcd
	f.y /= gcd
}

func (f *Fraction) compareTo(o Fraction) int {
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

type Rect struct {
	x1 int
	y1 int
	x2 int
	y2 int
}

func (r *Rect) toString() string {
	return fmt.Sprintf("%d %d %d %d", r.x1, r.y1, r.x2, r.y2)
}

func (r *Rect) equals(rect Rect) bool {
	return r.x1 == rect.x1 && r.y1 == rect.y1 && r.x2 == rect.x2 && r.y2 == rect.y2
}

func (r *Rect) inside(x, y int) int {
	inx := in(r.x1, r.x2, x)
	iny := in(r.y1, r.y2, y)
	return inx * iny
}

func (r *Rect) additional(rect Rect) int {
	if r.equals(rect) {
		return 0
	}
	if r.inside(rect.x1, rect.y1) == 4 || r.inside(rect.x2, rect.y2) == 4 || r.inside(rect.x1, rect.y2) == 4 || r.inside(rect.x2, rect.y1) == 4 {
		return 1
	}
	if r.inside(rect.x1, rect.y1) == 1 || r.inside(rect.x2, rect.y2) == 1 {
		return 1
	}
	return 2
}

func in(min, max, x int) int {
	if x == min || x == max {
		return 1
	}
	if x > min && x < max {
		return 2
	}
	return 0
}

func sum(x, y int) int {
	if x+y >= mod {
		return x + y - mod
	}
	return x + y
}

func mult(x, y int64) int64 {
	return x * y % mod
}

func div(x, y int64) int64 {
	return x * modInv(y) % mod
}

var mod int64 = 1000000007

type id6 struct {
	sum []int64
}

func newId6(n int) *id6 {
	return &id6{
		sum: make([]int64, n),
	}
}

func (id *id6) add(x int, d int64) {
	for i := x; i < len(id.sum); i |= i + 1 {
		id.sum[i] += d
	}
}

func (id *id6) sum(r int) int64 {
	var ans int64
	for i := r; i >= 0; i = i&(i+1) - 1 {
		ans += id.sum[i]
	}
	return ans
}

func (id *id6) sumRange(l, r int) int64 {
	if l > r {
		return 0
	}
	return id.sum(r) - id.sum(l-1)
}

type id3 struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func newId3(n int) *id3 {
	pow := 1
	for pow < n {
		pow *= 2
	}
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	flag := make([]bool, 2*pow)
	for i := 0; i < len(max); i++ {
		max[i] = math.MinInt64 / 2
	}
	return &id3{
		pow:   pow,
		max:   max,
		delta: delta,
		flag:  flag,
	}
}

func (id *id3) add(v, tl, tr, l, r int, x int64) {
	id.push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		id.delta[v] += x
		id.flag[v] = true
		id.push(v, tl, tr)
		return
	}
	m := (tl + tr) / 2
	id.add(2*v, tl, m, l, r, x)
	id.add(2*v+1, m+1, tr, l, r, x)
	id.max[v] = id.f(id.max[2*v], id.max[2*v+1])
}

func (id *id3) set(v, tl, tr, l, r int, x int64) {
	id.push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		id.delta[v] = x
		id.flag[v] = true
		id.push(v, tl, tr)
		return
	}
	m := (tl + tr) / 2
	id.set(2*v, tl, m, l, r, x)
	id.set(2*v+1, m+1, tr, l, r, x)
	id.max[v] = id.f(id.max[2*v], id.max[2*v+1])
}

func (id *id3) push(v, tl, tr int) {
	if id.flag[v] {
		if v < id.pow {
			id.flag[2*v] = true
			id.flag[2*v+1] = true
			id.delta[2*v] += id.delta[v]
			id.delta[2*v+1] += id.delta[v]
		}
		id.flag[v] = false
		id.max[v] += id.delta[v]
		id.delta[v] = 0
	}
}

func (id *id3) f(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func (id *id3) get(v, tl, tr, x int) int64 {
	id.push(v, tl, tr)
	if id.max[v] == math.MinInt64/2 {
		return 0
	}
	if v >= id.pow {
		if v%2 == 0 {
			if id.max[v].value(l) > id.max[v].value(l) {
				return id.max[v].value(l)
			}
		} else {
			if id.max[v].value(r) > id.max[v].value(r) {
				return id.max[v].value(r)
			}
		}
		return 0
	}
	ans := id.max[v].value(x)
	m := (tl + tr) / 2
	if x <= m {
		ans = id.f(ans, id.get(2*v, tl, m, x))
	}
	if x >= m {
		ans = id.f(ans, id.get(2*v+1, m, tr, x))
	}
	return ans
}

func (id *id3) get(x int) int64 {
	return id.get(1, 0, id.pow, x)
}

type Circle struct {
	x int
	y int
	r int
}

func (c *Circle) clone() Circle {
	return Circle{
		x: c.x,
		y: c.y,
		r: c.r,
	}
}

func (c *Circle) compareTo(o Circle) int {
	if c.r != o.r {
		return c.r - o.r
	}
	if c.x != o.x {
		return c.x - o.x
	}
	return c.y - o.y
}

func inside(small, big Circle) bool {
	return (small.x-big.x)*(small.x-big.x)+(small.y-big.y)*(small.y-big.y) <= (big.r-small.r)*(big.r-small.r)
}

func tangent(c1, c2 Circle) []float64 {
	a := c1.clone()
	b := c2.clone()
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
		return []float64{0, ans[1], ans[0], 2 * math.Pi}
	}
	return ans
}

func mergeSort(s string, a []int, l, r int) bool {
	if r-l <= 1 {
		return true
	}
	m := (l + r) >> 1
	if !mergeSort(s, a, l, m) {
		return false
	}
	if !mergeSort(s, a, m, r) {
		return false
	}
	i := l
	j := m
	k := l
	for x := 0; x < len(s); x++ {
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

func solve() {
	s := fs.Next()
	l := 0
	r := 100001
	for {
		sz := (l + r) >> 1
		a := make([]int, sz)
		for i := 0; i < len(a); i++ {
			a[i] = i
		}
		x := 0
		b := make([]int, sz)
		if !mergeSort(s, a, 0, sz) {
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

func main() {
	fs := NewFastScanner(os.Stdin)
	solve()
}
