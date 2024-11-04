package main

import (
	"fmt"
	"math/rand"
	"sync"
)

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) ValueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) Mul(x, y int) int {
	return mod.ValueOf(x * y)
}

func (mod *Modular) Plus(x, y int) int {
	return mod.ValueOf(x + y)
}

type IntList struct {
	data []int
	size int
}

func NewIntList() *IntList {
	return &IntList{data: make([]int, 0)}
}

func (list *IntList) AddAll(x []int) {
	list.data = append(list.data, x...)
	list.size += len(x)
}

func (list *IntList) Get(i int) int {
	return list.data[i]
}

func (list *IntList) Size() int {
	return list.size
}

func (list *IntList) Clear() {
	list.data = list.data[:0]
	list.size = 0
}

type TaskG struct {
	mod *Modular
}

func NewTaskG() *TaskG {
	return &TaskG{mod: NewModular(998244353)}
}

func (task *TaskG) Solve(n, k int, allow []int) int {
	p := NewIntList()
	for _, a := range allow {
		p.AddAll([]int{a})
	}

	m := n / 2
	last := p
	ntt := NewId8(task.mod, 3)
	lists := make([]*IntList, 0)

	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last)
		}
		ntt.Pow2(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := NewIntList()
	ntt.Id1(lists, prod)

	ans := 0
	for i := 0; i < prod.Size(); i++ {
		plus := prod.Get(i)
		ans = task.mod.Plus(ans, task.mod.Mul(plus, plus))
	}

	return ans
}

type Id8 struct {
	modular *Modular
	g       int
}

func NewId8(mod *Modular, g int) *Id8 {
	return &Id8{modular: mod, g: g}
}

func (id *Id8) DFT(p []int, m int) {
	n := 1 << m
	// Bit-reversal permutation
	for i := 1; i < n; i++ {
		j := reverseBits(i, m)
		if i < j {
			p[i], p[j] = p[j], p[i]
		}
	}

	// FFT
	for d := 0; d < m; d++ {
		w1 := id.modular.ValueOf(id.g) // Placeholder for wCache[d]
		s := 1 << d
		s2 := s << 1
		for i := 0; i < n; i += s2 {
			w := 1
			for j := 0; j < s; j++ {
				a := i + j
				b := a + s
				t := id.modular.Mul(w, p[b])
				p[b] = id.modular.Plus(p[a], -t)
				p[a] = id.modular.Plus(p[a], t)
				w = id.modular.Mul(w, w1)
			}
		}
	}
}

func (id *Id8) Id1(lists []*IntList, ans *IntList) {
	pqs := make([]*IntList, len(lists))
	copy(pqs, lists)

	for len(pqs) > 1 {
		a := pqs[0]
		b := pqs[1]
		pqs = pqs[2:]
		id.Id9(a, b)
		pqs = append(pqs, a)
	}

	last := pqs[0]
	ans.Clear()
	ans.AddAll(last.data)
}

func (id *Id8) Id9(a, b *IntList) {
	rankAns := a.Size() - 1 + b.Size() - 1
	proper := ceilLog(rankAns + 1)
	a.data = append(a.data, make([]int, 1<<proper-len(a.data))...)
	b.data = append(b.data, make([]int, 1<<proper-len(b.data))...)
	id.DFT(a.data, proper)
	id.DFT(b.data, proper)
	// Placeholder for dotMul
	id.DFT(a.data, proper) // This should be the result of the multiplication
}

func reverseBits(x, m int) int {
	var res int
	for i := 0; i < m; i++ {
		res = (res << 1) | (x & 1)
		x >>= 1
	}
	return res
}

func ceilLog(x int) int {
	if x <= 1 {
		return 0
	}
	return 32 - bits.LeadingZeros32(uint32(x-1))
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		var n, k int
		fmt.Scan(&n, &k)
		allow := make([]int, k)
		for i := 0; i < k; i++ {
			fmt.Scan(&allow[i])
		}
		solver := NewTaskG()
		ans := solver.Solve(n, k, allow)
		fmt.Println(ans)
	}()
	wg.Wait()
}
