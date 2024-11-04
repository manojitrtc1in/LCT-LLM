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

func main() {
	solver := Solver{}
	solver.io = NewIO()
	defer solver.io.Close()
	solver.solve()
}

func (s *Solver) solve() {
	n := s.io.NextInt()

	id13 := min(n, 30)
	prev := make(map[int64]struct{})
	prev[0] = struct{}{}
	for i := 0; i < id13; i++ {
		next := make(map[int64]struct{})
		for v := range prev {
			next[v+1] = struct{}{}
			next[v+5] = struct{}{}
			next[v+10] = struct{}{}
			next[v+50] = struct{}{}
		}
		prev = next
	}

	if n > id13 {
		diff := n - id13
		s.done(int64(len(prev)) + int64(diff)*49)
	}

	s.io.Println(len(prev))
}

func (s *Solver) done(output int64) {
	s.io.Println(output)
	s.doneExit()
}

func (s *Solver) doneExit() {
	s.io.Close()
	panic("Clean exit")
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

func (io *IO) NextInt() int {
	io.scanner.Scan()
	var n int
	fmt.Sscanf(io.scanner.Text(), "%d", &n)
	return n
}

func (io *IO) Println(v ...interface{}) {
	fmt.Fprintln(io.writer, v...)
}

func (io *IO) Close() {
	io.writer.Flush()
}

func min(v ...int) int {
	ans := v[0]
	for _, val := range v[1:] {
		if val < ans {
			ans = val
		}
	}
	return ans
}
