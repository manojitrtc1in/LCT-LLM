package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

type FastInput struct {
	reader *bufio.Reader
}

func NewFastInput(reader io.Reader) *FastInput {
	return &FastInput{reader: bufio.NewReader(reader)}
}

func (f *FastInput) ReadLong() int64 {
	token := f.ReadToken()
	num, _ := strconv.ParseInt(token, 10, 64)
	return num
}

func (f *FastInput) ReadToken() string {
	token, _ := f.reader.ReadString('\n')
	return token[:len(token)-1]
}

type FastOutput struct {
	writer *bufio.Writer
}

func NewFastOutput(writer io.Writer) *FastOutput {
	return &FastOutput{writer: bufio.NewWriter(writer)}
}

func (f *FastOutput) Println(a ...interface{}) {
	fmt.Fprintln(f.writer, a...)
}

func (f *FastOutput) Flush() {
	f.writer.Flush()
}

type id1 struct {
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

func NewID1(cap int, rehash bool) *id1 {
	mask := (1 << (32 - bits.LeadingZeros32(cap-1))) - 1
	return &id1{
		slot:    make([]int, mask+1),
		next:    make([]int, cap+1),
		keys:    make([]int64, cap+1),
		values:  make([]int64, cap+1),
		removed: make([]bool, cap+1),
		mask:    mask,
		rehash:  rehash,
	}
}

func (m *id1) doubleCapacity() {
	newSize := max(len(m.next)+10, len(m.next)*2)
	m.next = append(m.next, make([]int, newSize-len(m.next))...)
	m.keys = append(m.keys, make([]int64, newSize-len(m.keys))...)
	m.values = append(m.values, make([]int64, newSize-len(m.values))...)
	m.removed = append(m.removed, make([]bool, newSize-len(m.removed))...)
}

func (m *id1) ensureSpace(req int) {
	if req > len(m.next) {
		m.doubleCapacity()
	}
}

func (m *id1) alloc() {
	m.alloc++
	if m.alloc >= len(m.next) {
		m.doubleCapacity()
	}
	m.next[m.alloc] = 0
	m.removed[m.alloc] = false
	m.size++
}

func (m *id1) rehash() {
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

func (m *id1) hash(x int64) int {
	h := int(x)
	return h ^ (h >> 16)
}

func (m *id1) put(x, y int64) {
	m.putWithCover(x, y, true)
}

func (m *id1) putWithCover(x, y int64, cover bool) {
	h := m.hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		m.alloc()
		m.slot[s] = m.alloc
		m.keys[m.alloc] = x
		m.values[m.alloc] = y
	} else {
		index := m.id8(s, x)
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

func (m *id1) id5(x, def int64) int64 {
	h := m.hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		return def
	}
	index := m.id8(s, x)
	if m.keys[index] == x {
		return m.values[index]
	}
	return def
}

func (m *id1) get(x int64) int64 {
	return m.id5(x, 0)
}

func (m *id1) id8(s int, x int64) int {
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

type id7 struct {
	index     int
	readIndex int
	keys      []int64
	values    []int64
	removed   []bool
}

func (it *id7) hasNext() bool {
	for it.index < len(it.keys) && it.removed[it.index] {
		it.index++
	}
	return it.index < len(it.keys)
}

func (it *id7) next() {
	if !it.hasNext() {
		panic("No more elements")
	}
	it.readIndex = it.index
	it.index++
}

func (it *id7) id10() int64 {
	return it.keys[it.readIndex]
}

func (it *id7) id11() int64 {
	return it.values[it.readIndex]
}

func (m *id1) iterator() *id7 {
	return &id7{
		index:     1,
		readIndex: -1,
		keys:      m.keys,
		values:    m.values,
		removed:   m.removed,
	}
}

type id12 interface {
	mul(a, b int64) int64
}

type id4 struct {
	m int64
}

func NewID4(m int64) *id4 {
	return &id4{m: m}
}

func (m *id4) mul(a, b int64) int64 {
	return (a * b) % m
}

type id6 struct {
	m int64
}

func NewID6(m int64) *id6 {
	return &id6{m: m}
}

func (m *id6) mul(a, b int64) int64 {
	if b == 0 {
		return 0
	}
	k := (m.mul(a, b>>1) << 1) % m.m
	if b&1 == 1 {
		k = (k + a) % m.m
	}
	return k
}

type LongList struct {
	size int
	cap  int
	data []int64
}

func NewLongList(cap int) *LongList {
	return &LongList{
		size: 0,
		cap:  cap,
		data: make([]int64, cap),
	}
}

func (l *LongList) ensureSpace(req int) {
	if req > l.cap {
		newCap := max(l.cap+10, l.cap*2)
		newData := make([]int64, newCap)
		copy(newData, l.data)
		l.data = newData
		l.cap = newCap
	}
}

func (l *LongList) add(x int64) {
	l.ensureSpace(l.size + 1)
	l.data[l.size] = x
	l.size++
}

func (l *LongList) addAll(x []int64, offset, length int) {
	l.ensureSpace(l.size + length)
	copy(l.data[l.size:], x[offset:offset+length])
	l.size += length
}

func (l *LongList) addAllList(list *LongList) {
	l.addAll(list.data, 0, list.size)
}

func (l *LongList) sort() {
	if l.size <= 1 {
		return
	}
	RandomizedShuffle(l.data[:l.size])
	sort.Slice(l.data[:l.size], func(i, j int) bool {
		return l.data[i] < l.data[j]
	})
}

func (l *LongList) unique() {
	if l.size <= 1 {
		return
	}
	l.sort()
	wpos := 1
	for i := 1; i < l.size; i++ {
		if l.data[i] != l.data[wpos-1] {
			l.data[wpos] = l.data[i]
			wpos++
		}
	}
	l.size = wpos
}

func (l *LongList) Size() int {
	return l.size
}

func (l *LongList) Get(i int) int64 {
	if i < 0 || i >= l.size {
		panic("Index out of range")
	}
	return l.data[i]
}

func (l *LongList) ToArray() []int64 {
	return l.data[:l.size]
}

func (l *LongList) Clear() {
	l.size = 0
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	input := NewFastInput(os.Stdin)
	output := NewFastOutput(os.Stdout)

	m := input.ReadLong()
	x := input.ReadLong()

	primes := Factorization(m).ToArray()
	id9 := NewLongList(20000)
	tmpList := NewLongList(20000)
	id2 := NewLongList()
	for _, p := range primes {
		id2.add(p)
		id2.addAll(Factorization(p-1).ToArray(), 0, Factorization(p-1).Size())
	}
	id2.unique()

	collect(id9, m, 0)
	power := NewLongPower(GetInstance(m))

	total := int64(1)
	for i := 0; i < id9.Size(); i++ {
		g := id9.Get(i)
		if g == m {
			continue
		}
		mg := m / g
		tmpList.Clear()
		collect(tmpList, mg, 0)
		cnt := int64(0)
		for j := tmpList.Size() - 1; j >= 0; j-- {
			t := tmpList.Get(j)
			cnt += mu(t) * ((m - 1) / (t * g))
		}

		tmpList.Clear()
		euler := euler(mg)
		primeFactors := tmpList
		for j := 0; j < id2.Size(); j++ {
			p := id2.Get(j)
			if euler%p == 0 {
				primeFactors.add(p)
			}
		}

		n := euler
		for j := 0; j < primeFactors.Size(); j++ {
			p := primeFactors.Get(j)
			for n%p == 0 && power.pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("Invalid state")
		}
		total += cnt / n
	}

	output.Println(total)
	output.Flush()
}

type id12 interface {
	pow(x, n int64) int64
}

type LongPower struct {
	modular id12
}

func NewLongPower(modular id12) *LongPower {
	return &LongPower{modular: modular}
}

func (p *LongPower) pow(x, n int64) int64 {
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

func Factorization(x int64) *LongList {
	ans := NewLongList()
	for i := int64(2); i*i <= x; i++ {
		if x%i != 0 {
			continue
		}
		ans.add(i)
		for x%i == 0 {
			x /= i
		}
	}
	if x > 1 {
		ans.add(x)
	}
	return ans
}

func collect(list *LongList, x int64, i int) {
	if i == len(primes) {
		list.add(x)
		return
	}
	collect(list, x, i+1)
	for x%primes[i] == 0 {
		x /= primes[i]
		collect(list, x, i+1)
	}
}

func mu(x int64) int64 {
	ans := muMap.Get(x, -1)
	if ans == -1 {
		populate(x)
		ans = muMap.Get(x)
	}
	return ans
}

func euler(x int64) int64 {
	ans := eulerMap.Get(x, -1)
	if ans == -1 {
		populate(x)
		ans = eulerMap.Get(x)
	}
	return ans
}

func populate(x int64) {
	factor := id0(x)
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

func id0(x int64) int64 {
	for _, p := range primes {
		if x%p == 0 {
			return p
		}
	}
	return x
}

var (
	primes  []int64
	muMap   = NewID1(100000, false)
	eulerMap = NewID1(100000, false)
)

func id9(m int64) *LongList {
	ans := NewLongList(20000)
	tmpList := NewLongList(20000)
	id2 := NewLongList()
	for _, p := range primes {
		id2.add(p)
		id2.addAll(Factorization(p-1).ToArray(), 0, Factorization(p-1).Size())
	}
	id2.unique()

	collect(ans, m, 0)
	power := NewLongPower(GetInstance(m))

	for i := 0; i < ans.Size(); i++ {
		g := ans.Get(i)
		if g == m {
			continue
		}
		mg := m / g
		tmpList.Clear()
		collect(tmpList, mg, 0)
		cnt := int64(0)
		for j := tmpList.Size() - 1; j >= 0; j-- {
			t := tmpList.Get(j)
			cnt += mu(t) * ((m - 1) / (t * g))
		}

		tmpList.Clear()
		euler := euler(mg)
		primeFactors := tmpList
		for j := 0; j < id2.Size(); j++ {
			p := id2.Get(j)
			if euler%p == 0 {
				primeFactors.add(p)
			}
		}

		n := euler
		for j := 0; j < primeFactors.Size(); j++ {
			p := primeFactors.Get(j)
			for n%p == 0 && power.pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("Invalid state")
		}
		ans.Set(i, cnt/n)
	}

	return ans
}

func main() {
	m := readLong()
	x := readLong()

	primes = Factorization(m).ToArray()
	id9 := id9(m)

	total := int64(1)
	for i := 0; i < id9.Size(); i++ {
		total += id9.Get(i)
	}

	println(total)
}

var (
	reader = bufio.NewReader(os.Stdin)
)

func readLong() int64 {
	token, _ := reader.ReadString('\n')
	num, _ := strconv.ParseInt(token[:len(token)-1], 10, 64)
	return num
}
