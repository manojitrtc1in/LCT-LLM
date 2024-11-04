package main

import (
	"container/heap"
	"fmt"
	"math"
	"sort"
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

func id3(a Line, b Point) float64 {
	if dot(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y}) < 1e-9 {
		return math.Sqrt((b.x-a.first.x)*(b.x-a.first.x) + (b.y-a.first.y)*(b.y-a.first.y))
	}
	if dot(Point{a.first.x - a.second.x, a.first.y - a.second.y}, Point{b.x - a.second.x, b.y - a.second.y}) < 1e-9 {
		return math.Sqrt((b.x-a.second.x)*(b.x-a.second.x) + (b.y-a.second.y)*(b.y-a.second.y))
	}
	return math.Abs(cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.x - a.first.x, b.y - a.first.y})) / math.Sqrt(dot(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{a.second.x - a.first.x, a.second.y - a.first.y}))
}

func id0(a, b Line) bool {
	return (cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.first.x - a.first.x, b.first.y - a.first.y})*cross(Point{a.second.x - a.first.x, a.second.y - a.first.y}, Point{b.second.x - a.first.x, b.second.y - a.first.y}) < 1e-9) &&
		(cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.first.x - b.first.x, a.first.y - b.first.y})*cross(Point{b.second.x - b.first.x, b.second.y - b.first.y}, Point{a.second.x - b.first.x, a.second.y - b.first.y}) < 1e-9)
}

func intersectionL(a, b Line) Point {
	da := Point{a.second.x - a.first.x, a.second.y - a.first.y}
	db := Point{b.second.x - b.first.x, b.second.y - b.first.y}
	return Point{
		x: a.first.x + da.x*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
		y: a.first.y + da.y*cross(db, Point{b.first.x - a.first.x, b.first.y - a.first.y})/cross(db, da),
	}
}

func id8(a, b Line) float64 {
	if id0(a, b) {
		return 0
	}
	return math.Min(math.Min(id3(a, b.first), id3(a, b.second)), math.Min(id3(b, a.first), id3(b, a.second)))
}

func id9(a, b Circle) (Point, Point) {
	dist := math.Sqrt((a.center.x-b.center.x)*(a.center.x-b.center.x) + (a.center.y-b.center.y)*(a.center.y-b.center.y))
	if dist <= 1e-9+a.r+b.r && dist+1e-9 >= math.Abs(a.r-b.r) {
		target := Point{x: b.center.x - a.center.x, y: b.center.y - a.center.y}
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
	return Point{}, Point{}
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func pows(val int64, b int64) int64 {
	if b < 1 {
		return 1
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
	zipper   map[int64]int64
	unzipper map[int64]int64
	fetcher  []int64
}

func NewCompressor() *Compressor {
	return &Compressor{
		id6:      false,
		zipper:   make(map[int64]int64),
		unzipper: make(map[int64]int64),
		fetcher:  []int64{},
	}
}

func (c *Compressor) Add(now int64) {
	if c.id6 {
		return
	}
	c.zipper[now] = 1
	c.fetcher = append(c.fetcher, now)
}

func (c *Compressor) Exec() {
	if c.id6 {
		return
	}
	cnt := int64(0)
	for k := range c.zipper {
		c.zipper[k] = cnt
		c.unzipper[cnt] = k
		cnt++
	}
	c.id6 = true
}

func (c *Compressor) Fetch() int64 {
	if !c.id6 {
		return -1
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) Zip(now int64) int64 {
	if !c.id6 {
		return -1
	}
	return c.zipper[now]
}

func (c *Compressor) Unzip(a int64) int64 {
	if !c.id6 {
		return -1
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
	value int64
	mod   int64
}

func NewModInt(a, mod int64) ModInt {
	return ModInt{value: a % mod, mod: mod}
}

func (m ModInt) Add(rhs ModInt) ModInt {
	return NewModInt(m.value+rhs.value, m.mod)
}

func (m ModInt) Subtract(rhs ModInt) ModInt {
	return NewModInt(m.value-rhs.value, m.mod)
}

func (m ModInt) Multiply(rhs ModInt) ModInt {
	return NewModInt(m.value*rhs.value, m.mod)
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

func (d *Dice) ReachAble(now *Dice) bool {
	hoge := make(map[Dice]struct{})
	next := []Dice{*now}
	hoge[*now] = struct{}{}
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

func (d *Dice) Equal(a *Dice) bool {
	for q := 0; q < 6; q++ {
		if a.vertexs[q] != d.vertexs[q] {
			return false
		}
	}
	return true
}

func (d *Dice) Less(a *Dice) bool {
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

func id1(center, up int) (Dice, Dice) {
	target := 1
	for {
		if center != target && 7-center != target && up != target && 7-up != target {
			break
		}
		target++
	}
	return NewDice([]int64{int64(up), int64(target), int64(center), int64(7 - target), int64(7 - center), int64(7 - up)}),
		NewDice([]int64{int64(up), int64(7 - target), int64(center), int64(target), int64(7 - center), int64(7 - up)})
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
	return NewDice([]int64{int64(goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(7 - goa[0])}),
		NewDice([]int64{int64(goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(7 - goa[0])}),
		NewDice([]int64{int64(7 - goa[0]), int64(goa[1]), int64(center), int64(7 - goa[1]), int64(7 - center), int64(goa[0])}),
		NewDice([]int64{int64(7 - goa[0]), int64(7 - goa[1]), int64(center), int64(goa[1]), int64(7 - center), int64(goa[0])})
}

type Dijkstra struct {
	vertexs      [][]Pair
	CostFunction func(Pair) int64
}

type Pair struct {
	first, second int
}

func NewDijkstra(n int, cost func(Pair) int64) *Dijkstra {
	return &Dijkstra{
		vertexs:      make([][]Pair, n),
		CostFunction: cost,
	}
}

func (d *Dijkstra) AddEdge(a, b int, c Pair) {
	d.vertexs[a] = append(d.vertexs[a], Pair{b, c})
}

func (d *Dijkstra) BuildResult(StartPoint int) []int64 {
	dist := make([]int64, len(d.vertexs))
	for i := range dist {
		dist[i] = math.MaxInt64
	}
	dist[StartPoint] = 0
	next := &PriorityQueue{}
	heap.Push(next, Pair{0, StartPoint})
	for next.Len() > 0 {
		now := heap.Pop(next).(Pair)
		if dist[now.second] != now.first {
			continue
		}
		for _, x := range d.vertexs[now.second] {
			nowCost := now.first + d.CostFunction(x)
			if dist[x.first] > nowCost {
				dist[x.first] = nowCost
				heap.Push(next, Pair{nowCost, x.first})
			}
		}
	}
	return dist
}

type Dinic struct {
	Graph [][]Edge
	Level []int
	Iter  []int
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
	d.Graph[a] = append(d.Graph[a], Edge{b, cap, len(d.Graph[b])})
	d.Graph[b] = append(d.Graph[b], Edge{a, 0, len(d.Graph[a]) - 1})
}

func (d *Dinic) Bfs(s int) {
	d.Level = make([]int, len(d.Graph))
	for i := range d.Level {
		d.Level[i] = -1
	}
	d.Level[s] = 0
	next := []int{s}
	for len(next) > 0 {
		now := next[0]
		next = next[1:]
		for _, x := range d.Graph[now] {
			if x.cap == 0 {
				continue
			}
			if d.Level[x.to] == -1 {
				d.Level[x.to] = d.Level[now] + 1
				next = append(next, x.to)
			}
		}
	}
}

func (d *Dinic) Dfs(now, goal, val int) int {
	if goal == now {
		return val
	}
	for i := d.Iter[now]; i < len(d.Graph[now]); i++ {
		d.Iter[now] = i
		target := &d.Graph[now][i]
		if target.cap > 0 && d.Level[now] < d.Level[target.to] {
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
		if d.Level[t] < 0 {
			break
		}
		d.Iter = make([]int, len(d.Graph))
		for f = d.Dfs(s, t, math.MaxInt64); f > 0; f = d.Dfs(s, t, math.MaxInt64) {
			ans += f
		}
	}
	return ans
}

type Id7 struct {
	vertexs    [][]int
	depth      []int
	backs      []int
	connections []int
	zip, unzip []int
}

func NewId7(n int) *Id7 {
	return &Id7{
		vertexs:    make([][]int, n),
		depth:      make([]int, n),
		zip:        make([]int, n),
		unzip:      make([]int, n),
	}
}

func (id *Id7) AddEdge(a, b int) {
	id.vertexs[a] = append(id.vertexs[a], b)
	id.vertexs[b] = append(id.vertexs[b], a)
}

func (id *Id7) DepthDfs(now, back int) int {
	id.depth[now] = 0
	for _, x := range id.vertexs[now] {
		if x == back {
			continue
		}
		id.depth[now] = max(id.depth[now], 1+id.DepthDfs(x, now))
	}
	return id.depth[now]
}

func (id *Id7) Dfs(now, backing int) {
	id.zip[now] = len(id.backs)
	id.unzip[len(id.backs)] = now
	id.backs = append(id.backs, backing)
	nowMax := -1
	itr := -1
	for _, x := range id.vertexs[now] {
		if id.depth[x] > id.depth[now] {
			continue
		}
		if nowMax < id.depth[x] {
			nowMax = id.depth[x]
			itr = x
		}
	}
	if itr == -1 {
		return
	}
	id.connections = append(id.connections, id.connections[len(id.connections)-1])
	id.Dfs(itr, backing)
	for _, x := range id.vertexs[now] {
		if id.depth[x] > id.depth[now] {
			continue
		}
		if x == itr {
			continue
		}
		id.connections = append(id.connections, id.zip[now])
		id.Dfs(x, len(id.backs))
	}
}

func (id *Id7) Build() {
	id.DepthDfs(0, -1)
	id.connections = append(id.connections, -1)
	id.Dfs(0, -1)
}

func (id *Id7) Query(a, b int) []Pair {
	a = id.zip[a]
	b = id.zip[b]
	ans := []Pair{}
	for id.backs[a] != id.backs[b] {
		if a < b {
			a, b = b, a
		}
		ans = append(ans, Pair{id.backs[a], a + 1})
		a = id.connections[a]
	}
	if a > b {
		a, b = b, a
	}
	ans = append(ans, Pair{a, b + 1})
	return ans
}

func (id *Id7) Lca(a, b int) int {
	a = id.zip[a]
	b = id.zip[b]
	for id.backs[a] != id.backs[b] {
		if a < b {
			a, b = b, a
		}
		a = id.connections[a]
	}
	return id.unzip[min(a, b)]
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

func (st *SegmentTree) Set(k int, x int64) {
	st.seg[k+st.sz] = x
}

func (st *SegmentTree) Build() {
	for k := st.sz - 1; k > 0; k-- {
		st.seg[k] = st.f(st.seg[2*k+0], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Update(k int, x int64) {
	k += st.sz
	st.seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		st.seg[k] = st.f(st.seg[2*k+0], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Query(a, b int) int64 {
	L, R := st.M1, st.M1
	for a += st.sz; b += st.sz; a < b {
		if a&1 != 0 {
			L = st.f(L, st.seg[a])
			a++
		}
		if b&1 != 0 {
			b--
			R = st.f(st.seg[b], R)
		}
		a >>= 1
		b >>= 1
	}
	return st.f(L, R)
}

func (st *SegmentTree) Get(k int) int64 {
	return st.seg[k+st.sz]
}

type Id5 struct {
	sz, height int
	data       []int64
	lazy       []int64
	f          func(int64, int64) int64
	g          func(int64, int64) int64
	h          func(int64, int64) int64
	M1         int64
	OM0        int64
}

func NewId5(n int, f func(int64, int64) int64, g func(int64, int64) int64, h func(int64, int64) int64, M1 int64, OM0 int64) *Id5 {
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
		lazy[i] = OM0
	}
	return &Id5{sz: sz, height: height, data: data, lazy: lazy, f: f, g: g, h: h, M1: M1, OM0: OM0}
}

func (id *Id5) Set(k int, x int64) {
	id.data[k+id.sz] = x
}

func (id *Id5) Build() {
	for k := id.sz - 1; k > 0; k-- {
		id.data[k] = id.f(id.data[2*k+0], id.data[2*k+1])
	}
}

func (id *Id5) Propagate(k int) {
	if id.lazy[k] != id.OM0 {
		id.lazy[2*k+0] = id.h(id.lazy[2*k+0], id.lazy[k])
		id.lazy[2*k+1] = id.h(id.lazy[2*k+1], id.lazy[k])
		id.data[k] = id.Reflect(k)
		id.lazy[k] = id.OM0
	}
}

func (id *Id5) Reflect(k int) int64 {
	if id.lazy[k] == id.OM0 {
		return id.data[k]
	}
	return id.g(id.data[k], id.lazy[k])
}

func (id *Id5) Recalc(k int) {
	for k >>= 1; k > 0; k >>= 1 {
		id.data[k] = id.f(id.Reflect(2*k+0), id.Reflect(2*k+1))
	}
}

func (id *Id5) Thrust(k int) {
	for i := id.height; i > 0; i-- {
		id.Propagate(k >> i)
	}
}

func (id *Id5) Update(a, b int, x int64) {
	id.Thrust(a + id.sz)
	id.Thrust(b + id.sz - 1)
	for l, r := a+id.sz, b+id.sz; l < r; l >>= 1 {
		if l&1 != 0 {
			id.lazy[l] = id.h(id.lazy[l], x)
			l++
		}
		if r&1 != 0 {
			r--
			id.lazy[r] = id.h(id.lazy[r], x)
		}
	}
	id.Recalc(a)
	id.Recalc(b)
}

func (id *Id5) Query(a, b int) int64 {
	id.Thrust(a + id.sz)
	id.Thrust(b + id.sz - 1)
	L, R := id.M1, id.M1
	for l, r := a+id.sz, b+id.sz; l < r; l >>= 1 {
		if l&1 != 0 {
			L = id.f(L, id.Reflect(l))
			l++
		}
		if r&1 != 0 {
			r--
			R = id.f(id.Reflect(r), R)
		}
	}
	return id.f(L, R)
}

func (id *Id5) Get(k int) int64 {
	return id.Query(k, k+1)
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
		fmt.Print(v + 1, " ")
	}
	fmt.Println()
}

func main() {
	init()
	solve()
}
