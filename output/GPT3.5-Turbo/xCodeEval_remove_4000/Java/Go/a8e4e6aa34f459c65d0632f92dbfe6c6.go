package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 998244353
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n, m, k int
	fmt.Fscan(reader, &n, &m, &k)

	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = pow(i, k)
	}

	ans := 0
	bc := newID1(n, k, true)
	for t := 0; t <= k; t++ {
		p1 := bc.get(t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := composite(t, i)
			contrib = mul(contrib, xk[t-i])
			if i%2 == 1 {
				contrib = valueOf(-contrib)
			}
			p2 = plus(p2, contrib)
		}
		p3 := inverse(t)

		contrib := mul(p1, p2)
		contrib = mul(contrib, p3)
		ans = plus(ans, contrib)
	}

	fmt.Fprintln(writer, ans)
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = mul(r, r)
	if n&1 == 1 {
		r = mul(r, x)
	}
	return r
}

func composite(m, n int) int {
	if n > m {
		return 0
	}
	return mul(mul(fact(m), invFact(n)), invFact(m-n))
}

func fact(n int) int {
	f := 1
	for i := 2; i <= n; i++ {
		f = mul(f, i)
	}
	return f
}

func invFact(n int) int {
	inv := make([]int, n+1)
	inv[1] = 1
	for i := 2; i <= n; i++ {
		k := mod / i
		r := mod % i
		inv[i] = mul(-k, inv[r])
	}
	return inv[n]
}

func inverse(n int) int {
	return pow(n, mod-2)
}

func plus(a, b int) int {
	c := a + b
	if c >= mod {
		c -= mod
	}
	return c
}

func mul(a, b int) int {
	return (a * b) % mod
}

func valueOf(x int) int {
	x %= mod
	if x < 0 {
		x += mod
	}
	return x
}

type id1 struct {
	m    int
	n    int64
	mod  int
	id8  []int
	fft  bool
}

func newID1(n int64, m int, fft bool) *id1 {
	id8 := pow(n)
	id8 = append(id8, make([]int, m+1)...)
	return &id1{
		m:    m,
		n:    n,
		mod:  mod,
		id8:  id8,
		fft:  fft,
	}
}

func (id *id1) get(i int) int {
	return id.id8[i]
}

func (id *id1) mul(a, b, c []int) {
	if !id.fft {
		polynomialsMul(a, b, c, id.mod)
	} else {
		ans := multiplyMod(a, b, id.mod)
		copy(c, ans)
	}
	trim(c)
}

func trim(x []int) {
	if len(x) > m+1 {
		x = x[:m+1]
	}
}

func (id *id1) pow(exp int64) []int {
	ceil := ceilLog(m + 1 + m)
	loop := []IntegerList{make(IntegerList, 1<<ceil), make(IntegerList, 1<<ceil)}
	loop[0][0] = 1
	for i := floorLog(exp); i >= 0; i-- {
		polynomialsMul(loop[0], loop[0], loop[1], id.mod)
		if 1 == bitAt(exp, i) {
			polynomialsMul(loop[0], loop[1], loop[0], id.mod)
		}
	}
	return loop[0]
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = mul(r, r)
	if n&1 == 1 {
		r = mul(r, x)
	}
	return r
}

func bitAt(x int64, i int) int {
	return int((x >> i) & 1)
}

func ceilLog(x int) int {
	ans := floorLog(x)
	if 1<<ans < x {
		ans++
	}
	return ans
}

func floorLog(x int) int {
	if x < 1<<16 {
		return cache[x]
	}
	return 16 + cache[x>>16]
}

func floorLog(x int64) int {
	ans := 0
	for x >= 1<<16 {
		ans += 16
		x >>= 16
	}
	return ans + cache[x]
}

func multiplyMod(a, b []int, m int) []int {
	need := len(a) + len(b) - 1
	n := 1 << ceilLog(need)

	aReal := make([]float64, n)
	aImag := make([]float64, n)
	for i := 0; i < len(a); i++ {
		x := (a[i]%m + m) % m
		aReal[i] = float64(x & ((1 << 15) - 1))
		aImag[i] = float64(x >> 15)
	}
	dft([][]float64{aReal, aImag}, floorLog(n))

	bReal := make([]float64, n)
	bImag := make([]float64, n)
	for i := 0; i < len(b); i++ {
		x := (b[i]%m + m) % m
		bReal[i] = float64(x & ((1 << 15) - 1))
		bImag[i] = float64(x >> 15)
	}
	dft([][]float64{bReal, bImag}, floorLog(n))

	faReal := make([]float64, n)
	faImag := make([]float64, n)
	fbReal := make([]float64, n)
	fbImag := make([]float64, n)

	for i := 0; i < n; i++ {
		j := (n - i) & (n - 1)

		id6 := (aReal[i] + aReal[j]) / 2
		id5 := (aImag[i] - aImag[j]) / 2
		id4 := (aImag[i] + aImag[j]) / 2
		id12 := (aReal[j] - aReal[i]) / 2

		id0 := (bReal[i] + bReal[j]) / 2
		id7 := (bImag[i] - bImag[j]) / 2
		id13 := (bImag[i] + bImag[j]) / 2
		id9 := (bReal[j] - bReal[i]) / 2

		faReal[i] = id6*id0 - id5*id7 - id4*id9 - id12*id13
		faImag[i] = id6*id7 + id5*id0 + id4*id13 - id12*id9

		fbReal[i] = id6*id13 - id5*id9 + id4*id0 - id12*id7
		fbImag[i] = id6*id9 + id5*id13 + id4*id7 + id12*id0
	}

	idft([][]float64{faReal, faImag}, floorLog(n))
	idft([][]float64{fbReal, fbImag}, floorLog(n))

	res := make([]int, need)
	for i := 0; i < need; i++ {
		aa := int(faReal[i] + 0.5)
		bb := int(fbReal[i] + 0.5)
		cc := int(faImag[i] + 0.5)
		res[i] = ((aa%m + (bb%m<<15) + (cc%m<<30)) % m)
	}
	return res
}

func dft(p [][]float64, m int) {
	n := 1 << m

	shift := 32 - bits.TrailingZeros(uint(n))
	for i := 1; i < n; i++ {
		j := bits.Reverse(uint(i << shift))
		if i < j {
			p[0][i], p[0][j] = p[0][j], p[0][i]
			p[1][i], p[1][j] = p[1][j], p[1][i]
		}
	}

	t := make([]float64, 2)
	for d := 0; d < m; d++ {
		s := 1 << d
		s2 := s << 1
		prepareLevel(d)
		for i := 0; i < n; i += s2 {
			for j := 0; j < s; j++ {
				a := i + j
				b := a + s
				mul(realLevels[d][j], imgLevels[d][j], p[0][b], p[1][b], t, 0)
				sub(p[0][a], p[1][a], t[0], t[1], p, b)
				add(p[0][a], p[1][a], t[0], t[1], p, a)
			}
		}
	}
}

func idft(p [][]float64, m int) {
	dft(p, m)

	n := 1 << m
	div(p[0][0], p[1][0], n, p, 0)
	div(p[0][n/2], p[1][n/2], n, p, n/2)
	for i := 1; i < n/2; i++ {
		a := p[0][n-i]
		b := p[1][n-i]
		div(p[0][i], p[1][i], n, p, n-i)
		div(a, b, n, p, i)
	}
}

func add(r1, i1, r2, i2 float64, r [][]float64, i int) {
	r[0][i] = r1 + r2
	r[1][i] = i1 + i2
}

func sub(r1, i1, r2, i2 float64, r [][]float64, i int) {
	r[0][i] = r1 - r2
	r[1][i] = i1 - i2
}

func mul(r1, i1, r2, i2 float64, r [][]float64, i int) {
	r[0][i] = r1*r2 - i1*i2
	r[1][i] = r1*i2 + i1*r2
}

func div(r1, i1 float64, r2 int, r [][]float64, i int) {
	r[0][i] = r1 / float64(r2)
	r[1][i] = i1 / float64(r2)
}

func prepareLevel(i int) {
	if realLevels[i] == nil {
		realLevels[i] = make([]float64, 1<<i)
		imgLevels[i] = make([]float64, 1<<i)
		for j := 0; j < 1<<i; j++ {
			realLevels[i][j] = math.Cos(math.Pi/float64(1<<i)*float64(j))
			imgLevels[i][j] = math.Sin(math.Pi/float64(1<<i)*float64(j))
		}
	}
}

func polynomialsMul(a, b, c []int, mod int) {
	rA := rankOf(a)
	rB := rankOf(b)
	c = make([]int, rA+rB+1)
	for i := 0; i <= rA; i++ {
		for j := 0; j <= rB; j++ {
			c[i+j] = plus(c[i+j], mul(a[i], b[j]))
		}
	}
}

func rankOf(p []int) int {
	r := len(p) - 1
	for r >= 0 && p[r] == 0 {
		r--
	}
	return max(0, r)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func bitAt(x int64, i int) int {
	return int((x >> i) & 1)
}

var (
	cache = [1 << 16]byte{}
)

func init() {
	b := 0
	for i := 0; i < 1<<16; i++ {
		for 1<<(b+1) <= i {
			b++
		}
		cache[i] = byte(b)
	}
}

type IntegerList []int

func (list IntegerList) expandWith(x, len int) {
	for len > cap(list) {
		list = append(list, x)
	}
	list = list[:len]
}

func (list IntegerList) clear() {
	list = list[:0]
}

func (list IntegerList) clone() IntegerList {
	return append(IntegerList{}, list...)
}

func (list IntegerList) remove(l, r int) {
	if l > r {
		return
	}
	copy(list[l:], list[r+1:])
	list = list[:len(list)-(r-l+1)]
}

func (list IntegerList) addAll(x []int) {
	list = append(list, x...)
}

func (list IntegerList) addAllOffset(x []int, offset, len int) {
	list = append(list, x[offset:offset+len]...)
}

func (list IntegerList) addAllList(other IntegerList) {
	list = append(list, other...)
}

func (list IntegerList) set(i, x int) {
	list[i] = x
}

func (list IntegerList) size() int {
	return len(list)
}

func (list IntegerList) toArray() []int {
	return append([]int{}, list...)
}

func (list IntegerList) String() string {
	return fmt.Sprint(list.toArray())
}

func (list IntegerList) equals(obj interface{}) bool {
	other, ok := obj.(IntegerList)
	if !ok {
		return false
	}
	if len(list) != len(other) {
		return false
	}
	for i := 0; i < len(list); i++ {
		if list[i] != other[i] {
			return false
		}
	}
	return true
}

func (list IntegerList) hashCode() int {
	h := 1
	for i := 0; i < len(list); i++ {
		h = h*31 + list[i]
	}
	return h
}

type Modular struct {
	m int
}

func (mod Modular) valueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod Modular) mul(x, y int) int {
	return mod.valueOf(x * y)
}

func (mod Modular) plus(x, y int) int {
	return mod.valueOf(x + y)
}

func (mod Modular) id2() Modular {
	return Modular{mod.m - 1}
}

type FastInput struct {
	reader *bufio.Reader
}

func newFastInput(r io.Reader) *FastInput {
	return &FastInput{reader: bufio.NewReader(r)}
}

func (in *FastInput) readInt() int {
	var x int
	fmt.Fscan(in.reader, &x)
	return x
}

type FastOutput struct {
	writer *bufio.Writer
}

func newFastOutput(w io.Writer) *FastOutput {
	return &FastOutput{writer: bufio.NewWriter(w)}
}

func (out *FastOutput) println(c int) {
	fmt.Fprintln(out.writer, c)
}

func (out *FastOutput) flush() {
	out.writer.Flush()
}

func main() {
	in := newFastInput(os.Stdin)
	out := newFastOutput(os.Stdout)
	defer out.flush()

	n := in.readInt()
	m := in.readInt()
	k := in.readInt()

	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = pow(i, k)
	}

	ans := 0
	bc := newID1(int64(n), k, true)
	for t := 0; t <= k; t++ {
		p1 := bc.get(t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := composite(t, i)
			contrib = mul(contrib, xk[t-i])
			if i%2 == 1 {
				contrib = valueOf(-contrib)
			}
			p2 = plus(p2, contrib)
		}
		p3 := inverse(t)

		contrib := mul(p1, p2)
		contrib = mul(contrib, p3)
		ans = plus(ans, contrib)
	}

	out.println(ans)
}
