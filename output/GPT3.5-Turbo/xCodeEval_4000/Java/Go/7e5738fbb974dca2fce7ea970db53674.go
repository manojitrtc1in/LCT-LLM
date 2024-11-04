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
	return &DSU{parent, size}
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

type FastFourierTransform struct{}

func (f *FastFourierTransform) fft(a, b []float64, invert bool) {
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
		wLenA := math.Cos(angle)
		wLenB := math.Sin(angle)
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

func (f *FastFourierTransform) multiply(a, b []float64) []int64 {
	resultSize := 1 << uint(math.Max(float64(len(a)), float64(len(b)))) << 2
	resultSize = int(math.Max(float64(resultSize), 1))
	aReal := make([]float64, resultSize)
	aImaginary := make([]float64, resultSize)
	bReal := make([]float64, resultSize)
	bImaginary := make([]float64, resultSize)
	for i := 0; i < len(a); i++ {
		aReal[i] = a[i]
	}
	for i := 0; i < len(b); i++ {
		bReal[i] = b[i]
	}
	f.fft(aReal, aImaginary, false)
	f.fft(bReal, bImaginary, false)
	for i := 0; i < resultSize; i++ {
		real := aReal[i]*bReal[i] - aImaginary[i]*bImaginary[i]
		aImaginary[i] = aImaginary[i]*bReal[i] + bImaginary[i]*aReal[i]
		aReal[i] = real
	}
	f.fft(aReal, aImaginary, true)
	result := make([]int64, resultSize)
	for i := 0; i < resultSize; i++ {
		result[i] = int64(math.Round(aReal[i]))
	}
	return result
}

type NumberTheory struct{}

func (n *NumberTheory) isPrime(num int64) bool {
	if num < 2 {
		return false
	}
	for x := int64(2); x*x <= num; x++ {
		if num%x == 0 {
			return false
		}
	}
	return true
}

func (n *NumberTheory) primeFactorisation(num int64) []int64 {
	factors := make([]int64, 0)
	for x := int64(2); x*x <= num; x++ {
		for num%x == 0 {
			factors = append(factors, x)
			num /= x
		}
	}
	if num > 1 {
		factors = append(factors, num)
	}
	return factors
}

func (n *NumberTheory) sieveOfEratosthenes(num int) []int {
	sieve := make([]int, num+1)
	for x := 2; x*x <= num; x++ {
		if sieve[x] != 0 {
			continue
		}
		for u := x * x; u <= num; u += x {
			if sieve[u] == 0 {
				sieve[u] = x
			}
		}
	}
	return sieve
}

func (n *NumberTheory) gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return n.gcd(b, a%b)
}

func (n *NumberTheory) phi(num int64) int64 {
	result := float64(num)
	for p := int64(2); p*p <= num; p++ {
		if num%p == 0 {
			for num%p == 0 {
				num /= p
			}
			result *= (1.0 - (1.0 / float64(p)))
		}
	}
	if num > 1 {
		result *= (1.0 - (1.0 / float64(num)))
	}
	return int64(result)
}

func (n *NumberTheory) extendedEuclid(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return a, 1, 0
	}
	d, x, y := n.extendedEuclid(b, a%b)
	return d, y, x - (a/b)*y
}

func (n *NumberTheory) modularExponentiation(a, b, num int64) int64 {
	d := int64(1)
	bString := strconv.FormatInt(b, 2)
	for i := 0; i < len(bString); i++ {
		d = (d * d) % num
		if bString[i] == '1' {
			d = (d * a) % num
		}
	}
	return d
}

type Name struct {
	d int64
	x int64
	y int64
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
	sa := &SuffixArray{
		ALPHABET_SZ: 256,
		N:           len(str),
		T:           make([]int, len(str)),
		lcp:         make([]int, len(str)),
		sa:          make([]int, len(str)),
		sa2:         make([]int, len(str)),
		rank:        make([]int, len(str)),
		tmp:         make([]int, len(str)),
		c:           make([]int, int(math.Max(float64(256), float64(len(str))))),
	}
	for i := 0; i < len(str); i++ {
		sa.T[i] = int(str[i])
	}
	sa.construct()
	sa.kasai()
	return sa
}

func (s *SuffixArray) construct() {
	for i := 0; i < s.N; i++ {
		s.c[s.rank[i]]++
	}
	for i := 1; i < s.ALPHABET_SZ; i++ {
		s.c[i] += s.c[i-1]
	}
	for i := s.N - 1; i >= 0; i-- {
		s.sa[s.c[s.rank[i]]-1] = i
		s.c[s.rank[i]]--
	}
	for p := 1; p < s.N; p <<= 1 {
		r := 0
		for i := s.N - p; i < s.N; i++ {
			s.sa2[r] = i
			r++
		}
		for i := 0; i < s.N; i++ {
			if s.sa[i] >= p {
				s.sa2[r] = s.sa[i] - p
				r++
			}
		}
		for i := 0; i < s.ALPHABET_SZ; i++ {
			s.c[i] = 0
		}
		for i := 0; i < s.N; i++ {
			s.c[s.rank[i]]++
		}
		for i := 1; i < s.ALPHABET_SZ; i++ {
			s.c[i] += s.c[i-1]
		}
		for i := s.N - 1; i >= 0; i-- {
			s.sa[s.c[s.rank[s.sa2[i]]]-1] = s.sa2[i]
			s.c[s.rank[s.sa2[i]]]--
		}
		s.sa2, s.sa = s.sa, s.sa2
		s.rank[s.sa[0]] = 0
		r = 1
		for i := 1; i < s.N; i++ {
			if s.sa2[i-1]+p < s.N && s.sa[i]+p < s.N && s.rank[s.sa2[i-1]] == s.rank[s.sa[i]] && s.rank[s.sa2[i-1]+p] == s.rank[s.sa[i]+p] {
				s.rank[s.sa[i]] = r - 1
			} else {
				s.rank[s.sa[i]] = r
				r++
			}
		}
		if r == s.N {
			break
		}
		s.ALPHABET_SZ = r
	}
}

func (s *SuffixArray) kasai() {
	inv := make([]int, s.N)
	for i := 0; i < s.N; i++ {
		inv[s.sa[i]] = i
	}
	for i := 0; i < s.N; i++ {
		if inv[i] > 0 {
			k := s.sa[inv[i]-1]
			len := 0
			for i+len < s.N && k+len < s.N && s.T[i+len] == s.T[k+len] {
				len++
			}
			s.lcp[inv[i]-1] = len
			if len > 0 {
				len--
			}
		}
	}
}

type ZAlgorithm struct{}

func (z *ZAlgorithm) calculateZ(input []byte) []int {
	zArray := make([]int, len(input))
	left := 0
	right := 0
	for k := 1; k < len(input); k++ {
		if k > right {
			left = right
			for right < len(input) && input[right] == input[right-left] {
				right++
			}
			zArray[k] = right - left
			right--
		} else {
			k1 := k - left
			if zArray[k1] < right-k+1 {
				zArray[k] = zArray[k1]
			} else {
				left = k
				for right < len(input) && input[right] == input[right-left] {
					right++
				}
				zArray[k] = right - left
				right--
			}
		}
	}
	return zArray
}

func (z *ZAlgorithm) matchPattern(text, pattern []byte) []int {
	newString := make([]byte, len(text)+len(pattern)+1)
	i := 0
	for _, ch := range pattern {
		newString[i] = ch
		i++
	}
	newString[i] = '$'
	i++
	for _, ch := range text {
		newString[i] = ch
		i++
	}
	result := make([]int, 0)
	zArray := z.calculateZ(newString)
	for i := 0; i < len(zArray); i++ {
		if zArray[i] == len(pattern) {
			result = append(result, i-len(pattern)-1)
		}
	}
	return result
}

type KMPAlgorithm struct{}

func (k *KMPAlgorithm) computeTemporalArray(pattern []byte) []int {
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

func (k *KMPAlgorithm) KMPMatcher(text, pattern []byte) []int {
	lps := k.computeTemporalArray(pattern)
	j := 0
	i := 0
	n := len(text)
	m := len(pattern)
	indices := make([]int, 0)
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
				i = i + 1
			}
		}
	}
	return indices
}

type Hashing struct{}

func (h *Hashing) computePowers(p int64, n int, m int64) []int64 {
	powers := make([]int64, n)
	powers[0] = 1
	for i := 1; i < n; i++ {
		powers[i] = (powers[i-1] * p) % m
	}
	return powers
}

func (h *Hashing) computeHash(s string) int64 {
	p := int64(31)
	m := int64(1_000_000_009)
	hashValue := int64(0)
	powers := h.computePowers(p, len(s), m)
	for i := 0; i < len(s); i++ {
		ch := int64(s[i] - 'a' + 1)
		hashValue = (hashValue + ch*powers[i]) % m
	}
	return hashValue
}

type BasicFunctions struct{}

func (b *BasicFunctions) min(A []int64) int64 {
	min := int64(1<<63 - 1)
	for i := 0; i < len(A); i++ {
		if A[i] < min {
			min = A[i]
		}
	}
	return min
}

func (b *BasicFunctions) max(A []int64) int64 {
	max := int64(-1 << 63)
	for i := 0; i < len(A); i++ {
		if A[i] > max {
			max = A[i]
		}
	}
	return max
}

type MergeSortInt struct{}

func (m *MergeSortInt) merge(arr []int, l, m, r int) {
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

func (m *MergeSortInt) sort(arr []int, l, r int) {
	if l < r {
		mid := (l + r) / 2

		m.sort(arr, l, mid)
		m.sort(arr, mid+1, r)

		m.merge(arr, l, mid, r)
	}
}

type MergeSortLong struct{}

func (m *MergeSortLong) merge(arr []int64, l, m, r int) {
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

func (m *MergeSortLong) sort(arr []int64, l, r int) {
	if l < r {
		mid := (l + r) / 2

		m.sort(arr, l, mid)
		m.sort(arr, mid+1, r)

		m.merge(arr, l, mid, r)
	}
}

type Node struct {
	s string
}

func NewNode(s string) *Node {
	return &Node{s}
}

func (n *Node) Equals(obj interface{}) bool {
	if obj == nil {
		return false
	}
	if node, ok := obj.(*Node); ok {
		return n.s == node.s
	}
	return false
}

func (n *Node) HashCode() int {
	return len(n.s)
}

type FenwickTree struct{}

func (f *FenwickTree) update(fenwickTree []int64, delta int64, index int) {
	index += 1
	for index < len(fenwickTree) {
		fenwickTree[index] += delta
		index = index + (index & (-index))
	}
}

func (f *FenwickTree) prefixSum(fenwickTree []int64, index int) int64 {
	sum := int64(0)
	index += 1
	for index > 0 {
		sum += fenwickTree[index]
		index -= (index & (-index))
	}
	return sum
}

type SegmentTree struct{}

func (s *SegmentTree) nextPowerOfTwo(num int) int {
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

func (s *SegmentTree) createSegmentTree(input []int) []int {
	np2 := s.nextPowerOfTwo(len(input))
	segmentTree := make([]int, np2*2-1)

	for i := 0; i < len(segmentTree); i++ {
		segmentTree[i] = int(math.MinInt32)
	}

	s.constructSegmentTree(segmentTree, input, 0, len(input)-1, 0)
	return segmentTree
}

func (s *SegmentTree) constructSegmentTree(segmentTree, input []int, low, high, pos int) {
	if low == high {
		segmentTree[pos] = input[low]
		return
	}
	mid := (low + high) / 2
	s.constructSegmentTree(segmentTree, input, low, mid, 2*pos+1)
	s.constructSegmentTree(segmentTree, input, mid+1, high, 2*pos+2)
	segmentTree[pos] = int(math.Max(float64(segmentTree[2*pos+1]), float64(segmentTree[2*pos+2])))
}

func (s *SegmentTree) rangeMinimumQuery(segmentTree []int, qlow, qhigh, len int) int {
	return s.rangeMinimumQuery(segmentTree, 0, len-1, qlow, qhigh, 0)
}

func (s *SegmentTree) rangeMinimumQuery(segmentTree []int, low, high, qlow, qhigh, pos int) int {
	if qlow <= low && qhigh >= high {
		return segmentTree[pos]
	}
	if qlow > high || qhigh < low {
		return int(math.MinInt32)
	}
	mid := (low + high) / 2
	return int(math.Max(float64(s.rangeMinimumQuery(segmentTree, low, mid, qlow, qhigh, 2*pos+1))), float64(s.rangeMinimumQuery(segmentTree, mid+1, high, qlow, qhigh, 2*pos+2))))
}

type Trie struct {
	root *TrieNode
}

type TrieNode struct {
	children   map[rune]*TrieNode
	endOfWord  bool
}

func NewTrie() *Trie {
	return &Trie{
		root: &TrieNode{
			children:  make(map[rune]*TrieNode),
			endOfWord: false,
		},
	}
}

func (t *Trie) Insert(word string) {
	current := t.root
	for _, ch := range word {
		node, ok := current.children[ch]
		if !ok {
			node = &TrieNode{
				children:  make(map[rune]*TrieNode),
				endOfWord: false,
			}
			current.children[ch] = node
		}
		current = node
	}
	current.endOfWord = true
}

func (t *Trie) Search(word string) bool {
	current := t.root
	for _, ch := range word {
		node, ok := current.children[ch]
		if !ok {
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
	node, ok := current.children[ch]
	if !ok {
		return false
	}
	shouldDeleteCurrentNode := t.delete(node, word, index+1)

	if shouldDeleteCurrentNode {
		delete(current.children, ch)
		return len(current.children) == 0
	}
	return false
}

func main() {
	// Your code here
}
