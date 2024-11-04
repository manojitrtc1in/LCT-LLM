package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	eps       = 1e-12
	MAX_MOD   = 1000000007
	GYAKU     = 500000004
	MOD       = 998244353
)

type Point struct {
	x, y float64
}

type Line struct {
	first, second Point
}

type Circle struct {
	center Point
	r      float64
}

func dot(a, b Point) float64 {
	return a.x*b.x + a.y*b.y
}

func cross(a, b Point) float64 {
	return a.x*b.y - a.y*b.x
}

func DistLinePoint(a Line, b Point) float64 {
	if dot(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y}) < eps {
		return distance(b, a.first)
	}
	if dot(Point{a.first.x - a.second.x, a.first.y - a.second.y}, Point{b.x - a.second.x, b.y - a.second.y}) < eps {
		return distance(b, a.second)
	}
	return math.Abs(cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y})) / distance(a.second, a.first)
}

func distance(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func isIntersectedLS(a, b Line) bool {
	return (cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.first.x - a.first.x, b.first.y - a.first.y})*cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.second.x - a.first.x, b.second.y - a.first.y}) < eps) &&
		(cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.first.x - b.first.x, a.first.y - b.first.y})*cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.second.x - b.first.x, a.second.y - b.first.y}) < eps)
}

func intersectionL(a, b Line) Point {
	da := Point{a.second.x - a.first.x, a.second.y - a.first.y}
	db := Point{b.second.x - b.first.x, b.second.y - b.first.y}
	return Point{
		x: a.first.x + da.x * cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y}) / cross(db, da),
		y: a.first.y + da.y * cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y}) / cross(db, da),
	}
}

func DistLineLine(a, b Line) float64 {
	if isIntersectedLS(a, b) {
		return 0
	}
	return math.Min(math.Min(DistLinePoint(a, b.first), DistLinePoint(a, b.second)), math.Min(DistLinePoint(b, a.first), DistLinePoint(b, a.second)))
}

func intersectionCircleCircle(a, b Circle) (Point, Point) {
	dist := distance(a.center, b.center)
	if dist > eps+a.r+b.r || dist+eps < math.Abs(a.r-b.r) {
		panic("Circles do not intersect")
	}
	target := Point{b.center.x - a.center.x, b.center.y - a.center.y}
	pointer := target.x*target.x + target.y*target.y
	aa := (pointer + a.r*a.r - b.r*b.r) / 2.0
	l := Point{
		x: (aa*target.x + target.y*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		y: (aa*target.y - target.x*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r := Point{
		x: (aa*target.x - target.y*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		y: (aa*target.y + target.x*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r.x += a.center.x
	r.y += a.center.y
	l.x += a.center.x
	l.y += a.center.y
	return l, r
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

type Compressor struct {
	isZipped bool
	zipper   map[Fraction]int
	unzipper map[int]Fraction
	fetcher  []Fraction
}

func NewCompressor() *Compressor {
	return &Compressor{
		isZipped: false,
		zipper:   make(map[Fraction]int),
		unzipper: make(map[int]Fraction),
		fetcher:  []Fraction{},
	}
}

func (c *Compressor) Add(now Fraction) {
	if c.isZipped {
		panic("Already zipped")
	}
	c.zipper[now] = 1
	c.fetcher = append(c.fetcher, now)
}

func (c *Compressor) Exec() {
	if c.isZipped {
		panic("Already zipped")
	}
	cnt := 0
	for k := range c.zipper {
		c.zipper[k] = cnt
		c.unzipper[cnt] = k
		cnt++
	}
	c.isZipped = true
}

func (c *Compressor) Fetch() int {
	if !c.isZipped {
		panic("Not zipped")
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) Zip(now Fraction) int {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.zipper[now]
}

func (c *Compressor) Unzip(a int) Fraction {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.unzipper[a]
}

type SegmentTree struct {
	data []int
	f    func(int, int) int
	M1   int
}

func NewSegmentTree(n int, f func(int, int) int, M1 int) *SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	data := make([]int, 2*sz)
	for i := range data {
		data[i] = M1
	}
	return &SegmentTree{data: data, f: f, M1: M1}
}

func (st *SegmentTree) Set(k int, x int) {
	st.data[k+len(st.data)/2] = x
}

func (st *SegmentTree) Build() {
	for k := len(st.data)/2 - 1; k > 0; k-- {
		st.data[k] = st.f(st.data[2*k], st.data[2*k+1])
	}
}

func (st *SegmentTree) Update(k int, x int) {
	k += len(st.data) / 2
	st.data[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		st.data[k] = st.f(st.data[2*k], st.data[2*k+1])
	}
}

func (st *SegmentTree) Query(a, b int) int {
	L, R := st.M1, st.M1
	for a, b = a+len(st.data)/2, b+len(st.data)/2; a < b; a >>= 1 {
		if a&1 != 0 {
			L = st.f(L, st.data[a])
			a++
		}
	}
	for b >>= 1; a < b; b >>= 1 {
		if b&1 != 0 {
			b--
			R = st.f(st.data[b], R)
		}
	}
	return st.f(L, R)
}

type Fraction struct {
	a, b int64
}

func NewFraction(c, d int64) Fraction {
	hoge := gcd(int(c), int(d))
	c /= hoge
	d /= hoge
	if d < 0 {
		d *= -1
		c *= -1
	}
	return Fraction{a: c, b: d}
}

func (f Fraction) Less(rhs Fraction) bool {
	return f.a*rhs.b < rhs.a*f.b
}

func solve() {
	var n, w int64
	fmt.Scan(&n, &w)
	FI := []struct {
		left, right Fraction
	}{}
	for i := int64(0); i < n; i++ {
		var a, b int64
		fmt.Scan(&a, &b)
		left := NewFraction(-a, b-w)
		right := NewFraction(-a, b+w)
		right.a *= -1
		FI = append(FI, struct {
			left, right Fraction
		}{left: left, right: right})
	}
	sort.Slice(FI, func(i, j int) bool {
		return FI[i].left.Less(FI[j].left)
	})
	ans := int64(0)
	zip := NewCompressor()
	for _, f := range FI {
		f.right.a *= -1
		zip.Add(f.right)
	}
	seg := NewSegmentTree(2*int(n), func(a, b int) int {
		return a + b
	}, 0)
	zip.Exec()
	for _, f := range FI {
		hoge := zip.Fetch()
		ans += int64(seg.Query(hoge, 2*int(n)))
		tmp := seg.data[hoge]
		seg.Update(hoge, tmp+1)
	}
	fmt.Println(ans)
}

func main() {
	solve()
}
