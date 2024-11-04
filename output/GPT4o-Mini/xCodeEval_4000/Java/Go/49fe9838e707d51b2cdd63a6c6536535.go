package main

import (
	"fmt"
	"io"
	"math/rand"
	"sync"
)

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
	mask := (1 << (32 - bits.LeadingZeros32(uint32(cap-1)))) - 1
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

func (m *LongHashMap) alloc() {
	m.alloc++
	if m.alloc >= len(m.next) {
		m.doubleCapacity()
	}
	m.next[m.alloc] = 0
	m.removed[m.alloc] = false
	m.size++
}

func (m *LongHashMap) doubleCapacity() {
	newSize := max(len(m.next)+10, len(m.next)*2)
	m.next = append(m.next, make([]int, newSize-len(m.next))...)
	m.keys = append(m.keys, make([]int64, newSize-len(m.keys))...)
	m.values = append(m.values, make([]int64, newSize-len(m.values))...)
	m.removed = append(m.removed, make([]bool, newSize-len(m.removed))...)
}

func (m *LongHashMap) hash(x int64) int {
	h := int64(hashCode(x))
	return int(h ^ (h >> 16)) & m.mask
}

func (m *LongHashMap) put(x, y int64, cover bool) {
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

func (m *LongHashMap) getOrDefault(x int64, def int64) int64 {
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

type FastInput struct {
	is       io.Reader
	buf      []byte
	bufLen   int
	bufOffset int
	next     int
}

func NewFastInput(is io.Reader) *FastInput {
	return &FastInput{
		is:  is,
		buf: make([]byte, 1<<13),
	}
}

func (f *FastInput) read() int {
	for f.bufLen == f.bufOffset {
		f.bufOffset = 0
		n, err := f.is.Read(f.buf)
		if err != nil {
			f.bufLen = -1
			return -1
		}
		f.bufLen = n
	}
	return int(f.buf[f.bufOffset])
}

func (f *FastInput) skipBlank() {
	for f.next >= 0 && f.next <= 32 {
		f.next = f.read()
	}
}

func (f *FastInput) readLong() int64 {
	sign := 1
	f.skipBlank()
	if f.next == '+' || f.next == '-' {
		if f.next == '+' {
			sign = 1
		} else {
			sign = -1
		}
		f.next = f.read()
	}

	var val int64
	if sign == 1 {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 + int64(f.next-'0')
			f.next = f.read()
		}
	} else {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 - int64(f.next-'0')
			f.next = f.read()
		}
	}

	return val
}

type FastOutput struct {
	cache *strings.Builder
	os    io.Writer
}

func NewFastOutput(os io.Writer) *FastOutput {
	return &FastOutput{
		cache: new(strings.Builder),
		os:    os,
	}
}

func (f *FastOutput) append(csq string) *FastOutput {
	f.cache.WriteString(csq)
	return f
}

func (f *FastOutput) println(c int64) *FastOutput {
	f.cache.WriteString(fmt.Sprintf("%d", c))
	f.printlnEmpty()
	return f
}

func (f *FastOutput) printlnEmpty() *FastOutput {
	f.cache.WriteString("\n")
	return f
}

func (f *FastOutput) flush() {
	_, _ = f.os.Write([]byte(f.cache.String()))
	f.cache.Reset()
}

func (f *FastOutput) close() {
	f.flush()
}

type GXMouseInTheCampus struct {
	mu    *LongHashMap
	euler *LongHashMap
	primes []int64
}

func NewGXMouseInTheCampus() *GXMouseInTheCampus {
	mu := NewLongHashMap(100000, false)
	euler := NewLongHashMap(100000, false)
	mu.put(1, 1, true)
	euler.put(1, 1, true)
	return &GXMouseInTheCampus{mu: mu, euler: euler}
}

func (g *GXMouseInTheCampus) oneOfPrimeFactor(x int64) int64 {
	for _, p := range g.primes {
		if x%p == 0 {
			return p
		}
	}
	return x
}

func (g *GXMouseInTheCampus) populate(x int64) {
	factor := g.oneOfPrimeFactor(x)
	cnt := int64(0)
	y := x
	for y%factor == 0 {
		cnt++
		y /= factor
	}
	if cnt > 1 {
		g.mu.put(x, 0, true)
	} else {
		g.mu.put(x, -g.mu.get(y), true)
	}
	g.euler.put(x, g.euler.get(y)*(x/y-x/y/factor), true)
}

func (g *GXMouseInTheCampus) muFunc(x int64) int64 {
	ans := g.mu.getOrDefault(x, -1)
	if ans == -1 {
		g.populate(x)
		ans = g.mu.get(x)
	}
	return ans
}

func (g *GXMouseInTheCampus) eulerFunc(x int64) int64 {
	ans := g.euler.getOrDefault(x, -1)
	if ans == -1 {
		g.populate(x)
		ans = g.euler.get(x)
	}
	return ans
}

func (g *GXMouseInTheCampus) solve(testNumber int, in *FastInput, out *FastOutput) {
	m := in.readLong()
	x := in.readLong()

	g.primes = LongPollardRho{}.findAllFactors(m).keys()
	allFactorOfM := NewLongList(20000)
	tmpList := NewLongList(20000)
	allPossiblePrimeFactor := NewLongList()
	for _, p := range g.primes {
		allPossiblePrimeFactor.add(p)
		allPossiblePrimeFactor.addAll(Factorization{}.factorizeNumberPrime(p - 1))
	}
	allPossiblePrimeFactor.unique()

	g.collect(allFactorOfM, m, 0)
	power := NewLongPower(ILongModularGetInstance(m))

	total := int64(1)
	for i := 0; i < allFactorOfM.size(); i++ {
		g := allFactorOfM.get(i)
		if g == m {
			continue
		}
		mg := m / g
		tmpList.clear()
		g.collect(tmpList, mg, 0)
		cnt := int64(0)
		for j := tmpList.size() - 1; j >= 0; j-- {
			t := tmpList.get(j)
			cnt += g.muFunc(t) * ((m - 1) / (t * g))
		}

		tmpList.clear()
		euler := g.eulerFunc(mg)
		primeFactors := tmpList
		for j := 0; j < allPossiblePrimeFactor.size(); j++ {
			p := allPossiblePrimeFactor.get(j)
			if euler%p == 0 {
				primeFactors.add(p)
			}
		}

		n := euler
		for j := 0; j < primeFactors.size(); j++ {
			p := primeFactors.get(j)
			for n%p == 0 && power.pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("IllegalStateException")
		}
		total += cnt / n
	}

	out.println(total)
}

func (g *GXMouseInTheCampus) collect(list *LongList, x int64, i int) {
	if i == len(g.primes) {
		list.add(x)
		return
	}
	g.collect(list, x, i+1)
	for x%g.primes[i] == 0 {
		x /= g.primes[i]
		g.collect(list, x, i+1)
	}
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := NewFastInput(os.Stdin)
		out := NewFastOutput(os.Stdout)
		solver := NewGXMouseInTheCampus()
		solver.solve(1, in, out)
		out.close()
	}()
	wg.Wait()
}
