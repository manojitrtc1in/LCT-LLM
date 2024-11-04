package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

const (
	FAST_ALLOCATOR_MEMORY = 1e6
	MAXN                  = 3e5 + 42
)

var (
	allocatorPos    int
	allocatorMemory [FAST_ALLOCATOR_MEMORY]byte
)

func main() {
	initFunc()
	root := &Treap{t: 0, y: mrand(), prefixSum: 0, speed: 0, push: 0, minPrefixSumInSubtree: 0}
	root = merge(root, &Treap{t: 2e9, y: mrand(), prefixSum: 0, speed: 0, push: 0, minPrefixSumInSubtree: 0})
	q := readInt()
	for i := 0; i < q; i++ {
		t := readInt()
		if t == 1 {
			t := readInt()
			s := readInt()
			l, r := split(root, t)
			vr := id12(r)
			vl := id7(l)
			psum := vl.prefixSum + (t-vl.t)*vl.speed
			id5 := psum + (vr.t-t)*s
			vertexAdd(r, id5-vr.prefixSum)
			root = merge(l, merge(&Treap{t: t, y: mrand(), prefixSum: psum, speed: s, push: 0, minPrefixSumInSubtree: 0}, r))
		} else if t == 2 {
			t := readInt()
			l, tr := split(root, t)
			y, r := split(tr, t+1)
			vl := id7(l)
			vr := id12(r)
			id5 := vl.prefixSum + (vr.t-vl.t)*vl.speed
			vertexAdd(r, id5-vr.prefixSum)
			root = merge(l, r)
		} else {
			L := readInt()
			R := readInt()
			v := readInt()
			if v == 0 {
				fmt.Println(L)
				continue
			}
			l, yr := split(root, L)
			y, r := split(yr, R+1)
			if y == nil {
				fmt.Println(-1)
			} else {
				vl := id12(y)
				vr := id7(y)
				id13 := vl.prefixSum - v
				if y.minPrefixSumInSubtree > id13 {
					id5 := vr.prefixSum + (R-vr.t)*vr.speed
					if id5 > id13 {
						fmt.Println(-1)
					} else {
						fmt.Println(vr.t + float64(id13-vr.prefixSum)/float64(vr.speed))
					}
				} else {
					h := id2(y, id13)
					yl, yr := split(y, h.t)
					vyl := id7(yl)
					fmt.Println(vyl.t + float64(id13-vyl.prefixSum)/float64(vyl.speed))
					y = merge(yl, yr)
				}
			}
			root = merge(l, merge(y, r))
		}
	}
}

type Treap struct {
	left                  *Treap
	right                 *Treap
	t                     int
	y                     int
	prefixSum             int64
	speed                 int64
	push                  int64
	minPrefixSumInSubtree int64
}

func vertexAdd(a *Treap, push int64) {
	a.prefixSum += push
	a.minPrefixSumInSubtree += push
	a.push += push
}

func push(a *Treap) {
	push := a.push
	if push == 0 {
		return
	}
	if a.left != nil {
		vertexAdd(a.left, push)
	}
	if a.right != nil {
		vertexAdd(a.right, push)
	}
	a.push = 0
}

func smin(a *Treap) int64 {
	if a != nil {
		return a.minPrefixSumInSubtree
	}
	return INF
}

func recalc(a *Treap) {
	a.minPrefixSumInSubtree = min(smin(a.left), smin(a.right), a.prefixSum)
}

func merge(a, b *Treap) *Treap {
	if a == nil {
		return b
	}
	if b == nil {
		return a
	}
	if a.y < b.y {
		push(a)
		a.right = merge(a.right, b)
		recalc(a)
		return a
	} else {
		push(b)
		b.left = merge(a, b.left)
		recalc(b)
		return b
	}
}

func split(a *Treap, k int) (*Treap, *Treap) {
	if a == nil {
		return nil, nil
	}
	push(a)
	if a.t < k {
		l, r := split(a.right, k)
		a.right = l
		recalc(a)
		return a, r
	} else {
		l, r := split(a.left, k)
		a.left = r
		recalc(a)
		return l, a
	}
}

func id12(a *Treap) *Treap {
	push(a)
	if a.left == nil {
		return a
	}
	return id12(a.left)
}

func id7(a *Treap) *Treap {
	push(a)
	if a.right == nil {
		return a
	}
	return id7(a.right)
}

func id2(a *Treap, v int64) *Treap {
	push(a)
	if smin(a.left) <= v {
		return id2(a.left, v)
	}
	if a.prefixSum <= v {
		return a
	}
	return id2(a.right, v)
}

func min(a ...int64) int64 {
	minVal := a[0]
	for _, val := range a {
		if val < minVal {
			minVal = val
		}
	}
	return minVal
}

func id11(L int64) int64 {
	L += rand.Int63() % 4242
	for !isPrime(L) {
		L++
	}
	return L
}

func isPrime(n int64) bool {
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func id2(a *Treap, v int64) *Treap {
	push(a)
	if smin(a.left) <= v {
		return id2(a.left, v)
	}
	if a.prefixSum <= v {
		return a
	}
	return id2(a.right, v)
}

func id9(n int64) []pair {
	fac := factor(n)
	ret := make([]pair, 0)
	L := 0
	for L < len(fac) {
		R := L
		for R < len(fac) && fac[R] == fac[L] {
			R++
		}
		ret = append(ret, pair{fac[L], R - L})
		L = R
	}
	return ret
}

func factor(n int64) []int64 {
	ans := make([]int64, 0)
	for i := int64(2); i*i <= n; i++ {
		for n%i == 0 {
			ans = append(ans, i)
			n /= i
		}
	}
	if n != 1 {
		ans = append(ans, n)
	}
	return ans
}

func id0(n int64) []int64 {
	ret := make([]int64, 0)
	for i := int64(1); i*i <= n; i++ {
		if n%i == 0 {
			ret = append(ret, i)
			if i*i != n {
				ret = append(ret, n/i)
			}
		}
	}
	return ret
}

func id1(s string, n int) *id1 {
	mod := make([]int64, 0)
	pow := make([]int64, 0)
	hash := make([][]int64, 0)
	pows := make([][]int64, 0)
	for i := 0; i < n; i++ {
		mod = append(mod, id11(0))
		pow = append(pow, id11(0))
		hash = append(hash, []int64{0})
		pows = append(pows, []int64{1})
	}
	id1 := &id1{s: s, MOD: mod, POW: pow, hash: hash, pows: pows}
	for _, c := range s {
		id1 += string(c)
	}
	return id1
}

type id1 struct {
	s     string
	MOD   []int64
	POW   []int64
	hash  [][]int64
	pows  [][]int64
}

func (id1 *id1) substr(L, n int) string {
	return id1.s[L : L+n]
}

func (id1 *id1) size() int {
	return len(id1.s)
}

func (id1 *id1) getHash(L, R int) []int64 {
	ret := make([]int64, 0)
	for i := 0; i < len(id1.hash); i++ {
		ret = append(ret, nmod(id1.hash[i][R]-id1.hash[i][L]*id1.pows[i][R-L], id1.MOD[i]))
	}
	return ret
}

func (id1 *id1) equal(L1, R1, L2, R2 int) bool {
	return reflect.DeepEqual(id1.getHash(L1, R1), id1.getHash(L2, R2))
}

func (id1 *id1) addChar(c byte) {
	id1.s += string(c)
	for i := 0; i < len(id1.hash); i++ {
		m := id1.MOD[i]
		p := id1.POW[i]
		cp := id1.pows[i][len(id1.pows[i])-1]
		cm := id1.hash[i][len(id1.hash[i])-1]
		cm = (cm*p + int64(c)) % m
		cp = cp * p % m
		id1.hash[i] = append(id1.hash[i], cm)
		id1.pows[i] = append(id1.pows[i], cp)
	}
}

func (id1 *id1) addString(oth string) {
	for _, c := range oth {
		id1.addChar(byte(c))
	}
}

type pair struct {
	first  int64
	second int
}

var (
	id3 = 0
)

func writeChar(x int) {
	if id3 == buf_size {
		os.Stdout.Write(write_buf)
		id3 = 0
	}
	write_buf[id3] = byte(x)
	id3++
}

func flush() {
	if id3 > 0 {
		os.Stdout.Write(write_buf[:id3])
		id3 = 0
	}
}

func writeInt(x int64, end byte, outputLen int) {
	if x < 0 {
		writeChar('-')
		x = -x
	}

	s := strconv.FormatInt(x, 10)
	for len(s) < outputLen {
		s = "0" + s
	}
	for i := len(s) - 1; i >= 0; i-- {
		writeChar(int(s[i]) - '0')
	}
	if end != 0 {
		writeChar(int(end))
	}
}

func writeWord(s string) {
	for _, c := range s {
		writeChar(int(c))
	}
}

func writeDouble(x float64, outputLen int) {
	if x < 0 {
		writeChar('-')
		x = -x
	}
	t := int(x)
	writeInt(int64(t), 0, 0)
	x -= float64(t)
	writeChar('.')
	for i := outputLen - 1; i > 0; i-- {
		x *= 10
		t := int(x)
		writeChar(int('0') + t)
		x -= float64(t)
	}
	x *= 10
	t := int(x + 0.5)
	writeChar(int('0') + t)
}

func initFunc() {
	allocatorPos = 0
	allocatorMemory = [FAST_ALLOCATOR_MEMORY]byte{}
}

func operatorNew(n int) *byte {
	res := &allocatorMemory[allocatorPos]
	allocatorPos += n
	return res
}

func operatorDelete(p *byte) {
}

func readString() string {
	return readWord()
}

func id8() bool {
	if buf_pos == buf_len {
		buf_pos = 0
		buf_len = read(buf[:])
		if buf_pos == buf_len {
			return true
		}
	}
	return false
}

func getChar() int {
	if id8() {
		return -1
	}
	return int(buf[buf_pos])
}

func peekChar() int {
	if id8() {
		return -1
	}
	return int(buf[buf_pos])
}

func id6() bool {
	c := peekChar()
	for c != -1 && c <= 32 {
		buf_pos++
		c = peekChar()
	}
	return c == -1
}

func id10() {
	for !id8() && buf[buf_pos] <= 32 {
		buf_pos++
	}
}

func readChar() int {
	c := getChar()
	for c != -1 && c <= 32 {
		c = getChar()
	}
	return c
}

func readUInt() int {
	c := readChar()
	x := 0
	for '0' <= c && c <= '9' {
		x = x*10 + c - '0'
		c = getChar()
	}
	return x
}

func readInt() int {
	s := 1
	c := readChar()
	x := 0
	if c == '-' {
		s = -1
		c = getChar()
	} else if c == '+' {
		c = getChar()
	}
	for '0' <= c && c <= '9' {
		x = x*10 + c - '0'
		c = getChar()
	}
	return s * x
}

func readDouble() float64 {
	s := 1
	c := readChar()
	x := 0
	if c == '-' {
		s = -1
		c = getChar()
	} else if c == '+' {
		c = getChar()
	}
	for '0' <= c && c <= '9' {
		x = x*10 + c - '0'
		c = getChar()
	}
	if c == '.' {
		c = getChar()
		coef := 1.0
		for '0' <= c && c <= '9' {
			x += (c - '0') * int(coef)
			coef *= 1e-1
			c = getChar()
		}
	}
	return float64(s * x)
}

func readWord() string {
	c := readChar()
	var sb strings.Builder
	for c > 32 {
		sb.WriteByte(byte(c))
		c = getChar()
	}
	return sb.String()
}

func readLine() string {
	c := getChar()
	var sb strings.Builder
	for c != '\n' && c != -1 {
		sb.WriteByte(byte(c))
		c = getChar()
	}
	return sb.String()
}

func nmod(a, m int64) int64 {
	return (a%m + m) % m
}

func mrand() int {
	return abs((1*rand.Intn(1<<15) + rand.Intn(1<<15)))
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
