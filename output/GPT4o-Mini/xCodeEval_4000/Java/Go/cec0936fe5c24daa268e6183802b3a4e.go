package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{scanner: bufio.NewScanner(r)}
}

func (in *InputReader) ReadInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

func (in *InputReader) ReadLongArray(size int) []int64 {
	arr := make([]int64, size)
	for i := 0; i < size; i++ {
		in.scanner.Scan()
		fmt.Sscanf(in.scanner.Text(), "%d", &arr[i])
	}
	return arr
}

func (in *InputReader) ReadIntArray(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = in.ReadInt()
	}
	return arr
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) PrintLine(i int64) {
	fmt.Fprintln(out.writer, i)
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

type AMarcinAndTrainingCamp struct{}

func (solver *AMarcinAndTrainingCamp) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	n := in.ReadInt()
	A := in.ReadLongArray(n)
	B := in.ReadIntArray(n)
	used := make([]bool, n)
	order := make([]int, n)
	for i := range order {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return A[order[i]] < A[order[j]]
	})
	res := int64(0)
	reverse(order)

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

func reverse(array []int) {
	for i, j := 0, len(array)-1; i < j; i, j = i+1, j-1 {
		array[i], array[j] = array[j], array[i]
	}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := AMarcinAndTrainingCamp{}
	solver.Solve(1, in, out)
	out.Close()
}
