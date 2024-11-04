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
	return int(h ^ (h >> 16))
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

func (in *FastInput) read() int {
	for in.bufLen == in.bufOffset {
		in.bufOffset = 0
		n, err := in.is.Read(in.buf)
		if err != nil {
			in.bufLen = -1
			return -1
		}
		in.bufLen = n
	}
	return int(in.buf[in.bufOffset])
}

func (in *FastInput) skipBlank() {
	for in.next >= 0 && in.next <= 32 {
		in.next = in.read()
	}
}

func (in *FastInput) readLong() int64 {
	sign := int64(1)

	in.skipBlank()
	if in.next == '+' || in.next == '-' {
		if in.next == '+' {
			sign = 1
		} else {
			sign = -1
		}
		in.next = in.read()
	}

	val := int64(0)
	if sign == 1 {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 + int64(in.next-'0')
			in.next = in.read()
		}
	} else {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 - int64(in.next-'0')
			in.next = in.read()
		}
	}

	return val
}

type GXMouseInTheCampus struct {
	mu    *LongHashMap
	euler *LongHashMap
	primes []int64
}

func NewGXMouseInTheCampus() *GXMouseInTheCampus {
	mu := NewLongHashMap(100000, false)
	euler := NewLongHashMap(100000, false)
	mu.put(1, 1)
	euler.put(1, 1)
	return &GXMouseInTheCampus{
		mu:    mu,
		euler: euler,
	}
}

func (solver *GXMouseInTheCampus) oneOfPrimeFactor(x int64) int64 {
	for _, p := range solver.primes {
		if x%p == 0 {
			return p
		}
	}
	return x
}

func (solver *GXMouseInTheCampus) populate(x int64) {
	factor := solver.oneOfPrimeFactor(x)
	cnt := int64(0)
	y := x
	for y%factor == 0 {
		cnt++
		y /= factor
	}
	if cnt > 1 {
		solver.mu.put(x, 0)
	} else {
		solver.mu.put(x, -solver.mu.getOrDefault(y, -1))
	}
	solver.euler.put(x, solver.euler.getOrDefault(y, -1)*(x/y-x/y/factor))
}

func (solver *GXMouseInTheCampus) mu(x int64) int64 {
	ans := solver.mu.getOrDefault(x, -1)
	if ans == -1 {
		solver.populate(x)
		ans = solver.mu.get(x)
	}
	return ans
}

func (solver *GXMouseInTheCampus) euler(x int64) int64 {
	ans := solver.euler.getOrDefault(x, -1)
	if ans == -1 {
		solver.populate(x)
		ans = solver.euler.get(x)
	}
	return ans
}

func (solver *GXMouseInTheCampus) collect(list *[]int64, x int64, i int) {
	if i == len(solver.primes) {
		*list = append(*list, x)
		return
	}
	solver.collect(list, x, i+1)
	for x%solver.primes[i] == 0 {
		x /= solver.primes[i]
		solver.collect(list, x, i+1)
	}
}

func (solver *GXMouseInTheCampus) solve(testNumber int, in *FastInput, out io.Writer) {
	m := in.readLong()
	x := in.readLong()

	solver.primes = Factorization.factorizeNumberPrime(m)
	allFactorOfM := make([]int64, 0, 20000)
	tmpList := make([]int64, 0, 20000)
	allPossiblePrimeFactor := make([]int64, 0)

	for _, p := range solver.primes {
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, p)
		allPossiblePrimeFactor = append(allPossiblePrimeFactor, Factorization.factorizeNumberPrime(p-1)...)
	}
	allPossiblePrimeFactor = unique(allPossiblePrimeFactor)

	solver.collect(&allFactorOfM, m, 0)
	power := NewLongPower(ILongModular(m))

	total := int64(1)
	for _, g := range allFactorOfM {
		if g == m {
			continue
		}
		mg := m / g
		tmpList = tmpList[:0]
		solver.collect(&tmpList, mg, 0)
		cnt := int64(0)
		for j := len(tmpList) - 1; j >= 0; j-- {
			t := tmpList[j]
			cnt += solver.mu(t) * ((m - 1) / (t * g))
		}

		tmpList = tmpList[:0]
		euler := solver.euler(mg)
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
			panic("IllegalStateException")
		}
		total += cnt / n
	}

	fmt.Fprintln(out, total)
}

type LongPower struct {
	modular ILongModular
}

func NewLongPower(modular ILongModular) *LongPower {
	return &LongPower{modular: modular}
}

func (lp *LongPower) pow(x, n int64) int64 {
	if n == 0 {
		return 1
	}
	r := lp.pow(x, n>>1)
	r = lp.modular.mul(r, r)
	if n&1 == 1 {
		r = lp.modular.mul(r, x)
	}
	return r
}

type ILongModular interface {
	mul(a, b int64) int64
}

func getInstance(mod int64) ILongModular {
	if mod <= (1 << 54) {
		return &LongModularDanger{m: mod}
	}
	return &LongModular{m: mod}
}

type LongModular struct {
	m int64
}

func (lm *LongModular) mul(a, b int64) int64 {
	return b == 0 ? 0 : ((lm.mul(a, b>>1)<<1)%lm.m + a*(b&1)) % lm.m
}

type LongModularDanger struct {
	m int64
}

func (lmd *LongModularDanger) mul(a, b int64) int64 {
	return DigitUtils.mulMod(a, b, lmd.m)
}

type Factorization struct{}

func (f *Factorization) factorizeNumberPrime(x int64) []int64 {
	ans := []int64{}
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

type DigitUtils struct{}

func (du *DigitUtils) round(x float64) int64 {
	if x >= 0 {
		return int64(x + 0.5)
	}
	return int64(x - 0.5)
}

func (du *DigitUtils) mod(x, mod int64) int64 {
	x %= mod
	if x < 0 {
		x += mod
	}
	return x
}

func (du *DigitUtils) mulMod(a, b, mod int64) int64 {
	k := du.round(float64(a)/float64(mod) * float64(b))
	return du.mod(a*b-k*mod, mod)
}

func unique(list []int64) []int64 {
	seen := make(map[int64]struct{})
	result := []int64{}
	for _, v := range list {
		if _, ok := seen[v]; !ok {
			seen[v] = struct{}{}
			result = append(result, v)
		}
	}
	return result
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := NewFastInput(os.Stdin)
		out := os.Stdout
		solver := NewGXMouseInTheCampus()
		solver.solve(1, in, out)
	}()
	wg.Wait()
}
