package main

import (
	"bufio"
	"fmt"
	"os"
)

type Point struct {
	x int
	y int
}

type DSU struct {
	p    []int
	rank []int
	size []int
}

func NewDSU(n int) *DSU {
	p := make([]int, n)
	rank := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		p[i] = i
		rank[i] = 0
		size[i] = 1
	}
	return &DSU{p, rank, size}
}

func (dsu *DSU) Find(a int) int {
	if dsu.p[a] == dsu.p[dsu.p[a]] {
		return dsu.p[a]
	}
	dsu.p[a] = dsu.Find(dsu.p[a])
	return dsu.p[a]
}

func (dsu *DSU) Merge(a, b int) {
	a = dsu.Find(a)
	b = dsu.Find(b)
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

type id8 struct {
	slot    []int
	next    []int
	keys    []int
	values  []int
	alloc   int
	removed []bool
	mask    int
	size    int
	rehash  bool
	hasher  *Hasher
}

func Newid8(cap int, rehash bool) *id8 {
	mask := (1 << (32 - bits.LeadingZeros32(cap-1))) - 1
	slot := make([]int, mask+1)
	next := make([]int, cap+1)
	keys := make([]int, cap+1)
	values := make([]int, cap+1)
	removed := make([]bool, cap+1)
	return &id8{slot, next, keys, values, 0, removed, mask, 0, rehash, NewHasher()}
}

func (id8 *id8) DoubleCapacity() {
	newSize := max(len(id8.next)+10, len(id8.next)*2)
	id8.next = append(id8.next, make([]int, newSize-len(id8.next))...)
	id8.keys = append(id8.keys, make([]int, newSize-len(id8.keys))...)
	id8.values = append(id8.values, make([]int, newSize-len(id8.values))...)
	id8.removed = append(id8.removed, make([]bool, newSize-len(id8.removed))...)
}

func (id8 *id8) Alloc() {
	id8.alloc++
	if id8.alloc >= len(id8.next) {
		id8.DoubleCapacity()
	}
	id8.next[id8.alloc] = 0
	id8.removed[id8.alloc] = false
	id8.size++
}

func (id8 *id8) Rehash() {
	newSlots := make([]int, max(16, len(id8.slot)*2))
	newMask := len(newSlots) - 1
	for i := 0; i < len(id8.slot); i++ {
		if id8.slot[i] == 0 {
			continue
		}
		head := id8.slot[i]
		for head != 0 {
			n := id8.next[head]
			s := id8.hash(id8.keys[head]) & newMask
			id8.next[head] = newSlots[s]
			newSlots[s] = head
			head = n
		}
	}
	id8.slot = newSlots
	id8.mask = newMask
}

func (id8 *id8) Hash(x int) int {
	return id8.hasher.Hash(x)
}

func (id8 *id8) Put(x, y int) {
	id8.PutCover(x, y, true)
}

func (id8 *id8) PutCover(x, y int, cover bool) {
	h := id8.Hash(x)
	s := h & id8.mask
	if id8.slot[s] == 0 {
		id8.Alloc()
		id8.slot[s] = id8.alloc
		id8.keys[id8.alloc] = x
		id8.values[id8.alloc] = y
	} else {
		index := id8.id2(s, x)
		if id8.keys[index] != x {
			id8.Alloc()
			id8.next[index] = id8.alloc
			id8.keys[id8.alloc] = x
			id8.values[id8.alloc] = y
		} else if cover {
			id8.values[index] = y
		}
	}
	if id8.rehash && id8.size >= len(id8.slot) {
		id8.Rehash()
	}
}

func (id8 *id8) ContainKey(x int) bool {
	h := id8.Hash(x)
	s := h & id8.mask
	if id8.slot[s] == 0 {
		return false
	}
	return id8.keys[id8.id2(s, x)] == x
}

func (id8 *id8) id1(x, def int) int {
	h := id8.Hash(x)
	s := h & id8.mask
	if id8.slot[s] == 0 {
		return def
	}
	index := id8.id2(s, x)
	if id8.keys[index] == x {
		return id8.values[index]
	}
	return def
}

func (id8 *id8) Get(x int) int {
	return id8.id1(x, 0)
}

func (id8 *id8) id2(s, x int) int {
	iter := id8.slot[s]
	for id8.keys[iter] != x {
		if id8.next[iter] != 0 {
			iter = id8.next[iter]
		} else {
			return iter
		}
	}
	return iter
}

type id3 struct {
	values []int
	next   []int
	heads  []int
	alloc  int
}

func Newid3(qNum, totalCapacity int) *id3 {
	values := make([]int, totalCapacity+1)
	next := make([]int, totalCapacity+1)
	heads := make([]int, qNum)
	return &id3{values, next, heads, 0}
}

func (id3 *id3) AddLast(qId, x int) {
	id3.Alloc()
	id3.values[id3.alloc] = x
	id3.next[id3.alloc] = id3.heads[qId]
	id3.heads[qId] = id3.alloc
}

type id5 struct {
	index     int
	readIndex int
	id8       *id8
}

func (id5 *id5) HasNext() bool {
	for id5.index <= id5.id8.alloc && id5.id8.removed[id5.index] {
		id5.index++
	}
	return id5.index <= id5.id8.alloc
}

func (id5 *id5) Next() {
	if !id5.HasNext() {
		panic("No next element")
	}
	id5.readIndex = id5.index
	id5.index++
}

func (id5 *id5) Id4() int {
	return id5.id8.keys[id5.readIndex]
}

func (id5 *id5) Id6() int {
	return id5.id8.values[id5.readIndex]
}

type Hasher struct {
	time int64
}

func NewHasher() *Hasher {
	return &Hasher{time: time.Now().UnixNano() + time.Now().Unix()}
}

func (hasher *Hasher) Shuffle(x int64) int {
	x += hasher.time
	x += 0x9e3779b97f4a7c15
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb
	return int(x ^ (x >> 31))
}

func (hasher *Hasher) Hash(x int) int {
	return hasher.Shuffle(int64(x))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	pts := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &pts[i].x)
		fmt.Fscan(reader, &pts[i].y)
	}

	x := Newid8(n, false)
	y := Newid8(n, false)
	dsu := NewDSU(n)
	for i := 0; i < n; i++ {
		if x.ContainKey(pts[i].x) {
			dsu.Merge(x.Get(pts[i].x), i)
		}
		if y.ContainKey(pts[i].y) {
			dsu.Merge(y.Get(pts[i].y), i)
		}
		x.Put(pts[i].x, i)
		y.Put(pts[i].y, i)
	}

	xStack := Newid3(n, n)
	yStack := Newid3(n, n)
	for i := 0; i < n; i++ {
		xStack.AddLast(dsu.Find(i), pts[i].x)
		yStack.AddLast(dsu.Find(i), pts[i].y)
	}

	xList := make([]int, 0, n)
	yList := make([]int, 0, n)

	mod := NewModular(int(1e9) + 7)
	comb := NewCombination(2*n, mod)
	ans := 1
	for i := 0; i < n; i++ {
		if dsu.Find(i) != i {
			continue
		}
		xList = xList[:0]
		yList = yList[:0]
		for iterator := xStack.Iterator(i); iterator.HasNext(); {
			iterator.Next()
			xList = append(xList, iterator.Id4())
		}
		for iterator := yStack.Iterator(i); iterator.HasNext(); {
			iterator.Next()
			yList = append(yList, iterator.Id4())
		}
		xList = Unique(xList)
		yList = Unique(yList)

		line := len(xList) + len(yList)
		num := dsu.size[i]
		local := 0
		for j := 0; j <= num; j++ {
			local = mod.Plus(local, comb.Combination(line, j))
		}

		ans = mod.Mul(ans, local)
	}

	fmt.Fprintln(writer, ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) GetMod() int {
	return mod.m
}

func (mod *Modular) ValueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) Mul(x, y int) int {
	return mod.ValueOf(int64(x) * int64(y))
}

func (mod *Modular) Plus(x, y int) int {
	return mod.ValueOf(x + y)
}

type Factorial struct {
	fact  []int
	inv   []int
	mod   *Modular
	limit int
}

func NewFactorial(limit int, mod *Modular) *Factorial {
	fact := make([]int, limit+1)
	inv := make([]int, limit+1)
	fact[0] = 1
	inv[0] = 1
	for i := 1; i <= limit; i++ {
		fact[i] = mod.Mul(fact[i-1], i)
		inv[i] = mod.Mul(inv[i-1], mod.ValueOf(i).Inverse())
	}
	return &Factorial{fact, inv, mod, limit}
}

func (factorial *Factorial) Fact(n int) int {
	return factorial.fact[n]
}

func (factorial *Factorial) InvFact(n int) int {
	return factorial.inv[n]
}

type Combination struct {
	factorial *Factorial
	mod       *Modular
}

func NewCombination(limit int, mod *Modular) *Combination {
	factorial := NewFactorial(limit, mod)
	return &Combination{factorial, mod}
}

func (comb *Combination) Combination(m, n int) int {
	if n > m {
		return 0
	}
	return comb.mod.Mul(comb.mod.Mul(comb.factorial.Fact(m), comb.factorial.InvFact(n)), comb.factorial.InvFact(m-n))
}

func Unique(arr []int) []int {
	set := make(map[int]bool)
	uniqueArr := make([]int, 0, len(arr))
	for _, v := range arr {
		if !set[v] {
			set[v] = true
			uniqueArr = append(uniqueArr, v)
		}
	}
	return uniqueArr
}
