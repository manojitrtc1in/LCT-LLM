package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var m, x int64
	fmt.Fscan(reader, &m, &x)

	primes := factorizeNumberPrime(m)
	allFactorOfM := make([]int64, 0)
	tmpList := make([]int64, 0)
	allPossiblePrimeFactor := make([]int64, 0)
	for _, p := range primes {
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, p)
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, factorizeNumberPrime(p-1)...)
	}
	allPossiblePrimeFactor = unique(allPossiblePrimeFactor)

	collect(&allFactorOfM, m, 0)
	power := NewPower(NewLongModular(m))

	total := int64(1)
	for _, g := range allFactorOfM {
		if g == m {
			continue
		}
		mg := m / g
		tmpList = tmpList[:0]
		collect(&tmpList, mg, 0)
		cnt := int64(0)
		for j := len(tmpList) - 1; j >= 0; j-- {
			t := tmpList[j]
			cnt += mu(t) * ((m - 1) / (t * g))
		}

		tmpList = tmpList[:0]
		euler := euler(mg)
		primeFactors := tmpList
		for _, p := range allPossiblePrimeFactor {
			if euler%p == 0 {
				primeFactors = append(primeFactors, p)
			}
		}

		n := euler
		for _, p := range primeFactors {
			for n%p == 0 && power.Pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("Invalid state")
		}
		total += cnt / n
	}

	fmt.Fprintln(writer, total)
}

func factorizeNumberPrime(x int64) []int64 {
	ans := make([]int64, 0)
	for i := int64(2); i*i <= x; i++ {
		if x%i != 0 {
			continue
		}
		ans = append(ans, i)
		for x%i == 0 {
			x /= i
		}
	}
	if x > 1 {
		ans = append(ans, x)
	}
	return ans
}

func unique(a []int64) []int64 {
	if len(a) <= 1 {
		return a
	}

	sort(a, 0, len(a)-1)
	wpos := 1
	for i := 1; i < len(a); i++ {
		if a[i] != a[wpos-1] {
			a[wpos] = a[i]
			wpos++
		}
	}
	return a[:wpos]
}

func sort(a []int64, l, r int) {
	if l >= r {
		return
	}
	m := (l + r) >> 1
	sort(a, l, m)
	sort(a, m+1, r)
	merge(a, l, m, r)
}

func merge(a []int64, l, m, r int) {
	tmp := make([]int64, r-l+1)
	i := l
	j := m + 1
	k := 0
	for i <= m && j <= r {
		if a[i] <= a[j] {
			tmp[k] = a[i]
			i++
		} else {
			tmp[k] = a[j]
			j++
		}
		k++
	}
	for i <= m {
		tmp[k] = a[i]
		i++
		k++
	}
	for j <= r {
		tmp[k] = a[j]
		j++
		k++
	}
	copy(a[l:r+1], tmp)
}

func collect(list *[]int64, x int64, i int) {
	if i == len(primes) {
		*list = append(*list, x)
		return
	}
	collect(list, x, i+1)
	for x%primes[i] == 0 {
		x /= primes[i]
		collect(list, x, i+1)
	}
}

type LongHashMap struct {
	slot    []int
	next    []int
	keys    []int64
	values  []int64
	alloc   int
	removed []bool
	mask    int
	size    int
	rehash  bool
}

func NewLongHashMap(cap int, rehash bool) *LongHashMap {
	mask := (1 << (32 - leadingZeros(cap-1))) - 1
	return &LongHashMap{
		slot:    make([]int, mask+1),
		next:    make([]int, cap+1),
		keys:    make([]int64, cap+1),
		values:  make([]int64, cap+1),
		removed: make([]bool, cap+1),
		mask:    mask,
		rehash:  rehash,
	}
}

func (m *LongHashMap) doubleCapacity() {
	newSize := max(len(m.next)+10, len(m.next)*2)
	m.next = append(m.next, make([]int, newSize-len(m.next))...)
	m.keys = append(m.keys, make([]int64, newSize-len(m.keys))...)
	m.values = append(m.values, make([]int64, newSize-len(m.values))...)
	m.removed = append(m.removed, make([]bool, newSize-len(m.removed))...)
}

func (m *LongHashMap) alloc() {
	m.alloc++
	if m.alloc >= len(m.next) {
		m.doubleCapacity()
	}
	m.next[m.alloc] = 0
	m.removed[m.alloc] = false
	m.size++
}

func (m *LongHashMap) rehash() {
	newSlots := make([]int, max(16, len(m.slot)*2))
	newMask := len(newSlots) - 1
	for i := 0; i < len(m.slot); i++ {
		if m.slot[i] == 0 {
			continue
		}
		head := m.slot[i]
		for head != 0 {
			n := m.next[head]
			s := hash(m.keys[head]) & newMask
			m.next[head] = newSlots[s]
			newSlots[s] = head
			head = n
		}
	}
	m.slot = newSlots
	m.mask = newMask
}

func (m *LongHashMap) put(x, y int64) {
	m.putWithCover(x, y, true)
}

func (m *LongHashMap) putWithCover(x, y int64, cover bool) {
	h := hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		m.alloc()
		m.slot[s] = m.alloc
		m.keys[m.alloc] = x
		m.values[m.alloc] = y
	} else {
		index := m.findIndexOrLastEntry(s, x)
		if m.keys[index] != x {
			m.alloc()
			m.next[index] = m.alloc
			m.keys[m.alloc] = x
			m.values[m.alloc] = y
		} else if cover {
			m.values[index] = y
		}
	}
	if m.rehash && m.size >= len(m.slot) {
		m.rehash()
	}
}

func (m *LongHashMap) findIndexOrLastEntry(s int, x int64) int {
	iter := m.slot[s]
	for m.keys[iter] != x {
		if m.next[iter] != 0 {
			iter = m.next[iter]
		} else {
			return iter
		}
	}
	return iter
}

func (m *LongHashMap) getOrDefault(x, def int64) int64 {
	h := hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		return def
	}
	index := m.findIndexOrLastEntry(s, x)
	if m.keys[index] == x {
		return m.values[index]
	}
	return def
}

func hash(x int64) int {
	h := int(x)
	return h ^ (h >> 16)
}

type LongEntryIterator struct {
	m         *LongHashMap
	index     int
	readIndex int
}

func (iter *LongEntryIterator) hasNext() bool {
	for iter.index <= iter.m.alloc && iter.m.removed[iter.index] {
		iter.index++
	}
	return iter.index <= iter.m.alloc
}

func (iter *LongEntryIterator) next() {
	if !iter.hasNext() {
		panic("No next element")
	}
	iter.readIndex = iter.index
	iter.index++
}

func (iter *LongEntryIterator) getEntryKey() int64 {
	return iter.m.keys[iter.readIndex]
}

func (iter *LongEntryIterator) getEntryValue() int64 {
	return iter.m.values[iter.readIndex]
}

func NewPower(mod ILongModular) *LongPower {
	return &LongPower{mod: mod}
}

type LongPower struct {
	mod ILongModular
}

func (p *LongPower) Pow(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	r := p.Pow(x, n>>1)
	r = p.mod.Mul(r, r)
	if n&1 == 1 {
		r = p.mod.Mul(r, x)
	}
	return r
}

type ILongModular interface {
	Mul(a, b int64) int64
}

type LongModular struct {
	m int64
}

func NewLongModular(m int64) *LongModular {
	return &LongModular{m: m}
}

func (m *LongModular) Mul(a, b int64) int64 {
	return b * a % m.m
}

func leadingZeros(x int) int {
	return bitsLen(uint(x)) - 1
}

func bitsLen(x uint) int {
	if x == 0 {
		return 0
	}
	return 32 - bits.LeadingZeros32(x)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func hash(x int64) int {
	h := int(x)
	return h ^ (h >> 16)
}

func mu(x int64) int64 {
	return muMap.GetOrDefault(x, -1)
}

func euler(x int64) int64 {
	return eulerMap.GetOrDefault(x, -1)
}

var (
	primes     []int64
	muMap      *LongHashMap
	eulerMap   *LongHashMap
)

func init() {
	primes = factorizeNumberPrime(100000)
	muMap = NewLongHashMap(100000, false)
	eulerMap = NewLongHashMap(100000, false)
	muMap.put(1, 1)
	eulerMap.put(1, 1)
}

func oneOfPrimeFactor(x int64) int64 {
	for _, p := range primes {
		if x%p == 0 {
			return p
		}
	}
	return x
}

func populate(x int64) {
	factor := oneOfPrimeFactor(x)
	cnt := int64(0)
	y := x
	for y%factor == 0 {
		cnt++
		y /= factor
	}
	if cnt > 1 {
		muMap.put(x, 0)
	} else {
		muMap.put(x, -mu(y))
	}
	eulerMap.put(x, euler(y)*(x/y-x/y/factor))
}

func collect(list *[]int64, x int64, i int) {
	if i == len(primes) {
		*list = append(*list, x)
		return
	}
	collect(list, x, i+1)
	for x%primes[i] == 0 {
		x /= primes[i]
		collect(list, x, i+1)
	}
}

func mu(x int64) int64 {
	ans := muMap.GetOrDefault(x, -1)
	if ans == -1 {
		populate(x)
		ans = muMap.GetOrDefault(x, -1)
	}
	return ans
}

func euler(x int64) int64 {
	ans := eulerMap.GetOrDefault(x, -1)
	if ans == -1 {
		populate(x)
		ans = eulerMap.GetOrDefault(x, -1)
	}
	return ans
}

func factorizeNumberPrime(x int64) []int64 {
	ans := make([]int64, 0)
	for i := int64(2); i*i <= x; i++ {
		if x%i != 0 {
			continue
		}
		ans = append(ans, i)
		for x%i == 0 {
			x /= i
		}
	}
	if x > 1 {
		ans = append(ans, x)
	}
	return ans
}
