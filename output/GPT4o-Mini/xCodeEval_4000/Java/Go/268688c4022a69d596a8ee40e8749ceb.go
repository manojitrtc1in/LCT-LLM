package main

import (
	"fmt"
	"math"
	"sort"
)

func repow(b int, p int) int {
	a := int64(b)
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res *= a
		}
		a *= a
		p /= 2
	}
	return int(res)
}

func repowMod(b int, p int, modder int) int {
	a := int64(b % modder)
	res := int64(1)
	for p > 0 {
		if p%2 == 1 {
			res = (res * a) % int64(modder)
		}
		a = (a * a) % int64(modder)
		p /= 2
	}
	return int(res)
}

func gcd(c int64, d int64) int64 {
	for {
		f := c % d
		if f == 0 {
			return d
		}
		c = d
		d = f
	}
}

func lcm(c int64, d int64) int64 {
	return c / gcd(c, d) * d
}

func divList(n int) []int {
	div := []int{}
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			div = append(div, i)
			if i*i != n {
				div = append(div, n/i)
			}
		}
	}
	return div
}

func divListLong(n int64) []int64 {
	div := []int64{}
	for i := int64(1); i*i <= n; i++ {
		if n%i == 0 {
			div = append(div, i)
			if i*i != n {
				div = append(div, n/i)
			}
		}
	}
	return div
}

func divSet(n int) map[int]struct{} {
	div := make(map[int]struct{})
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			div[i] = struct{}{}
			div[n/i] = struct{}{}
		}
	}
	return div
}

func pFacMap(x int64) map[int64]int {
	mp := make(map[int64]int)
	t := x
	for i := int64(2); i*i <= x && i <= t; i++ {
		if t%i == 0 {
			num := 0
			for t%i == 0 {
				t /= i
				num++
			}
			mp[i] = num
		}
	}
	if t != 1 {
		mp[t] = 1
	}
	return mp
}

func isPrime(n int64) bool {
	if n == 2 {
		return true
	}
	if n&1 == 0 || n == 1 {
		return false
	}
	if n > math.MaxInt32 {
		return tameshiwari(n)
	}
	d := n - 1
	s := 0
	for d&1 == 0 {
		d /= 2
		s++
	}
	aa := []int{2, 3, 5, 7, 11, 13, 17}
	for _, a := range aa {
		if a >= int(n) {
			break
		}
		t := d
		y := repow(a, int(t))
		for t != n-1 && y != 1 && y != n-1 {
			y = (y * y) % n
			t *= 2
		}
		if y != n-1 && t%2 == 0 {
			return false
		}
	}
	return true
}

func tameshiwari(n int64) bool {
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

type NCK struct {
	max  int
	mod  int
	fac  []int64
	finv []int64
	inv  []int64
}

func NewNCK(max int, mod int) *NCK {
	nck := &NCK{max: max, mod: mod}
	nck.pre(max, mod)
	return nck
}

func (nck *NCK) pre(nmax int, nmod int) {
	nck.fac = make([]int64, nmax)
	nck.finv = make([]int64, nmax)
	nck.inv = make([]int64, nmax)
	nck.fac[0] = 1
	nck.fac[1] = 1
	nck.finv[0] = 1
	nck.finv[1] = 1
	nck.inv[1] = 1
	for i := 2; i < nmax; i++ {
		nck.fac[i] = nck.fac[i-1] * int64(i) % int64(nmod)
		nck.inv[i] = int64(nmod - nck.inv[nmod%i]*(nmod/i)%nmod) % int64(nmod)
		nck.finv[i] = nck.finv[i-1] * nck.inv[i] % int64(nmod)
	}
}

func (nck *NCK) nCk(n int, k int) int64 {
	if n < k {
		return 0
	}
	if n < 0 || k < 0 {
		return 0
	}
	return nck.fac[n] * (nck.finv[k] * nck.finv[n-k] % int64(nck.mod)) % int64(nck.mod)
}

func kmp(t string, p string) int {
	f := make([]int, len(p)+1)
	i, j := 0, 1
	f[1] = 0
	for j < len(p) {
		if i == 0 || p[i-1] == p[j-1] {
			i++
			j++
			f[j] = i
		} else {
			i = f[i]
		}
	}
	i, j = 1, 1
	for i <= len(p) && j <= len(t) {
		if i == 0 || p[i-1] == t[j-1] {
			i++
			j++
		} else {
			i = f[i]
		}
	}
	if i == (len(p) + 1) {
		return j - i
	}
	return -1
}

func stSort(s string) string {
	sb := []rune(s)
	lg := len(sb)
	for i := 1; i < lg; i++ {
		l, r := 0, i-1
		for l <= r {
			gaze := (l + r) / 2
			if sb[gaze] <= sb[i] {
				l = gaze + 1
			} else {
				r = gaze - 1
			}
		}
		sb = append(sb[:l], append([]rune{sb[i]}, sb[l:]...)...)
		sb = append(sb[:i+1], sb[i+1:]...)
	}
	return string(sb)
}

type Xy struct {
	x int
	y int
}

func NewXy(x int, y int) Xy {
	return Xy{x: x, y: y}
}

func (o Xy) manht(other Xy) int {
	return int(math.Abs(float64(o.x-other.x))) + int(math.Abs(float64(o.y-other.y)))
}

func (o Xy) henkaku() float64 {
	return math.Atan2(float64(o.y), float64(o.x))
}

func hencom(s1 Xy, s2 Xy) int {
	return int(math.Signbit(s1.henkaku() - s2.henkaku()))
}

func (o Xy) equals(other Xy) bool {
	return o.x == other.x && o.y == other.y
}

type Zip1 struct {
	zip    map[int64]int
	unzip  []int64
}

func NewZip1(a []int64) *Zip1 {
	zip := make(map[int64]int)
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
	mae := int64(0)
	zure := 0
	for i := 0; i < len(a); i++ {
		if i == 0 || mae != a[i] {
			zip[a[i]] = i - zure
			mae = a[i]
		} else {
			zure++
		}
	}
	unzip := make([]int64, len(zip))
	for k, v := range zip {
		unzip[v] = k
	}
	return &Zip1{zip: zip, unzip: unzip}
}

func (z *Zip1) zipValue(t int64) int {
	return z.zip[t]
}

func (z *Zip1) unzipValue(i int) int64 {
	return z.unzip[i]
}

func (z *Zip1) size() int {
	return len(z.zip)
}

type UnFd struct {
	parent []int
	size   []int
	forest int
}

func NewUnFd(n int) *UnFd {
	parent := make([]int, n)
	size := make([]int, n)
	forest := n
	for i := 0; i < n; i++ {
		parent[i] = i
		size[i] = 1
	}
	return &UnFd{parent: parent, size: size, forest: forest}
}

func (uf *UnFd) isRoot(i int) bool {
	return uf.parent[i] == i
}

func (uf *UnFd) rootOf(i int) int {
	if uf.isRoot(i) {
		return i
	}
	uf.parent[i] = uf.rootOf(uf.parent[i])
	return uf.parent[i]
}

func (uf *UnFd) same(i int, j int) bool {
	return uf.rootOf(i) == uf.rootOf(j)
}

func (uf *UnFd) merge(i int, j int) {
	i = uf.rootOf(i)
	j = uf.rootOf(j)
	if i == j {
		return
	}
	uf.size[int(math.Min(float64(i), float64(j)))] += uf.size[int(math.Max(float64(i), float64(j)))]
	uf.parent[int(math.Max(float64(i), float64(j)))] = int(math.Min(float64(i), float64(j)))
	uf.forest--
}

func (uf *UnFd) sizeOf(i int) int {
	return uf.size[uf.rootOf(i)]
}

func (uf *UnFd) parents() []int {
	return uf.parent
}

func (uf *UnFd) forestCount() int {
	return uf.forest
}

func (uf *UnFd) String() string {
	return fmt.Sprint(uf.parent)
}

type SegTree[T any] struct {
	n    int
	m    int
	op   func(a, b T) T
	l    []int
	r    []int
	a    []T
	ident T
}

func NewSegTree[T any](n int, op func(a, b T) T, ident T) *SegTree[T] {
	seg := &SegTree[T]{n: n, op: op, ident: ident}
	ii := n - 1
	p := 0
	for ii > 0 {
		ii /= 2
		p++
	}
	seg.m = repow(2, p+1) - 1
	seg.a = make([]T, seg.m)
	for i := range seg.a {
		seg.a[i] = ident
	}
	seg.l = make([]int, seg.m)
	seg.r = make([]int, seg.m)
	for i := 0; i <= seg.m/2; i++ {
		seg.l[seg.m/2+i] = i
		seg.r[seg.m/2+i] = i + 1
	}
	for i := seg.m/2 - 1; i >= 0; i-- {
		seg.l[i] = seg.l[lch(i)]
		seg.r[i] = seg.r[rch(i)]
	}
	return seg
}

func (seg *SegTree[T]) getAll() T {
	return seg.a[0]
}

func (seg *SegTree[T]) get(from int, to int) T {
	if from < 0 || seg.n < to || from >= to {
		panic(fmt.Sprintf("%d,%d", from, to))
	}
	return seg.getRec(from, to, 0)
}

func (seg *SegTree[T]) getRec(from int, to int, node int) T {
	if from == seg.l[node] && to == seg.r[node] {
		return seg.a[node]
	} else {
		if to <= seg.l[node]+(seg.r[node]-seg.l[node])/2 {
			return seg.getRec(from, to, lch(node))
		} else if seg.l[node]+(seg.r[node]-seg.l[node])/2 <= from {
			return seg.getRec(from, to, rch(node))
		} else {
			return seg.op(seg.getRec(from, seg.l[node]+(seg.r[node]-seg.l[node])/2, lch(node)), seg.getRec(seg.l[node]+(seg.r[node]-seg.l[node])/2, to, rch(node)))
		}
	}
}

func (seg *SegTree[T]) set(ob T, i int) {
	if i < 0 || seg.n <= i {
		panic(fmt.Sprintf("%d is out of length %d", i, seg.n))
	}
	j := seg.m/2 + i
	seg.a[j] = ob
	for {
		if j == 0 {
			break
		}
		j = prt(j)
		seg.a[j] = seg.op(seg.a[lch(j)], seg.a[rch(j)])
	}
}

func prt(node int) int {
	return (node - 1) / 2
}

func lch(node int) int {
	return 2*node + 1
}

func rch(node int) int {
	return 2*node + 2
}

func (seg *SegTree[T]) String() string {
	return fmt.Sprint(seg.a)
}

func nextPermutation(per []int) bool {
	if len(per) < 2 {
		return false
	}
	i := len(per) - 1
	for i > 0 {
		if per[i-1] < per[i] {
			break
		}
		i--
	}
	if i > 0 {
		i--
		var tmp int
		j := len(per) - 1
		for j > i {
			if per[j] > per[i] {
				break
			}
			j--
		}
		tmp = per[i]
		per[i] = per[j]
		per[j] = tmp
		for k := i + 1; k < (i+1+len(per))/2; k++ {
			tmp = per[k]
			per[k] = per[len(per)-k+i]
			per[len(per)-k+i] = tmp
		}
		return true
	}
	var tmp int
	for k := 0; k < len(per); k++ {
		tmp = per[k]
		per[k] = per[len(per)-k-1]
		per[len(per)-k-1] = tmp
	}
	return false
}

func nextBits(b []bool) bool {
	for i := 0; i < len(b); i++ {
		if b[i] {
			b[i] = false
		} else {
			b[i] = true
			return true
		}
	}
	return false
}

type Scnr struct {
	ins    *os.File
	buffer []byte
	ptr    int
	buflen int
}

func NewScnr() *Scnr {
	return &Scnr{ins: os.Stdin}
}

func (sc *Scnr) hasNextByte() bool {
	if sc.ptr < sc.buflen {
		return true
	} else {
		sc.ptr = 0
		var err error
		sc.buflen, err = sc.ins.Read(sc.buffer)
		if err != nil {
			return false
		}
		if sc.buflen <= 0 {
			return false
		}
	}
	return true
}

func (sc *Scnr) readByte() int {
	if sc.hasNextByte() {
		return int(sc.buffer[sc.ptr])
	} else {
		return -1
	}
}

func isPrintableChar(c int) bool {
	return 33 <= c && c <= 126
}

func (sc *Scnr) hasNext() bool {
	for sc.hasNextByte() && !isPrintableChar(sc.buffer[sc.ptr]) {
		sc.ptr++
	}
	return sc.hasNextByte()
}

func (sc *Scnr) next() string {
	return sc.nextBuilder().String()
}

func (sc *Scnr) nextBuilder() *strings.Builder {
	if !sc.hasNext() {
		panic("NoSuchElementException")
	}
	sb := &strings.Builder{}
	b := sc.readByte()
	for isPrintableChar(b) {
		sb.WriteByte(byte(b))
		b = sc.readByte()
	}
	return sb
}

func (sc *Scnr) nextInt() int {
	nl := sc.nextLong()
	if nl < math.MinInt32 || nl > math.MaxInt32 {
		panic("NumberFormatException")
	}
	return int(nl)
}

func (sc *Scnr) nextLong() int64 {
	if !sc.hasNext() {
		panic("NoSuchElementException")
	}
	var n int64
	var minus bool
	b := sc.readByte()
	if b == '-' {
		minus = true
		b = sc.readByte()
	}
	if b < '0' || b > '9' {
		panic("NumberFormatException")
	}
	for {
		if '0' <= b && b <= '9' {
			n = n*10 + int64(b-'0')
		} else if b == -1 || !isPrintableChar(b) {
			if minus {
				return -n
			}
			return n
		} else {
			panic("NumberFormatException")
		}
		b = sc.readByte()
	}
}

func main() {
	sc := NewScnr()
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	for i := sc.nextInt(); i > 0; i-- {
		solve(sc, out)
	}
}

func solve(sc *Scnr, out *bufio.Writer) {
	n := sc.nextInt()
	dq := make([]int, n)
	for i := 0; i < n; i++ {
		dq[i] = sc.nextInt()
	}
	a := dq[0]
	b := 0
	pre := a
	now := 0
	cnt := 1
	for len(dq) > 0 {
		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[len(dq)-1]
			dq = dq[:len(dq)-1]
		}
		if now != 0 {
			b += now
			pre = now
			cnt++
		}
		if len(dq) == 0 {
			break
		}
		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[0]
			dq = dq[1:]
		}
		if now != 0 {
			a += now
			pre = now
			cnt++
		}
	}
	fmt.Fprintf(out, "%d %d %d\n", cnt, a, b)
}
