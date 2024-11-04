package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type DSU struct {
	parent []int
	size   []int
}

func NewDSU(n int) *DSU {
	dsu := &DSU{
		parent: make([]int, n),
		size:   make([]int, n),
	}
	for i := range dsu.parent {
		dsu.parent[i] = -1
	}
	return dsu
}

func (dsu *DSU) MakeSet(v int) {
	dsu.parent[v] = v
	dsu.size[v] = 1
}

func (dsu *DSU) FindSet(v int) int {
	if v == dsu.parent[v] {
		return v
	}
	dsu.parent[v] = dsu.FindSet(dsu.parent[v])
	return dsu.parent[v]
}

func (dsu *DSU) UnionSets(a, b int) {
	a = dsu.FindSet(a)
	b = dsu.FindSet(b)
	if a != b {
		if dsu.size[a] < dsu.size[b] {
			a, b = b, a
		}
		dsu.parent[b] = a
		dsu.size[a] += dsu.size[b]
	}
}

type FastFourierTransform struct{}

func (fft *FastFourierTransform) fft(a, b []float64, invert bool) {
	count := len(a)
	for i, j := 1, 0; i < count; i++ {
		bit := count >> 1
		for ; j >= bit; bit >>= 1 {
			j -= bit
		}
		j += bit
		if i < j {
			a[i], a[j] = a[j], a[i]
			b[i], b[j] = b[j], b[i]
		}
	}
	for len := 2; len <= count; len <<= 1 {
		halfLen := len >> 1
		angle := 2 * 3.141592653589793 / float64(len)
		if invert {
			angle = -angle
		}
		wLenA := cos(angle)
		wLenB := sin(angle)
		for i := 0; i < count; i += len {
			wA, wB := 1.0, 0.0
			for j := 0; j < halfLen; j++ {
				uA, uB := a[i+j], b[i+j]
				vA := a[i+j+halfLen]*wA - b[i+j+halfLen]*wB
				vB := a[i+j+halfLen]*wB + b[i+j+halfLen]*wA
				a[i+j] = uA + vA
				b[i+j] = uB + vB
				a[i+j+halfLen] = uA - vA
				b[i+j+halfLen] = uB - vB
				nextWA := wA*wLenA - wB*wLenB
				wB = wA*wLenB + wB*wLenA
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

func (fft *FastFourierTransform) Multiply(a, b []int64) []int64 {
	resultSize := highestOneBit(max(len(a), len(b))-1) << 2
	resultSize = max(resultSize, 1)
	aReal := make([]float64, resultSize)
	aImaginary := make([]float64, resultSize)
	bReal := make([]float64, resultSize)
	bImaginary := make([]float64, resultSize)
	for i := range a {
		aReal[i] = float64(a[i])
	}
	for i := range b {
		bReal[i] = float64(b[i])
	}
	fft.fft(aReal, aImaginary, false)
	fft.fft(bReal, bImaginary, false)
	for i := 0; i < resultSize; i++ {
		real := aReal[i]*bReal[i] - aImaginary[i]*bImaginary[i]
		aImaginary[i] = aImaginary[i]*bReal[i] + bImaginary[i]*aReal[i]
		aReal[i] = real
	}
	fft.fft(aReal, aImaginary, true)
	result := make([]int64, resultSize)
	for i := range result {
		result[i] = int64(round(aReal[i]))
	}
	return result
}

type NumberTheory struct{}

func (nt *NumberTheory) IsPrime(n int64) bool {
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

func (nt *NumberTheory) PrimeFactorisation(n int64) []int64 {
	factors := []int64{}
	for x := int64(2); x*x <= n; x++ {
		for n%x == 0 {
			factors = append(factors, x)
			n /= x
		}
	}
	if n > 1 {
		factors = append(factors, n)
	}
	return factors
}

func (nt *NumberTheory) SieveOfEratosthenes(n int) []int {
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

func (nt *NumberTheory) GCD(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return nt.GCD(b, a%b)
}

func (nt *NumberTheory) Phi(n int64) int64 {
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
	d, x, y int64
}

func (nt *NumberTheory) ExtendedEuclid(a, b int64) Name {
	if b == 0 {
		return Name{d: a, x: 1, y: 0}
	}
	n1 := nt.ExtendedEuclid(b, a%b)
	return Name{d: n1.d, x: n1.y, y: n1.x - (a / b) * n1.y}
}

func (nt *NumberTheory) ModularExponentiation(a, b, n int64) int64 {
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

type SuffixArray struct {
	ALPHABET_SZ int
	N           int
	T           []int
	lcp         []int
	sa          []int
	sa2         []int
	rank        []int
	tmp         []int
	c           []int
}

func NewSuffixArray(str string) *SuffixArray {
	return NewSuffixArrayFromIntArray(ToIntArray(str))
}

func ToIntArray(s string) []int {
	text := make([]int, len(s))
	for i := range s {
		text[i] = int(s[i])
	}
	return text
}

func NewSuffixArrayFromIntArray(text []int) *SuffixArray {
	sa := &SuffixArray{
		T:           text,
		N:           len(text),
		sa:         make([]int, len(text)),
		sa2:        make([]int, len(text)),
		rank:       make([]int, len(text)),
		c:          make([]int, max(256, len(text))),
		ALPHABET_SZ: 256,
	}
	sa.construct()
	sa.kasai()
	return sa
}

func (sa *SuffixArray) construct() {
	for i := 0; i < sa.N; i++ {
		sa.c[sa.rank[i] = sa.T[i]]++
	}
	for i := 1; i < sa.ALPHABET_SZ; i++ {
		sa.c[i] += sa.c[i-1]
	}
	for i := sa.N - 1; i >= 0; i-- {
		sa.sa[sa.c[sa.T[i]]-1] = i
		sa.c[sa.T[i]]--
	}
	for p := 1; p < sa.N; p <<= 1 {
		r := 0
		for i := sa.N - p; i < sa.N; i++ {
			sa.sa2[r] = i
			r++
		}
		for i := 0; i < sa.N; i++ {
			if sa.sa[i] >= p {
				sa.sa2[r] = sa.sa[i] - p
				r++
			}
		}
		for i := 0; i < sa.ALPHABET_SZ; i++ {
			sa.c[i] = 0
		}
		for i := 0; i < sa.N; i++ {
			sa.c[sa.rank[i]]++
		}
		for i := 1; i < sa.ALPHABET_SZ; i++ {
			sa.c[i] += sa.c[i-1]
		}
		for i := sa.N - 1; i >= 0; i-- {
			sa.sa[sa.c[sa.rank[sa.sa2[i]]]-1] = sa.sa2[i]
			sa.c[sa.rank[sa.sa2[i]]]--
		}
		for sa.sa2[sa.sa[0]] = r = 0; i < sa.N; i++ {
			if !(sa.rank[sa.sa[i-1]] == sa.rank[sa.sa[i]] &&
				sa.sa[i-1]+p < sa.N &&
				sa.sa[i]+p < sa.N &&
				sa.rank[sa.sa[i-1]+p] == sa.rank[sa.sa[i]+p]) {
				r++
			}
			sa.sa2[sa.sa[i]] = r
		}
		sa.tmp = sa.rank
		sa.rank = sa.sa2
		sa.sa2 = sa.tmp
		if r == sa.N-1 {
			break
		}
		sa.ALPHABET_SZ = r + 1
	}
}

func (sa *SuffixArray) kasai() {
	sa.lcp = make([]int, sa.N)
	inv := make([]int, sa.N)
	for i := 0; i < sa.N; i++ {
		inv[sa.sa[i]] = i
	}
	for i, len := 0, 0; i < sa.N; i++ {
		if inv[i] > 0 {
			k := sa.sa[inv[i]-1]
			for (i+len < sa.N) && (k+len < sa.N) && sa.T[i+len] == sa.T[k+len] {
				len++
			}
			sa.lcp[inv[i]-1] = len
			if len > 0 {
				len--
			}
		}
	}
}

type ZAlgorithm struct{}

func (za *ZAlgorithm) CalculateZ(input []rune) []int {
	Z := make([]int, len(input))
	left, right := 0, 0
	for k := 1; k < len(input); k++ {
		if k > right {
			left, right = k, k
			for right < len(input) && input[right] == input[right-left] {
				right++
			}
			Z[k] = right - left
			right--
		} else {
			k1 := k - left
			if Z[k1] < right-k+1 {
				Z[k] = Z[k1]
			} else {
				left = k
				for right < len(input) && input[right] == input[right-left] {
					right++
				}
				Z[k] = right - left
				right--
			}
		}
	}
	return Z
}

func (za *ZAlgorithm) MatchPattern(text, pattern []rune) []int {
	newString := append(pattern, '$')
	newString = append(newString, text...)
	result := []int{}
	Z := za.CalculateZ(newString)

	for i := 0; i < len(Z); i++ {
		if Z[i] == len(pattern) {
			result = append(result, i-len(pattern)-1)
		}
	}
	return result
}

type KMPAlgorithm struct{}

func (kmp *KMPAlgorithm) ComputeTemporalArray(pattern []rune) []int {
	lps := make([]int, len(pattern))
	index := 0
	for i := 1; i < len(pattern); {
		if pattern[i] == pattern[index] {
			lps[i] = index + 1
			index++
			i++
		} else {
			if index != 0 {
				index = lps[index-1]
			} else {
				lps[i] = 0
				i++
			}
		}
	}
	return lps
}

func (kmp *KMPAlgorithm) KMPMatcher(text, pattern []rune) []int {
	lps := kmp.ComputeTemporalArray(pattern)

	j, i, n, m := 0, 0, len(text), len(pattern)
	indices := []int{}
	for i < n {
		if pattern[j] == text[i] {
			i++
			j++
		}
		if j == m {
			indices = append(indices, i-j)
			j = lps[j-1]
		} else if i < n && pattern[j] != text[i] {
			if j != 0 {
				j = lps[j-1]
			} else {
				i++
			}
		}
	}
	return indices
}

type Hashing struct{}

func (h *Hashing) ComputePowers(p int64, n int, m int64) []int64 {
	powers := make([]int64, n)
	powers[0] = 1
	for i := 1; i < n; i++ {
		powers[i] = (powers[i-1] * p) % m
	}
	return powers
}

func (h *Hashing) ComputeHash(s string) int64 {
	p := int64(31)
	m := int64(1_000_000_009)
	hashValue := int64(0)
	powers := h.ComputePowers(p, len(s), m)
	for i, ch := range s {
		hashValue = (hashValue + (int64(ch)-int64('a')+1)*powers[i]) % m
	}
	return hashValue
}

type BasicFunctions struct{}

func (bf *BasicFunctions) Min(A []int64) int64 {
	min := int64(1<<63 - 1)
	for _, v := range A {
		min = minInt64(min, v)
	}
	return min
}

func (bf *BasicFunctions) Max(A []int64) int64 {
	max := int64(-1 << 63)
	for _, v := range A {
		max = maxInt64(max, v)
	}
	return max
}

type MergeSortInt struct{}

func (ms *MergeSortInt) Merge(arr []int, l, m, r int) {
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

	i, j, k := 0, 0, l
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

func (ms *MergeSortInt) Sort(arr []int, l, r int) {
	if l < r {
		m := (l + r) / 2
		ms.Sort(arr, l, m)
		ms.Sort(arr, m+1, r)
		ms.Merge(arr, l, m, r)
	}
}

type MergeSortLong struct{}

func (ms *MergeSortLong) Merge(arr []int64, l, m, r int) {
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

	i, j, k := 0, 0, l
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

func (ms *MergeSortLong) Sort(arr []int64, l, r int) {
	if l < r {
		m := (l + r) / 2
		ms.Sort(arr, l, m)
		ms.Sort(arr, m+1, r)
		ms.Merge(arr, l, m, r)
	}
}

type Node struct {
	s string
}

func NewNode(s string) *Node {
	return &Node{s: s}
}

func (n *Node) Equals(ob interface{}) bool {
	if ob == nil {
		return false
	}
	if obj, ok := ob.(*Node); ok {
		return n.s == obj.s
	}
	return false
}

func (n *Node) HashCode() int {
	return len(n.s)
}

type Reader struct {
	BUFFER_SIZE   int
	din           *bufio.Reader
}

func NewReader() *Reader {
	return &Reader{
		BUFFER_SIZE: 1 << 16,
		din:        bufio.NewReader(os.Stdin),
	}
}

func (r *Reader) ReadLine() (string, error) {
	return r.din.ReadString('\n')
}

func (r *Reader) NextInt() (int, error) {
	var ret int
	_, err := fmt.Fscan(r.din, &ret)
	return ret, err
}

func (r *Reader) NextLong() (int64, error) {
	var ret int64
	_, err := fmt.Fscan(r.din, &ret)
	return ret, err
}

func (r *Reader) NextDouble() (float64, error) {
	var ret float64
	_, err := fmt.Fscan(r.din, &ret)
	return ret, err
}

type FenwickTree struct{}

func (ft *FenwickTree) Update(fenwickTree []int64, delta int64, index int) {
	index++
	for index < len(fenwickTree) {
		fenwickTree[index] += delta
		index += index & (-index)
	}
}

func (ft *FenwickTree) PrefixSum(fenwickTree []int64, index int) int64 {
	sum := int64(0)
	index++
	for index > 0 {
		sum += fenwickTree[index]
		index -= index & (-index)
	}
	return sum
}

type SegmentTree struct{}

func (st *SegmentTree) NextPowerOfTwo(num int) int {
	if num == 0 {
		return 1
	}
	if num > 0 && (num&(num-1)) == 0 {
		return num
	}
	for (num & (num - 1)) > 0 {
		num = num & (num - 1)
	}
	return num << 1
}

func (st *SegmentTree) CreateSegmentTree(input []int) []int {
	np2 := st.NextPowerOfTwo(len(input))
	segmentTree := make([]int, np2*2-1)

	for i := range segmentTree {
		segmentTree[i] = int(^uint(0) >> 1) // Integer.MIN_VALUE
	}

	st.ConstructSegmentTree(segmentTree, input, 0, len(input)-1, 0)
	return segmentTree
}

func (st *SegmentTree) ConstructSegmentTree(segmentTree, input []int, low, high, pos int) {
	if low == high {
		segmentTree[pos] = input[low]
		return
	}
	mid := (low + high) / 2
	st.ConstructSegmentTree(segmentTree, input, low, mid, 2*pos+1)
	st.ConstructSegmentTree(segmentTree, input, mid+1, high, 2*pos+2)
	segmentTree[pos] = max(segmentTree[2*pos+1], segmentTree[2*pos+2])
}

func (st *SegmentTree) RangeMinimumQuery(segmentTree []int, qlow, qhigh, len int) int {
	return st.RangeMinimumQueryHelper(segmentTree, 0, len-1, qlow, qhigh, 0)
}

func (st *SegmentTree) RangeMinimumQueryHelper(segmentTree []int, low, high, qlow, qhigh, pos int) int {
	if qlow <= low && qhigh >= high {
		return segmentTree[pos]
	}
	if qlow > high || qhigh < low {
		return int(^uint(0) >> 1) // Integer.MIN_VALUE
	}
	mid := (low + high) / 2
	return max(st.RangeMinimumQueryHelper(segmentTree, low, mid, qlow, qhigh, 2*pos+1),
		st.RangeMinimumQueryHelper(segmentTree, mid+1, high, qlow, qhigh, 2*pos+2))
}

type Trie struct {
	root *TrieNode
}

type TrieNode struct {
	children map[rune]*TrieNode
	endOfWord bool
}

func NewTrie() *Trie {
	return &Trie{root: &TrieNode{children: make(map[rune]*TrieNode)}}
}

func (t *Trie) Insert(word string) {
	current := t.root
	for _, ch := range word {
		node, exists := current.children[ch]
		if !exists {
			node = &TrieNode{children: make(map[rune]*TrieNode)}
			current.children[ch] = node
		}
		current = node
	}
	current.endOfWord = true
}

func (t *Trie) Search(word string) bool {
	current := t.root
	for _, ch := range word {
		node, exists := current.children[ch]
		if !exists {
			return false
		}
		current = node
	}
	return current.endOfWord
}

func (t *Trie) Delete(word string) {
	t.delete(t.root, word, 0)
}

func (t *Trie) delete(current *TrieNode, word string, index int) bool {
	if index == len(word) {
		if !current.endOfWord {
			return false
		}
		current.endOfWord = false
		return len(current.children) == 0
	}
	ch := rune(word[index])
	node, exists := current.children[ch]
	if !exists {
		return false
	}
	shouldDeleteCurrentNode := t.delete(node, word, index+1)

	if shouldDeleteCurrentNode {
		delete(current.children, ch)
		return len(current.children) == 0
	}
	return false
}

type SegmentTreeLazy struct{}

func (st *SegmentTreeLazy) NextPowerOfTwo(num int) int {
	if num == 0 {
		return 1
	}
	if num > 0 && (num&(num-1)) == 0 {
		return num
	}
	for (num & (num - 1)) > 0 {
		num = num & (num - 1)
	}
	return num << 1
}

func (st *SegmentTreeLazy) CreateSegmentTree(input []int) []int {
	nextPowOfTwo := st.NextPowerOfTwo(len(input))
	segmentTree := make([]int, nextPowOfTwo*2-1)

	for i := range segmentTree {
		segmentTree[i] = int(^uint(0) >> 1) // Integer.MAX_VALUE
	}
	st.ConstructMinSegmentTree(segmentTree, input, 0, len(input)-1, 0)
	return segmentTree
}

func (st *SegmentTreeLazy) ConstructMinSegmentTree(segmentTree, input []int, low, high, pos int) {
	if low == high {
		segmentTree[pos] = input[low]
		return
	}
	mid := (low + high) / 2
	st.ConstructMinSegmentTree(segmentTree, input, low, mid, 2*pos+1)
	st.ConstructMinSegmentTree(segmentTree, input, mid+1, high, 2*pos+2)
	segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2])
}

func (st *SegmentTreeLazy) UpdateSegmentTreeRangeLazy(input, segmentTree, lazy []int, startRange, endRange, delta int) {
	st.UpdateSegmentTreeRangeLazyHelper(segmentTree, lazy, startRange, endRange, delta, 0, len(input)-1, 0)
}

func (st *SegmentTreeLazy) UpdateSegmentTreeRangeLazyHelper(segmentTree, lazy []int, startRange, endRange, delta, low, high, pos int) {
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
	st.UpdateSegmentTreeRangeLazyHelper(segmentTree, lazy, startRange, endRange, delta, low, mid, 2*pos+1)
	st.UpdateSegmentTreeRangeLazyHelper(segmentTree, lazy, startRange, endRange, delta, mid+1, high, 2*pos+2)
	segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2])
}

func (st *SegmentTreeLazy) RangeMinimumQueryLazy(segmentTree, lazy []int, qlow, qhigh, len int) int {
	return st.RangeMinimumQueryLazyHelper(segmentTree, lazy, qlow, qhigh, 0, len-1, 0)
}

func (st *SegmentTreeLazy) RangeMinimumQueryLazyHelper(segmentTree, lazy []int, qlow, qhigh, low, high, pos int) int {
	if low > high {
		return int(^uint(0) >> 1) // Integer.MAX_VALUE
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
		return int(^uint(0) >> 1) // Integer.MAX_VALUE
	}

	if qlow <= low && qhigh >= high {
		return segmentTree[pos]
	}

	mid := (low + high) / 2
	return min(st.RangeMinimumQueryLazyHelper(segmentTree, lazy, qlow, qhigh, low, mid, 2*pos+1),
		st.RangeMinimumQueryLazyHelper(segmentTree, lazy, qlow, qhigh, mid+1, high, 2*pos+2))
}

func main() {
	reader := NewReader()
	s1, _ := reader.ReadLine()
	s1Split := strings.Fields(s1)
	n, _ := strconv.Atoi(s1Split[0])
	k, _ := strconv.Atoi(s1Split[1])
	s, _ := reader.ReadLine()

	var stringBuilder strings.Builder

	if k == 0 {
		fmt.Println(s)
		return
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
