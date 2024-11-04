package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

type ProblemSolver struct{}

func (ps *ProblemSolver) id13(in *InputReader, out *OutputWriter) {
	test := 1

	for test > 0 {
		test--

		n := in.NextInt()
		ar := in.Id0(n, n)

		sum := int64(0)
		for i := 0; i < n; i++ {
			sum += int64(ar[i][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[n-i-1][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[(n-1)/2][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[i][(n-1)/2])
		}
		out.Println(sum - int64(ar[(n-1)/2][(n-1)/2])*3)
	}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	problemSolver := &ProblemSolver{}
	problemSolver.id13(in, out)
	out.Flush()
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (in *InputReader) NextInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscan(in.scanner.Text(), &x)
	return x
}

func (in *InputReader) Id0(n, m int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, m)
		for j := 0; j < m; j++ {
			matrix[i][j] = in.NextInt()
		}
	}
	return matrix
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(v ...interface{}) {
	fmt.Fprintln(out.writer, v...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}
