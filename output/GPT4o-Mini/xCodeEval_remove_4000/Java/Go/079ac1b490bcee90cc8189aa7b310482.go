package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const mod = 1000000007

type FastScanner struct {
	scanner *bufio.Scanner
}

func NewFastScanner() *FastScanner {
	return &FastScanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (fs *FastScanner) Next() string {
	fs.scanner.Scan()
	return fs.scanner.Text()
}

func (fs *FastScanner) NextInt() int {
	var x int
	fmt.Sscanf(fs.Next(), "%d", &x)
	return x
}

func (fs *FastScanner) NextLong() int64 {
	var x int64
	fmt.Sscanf(fs.Next(), "%d", &x)
	return x
}

type Fraction struct {
	x, y int64
}

func (f *Fraction) norm() {
	g := gcd(f.x, f.y)
	f.x /= g
	f.y /= g
}

func (f Fraction) compareTo(o Fraction) int {
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

func sum(a, b Fraction) Fraction {
	c := Fraction{a.x*b.y + a.y*b.x, a.y * b.y}
	c.norm()
	return c
}

func gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	return gcd(y, x%y)
}

type Pair struct {
	x, y int
}

func (p Pair) compareTo(o Pair) int {
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

func pow(x, p int64) int64 {
	if p <= 0 {
		return 1
	}
	th := pow(x, p/2)
	th = (th * th) % mod
	if p%2 == 1 {
		th = (th * x) % mod
	}
	return th
}

func mult1(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] = (c[i] + a[i^k]*b[k]) % mod
		}
	}
	return c
}

func mult(a, b [][]int64) [][]int64 {
	n := len(a)
	c := make([][]int64, n)
	for i := range c {
		c[i] = make([]int64, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}
	return c
}

func powMatrix(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		n := len(x)
		e := make([][]int64, n)
		for i := range e {
			e[i] = make([]int64, n)
			e[i][i] = 1
		}
		return e
	}
	ans := powMatrix(x, p/2)
	ans = mult(ans, ans)
	if p%2 == 1 {
		ans = mult(ans, x)
	}
	return ans
}

func multArray(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] = (c[i] + a[k]*b[k^i]) % mod
		}
	}
	return c
}

func powArray(x []int64, p int64) []int64 {
	if p == 0 {
		e := make([]int64, len(x))
		e[0] = 1
		return e
	}
	ans := powArray(x, p/2)
	ans = multArray(ans, ans)
	if p%2 == 1 {
		ans = multArray(ans, x)
	}
	return ans
}

func modInv(x int64) int64 {
	return pow(x, mod-2)
}

type id5 struct {
	div    []int
	primes []int
}

func NewId5(max int) *id5 {
	div := make([]int, max+1)
	primes := []int{}
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
	return &id5{div: div, primes: primes}
}

func (id *id5) factorization(x int) []int {
	ans := []int{}
	for id.div[x] > 0 {
		ans = append(ans, id.div[x])
		x /= id.div[x]
	}
	return ans
}

func (id *id5) id1(x int) []int {
	div := id.factorization(x)
	lenDiv := len(div)
	set := map[int]struct{}{}
	for mask := 0; mask < (1 << lenDiv); mask++ {
		th := 1
		for i := 0; i < lenDiv; i++ {
			if (mask & (1 << i)) > 0 {
				th *= div[i]
			}
		}
		set[th] = struct{}{}
	}
	ans := make([]int, 0, len(set))
	for i := range set {
		ans = append(ans, i)
	}
	sort.Ints(ans)
	return ans
}

func (id *id5) id0(x int) []int {
	div := id.factorization(x)
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
	ans := map[int]struct{}{}
	for {
		z := 1
		for i := 0; i < len(th); i++ {
			z *= pow[i][th[i]]
		}
		ans[z] = struct{}{}
		if !next(th, sz) {
			break
		}
	}
	answer := make([]int, 0, len(ans))
	for i := range ans {
		answer = append(answer, i)
	}
	sort.Ints(answer)
	return answer
}

func next(th, max []int) bool {
	for i := len(th) - 1; i >= 0; i-- {
		if th[i] != max[i] {
			th[i]++
			for j := i + 1; j < len(max); j++ {
				th[j] = 0
			}
			return true
		}
	}
	return false
}

func (id *id5) id2(x int) string {
	if x == 1 {
		return "1 = 1"
	}
	list := id.factorization(x)
	ans := fmt.Sprintf("%d = ", x)
	for i, v := range list {
		ans += fmt.Sprintf("%d", v)
		if i < len(list)-1 {
			ans += " * "
		}
	}
	return ans
}

type Rect struct {
	x1, y1, x2, y2 int
}

func (r Rect) String() string {
	return fmt.Sprintf("%d %d %d %d", r.x1, r.y1, r.x2, r.y2)
}

func (r Rect) equals(other Rect) bool {
	return r.x1 == other.x1 && r.y1 == other.y1 && r.x2 == other.x2 && r.y2 == other.y2
}

func (r Rect) inside(x, y int) int {
	inx := in(r.x1, r.x2, x)
	iny := in(r.y1, r.y2, y)
	return inx * iny
}

func (r Rect) additional(other Rect) int {
	if r.equals(other) {
		return 0
	}
	if r.inside(other.x1, other.y1) == 4 || r.inside(other.x2, other.y2) == 4 || r.inside(other.x1, other.y2) == 4 || r.inside(other.x2, other.y1) == 4 {
		return 1
	}
	if r.inside(other.x1, other.y1) == 1 || r.inside(other.x2, other.y2) == 1 {
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

func sumMod(x, y int) int {
	if x+y >= mod {
		return x + y - mod
	}
	return x + y
}

func multMod(x, y int64) int64 {
	return (x * y) % mod
}

func divMod(x, y int64) int64 {
	return (x * modInv(y)) % mod
}

type id6 struct {
	sum []int64
}

func NewId6(n int) *id6 {
	return &id6{sum: make([]int64, n)}
}

func (id *id6) add(x int, d int64) {
	for i := x; i < len(id.sum); i = (i | (i + 1)) {
		id.sum[i] += d
	}
}

func (id *id6) sumTo(r int) int64 {
	ans := int64(0)
	for i := r; i >= 0; i = (i & (i + 1)) - 1 {
		ans += id.sum[i]
	}
	return ans
}

func (id *id6) sumRange(l, r int) int64 {
	if l > r {
		return 0
	}
	return id.sumTo(r) - id.sumTo(l - 1)
}

type id3 struct {
	pow   int
	max   []int64
	delta []int64
	flag  []bool
}

func NewId3(a []int64) *id3 {
	pow := 1
	for pow < len(a) {
		pow *= 2
	}
	max := make([]int64, 2*pow)
	delta := make([]int64, 2*pow)
	for i := 0; i < len(max); i++ {
		max[i] = math.MinInt64 / 2
	}
	for i := 0; i < len(a); i++ {
		max[pow+i] = a[i]
	}
	for i := pow - 1; i > 0; i-- {
		max[i] = f(max[2*i], max[2*i+1])
	}
	return &id3{pow: pow, max: max, delta: delta, flag: make([]bool, 2*pow)}
}

func (id *id3) get(v, tl, tr, l, r int) int64 {
	id.push(v, tl, tr)
	if l > r {
		return math.MinInt64 / 2
	}
	if l == tl && r == tr {
		return id.max[v]
	}
	tm := (tl + tr) / 2
	return f(id.get(2*v, tl, tm, l, min(r, tm)), id.get(2*v+1, tm+1, tr, max(l, tm+1), r))
}

func (id *id3) set(v, tl, tr, l, r int, x int64) {
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
	tm := (tl + tr) / 2
	id.set(2*v, tl, tm, l, r, x)
	id.set(2*v+1, tm+1, tr, l, r, x)
	id.max[v] = f(id.max[2*v], id.max[2*v+1])
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
	return max(a, b)
}

type Circle struct {
	x, y, r int
}

func (c Circle) clone() Circle {
	return Circle{x: c.x, y: c.y, r: c.r}
}

func (c Circle) compareTo(o Circle) int {
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
	minr := min(a.r, b.r)
	a.r -= minr
	b.r -= minr
	b.x -= a.x
	b.y -= a.y
	a0 := math.Atan2(float64(b.y), float64(b.x))
	len := math.Sqrt(float64(b.x*b.x + b.y*b.y))
	var da float64
	if a.r == 0 {
		da = math.Asin(float64(b.r)/len) + math.Pi/2
	} else {
		da = math.Acos(float64(a.r) / len)
	}
	return []float64{a0 - da, a0 + da}
}

func norm(ans []float64) []float64 {
	for i := range ans {
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

var x int
var b []int

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
	i, j, k := l, m, l
	for i < m && j < r {
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
		x++
	}
	for i < m {
		b[k] = a[i]
		i++
		k++
	}
	for j < r {
		b[k] = a[j]
		j++
		k++
	}
	for p := l; p < r; p++ {
		a[p] = b[p]
	}
	return true
}

func rev(a []int) []int {
	res := make([]int, len(a))
	for i := range a {
		res[a[i]] = i
	}
	return res
}

func solve(fs *FastScanner) {
	s := fs.Next()
	l, r := 0, 100001
	for {
		sz := (l + r) >> 1
		a := make([]int, sz)
		for i := 0; i < sz; i++ {
			a[i] = i
		}
		x = 0
		b = make([]int, sz)
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
		for i := range a {
			fmt.Printf("%d ", a[i]+1)
		}
		return
	}
}

func main() {
	fs := NewFastScanner()
	solve(fs)
}