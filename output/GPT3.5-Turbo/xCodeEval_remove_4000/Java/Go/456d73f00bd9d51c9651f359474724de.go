package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Solver struct {
	io *IO
}

func NewSolver() *Solver {
	return &Solver{
		io: NewIO(),
	}
}

func (s *Solver) Solve() {
	n := s.io.NextInt()
	m := s.io.NextInt()
	if m < n {
		helper := m
		m = n
		n = helper
	}

	if n == 1 {
		s.io.Println(id17(m))
		return
	}
	if n == 2 {
		if m < 3 {
			s.io.Println(0)
		} else if m == 3 {
			s.io.Println(4)
		} else if m == 7 {
			s.io.Println(12)
		} else {
			s.io.Println(2 * m)
		}
		return
	}

	s.io.Println(2 * (n * m / 2))
}

func id17(m int) int {
	ans := 6 * (m / 6)
	if m%6 == 5 {
		ans += 4
	} else if m%6 == 4 {
		ans += 2
	}
	return ans
}

type IO struct {
	r *bufio.Reader
	w *bufio.Writer
}

func NewIO() *IO {
	return &IO{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}

func (io *IO) NextLine() string {
	line, _ := io.r.ReadString('\n')
	return strings.TrimRight(line, "\r\n")
}

func (io *IO) NextInt() int {
	line := io.NextLine()
	num, _ := strconv.Atoi(line)
	return num
}

func (io *IO) Println(a ...interface{}) {
	fmt.Fprintln(io.w, a...)
}

func (io *IO) Flush() {
	io.w.Flush()
}

func main() {
	solver := NewSolver()
	solver.Solve()
	solver.io.Flush()
}
