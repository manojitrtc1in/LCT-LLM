package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

var (
	modular Modular
	power   Power
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	modular = NewModular(998244353)
	power = NewPower(modular)

	var n, k int
	fmt.Fscan(reader, &n, &k)

	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		var x int
		fmt.Fscan(reader, &x)
		allow[x] = 1
	}

	p := NewIntList()
	p.AddAll(allow)

	m := n / 2
	last := p.Clone()
	ntt := NewNumberTheoryTransform(modular, 3)
	lists := make([]*IntList, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last.Clone())
		}
		ntt.Pow2(last)
		Normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := NewIntList()
	ntt.MulByPQ(lists, prod)

	ans := 0
	for i := 0; i < prod.Size(); i++ {
		plus := prod.Get(i)
		ans = modular.Plus(ans, modular.Mul(plus, plus))
	}

	fmt.Fprintln(writer, ans)
}

type Modular struct {
	m int
}

func NewModular(m int) Modular {
	return Modular{m: m}
}

func (mod Modular) ValueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod Modular) Mul(x, y int) int {
	return mod.ValueOf(x * y)
}

func (mod Modular) Plus(x, y int) int {
	return mod.ValueOf(x + y)
}

type Power struct {
	modular Modular
}

func NewPower(modular Modular) Power {
	return Power{modular: modular}
}

func (power Power) Pow(x, n int) int {
	if n == 0 {
		return power.modular.ValueOf(1)
	}
	r := power.Pow(x, n>>1)
	r = power.modular.ValueOf(r * r)
	if n&1 == 1 {
		r = power.modular.ValueOf(r * x)
	}
	return r
}

type IntList struct {
	size int
	cap  int
	data []int
}

func NewIntList() *IntList {
	return &IntList{}
}

func (list *IntList) Get(i int) int {
	list.checkRange(i)
	return list.data[i]
}

func (list *IntList) AddAll(x []int) {
	list.AddAllOffset(x, 0, len(x))
}

func (list *IntList) AddAllOffset(x []int, offset, length int) {
	list.ensureSpace(list.size + length)
	copy(list.data[list.size:], x[offset:offset+length])
	list.size += length
}

func (list *IntList) AddAllList(other *IntList) {
	list.AddAllOffset(other.data, 0, other.size)
}

func (list *IntList) ExpandWith(x, length int) {
	list.ensureSpace(length)
	for list.size < length {
		list.data[list.size] = x
		list.size++
	}
}

func (list *IntList) Retain(n int) {
	if n < 0 {
		panic("n must be non-negative")
	}
	if n >= list.size {
		return
	}
	list.size = n
}

func (list *IntList) Size() int {
	return list.size
}

func (list *IntList) ToArray() []int {
	return append([]int(nil), list.data[:list.size]...)
}

func (list *IntList) Clear() {
	list.size = 0
}

func (list *IntList) Clone() *IntList {
	clone := &IntList{}
	clone.AddAllList(list)
	return clone
}

func (list *IntList) ensureSpace(space int) {
	if space <= list.cap {
		return
	}
	newData := make([]int, max(list.cap<<1, space))
	copy(newData, list.data)
	list.data = newData
	list.cap = space
}

func (list *IntList) checkRange(i int) {
	if i < 0 || i >= list.size {
		panic("index out of range")
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type NumberTheoryTransform struct {
	modular Modular
	g       int
	wCache  []int
	invCache []int
}

func NewNumberTheoryTransform(modular Modular, g int) NumberTheoryTransform {
	ntt := NumberTheoryTransform{
		modular: modular,
		g:       g,
		wCache:  make([]int, 30),
		invCache: make([]int, 30),
	}
	for i := 0; i < 30; i++ {
		s := 1 << i
		ntt.wCache[i] = power.Pow(ntt.g, (modular.m-1)/2/s)
		ntt.invCache[i] = power.Pow(s, modular.m-2)
	}
	return ntt
}

func (ntt *NumberTheoryTransform) DotMul(a, b, c []int, m int) {
	for i := 0; i < 1<<m; i++ {
		c[i] = modular.Mul(a[i], b[i])
	}
}

func (ntt *NumberTheoryTransform) DFT(p []int, m int) {
	n := 1 << m

	shift := 32 - bits.LeadingZeros32(uint32(n))
	for i := 1; i < n; i++ {
		j := bits.Reverse32(uint32(i << shift))
		if i < int(j) {
			p[i], p[j] = p[j], p[i]
		}
	}

	w := 0
	t := 0
	for d := 0; d < m; d++ {
		w1 := ntt.wCache[d]
		s := 1 << d
		s2 := s << 1
		for i := 0; i < n; i += s2 {
			w = 1
			for j := 0; j < s; j++ {
				a := i + j
				b := a + s
				t = modular.Mul(w, p[b])
				p[b] = modular.Plus(p[a], -t)
				p[a] = modular.Plus(p[a], t)
				w = modular.Mul(w, w1)
			}
		}
	}
}

func (ntt *NumberTheoryTransform) IDFT(p []int, m int) {
	ntt.DFT(p, m)

	n := 1 << m
	invN := ntt.invCache[m]

	p[0] = modular.Mul(p[0], invN)
	p[n/2] = modular.Mul(p[n/2], invN)
	for i := 1; i < n/2; i++ {
		a := p[n-i]
		p[n-i] = modular.Mul(p[i], invN)
		p[i] = modular.Mul(a, invN)
	}
}

func (ntt *NumberTheoryTransform) MulByPQ(lists []*IntList, ans *IntList) {
	pqs := make(PriorityQueue, 0)
	for _, list := range lists {
		clone := list.Clone()
		pqs.Push(clone)
	}
	for len(pqs) > 1 {
		a := pqs.Pop()
		b := pqs.Pop()
		ntt.MultiplyAndStoreAnswerIntoA(a, b)
		pqs.Push(a)
	}
	last := pqs.Pop()
	ans.Clear()
	ans.AddAllList(last)
}

func (ntt *NumberTheoryTransform) Pow2(a *IntList) {
	rankAns := (a.Size() - 1) * 2
	proper := ceilLog(rankAns + 1)
	a.ExpandWith(0, 1<<proper)
	ntt.DFT(a.data, proper)
	ntt.DotMul(a.data, a.data, a.data, proper)
	ntt.IDFT(a.data, proper)
	Normalize(a)
}

func (ntt *NumberTheoryTransform) MultiplyAndStoreAnswerIntoA(a, b *IntList) {
	rankAns := a.Size() - 1 + b.Size() - 1
	proper := ceilLog(rankAns + 1)
	a.ExpandWith(0, 1<<proper)
	b.ExpandWith(0, 1<<proper)
	ntt.DFT(a.data, proper)
	ntt.DFT(b.data, proper)
	ntt.DotMul(a.data, b.data, a.data, proper)
	ntt.IDFT(a.data, proper)
	Normalize(a)
}

func ceilLog(x int) int {
	return 32 - bits.LeadingZeros32(uint32(x-1))
}

func Normalize(list *IntList) {
	list.Retain(RankOf(list) + 1)
}

func RankOf(p *IntList) int {
	r := p.Size() - 1
	for r >= 0 && p.Get(r) == 0 {
		r--
	}
	return max(0, r)
}

type PriorityQueue []*IntList

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].Size() < pq[j].Size()
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*IntList)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() *IntList {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func main() {
	thread := make(chan struct{}, 1)
	thread <- struct{}{}
	<-thread
}

type TaskAdapter struct{}

func (task *TaskAdapter) Run() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	in := NewFastInput(reader)
	out := NewFastOutput(writer)
	solver := NewTaskG()
	solver.Solve(1, in, out)
	out.Close()
}

type TaskG struct {
	mod Modular
}

func NewTaskG() *TaskG {
	return &TaskG{mod: NewModular(998244353)}
}

func (task *TaskG) Solve(testNumber int, in *FastInput, out *FastOutput) {
	n := in.ReadInt()
	k := in.ReadInt()
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		x := in.ReadInt()
		allow[x] = 1
	}
	p := NewIntList()
	p.AddAll(allow)

	m := n / 2
	last := p.Clone()
	ntt := NewNumberTheoryTransform(task.mod, 3)
	lists := make([]*IntList, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last.Clone())
		}
		ntt.Pow2(last)
		Normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := NewIntList()
	ntt.MulByPQ(lists, prod)

	ans := 0
	for i := 0; i < prod.Size(); i++ {
		plus := prod.Get(i)
		ans = task.mod.Plus(ans, task.mod.Mul(plus, plus))
	}

	out.Println(ans)
}

type FastInput struct {
	reader *bufio.Reader
}

func NewFastInput(reader io.Reader) *FastInput {
	return &FastInput{reader: bufio.NewReader(reader)}
}

func (in *FastInput) ReadInt() int {
	x, _ := in.readInt()
	return x
}

func (in *FastInput) readInt() (int, error) {
	sign := 1

	in.skipBlank()
	if in.next == '+' || in.next == '-' {
		if in.next == '-' {
			sign = -1
		}
		in.next = in.read()
	}

	val := 0
	if sign == 1 {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 + int(in.next-'0')
			in.next = in.read()
		}
	} else {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 - int(in.next-'0')
			in.next = in.read()
		}
	}

	return val, nil
}

func (in *FastInput) skipBlank() {
	for in.next >= 0 && in.next <= 32 {
		in.next = in.read()
	}
}

func (in *FastInput) read() int {
	if in.bufLen == in.bufOffset {
		in.bufOffset = 0
		in.bufLen = in.fill()
		if in.bufLen == 0 {
			return -1
		}
	}
	in.bufOffset++
	return int(in.buf[in.bufOffset-1])
}

func (in *FastInput) fill() int {
	if in.buf, in.bufLen = in.reader.ReadBytes('\n'); in.bufLen != 0 {
		return in.bufLen
	}
	if in.buf, in.bufLen = in.reader.ReadBytes('\r'); in.bufLen != 0 {
		return in.bufLen
	}
	return 0
}

type FastOutput struct {
	writer *bufio.Writer
}

func NewFastOutput(writer io.Writer) *FastOutput {
	return &FastOutput{writer: bufio.NewWriter(writer)}
}

func (out *FastOutput) Println(c int) {
	fmt.Fprintln(out.writer, c)
}

func (out *FastOutput) Close() {
	out.writer.Flush()
}

type IntList struct {
	size int
	cap  int
	data []int
}

func NewIntList() *IntList {
	return &IntList{}
}

func (list *IntList) Get(i int) int {
	list.checkRange(i)
	return list.data[i]
}

func (list *IntList) AddAll(x []int) {
	list.AddAllOffset(x, 0, len(x))
}

func (list *IntList) AddAllOffset(x []int, offset, length int) {
	list.ensureSpace(list.size + length)
	copy(list.data[list.size:], x[offset:offset+length])
	list.size += length
}

func (list *IntList) AddAllList(other *IntList) {
	list.AddAllOffset(other.data, 0, other.size)
}

func (list *IntList) ExpandWith(x, length int) {
	list.ensureSpace(length)
	for list.size < length {
		list.data[list.size] = x
		list.size++
	}
}

func (list *IntList) Retain(n int) {
	if n < 0 {
		panic("n must be non-negative")
	}
	if n >= list.size {
		return
	}
	list.size = n
}

func (list *IntList) Size() int {
	return list.size
}

func (list *IntList) ToArray() []int {
	return append([]int(nil), list.data[:list.size]...)
}

func (list *IntList) Clear() {
	list.size = 0
}

func (list *IntList) Clone() *IntList {
	clone := &IntList{}
	clone.AddAllList(list)
	return clone
}

func (list *IntList) ensureSpace(space int) {
	if space <= list.cap {
		return
	}
	newData := make([]int, max(list.cap<<1, space))
	copy(newData, list.data)
	list.data = newData
	list.cap = space
}

func (list *IntList) checkRange(i int) {
	if i < 0 || i >= list.size {
		panic("index out of range")
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
