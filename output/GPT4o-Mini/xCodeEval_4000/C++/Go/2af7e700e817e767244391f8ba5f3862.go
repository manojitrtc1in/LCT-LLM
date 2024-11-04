package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

const (
	eps         = 1e-8
	MAX_MOD     = 1000000007
	GYAKU       = 500000004
	MOD         = 998244353
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

func isIntersectedLS(a, b Line) bool {
	return (cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.first.x - a.first.x, b.first.y - a.first.y}) * cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.second.x - a.first.x, b.second.y - a.first.y}) < eps) &&
		(cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.first.x - b.first.x, a.first.y - b.first.y}) * cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.second.x - b.first.x, a.second.y - b.first.y}) < eps)
}

func intersectionL(a, b Line) Point {
	da := Point{a.second.x - a.first.x, a.second.y - a.first.y}
	db := Point{b.second.x - b.first.x, b.second.y - b.first.y}
	return Point{
		x: a.first.x + da.x*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
		y: a.first.y + da.y*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
	}
}

func distance(a, b Point) float64 {
	return math.Sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
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
		return Point{}, Point{}
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

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

type Compressor struct {
	isZipped bool
	zipper   map[int64]int64
	unzipper map[int64]int64
	fetcher  []int64
}

func NewCompressor() *Compressor {
	return &Compressor{
		isZipped: false,
		zipper:   make(map[int64]int64),
		unzipper: make(map[int64]int64),
		fetcher:  []int64{},
	}
}

func (c *Compressor) Add(now int64) {
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
	cnt := int64(0)
	for k := range c.zipper {
		c.zipper[k] = cnt
		c.unzipper[cnt] = k
		cnt++
	}
	c.isZipped = true
}

func (c *Compressor) Fetch() int64 {
	if !c.isZipped {
		panic("Not zipped")
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) Zip(now int64) int64 {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.zipper[now]
}

func (c *Compressor) Unzip(a int64) int64 {
	if !c.isZipped {
		panic("Not zipped")
	}
	return c.unzipper[a]
}

func (c *Compressor) Next(now int64) int64 {
	for k := range c.zipper {
		if k > now {
			return c.zipper[k]
		}
	}
	return int64(len(c.zipper))
}

func (c *Compressor) Back(now int64) int64 {
	for k := range c.zipper {
		if k < now {
			return c.zipper[k]
		}
	}
	return -1
}

type Matrix struct {
	data [][]int64
}

func NewMatrix(a [][]int64) *Matrix {
	return &Matrix{data: a}
}

func (m *Matrix) Add(obj *Matrix) *Matrix {
	ans := [][]int64{}
	for i := range obj.data {
		row := []int64{}
		for j := range obj.data[i] {
			hoge := obj.data[i][j] + m.data[i][j]
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

func (m *Matrix) Subtract(obj *Matrix) *Matrix {
	ans := [][]int64{}
	for i := range obj.data {
		row := []int64{}
		for j := range obj.data[i] {
			hoge := m.data[i][j] - obj.data[i][j]
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

func (m *Matrix) Multiply(obj *Matrix) *Matrix {
	ans := [][]int64{}
	for i := range m.data {
		row := []int64{}
		for j := range obj.data[0] {
			hoge := m.data[i][0] * obj.data[0][j]
			for t := 1; t < len(obj.data); t++ {
				hoge += m.data[i][t] * obj.data[t][j]
			}
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

type Fraction struct {
	a, b int64
}

func NewFraction(c, d int64) Fraction {
	hoge := gcd(abs(c), abs(d))
	if hoge != 0 {
		c /= hoge
		d /= hoge
		if d < 0 || (d == 0 && c < 0) {
			d *= -1
			c *= -1
		}
	}
	return Fraction{a: c, b: d}
}

func (f Fraction) Less(rhs Fraction) bool {
	if f.a < 0 && rhs.a > 0 {
		return true
	}
	if f.a > 0 && rhs.a < 0 {
		return false
	}
	return f.a*rhs.b < rhs.a*f.b
}

func (f Fraction) Equal(rhs Fraction) bool {
	return f.a == rhs.a && f.b == rhs.b
}

type ModInt struct {
	value uint64
}

func NewModInt(a int64, mod uint64) ModInt {
	return ModInt{value: uint64(a % int64(mod))}
}

func (m ModInt) Add(rhs ModInt, mod uint64) ModInt {
	return NewModInt(int64(m.value+rhs.value), mod)
}

func (m ModInt) Sub(rhs ModInt, mod uint64) ModInt {
	return NewModInt(int64(m.value-rhs.value), mod)
}

func (m ModInt) Mul(rhs ModInt, mod uint64) ModInt {
	return NewModInt(int64(m.value*rhs.value), mod)
}

func (m ModInt) Div(rhs ModInt, mod uint64) ModInt {
	rem := mod - 2
	for rem > 0 {
		if rem%2 == 1 {
			m = m.Mul(rhs, mod)
		}
		rhs = rhs.Mul(rhs, mod)
		rem /= 2
	}
	return m
}

func (m ModInt) Less(rhs ModInt) bool {
	return m.value < rhs.value
}

func (m ModInt) String() string {
	return fmt.Sprintf("%d", m.value)
}

type Dice struct {
	vertexs []int64
}

func NewDice(init []int64) *Dice {
	return &Dice{vertexs: init}
}

func (d *Dice) RtoL() {
	for q := 1; q < 4; q++ {
		d.vertexs[q], d.vertexs[q+1] = d.vertexs[q+1], d.vertexs[q]
	}
}

func (d *Dice) LtoR() {
	for q := 3; q >= 1; q-- {
		d.vertexs[q], d.vertexs[q+1] = d.vertexs[q+1], d.vertexs[q]
	}
}

func (d *Dice) UtoD() {
	d.vertexs[5], d.vertexs[4] = d.vertexs[4], d.vertexs[5]
	d.vertexs[2], d.vertexs[5] = d.vertexs[5], d.vertexs[2]
	d.vertexs[0], d.vertexs[2] = d.vertexs[2], d.vertexs[0]
}

func (d *Dice) DtoU() {
	d.vertexs[0], d.vertexs[2] = d.vertexs[2], d.vertexs[0]
	d.vertexs[2], d.vertexs[5] = d.vertexs[5], d.vertexs[2]
	d.vertexs[5], d.vertexs[4] = d.vertexs[4], d.vertexs[5]
}

func (d *Dice) ReachAble(now Dice) bool {
	hoge := make(map[Dice]struct{})
	next := []Dice{now}
	hoge[now] = struct{}{}
	for len(next) > 0 {
		seeing := next[0]
		next = next[1:]
		if seeing == *d {
			return true
		}
		seeing.RtoL()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.LtoR()
		seeing.LtoR()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.RtoL()
		seeing.UtoD()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.DtoU()
		seeing.DtoU()
		if _, exists := hoge[seeing]; !exists {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
	}
	return false
}

func (d *Dice) Equal(a Dice) bool {
	for q := 0; q < 6; q++ {
		if a.vertexs[q] != d.vertexs[q] {
			return false
		}
	}
	return true
}

func (d *Dice) Less(a Dice) bool {
	for i := 0; i < 6; i++ {
		if d.vertexs[i] < a.vertexs[i] {
			return true
		}
		if d.vertexs[i] > a.vertexs[i] {
			return false
		}
	}
	return false
}

func TwoDimDice(center, up int64) (Dice, Dice) {
	target := int64(1)
	for {
		if center != target && 7-center != target && up != target && 7-up != target {
			break
		}
		target++
	}
	return NewDice([]int64{up, target, center, 7 - target, 7 - center, 7 - up}),
		NewDice([]int64{up, 7 - target, center, target, 7 - center, 7 - up})
}

func OneDimDice(center int64) (Dice, Dice, Dice, Dice) {
	bo := min(center, 7-center)
	var goa [2]int64
	if bo == 1 {
		goa = [2]int64{2, 3}
	} else if bo == 2 {
		goa = [2]int64{1, 3}
	} else if bo == 3 {
		goa = [2]int64{1, 2}
	}
	return NewDice([]int64{goa[0], goa[1], center, 7 - goa[1], 7 - center, 7 - goa[0]}),
		NewDice([]int64{goa[0], 7 - goa[1], center, goa[1], 7 - center, 7 - goa[0]}),
		NewDice([]int64{7 - goa[0], goa[1], center, 7 - goa[1], 7 - center, goa[0]}),
		NewDice([]int64{7 - goa[0], 7 - goa[1], center, goa[1], 7 - center, goa[0]})
}

type Dijkstra struct {
	vertexs      [][]Pair
	CostFunction func(A) int64
}

type Pair struct {
	first int
	second int64
}

func NewDijkstra(n int, cost func(A) int64) *Dijkstra {
	return &Dijkstra{
		vertexs:      make([][]Pair, n),
		CostFunction: cost,
	}
}

func (d *Dijkstra) AddEdge(a, b int, c int64) {
	d.vertexs[a] = append(d.vertexs[a], Pair{first: b, second: c})
}

func (d *Dijkstra) BuildResult(startPoint int) []int64 {
	dist := make([]int64, len(d.vertexs))
	for i := range dist {
		dist[i] = 2e18
	}
	dist[startPoint] = 0
	next := &PriorityQueue{}
	heap.Push(next, Pair{first: 0, second: startPoint})
	for next.Len() > 0 {
		now := heap.Pop(next).(Pair)
		if dist[now.second] != now.first {
			continue
		}
		for _, x := range d.vertexs[now.second] {
			nowCost := now.first + d.CostFunction(x.second)
			if dist[x.first] > nowCost {
				dist[x.first] = nowCost
				heap.Push(next, Pair{first: nowCost, second: x.first})
			}
		}
	}
	return dist
}

type Dinic struct {
	Graph [][]Edge
	level []int
	itr   []int
}

type Edge struct {
	to, cap, rev int
}

func NewDinic(n int) *Dinic {
	return &Dinic{
		Graph: make([][]Edge, n),
	}
}

func (d *Dinic) AddEdge(a, b, cap int) {
	d.Graph[a] = append(d.Graph[a], Edge{to: b, cap: cap, rev: len(d.Graph[b])})
	d.Graph[b] = append(d.Graph[b], Edge{to: a, cap: 0, rev: len(d.Graph[a]) - 1})
}

func (d *Dinic) Bfs(s int) {
	d.level = make([]int, len(d.Graph))
	for i := range d.level {
		d.level[i] = -1
	}
	d.level[s] = 0
	next := []int{s}
	for len(next) > 0 {
		now := next[0]
		next = next[1:]
		for _, x := range d.Graph[now] {
			if x.cap == 0 {
				continue
			}
			if d.level[x.to] == -1 {
				d.level[x.to] = d.level[now] + 1
				next = append(next, x.to)
			}
		}
	}
}

func (d *Dinic) Dfs(now, goal, val int) int {
	if goal == now {
		return val
	}
	for i := d.itr[now]; i < len(d.Graph[now]); i++ {
		target := &d.Graph[now][i]
		if target.cap > 0 && d.level[now] < d.level[target.to] {
			d.itr[now] = i
			d := d.Dfs(target.to, goal, min(val, target.cap))
			if d > 0 {
				target.cap -= d
				d.Graph[target.to][target.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func (d *Dinic) Run(s, t int) int {
	ans := 0
	f := 0
	for {
		d.Bfs(s)
		if d.level[t] < 0 {
			break
		}
		d.itr = make([]int, len(d.Graph))
		for {
			f = d.Dfs(s, t, 1e9)
			if f == 0 {
				break
			}
			ans += f
		}
	}
	return ans
}

type HLDecomposition struct {
	vertexs     [][]int
	depth       []int
	backs       []int
	connections []int
	zip         []int
	unzip       []int
}

func NewHLDecomposition(n int) *HLDecomposition {
	return &HLDecomposition{
		vertexs: make([][]int, n),
		depth:   make([]int, n),
		zip:     make([]int, n),
		unzip:   make([]int, n),
	}
}

func (h *HLDecomposition) AddEdge(a, b int) {
	h.vertexs[a] = append(h.vertexs[a], b)
	h.vertexs[b] = append(h.vertexs[b], a)
}

func (h *HLDecomposition) DepthDFS(now, back int) int {
	h.depth[now] = 0
	for _, x := range h.vertexs[now] {
		if x == back {
			continue
		}
		h.depth[now] = max(h.depth[now], 1+h.DepthDFS(x, now))
	}
	return h.depth[now]
}

func (h *HLDecomposition) Dfs(now, backing int) {
	h.zip[now] = len(h.backs)
	h.unzip[len(h.backs)] = now
	h.backs = append(h.backs, backing)
	nowMax := -1
	itr := -1
	for _, x := range h.vertexs[now] {
		if h.depth[x] > h.depth[now] {
			continue
		}
		if nowMax < h.depth[x] {
			nowMax = h.depth[x]
			itr = x
		}
	}
	if itr == -1 {
		return
	}
	h.connections = append(h.connections, h.connections[len(h.connections)-1])
	h.Dfs(itr, backing)
	for _, x := range h.vertexs[now] {
		if h.depth[x] > h.depth[now] {
			continue
		}
		if x == itr {
			continue
		}
		h.connections = append(h.connections, h.zip[now])
		h.Dfs(x, len(h.backs))
	}
}

func (h *HLDecomposition) Build() {
	h.DepthDFS(0, -1)
	h.connections = append(h.connections, -1)
	h.Dfs(0, -1)
}

func (h *HLDecomposition) Query(a, b int) []Pair {
	a = h.zip[a]
	b = h.zip[b]
	ans := []Pair{}
	for h.backs[a] != h.backs[b] {
		if a < b {
			swap(&a, &b)
		}
		ans = append(ans, Pair{first: h.backs[a], second: a + 1})
		a = h.connections[a]
	}
	if a > b {
		swap(&a, &b)
	}
	ans = append(ans, Pair{first: a, second: b + 1})
	return ans
}

func (h *HLDecomposition) LCA(a, b int) int {
	a = h.zip[a]
	b = h.zip[b]
	for h.backs[a] != h.backs[b] {
		if a < b {
			swap(&a, &b)
		}
		a = h.connections[a]
	}
	return h.unzip[min(a, b)]
}

type SegmentTree struct {
	sz  int
	seg []int64
	f   func(int64, int64) int64
	M1  int64
}

func NewSegmentTree(n int, f func(int64, int64) int64, M1 int64) *SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	seg := make([]int64, 2*sz+1)
	for i := range seg {
		seg[i] = M1
	}
	return &SegmentTree{sz: sz, seg: seg, f: f, M1: M1}
}

func (s *SegmentTree) Set(k int, x int64) {
	s.seg[k+s.sz] = x
}

func (s *SegmentTree) Build() {
	for k := s.sz - 1; k > 0; k-- {
		s.seg[k] = s.f(s.seg[2*k+0], s.seg[2*k+1])
	}
}

func (s *SegmentTree) Update(k int, x int64) {
	k += s.sz
	s.seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		s.seg[k] = s.f(s.seg[2*k+0], s.seg[2*k+1])
	}
}

func (s *SegmentTree) Query(a, b int) int64 {
	L, R := s.M1, s.M1
	for a += s.sz; b += s.sz; a < b; a >>= 1 {
		if a&1 != 0 {
			L = s.f(L, s.seg[a])
			a++
		}
		if b&1 != 0 {
			b--
			R = s.f(s.seg[b], R)
		}
	}
	return s.f(L, R)
}

func (s *SegmentTree) Get(k int) int64 {
	return s.seg[k+s.sz]
}

type LazySegmentTree struct {
	sz      int
	height  int
	data    []int64
	lazy    []int64
	f       func(int64, int64) int64
	g       func(int64, int64) int64
	h       func(int64, int64) int64
	M1      int64
	OM0     int64
}

func NewLazySegmentTree(n int, f func(int64, int64) int64, g func(int64, int64) int64, h func(int64, int64) int64, M1 int64, OM0 int64) *LazySegmentTree {
	sz := 1
	height := 0
	for sz < n {
		sz <<= 1
		height++
	}
	data := make([]int64, 2*sz)
	lazy := make([]int64, 2*sz)
	for i := range data {
		data[i] = M1
	}
	for i := range lazy {
		lazy[i] = OM0
	}
	return &LazySegmentTree{sz: sz, height: height, data: data, lazy: lazy, f: f, g: g, h: h, M1: M1, OM0: OM0}
}

func (l *LazySegmentTree) Set(k int, x int64) {
	l.data[k+l.sz] = x
}

func (l *LazySegmentTree) Build() {
	for k := l.sz - 1; k > 0; k-- {
		l.data[k] = l.f(l.data[2*k+0], l.data[2*k+1])
	}
}

func (l *LazySegmentTree) Propagate(k int) {
	if l.lazy[k] != l.OM0 {
		l.lazy[2*k+0] = l.h(lazy[2*k+0], l.lazy[k])
		l.lazy[2*k+1] = l.h(lazy[2*k+1], l.lazy[k])
		l.data[k] = l.Reflect(k)
		l.lazy[k] = l.OM0
	}
}

func (l *LazySegmentTree) Reflect(k int) int64 {
	if l.lazy[k] == l.OM0 {
		return l.data[k]
	}
	return l.g(l.data[k], l.lazy[k])
}

func (l *LazySegmentTree) Recalc(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		l.data[k] = l.f(l.Reflect(2*k+0), l.Reflect(2*k+1))
	}
}

func (l *LazySegmentTree) Thrust(k int) {
	for i := l.height; i > 0; i-- {
		l.Propagate(k >> i)
	}
}

func (l *LazySegmentTree) Update(a, b int, x int64) {
	l.Thrust(a + l.sz)
	l.Thrust(b + l.sz - 1)
	for l, r := a, b+1; l < r; l >>= 1 {
		if l&1 != 0 {
			lazy[l] = l.h(lazy[l], x)
			l++
		}
		if r&1 != 0 {
			r--
			lazy[r] = l.h(lazy[r], x)
		}
	}
	l.Recalc(a)
	l.Recalc(b)
}

func (l *LazySegmentTree) Query(a, b int) int64 {
	l.Thrust(a + l.sz)
	l.Thrust(b + l.sz - 1)
	L, R := l.M1, l.M1
	for l, r := a + l.sz, b + l.sz; l < r; l >>= 1 {
		if l&1 != 0 {
			L = l.f(L, l.Reflect(l))
			l++
		}
		if r&1 != 0 {
			r--
			R = l.f(l.Reflect(r), R)
		}
	}
	return l.f(L, R)
}

func (l *LazySegmentTree) Get(k int) int64 {
	return l.Query(k, k+1)
}

type KMP struct {
	table   []int64
	Pattern []int64
}

func NewKMP(a []int64) *KMP {
	return &KMP{Pattern: a}
}

func (k *KMP) Build(a []int64) {
	k.Pattern = a
	k.table = make([]int64, len(a)+1)
	j := int64(-1)
	for i := 0; i < len(a); i++ {
		for j >= 0 && k.Pattern[i] != k.Pattern[j] {
			j = k.table[j]
		}
		k.table[i+1] = j + 1
	}
}

func (k *KMP) Search(a []int64) []int64 {
	ans := []int64{}
	for i, k := 0, int64(0); i < len(a); i++ {
		for k >= 0 && a[i] != k.Pattern[k] {
			k = k.table[k]
		}
		k++
		if k >= int64(len(k.Pattern)) {
			ans = append(ans, i-int64(len(k.Pattern))+1)
			k = k.table[k]
		}
	}
	return ans
}

func xor128() uint64 {
	staticX := uint64(123456789)
	staticY := uint64(362436069)
	staticZ := uint64(521288629)
	staticW := uint64(88675123)
	t := (staticX ^ (staticX << 11))
	staticX = staticY
	staticY = staticZ
	staticZ = staticW
	return (staticW = (staticW ^ (staticW >> 19)) ^ (t ^ (t >> 8)))
}

func init() {
	fmt.Println("Initialization")
}

func solve() {
	var n int
	fmt.Scan(&n)
	inputs := make([]Vert, n)
	for i := 0; i < n; i++ {
		var a Vert
		for q := 0; q < 5; q++ {
			fmt.Scan(&a.hoge[q])
		}
		inputs[i] = a
	}
	ans := []int{}
	for i := 0; i < n; i++ {
		ok := true
		for q := 0; q < n; q++ {
			if i == q {
				continue
			}
			for j := q + 1; j < n; j++ {
				if i == j {
					continue
				}
				var A, B Vert
				for t := 0; t < 5; t++ {
					A.hoge[t] = inputs[q].hoge[t] - inputs[i].hoge[t]
					B.hoge[t] = inputs[j].hoge[t] - inputs[i].hoge[t]
				}
				if sign(A, B) == false {
					ok = false
					break
				}
			}
			if !ok {
				break
			}
		}
		if ok {
			ans = append(ans, i)
		}
	}
	fmt.Println(len(ans))
	for _, v := range ans {
		fmt.Printf("%d ", v+1)
	}
	fmt.Println()
}

func main() {
	init()
	solve()
}
