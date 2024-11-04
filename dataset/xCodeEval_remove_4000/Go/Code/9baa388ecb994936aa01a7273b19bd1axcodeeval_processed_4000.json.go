



package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
func diff(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}
func larger(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func smaller(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func largest(a, b, c int) (lgst int) {
	if a > b {
		lgst = a
	} else {
		lgst = b
	}
	if c > lgst {
		lgst = c
	}
	return
}
func smallest(a, b, c int) (slst int) {
	if a < b {
		slst = a
	} else {
		slst = b
	}
	if c < slst {
		slst = c
	}
	return
}
func intsMax(a []int) (val int) {
	if len(a) == 0 {
		panic("func intsMax: zero length slice")
	}
	val = a[0]
	for _, aa := range a {
		if aa > val {
			val = aa
		}
	}
	return
}
func id32(a []int) (idx, val int) {
	if len(a) == 0 {
		panic("func id32: zero length slice")
	}
	val = a[0]
	for i, aa := range a {
		if aa > val {
			idx, val = i, aa
		}
	}
	return
}
func intsMin(a []int) (val int) {
	if len(a) == 0 {
		panic("func intsMin: zero length slice")
	}
	val = a[0]
	for _, aa := range a {
		if aa < val {
			val = aa
		}
	}
	return
}
func id36(a []int) (idx, val int) {
	if len(a) == 0 {
		panic("func id36: zero length slice")
	}
	val = a[0]
	for i, aa := range a {
		if aa < val {
			idx, val = i, aa
		}
	}
	return
}
func intsSum(a []int) int {
	res := 0
	for _, v := range a {
		res += v
	}
	return res
}
func intsAve(s []int) float64 {
	return float64(intsSum(s)) / float64(len(s))
}
func intsAdd(a *[]int, x int)    { *a = append(*a, x) }
func intsDelete(a *[]int, i int) { *a = append((*a)[:i], (*a)[i+1:]...) }
func intsJoin(a, b []int) []int  { return append(a, b...) }
func intsClear(a []int) []int    { return a[:0] }
func intsCopy(a []int) []int     { return append([]int(nil), a...) }
func id28(a []int) []int {
	s := intsCopy(a)
	sort.Ints(s)
	return s
}
func id4(a []int) []int {
	s := intsCopy(a)
	sort.Sort(sort.Reverse(sort.IntSlice(s)))
	return s
}
func intsReverse(a []int) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}
func intsFill(a []int, val int) {
	for i := 0; i < len(a); i++ {
		a[i] = val
	}
}
func id26(a []int) int {
	if len(a) == 0 {
		panic("func peekBack: zero length slice")
	}
	return a[len(a)-1]
}
func id15(a []int) int {
	if len(a) == 0 {
		panic("func peekFront: zero length slice")
	}
	return a[0]
}
func id38(a *[]int) int {
	if len(*a) == 0 {
		panic("func popBack: zero length slice")
	}
	t := (*a)[len(*a)-1]
	*a = (*a)[:len(*a)-1]
	return t
}
func id7(a *[]int) int {
	if len(*a) == 0 {
		panic("func popFront: zero length slice")
	}
	h := (*a)[0]
	*a = (*a)[1:]
	return h
}
func id33(a *[]int, x int) { *a = append(*a, x) }
func id13(a *[]int, x int) {
	*a = append(*a, 0)
	copy((*a)[1:], (*a)[0:])
	(*a)[0] = x
}
func id30(a *[]int, sentinel int) { id13(a, sentinel) }
func id34(a *[]int, sentinel int) { id33(a, sentinel) }
func id8(a *[]int, sentinel int) {
	id13(a, sentinel)
	id33(a, sentinel)
}
func id5(n int) []int {
	as := make([]int, n)
	for i := range as {
		as[i] = i
	}
	return as
}
func id29(a []int) bool {
	m := make(map[int]bool, len(a))
	for _, aa := range a {
		if _, exists := m[aa]; exists {
			return true
		} else {
			m[aa] = true
		}
	}
	return false
}
func isEven(n int) bool     { return n&1 == 0 }
func isOdd(n int) bool      { return n&1 == 1 }
func floor(x float64) int   { return int(x) }
func ceil(x float64) int    { return int(math.Ceil(x)) }
func ceilDiv(x, y int) int  { return ((x) + (y) - 1) / (y) }
func floorDiv(x, y int) int { return (x) / (y) }
func pow(x, y int) int {
	if y < 0 {
		panic("Exponent must be a natural number")
	}
	z := 1
	for ; y != 0; y >>= 1 {
		if y&1 == 1 {
			z *= x
		}
		x *= x
	}
	return z
}
func fact(x int) int {
	fact := 1
	for i := 1; i <= x; i++ {
		fact *= i
	}
	return fact
}
func sigmaK(n int) int  { return n * (n + 1) / 2 }
func sigmaKK(n int) int { return (n * (n + 1) / 2) * (2*n + 1) / 3 }
func id21(a, b point) float64 {
	s := diff(a.x, b.x)
	s *= s
	t := diff(a.y, b.y)
	t *= t
	return math.Sqrt(float64(s) + float64(t))
}
func id19(a, b point) int {
	s := diff(a.x, b.x)
	t := diff(a.y, b.y)
	return s + t
}
func swap(a, b *int) { *a, *b = *b, *a }
func chmax(a *int, b int) bool {
	if *a < b {
		*a = b
		return true
	}
	return false
}
func chmin(a *int, b int) bool {
	if *a > b {
		*a = b
		return true
	}
	return false
}
func id2(a []int) []int {
	b := append([]int{0}, a...)
	for i := 1; i < len(b); i++ {
		b[i] += b[i-1]
	}
	return b
}
func bytesReverse(a []byte) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}
func id10(s string) bool {
	if len(s) != 1 {
		panic("wrong arg")
	}
	t := s[0]
	return 'A' <= t && t <= 'Z'
}
func id9(s string) bool {
	if len(s) != 1 {
		panic("wrong arg")
	}
	t := s[0]
	return 'a' <= t && t <= 'z'
}
func id16(s string) string { return strings.ToUpper(s) }
func id24(s string) string { return strings.ToLower(s) }
func id39(s string) int {
	if len(s) != 1 {
		panic("wrong arg")
	}
	t := s[0]
	if !('A' <= t && t <= 'Z') {
		panic("arg must be upper case alphabet")
	}
	return int(t - 'A')
}
func id17(s string) int {
	if len(s) != 1 {
		panic("wrong arg")
	}
	t := s[0]
	if !('a' <= t && t <= 'z') {
		panic("arg must be lower case alphabet")
	}
	return int(t - 'a')
}
func id3(alphaLower string) (id11 [26]int) {
	ct := [26]int{}
	for _, ss := range alphaLower {
		if !('a' <= ss && ss <= 'z') {
			panic("func id3: argument must be lowercase string")
		}
		ct[ss-'a']++
	}
	return ct
}
func id1(alphaUpper string) (id11 [26]int) {
	ct := [26]int{}
	for _, ss := range alphaUpper {
		if !('A' <= ss && ss <= 'Z') {
			panic("func id1: argument must be uppercase string")
		}
		ct[ss-'A']++
	}
	return ct
}
func strReverse(s string) string {
	r := []rune(s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}
func id27(r rune) bool { return 'A' <= r && r <= 'Z' }
func id14(r rune) bool { return 'a' <= r && r <= 'z' }
func id0(a []rune) {
	for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
		a[i], a[j] = a[j], a[i]
	}
}
func id18(s string) int {
	i, err := strconv.Atoi(s)
	if err != nil {
		panic(err)
	}
	return i
}
func id31(i int) string     { return strconv.Itoa(i) }
func CalcMod(a, mod int) int    { return (a%mod + mod) % mod }
func ModSum(a *int, b, mod int) { *a = (((*a) % mod) + mod + (b % mod)) % mod }
func ModMul(a *int, b, mod int) { *a = (((*a) % mod) * (b % mod)) % mod }
func ModPow(x, y, mod int) int {
	if y < 0 {
		panic("Exponent must be a natural number")
	}
	z := 1
	for ; y != 0; y >>= 1 {
		if y&1 == 1 {
			z = (z * x) % mod
		}
		x = (x * x) % mod
	}
	return z
}
func ModFact(x, mod int) int {
	fact := 1
	for i := 1; i <= x; i++ {
		fact = fact * i % mod
	}
	return fact
}
func ModInv(x, mod int) int { return ModPow(x, mod-2, mod) }
func id35(parentSize, childSize int, initialValue bool) *[][]bool {
	res := make([][]bool, parentSize)
	for i := range res {
		res[i] = make([]bool, childSize)
		for j := range res[i] {
			res[i][j] = initialValue
		}
	}
	return &res
}
func id23(parentSize, childSize int, initialValue int) *[][]int {
	res := make([][]int, parentSize)
	for i := range res {
		res[i] = make([]int, childSize)
		for j := range res[i] {
			res[i][j] = initialValue
		}
	}
	return &res
}

var (
	sc = bufio.NewScanner(os.Stdin)
	bw = bufio.NewWriterSize(os.Stdout, bwBufSize)
)

func init() {
	sc.Split(bufio.ScanWords)
	sc.Buffer(make([]byte, 1e7), 1e7)
}
func ru() (n int) {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	for _, v := range sc.Bytes() {
		n = n*10 + int(v-48)
	}
	return
}
func ri() (n int) {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	b := sc.Bytes()
	neg := false
	if b[0] == 45 {
		neg = true
		b = b[1:]
	}
	for _, v := range b {
		n = n*10 + int(v-48)
	}
	if neg {
		n = -n
	}
	return
}
func ri64() (n int64) {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	b := sc.Bytes()
	neg := false
	if b[0] == 45 {
		neg = true
		b = b[1:]
	}
	for _, v := range b {
		n = n*10 + int64(v-48)
	}
	if neg {
		n = -n
	}
	return
}
func rf64() float64 {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	f, err := strconv.ParseFloat(sc.Text(), 64)
	if err != nil {
		panic(err)
	}
	return f
}
func rs() string {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	return sc.Text()
}
func rb() []byte {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	return sc.Bytes()
}
func rr() []rune {
	sc.Scan()
	if err := sc.Err(); err != nil {
		panic(err)
	}
	return []rune(sc.Text())
}
func ris(n int) []int {
	s := make([]int, n)
	for i := range s {
		s[i] = ri()
	}
	return s
}
func id20(n int) []int {
	s := make([]int, n)
	for i := range s {
		s[i] = ri() - 1
	}
	return s
}
func id6(n int) []int64 {
	s := make([]int64, n)
	for i := range s {
		s[i] = ri64()
	}
	return s
}
func riis(n int) ([]int, []int) {
	s := make([]int, n)
	t := make([]int, n)
	for i := range s {
		s[i] = ri()
		t[i] = ri()
	}
	return s, t
}
func rss(n int) []string {
	s := make([]string, n)
	for i := range s {
		s[i] = rs()
	}
	return s
}
func pf(format string, a ...interface{}) {
	if _, err := fmt.Fprintf(bw, format, a...); err != nil {
		panic(err)
	}
}
func pln(a ...interface{}) {
	if _, err := fmt.Fprintln(bw, a...); err != nil {
		panic(err)
	}
}
func pints(a []int) {
	for _, v := range a {
		fmt.Fprintln(bw, v)
	}
}
func id12(a []int) {
	s := fmt.Sprint(a)
	if _, err := fmt.Fprintln(bw, s[1:len(s)-1]); err != nil {
		panic(err)
	}
}
func dbg(a ...interface{}) {
	if _, err := fmt.Fprintln(os.Stderr, a...); err != nil {
		panic(err)
	}
}
func dbgMatrix(a [][]int) {
	for i := 0; i < len(a); i++ {
		dbg(a[i])
	}
}
func flush() {
	if err := bw.Flush(); err != nil {
		panic(err)
	}
}
func id25(b bool) string {
	if b {
		return "YES"
	} else {
		return "NO"
	}
}
func id37(b bool) string {
	if b {
		return "Yes"
	} else {
		return "No"
	}
}
func main() {
	solve()
	flush()
}

const (
	bwBufSize = 1e6

	alphabetLower = "abcdefghijklmnopqrstuvwxyz"
	alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

	

	

	

	inf = 1 << 60
	mod = 1e9 + 7
)

type pair struct{ fi, se int }
type byFiSe []pair

func (p byFiSe) Len() int      { return len(p) }
func (p byFiSe) Swap(i, j int) { p[i], p[j] = p[j], p[i] }
func (p byFiSe) Less(i, j int) bool {
	if p[i].fi == p[j].fi {
		return p[i].se < p[j].se
	}
	return p[i].fi < p[j].fi
}

type point struct{ x, y int }

type UnDirectedTree struct{ g [][]int }

func id22(size int) *UnDirectedTree { return &UnDirectedTree{g: make([][]int, size)} }
func (tr *UnDirectedTree) AddEdge(u, v int) {
	tr.g[u] = append(tr.g[u], v)
	tr.g[v] = append(tr.g[v], u)
}
func (tr *UnDirectedTree) DFS(r int) []int {
	ds := make([]int, len(tr.g))
	var f func(int, int, int)
	f = func(c, p, d int) {
		ds[c] = d
		for _, nv := range tr.g[c] {
			if nv == p {
				continue
			}
			f(nv, c, d+1)
		}
	}
	f(r, -1, 0)
	return ds
}

func solve() {
	n, x := ri(), ri()-1

	t := id22(n)
	for i := 0; i < n-1; i++ {
		a, b := ri()-1, ri()-1
		t.AddEdge(a, b)
	}

	distX := t.DFS(x)
	distA := t.DFS(0)

	distAtoZ := distA[x]
	q := []int{x}
	var now int
	isVisited := make([]bool, len(t.g))
	for len(q) != 0 {
		now, q = q[0], q[1:]
		isVisited[now] = true
		chmax(&distAtoZ, distA[now])
		for _, next := range t.g[now] {
			if isVisited[next] {
				continue
			}
			if !(distX[next] < distA[next]) {
				continue
			}
			q = append(q, next)
		}
	}

	pln(distAtoZ * 2)
}
