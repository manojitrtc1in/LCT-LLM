package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type ProblemSolver struct{}

func (ps *ProblemSolver) solveTheProblem(in *InputReader, out *OutputWriter) {
	test := 1

	for test > 0 {
		test--

		n := in.nextInt()
		ar := in.nextIntMatrix(n)

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
		out.println(sum - int64(ar[(n-1)/2][(n-1)/2])*3)
	}
}

func main() {
	inputStream := bufio.NewReader(os.Stdin)
	outputStream := bufio.NewWriter(os.Stdout)
	in := NewInputReader(inputStream)
	out := NewOutputWriter(outputStream)
	problemSolver := ProblemSolver{}
	problemSolver.solveTheProblem(in, out)
	out.flush()
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r *bufio.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (in *InputReader) nextInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

func (in *InputReader) nextIntMatrix(n int) [][]int {
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		matrix[i] = make([]int, n)
		for j := 0; j < n; j++ {
			matrix[i][j] = in.nextInt()
		}
	}
	return matrix
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w *bufio.Writer) *OutputWriter {
	return &OutputWriter{writer: w}
}

func (out *OutputWriter) println(v int64) {
	fmt.Fprintln(out.writer, v)
}

func (out *OutputWriter) flush() {
	out.writer.Flush()
}
