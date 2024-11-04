package main

import (
	"container/heap"
	"fmt"
	"math/cmplx"
	"math"
	"os"
	"sort"
)

type Point complex128
type Line struct {
	first, second Point
}

type Circle struct {
	center Point
	r      float64
}

const eps = 1e-9

func dot(a, b Point) float64 {
	return real(a)*real(b) + imag(a)*imag(b)
}

func cross(a, b Point) float64 {
	return real(a)*imag(b) - imag(a)*real(b)
}

func id3(a Line, b Point) float64 {
	if dot(a.second-a.first, b-a.first) < eps {
		return cmplx.Abs(b - a.first)
	}
	if dot(a.first-a.second, b-a.second) < eps {
		return cmplx.Abs(b - a.second)
	}
	return cmplx.Abs(cross(a.second-a.first, b-a.first)) / cmplx.Abs(a.second-a.first)
}

func id0(a, b Line) bool {
	return (cross(a.second-a.first, b.first-a.first)*cross(a.second-a.first, b.second-a.first) < eps) &&
		(cross(b.second-b.first, a.first-b.first)*cross(b.second-b.first, a.second-b.first) < eps)
}

func intersectionL(a, b Line) Point {
	da := a.second - a.first
	db := b.second - b.first
	return a.first + da*cross(db, b.first-a.first)/cross(db, da)
}

func id8(a, b Line) float64 {
	if id0(a, b) {
		return 0
	}
	return math.Min(math.Min(id3(a, b.first), id3(a, b.second)), math.Min(id3(b, a.first), id3(b, a.second)))
}

func id9(a, b Circle) (Point, Point) {
	dist := cmplx.Abs(a.center - b.center)
	if dist > eps+a.r+b.r || dist+eps < math.Abs(a.r-b.r) {
		panic("Invalid circles")
	}
	target := b.center - a.center
	pointer := real(target)*real(target) + imag(target)*imag(target)
	aa := (pointer + a.r*a.r - b.r*b.r) / 2.0
	l := Point((aa*real(target)+imag(target)*math.Sqrt(pointer*a.r*a.r-aa*aa))/pointer,
		(aa*imag(target)-real(target)*math.Sqrt(pointer*a.r*a.r-aa*aa))/pointer)
	r := Point((aa*real(target)-imag(target)*math.Sqrt(pointer*a.r*a.r-aa*aa))/pointer,
		(aa*imag(target)+real(target)*math.Sqrt(pointer*a.r*a.r-aa*aa))/pointer)
	r += a.center
	l += a.center
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
	zipper   map[interface{}]int64
	unzipper map[int64]interface{}
	fetcher  []interface{}
}

func NewCompressor() *Compressor {
	return &Compressor{
		id6:      false,
		zipper:   make(map[interface{}]int64),
		unzipper: make(map[int64]interface{}),
		fetcher:  []interface{}{},
	}
}

func (c *Compressor) Add(now interface{}) {
	if c.id6 {
		panic("Cannot add after exec")
	}
	c.zipper[now] = 1
	c.fetcher = append(c.fetcher, now)
}

func (c *Compressor) Exec() {
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

func (c *Compressor) Fetch() int64 {
	if !c.id6 {
		panic("Must exec before fetch")
	}
	hoge := c.fetcher[0]
	c.fetcher = c.fetcher[1:]
	return c.zipper[hoge]
}

func (c *Compressor) Zip(now interface{}) int64 {
	if !c.id6 {
		panic("Must exec before zip")
	}
	if _, exists := c.zipper[now]; !exists {
		panic("Value not found")
	}
	return c.zipper[now]
}

func (c *Compressor) Unzip(a int64) interface{} {
	if !c.id6 {
		panic("Must exec before unzip")
	}
	if a >= int64(len(c.unzipper)) {
		panic("Index out of range")
	}
	return c.unzipper[a]
}

func (c *Compressor) Next(now interface{}) int64 {
	x := c.zipper[now]
	for i := x + 1; i < int64(len(c.zipper)); i++ {
		if _, exists := c.unzipper[i]; exists {
			return i
		}
	}
	return int64(len(c.zipper))
}

func (c *Compressor) Back(now interface{}) int64 {
	x := c.zipper[now]
	if x == 0 {
		return -1
	}
	for i := x - 1; i >= 0; i-- {
		if _, exists := c.unzipper[i]; exists {
			return i
		}
	}
	return -1
}

type Matrix struct {
	data [][]float64
}

func NewMatrix(a [][]float64) *Matrix {
	return &Matrix{data: a}
}

func (m *Matrix) Add(obj *Matrix) *Matrix {
	if len(obj.data) != len(m.data) || len(obj.data[0]) != len(m.data[0]) {
		panic("Matrix dimensions do not match")
	}
	ans := make([][]float64, len(obj.data))
	for i := range obj.data {
		ans[i] = make([]float64, len(obj.data[i]))
		for q := range obj.data[i] {
			ans[i][q] = obj.data[i][q] + m.data[i][q]
		}
	}
	return NewMatrix(ans)
}

func (m *Matrix) Subtract(obj *Matrix) *Matrix {
	if len(obj.data) != len(m.data) || len(obj.data[0]) != len(m.data[0]) {
		panic("Matrix dimensions do not match")
	}
	ans := make([][]float64, len(obj.data))
	for i := range obj.data {
		ans[i] = make([]float64, len(obj.data[i]))
		for q := range obj.data[i] {
			ans[i][q] = m.data[i][q] - obj.data[i][q]
		}
	}
	return NewMatrix(ans)
}

func (m *Matrix) Multiply(obj *Matrix) *Matrix {
	if len(obj.data) != len(m.data[0]) {
		panic("Matrix dimensions do not match")
	}
	ans := make([][]float64, len(m.data))
	for i := range m.data {
		ans[i] = make([]float64, len(obj.data[0]))
		for q := range obj.data[0] {
			hoge := m.data[i][0] * obj.data[0][q]
			for t := 1; t < len(obj.data[i]); t++ {
				hoge += m.data[i][t] * obj.data[t][q]
			}
			ans[i][q] = hoge
		}
	}
	return NewMatrix(ans)
}

type Fraction struct {
	a, b int64
}

func NewFraction(c, d int64) Fraction {
	hoge := gcd(abs(c), abs(d))
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

type ModInt struct {
	value uint64
	mod   uint64
}

func NewModInt(a, mod uint64) ModInt {
	return ModInt{value: (a % mod + 2*mod) % mod, mod: mod}
}

func (m ModInt) Add(rhs ModInt) ModInt {
	return NewModInt(m.value+rhs.value, m.mod)
}

func (m ModInt) Subtract(rhs ModInt) ModInt {
	if m.value < rhs.value {
		m.value += m.mod
	}
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
	for q := 0; q < 6; q++ {
		if d.vertexs[q] < a.vertexs[q] {
			return true
		}
		if d.vertexs[q] > a.vertexs[q] {
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
	vertexs      [][]struct{ to int; cost float64 }
	CostFunction func(float64) float64
}

func NewDijkstra(n int, cost func(float64) float64) *Dijkstra {
	vertexs := make([][]struct{ to int; cost float64 }, n)
	return &Dijkstra{vertexs: vertexs, CostFunction: cost}
}

func (d *Dijkstra) AddEdge(a, b int, c float64) {
	d.vertexs[a] = append(d.vertexs[a], struct{ to int; cost float64 }{to: b, cost: c})
}

func (d *Dijkstra) BuildResult(startPoint int) []float64 {
	dist := make([]float64, len(d.vertexs))
	for i := range dist {
		dist[i] = 2e18
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

type Dinic struct {
	Graph [][]edge
	level []int
	itr   []int
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
			d.itr[now]++
			dVal := d.Dfs(target.to, goal, min(val, target.cap))
			if dVal > 0 {
				target.cap -= dVal
				d.Graph[target.to][target.rev].cap += dVal
				return dVal
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

type SegmentTree struct {
	sz  int
	seg []float64
	f   func(float64, float64) float64
	M1  float64
}

func NewSegmentTree(n int, f func(float64, float64) float64, M1 float64) *SegmentTree {
	sz := 1
	for sz < n {
		sz <<= 1
	}
	seg := make([]float64, 2*sz)
	for i := range seg {
		seg[i] = M1
	}
	return &SegmentTree{sz: sz, seg: seg, f: f, M1: M1}
}

func (st *SegmentTree) Set(k int, x float64) {
	st.seg[k+st.sz] = x
}

func (st *SegmentTree) Build() {
	for k := st.sz - 1; k > 0; k-- {
		st.seg[k] = st.f(st.seg[2*k+0], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Update(k int, x float64) {
	k += st.sz
	st.seg[k] = x
	for k >>= 1; k > 0; k >>= 1 {
		st.seg[k] = st.f(st.seg[2*k+0], st.seg[2*k+1])
	}
}

func (st *SegmentTree) Query(a, b int) float64 {
	L, R := st.M1, st.M1
	for a += st.sz; b += st.sz; a < b; a >>= 1 {
		if a&1 != 0 {
			L = st.f(L, st.seg[a])
			a++
		}
		if b&1 != 0 {
			b--
			R = st.f(st.seg[b], R)
		}
	}
	return st.f(L, R)
}

type KMP struct {
	table   []int
	Pattern []int
}

func NewKMP(a []int) *KMP {
	kmp := &KMP{}
	kmp.Build(a)
	return kmp
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

func xor128() uint64 {
	staticX := uint64(123456789)
	staticY := uint64(362436069)
	staticZ := uint64(521288629)
	staticW := uint64(88675123)
	t := staticX ^ (staticX << 11)
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
	var t string
	fmt.Scan(&t)
	cnter := []int{}
	for i := 0; i < len(t); i++ {
		if t[i] == '0' {
			cnter = append(cnter, i*2+i%2)
		}
	}
	nexts := struct {
		first, second ModInt
	}{first: NewModInt(1, 1e9 + 7), second: NewModInt(1, 1e9 + 7)}
	hoge := make([]struct {
		first, second ModInt
	}, len(cnter)+1)
	rev := make([]struct {
		first, second ModInt
	}, len(cnter)+1)
	for i := 0; i < len(cnter); i++ {
		hoge[i+1] = hoge[i]
		hoge[i+1].first = hoge[i+1].first.Add(nexts.first.Multiply(ModInt{value: int64(cnter[i] % 2), mod: 1e9 + 7}))
		hoge[i+1].second = hoge[i+1].second.Add(nexts.second.Multiply(ModInt{value: int64(cnter[i] % 2), mod: 1e9 + 7}))
		rev[i+1] = rev[i]
		rev[i+1].first = rev[i+1].first.Add(nexts.first.Multiply(ModInt{value: int64((cnter[i] + 1) % 2), mod: 1e9 + 7}))
		rev[i+1].second = rev[i+1].second.Add(nexts.second.Multiply(ModInt{value: int64((cnter[i] + 1) % 2), mod: 1e9 + 7}))
		nexts.first = nexts.first.Multiply(NewModInt(2, 1e9 + 7))
		nexts.second = nexts.second.Multiply(NewModInt(2, 1e9 + 7))
	}
	var query int
	fmt.Scan(&query)
	for i := 0; i < query; i++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		a--
		b--
		Left := [2]int{sort.SearchInts(cnter, a*2), sort.SearchInts(cnter, (a+c)*2)}
		Right := [2]int{sort.SearchInts(cnter, b*2), sort.SearchInts(cnter, (b+c)*2)}
		if Left[1]-Left[0] != Right[1]-Right[0] {
			fmt.Println("No")
			continue
		}
		ok := 1
		var aa, bb struct {
			first, second ModInt
		}
		aa = hoge[Left[1]]
		aa.first = aa.first.Subtract(hoge[Left[0]].first)
		aa.second = aa.second.Subtract(hoge[Left[0]].second)
		if a%2 == b%2 {
			bb = hoge[Right[1]]
			bb.first = bb.first.Subtract(hoge[Right[0]].first)
			bb.second = bb.second.Subtract(hoge[Right[0]].second)
		} else {
			bb = rev[Right[1]]
			bb.first = bb.first.Subtract(rev[Right[0]].first)
			bb.second = bb.second.Subtract(rev[Right[0]].second)
		}
		if Left[0] != 0 {
			aa.first = aa.first.Divide(pows(2, int64(Left[0])))
			aa.second = aa.second.Divide(pows(2, int64(Left[0])))
		}
		if Right[0] != 0 {
			bb.first = bb.first.Divide(pows(2, int64(Right[0])))
			bb.second = bb.second.Divide(pows(2, int64(Right[0])))
		}
		if aa.first.value != bb.first.value || aa.second.value != bb.second.value {
			ok = 0
		}
		if ok == 1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func main() {
	init()
	solve()
}
