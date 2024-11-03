package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"strings"
	"time"
)

type int64 int64
type uint64 uint64

func throwRuntimeError(msg string) {
	panic(msg)
}

type X struct{}

type ScopeTimer struct {
	tic  time.Time
	msg  string
}

func NewScopeTimer(msg string) *ScopeTimer {
	return &ScopeTimer{
		tic:  time.Now(),
		msg:  msg,
	}
}

func (st *ScopeTimer) String() string {
	toc := time.Now()
	dt := toc.Sub(st.tic)

	mil := dt.Milliseconds() % 1000
	sec := (dt.Milliseconds() / 1000) % 60
	min := (dt.Milliseconds() / 60000) % 60
	hrs := (dt.Milliseconds() / 3600000)

	return fmt.Sprintf("%s\n\telapsed time: %d hrs, %d min, %d sec, %d mil-sec\n", st.msg, hrs, min, sec, mil)
}

type absDiff struct{}

func (ad absDiff) Apply(x, y int64) int64 {
	if x < y {
		return y - x
	}
	return x - y
}

type isin struct {
	vals []int64
}

func (i isin) Apply(x int64) bool {
	for _, v := range i.vals {
		if v == x {
			return true
		}
	}
	return false
}

type Apply2nd struct {
	binaryOp func(int64, int64) int64
}

func (a Apply2nd) Apply(x, y int64) int64 {
	return a.binaryOp(x, y)
}

type countInv struct{}

func (ci countInv) Apply(first, last []int64) int64 {
	cnt := int64(0)
	l := make([]int64, len(first))

	for n, v := range first {
		iter := sort.Search(len(l), func(i int) bool {
			return l[i] > v
		})

		cnt += int64(n)

		for i := len(l) - 1; i >= iter; i-- {
			l[i] = l[i-1]
		}
		l[iter] = v
	}

	return cnt
}

type id26 struct{}

func (id id26) Apply(first, last []int64, val int64) {
	for i := range first {
		first[i] = val
		val++
	}
}

type Remove struct{}

func (r Remove) Apply(first, last, begin, end []int64) []int64 {
	result := first[:0]

	for _, v := range first {
		found := false
		for _, b := range begin {
			if v == b {
				found = true
				break
			}
		}

		if !found {
			result = append(result, v)
		}
	}

	return result
}

type id6 struct {
	first  []int64
	second []int64
}

func (id id6) Apply(i, j int64) int64 {
	return id.second[i] - id.second[j]
}

type id12 struct {
	comp func(int64, int64) bool
}

func (id id12) Apply(i, j []int64) bool {
	return id.comp(i[0], j[0])
}

type id17 struct {
	chrs []int64
}

func (id id17) Apply(x int64) bool {
	for _, v := range id.chrs {
		if v == x {
			return true
		}
	}
	return false
}

type id25 struct{}

func (id id25) Apply(x int64) string {
	return fmt.Sprintf("%d", x)
}

type id0 struct{}

func (id id0) Apply(str string) int64 {
	var val int64
	_, err := fmt.Sscanf(str, "%d", &val)
	if err != nil {
		panic(err)
	}
	return val
}

type tokenize struct {
	sep string
}

func (t tokenize) Apply(str string) []string {
	return strings.Split(str, t.sep)
}

type chunk struct {
	first  string
	last   string
	k      int64
	id7    bool
	strList []string
}

func (c *chunk) Apply() {
	c.strList = make([]string, 0)

	if c.id7 {
		for i, j := len(c.last), len(c.last); j >= 0; j = i {
			i = len(c.first) + int(c.k)
			if i < j {
				c.strList = append(c.strList, c.last[i:j])
			} else {
				c.strList = append(c.strList, c.last[c.first:j])
			}
		}
	} else {
		for i, j := 0, 0; i < len(c.last); i = j {
			j = i + int(c.k)
			if j < len(c.last) {
				c.strList = append(c.strList, c.last[i:j])
			} else {
				c.strList = append(c.strList, c.last[i:len(c.last)])
			}
		}
	}
}

type erase struct {
	str  string
	ch   int64
	chrs []int64
}

func (e erase) Apply() string {
	if e.ch != 0 {
		return strings.ReplaceAll(e.str, string(e.ch), "")
	}

	for _, v := range e.chrs {
		e.str = strings.ReplaceAll(e.str, string(v), "")
	}

	return e.str
}

type id21 struct {
	word []string
}

func (id id21) Apply() []map[int64]int64 {
	tree := make([]map[int64]int64, 1)
	for _, w := range id.word {
		root := int64(0)
		for _, a := range w {
			ref := tree[root][int64(a)]
			if ref == 0 {
				ref = int64(len(tree))
				tree = append(tree, make(map[int64]int64))
			}
			root = ref
		}
	}
	return tree
}

type BigInteger struct {
	val int64
}

type gcd struct{}

func (g gcd) Apply(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return g.Apply(b, a%b)
}

type id18 struct{}

func (id id18) Apply(n int64, fac map[int64]int64) {
	for k := int64(2); n > 1; k++ {
		if n%k == 0 {
			ref := fac[k]
			for n%k == 0 {
				ref++
				n /= k
			}
			fac[k] = ref
		}
	}
}

type absdiff struct{}

func (ad absdiff) Apply(x, y int64) int64 {
	if x < y {
		return y - x
	}
	return x - y
}

type id2 struct{}

func (id id2) Apply(a, b int64) (int64, int64) {
	if a%b != 0 {
		x, y := id.Apply(b, a%b)
		return y, x - (a/b)*y
	}
	return 0, 1
}

type mini struct{}

func (m mini) Apply(args ...int64) int64 {
	if len(args) == 0 {
		panic("no arguments provided")
	}

	res := args[0]
	for _, val := range args[1:] {
		if val < res {
			res = val
		}
	}

	return res
}

type maxi struct{}

func (m maxi) Apply(args ...int64) int64 {
	if len(args) == 0 {
		panic("no arguments provided")
	}

	res := args[0]
	for _, val := range args[1:] {
		if val > res {
			res = val
		}
	}

	return res
}

type modinv struct{}

func (mi modinv) Apply(a, m int64) int64 {
	_, x := id2.Apply(a, m)

	if a*x%m != 1 {
		panic(fmt.Sprintf("%d is not coprime to %d", a, m))
	}

	return (m + x%m) % m
}

type isnan struct{}

func (isnan isnan) Apply(a float64) bool {
	return math.IsNaN(a)
}

type RandInt struct {
	m int
	f float64
}

func NewRandInt(a, b int) *RandInt {
	return &RandInt{
		m: a,
		f: float64(b-a) / float64(rand.MaxInt64),
	}
}

func (ri *RandInt) Apply() int {
	return ri.m + int(math.Ceil(ri.f*rand.Float64()))
}

type RandDouble struct {
	m float64
	f float64
}

func NewRandDouble(a, b float64) *RandDouble {
	return &RandDouble{
		m: a,
		f: (b - a) / float64(rand.MaxInt64),
	}
}

func (rd *RandDouble) Apply() float64 {
	return rd.m + rd.f*rand.Float64()
}

type Noisy struct {
	msg string
}

func NewNoisy(msg string) *Noisy {
	fmt.Printf(" Noisy ( %s )\t@ %p\n", msg, &Noisy{})
	return &Noisy{
		msg: msg,
	}
}

func (n *Noisy) Beep() {
	fmt.Printf(" beep ( %s )\t@ %p\n", n.msg, &Noisy{})
}

func (n *Noisy) BeepConst() {
	fmt.Printf(" const beep ( %s )\t@ %p\n", n.msg, &Noisy{})
}

type UnionFind struct {
	parent []int
	rank   []int
}

func NewUnionFind(n int) *UnionFind {
	parent := make([]int, n)
	rank := make([]int, n)

	for i := 0; i < n; i++ {
		parent[i] = i
	}

	return &UnionFind{
		parent: parent,
		rank:   rank,
	}
}

func (uf *UnionFind) Find(s int) int {
	if uf.parent[s] == s {
		return s
	}
	uf.parent[s] = uf.Find(uf.parent[s])
	return uf.parent[s]
}

func (uf *UnionFind) Union(i, j int) {
	i = uf.Find(i)
	j = uf.Find(j)

	if i != j {
		if uf.rank[i] < uf.rank[j] {
			uf.parent[i] = j
		} else {
			uf.parent[j] = i
			if uf.rank[i] == uf.rank[j] {
				uf.rank[i]++
			}
		}
	}
}

func refill(k int, left, right []tuple) int {
	comp := func(i, j int) bool {
		return right[i].Item1-right[i].Item0 < right[j].Item1-right[j].Item0
	}

	idx := make([]int, len(left))
	for i := range idx {
		idx[i] = i
	}

	heap := NewHeap(idx, comp)
	val := 0

	for !heap.Empty() && k > 0 {
		i := heap.Front().(int)
		heap.Pop()

		if left[i].Item0 < right[i].Item1 {
			w := min(k, left[i].Item2)
			k -= w
			val += w * (right[i].Item1 - left[i].Item0)
		}
	}

	return val
}

func a176() int {
	var n, m, k int
	fmt.Scan(&n, &m, &k)

	a := make([][]tuple, n)
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		fmt.Scan(&a[i])
	}

	val := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j {
				val = max(val, refill(k, a[i], a[j]))
			}
		}
	}

	return val
}

func main() {
	rand.Seed(time.Now().UnixNano())
	fmt.Println(a176())
}
