package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (fs *FastScanner) NextInt() int {
	fs.scanner.Scan()
	var x int
	fmt.Sscanf(fs.scanner.Text(), "%d", &x)
	return x
}

func (fs *FastScanner) NextLong() int64 {
	fs.scanner.Scan()
	var x int64
	fmt.Sscanf(fs.scanner.Text(), "%d", &x)
	return x
}

type DSU struct {
	sz []int
	p  []int
}

func NewDSU(n int) *DSU {
	sz := make([]int, n)
	p := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		sz[i] = 1
	}
	return &DSU{sz: sz, p: p}
}

func (dsu *DSU) Get(x int) int {
	if x == dsu.p[x] {
		return x
	}
	par := dsu.Get(dsu.p[x])
	dsu.p[x] = par
	return par
}

func (dsu *DSU) Unite(a, b int) bool {
	pa := dsu.Get(a)
	pb := dsu.Get(b)
	if pa == pb {
		return false
	}
	if dsu.sz[pa] < dsu.sz[pb] {
		dsu.p[pa] = pb
		dsu.sz[pb] += dsu.sz[pa]
	} else {
		dsu.p[pb] = pa
		dsu.sz[pa] += dsu.sz[pb]
	}
	return true
}

type SegmentTreeAdd struct {
	pow     int
	max     []int64
	delta   []int64
	flag    []bool
}

func NewSegmentTreeAdd(a []int64) *SegmentTreeAdd {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	flag := make([]bool, 2*pow)
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	for i := range max {
		max[i] = math.MinInt64 / 2
	}
	for i := 0; i < len(a); i++ {
		max[pow+i] = a[i]
	}
	for i := pow - 1; i > 0; i-- {
		max[i] = max[2*i]
		if max[2*i+1] > max[i] {
			max[i] = max[2*i+1]
		}
	}
	return &SegmentTreeAdd{pow: pow, max: max, delta: delta, flag: flag}
}

func (st *SegmentTreeAdd) Push(v, tl, tr int) {
	if st.flag[v] {
		if v < st.pow {
			st.flag[2*v] = true
			st.flag[2*v+1] = true
			st.delta[2*v] += st.delta[v]
			st.delta[2*v+1] += st.delta[v]
		}
		st.flag[v] = false
		st.max[v] += st.delta[v]
		st.delta[v] = 0
	}
}

func (st *SegmentTreeAdd) Get(v, tl, tr, l, r int) int64 {
	st.Push(v, tl, tr)
	if l > r {
		return math.MinInt64 / 2
	}
	if l == tl && r == tr {
		return st.max[v]
	}
	tm := (tl + tr) / 2
	return max(st.Get(2*v, tl, tm, l, min(r, tm)), st.Get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (st *SegmentTreeAdd) Set(v, tl, tr, l, r int, x int64) {
	st.Push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		st.delta[v] += x
		st.flag[v] = true
		st.Push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	st.Set(2*v, tl, tm, l, r, x)
	st.Set(2*v+1, tm+1, tr, l, r, x)
	st.max[v] = max(st.max[2*v], st.max[2*v+1])
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type SegmentTreeSet struct {
	pow     int
	sum     []int
	delta   []int
	flag    []bool
}

func NewSegmentTreeSet(a []int) *SegmentTreeSet {
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
	return &SegmentTreeSet{pow: pow, sum: sum, delta: delta, flag: flag}
}

func (st *SegmentTreeSet) Push(v, tl, tr int) {
	if st.flag[v] {
		if v < st.pow {
			st.flag[2*v] = true
			st.flag[2*v+1] = true
			st.delta[2*v] = st.delta[v]
			st.delta[2*v+1] = st.delta[v]
		}
		st.flag[v] = false
		st.sum[v] = st.delta[v] * (tr - tl + 1)
	}
}

func (st *SegmentTreeSet) Get(v, tl, tr, l, r int) int {
	st.Push(v, tl, tr)
	if l > r {
		return 0
	}
	if l == tl && r == tr {
		return st.sum[v]
	}
	tm := (tl + tr) / 2
	return st.f(st.Get(2*v, tl, tm, l, min(r, tm)), st.Get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (st *SegmentTreeSet) Set(v, tl, tr, l, r, x int) {
	st.Push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		st.delta[v] = x
		st.flag[v] = true
		st.Push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	st.Set(2*v, tl, tm, l, r, x)
	st.Set(2*v+1, tm+1, tr, l, r, x)
	st.sum[v] = st.f(st.sum[2*v], st.sum[2*v+1])
}

func (st *SegmentTreeSet) f(a, b int) int {
	return a + b
}

type Pair struct {
	x int
	y int
}

func NewPair(x, y int) *Pair {
	return &Pair{x: x, y: y}
}

func (p *Pair) CompareTo(o *Pair) int {
	if p.y > o.y {
		return 1
	}
	if p.y < o.y {
		return -1
	}
	if p.x > o.x {
		return 1
	}
	if p.x < o.x {
		return -1
	}
	return 0
}

var mod int64 = 1000000007

func Shuffle(a []*Pair) {
	for i := range a {
		x := rand.Intn(i + 1)
		a[x], a[i] = a[i], a[x]
	}
}

func Add(m map[int64]int, l int64) {
	if _, ok := m[l]; ok {
		m[l]++
	} else {
		m[l] = 1
	}
}

func Remove(m map[int]int, s int) {
	if m[s] > 1 {
		m[s]--
	} else {
		delete(m, s)
	}
}

func Signum(x float64) int {
	eps := 1e-10
	if x > eps {
		return 1
	}
	if x < -eps {
		return -1
	}
	return 0
}

func Abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func Min(x, y int64) int64 {
	if x < y {
		return x
	}
	return y
}

func Max(x, y int64) int64 {
	if x > y {
		return x
	}
	return y
}

func GCD(x, y int64) int64 {
	for y > 0 {
		c := y
		y = x % y
		x = c
	}
	return x
}

type Rect struct {
	x1     int64
	x2     int64
	y1     int64
	y2     int64
	number int
}

type Fenvik struct {
	t []int
}

func NewFenvik(n int) *Fenvik {
	t := make([]int, n)
	return &Fenvik{t: t}
}

func (f *Fenvik) Add(x, delta int) {
	for i := x; i < len(f.t); i = (i | (i + 1)) {
		f.t[i] += delta
	}
}

func (f *Fenvik) Sum(r int) int {
	ans := 0
	x := r
	for x >= 0 {
		ans += f.t[x]
		x = (x & (x + 1)) - 1
	}
	return ans
}

func (f *Fenvik) SumRange(l, r int) int {
	return f.Sum(r) - f.Sum(l - 1)
}

type SegmentTreeMaxSum struct {
	pow        int
	sum        []int
	maxPrefSum []int
	maxSufSum  []int
	maxSum     []int
}

func NewSegmentTreeMaxSum(a []int) *SegmentTreeMaxSum {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	sum := make([]int, 2*pow)
	maxPrefSum := make([]int, 2*pow)
	maxSum := make([]int, 2*pow)
	maxSufSum := make([]int, 2*pow)
	for i := 0; i < len(a); i++ {
		sum[pow+i] = a[i]
		maxSum[pow+i] = max(a[i], 0)
		maxPrefSum[pow+i] = maxSum[pow+i]
		maxSufSum[pow+i] = maxSum[pow+i]
	}
	for i := pow - 1; i > 0; i-- {
		Update(maxSum, sum, maxPrefSum, maxSufSum, i)
	}
	return &SegmentTreeMaxSum{pow: pow, sum: sum, maxPrefSum: maxPrefSum, maxSufSum: maxSufSum, maxSum: maxSum}
}

func Update(maxSum, sum, maxPrefSum, maxSufSum []int, i int) {
	sum[i] = sum[2*i] + sum[2*i+1]
	maxSum[i] = max(maxSum[2*i], max(maxSum[2*i+1], maxSufSum[2*i]+maxPrefSum[2*i+1]))
	maxPrefSum[i] = max(maxPrefSum[2*i], maxPrefSum[2*i+1]+sum[2*i])
	maxSufSum[i] = max(maxSufSum[2*i+1], maxSufSum[2*i]+sum[2*i+1])
}

func (st *SegmentTreeMaxSum) Get(v, tl, tr, l, r int) []int {
	if r <= tl || l >= tr {
		return []int{0, 0, 0, 0}
	}
	if l <= tl && r >= tr {
		return []int{st.maxPrefSum[v], st.maxSum[v], st.maxSufSum[v], st.sum[v]}
	}
	tm := (tl + tr) / 2
	left := st.Get(2*v, tl, tm, l, r)
	right := st.Get(2*v+1, tm, tr, l, r)
	return []int{
		max(left[0], right[0]+left[3]),
		max(left[1], max(right[1], left[2]+right[0])),
		max(right[2], left[2]+right[3]),
		left[3] + right[3],
	}
}

func (st *SegmentTreeMaxSum) Set(v, tl, tr, x, value int) {
	if v >= st.pow {
		st.sum[v] = value
		st.maxSum[v] = max(value, 0)
		st.maxPrefSum[v] = st.maxSum[v]
		st.maxSufSum[v] = st.maxSum[v]
		return
	}
	tm := (tl + tr) / 2
	if x < tm {
		st.Set(2*v, tl, tm, x, value)
	} else {
		st.Set(2*v+1, tm, tr, x, value)
	}
	Update(st.maxSum, st.sum, st.maxPrefSum, st.maxSufSum, v)
}

type Point struct {
	x float64
	y float64
}

func NewPoint(x, y float64) *Point {
	return &Point{x: x, y: y}
}

func (p *Point) Dist2() float64 {
	return p.x*p.x + p.y*p.y
}

func (p *Point) Add(v *Point) *Point {
	return NewPoint(p.x+v.x, p.y+v.y)
}

func (p *Point) CompareTo(o *Point) int {
	z := Signum(p.x + p.y - o.x - o.y)
	if z != 0 {
		return z
	}
	if Signum(p.x-o.x) != 0 {
		return Signum(p.x - o.x)
	}
	return Signum(p.y - o.y)
}

type Circle struct {
	p *Point
	r int
}

func NewCircle(p *Point, r int) *Circle {
	return &Circle{p: p, r: r}
}

func (c *Circle) Inside(p *Point) bool {
	return Hypot2(p.x-c.p.x, p.y-c.p.y) <= Sq(float64(c.r))
}

func (c *Circle) Angle() *Point {
	z := float64(c.r) / sq2
	z -= math.Mod(z, 1e-5)
	return NewPoint(c.p.x-z, c.p.y-z)
}

func (c *Circle) CompareTo(o *Circle) int {
	a := c.Angle()
	oa := o.Angle()
	z := Signum(a.x + a.y - oa.x - oa.y)
	if z != 0 {
		return z
	}
	return Signum(a.y - oa.y)
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
		gcd := GCD(x, y)
		x /= gcd
		y /= gcd
	}
	return &Fraction{x: x, y: y}
}

func (f *Fraction) CompareTo(o *Fraction) int64 {
	res := f.x*o.y - f.y*o.x
	if res > 0 {
		return 1
	}
	if res < 0 {
		return -1
	}
	return 0
}

func (f *Fraction) String() string {
	return fmt.Sprintf("%d/%d", f.x, f.y)
}

func (f *Fraction) Clone() *Fraction {
	return NewFraction(f.x, f.y, false)
}

type Event struct {
	f    *Fraction
	typ  int
}

func NewEvent(f *Fraction, typ int) *Event {
	return &Event{f: f, typ: typ}
}

func (e *Event) CompareTo(o *Event) int {
	c := e.f.CompareTo(o.f)
	if c != 0 {
		return c
	}
	return e.typ - o.typ
}

func Sq(x float64) float64 {
	return x * x
}

func Hypot2(x, y float64) float64 {
	return Sq(x) + Sq(y)
}

func Kuhn(v int, edge [][]int, used []bool, mt []int) bool {
	used[v] = true
	for _, u := range edge[v] {
		if mt[u] < 0 || (!used[mt[u]] && Kuhn(mt[u], edge, used, mt)) {
			mt[u] = v
			return true
		}
	}
	return false
}

func Matching(edge [][]int) int {
	n := len(edge)
	mt := make([]int, n)
	for i := range mt {
		mt[i] = -1
	}
	used := make([]bool, n)
	ans := 0
	for i := 0; i < n; i++ {
		if !used[i] && Kuhn(i, edge, used, mt) {
			for j := range used {
				used[j] = false
			}
			ans++
		}
	}
	return ans
}

var sq2 = math.Sqrt(2)

type Stack struct {
	st []int
	sz int
}

func NewStack(n int) *Stack {
	return &Stack{st: make([]int, n), sz: 0}
}

func (s *Stack) IsEmpty() bool {
	return s.sz == 0
}

func (s *Stack) Peek() int {
	return s.st[s.sz-1]
}

func (s *Stack) Pop() int {
	s.sz--
	return s.st[s.sz]
}

func (s *Stack) Clear() {
	s.sz = 0
}

func (s *Stack) Add(x int) {
	s.st[s.sz] = x
	s.sz++
}

func (s *Stack) Get(x int) int {
	return s.st[x]
}

func ReadGraph(n, m int) [][]int {
	to := make([][]int, n)
	sz := make([]int, n)
	x := make([]int, m)
	y := make([]int, m)
	for i := 0; i < m; i++ {
		x[i] = in.NextInt() - 1
		y[i] = in.NextInt() - 1
		sz[x[i]]++
		sz[y[i]]++
	}
	for i := range to {
		to[i] = make([]int, sz[i])
		sz[i] = 0
	}
	for i := 0; i < m; i++ {
		to[x[i]][sz[x[i]]] = y[i]
		to[y[i]][sz[y[i]]] = x[i]
		sz[x[i]]++
		sz[y[i]]++
	}
	return to
}

type Pol struct {
	coeff []float64
}

func NewPol(coeff []float64) *Pol {
	return &Pol{coeff: coeff}
}

func (p *Pol) Mult(q *Pol) *Pol {
	ans := make([]float64, len(p.coeff)+len(q.coeff)-1)
	for i := range ans {
		for j := max(0, i-len(q.coeff)+1); j < len(p.coeff) && j <= i; j++ {
			ans[i] += p.coeff[j] * q.coeff[i-j]
		}
	}
	return NewPol(ans)
}

func (p *Pol) Value(x float64) float64 {
	ans := 0.0
	pow := 1.0
	for i := range p.coeff {
		ans += p.coeff[i] * pow
		pow *= x
	}
	return ans
}

func (p *Pol) Integrate(r float64) float64 {
	newCoeff := make([]float64, len(p.coeff)+1)
	for i := range p.coeff {
		newCoeff[i+1] = p.coeff[i] / float64(i+1)
	}
	return NewPol(newCoeff).Value(r)
}

func (p *Pol) IntegrateRange(l, r float64) float64 {
	return p.Integrate(r) - p.Integrate(l)
}

type DSU1 struct {
	p    []int
	sz   []int
	less *Stack
	more *Stack
	q    [][]int
	used []bool
}

func NewDSU1(v []int, m int) *DSU1 {
	n := len(v)
	p := make([]int, n)
	sz := make([]int, n)
	q := make([][]int, n)
	less := NewStack(m)
	more := NewStack(m)
	used := make([]bool, n+1)
	for i := 0; i < n; i++ {
		p[i] = i
		sz[i] = 1
		q[i] = make([]int, 0)
		q[i] = append(q[i], -v[i])
	}
	return &DSU1{p: p, sz: sz, q: q, less: less, more: more, used: used}
}

func (dsu *DSU1) Get(x int) int {
	for x != dsu.p[x] {
		x = dsu.p[x]
	}
	return x
}

func (dsu *DSU1) Unite(a, b int) bool {
	pa := dsu.Get(a)
	pb := dsu.Get(b)
	if pa == pb {
		dsu.less.Add(-1)
		dsu.more.Add(-1)
		return false
	}
	if dsu.sz[pa] < dsu.sz[pb] {
		dsu.p[pa] = pb
		dsu.sz[pb] += dsu.sz[pa]
		dsu.less.Add(pa)
		dsu.more.Add(pb)
		for _, i := range dsu.q[pa] {
			dsu.q[pb] = append(dsu.q[pb], i)
		}
	} else {
		dsu.p[pb] = pa
		dsu.sz[pa] += dsu.sz[pb]
		dsu.less.Add(pb)
		dsu.more.Add(pa)
		for _, i := range dsu.q[pb] {
			dsu.q[pa] = append(dsu.q[pa], i)
		}
	}
	return true
}

func (dsu *DSU1) PopEdge() {
	pa := dsu.less.Pop()
	pb := dsu.more.Pop()
	if pa < 0 {
		return
	}
	dsu.p[pa] = pa
	dsu.sz[pb] -= dsu.sz[pa]
}

func (dsu *DSU1) Poll(x int) int {
	px := dsu.Get(x)
	for len(dsu.q[px]) > 0 {
		v := -dsu.q[px][0]
		dsu.q[px] = dsu.q[px][1:]
		if !dsu.used[v] && dsu.Get(inv[v-1]) == px {
			dsu.used[v] = true
			return v
		}
	}
	return 0
}

var inv []int

func Solve() {
	n := in.NextInt()
	m := in.NextInt()
	q := in.NextInt()
	v := make([]int, n)
	inv = make([]int, n)
	for i := range v {
		v[i] = in.NextInt()
		inv[v[i]-1] = i
	}
	a := make([]int, m)
	b := make([]int, m)
	for i := range b {
		a[i] = in.NextInt() - 1
		b[i] = in.NextInt() - 1
	}
	typeQuery := make([]bool, q)
	x := make([]int, q)
	removed := make([]bool, m)
	for i := 0; i < q; i++ {
		if in.NextInt() == 1 {
			x[i] = in.NextInt() - 1
			typeQuery[i] = true
		} else {
			x[i] = in.NextInt() - 1
			removed[x[i]] = true
		}
	}
	dsu := NewDSU1(v, m)
	for i := range removed {
		if !removed[i] {
			dsu.Unite(a[i], b[i])
		}
	}
	for i := q - 1; i >= 0; i-- {
		if !typeQuery[i] {
			dsu.Unite(a[x[i]], b[x[i]])
		}
	}
	for i := 0; i < q; i++ {
		if typeQuery[i] {
			fmt.Println(dsu.Poll(x[i]))
		} else {
			dsu.PopEdge()
		}
	}
}

func main() {
	in = NewFastScanner()
	Solve()
}
