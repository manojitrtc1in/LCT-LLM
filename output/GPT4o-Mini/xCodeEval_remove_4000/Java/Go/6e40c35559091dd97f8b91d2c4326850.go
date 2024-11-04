package main

import (
	"fmt"
	"io"
	"math"
)

func main() {
	taskAdapter := &TaskAdapter{}
	go taskAdapter.run()
	select {}
}

type TaskAdapter struct{}

func (t *TaskAdapter) run() {
	in := NewFastInput(io.Stdin)
	out := NewFastOutput(io.Stdout)
	solver := &id5{}
	solver.solve(1, in, out)
	out.close()
}

type id5 struct{}

func (s *id5) solve(testNumber int, in *FastInput, out *FastOutput) {
	n := in.readLong()
	k := in.readInt()

	mod := NewModular(1000000007)
	power := NewPower(mod)

	items := 200
	fib := make([]int, items)
	fib[0] = 1
	fib[1] = 2
	a := make([]int, items)
	for i := 2; i < items; i++ {
		fib[i] = mod.plus(fib[i-1], fib[i-2])
	}
	for i := 0; i < items; i++ {
		a[i] = mod.mul(fib[i], power.pow(i+1, k))
		if i > 0 {
			a[i] = mod.plus(a[i], a[i-1])
		}
	}

	seq := NewIntegerList()
	seq.addAll(a)
	solver2 := id9_id2(seq, mod)
	ans := solver2.solve(n - 1, seq)

	out.println(ans)
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

func (list *IntegerList) addAll(arr []int) {
	list.data = append(list.data, arr...)
	list.size += len(arr)
}

func (list *IntegerList) get(i int) int {
	return list.data[i]
}

func (list *IntegerList) size() int {
	return list.size
}

type Power struct {
	modular *Modular
}

func NewPower(modular *Modular) *Power {
	return &Power{modular: modular}
}

func (p *Power) pow(x, n int) int {
	if n == 0 {
		return p.modular.valueOf(1)
	}
	r := p.pow(x, n>>1)
	r = p.modular.valueOf(r * r)
	if n&1 == 1 {
		r = p.modular.valueOf(r * x)
	}
	return r
}

type id9 struct {
	mod      *Modular
	coe      *IntegerList
	p        *IntegerList
	remainder *IntegerList
	pow      *Power
	n        int
}

func id9_id2(seq *IntegerList, mod *Modular) *id9 {
	id10 := NewId0(mod, seq.size())
	for i := 0; i < seq.size(); i++ {
		id10.add(seq.get(i))
	}
	coes := NewIntegerList()
	for i := 1; i <= id10.length(); i++ {
		coes.add(id10.codeAt(i))
	}
	return &id9{coe: coes, mod: mod, n: coes.size}
}

func (s *id9) solve(k int64, a *IntegerList) int {
	if k < int64(a.size()) {
		return a.get(int(k))
	}
	// Implement Polynomials.module logic here
	return 0 // Placeholder
}

type FastInput struct {
	is       io.Reader
	buf      []byte
	bufLen   int
	bufOffset int
	next     int
}

func NewFastInput(is io.Reader) *FastInput {
	return &FastInput{is: is, buf: make([]byte, 1<<13)}
}

func (f *FastInput) read() int {
	if f.bufLen == f.bufOffset {
		f.bufOffset = 0
		n, err := f.is.Read(f.buf)
		if err != nil {
			f.bufLen = -1
		} else {
			f.bufLen = n
		}
	}
	if f.bufLen == -1 {
		return -1
	}
	f.bufOffset++
	return int(f.buf[f.bufOffset-1])
}

func (f *FastInput) readInt() int {
	sign := 1
	f.skipBlank()
	if f.next == '+' || f.next == '-' {
		if f.next == '+' {
			sign = 1
		} else {
			sign = -1
		}
		f.next = f.read()
	}

	val := 0
	if sign == 1 {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 + f.next - '0'
			f.next = f.read()
		}
	} else {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 - f.next + '0'
			f.next = f.read()
		}
	}
	return val
}

func (f *FastInput) readLong() int64 {
	sign := 1
	f.skipBlank()
	if f.next == '+' || f.next == '-' {
		if f.next == '+' {
			sign = 1
		} else {
			sign = -1
		}
		f.next = f.read()
	}

	val := int64(0)
	if sign == 1 {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 + int64(f.next-'0')
			f.next = f.read()
		}
	} else {
		for f.next >= '0' && f.next <= '9' {
			val = val*10 - int64(f.next-'0')
			f.next = f.read()
		}
	}
	return val
}

func (f *FastInput) skipBlank() {
	for f.next >= 0 && f.next <= 32 {
		f.next = f.read()
	}
}

type FastOutput struct {
	writer io.Writer
}

func NewFastOutput(writer io.Writer) *FastOutput {
	return &FastOutput{writer: writer}
}

func (out *FastOutput) println(c int) {
	fmt.Fprintln(out.writer, c)
}

func (out *FastOutput) close() {
	// Implement close logic if needed
}
