package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	s1, _ := reader.ReadString('\n')
	s1 = strings.TrimSuffix(s1, "\n")
	s1Arr := strings.Split(s1, " ")
	n, _ := strconv.Atoi(s1Arr[0])
	k, _ := strconv.Atoi(s1Arr[1])

	s, _ := reader.ReadString('\n')
	s = strings.TrimSuffix(s, "\n")

	var stringBuilder strings.Builder

	if k == 0 {
		fmt.Println(s)
		os.Exit(0)
	}
	if n == 1 {
		if k >= 1 {
			stringBuilder.WriteString("0")
		} else {
			stringBuilder.WriteString(s)
		}
	} else {
		count := 0
		if s[0] != '1' {
			stringBuilder.WriteString("1")
			count++
		} else {
			stringBuilder.WriteString("1")
		}
		for i := 1; i < n; i++ {
			if count >= k {
				stringBuilder.WriteString(s[i:])
				break
			} else {
				if s[i] == '0' {
					stringBuilder.WriteString("0")
					continue
				} else {
					stringBuilder.WriteString("0")
					count++
				}
			}
		}
	}
	fmt.Println(stringBuilder.String())
}

type DSU struct {
	parent []int
	size   []int
}

func NewDSU(n int) *DSU {
	parent := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		parent[i] = -1
	}
	return &DSU{
		parent: parent,
		size:   size,
	}
}

func (d *DSU) makeSet(v int) {
	d.parent[v] = v
	d.size[v] = 1
}

func (d *DSU) findSet(v int) int {
	if v == d.parent[v] {
		return v
	}
	d.parent[v] = d.findSet(d.parent[v])
	return d.parent[v]
}

func (d *DSU) unionSets(a, b int) {
	a = d.findSet(a)
	b = d.findSet(b)
	if a != b {
		if d.size[a] < d.size[b] {
			temp := a
			a = b
			b = temp
		}
		d.parent[b] = a
		d.size[a] += d.size[b]
	}
}

type id18 struct{}

func (id18) fft(a, b []float64, invert bool) {
	count := len(a)
	for i, j := 1, 0; i < count; i++ {
		bit := count >> 1
		for j >= bit {
			j -= bit
			bit >>= 1
		}
		j += bit
		if i < j {
			temp := a[i]
			a[i] = a[j]
			a[j] = temp
			temp = b[i]
			b[i] = b[j]
			b[j] = temp
		}
	}
	for len := 2; len <= count; len <<= 1 {
		halfLen := len >> 1
		angle := 2 * math.Pi / float64(len)
		if invert {
			angle = -angle
		}
		id17 := math.Cos(angle)
		id2 := math.Sin(angle)
		for i := 0; i < count; i += len {
			wA := 1.0
			wB := 0.0
			for j := 0; j < halfLen; j++ {
				uA := a[i+j]
				uB := b[i+j]
				vA := a[i+j+halfLen]*wA - b[i+j+halfLen]*wB
				vB := a[i+j+halfLen]*wB + b[i+j+halfLen]*wA
				a[i+j] = uA + vA
				b[i+j] = uB + vB
				a[i+j+halfLen] = uA - vA
				b[i+j+halfLen] = uB - vB
				nextWA := wA*id17 - wB*id2
				wB = wA*id2 + wB*id17
				wA = nextWA
			}
		}
	}
	if invert {
		for i := 0; i < count; i++ {
			a[i] /= float64(count)
			b[i] /= float64(count)
		}
	}
}

func (id18) multiply(a, b []int64) []int64 {
	resultSize := 1 << uint(math.Max(float64(len(a)), float64(len(b)))) << 2
	resultSize = int(math.Max(float64(resultSize), 1))
	aReal := make([]float64, resultSize)
	id10 := make([]float64, resultSize)
	bReal := make([]float64, resultSize)
	id29 := make([]float64, resultSize)
	for i := 0; i < len(a); i++ {
		aReal[i] = float64(a[i])
	}
	for i := 0; i < len(b); i++ {
		bReal[i] = float64(b[i])
	}
	id18{}.fft(aReal, id10, false)
	id18{}.fft(bReal, id29, false)
	for i := 0; i < resultSize; i++ {
		real := aReal[i]*bReal[i] - id10[i]*id29[i]
		id10[i] = id10[i]*bReal[i] + id29[i]*aReal[i]
		aReal[i] = real
	}
	id18{}.fft(aReal, id10, true)
	result := make([]int64, resultSize)
	for i := 0; i < resultSize; i++ {
		result[i] = int64(math.Round(aReal[i]))
	}
	return result
}

type NumberTheory struct{}

func (NumberTheory) isPrime(n int64) bool {
	if n < 2 {
		return false
	}
	for x := int64(2); x*x <= n; x++ {
		if n%x == 0 {
			return false
		}
	}
	return true
}

func (NumberTheory) id26(n int64) []int64 {
	f := make([]int64, 0)
	for x := int64(2); x*x <= n; x++ {
		for n%x == 0 {
			f = append(f, x)
			n /= x
		}
	}
	if n > 1 {
		f = append(f, n)
	}
	return f
}

func (NumberTheory) id19(n int) []int {
	sieve := make([]int, n+1)
	for x := 2; x*x <= n; x++ {
		if sieve[x] != 0 {
			continue
		}
		for u := x * x; u <= n; u += x {
			if sieve[u] == 0 {
				sieve[u] = x
			}
		}
	}
	return sieve
}

func (NumberTheory) gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func (NumberTheory) phi(n int64) int64 {
	result := float64(n)
	for p := int64(2); p*p <= n; p++ {
		if n%p == 0 {
			for n%p == 0 {
				n /= p
			}
			result *= (1.0 - (1.0 / float64(p)))
		}
	}
	if n > 1 {
		result *= (1.0 - (1.0 / float64(n)))
	}
	return int64(result)
}

type Name struct {
	d int64
	x int64
	y int64
}

func (NumberTheory) id21(a, b int64) Name {
	if b == 0 {
		return Name{a, 1, 0}
	}
	n1 := id21(b, a%b)
	n2 := Name{n1.d, n1.y, n1.x - (a/b)*n1.y}
	return n2
}

func (NumberTheory) id22(a, b, n int64) int64 {
	d := int64(1)
	bString := strconv.FormatInt(b, 2)
	for i := 0; i < len(bString); i++ {
		d = (d * d) % n
		if bString[i] == '1' {
			d = (d * a) % n
		}
	}
	return d
}

type Hashing struct{}

func (Hashing) id8(p int64, n int, m int64) []int64 {
	powers := make([]int64, n)
	powers[0] = 1
	for i := 1; i < n; i++ {
		powers[i] = (powers[i-1] * p) % m
	}
	return powers
}

func (Hashing) computeHash(s string) int64 {
	p := int64(31)
	m := int64(1_000_000_009)
	hashValue := int64(0)
	powers := id8(p, len(s), m)
	for i := 0; i < len(s); i++ {
		ch := s[i]
		hashValue = (hashValue + (int64(ch-'a'+1)*powers[i])%m) % m
	}
	return hashValue
}

type BasicFunctions struct{}

func (BasicFunctions) min(A []int64) int64 {
	min := int64(1<<63 - 1)
	for i := 0; i < len(A); i++ {
		if A[i] < min {
			min = A[i]
		}
	}
	return min
}

func (BasicFunctions) max(A []int64) int64 {
	max := int64(1<<63 - 1)
	for i := 0; i < len(A); i++ {
		if A[i] > max {
			max = A[i]
		}
	}
	return max
}

type id25 struct{}

func (id25) merge(arr []int, l int, m int, r int) {
	n1 := m - l + 1
	n2 := r - m

	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[l+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[m+1+j]
	}

	i := 0
	j := 0
	k := l
	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}

	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func (id25) sort(arr []int, l int, r int) {
	if l < r {
		m := (l + r) / 2

		sort(arr, l, m)
		sort(arr, m+1, r)

		merge(arr, l, m, r)
	}
}

type id7 struct{}

func (id7) merge(arr []int64, l int, m int, r int) {
	n1 := m - l + 1
	n2 := r - m

	L := make([]int64, n1)
	R := make([]int64, n2)

	for i := 0; i < n1; i++ {
		L[i] = arr[l+i]
	}
	for j := 0; j < n2; j++ {
		R[j] = arr[m+1+j]
	}

	i := 0
	j := 0
	k := l
	for i < n1 && j < n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i < n1 {
		arr[k] = L[i]
		i++
		k++
	}

	for j < n2 {
		arr[k] = R[j]
		j++
		k++
	}
}

func (id7) sort(arr []int64, l int, r int) {
	if l < r {
		m := (l + r) / 2

		sort(arr, l, m)
		sort(arr, m+1, r)

		merge(arr, l, m, r)
	}
}

type Node struct {
	s string
}

type Trie struct {
	root *TrieNode
}

type TrieNode struct {
	children map[byte]*TrieNode
	isEnd    bool
}

func NewTrie() *Trie {
	return &Trie{
		root: &TrieNode{
			children: make(map[byte]*TrieNode),
			isEnd:    false,
		},
	}
}

func (t *Trie) Insert(word string) {
	current := t.root
	for i := 0; i < len(word); i++ {
		ch := word[i]
		node, ok := current.children[ch]
		if !ok {
			node = &TrieNode{
				children: make(map[byte]*TrieNode),
				isEnd:    false,
			}
			current.children[ch] = node
		}
		current = node
	}
	current.isEnd = true
}

func (t *Trie) Search(word string) bool {
	current := t.root
	for i := 0; i < len(word); i++ {
		ch := word[i]
		node, ok := current.children[ch]
		if !ok {
			return false
		}
		current = node
	}
	return current.isEnd
}

func (t *Trie) Delete(word string) {
	t.delete(t.root, word, 0)
}

func (t *Trie) delete(current *TrieNode, word string, index int) bool {
	if index == len(word) {
		if !current.isEnd {
			return false
		}
		current.isEnd = false
		return len(current.children) == 0
	}
	ch := word[index]
	node, ok := current.children[ch]
	if !ok {
		return false
	}
	id14 := t.delete(node, word, index+1)

	if id14 {
		delete(current.children, ch)
		return len(current.children) == 0
	}
	return false
}

type id15 struct{}

func (id15) id23(num int) int {
	if num == 0 {
		return 1
	}
	if num > 0 && (num&(num-1)) == 0 {
		return num
	}
	for num&(num-1) > 0 {
		num = num & (num - 1)
	}
	return num << 1
}

func (id15) id16(input []int) []int {
	np2 := id23(len(input))
	segmentTree := make([]int, np2*2-1)

	for i := 0; i < len(segmentTree); i++ {
		segmentTree[i] = int(^uint(0) >> 1)
	}

	id0(segmentTree, input, 0, len(input)-1, 0)
	return segmentTree
}

func id0(segmentTree []int, input []int, low int, high int, pos int) {
	if low == high {
		segmentTree[pos] = input[low]
		return
	}
	mid := (low + high) / 2
	id0(segmentTree, input, low, mid, 2*pos+1)
	id0(segmentTree, input, mid+1, high, 2*pos+2)
	segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2])
}

func (id15) id9(input []int, segmentTree []int, lazy []int, startRange int, endRange int, delta int) {
	id9(segmentTree, lazy, startRange, endRange, delta, 0, len(input)-1, 0)
}

func id9(segmentTree []int, lazy []int, startRange int, endRange int, delta int, low int, high int, pos int) {
	if low > high {
		return
	}
	if lazy[pos] != 0 {
		segmentTree[pos] += lazy[pos]
		if low != high {
			lazy[2*pos+1] += lazy[pos]
			lazy[2*pos+2] += lazy[pos]
		}
		lazy[pos] = 0
	}

	if startRange > high || endRange < low {
		return
	}

	if startRange <= low && endRange >= high {
		segmentTree[pos] += delta
		if low != high {
			lazy[2*pos+1] += delta
			lazy[2*pos+2] += delta
		}
		return
	}

	mid := (low + high) / 2
	id9(segmentTree, lazy, startRange, endRange, delta, low, mid, 2*pos+1)
	id9(segmentTree, lazy, startRange, endRange, delta, mid+1, high, 2*pos+2)
	segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2])
}

func (id15) id27(segmentTree []int, lazy []int, qlow int, qhigh int, len int) int {
	return id27(segmentTree, lazy, qlow, qhigh, 0, len-1, 0)
}

func id27(segmentTree []int, lazy []int, qlow int, qhigh int, low int, high int, pos int) int {
	if low > high {
		return int(^uint(0) >> 1)
	}
	if lazy[pos] != 0 {
		segmentTree[pos] += lazy[pos]
		if low != high {
			lazy[2*pos+1] += lazy[pos]
			lazy[2*pos+2] += lazy[pos]
		}
		lazy[pos] = 0
	}

	if qlow > high || qhigh < low {
		return int(^uint(0) >> 1)
	}

	if qlow <= low && qhigh >= high {
		return segmentTree[pos]
	}

	mid := (low + high) / 2
	return min(id27(segmentTree, lazy, qlow, qhigh, low, mid, 2*pos+1), id27(segmentTree, lazy, qlow, qhigh, mid+1, high, 2*pos+2))
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Your code here
}
