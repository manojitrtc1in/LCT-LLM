package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
)

type State string

type Point struct {
	real, imag float64
}

type Line struct {
	first, second Point
}

type Circle struct {
	center Point
	r      float64
}

func dot(a, b Point) float64 {
	return a.real*b.real + a.imag*b.imag
}

func cross(a, b Point) float64 {
	return a.real*b.imag - a.imag*b.real
}

func id3(a Line, b Point) float64 {
	if dot(Point{a.second.real - a.first.real, a.second.imag - a.first.imag}, Point{b.real - a.first.real, b.imag - a.first.imag}) < eps {
		return math.Sqrt(math.Pow(b.real-a.first.real, 2) + math.Pow(b.imag-a.first.imag, 2))
	}
	if dot(Point{a.first.real - a.second.real, a.first.imag - a.second.imag}, Point{b.real - a.second.real, b.imag - a.second.imag}) < eps {
		return math.Sqrt(math.Pow(b.real-a.second.real, 2) + math.Pow(b.imag-a.second.imag, 2))
	}
	return math.Abs(cross(Point{a.second.real - a.first.real, a.second.imag - a.first.imag}, Point{b.real - a.first.real, b.imag - a.first.imag})) / math.Sqrt(math.Pow(a.second.real-a.first.real, 2)+math.Pow(a.second.imag-a.first.imag, 2))
}

func id0(a, b Line) int {
	return (cross(Point{a.second.real - a.first.real, a.second.imag - a.first.imag}, Point{b.first.real - a.first.real, b.first.imag - a.first.imag})*cross(Point{a.second.real - a.first.real, a.second.imag - a.first.imag}, Point{b.second.real - a.first.real, b.second.imag - a.first.imag}) < eps) &&
		(cross(Point{b.second.real - b.first.real, b.second.imag - b.first.imag}, Point{a.first.real - b.first.real, a.first.imag - b.first.imag})*cross(Point{b.second.real - b.first.real, b.second.imag - b.first.imag}, Point{a.second.real - b.first.real, a.second.imag - b.first.imag}) < eps)
}

func intersectionL(a, b Line) Point {
	da := Point{a.second.real - a.first.real, a.second.imag - a.first.imag}
	db := Point{b.second.real - b.first.real, b.second.imag - b.first.imag}
	return Point{
		a.first.real + da.real * cross(db, Point{b.first.real - a.first.real, b.first.imag - a.first.imag}) / cross(db, da),
		a.first.imag + da.imag * cross(db, Point{b.first.real - a.first.real, b.first.imag - a.first.imag}) / cross(db, da),
	}
}

func id8(a, b Line) float64 {
	if id0(a, b) == 1 {
		return 0
	}
	return math.Min(math.Min(id3(a, b.first), id3(a, b.second)), math.Min(id3(b, a.first), id3(b, a.second)))
}

func id9(a, b Circle) (Point, Point) {
	dist := math.Sqrt(math.Pow(a.center.real-b.center.real, 2) + math.Pow(a.center.imag-b.center.imag, 2))
	if dist > eps+a.r+b.r || dist+eps < math.Abs(a.r-b.r) {
		panic("Invalid circles")
	}
	target := Point{b.center.real - a.center.real, b.center.imag - a.center.imag}
	pointer := target.real*target.real + target.imag*target.imag
	aa := (pointer + a.r*a.r - b.r*b.r) / 2.0
	l := Point{
		(aa*target.real + target.imag*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		(aa*target.imag - target.real*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r := Point{
		(aa*target.real - target.imag*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
		(aa*target.imag + target.real*math.Sqrt(pointer*a.r*a.r-aa*aa)) / pointer,
	}
	r = Point{r.real + a.center.real, r.imag + a.center.imag}
	l = Point{l.real + a.center.real, l.imag + a.center.imag}
	return l, r
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func pows(val float64, b int64) float64 {
	if b < 1 {
		panic("b must be >= 1")
	}
	ans := val
	b--
	for b > 0 {
		if b%2 == 1 {
			ans *= val
		}
		val *= val
		b /= 2
	}
	return ans
}

type Compressor struct {
	id6      bool
	zipper   map[Fraction]int64
	unzipper map[int64]Fraction
	fetcher  []Fraction
}

func NewCompressor() *Compressor {
	return &Compressor{
		id6:      false,
		zipper:   make(map[Fraction]int64),
		unzipper: make(map[int64]Fraction),
		fetcher:  []Fraction{},
	}
}

func (c *Compressor) add(now Fraction) {
	if c.id6 {
		panic("Already executed")
	}
	c.zipper[now] = 1
	c.fetcher = append(c.fetcher, now)
}

func (c *Compressor) exec() {
	if c.id6 {
		panic("Already executed")
	}
	cnt := 0
	for k := range c.zipper {
		c.zipper[k] = int64(cnt)
		c.unzipper[int64(cnt)] = k
		cnt++
	}
	c.id6 = true
}

func (c *Compressor) fetch() int64 {
	if !c.id6 {
		panic("Not executed")
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) zip(now Fraction) int64 {
	if !c.id6 {
		panic("Not executed")
	}
	if _, ok := c.zipper[now]; !ok {
		panic("Not found")
	}
	return c.zipper[now]
}

func (c *Compressor) unzip(a int64) Fraction {
	if !c.id6 {
		panic("Not executed")
	}
	if a >= int64(len(c.unzipper)) {
		panic("Out of bounds")
	}
	return c.unzipper[a]
}

func (c *Compressor) next(now Fraction) int64 {
	for k, v := range c.zipper {
		if k > now {
			return v
		}
	}
	return int64(len(c.zipper))
}

func (c *Compressor) back(now Fraction) int64 {
	for k, v := range c.zipper {
		if k < now {
			return v
		}
	}
	return -1
}

type Matrix struct {
	data [][]int
}

func NewMatrix(a [][]int) *Matrix {
	return &Matrix{data: a}
}

func (m *Matrix) Add(obj *Matrix) *Matrix {
	ans := [][]int{}
	if len(obj.data) != len(m.data) || len(obj.data[0]) != len(m.data[0]) {
		panic("Matrix size mismatch")
	}
	for i := range obj.data {
		row := []int{}
		for j := range obj.data[i] {
			hoge := obj.data[i][j] + m.data[i][j]
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

func (m *Matrix) Subtract(obj *Matrix) *Matrix {
	ans := [][]int{}
	if len(obj.data) != len(m.data) || len(obj.data[0]) != len(m.data[0]) {
		panic("Matrix size mismatch")
	}
	for i := range obj.data {
		row := []int{}
		for j := range obj.data[i] {
			hoge := m.data[i][j] - obj.data[i][j]
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

func (m *Matrix) Multiply(obj *Matrix) *Matrix {
	ans := [][]int{}
	if len(obj.data) != len(m.data[0]) {
		panic("Matrix size mismatch")
	}
	for i := range m.data {
		row := []int{}
		for j := range obj.data[0] {
			hoge := m.data[i][0] * obj.data[0][j]
			for t := 1; t < len(obj.data[i]); t++ {
				hoge += m.data[i][t] * obj.data[t][j]
			}
			row = append(row, hoge)
		}
		ans = append(ans, row)
	}
	return NewMatrix(ans)
}

type ModInt struct {
	value uint64
	mod   uint64
}

func NewModInt(a int64, mod uint64) ModInt {
	return ModInt{value: uint64((a%int64(mod) + 2*int64(mod)) % int64(mod)), mod: mod}
}

func (m ModInt) Add(rhs ModInt) ModInt {
	return NewModInt(int64(m.value+rhs.value), m.mod)
}

func (m ModInt) Subtract(rhs ModInt) ModInt {
	if m.value < rhs.value {
		m.value += m.mod
	}
	return NewModInt(int64(m.value-rhs.value), m.mod)
}

func (m ModInt) Multiply(rhs ModInt) ModInt {
	return NewModInt(int64((m.value * rhs.value) % m.mod), m.mod)
}

func (m ModInt) Divide(rhs ModInt) ModInt {
	rem := m.mod - 2
	for rem > 0 {
		if rem%2 == 1 {
			m = m.Multiply(rhs)
		}
		rhs = rhs.Multiply(rhs)
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
		if _, ok := hoge[seeing]; !ok {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.LtoR()
		seeing.LtoR()
		if _, ok := hoge[seeing]; !ok {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.RtoL()
		seeing.UtoD()
		if _, ok := hoge[seeing]; !ok {
			hoge[seeing] = struct{}{}
			next = append(next, seeing)
		}
		seeing.DtoU()
		seeing.DtoU()
		if _, ok := hoge[seeing]; !ok {
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
	return d.vertexs < a.vertexs
}

func id1(center, up int) (Dice, Dice) {
	target := 1
	for {
		if center != target && 7-center != target && up != target && 7-up != target {
			break
		}
		target++
	}
	return Dice{vertexs: []int64{int64(up), int64(target), int64(center), int64(7 - target), int64(7 - center), int64(7 - up)}},
		Dice{vertexs: []int64{int64(up), int64(7 - target), int64(center), int64(target), int64(7 - center), int64(7 - up)}}
}

func id2(center int) (Dice, Dice, Dice, Dice) {
	bo := int(math.Min(float64(center), float64(7-center)))
	var goa [2]int
	if bo == 1 {
		goa = [2]int{2, 3}
	} else if bo == 2 {
		goa = [2]int{1, 3}
	} else if bo == 3 {
		goa = [2]int{1, 2}
	}
	return Dice{vertexs: []int64{int64(goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(7 - goa[0])}},
		Dice{vertexs: []int64{int64(goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(7 - goa[0])}},
		Dice{vertexs: []int64{int64(7 - goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(goa[0])}},
		Dice{vertexs: []int64{int64(7 - goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(goa[0])}}
}

type Dijkstra struct {
	vertexs      [][]struct{ to int; cost int64 }
	CostFunction func(int64) int64
}

func NewDijkstra(n int, cost func(int64) int64) *Dijkstra {
	vertexs := make([][]struct{ to int; cost int64 }, n)
	return &Dijkstra{vertexs: vertexs, CostFunction: cost}
}

func (d *Dijkstra) AddEdge(a, b int, c int64) {
	d.vertexs[a] = append(d.vertexs[a], struct{ to int; cost int64 }{to: b, cost: c})
}

func (d *Dijkstra) BuildResult(startPoint int) []int64 {
	dist := make([]int64, len(d.vertexs))
	for i := range dist {
		dist[i] = math.MaxInt64
	}
	dist[startPoint] = 0
	next := &PriorityQueue{}
	heap.Push(next, &Item{value: 0, index: startPoint})
	for next.Len() > 0 {
		now := heap.Pop(next).(*Item)
		if dist[now.index] != now.value {
			continue
		}
		for _, x := range d.vertexs[now.index] {
			nowCost := now.value + d.CostFunction(x.cost)
			if dist[x.to] > nowCost {
				dist[x.to] = nowCost
				heap.Push(next, &Item{value: nowCost, index: x.to})
			}
		}
	}
	return dist
}

type Item struct {
	value int64
	index int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool { return pq[i].value < pq[j].value }

func (pq PriorityQueue) Swap(i, j int) { pq[i], pq[j] = pq[j], pq[i] }

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(*Item))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

type Dinic struct {
	Graph  [][]edge
	level  []int
	itr    []int
}

type edge struct {
	to, cap, rev int
}

func NewDinic(n int) *Dinic {
	Graph := make([][]edge, n)
	return &Dinic{Graph: Graph}
}

func (d *Dinic) AddEdge(a, b, cap int) {
	d.Graph[a] = append(d.Graph[a], edge{to: b, cap: cap, rev: len(d.Graph[b])})
	d.Graph[b] = append(d.Graph[b], edge{to: a, cap: 0, rev: len(d.Graph[a]) - 1})
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
			d := d.Dfs(target.to, goal, int(math.Min(float64(val), float64(target.cap))))
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
			f = d.Dfs(s, t, int(1e9))
			if f == 0 {
				break
			}
			ans += f
		}
	}
	return ans
}

type id7 struct {
	vertexs     [][]int
	depth       []int
	backs       []int
	connections []int
	zip         []int
	unzip       []int
}

func NewId7(n int) *id7 {
	vertexs := make([][]int, n)
	depth := make([]int, n)
	zip := make([]int, n)
	unzip := make([]int, n)
	return &id7{vertexs: vertexs, depth: depth, zip: zip, unzip: unzip}
}

func (i *id7) AddEdge(a, b int) {
	i.vertexs[a] = append(i.vertexs[a], b)
	i.vertexs[b] = append(i.vertexs[b], a)
}

func (i *id7) DepthDfs(now, back int) int {
	i.depth[now] = 0
	for _, x := range i.vertexs[now] {
		if x == back {
			continue
		}
		i.depth[now] = int(math.Max(float64(i.depth[now]), float64(1+i.DepthDfs(x, now))))
	}
	return i.depth[now]
}

func (i *id7) Dfs(now, backing int) {
	i.zip[now] = len(i.backs)
	i.unzip[len(i.backs)] = now
	i.backs = append(i.backs, backing)
	nowMax := -1
	itr := -1
	for _, x := range i.vertexs[now] {
		if i.depth[x] > i.depth[now] {
			continue
		}
		if nowMax < i.depth[x] {
			nowMax = i.depth[x]
			itr = x
		}
	}
	if itr == -1 {
		return
	}
	i.connections = append(i.connections, i.connections[len(i.connections)-1])
	i.Dfs(itr, backing)
	for _, x := range i.vertexs[now] {
		if i.depth[x] > i.depth[now] {
			continue
		}
		if x == itr {
			continue
		}
		i.connections = append(i.connections, i.zip[now])
		i.Dfs(x, len(i.backs))
	}
}

func (i *id7) Build() {
	i.DepthDfs(0, -1)
	i.connections = append(i.connections, -1)
	i.Dfs(0, -1)
}

func (i *id7) Query(a, b int) []struct{ first, second int } {
	a = i.zip[a]
	b = i.zip[b]
	ans := []struct{ first, second int }{}
	for i.backs[a] != i.backs[b] {
		if a < b {
			swap(&a, &b)
		}
		ans = append(ans, struct{ first, second int }{first: i.backs[a], second: a + 1})
		a = i.connections[a]
	}
	if a > b {
		swap(&a, &b)
	}
	ans = append(ans, struct{ first, second int }{first: a, second: b + 1})
	return ans
}

func (i *id7) Lca(a, b int) int {
	a = i.zip[a]
	b = i.zip[b]
	for i.backs[a] != i.backs[b] {
		if a < b {
			swap(&a, &b)
		}
		a = i.connections[a]
	}
	return i.unzip[int(math.Min(float64(a), float64(b)))]
}

type SegmentTree struct {
	sz   int
	seg  []int
	f    func(int, int) int
	M1   int
}

func NewSegmentTree(n int, f func(int, int) int, M1 int) *SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	seg := make([]int, 2*sz+1)
	for i := range seg {
		seg[i] = M1
	}
	return &SegmentTree{sz: sz, seg: seg, f: f, M1: M1}
}

func (s *SegmentTree) Set(k int, x int) {
	s.seg[k+s.sz] = x
}

func (s *SegmentTree) Build() {
	for k := s.sz - 1; k > 0; k-- {
		s.seg[k] = s.f(s.seg[2*k+0], s.seg[2*k+1])
	}
}

func (s *SegmentTree) Update(k int, x int) {
	k += s.sz
	s.seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		s.seg[k] = s.f(s.seg[2*k+0], s.seg[2*k+1])
	}
}

func (s *SegmentTree) Query(a, b int) int {
	L, R := s.M1, s.M1
	for a += s.sz; b += s.sz; a < b {
		if a&1 == 1 {
			L = s.f(L, s.seg[a])
			a++
		}
		if b&1 == 1 {
			b--
			R = s.f(s.seg[b], R)
		}
		a >>= 1
		b >>= 1
	}
	return s.f(L, R)
}

func (s *SegmentTree) Get(k int) int {
	return s.seg[k+s.sz]
}

type id5 struct {
	sz, height int
	data       []int
	lazy       []int
	f          func(int, int) int
	g          func(int, int, int) int
	h          func(int, int) int
	M1         int
	OM0        int
}

func NewId5(n int, f func(int, int) int, g func(int, int, int) int, h func(int, int) int, M1 int, OM0 int) *id5 {
	sz := 1
	height := 0
	for sz < n {
		sz <<= 1
		height++
	}
	data := make([]int, 2*sz)
	lazy := make([]int, 2*sz)
	for i := range data {
		data[i] = M1
		lazy[i] = OM0
	}
	return &id5{sz: sz, height: height, data: data, lazy: lazy, f: f, g: g, h: h, M1: M1, OM0: OM0}
}

func (i *id5) Set(k int, x int) {
	i.data[k+i.sz] = x
}

func (i *id5) Build() {
	for k := i.sz - 1; k > 0; k-- {
		i.data[k] = i.f(i.data[2*k+0], i.data[2*k+1])
	}
}

func (i *id5) Propagate(k int) {
	if i.lazy[k] != i.OM0 {
		i.lazy[2*k+0] = i.h(i.lazy[2*k+0], i.lazy[k])
		i.lazy[2*k+1] = i.h(i.lazy[2*k+1], i.lazy[k])
		i.data[k] = i.Reflect(k)
		i.lazy[k] = i.OM0
	}
}

func (i *id5) Reflect(k int) int {
	if i.lazy[k] == i.OM0 {
		return i.data[k]
	}
	for q := i.sz; q >= 0; q /= 2 {
		if q&k != 0 {
			return i.g(i.data[k], i.lazy[k], i.sz/q)
		}
	}
	return 0
}

func (i *id5) Recalc(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		i.data[k] = i.f(i.Reflect(2*k+0), i.Reflect(2*k+1))
	}
}

func (i *id5) Thrust(k int) {
	for j := i.height; j > 0; j-- {
		i.Propagate(k >> j)
	}
}

func (i *id5) Update(a, b int, x int) {
	i.Thrust(a + i.sz)
	i.Thrust(b + i.sz - 1)
	for l, r := a+i.sz, b+i.sz+1; l < r; l >>= 1 {
		if l&1 == 1 {
			i.lazy[l] = i.h(i.lazy[l], x)
			l++
		}
		if r&1 == 1 {
			r--
			i.lazy[r] = i.h(i.lazy[r], x)
		}
	}
	i.Recalc(a)
	i.Recalc(b)
}

func (i *id5) Query(a, b int) int {
	i.Thrust(a + i.sz)
	i.Thrust(b + i.sz - 1)
	L, R := i.M1, i.M1
	for l, r := a+i.sz, b+i.sz+1; l < r; l >>= 1 {
		if l&1 == 1 {
			L = i.f(L, i.Reflect(l))
			l++
		}
		if r&1 == 1 {
			r--
			R = i.f(i.Reflect(r), R)
		}
	}
	return i.f(L, R)
}

func (i *id5) Get(k int) int {
	return i.Query(k, k+1)
}

type KMP struct {
	table   []int
	Pattern []int
}

func NewKMP(a []int) *KMP {
	return &KMP{Pattern: a}
}

func (k *KMP) Build(a []int) {
	k.Pattern = a
	k.table = make([]int, len(a)+1)
	j := -1
	for i := 0; i < len(a); i++ {
		for j >= 0 && a[i] != a[j] {
			j = k.table[j]
		}
		k.table[i+1] = j + 1
		j++
	}
}

func (k *KMP) Search(a []int) []int {
	ans := []int{}
	for i, k := 0, 0; i < len(a); i++ {
		for k >= 0 && a[i] != k.Pattern[k] {
			k = k.table[k]
		}
		k++
		if k >= len(k.Pattern) {
			ans = append(ans, i-len(k.Pattern)+1)
			k = k.table[k]
		}
	}
	return ans
}

var eps = 1e-9

func init() {
	// Set up any necessary initialization here
}

func solve() {
	var n, w int
	fmt.Scan(&n, &w)
	FI := []struct {
		Left  Fraction
		Right Fraction
	}{}
	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		Left := Fraction{a: -a, b: b - w}
		Right := Fraction{a: -a, b: b + w}
		{
			hoge := gcd(int(math.Abs(float64(Left.a))), int(math.Abs(float64(Left.b))))
			Left.a /= int64(hoge)
			Left.b /= int64(hoge)
		}
		{
			hoge := gcd(int(math.Abs(float64(Right.a))), int(math.Abs(float64(Right.b))))
			Right.a /= int64(hoge)
			Right.b /= int64(hoge)
		}
		if Left.b < 0 {
			Left.a *= -1
			Left.b *= -1
		}
		if Right.b < 0 {
			Right.a *= -1
			Right.b *= -1
		}
		Right.a *= -1
		FI = append(FI, struct {
			Left  Fraction
			Right Fraction
		}{Left: Left, Right: Right})
	}
	sort.Slice(FI, func(i, j int) bool {
		return FI[i].Left < FI[j].Left
	})
	ans := 0
	zip := NewCompressor()
	for i := range FI {
		FI[i].Right.a *= -1
		zip.add(FI[i].Right)
	}
	seg := NewSegmentTree(2*n, func(a, b int) int { return a + b }, 0)
	zip.exec()
	for i := range FI {
		hoge := zip.fetch()
		ans += seg.Query(hoge, 2*n)
		tmp := seg.Get(hoge)
		seg.Update(hoge, tmp+1)
	}
	fmt.Println(ans)
}

func main() {
	init()
	solve()
}
