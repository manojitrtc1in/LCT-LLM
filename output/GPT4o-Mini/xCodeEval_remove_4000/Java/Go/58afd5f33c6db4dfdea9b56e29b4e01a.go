package main

import (
	"fmt"
	"io"
	"math/rand"
	"os"
	"sync"
)

type TaskAdapter struct{}

func (t *TaskAdapter) Run() {
	in := io.Reader(os.Stdin)
	out := io.Writer(os.Stdout)
	solver := &ID3{}
	solver.Solve(1, in, out)
}

type ID3 struct {
	mu    *ID1
	euler *ID1
	primes []int64
}

func NewID3() *ID3 {
	mu := NewID1(100000, false)
	euler := NewID1(100000, false)
	mu.Put(1, 1)
	euler.Put(1, 1)
	return &ID3{mu: mu, euler: euler}
}

func (id3 *ID3) id0(x int64) int64 {
	for _, p := range id3.primes {
		if x%p == 0 {
			return p
		}
	}
	return x
}

func (id3 *ID3) populate(x int64) {
	factor := id3.id0(x)
	cnt := int64(0)
	y := x
	for y%factor == 0 {
		cnt++
		y /= factor
	}
	if cnt > 1 {
		id3.mu.Put(x, 0)
	} else {
		id3.mu.Put(x, -id3.mu.Get(y))
	}
	id3.euler.Put(x, id3.euler.Get(y)*(x/y-x/y/factor))
}

func (id3 *ID3) muFunc(x int64) int64 {
	ans := id3.mu.Get(x)
	if ans == -1 {
		id3.populate(x)
		ans = id3.mu.Get(x)
	}
	return ans
}

func (id3 *ID3) eulerFunc(x int64) int64 {
	ans := id3.euler.Get(x)
	if ans == -1 {
		id3.populate(x)
		ans = id3.euler.Get(x)
	}
	return ans
}

func (id3 *ID3) Solve(testNumber int, in io.Reader, out io.Writer) {
	var m, x int64
	fmt.Fscanf(in, "%d %d", &m, &x)

	id3.primes = FactorizationID13(m)
	id9 := NewLongList(20000)
	tmpList := NewLongList(20000)
	id2 := NewLongList()
	for _, p := range id3.primes {
		id2.Add(p)
		id2.AddAll(FactorizationID13(p - 1))
	}
	id2.Unique()

	id3.collect(id9, m, 0)
	power := NewLongPower(NewID12(m))

	total := int64(1)
	for i := 0; i < id9.Size(); i++ {
		g := id9.Get(i)
		if g == m {
			continue
		}
		mg := m / g
		tmpList.Clear()
		id3.collect(tmpList, mg, 0)
		cnt := int64(0)
		for j := tmpList.Size() - 1; j >= 0; j-- {
			t := tmpList.Get(j)
			cnt += id3.muFunc(t) * ((m - 1) / (t * g))
		}

		tmpList.Clear()
		euler := id3.eulerFunc(mg)
		primeFactors := tmpList
		for j := 0; j < id2.Size(); j++ {
			p := id2.Get(j)
			if euler%p == 0 {
				primeFactors.Add(p)
			}
		}

		n := euler
		for j := 0; j < primeFactors.Size(); j++ {
			p := primeFactors.Get(j)
			for n%p == 0 && power.Pow(x, n/p)%mg == 1 {
				n /= p
			}
		}

		if cnt%n != 0 {
			panic("Illegal State")
		}
		total += cnt / n
	}

	fmt.Fprintln(out, total)
}

func (id3 *ID3) collect(list *LongList, x int64, i int) {
	if i == len(id3.primes) {
		list.Add(x)
		return
	}
	id3.collect(list, x, i+1)
	for x%id3.primes[i] == 0 {
		x /= id3.primes[i]
		id3.collect(list, x, i+1)
	}
}

type ID1 struct {
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

func NewID1(cap int, rehash bool) *ID1 {
	mask := (1 << (32 - bits.LeadingZeros32(uint32(cap-1)))) - 1
	return &ID1{
		slot:    make([]int, mask+1),
		next:    make([]int, cap+1),
		keys:    make([]int64, cap+1),
		values:  make([]int64, cap+1),
		removed: make([]bool, cap+1),
		mask:    mask,
		rehash:  rehash,
	}
}

func (id1 *ID1) doubleCapacity() {
	newSize := max(id1.next.length+10, id1.next.length*2)
	id1.next = append(id1.next, make([]int, newSize-len(id1.next))...)
	id1.keys = append(id1.keys, make([]int64, newSize-len(id1.keys))...)
	id1.values = append(id1.values, make([]int64, newSize-len(id1.values))...)
	id1.removed = append(id1.removed, make([]bool, newSize-len(id1.removed))...)
}

func (id1 *ID1) alloc() {
	id1.alloc++
	if id1.alloc >= len(id1.next) {
		id1.doubleCapacity()
	}
	id1.next[id1.alloc] = 0
	id1.removed[id1.alloc] = false
	id1.size++
}

func (id1 *ID1) rehash() {
	newSlots := make([]int, max(16, len(id1.slot)*2))
	newMask := len(newSlots) - 1
	for i := 0; i < len(id1.slot); i++ {
		if id1.slot[i] == 0 {
			continue
		}
		head := id1.slot[i]
		for head != 0 {
			n := id1.next[head]
			s := id1.hash(id1.keys[head]) & newMask
			id1.next[head] = newSlots[s]
			newSlots[s] = head
			head = n
		}
	}
	id1.slot = newSlots
	id1.mask = newMask
}

func (id1 *ID1) hash(x int64) int {
	h := int64(x) ^ (x >> 16)
	return int(h)
}

func (id1 *ID1) Put(x int64, y int64) {
	id1.Put(x, y, true)
}

func (id1 *ID1) Put(x int64, y int64, cover bool) {
	h := id1.hash(x)
	s := h & id1.mask
	if id1.slot[s] == 0 {
		id1.alloc()
		id1.slot[s] = id1.alloc
		id1.keys[id1.alloc] = x
		id1.values[id1.alloc] = y
	} else {
		index := id1.id8(s, x)
		if id1.keys[index] != x {
			id1.alloc()
			id1.next[index] = id1.alloc
			id1.keys[id1.alloc] = x
			id1.values[id1.alloc] = y
		} else if cover {
			id1.values[index] = y
		}
	}
	if id1.rehash && id1.size >= len(id1.slot) {
		id1.rehash()
	}
}

func (id1 *ID1) Get(x int64) int64 {
	return id1.id5(x, 0)
}

func (id1 *ID1) id5(x int64, def int64) int64 {
	h := id1.hash(x)
	s := h & id1.mask
	if id1.slot[s] == 0 {
		return def
	}
	index := id1.id8(s, x)
	if id1.keys[index] == x {
		return id1.values[index]
	}
	return def
}

func (id1 *ID1) id8(s int, x int64) int {
	iter := id1.slot[s]
	for id1.keys[iter] != x {
		if id1.next[iter] != 0 {
			iter = id1.next[iter]
		} else {
			return iter
		}
	}
	return iter
}

type LongList struct {
	size int
	cap  int
	data []int64
}

func NewLongList(cap int) *LongList {
	return &LongList{
		cap:  cap,
		data: make([]int64, cap),
	}
}

func (list *LongList) Add(x int64) {
	list.ensureSpace(list.size + 1)
	list.data[list.size] = x
	list.size++
}

func (list *LongList) ensureSpace(req int) {
	if req > list.cap {
		for list.cap < req {
			list.cap = max(list.cap+10, 2*list.cap)
		}
		list.data = append(list.data, make([]int64, list.cap-len(list.data))...)
	}
}

func (list *LongList) Get(i int) int64 {
	if i < 0 || i >= list.size {
		panic("Index out of bounds")
	}
	return list.data[i]
}

func (list *LongList) Size() int {
	return list.size
}

func (list *LongList) Clear() {
	list.size = 0
}

func (list *LongList) Unique() {
	if list.size <= 1 {
		return
	}
	sort.Slice(list.data[:list.size], func(i, j int) bool {
		return list.data[i] < list.data[j]
	})
	wpos := 1
	for i := 1; i < list.size; i++ {
		if list.data[i] != list.data[wpos-1] {
			list.data[wpos] = list.data[i]
			wpos++
		}
	}
	list.size = wpos
}

type LongPower struct {
	modular ID12
}

func NewLongPower(modular ID12) *LongPower {
	return &LongPower{modular: modular}
}

func (lp *LongPower) Pow(x int64, n int64) int64 {
	if n == 0 {
		return 1
	}
	r := lp.Pow(x, n>>1)
	r = lp.modular.Mul(r, r)
	if n&1 == 1 {
		r = lp.modular.Mul(r, x)
	}
	return r
}

type ID12 interface {
	Mul(a, b int64) int64
}

type ID4 struct {
	m int64
}

func NewID4(m int64) *ID4 {
	return &ID4{m: m}
}

func (id4 *ID4) Mul(a, b int64) int64 {
	return DigitUtilsMulMod(a, b, id4.m)
}

type DigitUtils struct{}

func DigitUtilsMulMod(a, b, mod int64) int64 {
	k := round(float64(a)/float64(mod) * float64(b))
	return mod(a*b-k*mod, mod)
}

func round(x float64) int64 {
	if x >= 0 {
		return int64(x + 0.5)
	}
	return int64(x - 0.5)
}

func mod(x, mod int64) int64 {
	x %= mod
	if x < 0 {
		x += mod
	}
	return x
}

type Factorization struct{}

func FactorizationID13(x int64) []int64 {
	var ans []int64
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

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		task := &TaskAdapter{}
		task.Run()
	}()
	wg.Wait()
}
