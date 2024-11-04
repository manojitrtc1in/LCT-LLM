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
	mMsg string
}

func NewScopeTimer(msg string) *ScopeTimer {
	return &ScopeTimer{
		tic:  time.Now(),
		mMsg: msg,
	}
}

func (st *ScopeTimer) String() string {
	toc := time.Now()
	dt := toc.Sub(st.tic)

	mil := dt.Milliseconds() % 1000
	sec := (dt.Milliseconds() / 1000) % 60
	min := (dt.Milliseconds() / 60000) % 60
	hrs := (dt.Milliseconds() / 3600000)

	return fmt.Sprintf("%s\n\telapsed time: %d hrs, %d min, %d sec, %d mil-sec\n", st.mMsg, hrs, min, sec, mil)
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

func (c countInv) Apply(first, last []int64) int64 {
	cnt := int64(0)
	l := make([]int64, len(first))

	for n, v := range first {
		iter := sort.Search(len(l), func(i int) bool {
			return l[i] > v
		})

		cnt += int64(n)

		copy(l[iter+1:], l[iter:])
		l[iter] = v
	}

	return cnt
}

type id26 struct{}

func (i id26) Apply(first, last []int64, val int64) {
	for n := range first {
		first[n] = val
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

func (i id6) Apply(x, y int64) int64 {
	return i.second[x] - i.second[y]
}

type id12 struct {
	comp func(int64, int64) bool
}

func (i id12) Apply(x, y []int64) bool {
	return i.comp(x[0], y[0])
}

type Erase struct{}

func (e Erase) Apply(str *string, ch byte) {
	*str = strings.ReplaceAll(*str, string(ch), "")
}

type id25 struct{}

func (i id25) Apply(x int64) string {
	return fmt.Sprintf("%d", x)
}

type id0 struct{}

func (i id0) Apply(str string) int64 {
	var val int64
	fmt.Sscanf(str, "%d", &val)
	return val
}

type Tokenize struct{}

func (t Tokenize) Apply(str string, sep byte) []string {
	return strings.Split(str, string(sep))
}

type Chunk struct{}

func (c Chunk) Apply(first, last string, k int, id7 bool) []string {
	strList := []string{}

	if id7 {
		for i, j := len(last), len(last); j != 0; j = i {
			i = len(first) - k
			if i < j {
				strList = append(strList, first[i:j])
			}
		}
	} else {
		for i, j := 0, 0; i != len(last); i = j {
			j = i + k
			if j < len(last) {
				strList = append(strList, first[i:j])
			}
		}
	}

	return strList
}

type id21 struct{}

func (i id21) Apply(word []string) []map[rune]int {
	tree := []map[rune]int{{}}
	for _, w := range word {
		root := 0
		for _, a := range w {
			ref, ok := tree[root][a]
			if !ok {
				ref = len(tree)
				tree = append(tree, map[rune]int{})
				tree[root][a] = ref
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

func (i id18) Apply(n int64, fac map[int64]int64) {
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

func (a absdiff) Apply(x, y int64) int64 {
	if x < y {
		return y - x
	}
	return x - y
}

type id29 struct{}

func (i id29) Apply(a int64) bool {
	p := []int64{
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
		79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
		163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
		241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331,
		337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
		431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
		521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613,
		617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709,
		719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821,
		823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919,
		929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,
	}

	n := len(p)

	if a < p[n-1]+1 {
		for _, v := range p {
			if v == a {
				return true
			}
		}
		return false
	}

	for _, v := range p {
		if a%v == 0 {
			return false
		}
	}

	k := 7
	for j := 0; j < k; j++ {
		if powmod(p[j], a-1, a) != 1 {
			return false
		}
	}

	return true
}

type id24 struct{}

func (i id24) Apply(n int64) []int64 {
	primes := []int64{}

	for k := int64(2); k <= n; k++ {
		if id29{}.Apply(k) {
			primes = append(primes, k)
		}
	}

	return primes
}

type id1 struct {
	adj  [][]int
	tag  []bool
	npair int
	NIL  int
	INF  int
	g1   []int
	dist []int
	pair []int
}

func NewID1(adj [][]int, tag []bool) *id1 {
	return &id1{
		adj:  adj,
		tag:  tag,
		npair: 0,
		NIL:  len(adj),
		INF:  len(adj) + 1,
		g1:   []int{},
		dist: make([]int, len(adj)+1),
		pair: make([]int, len(adj)),
	}
}

func (i *id1) GetNPair() int {
	return i.npair
}

func (i *id1) GetMap() map[int]int {
	m := make(map[int]int)

	for j := 0; j < len(i.pair); j++ {
		if i.pair[j] != i.NIL && i.tag[j] {
			m[j] = i.pair[j]
		}
	}

	return m
}

func (i *id1) MfBreadthFirstSearch() bool {
	id11 := []int{}

	for _, v := range i.g1 {
		if i.pair[v] == i.NIL {
			i.dist[v] = 0
			id11 = append(id11, v)
		} else {
			i.dist[v] = i.INF
		}
	}

	i.dist[i.NIL] = i.INF

	for len(id11) > 0 {
		v := id11[0]
		id11 = id11[1:]

		if i.dist[v] < i.dist[i.NIL] {
			for _, u := range i.adj[v] {
				if i.dist[i.pair[u]] == i.INF {
					i.dist[i.pair[u]] = i.dist[v] + 1
					id11 = append(id11, i.pair[u])
				}
			}
		}
	}

	return i.dist[i.NIL] != i.INF
}

func (i *id1) MfDepthFirstSearch(v int) bool {
	if v == i.NIL {
		return true
	}

	for _, u := range i.adj[v] {
		if i.dist[i.pair[u]] == i.dist[v]+1 && i.MfDepthFirstSearch(i.pair[u]) {
			i.pair[u] = v
			i.pair[v] = u
			return true
		}
	}

	i.dist[v] = i.INF
	return false
}

func main() {
	rand.Seed(time.Now().UnixNano())

	fmt.Println(a176())
}
