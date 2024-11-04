package main

import (
	"bufio"
	"fmt"
	"os"
	"math"
)

type Solver struct {
	io *IO
}

func NewSolver() *Solver {
	io := NewIO()
	solver := &Solver{io: io}
	defer io.Close()
	solver.solve()
	return solver
}

func (s *Solver) solve() {
	n := s.io.NextInt()

	endOfBrute := min(n, 30)
	prev := make(map[int64]struct{})
	prev[0] = struct{}{}
	for i := 0; i < endOfBrute; i++ {
		next := make(map[int64]struct{})
		for v := range prev {
			next[v+1] = struct{}{}
			next[v+5] = struct{}{}
			next[v+10] = struct{}{}
			next[v+50] = struct{}{}
		}
		prev = next
	}

	if n > endOfBrute {
		diff := n - endOfBrute
		s.done(int64(len(prev)) + int64(diff)*49)
	}

	s.io.Println(len(prev))
}

func (s *Solver) done(output int64) {
	s.io.Println(output)
	s.done()
}

func (s *Solver) done() {
	s.io.Close()
	panic("Clean exit")
}

func min(v ...int) int {
	ans := v[0]
	for _, value := range v[1:] {
		if value < ans {
			ans = value
		}
	}
	return ans
}

type IO struct {
	scanner *bufio.Scanner
	writer  *bufio.Writer
}

func NewIO() *IO {
	return &IO{
		scanner: bufio.NewScanner(os.Stdin),
		writer:  bufio.NewWriter(os.Stdout),
	}
}

func (io *IO) Close() {
	io.writer.Flush()
}

func (io *IO) NextInt() int {
	io.scanner.Scan()
	var n int
	fmt.Sscan(io.scanner.Text(), &n)
	return n
}

func (io *IO) Println(v ...interface{}) {
	fmt.Fprintln(io.writer, v...)
}

func main() {
	NewSolver()
}
