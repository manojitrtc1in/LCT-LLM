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

func (list *IntList) Size() int {
	return list.size
}

func (list *IntList) Get(i int) int {
	return list.data[i]
}

func (list *IntList) Clear() {
	list.data = nil
	list.size = 0
}

type TaskG struct {
	mod *Modular
}

func NewTaskG() *TaskG {
	return &TaskG{mod: NewModular(998244353)}
}

func (t *TaskG) Solve(n, k int, allow []int) int {
	m := n / 2
	last := make([]int, len(allow))
	copy(last, allow)

	prod := NewIntList()
	// Placeholder for NTT and other operations
	// Implement the logic as per the original Java code

	ans := 0
	for i := 0; i < prod.Size(); i++ {
		plus := prod.Get(i)
		ans = t.mod.Plus(ans, t.mod.Mul(plus, plus))
	}

	return ans
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)

	go func() {
		defer wg.Done()
		var n, k int
		fmt.Scan(&n, &k)
		allow := make([]int, 10)
		for i := 0; i < k; i++ {
			var x int
			fmt.Scan(&x)
			allow[x] = 1
		}
		solver := NewTaskG()
		ans := solver.Solve(n, k, allow)
		fmt.Println(ans)
	}()

	wg.Wait()
}
