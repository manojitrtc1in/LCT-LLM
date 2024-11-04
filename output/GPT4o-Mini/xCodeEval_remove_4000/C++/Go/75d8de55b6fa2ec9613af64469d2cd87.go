package main

import (
	"fmt"
	"math"
)

type Vector[T any] struct {
	data []T
}

func NewVector[T any](n int) *Vector[T] {
	return &Vector[T]{data: make([]T, n)}
}

func (v *Vector[T]) Get(ind int) T {
	if ind < 0 || ind >= len(v.data) {
		panic("Out of bounds")
	}
	return v.data[ind]
}

func (v *Vector[T]) Set(ind int, value T) {
	if ind < 0 || ind >= len(v.data) {
		panic("Out of bounds")
	}
	v.data[ind] = value
}

type Pair[T1, T2 any] struct {
	First  T1
	Second T2
}

const PI = math.Pi

func Min[T comparable](was *T, cand T) T {
	if *was > cand {
		*was = cand
	}
	return *was
}

func Max[T comparable](was *T, cand T) T {
	if *was < cand {
		*was = cand
	}
	return *was
}

func DPow[D float64](base D, exponent int64) D {
	if exponent < 0 {
		return DPow(1/base, -exponent)
	}
	if exponent == 0 {
		return 1
	}
	if exponent%2 == 1 {
		return DPow(base, exponent-1) * base
	} else {
		res := DPow(base, exponent>>1)
		return res * res
	}
}

type Arr[T any] struct {
	data []T
}

func NewArr[T any](n int) *Arr[T] {
	if n < 0 {
		panic("bad alloc")
	}
	return &Arr[T]{data: make([]T, n)}
}

func (a *Arr[T]) Size() int {
	return len(a.data)
}

func (a *Arr[T]) Get(at int) T {
	if at < 0 || at >= len(a.data) {
		panic("Out of bounds")
	}
	return a.data[at]
}

func (a *Arr[T]) Set(at int, value T) {
	if at < 0 || at >= len(a.data) {
		panic("Out of bounds")
	}
	a.data[at] = value
}

func Id5[T any](array *Arr[T], vs ...*Arr[T]) {
	n := array.Size()
	for i := 0; i < n; i++ {
		array.Set(i, array.Get(i)-1)
	}
	for _, v := range vs {
		Id5(v)
	}
}

type Id4[T any] struct {
	data []T
	d1   int
	d2   int
}

func NewId4[T any](d1, d2 int) *Id4[T] {
	sz := d1 * d2
	return &Id4[T]{data: make([]T, sz), d1: d1, d2: d2}
}

func (id *Id4[T]) Get(i1, i2 int) T {
	if i1 < 0 || i1 >= id.d1 || i2 < 0 || i2 >= id.d2 {
		panic("Out of bounds")
	}
	return id.data[i1*id.d2+i2]
}

func (id *Id4[T]) Set(i1, i2 int, value T) {
	if i1 < 0 || i1 >= id.d1 || i2 < 0 || i2 >= id.d2 {
		panic("Out of bounds")
	}
	id.data[i1*id.d2+i2] = value
}

type Input struct {
	in *fmt.Scan
}

func NewInput(in *fmt.Scan) *Input {
	return &Input{in: in}
}

func (input *Input) ReadInt() int {
	var x int
	_, err := fmt.Scan(&x)
	if err != nil {
		panic("Input id3")
	}
	return x
}

func (input *Input) ReadIntArray(size int) *Arr[int] {
	arr := NewArr[int](size)
	for i := 0; i < size; i++ {
		arr.Set(i, input.ReadInt())
	}
	return arr
}

type Output struct {
	out *fmt.Print
}

func NewOutput(out *fmt.Print) *Output {
	return &Output{out: out}
}

func (output *Output) Print(args ...any) {
	fmt.Print(args...)
}

func (output *Output) PrintLine(args ...any) {
	output.Print(args...)
	fmt.Println()
}

type TaskD struct{}

func (task *TaskD) Solve(inp *Input, out *Output) {
	n := inp.ReadInt()
	m := inp.ReadInt()
	b := inp.ReadIntArray(n)
	w := inp.ReadIntArray(n)
	x := inp.ReadIntArray(n - 1)
	y := inp.ReadIntArray(n - 1)
	Id5(x, y)

	graph := make([][]*BiEdge, n)
	for i := 0; i < n-1; i++ {
		graph[x.Get(i)] = append(graph[x.Get(i)], NewBiEdge(x.Get(i), y.Get(i)))
	}

	q := NewArr[int](n)
	var calcQ func(vert, last int) int
	calcQ = func(vert, last int) int {
		res := 1
		for _, e := range graph[vert] {
			next := e.to
			if next == last {
				continue
			}
			res += calcQ(next, vert)
		}
		q.Set(vert, res)
		return res
	}
	calcQ(0, -1)

	temp := NewArr[Pair[int, int]](n + 2)
	var go func(vert, last int)
	go = func(vert, last int) {
		id := -1
		for _, e := range graph[vert] {
			next := e.to
			if next == last {
				continue
			}
			go(next, vert)
			if id == -1 || q.Get(next) > q.Get(id) {
				id = next
			}
		}
		cur := answer[vert]
		delta := w.Get(vert) - b.Get(vert)
		if id == -1 {
			cur.Set(0, Pair[int, int]{0, delta})
			cur.Set(1, Pair[int, int]{0, 0})
			return
		}

		aid := answer[id]
		for i := 0; i <= q.Get(id); i++ {
			cur.Set(i, aid.Get(i))
			cur.Set(i, Pair[int, int]{cur.Get(i).First, cur.Get(i).Second + delta})
		}

		sz := q.Get(id)
		for i := sz + 1; i <= q.Get(vert); i++ {
			cur.Set(i, Pair[int, int]{-1, 0})
		}
		for _, e := range graph[vert] {
			next := e.to
			if next == last || next == id {
				continue
			}
			anext := answer[next]
			for i := 0; i <= sz; i++ {
				temp.Set(i, cur.Get(i))
				cur.Set(i, Pair[int, int]{-1, 0})
			}

			nsz := sz + q.Get(next)
			for i := 0; i <= sz; i++ {
				for j := 0; j <= q.Get(next); j++ {
					Max(&cur.Get(i+j), Pair[int, int]{temp.Get(i).First + anext.Get(j).First, temp.Get(i).Second + anext.Get(j).Second})
				}
			}
			sz = nsz
		}
		if vert == 0 {
			for i := n - 1; i >= 0; i-- {
				cur.Set(i+1, Pair[int, int]{cur.Get(i).First + (cur.Get(i).Second > 0 ? 1 : 0), 0})
			}
			return
		}

		for i := sz; i >= 0; i-- {
			Max(&cur.Get(i+1), Pair[int, int]{cur.Get(i).First + (cur.Get(i).Second > 0 ? 1 : 0), 0})
		}
	}
	go(0, -1)
	out.PrintLine(answer[0][m].First)
}

func main() {
	var n int
	fmt.Scan(&n)
	solver := TaskD{}
	for i := 0; i < n; i++ {
		in := NewInput(&fmt.Scan)
		out := NewOutput(&fmt.Print)
		solver.Solve(in, out)
	}
}
