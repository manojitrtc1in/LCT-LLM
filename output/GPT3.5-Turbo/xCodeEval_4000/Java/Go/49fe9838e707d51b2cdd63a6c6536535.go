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

	primes := findAllFactors(m)
	allFactorOfM := make([]int64, 0)
	allPossiblePrimeFactor := make([]int64, 0)
	for _, p := range primes {
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, p)
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, factorizeNumberPrime(p-1)...)
	}
	allPossiblePrimeFactor = unique(allPossiblePrimeFactor)

	collect(&allFactorOfM, m, 0)
	power := NewPower(m)

	total := int64(1)
	for _, g := range allFactorOfM {
		if g == m {
			continue
		}
		mg := m / g
		tmpList := make([]int64, 0)
		collect(&tmpList, mg, 0)
		cnt := int64(0)
		for j := len(tmpList) - 1; j >= 0; j-- {
			t := tmpList[j]
			cnt += mu(t) * ((m - 1) / (t * g))
		}

		tmpList = make([]int64, 0)
		euler := euler(mg)
		primeFactors := tmpList
		for _, p := range allPossiblePrimeFactor {
			if euler%p == 0 {
				primeFactors = append(primeFactors, p)
			}
		}

		n := euler
		for _, p := range primeFactors {
			for n%p == 0 && power.pow(x, n/p)%mg == 1 {
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

func findAllFactors(n int64) []int64 {
	factors := make(map[int64]int64)
	findAllFactorsHelper(&factors, n)
	primes := make([]int64, 0)
	for p := range factors {
		primes = append(primes, p)
	}
	return primes
}

func findAllFactorsHelper(factors *map[int64]int64, n int64) {
	if n == 1 {
		return
	}
	f := findFactor(n)
	if f == n {
		(*factors)[f]++
		return
	}
	findAllFactorsHelper(factors, f)
	findAllFactorsHelper(factors, n/f)
}

func findFactor(n int64) int64 {
	if mr(n, 3) {
		return n
	}
	for {
		f := findFactor0(int64(randomFloat()*(float64(n)-2))+2, int64(randomFloat()*(float64(n)-2))+2, n)
		if f != -1 {
			return f
		}
	}
}

func findFactor0(x, c, n int64) int64 {
	xi := x
	xj := x
	j := int64(2)
	i := int64(1)
	for i < n {
		i++
		xi = (xi*xi + c) % n
		g := gcd(n, abs(xi-xj))
		if g != 1 && g != n {
			return g
		}
		if i == j {
			j = j << 1
			xj = xi
		}
	}
	return -1
}

func gcd(a, b int64) int64 {
	if a >= b {
		return gcd0(a, b)
	}
	return gcd0(b, a)
}

func gcd0(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd0(b, a%b)
}

func mr(n int64, s int) bool {
	if n <= 1 {
		return false
	}
	if n == 2 {
		return true
	}
	if n%2 == 0 {
		return false
	}
	for i := 0; i < s; i++ {
		x := int64(randomFloat() * (float64(n) - 2))
		if !mr0(x, n) {
			return false
		}
	}
	return true
}

func mr0(x, n int64) bool {
	exp := n - 1
	for {
		y := pow(x, exp, n)
		if y != 1 && y != n-1 {
			return false
		}
		if y != 1 || exp%2 == 1 {
			break
		}
		exp = exp / 2
	}
	return true
}

func pow(x, n, mod int64) int64 {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1, mod)
	r = (r * r) % mod
	if n&1 == 1 {
		r = (r * x) % mod
	}
	return r
}

func collect(list *[]int64, x, i int64) {
	if i == int64(len(primes)) {
		*list = append(*list, x)
		return
	}
	collect(list, x, i+1)
	for x%primes[i] == 0 {
		x /= primes[i]
		collect(list, x, i+1)
	}
}

func unique(list []int64) []int64 {
	if len(list) <= 1 {
		return list
	}
	sort.Slice(list, func(i, j int) bool {
		return list[i] < list[j]
	})
	wpos := 1
	for i := 1; i < len(list); i++ {
		if list[i] != list[wpos-1] {
			list[wpos] = list[i]
			wpos++
		}
	}
	return list[:wpos]
}

func randomFloat() float64 {
	return rand.Float64()
}

type Power struct {
	modular ILongModular
}

func NewPower(mod int64) *Power {
	return &Power{modular: NewLongModular(mod)}
}

func (p *Power) pow(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	r := p.pow(x, n>>1)
	r = p.modular.mul(r, r)
	if n&1 == 1 {
		r = p.modular.mul(r, x)
	}
	return r
}

type LongModular struct {
	m int64
}

func NewLongModular(m int64) *LongModular {
	return &LongModular{m: m}
}

func (mod *LongModular) mul(a, b int64) int64 {
	return (b == 0) ? 0 : ((mod.mul(a, b>>1) << 1) % mod.m + a*(b&1)) % mod.m
}

func (mod *LongModular) plus(a, b int64) int64 {
	return mod.valueOf(a + b)
}

func (mod *LongModular) valueOf(a int64) int64 {
	a %= mod.m
	if a < 0 {
		a += mod.m
	}
	return a
}

type LongEntryIterator interface {
	HasNext() bool
	Next()
	GetEntryKey() int64
	GetEntryValue() int64
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
	mask := (1 << (32 - bits.LeadingZeros32(cap-1))) - 1
	slot := make([]int, mask+1)
	next := make([]int, cap+1)
	keys := make([]int64, cap+1)
	values := make([]int64, cap+1)
	removed := make([]bool, cap+1)
	return &LongHashMap{
		slot:    slot,
		next:    next,
		keys:    keys,
		values:  values,
		removed: removed,
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
			s := m.hash(m.keys[head]) & newMask
			m.next[head] = newSlots[s]
			newSlots[s] = head
			head = n
		}
	}
	m.slot = newSlots
	m.mask = newMask
}

func (m *LongHashMap) hash(x int64) int {
	h := int(hash64(x))
	return h ^ (h >> 16)
}

func (m *LongHashMap) put(x, y int64) {
	m.putWithCover(x, y, true)
}

func (m *LongHashMap) putWithCover(x, y int64, cover bool) {
	h := m.hash(x)
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

func (m *LongHashMap) GetOrDefault(x, def int64) int64 {
	h := m.hash(x)
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

func (m *LongHashMap) Get(x int64) int64 {
	return m.GetOrDefault(x, 0)
}

func (m *LongHashMap) Iterator() LongEntryIterator {
	return &LongEntryIteratorImpl{
		m:     m,
		index: 1,
	}
}

type LongEntryIteratorImpl struct {
	m       *LongHashMap
	index   int
	readIdx int
}

func (iter *LongEntryIteratorImpl) HasNext() bool {
	for iter.index <= iter.m.alloc && iter.m.removed[iter.index] {
		iter.index++
	}
	return iter.index <= iter.m.alloc
}

func (iter *LongEntryIteratorImpl) Next() {
	if !iter.HasNext() {
		panic("No next element")
	}
	iter.readIdx = iter.index
	iter.index++
}

func (iter *LongEntryIteratorImpl) GetEntryKey() int64 {
	return iter.m.keys[iter.readIdx]
}

func (iter *LongEntryIteratorImpl) GetEntryValue() int64 {
	return iter.m.values[iter.readIdx]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}

func unique(list []int64) []int64 {
	if len(list) <= 1 {
		return list
	}
	sort.Slice(list, func(i, j int) bool {
		return list[i] < list[j]
	})
	wpos := 1
	for i := 1; i < len(list); i++ {
		if list[i] != list[wpos-1] {
			list[wpos] = list[i]
			wpos++
		}
	}
	return list[:wpos]
}

func collect(list *[]int64, x, i int64) {
	if i == int64(len(primes)) {
		*list = append(*list, x)
		return
	}
	collect(list, x, i+1)
	for x%primes[i] == 0 {
		x /= primes[i]
		collect(list, x, i+1)
	}
}

var primes []int64

func init() {
	primes = findAllFactors(100000)
}

func main() {
	var m, x int64
	fmt.Scan(&m, &x)

	primes = findAllFactors(m)
	allFactorOfM := make([]int64, 0)
	allPossiblePrimeFactor := make([]int64, 0)
	for _, p := range primes {
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, p)
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, factorizeNumberPrime(p-1)...)
	}
	allPossiblePrimeFactor = unique(allPossiblePrimeFactor)

	collect(&allFactorOfM, m, 0)
	power := NewPower(m)

	total := int64(1)
	for _, g := range allFactorOfM {
		if g == m {
			continue
		}
		mg := m / g
		tmpList := make([]int64, 0)
		collect(&tmpList, mg, 0)
		cnt := int64(0)
		for j := len(tmpList) - 1; j >= 0; j-- {
			t := tmpList[j]
			cnt += mu(t) * ((m - 1) / (t * g))
		}

		tmpList = make([]int64, 0)
		euler := euler(mg)
		primeFactors := tmpList
		for _, p := range allPossiblePrimeFactor {
			if euler%p == 0 {
				primeFactors = append(primeFactors, p)
			}
		}

		n := euler
		for _, p := range primeFactors {
			for n%p == 0 && power.pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("Invalid state")
		}
		total += cnt / n
	}

	fmt.Println(total)
}
