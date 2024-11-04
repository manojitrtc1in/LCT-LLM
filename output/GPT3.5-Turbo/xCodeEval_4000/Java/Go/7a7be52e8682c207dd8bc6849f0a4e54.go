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
	br *bufio.Reader
}

func NewFastScanner(f *os.File) *FastScanner {
	return &FastScanner{br: bufio.NewReader(f)}
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
	return &PrintWriter{bw: bufio.NewWriter(f)}
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

type F struct {
	in       *FastScanner
	out      *PrintWriter
	systemIO bool
}

func (f *F) Pow(x, p, mod int64) int64 {
	if p <= 0 {
		return 1
	}
	th := f.Pow(x, p/2, mod)
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
	return &Fraction{x: x, y: y}
}

func (frac *Fraction) Norm() {
	gcd := f.Gcd(frac.x, frac.y)
	frac.x /= gcd
	frac.y /= gcd
}

func (frac *Fraction) CompareTo(o *Fraction) int {
	if frac.x > o.x {
		return 1
	}
	if frac.x < o.x {
		return -1
	}
	if frac.y > o.y {
		return 1
	}
	if frac.y < o.y {
		return -1
	}
	return 0
}

func (f *F) Sum(a, b *Fraction) *Fraction {
	c := NewFraction(a.x*b.y+a.y*b.x, a.y*b.y)
	c.Norm()
	return c
}

func (f *F) Gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	if x == 0 {
		return y
	}
	return f.Gcd(y, x%y)
}

type Pair struct {
	x int
	y int
}

func NewPair(x, y int) *Pair {
	return &Pair{x: x, y: y}
}

func (p *Pair) Clone() *Pair {
	return &Pair{x: p.x, y: p.y}
}

func (p *Pair) CompareTo(o *Pair) int {
	if p.x > o.x {
		return 1
	}
	if p.x < o.x {
		return -1
	}
	if p.y > o.y {
		return 1
	}
	if p.y < o.y {
		return -1
	}
	return 0
}

func (f *F) Mult1(a, b []int64) []int64 {
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

func (f *F) Mult(a, b [][]int64) [][]int64 {
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

func (f *F) Pow(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		e := make([][]int64, len(x))
		for i := 0; i < len(e); i++ {
			e[i] = make([]int64, len(x))
			e[i][i] = 1
		}
		return e
	}
	ans := f.Pow(x, p/2)
	ans = f.Mult(ans, ans)
	if p%2 == 1 {
		ans = f.Mult(ans, x)
	}
	return ans
}

func (f *F) Mult(a, b []int64) []int64 {
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

func (f *F) Pow(x []int64, p int64) []int64 {
	if p == 0 {
		e := make([]int64, len(x))
		e[0] = 1
		return e
	}
	ans := f.Pow(x, p/2)
	ans = f.Mult(ans, ans)
	if p%2 == 1 {
		ans = f.Mult(ans, x)
	}
	return ans
}

func (f *F) Pow(x, p int64) int64 {
	if p <= 0 {
		return 1
	}
	ans := f.Pow(x, p/2)
	ans = (ans * ans) % mod
	if p%2 == 1 {
		ans = (ans * x) % mod
	}
	return ans
}

func (f *F) ModInv(x int64) int64 {
	return f.Pow(x, mod-2)
}

type Factorizator struct {
	div    []int
	primes []int
}

func NewFactorizator(max int) *Factorizator {
	div := make([]int, max+1)
	primes := make([]int, 0)
	for i := 2; i < len(div); i++ {
		if div[i] == 0 {
			div[i] = i
			primes = append(primes, i)
		}
		for _, j := range primes {
			if i*j > max {
				break
			}
			div[i*j] = j
		}
	}
	return &Factorizator{div: div, primes: primes}
}

func (f *Factorizator) Factorization(x int) []int {
	ans := make([]int, 0)
	for f.div[x] > 0 {
		ans = append(ans, f.div[x])
		x /= f.div[x]
	}
	return ans
}

func (f *Factorizator) AllDivisors(x int) []int {
	div := f.Factorization(x)
	len := len(div)
	set := make(map[int]bool)
	for mask := 0; mask < (1 << len); mask++ {
		th := 1
		for i := 0; i < len; i++ {
			if (mask & (1 << i)) > 0 {
				th *= div[i]
			}
		}
		set[th] = true
	}
	ans := make([]int, 0)
	for i := range set {
		ans = append(ans, i)
	}
	return ans
}

func (f *Factorizator) Divisors(x int) []int {
	div := f.Factorization(x)
	pr := 0
	for i := 0; i < len(div); i++ {
		if i == 0 || div[i] != div[i-1] {
			pr++
		}
	}
	primes := make([]int, pr)
	sz := make([]int, pr)
	pr = -1
	for i := 0; i < len(div); i++ {
		if i == 0 || div[i] != div[i-1] {
			pr++
			primes[pr] = div[i]
			sz[pr] = 1
		} else {
			sz[pr]++
		}
	}
	pr++
	pow := make([][]int, pr)
	for i := 0; i < len(pow); i++ {
		pow[i] = make([]int, sz[i]+1)
		pow[i][0] = 1
		for j := 1; j < len(pow[i]); j++ {
			pow[i][j] = pow[i][j-1] * primes[i]
		}
	}
	th := make([]int, pr)
	ans := make(map[int]bool)
	for {
		z := 1
		for i := 0; i < len(th); i++ {
			z *= pow[i][th[i]]
		}
		ans[z] = true
		ok := false
		for i := len(th) - 1; i >= 0; i-- {
			if th[i] != sz[i] {
				th[i]++
				for j := i + 1; j < len(sz); j++ {
					th[j] = 0
				}
				ok = true
				break
			}
		}
		if !ok {
			break
		}
	}
	answer := make([]int, 0)
	for i := range ans {
		answer = append(answer, i)
	}
	return answer
}

func (f *Factorizator) FactorizationToString(x int) string {
	if x == 1 {
		return "1 = 1"
	}
	list := f.Factorization(x)
	ans := fmt.Sprintf("%d = ", x)
	for i := 0; i < len(list); i++ {
		ans += strconv.Itoa(list[i])
		if i < len(list)-1 {
			ans += " * "
		}
	}
	return ans
}

type Rect struct {
	x1 int
	y1 int
	x2 int
	y2 int
}

func NewRect(x1, y1, x2, y2 int) *Rect {
	return &Rect{x1: x1, y1: y1, x2: x2, y2: y2}
}

func (r *Rect) String() string {
	return fmt.Sprintf("%d %d %d %d", r.x1, r.y1, r.x2, r.y2)
}

func (r *Rect) Equals(rect *Rect) bool {
	return r.x1 == rect.x1 && r.y1 == rect.y1 && r.x2 == rect.x2 && r.y2 == rect.y2
}

func (r *Rect) Inside(x, y int) int {
	inx := f.In(r.x1, r.x2, x)
	iny := f.In(r.y1, r.y2, y)
	return inx * iny
}

func (r *Rect) Additional(rect *Rect) int {
	if r.Equals(rect) {
		return 0
	}
	if r.Inside(rect.x1, rect.y1) == 4 || r.Inside(rect.x2, rect.y2) == 4 || r.Inside(rect.x1, rect.y2) == 4 || r.Inside(rect.x2, rect.y1) == 4 {
		return 1
	}
	if r.Inside(rect.x1, rect.y1) == 1 || r.Inside(rect.x2, rect.y2) == 1 {
		return 1
	}
	return 2
}

func (f *F) In(min, max, x int) int {
	if x == min || x == max {
		return 1
	}
	if x > min && x < max {
		return 2
	}
	return 0
}

func (f *F) Sum(x, y int) int {
	if x+y >= mod {
		return x + y - mod
	}
	return x + y
}

func (f *F) Mult(x, y int64) int64 {
	return x * y % mod
}

func (f *F) Div(x, y int64) int64 {
	return x * f.ModInv(y) % mod
}

const mod = 1000000007

type Fenvik struct {
	sum []int64
}

func NewFenvik(n int) *Fenvik {
	return &Fenvik{sum: make([]int64, n)}
}

func (f *Fenvik) Add(x int, d int64) {
	for i := x; i < len(f.sum); i |= i + 1 {
		f.sum[i] += d
	}
}

func (f *Fenvik) Sum(r int) int64 {
	var ans int64
	for i := r; i >= 0; i = i&(i+1) - 1 {
		ans += f.sum[i]
	}
	return ans
}

func (f *Fenvik) SumRange(l, r int) int64 {
	if l > r {
		return 0
	}
	return f.Sum(r) - f.Sum(l-1)
}

type SegmentTreeAdd struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func NewSegmentTreeAdd(a []int64) *SegmentTreeAdd {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	flag := make([]bool, 2*pow)
	for i := 0; i < len(max); i++ {
		max[i] = math.MinInt64 / 2
	}
	for i := 0; i < len(a); i++ {
		max[pow+i] = a[i]
	}
	for i := pow - 1; i > 0; i-- {
		max[i] = f.F(max[2*i], max[2*i+1])
	}
	return &SegmentTreeAdd{pow: pow, max: max, delta: delta, flag: flag}
}

func (st *SegmentTreeAdd) Add(v, l, r int, line int64) {
	st.push(v, l, r)
	if st.max[v] == math.MinInt64/2 {
		st.max[v] = line
		return
	}
	if v >= st.pow {
		if v%2 == 0 {
			if f.F(line, st.max[v].value(l)) {
				st.max[v] = line
			}
		} else {
			if f.F(line, st.max[v].value(r)) {
				st.max[v] = line
			}
		}
		return
	}
	m := (l + r) / 2
	if f.F(line, st.max[v].value(m)) {
		c := line
		line = st.max[v]
		st.max[v] = c
	}
	if f.F(line, st.max[v].value(l)) {
		st.Add(2*v, l, m, line)
	}
	if f.F(line, st.max[v].value(r)) {
		st.Add(2*v+1, m, r, line)
	}
}

func (st *SegmentTreeAdd) push(v, l, r int) {
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

func (st *SegmentTreeAdd) F(a, b int64) bool {
	return a > b
}

func (st *SegmentTreeAdd) Get(v, l, r, x int) int64 {
	st.push(v, l, r)
	if st.max[v] == math.MinInt64/2 {
		return 0
	}
	if v >= st.pow {
		return st.max[v].value(x)
	}
	ans := st.max[v].value(x)
	m := (l + r) / 2
	if x <= m {
		ans = f.F(ans, st.Get(2*v, l, m, x))
	}
	if x >= m {
		ans = f.F(ans, st.Get(2*v+1, m, r, x))
	}
	return ans
}

func (st *SegmentTreeAdd) Get(x int) int64 {
	return st.Get(1, 0, st.pow, x)
}

type Circle struct {
	x int
	y int
	r int
}

func NewCircle(x, y, r int) *Circle {
	return &Circle{x: x, y: y, r: r}
}

func (c *Circle) Clone() *Circle {
	return &Circle{x: c.x, y: c.y, r: c.r}
}

func (c *Circle) CompareTo(o *Circle) int {
	if c.r != o.r {
		return c.r - o.r
	}
	if c.x != o.x {
		return c.x - o.x
	}
	return c.y - o.y
}

func (f *F) Inside(small, big *Circle) bool {
	return (small.x-big.x)*(small.x-big.x)+(small.y-big.y)*(small.y-big.y) <= (big.r-small.r)*(big.r-small.r)
}

func (f *F) Tangent(c1, c2 *Circle) []float64 {
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
	return f.Norm(ans)
}

func (f *F) Norm(ans []float64) []float64 {
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

func (f *F) MergeSort(s string, a []int, l, r int) bool {
	if r-l <= 1 {
		return true
	}
	m := (l + r) >> 1
	if !f.MergeSort(s, a, l, m) {
		return false
	}
	if !f.MergeSort(s, a, m, r) {
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

func (f *F) Rev(a []int) []int {
	res := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		res[a[i]] = i
	}
	return res
}

func (f *F) Solve() {
	s := f.in.Next()
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
		if !f.MergeSort(s, a, 0, sz) {
			r = sz
			continue
		}
		if x < len(s) {
			l = sz
			continue
		}
		a = f.Rev(a)
		f.out.Println(sz)
		for i := 0; i < len(a); i++ {
			f.out.Print(a[i]+1, " ")
		}
		return
	}
}

func (f *F) Run() {
	if f.systemIO {
		f.in = NewFastScanner(os.Stdin)
		f.out = NewPrintWriter(os.Stdout)
	} else {
		inFile, _ := os.Open("input.txt")
		defer inFile.Close()
		outFile, _ := os.Create("output.txt")
		defer outFile.Close()
		f.in = NewFastScanner(inFile)
		f.out = NewPrintWriter(outFile)
	}
	f.Solve()
	f.out.Flush()
}

func main() {
	f := &F{systemIO: true}
	f.Run()
}
