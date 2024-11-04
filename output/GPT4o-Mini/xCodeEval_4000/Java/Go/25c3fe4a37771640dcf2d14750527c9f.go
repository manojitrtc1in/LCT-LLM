package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var mod = int(math.Pow(10, 9) + 7)
var dx = []int{-1, 0, 1, 0}
var dy = []int{0, -1, 0, 1}
var dx8 = []int{-1, -1, -1, 0, 0, 1, 1, 1}
var dy8 = []int{-1, 0, 1, -1, 1, -1, 0, 1}
var dx9 = []int{-1, -1, -1, 0, 0, 0, 1, 1, 1}
var dy9 = []int{-1, 0, 1, -1, 0, 1, -1, 0, 1}

var eps = 1e-10
var primeNumbers []int

func main() {
	sc := NewScanner()
	str := sc.NextLine()
	inp := []rune(str)
	n := len(inp)

	pos := []string{"00", "25", "50", "75"}
	count := 0

	if len(inp) == 1 {
		if inp[0] == '0' || inp[0] == 'X' || inp[0] == '_' {
			count++
		}
	} else {
		for _, cstr := range pos {
			X := -1
			idx := 0
			possible := true
			for i := n - 2; i < n; i++ {
				curr := inp[i]
				strcurr := rune(cstr[idx])
				idx++

				if curr == '_' {
					continue
				} else if curr == 'X' {
					if X == -1 {
						X = int(strcurr - '0')
					} else {
						if X != int(strcurr-'0') {
							possible = false
							break
						}
					}
				} else {
					if curr != strcurr {
						possible = false
						break
					}
				}
			}

			if !possible {
				continue
			}

			if len(str) == 2 {
				if cstr[0] == '0' {
					continue
				}
				count++
				continue
			}

			ninp := make([]rune, len(inp))
			copy(ninp, inp)

			cntX := 0
			for _, ch := range inp {
				if ch == 'X' {
					cntX++
				}
			}

			if X != -1 || cntX == 0 {
				if X != -1 {
					for k := 0; k < len(str); k++ {
						ninp[k] = inp[k]
						if inp[k] == 'X' {
							ninp[k] = rune(X + '0')
						}
					}
				}

				if ninp[0] == '0' {
					continue
				}
				counter := 1
				for k := 0; k < len(str)-2; k++ {
					if ninp[k] == '_' {
						if k == 0 {
							counter *= 9
						} else {
							counter *= 10
						}
					}
				}

				count += counter
			} else {
				if ninp[0] == '0' {
					continue
				}

				counter := 1
				for k := 0; k < len(str)-2; k++ {
					if ninp[k] == '_' {
						if k == 0 {
							counter *= 9
						} else {
							counter *= 10
						}
					}
				}

				if ninp[0] == 'X' {
					counter *= 9
				} else {
					counter *= 10
				}

				count += counter
			}
		}
	}

	fmt.Println(count)
}

type Graph struct {
	V     int
	edges [][]int
}

func NewGraph(V int) *Graph {
	g := &Graph{V: V}
	g.edges = make([][]int, V+1)
	for i := 0; i <= V; i++ {
		g.edges[i] = []int{}
	}
	return g
}

func (g *Graph) AddEdge(from, to int) {
	g.edges[from] = append(g.edges[from], to)
	g.edges[to] = append(g.edges[to], from)
}

type DisjointUnionSets struct {
	rank   []int
	parent []int
	n      int
}

func NewDisjointUnionSets(n int) *DisjointUnionSets {
	dus := &DisjointUnionSets{
		rank:   make([]int, n),
		parent: make([]int, n),
		n:      n,
	}
	for i := 0; i < n; i++ {
		dus.rank[i] = 1
		dus.parent[i] = -1
	}
	return dus
}

func (dus *DisjointUnionSets) Find(curr int) int {
	if dus.parent[curr] == -1 {
		return curr
	}
	dus.parent[curr] = dus.Find(dus.parent[curr])
	return dus.parent[curr]
}

func (dus *DisjointUnionSets) Union(a, b int) {
	s1 := dus.Find(a)
	s2 := dus.Find(b)

	if s1 != s2 {
		if dus.rank[s1] < dus.rank[s2] {
			dus.parent[s1] = s2
			dus.rank[s2] += dus.rank[s1]
		} else {
			dus.parent[s2] = s1
			dus.rank[s1] += dus.rank[s2]
		}
	}
}

func powerMOD(x, y int64) int64 {
	res := int64(1)
	for y > 0 {
		if y&1 != 0 {
			x %= int64(mod)
			res %= int64(mod)
			res = (res * x) % int64(mod)
		}
		y >>= 1
		x %= int64(mod)
		x = (x * x) % int64(mod)
	}
	return res % int64(mod)
}

func power(x, y int64) int64 {
	res := int64(1)
	for y > 0 {
		if y&1 != 0 {
			res = (res * x)
		}
		y >>= 1
		x = (x * x)
	}
	return res
}

type SegmentTree struct {
	arr  []int64
	tree []int64
}

func NewSegmentTree(arr []int64) *SegmentTree {
	n := len(arr)
	st := &SegmentTree{arr: make([]int64, n), tree: make([]int64, 4*n+1)}
	copy(st.arr, arr)
	return st
}

func (st *SegmentTree) BuildTree(s, e, index int) {
	if s == e {
		st.tree[index] = st.arr[s]
		return
	}

	mid := (s + e) / 2
	st.BuildTree(s, mid, 2*index)
	st.BuildTree(mid+1, e, 2*index+1)

	st.tree[index] = min(st.tree[2*index], st.tree[2*index+1])
}

func (st *SegmentTree) Query(s, e, qs, qe, index int) int64 {
	if s >= qs && e <= qe {
		return st.tree[index]
	}

	if qe < s || qs > e {
		return math.MaxInt64
	}

	mid := (s + e) / 2
	left := st.Query(s, mid, qs, qe, 2*index)
	right := st.Query(mid+1, e, qs, qe, 2*index+1)

	return min(left, right)
}

func (st *SegmentTree) UpdateNode(s, e, i int64, increment int64, index int) {
	if i < int64(s) || i > int64(e) {
		return
	}

	if s == e {
		st.tree[index] += increment
		return
	}

	mid := (s + e) / 2
	st.UpdateNode(s, mid, i, increment, 2*index)
	st.UpdateNode(mid+1, e, i, increment, 2*index+1)

	st.tree[index] = min(st.tree[2*index], st.tree[2*index+1])
}

func (st *SegmentTree) UpdateRange(s, e, l, r int64, increment int64, index int) {
	if l > int64(e) || r < int64(s) {
		return
	}

	if s == e {
		st.tree[index] += increment
	}

	mid := (s + e) / 2
	st.UpdateRange(s, mid, l, r, increment, 2*index)
	st.UpdateRange(mid+1, e, l, r, increment, 2*index)
	st.tree[index] = min(st.tree[2*index], st.tree[2*index+1])
}

func primeSieve(n int) {
	bitset := make([]bool, n+1)
	for i := 0; i < n; i++ {
		if i == 0 || i == 1 {
			bitset[i] = true
			continue
		}
		if bitset[i] {
			continue
		}
		primeNumbers = append(primeNumbers, i)
		for j := i; j <= n; j += i {
			bitset[j] = true
		}
	}
}

func countDivisors(number int64) int {
	if number == 1 {
		return 1
	}
	primeFactors := []int{}
	index := 0
	curr := primeNumbers[index]
	for curr*curr <= number {
		for number%int64(curr) == 0 {
			number /= int64(curr)
			primeFactors = append(primeFactors, curr)
		}
		index++
		curr = primeNumbers[index]
	}

	if number != 1 {
		primeFactors = append(primeFactors, int(number))
	}
	current := primeFactors[0]
	totalDivisors := 1
	currentCount := 2
	for i := 1; i < len(primeFactors); i++ {
		if primeFactors[i] == current {
			currentCount++
		} else {
			totalDivisors *= currentCount
			currentCount = 2
			current = primeFactors[i]
		}
	}
	totalDivisors *= currentCount
	return totalDivisors
}

func primeExponentsCount(n int) int {
	if n <= 1 {
		return 0
	}
	sqrt := int(math.Sqrt(float64(n)))
	remainingNumber := n
	result := 0
	for i := 2; i <= sqrt; i++ {
		for remainingNumber%i == 0 {
			result++
			remainingNumber /= i
		}
	}

	if remainingNumber > 1 {
		result++
	}
	return result
}

func nextPermutation(p []int) bool {
	for a := len(p) - 2; a >= 0; a-- {
		if p[a] < p[a+1] {
			for b := len(p) - 1; ; b-- {
				if p[b] > p[a] {
					p[a], p[b] = p[b], p[a]
					for a++; b > a; a, b = a+1, b-1 {
						p[a], p[b] = p[b], p[a]
					}
					return true
				}
			}
		}
	}
	return false
}

func getNcR(n, r int) int64 {
	p := int64(1)
	k := int64(1)
	if n-r < r {
		r = n - r
	}

	if r != 0 {
		for r > 0 {
			p *= int64(n)
			k *= int64(r)
			m := gcd(p, k)
			p /= m
			k /= m
			n--
			r--
		}
	} else {
		p = 1
	}
	return p
}

func isVowel(c rune) bool {
	return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'
}

func sortInt(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortInt64(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func binomialCoeff(n, k int) int {
	C := make([]int, k+1)
	C[0] = 1
	for i := 1; i <= n; i++ {
		for j := min(i, k); j > 0; j-- {
			C[j] = C[j] + C[j-1]
		}
	}
	return C[k]
}

type Pair struct {
	a        int
	b        int
	hashCode int
}

func NewPair(a, b int) Pair {
	return Pair{a: a, b: b, hashCode: hash(a, b)}
}

func (p Pair) String() string {
	return fmt.Sprintf("%d -> %d", p.a, p.b)
}

func (p Pair) Equals(o interface{}) bool {
	if that, ok := o.(Pair); ok {
		return p.a == that.a && p.b == that.b
	}
	return false
}

func (p Pair) HashCode() int {
	return p.hashCode
}

type Triplet struct {
	a int
	b int
	c int
}

func NewTriplet(a, b, c int) Triplet {
	return Triplet{a: a, b: b, c: c}
}

func (t Triplet) String() string {
	return fmt.Sprintf("%d -> %d", t.a, t.b)
}

func lcm(a, b int64) int64 {
	return a * (b / gcd(a, b))
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func __gcd(n1, n2 int64) int64 {
	gcd := int64(1)
	for i := int64(1); i <= n1 && i <= n2; i++ {
		if n1%i == 0 && n2%i == 0 {
			gcd = i
		}
	}
	return gcd
}

func swapInt(arr []int, left, right int) {
	arr[left], arr[right] = arr[right], arr[left]
}

func swapRune(arr []rune, left, right int) {
	arr[left], arr[right] = arr[right], arr[left]
}

func reverse(arr []int) {
	left := 0
	right := len(arr) - 1

	for left <= right {
		swapInt(arr, left, right)
		left++
		right--
	}
}

func expo(a, b, mod int64) int64 {
	res := int64(1)
	for b > 0 {
		if (b & 1) == 1 {
			res = (res * a) % mod
		}
		a = (a * a) % mod
		b >>= 1
	}
	return res
}

func mminvprime(a, b int64) int64 {
	return expo(a, b-2, b)
}

func modAdd(a, b, m int64) int64 {
	a = a % m
	b = b % m
	return (((a + b) % m) + m) % m
}

func modSub(a, b, m int64) int64 {
	a = a % m
	b = b % m
	return (((a - b) % m) + m) % m
}

func modMul(a, b, m int64) int64 {
	a = a % m
	b = b % m
	return (((a * b) % m) + m) % m
}

func modDiv(a, b, m int64) int64 {
	a = a % m
	b = b % m
	return (modMul(a, mminvprime(b, m), m) + m) % m
}

func nCr(N, K, mod int64) int64 {
	upper := int64(1)
	lower := int64(1)
	lowerr := int64(1)

	for i := int64(1); i <= N; i++ {
		upper = modMul(upper, i, mod)
	}

	for i := int64(1); i <= K; i++ {
		lower = modMul(lower, i, mod)
	}

	for i := int64(1); i <= (N - K); i++ {
		lowerr = modMul(lowerr, i, mod)
	}

	answer := modMul(lower, lowerr, mod)
	answer = modDiv(upper, answer, mod)

	return answer
}

func combination(n, r, m int64, fact, ifact []int64) int64 {
	val1 := fact[n]
	val2 := ifact[n-r]
	val3 := ifact[r]
	return (((val1 * val2) % m) * val3) % m
}

type Scanner struct {
	scanner *bufio.Scanner
}

func NewScanner() *Scanner {
	return &Scanner{scanner: bufio.NewScanner(os.Stdin)}
}

func (s *Scanner) Next() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func (s *Scanner) NextInt() int {
	val, _ := strconv.Atoi(s.Next())
	return val
}

func (s *Scanner) NextLong() int64 {
	val, _ := strconv.ParseInt(s.Next(), 10, 64)
	return val
}

func (s *Scanner) NextDouble() float64 {
	val, _ := strconv.ParseFloat(s.Next(), 64)
	return val
}

func (s *Scanner) NextLine() string {
	s.scanner.Scan()
	return s.scanner.Text()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
