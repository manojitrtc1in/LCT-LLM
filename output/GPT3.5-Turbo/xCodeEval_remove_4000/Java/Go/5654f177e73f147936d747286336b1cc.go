package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type FastScanner struct {
	br *bufio.Reader
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
	str, _ := fs.br.ReadString(' ')
	return strings.TrimRight(str, " ")
}

func (fs *FastScanner) NextInt() int {
	str := fs.Next()
	num, _ := strconv.Atoi(str)
	return num
}

func (fs *FastScanner) NextLong() int64 {
	str := fs.Next()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func (fs *FastScanner) NextDouble() float64 {
	str := fs.Next()
	num, _ := strconv.ParseFloat(str, 64)
	return num
}

type PrintWriter struct {
	bw *bufio.Writer
}

func NewPrintWriter(f *os.File) *PrintWriter {
	return &PrintWriter{
		bw: bufio.NewWriter(f),
	}
}

func (pw *PrintWriter) Println(a ...interface{}) {
	fmt.Fprintln(pw.bw, a...)
}

func (pw *PrintWriter) Printf(format string, a ...interface{}) {
	fmt.Fprintf(pw.bw, format, a...)
}

func (pw *PrintWriter) Flush() {
	pw.bw.Flush()
}

type E struct {
	in       *FastScanner
	out      *PrintWriter
	systemIO bool
}

func NewE() *E {
	return &E{
		systemIO: true,
	}
}

type DSU struct {
	sz []int
	p  []int
}

func NewDSU(n int) *DSU {
	sz := make([]int, n)
	p := make([]int, n)
	for i := 0; i < len(p); i++ {
		p[i] = i
		sz[i] = 1
	}
	return &DSU{
		sz: sz,
		p:  p,
	}
}

func (d *DSU) get(x int) int {
	if x == d.p[x] {
		return x
	}
	par := d.get(d.p[x])
	d.p[x] = par
	return par
}

func (d *DSU) unite(a, b int) bool {
	pa := d.get(a)
	pb := d.get(b)
	if pa == pb {
		return false
	}
	if d.sz[pa] < d.sz[pb] {
		d.p[pa] = pb
		d.sz[pb] += d.sz[pa]
	} else {
		d.p[pb] = pa
		d.sz[pa] += d.sz[pb]
	}
	return true
}

type id2 struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func Newid2(a []int64) *id2 {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	flag := make([]bool, 2*pow)
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	for i := 0; i < len(max); i++ {
		max[i] = int64(-1e18)
	}
	for i := 0; i < len(a); i++ {
		max[pow+i] = a[i]
	}
	for i := pow - 1; i > 0; i-- {
		max[i] = f(max[2*i], max[2*i+1])
	}
	return &id2{
		pow:   pow,
		max:   max,
		delta: delta,
		flag:  flag,
	}
}

func (i *id2) get(v, tl, tr, l, r int) int64 {
	i.push(v, tl, tr)
	if l > r {
		return int64(-1e18)
	}
	if l == tl && r == tr {
		return i.max[v]
	}
	tm := (tl + tr) / 2
	return f(i.get(2*v, tl, tm, l, min(r, tm)), i.get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (i *id2) set(v, tl, tr, l, r int, x int64) {
	i.push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		i.delta[v] += x
		i.flag[v] = true
		i.push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	i.set(2*v, tl, tm, l, r, x)
	i.set(2*v+1, tm+1, tr, l, r, x)
	i.max[v] = f(i.max[2*v], i.max[2*v+1])
}

func (i *id2) push(v, tl, tr int) {
	if i.flag[v] {
		if v < i.pow {
			i.flag[2*v] = true
			i.flag[2*v+1] = true
			i.delta[2*v] += i.delta[v]
			i.delta[2*v+1] += i.delta[v]
		}
		i.flag[v] = false
		i.max[v] += i.delta[v]
		i.delta[v] = 0
	}
}

func f(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

type id5 struct {
	pow   int
	sum   []int
	delta []int
	flag  []bool
}

func Newid5(a []int) *id5 {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	flag := make([]bool, 2*pow)
	sum := make([]int, 2*pow)
	delta := make([]int, 2*pow)
	for i := 0; i < len(a); i++ {
		sum[pow+i] = a[i]
	}
	return &id5{
		pow:   pow,
		sum:   sum,
		delta: delta,
		flag:  flag,
	}
}

func (i *id5) get(v, tl, tr, l, r int) int {
	i.push(v, tl, tr)
	if l > r {
		return 0
	}
	if l == tl && r == tr {
		return i.sum[v]
	}
	tm := (tl + tr) / 2
	return f(i.get(2*v, tl, tm, l, min(r, tm)), i.get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (i *id5) set(v, tl, tr, l, r, x int) {
	i.push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		i.delta[v] = x
		i.flag[v] = true
		i.push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	i.set(2*v, tl, tm, l, r, x)
	i.set(2*v+1, tm+1, tr, l, r, x)
	i.sum[v] = f(i.sum[2*v], i.sum[2*v+1])
}

func (i *id5) push(v, tl, tr int) {
	if i.flag[v] {
		if v < i.pow {
			i.flag[2*v] = true
			i.flag[2*v+1] = true
			i.delta[2*v] = i.delta[v]
			i.delta[2*v+1] = i.delta[v]
		}
		i.flag[v] = false
		i.sum[v] = i.delta[v] * (tr - tl + 1)
	}
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

type Rect struct {
	x1     int64
	x2     int64
	y1     int64
	y2     int64
	number int
}

func NewRect(x1, x2, y1, y2 int64, number int) *Rect {
	return &Rect{
		x1:     x1,
		x2:     x2,
		y1:     y1,
		y2:     y2,
		number: number,
	}
}

type Point struct {
	x float64
	y float64
}

func NewPoint() *Point {
	return &Point{
		x: 0,
		y: 0,
	}
}

func NewPointWithValues(x, y float64) *Point {
	return &Point{
		x: x,
		y: y,
	}
}

func (p *Point) String() string {
	return fmt.Sprintf("%f %f", p.x, p.y)
}

func (p *Point) Equals(q *Point) bool {
	return p.x == q.x && p.y == q.y
}

func (p *Point) Dist2() float64 {
	return p.x*p.x + p.y*p.y
}

func (p *Point) Add(v *Point) *Point {
	return NewPointWithValues(p.x+v.x, p.y+v.y)
}

func (p *Point) CompareTo(q *Point) int {
	z := signum(p.x + p.y - q.x - q.y)
	if z != 0 {
		return z
	}
	return signum(p.x - q.x)
}

type Circle struct {
	p *Point
	r int
}

func NewCircle(p *Point, r int) *Circle {
	return &Circle{
		p: p,
		r: r,
	}
}

func (c *Circle) Angle() *Point {
	z := float64(c.r) / sq2
	z -= math.Mod(z, 1e-5)
	return NewPointWithValues(c.p.x-z, c.p.y-z)
}

func (c *Circle) Inside(p *Point) bool {
	return id0(p.x-c.p.x, p.y-c.p.y) <= sq(c.r)
}

type Fraction struct {
	x int64
	y int64
}

func NewFraction(x, y int64, needNorm bool) *Fraction {
	if y < 0 {
		x *= -1
		y *= -1
	}
	if needNorm {
		gcd := gcd(x, y)
		x /= gcd
		y /= gcd
	}
	return &Fraction{
		x: x,
		y: y,
	}
}

func (f *Fraction) Clone() *Fraction {
	return NewFraction(f.x, f.y, false)
}

func (f *Fraction) String() string {
	return fmt.Sprintf("%d/%d", f.x, f.y)
}

func (f *Fraction) CompareTo(o *Fraction) int {
	res := f.x*o.y - f.y*o.x
	if res > 0 {
		return 1
	}
	if res < 0 {
		return -1
	}
	return 0
}

func sq(x float64) float64 {
	return x * x
}

func id0(x, y float64) float64 {
	return sq(x) + sq(y)
}

func signum(x float64) int {
	if x > eps {
		return 1
	}
	if x < -eps {
		return -1
	}
	return 0
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func gcd(x, y int64) int64 {
	for y > 0 {
		c := y
		y = x % y
		x = c
	}
	return x
}

func (e *E) Solve() {
	n := e.in.NextInt()
	m := e.in.NextInt()
	q := e.in.NextInt()
	v := make([]int, n)
	inv := make([]int, n)
	for i := 0; i < len(v); i++ {
		v[i] = e.in.NextInt()
		inv[v[i]-1] = i
	}
	a := make([]int, m)
	b := make([]int, m)
	for i := 0; i < len(b); i++ {
		a[i] = e.in.NextInt() - 1
		b[i] = e.in.NextInt() - 1
	}
	typ := make([]bool, q)
	x := make([]int, q)
	removed := make([]bool, m)
	for i := 0; i < q; i++ {
		if e.in.NextInt() == 1 {
			x[i] = e.in.NextInt() - 1
			typ[i] = true
		} else {
			x[i] = e.in.NextInt() - 1
			removed[x[i]] = true
		}
	}
	dsu := Newid1(v, m)
	for i := 0; i < len(removed); i++ {
		if !removed[i] {
			dsu.unite(a[i], b[i])
		}
	}
	for i := q - 1; i >= 0; i-- {
		if !typ[i] {
			dsu.popEdge()
		}
	}
	for i := 0; i < q; i++ {
		if typ[i] {
			e.out.Println(dsu.poll(x[i]))
		}
	}
}

func (e *E) Run() {
	if e.systemIO {
		e.in = NewFastScanner(os.Stdin)
		e.out = NewPrintWriter(os.Stdout)
	} else {
		inFile, _ := os.Open("input.txt")
		defer inFile.Close()
		e.in = NewFastScanner(inFile)
		outFile, _ := os.Create("output.txt")
		defer outFile.Close()
		e.out = NewPrintWriter(outFile)
	}
	e.Solve()
	e.out.Flush()
}

func main() {
	e := NewE()
	e.Run()
}
