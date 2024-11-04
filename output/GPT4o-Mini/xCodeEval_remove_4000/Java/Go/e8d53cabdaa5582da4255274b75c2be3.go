package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type F struct {
	in      *bufio.Reader
	out     *bufio.Writer
	mod     int64
	x       int
	b       []int
}

func (f *F) pow(x, p, mod int64) int64 {
	if p <= 0 {
		return 1
	}
	th := f.pow(x, p/2, mod)
	th = (th * th) % mod
	if p%2 == 1 {
		th = (th * x) % mod
	}
	return th
}

type Fraction struct {
	x, y int64
}

func (f *Fraction) norm() {
	gcd := f.gcd(f.x, f.y)
	f.x /= gcd
	f.y /= gcd
}

func (f *Fraction) gcd(x, y int64) int64 {
	if y == 0 {
		return x
	}
	if x == 0 {
		return y
	}
	return f.gcd(y, x%y)
}

func (f *Fraction) sum(a, b Fraction) Fraction {
	c := Fraction{a.x*b.y + a.y*b.x, a.y * b.y}
	c.norm()
	return c
}

type Pair struct {
	x, y int
}

func (p *Pair) clone() Pair {
	return Pair{p.x, p.y}
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

func (f *F) mult1(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[i^k] * b[k]
			c[i] %= f.mod
		}
	}
	return c
}

func (f *F) mult(a, b [][]int64) [][]int64 {
	n := len(a)
	c := make([][]int64, n)
	for i := range c {
		c[i] = make([]int64, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				c[i][j] += a[i][k] * b[k][j]
				c[i][j] %= f.mod
			}
		}
	}
	return c
}

func (f *F) powMatrix(x [][]int64, p int64) [][]int64 {
	if p == 0 {
		e := make([][]int64, len(x))
		for i := range e {
			e[i] = make([]int64, len(x))
			e[i][i] = 1
		}
		return e
	}
	ans := f.powMatrix(x, p/2)
	ans = f.mult(ans, ans)
	if p%2 == 1 {
		ans = f.mult(ans, x)
	}
	return ans
}

func (f *F) multArray(a, b []int64) []int64 {
	n := len(a)
	c := make([]int64, n)
	for i := 0; i < n; i++ {
		for k := 0; k < n; k++ {
			c[i] += a[k] * b[k^i]
			c[i] %= f.mod
		}
	}
	return c
}

func (f *F) powArray(x []int64, p int64) []int64 {
	if p == 0 {
		e := make([]int64, len(x))
		e[0] = 1
		return e
	}
	ans := f.powArray(x, p/2)
	ans = f.multArray(ans, ans)
	if p%2 == 1 {
		ans = f.multArray(ans, x)
	}
	return ans
}

func (f *F) modInv(x int64) int64 {
	return f.pow(x, f.mod-2, f.mod)
}

type id5 struct {
	div    []int
	primes []int
}

func newId5(max int) *id5 {
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

func (r Rect) toString() string {
	return fmt.Sprintf("%d %d %d %d", r.x1, r.y1, r.x2, r.y2)
}

func (r Rect) equals(r2 Rect) bool {
	return r.x1 == r2.x1 && r.y1 == r2.y1 && r.x2 == r2.x2 && r.y2 == r2.y2
}

func (r Rect) inside(x, y int) int {
	inx := in(r.x1, r.x2, x)
	iny := in(r.y1, r.y2, y)
	return inx * iny
}

func (r Rect) additional(r2 Rect) int {
	if r.equals(r2) {
		return 0
	}
	if r.inside(r2.x1, r2.y1) == 4 || r.inside(r2.x2, r2.y2) == 4 || r.inside(r2.x1, r2.y2) == 4 || r.inside(r2.x2, r2.y1) == 4 {
		return 1
	}
	if r.inside(r2.x1, r2.y1) == 1 || r.inside(r2.x2, r2.y2) == 1 {
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

func (f *F) sum(x, y int64) int64 {
	if x+y >= f.mod {
		return x + y - f.mod
	}
	return x + y
}

func (f *F) mult(x, y int64) int64 {
	return x * y % f.mod
}

func (f *F) div(x, y int64) int64 {
	return x * f.modInv(y) % f.mod
}

func (f *F) solve() {
	s, _ := f.in.ReadString('\n')
	s = strings.TrimSpace(s)
	for sz := 1; ; sz++ {
		a := make([]int, sz)
		for i := 0; i < sz; i++ {
			a[i] = i
		}
		f.x = 0
		f.b = make([]int, sz)
		if !f.mergeSort(s, a, 0, sz) {
			continue
		}
		if f.x < len(s) {
			continue
		}
		a = f.rev(a)
		f.out.WriteString(fmt.Sprintf("%d\n", sz))
		for i := 0; i < len(a); i++ {
			f.out.WriteString(fmt.Sprintf("%d ", a[i]+1))
		}
		f.out.WriteString("\n")
		return
	}
}

func (f *F) mergeSort(s string, a []int, l, r int) bool {
	if r-l <= 1 {
		return true
	}
	m := (l + r) >> 1
	if !f.mergeSort(s, a, l, m) {
		return false
	}
	if !f.mergeSort(s, a, m, r) {
		return false
	}
	i, j, k := l, m, l
	for i < m && j < r {
		if f.x == len(s) {
			return false
		}
		if s[f.x] == '0' {
			f.b[k] = a[i]
			i++
		} else {
			f.b[k] = a[j]
			j++
		}
		k++
		f.x++
	}
	for i < m {
		f.b[k] = a[i]
		i++
		k++
	}
	for j < r {
		f.b[k] = a[j]
		j++
		k++
	}
	for p := l; p < r; p++ {
		a[p] = f.b[p]
	}
	return true
}

func (f *F) rev(a []int) []int {
	res := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		res[a[i]] = i
	}
	return res
}

func (f *F) run() {
	f.mod = 1000000007
	f.in = bufio.NewReader(os.Stdin)
	f.out = bufio.NewWriter(os.Stdout)
	defer f.out.Flush()
	f.solve()
}

func main() {
	f := &F{}
	f.run()
}
