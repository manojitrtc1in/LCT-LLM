package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
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

func (d *DSU) Find(a int) int {
	if d.p[a] == d.p[d.p[a]] {
		return d.p[a]
	}
	d.p[a] = d.Find(d.p[a])
	return d.p[a]
}

func (d *DSU) Merge(a, b int) {
	a = d.Find(a)
	b = d.Find(b)
	if a == b {
		return
	}
	if d.rank[a] == d.rank[b] {
		d.rank[a]++
	}
	if d.rank[a] < d.rank[b] {
		a, b = b, a
	}
	d.size[a] += d.size[b]
	d.p[b] = a
}

type IntegerHashMap struct {
	slot    []int
	next    []int
	keys    []int
	values  []int
	alloc   int
	removed []bool
	mask    int
	size    int
	rehash  bool
}

func NewIntegerHashMap(cap int, rehash bool) *IntegerHashMap {
	mask := (1 << (32 - numberOfLeadingZeros(cap-1))) - 1
	slot := make([]int, mask+1)
	next := make([]int, cap+1)
	keys := make([]int, cap+1)
	values := make([]int, cap+1)
	removed := make([]bool, cap+1)
	return &IntegerHashMap{slot, next, keys, values, 0, removed, mask, 0, rehash}
}

func (m *IntegerHashMap) DoubleCapacity() {
	newSize := max(m.next.length+10, m.next.length*2)
	m.next = resize(m.next, newSize)
	m.keys = resize(m.keys, newSize)
	m.values = resize(m.values, newSize)
	m.removed = resize(m.removed, newSize)
}

func (m *IntegerHashMap) Alloc() {
	m.alloc++
	if m.alloc >= len(m.next) {
		m.DoubleCapacity()
	}
	m.next[m.alloc] = 0
	m.size++
}

func (m *IntegerHashMap) Rehash() {
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

func (m *IntegerHashMap) Put(x, y int) {
	m.PutWithCover(x, y, true)
}

func (m *IntegerHashMap) PutWithCover(x, y int, cover bool) {
	h := hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		m.Alloc()
		m.slot[s] = m.alloc
		m.keys[m.alloc] = x
		m.values[m.alloc] = y
	} else {
		index := m.FindIndexOrLastEntry(s, x)
		if m.keys[index] != x {
			m.Alloc()
			m.next[index] = m.alloc
			m.keys[m.alloc] = x
			m.values[m.alloc] = y
		} else if cover {
			m.values[index] = y
		}
	}
	if m.rehash && m.size >= len(m.slot) {
		m.Rehash()
	}
}

func (m *IntegerHashMap) ContainKey(x int) bool {
	h := hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		return false
	}
	return m.keys[m.FindIndexOrLastEntry(s, x)] == x
}

func (m *IntegerHashMap) GetOrDefault(x, def int) int {
	h := hash(x)
	s := h & m.mask
	if m.slot[s] == 0 {
		return def
	}
	index := m.FindIndexOrLastEntry(s, x)
	if m.keys[index] == x {
		return m.values[index]
	}
	return def
}

func (m *IntegerHashMap) Get(x int) int {
	return m.GetOrDefault(x, 0)
}

func (m *IntegerHashMap) FindIndexOrLastEntry(s, x int) int {
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

type IntegerMultiWayStack struct {
	values []int
	next   []int
	heads  []int
	alloc  int
}

func NewIntegerMultiWayStack(qNum, totalCapacity int) *IntegerMultiWayStack {
	values := make([]int, totalCapacity+1)
	next := make([]int, totalCapacity+1)
	heads := make([]int, qNum)
	return &IntegerMultiWayStack{values, next, heads, 0}
}

func (s *IntegerMultiWayStack) Iterator(queue int) *IntegerIterator {
	return &IntegerIterator{
		ele: s.heads[queue],
		s:   s,
	}
}

func (s *IntegerMultiWayStack) AddLast(qId, x int) {
	s.Alloc()
	s.values[s.alloc] = x
	s.next[s.alloc] = s.heads[qId]
	s.heads[qId] = s.alloc
}

type IntegerIterator struct {
	ele int
	s   *IntegerMultiWayStack
}

func (it *IntegerIterator) HasNext() bool {
	return it.ele != 0
}

func (it *IntegerIterator) Next() int {
	ans := it.s.values[it.ele]
	it.ele = it.s.next[it.ele]
	return ans
}

type FastInput struct {
	reader *bufio.Reader
}

func NewFastInput(reader io.Reader) *FastInput {
	return &FastInput{bufio.NewReader(reader)}
}

func (f *FastInput) ReadInt() int {
	x := 0
	sign := 1
	b := f.ReadByte()
	for b <= ' ' {
		b = f.ReadByte()
	}
	if b == '-' {
		sign = -1
		b = f.ReadByte()
	}
	for b >= '0' && b <= '9' {
		x = x*10 + int(b-'0')
		b = f.ReadByte()
	}
	return x * sign
}

func (f *FastInput) ReadByte() byte {
	buf := make([]byte, 1)
	f.reader.Read(buf)
	return buf[0]
}

func main() {
	reader := NewFastInput(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := reader.ReadInt()
	pts := make([]Point, n)
	for i := 0; i < n; i++ {
		pts[i] = Point{reader.ReadInt(), reader.ReadInt()}
	}

	x := NewIntegerHashMap(n, false)
	y := NewIntegerHashMap(n, false)
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

	xStack := NewIntegerMultiWayStack(n, n)
	yStack := NewIntegerMultiWayStack(n, n)
	for i := 0; i < n; i++ {
		xStack.AddLast(dsu.Find(i), pts[i].x)
		yStack.AddLast(dsu.Find(i), pts[i].y)
	}

	xList := make([]int, 0, n)
	yList := make([]int, 0, n)

	mod := NewModular(1e9 + 7)
	comb := NewCombination(2*n, mod)
	ans := 1
	for i := 0; i < n; i++ {
		if dsu.Find(i) != i {
			continue
		}
		xList = xList[:0]
		yList = yList[:0]
		for it := xStack.Iterator(i); it.HasNext(); {
			xList = append(xList, it.Next())
		}
		for it := yStack.Iterator(i); it.HasNext(); {
			yList = append(yList, it.Next())
		}
		xList = UniqueInts(xList)
		yList = UniqueInts(yList)

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

func numberOfLeadingZeros(i int) int {
	if i == 0 {
		return 32
	}
	n := 1
	if i>>16 == 0 {
		n += 16
		i <<= 16
	}
	if i>>24 == 0 {
		n += 8
		i <<= 8
	}
	if i>>28 == 0 {
		n += 4
		i <<= 4
	}
	if i>>30 == 0 {
		n += 2
		i <<= 2
	}
	n -= i >> 31
	return n
}

func resize(slice []int, size int) []int {
	newSlice := make([]int, size)
	copy(newSlice, slice)
	return newSlice
}

func hash(x int) int {
	return shuffle(x)
}

func shuffle(x int64) int {
	x += time
	x += 0x9e3779b97f4a7c15
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb
	return int(x ^ (x >> 31))
}

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m}
}

func (m *Modular) ValueOf(x int) int {
	x %= m.m
	if x < 0 {
		x += m.m
	}
	return x
}

func (m *Modular) Mul(x, y int) int {
	return m.ValueOf(int64(x) * int64(y))
}

func (m *Modular) Plus(x, y int) int {
	return m.ValueOf(x + y)
}

type Combination struct {
	factorial *Factorial
	modular   *Modular
}

func NewCombination(limit int, modular *Modular) *Combination {
	factorial := NewFactorial(limit, modular)
	return &Combination{factorial, modular}
}

func (c *Combination) Combination(m, n int) int {
	if n > m {
		return 0
	}
	return c.modular.Mul(c.modular.Mul(c.factorial.Fact(m), c.factorial.InvFact(n)), c.factorial.InvFact(m-n))
}

type Factorial struct {
	fact    []int
	inv     []int
	modular *Modular
}

func NewFactorial(limit int, modular *Modular) *Factorial {
	fact := make([]int, limit+1)
	inv := make([]int, limit+1)
	fact[0] = 1
	inv[0] = 1
	for i := 1; i <= limit; i++ {
		fact[i] = modular.Mul(fact[i-1], i)
		inv[i] = modular.Mul(inv[i-1], modular.Inv(i))
	}
	return &Factorial{fact, inv, modular}
}

func (f *Factorial) Fact(n int) int {
	return f.fact[n]
}

func (f *Factorial) InvFact(n int) int {
	return f.inv[n]
}

func UniqueInts(a []int) []int {
	m := make(map[int]bool)
	for _, x := range a {
		m[x] = true
	}
	b := make([]int, 0, len(m))
	for x := range m {
		b = append(b, x)
	}
	return b
}

func main() {
	thread := NewThread(nil, NewTaskAdapter(), "", 1<<27)
	thread.Start()
	thread.Join()
}

type TaskAdapter struct{}

func (t *TaskAdapter) Run() {
	inputStream := NewFastInput(os.Stdin)
	outputStream := NewFastOutput(os.Stdout)
	in := NewFastInputReader(inputStream)
	out := NewFastOutputWriter(outputStream)
	solver := NewCPointsLinesAndReadyMadeTitles()
	solver.Solve(1, in, out)
	out.Flush()
}

type CPointsLinesAndReadyMadeTitles struct{}

func NewCPointsLinesAndReadyMadeTitles() *CPointsLinesAndReadyMadeTitles {
	return &CPointsLinesAndReadyMadeTitles{}
}

func (c *CPointsLinesAndReadyMadeTitles) Solve(testNumber int, in *FastInputReader, out *FastOutputWriter) {
	n := in.ReadInt()
	pts := make([]Point, n)
	for i := 0; i < n; i++ {
		pts[i] = Point{in.ReadInt(), in.ReadInt()}
	}

	x := NewIntegerHashMap(n, false)
	y := NewIntegerHashMap(n, false)
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

	xStack := NewIntegerMultiWayStack(n, n)
	yStack := NewIntegerMultiWayStack(n, n)
	for i := 0; i < n; i++ {
		xStack.AddLast(dsu.Find(i), pts[i].x)
		yStack.AddLast(dsu.Find(i), pts[i].y)
	}

	xList := make([]int, 0, n)
	yList := make([]int, 0, n)

	mod := NewModular(1e9 + 7)
	comb := NewCombination(2*n, mod)
	ans := 1
	for i := 0; i < n; i++ {
		if dsu.Find(i) != i {
			continue
		}
		xList = xList[:0]
		yList = yList[:0]
		for it := xStack.Iterator(i); it.HasNext(); {
			xList = append(xList, it.Next())
		}
		for it := yStack.Iterator(i); it.HasNext(); {
			yList = append(yList, it.Next())
		}
		xList = UniqueInts(xList)
		yList = UniqueInts(yList)

		line := len(xList) + len(yList)
		num := dsu.size[i]
		local := 0
		for j := 0; j <= num; j++ {
			local = mod.Plus(local, comb.Combination(line, j))
		}

		ans = mod.Mul(ans, local)
	}

	out.Println(ans)
}

type FastOutputWriter struct {
	writer io.Writer
}

func NewFastOutputWriter(writer io.Writer) *FastOutputWriter {
	return &FastOutputWriter{writer}
}

func (w *FastOutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
}

func (w *FastOutputWriter) Flush() {
	if writer, ok := w.writer.(*bufio.Writer); ok {
		writer.Flush()
	}
}

type FastInputReader struct {
	reader *bufio.Reader
}

func NewFastInputReader(reader io.Reader) *FastInputReader {
	return &FastInputReader{bufio.NewReader(reader)}
}

func (r *FastInputReader) ReadInt() int {
	x, _ := strconv.Atoi(r.readString())
	return x
}

func (r *FastInputReader) readString() string {
	str, _ := r.reader.ReadString('\n')
	return str[:len(str)-1]
}

type FastOutput struct {
	writer *bufio.Writer
}

func NewFastOutput(writer io.Writer) *FastOutput {
	return &FastOutput{bufio.NewWriter(writer)}
}

func (w *FastOutput) Println(a ...interface{}) {
	fmt.Fprintln(w.writer, a...)
}

func (w *FastOutput) Close() {
	w.writer.Flush()
}

type Thread struct {
	task     Runnable
	name     string
	stack    int
	delegate *ThreadDelegate
}

func NewThread(group *ThreadGroup, task Runnable, name string, stack int) *Thread {
	return &Thread{task, name, stack, NewThreadDelegate(group)}
}

func (t *Thread) Start() {
	t.delegate.Start(t)
}

func (t *Thread) Join() {
	t.delegate.Join()
}

type ThreadDelegate struct {
	group *ThreadGroup
}

func NewThreadDelegate(group *ThreadGroup) *ThreadDelegate {
	return &ThreadDelegate{group}
}

func (d *ThreadDelegate) Start(t *Thread) {
	go func() {
		t.task.Run()
	}()
}

func (d *ThreadDelegate) Join() {}

type ThreadGroup struct{}

type Runnable interface {
	Run()
}

type TaskAdapter struct{}

func (t *TaskAdapter) Run() {
	inputStream := NewFastInput(os.Stdin)
	outputStream := NewFastOutput(os.Stdout)
	in := NewFastInputReader(inputStream)
	out := NewFastOutputWriter(outputStream)
	solver := NewCPointsLinesAndReadyMadeTitles()
	solver.Solve(1, in, out)
	out.Flush()
}

func main() {
	thread := NewThread(nil, NewTaskAdapter(), "", 1<<27)
	thread.Start()
	thread.Join()
}
