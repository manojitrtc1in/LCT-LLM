package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	scanner := bufio.NewScanner(r)
	scanner.Split(bufio.ScanWords)
	return &InputReader{scanner: scanner}
}

func (in *InputReader) ReadLong() int64 {
	in.scanner.Scan()
	var x int64
	fmt.Sscan(in.scanner.Text(), &x)
	return x
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) PrintLine(args ...interface{}) {
	fmt.Fprintln(out.writer, args...)
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

type Task struct {
	mapData    map[int64]int
	divides    map[int64][]int64
	dp         [][]int64
	idx        int
}

func NewTask() *Task {
	return &Task{
		mapData: make(map[int64]int),
		divides: make(map[int64][]int64),
	}
}

func (t *Task) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	A := in.ReadLong()
	for i := int64(1); i*i <= A; i++ {
		if A%i == 0 {
			t.process(i)
			if i*i != A {
				t.process(A / i)
			}
		}
	}
	t.dp = make([][]int64, 2)
	t.dp[0] = make([]int64, len(t.mapData))
	t.dp[0][t.mapData[1]] = 1
	idx := 0
	for i := range t.divides {
		idx ^= 1
		for j := range t.mapData {
			j2 := t.mapData[j]
			t.dp[idx][j2] = t.dp[idx^1][j2]
			for _, x := range t.divides[i] {
				if j%x == 0 {
					t.dp[idx][j2] += t.dp[idx^1][t.mapData[j/x]]
				}
			}
		}
	}
	out.PrintLine(t.dp[idx][t.mapData[A]])
}

func (t *Task) prime(n int64) int64 {
	if n <= 1 {
		return -1
	}
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			for n%i == 0 {
				n /= i
			}
			if n == 1 {
				return i
			}
			return -1
		}
	}
	return n
}

func (t *Task) process(x int64) {
	t.mapData[x] = t.idx
	t.idx++
	p := t.prime(x - 1)
	if p > 0 {
		t.divides[p] = append(t.divides[p], x)
	}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	solver := NewTask()
	solver.Solve(1, in, out)
	out.Close()
}
