package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type IntComparator func(first, second int) int

type IntIterator interface {
	Value() (int, bool)
	Advance() bool
	IsValid() bool
}

type IntList interface {
	Get(index int) int
	Set(index int, value int)
	AddAt(index int, value int)
	RemoveAt(index int)
	Size() int
	Swap(first, second int)
	IntIterator() IntIterator
}

type IntArray struct {
	data []int
}

func NewIntArray(arr []int) *IntArray {
	return &IntArray{data: arr}
}

func (arr *IntArray) Size() int {
	return len(arr.data)
}

func (arr *IntArray) Get(at int) int {
	return arr.data[at]
}

func (arr *IntArray) Set(index int, value int) {
	arr.data[index] = value
}

func (arr *IntArray) AddAt(index int, value int) {
	arr.data = append(arr.data[:index], append([]int{value}, arr.data[index:]...)...)
}

func (arr *IntArray) RemoveAt(index int) {
	arr.data = append(arr.data[:index], arr.data[index+1:]...)
}

func (arr *IntArray) Swap(first, second int) {
	if first == second {
		return
	}
	temp := arr.Get(first)
	arr.Set(first, arr.Get(second))
	arr.Set(second, temp)
}

type IntStream interface {
	IntIterator() IntIterator
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{scanner: bufio.NewScanner(r)}
}

func (in *InputReader) ReadInt() int {
	in.scanner.Scan()
	var value int
	fmt.Sscanf(in.scanner.Text(), "%d", &value)
	return value
}

func (in *InputReader) ReadLongArray(size int) []int64 {
	arr := make([]int64, size)
	for i := 0; i < size; i++ {
		in.scanner.Scan()
		fmt.Sscanf(in.scanner.Text(), "%d", &arr[i])
	}
	return arr
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) PrintLine(value int64) {
	fmt.Fprintln(out.writer, value)
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

type Solver struct{}

func (s *Solver) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.ReadInt()
	A := in.ReadLongArray(n)
	B := make([]int, n)
	for i := 0; i < n; i++ {
		B[i] = in.ReadInt()
	}
	used := make([]bool, n)
	order := make([]int, n)
	for i := range order {
		order[i] = i
	}
	// Sorting order based on A
	// Implement sorting logic here
	res := int64(0)
	for idx := 0; idx < n; {
		to := idx
		for to+1 < n && A[order[to+1]] == A[order[idx]] {
			to++
		}
		valid := to > idx
		if !valid {
			for i := 0; i < idx; i++ {
				if used[i] && (A[order[i]]&A[order[idx]]) == A[order[idx]] {
					valid = true
				}
			}
		}
		if valid {
			for i := idx; i <= to; i++ {
				res += int64(B[order[i]])
				used[i] = true
			}
		}
		idx = to + 1
	}
	out.PrintLine(res)
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := &Solver{}
	solver.Solve(1, in, out)
	out.Close()
}
