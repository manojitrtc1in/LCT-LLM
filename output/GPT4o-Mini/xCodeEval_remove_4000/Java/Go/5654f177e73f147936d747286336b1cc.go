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

type Id2 struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func NewId2(a []int64) *Id2 {
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
	return &Id2{pow: pow, max: max, delta: delta, flag: flag}
}

func (id *Id2) Get(v, tl, tr, l, r int) int64 {
	id.Push(v, tl, tr)
	if l > r {
		return math.MinInt64 / 2
	}
	if l == tl && r == tr {
		return id.max[v]
	}
	tm := (tl + tr) / 2
	return max(id.Get(2*v, tl, tm, l, min(r, tm)), id.Get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (id *Id2) Set(v, tl, tr, l, r int, x int64) {
	id.Push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		id.delta[v] += x
		id.flag[v] = true
		id.Push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	id.Set(2*v, tl, tm, l, r, x)
	id.Set(2*v+1, tm+1, tr, l, r, x)
	id.max[v] = max(id.max[2*v], id.max[2*v+1])
}

func (id *Id2) Push(v, tl, tr int) {
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

type Id5 struct {
	pow   int
	sum   []int
	delta []int
	flag  []bool
}

func NewId5(a []int) *Id5 {
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
	return &Id5{pow: pow, sum: sum, delta: delta, flag: flag}
}

func (id *Id5) Get(v, tl, tr, l, r int) int {
	id.Push(v, tl, tr)
	if l > r {
		return 0
	}
	if l == tl && r == tr {
		return id.sum[v]
	}
	tm := (tl + tr) / 2
	return id.F(Get(2*v, tl, tm, l, min(r, tm)), Get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (id *Id5) Set(v, tl, tr, l, r, x int) {
	id.Push(v, tl, tr)
	if l > tr || r < tl {
		return
	}
	if l <= tl && r >= tr {
		id.delta[v] = x
		id.flag[v] = true
		id.Push(v, tl, tr)
		return
	}
	tm := (tl + tr) / 2
	id.Set(2*v, tl, tm, l, r, x)
	id.Set(2*v+1, tm+1, tr, l, r, x)
	id.sum[v] = id.F(id.sum[2*v], id.sum[2*v+1])
}

func (id *Id5) Push(v, tl, tr int) {
	if id.flag[v] {
		if v < id.pow {
			id.flag[2*v] = true
			id.flag[2*v+1] = true
			id.delta[2*v] = id.delta[v]
			id.delta[2*v+1] = id.delta[v]
		}
		id.flag[v] = false
		id.sum[v] = id.delta[v] * (tr - tl + 1)
	}
}

func (id *Id5) F(a, b int) int {
	return a + b
}

type Pair struct {
	x int
	y int
}

func NewPair(x, y int) *Pair {
	return &Pair{x: x, y: y}
}

func (p *Pair) Clone() *Pair {
	return NewPair(p.x, p.y)
}

func (p *Pair) String() string {
	return fmt.Sprintf("%d %d", p.x, p.y)
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

func Sort(a [][]int) {
	for i := range a {
		sort.Ints(a[i])
	}
}

func Add(mapLong map[int64]int, l int64) {
	if _, exists := mapLong[l]; exists {
		mapLong[l]++
	} else {
		mapLong[l] = 1
	}
}

func Remove(mapInt map[int]int, s int) {
	if mapInt[s] > 1 {
		mapInt[s]--
	} else {
		delete(mapInt, s)
	}
}

var maxLong int64 = math.MaxInt64 / 2
var eps float64 = 1e-10

func Signum(x float64) int {
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

type Id6 struct {
	t []int
}

func NewId6(n int) *Id6 {
	t := make([]int, n)
	return &Id6{t: t}
}

func (id *Id6) Add(x, delta int) {
	for i := x; i < len(id.t); i = (i | (i + 1)) {
		id.t[i] += delta
	}
}

func (id *Id6) Sum(r int) int {
	ans := 0
	x := r
	for x >= 0 {
		ans += id.t[x]
		x = (x & (x + 1)) - 1
	}
	return ans
}

func (id *Id6) SumRange(l, r int) int {
	return id.Sum(r) - id.Sum(l - 1)
}

type Id4 struct {
	pow     int
	sum     []int
	id3     []int
	id7     []int
	maxSum  []int
}

func NewId4(a []int) *Id4 {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	sum := make([]int, 2*pow)
	id3 := make([]int, 2*pow)
	maxSum := make([]int, 2*pow)
	id7 := make([]int, 2*pow)
	for i := 0; i < len(a); i++ {
		sum[pow+i] = a[i]
		maxSum[pow+i] = max(a[i], 0)
		id3[pow+i] = maxSum[pow+i]
		id7[pow+i] = maxSum[pow+i]
	}
	for i := pow - 1; i > 0; i-- {
		id4.Update(i, sum, maxSum, id3, id7)
	}
	return &Id4{pow: pow, sum: sum, id3: id3, id7: id7, maxSum: maxSum}
}

func (id *Id4) Get(v, tl, tr, l, r int) []int {
	if r <= tl || l >= tr {
		return []int{0, 0, 0, 0}
	}
	if l <= tl && r >= tr {
		return []int{id.id3[v], id.maxSum[v], id.id7[v], id.sum[v]}
	}
	tm := (tl + tr) / 2
	left := id.Get(2*v, tl, tm, l, r)
	right := id.Get(2*v+1, tm, tr, l, r)
	return []int{
		max(left[0], right[0]+left[3]),
		max(left[1], max(right[1], left[2]+right[0])),
		max(right[2], left[2]+right[3]),
		left[3] + right[3],
	}
}

func (id *Id4) Set(v, tl, tr, x, value int) {
	if v >= id.pow {
		id.sum[v] = value
		id.maxSum[v] = max(value, 0)
		id.id3[v] = id.maxSum[v]
		id.id7[v] = id.maxSum[v]
		return
	}
	tm := (tl + tr) / 2
	if x < tm {
		id.Set(2*v, tl, tm, x, value)
	} else {
		id.Set(2*v+1, tm, tr, x, value)
	}
	id.Update(v, id.sum, id.maxSum, id.id3, id.id7)
}

func (id *Id4) Update(i int, sum, maxSum, id3, id7 []int) {
	sum[i] = id.F(sum[2*i], sum[2*i+1])
	maxSum[i] = max(maxSum[2*i], max(maxSum[2*i+1], id7[2*i]+id3[2*i+1]))
	id3[i] = max(id3[2*i], id3[2*i+1]+sum[2*i])
	id7[i] = max(id7[2*i+1], id7[2*i]+sum[2*i+1])
}

func (id *Id4) F(a, b int) int {
	return a + b
}

type Point struct {
	x float64
	y float64
}

func NewPoint() *Point {
	return &Point{x: 0, y: 0}
}

func (p *Point) String() string {
	return fmt.Sprintf("%f %f", p.x, p.y)
}

func (p *Point) Equals(other *Point) bool {
	return p.x == other.x && p.y == other.y
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

func (c *Circle) Angle() *Point {
	z := float64(c.r) / sq2
	z -= math.Mod(z, 1e-5)
	return NewPoint(c.p.x-z, c.p.y-z)
}

func (c *Circle) Inside(p *Point) bool {
	return id0(p.x-c.p.x, p.y-c.p.y) <= sq(float64(c.r))
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

func (f *Fraction) Clone() *Fraction {
	return NewFraction(f.x, f.y, false)
}

func (f *Fraction) String() string {
	return fmt.Sprintf("%d/%d", f.x, f.y)
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

func sq(x float64) float64 {
	return x * x
}

func sqInt(x int64) int64 {
	return x * x
}

func id0(x, y float64) float64 {
	return sq(x) + sq(y)
}

func id0Int(x, y int64) int64 {
	return sqInt(x) + sqInt(y)
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

func (p *Pol) String() string {
	ans := ""
	for _, coeff := range p.coeff {
		ans += fmt.Sprintf("%f ", coeff)
	}
	return ans
}

func (p *Pol) Value(x float64) float64 {
	ans := 0.0
	pow := 1.0
	for _, coeff := range p.coeff {
		ans += coeff * pow
		pow *= x
	}
	return ans
}

func (p *Pol) Integrate(r float64) float64 {
	newCoeff := make([]float64, len(p.coeff)+1)
	for i := range p.coeff {
		newCoeff[i+1] = p.coeff[i] / fact[i+1]
	}
	return NewPol(newCoeff).Value(r)
}

func (p *Pol) IntegrateRange(l, r float64) float64 {
	return p.Integrate(r) - p.Integrate(l)
}

var fact = make([]float64, 100)

type Id1 struct {
	p    []int
	sz   []int
	less *Stack
	more *Stack
	q    [][]int
	used []bool
}

func NewId1(v []int, m int) *Id1 {
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
	return &Id1{p: p, sz: sz, less: less, more: more, q: q, used: used}
}

func (id *Id1) Get(x int) int {
	for x != id.p[x] {
		x = id.p[x]
	}
	return x
}

func (id *Id1) Unite(a, b int) bool {
	pa := id.Get(a)
	pb := id.Get(b)
	if pa == pb {
		id.less.Add(-1)
		id.more.Add(-1)
		return false
	}
	if id.sz[pa] < id.sz[pb] {
		id.p[pa] = pb
		id.sz[pb] += id.sz[pa]
		id.less.Add(pa)
		id.more.Add(pb)
		for _, i := range id.q[pa] {
			id.q[pb] = append(id.q[pb], i)
		}
	} else {
		id.p[pb] = pa
		id.sz[pa] += id.sz[pb]
		id.less.Add(pb)
		id.more.Add(pa)
		for _, i := range id.q[pb] {
			id.q[pa] = append(id.q[pa], i)
		}
	}
	return true
}

func (id *Id1) PopEdge() {
	pa := id.less.Pop()
	pb := id.more.Pop()
	if pa < 0 {
		return
	}
	id.p[pa] = pa
	id.sz[pb] -= id.sz[pa]
}

func (id *Id1) Poll(x int) int {
	px := id.Get(x)
	for len(id.q[px]) > 0 {
		v := -id.q[px][0]
		id.q[px] = id.q[px][1:]
		if !id.used[v] && id.Get(inv[v-1]) == px {
			id.used[v] = true
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
	dsu := NewId1(v, m)
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
