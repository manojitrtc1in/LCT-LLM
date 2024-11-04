package main

import (
	"fmt"
	"math/rand"
	"sync"
)

type Point struct {
	x, y int
}

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) valueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) mul(x, y int) int {
	return mod.valueOf(x * y)
}

func (mod *Modular) plus(x, y int) int {
	return mod.valueOf(x + y)
}

type DSU struct {
	p, rank, size []int
}

func NewDSU(n int) *DSU {
	dsu := &DSU{
		p:    make([]int, n),
		rank: make([]int, n),
		size: make([]int, n),
	}
	dsu.reset()
	return dsu
}

func (dsu *DSU) reset() {
	for i := range dsu.p {
		dsu.p[i] = i
		dsu.rank[i] = 0
		dsu.size[i] = 1
	}
}

func (dsu *DSU) find(a int) int {
	if dsu.p[a] != dsu.p[dsu.p[a]] {
		dsu.p[a] = dsu.find(dsu.p[a])
	}
	return dsu.p[a]
}

func (dsu *DSU) merge(a, b int) {
	a = dsu.find(a)
	b = dsu.find(b)
	if a == b {
		return
	}
	if dsu.rank[a] == dsu.rank[b] {
		dsu.rank[a]++
	}
	if dsu.rank[a] < dsu.rank[b] {
		a, b = b, a
	}
	dsu.size[a] += dsu.size[b]
	dsu.p[b] = a
}

type IntegerHashMap struct {
	slot, next, keys, values []int
	alloc                     int
	rehash                    bool
	mask                      int
	size                      int
}

func NewIntegerHashMap(cap int, rehash bool) *IntegerHashMap {
	mask := (1 << (32 - bits.LeadingZeros32(uint32(cap-1)))) - 1
	return &IntegerHashMap{
		slot:  make([]int, mask+1),
		next:  make([]int, cap+1),
		keys:  make([]int, cap+1),
		values: make([]int, cap+1),
		rehash: rehash,
		mask:   mask,
	}
}

func (m *IntegerHashMap) alloc() {
	m.alloc++
	if m.alloc >= len(m.next) {
		m.doubleCapacity()
	}
	m.next[m.alloc] = 0
	m.size++
}

func (m *IntegerHashMap) doubleCapacity() {
	newSize := max(len(m.next)+10, len(m.next)*2)
	m.next = append(m.next, make([]int, newSize-len(m.next))...)
	m.keys = append(m.keys, make([]int, newSize-len(m.keys))...)
	m.values = append(m.values, make([]int, newSize-len(m.values))...)
}

func (m *IntegerHashMap) put(x, y int) {
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
		}
	}
	if m.rehash && m.size >= len(m.slot) {
		m.rehash()
	}
}

func (m *IntegerHashMap) hash(x int) int {
	return x // Simplified hash function
}

func (m *IntegerHashMap) findIndexOrLastEntry(s, x int) int {
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
	data []byte
}

func NewFastInput() *FastInput {
	return &FastInput{}
}

func (in *FastInput) readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

type FastOutput struct {
	cache []byte
}

func NewFastOutput() *FastOutput {
	return &FastOutput{}
}

func (out *FastOutput) println(x int) {
	out.cache = append(out.cache, fmt.Sprintf("%d\n", x)...)
}

func (out *FastOutput) flush() {
	fmt.Print(string(out.cache))
	out.cache = nil
}

type CPointsLinesAndReadyMadeTitles struct{}

func (solver *CPointsLinesAndReadyMadeTitles) solve(testNumber int, in *FastInput, out *FastOutput) {
	n := in.readInt()
	pts := make([]Point, n)
	for i := 0; i < n; i++ {
		pts[i] = Point{x: in.readInt(), y: in.readInt()}
	}

	x := NewIntegerHashMap(n, false)
	y := NewIntegerHashMap(n, false)
	dsu := NewDSU(n)
	for i := 0; i < n; i++ {
		if x.containKey(pts[i].x) {
			dsu.merge(x.get(pts[i].x), i)
		}
		if y.containKey(pts[i].y) {
			dsu.merge(y.get(pts[i].y), i)
		}
		x.put(pts[i].x, i)
		y.put(pts[i].y, i)
	}

	ans := 1
	mod := NewModular(1e9 + 7)
	for i := 0; i < n; i++ {
		if dsu.find(i) != i {
			continue
		}
		local := 0
		for j := 0; j <= dsu.size[i]; j++ {
			local = mod.plus(local, comb.combination(line, j))
		}
		ans = mod.mul(ans, local)
	}

	out.println(ans)
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := NewFastInput()
		out := NewFastOutput()
		solver := &CPointsLinesAndReadyMadeTitles{}
		solver.solve(1, in, out)
		out.flush()
	}()
	wg.Wait()
}
