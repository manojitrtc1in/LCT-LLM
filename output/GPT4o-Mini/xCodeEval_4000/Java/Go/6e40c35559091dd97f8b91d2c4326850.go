package main

import (
	"fmt"
	"io"
	"os"
)

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

type IntegerList struct {
	data []int
	size int
}

func NewIntegerList() *IntegerList {
	return &IntegerList{data: make([]int, 0)}
}

func (list *IntegerList) add(x int) {
	list.data = append(list.data, x)
	list.size++
}

func (list *IntegerList) get(i int) int {
	return list.data[i]
}

func (list *IntegerList) size() int {
	return list.size
}

type FastInput struct {
	r io.Reader
}

func NewFastInput(r io.Reader) *FastInput {
	return &FastInput{r: r}
}

func (in *FastInput) readInt() (int, error) {
	var x int
	_, err := fmt.Fscanf(in.r, "%d", &x)
	return x, err
}

type FastOutput struct {
	w io.Writer
}

func NewFastOutput(w io.Writer) *FastOutput {
	return &FastOutput{w: w}
}

func (out *FastOutput) println(c int) {
	fmt.Fprintln(out.w, c)
}

type CYetAnotherNumberSequence struct{}

func (solver *CYetAnotherNumberSequence) solve(n int64, k int, out *FastOutput) {
	mod := NewModular(1000000007)
	fib := make([]int, 200)
	fib[0] = 1
	fib[1] = 2
	for i := 2; i < 200; i++ {
		fib[i] = mod.plus(fib[i-1], fib[i-2])
	}

	a := make([]int, 200)
	for i := 0; i < 200; i++ {
		a[i] = mod.mul(fib[i], pow(i+1, k, mod))
		if i > 0 {
			a[i] = mod.plus(a[i], a[i-1])
		}
	}

	seq := NewIntegerList()
	for _, val := range a {
		seq.add(val)
	}

	ans := linearRecurrenceSolver(n-1, seq, mod)
	out.println(ans)
}

func pow(x, n int, mod *Modular) int {
	if n == 0 {
		return mod.valueOf(1)
	}
	r := pow(x, n>>1, mod)
	r = mod.valueOf(r * r)
	if n&1 == 1 {
		r = mod.valueOf(r * x)
	}
	return r
}

func linearRecurrenceSolver(k int64, seq *IntegerList, mod *Modular) int {
	if k < int64(seq.size) {
		return seq.get(int(k))
	}
	// Implement the logic for solving the linear recurrence
	return 0 // Placeholder
}

func main() {
	in := NewFastInput(os.Stdin)
	out := NewFastOutput(os.Stdout)

	n, _ := in.readInt()
	k, _ := in.readInt()

	solver := &CYetAnotherNumberSequence{}
	solver.solve(int64(n), k, out)
}
