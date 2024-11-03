package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type IO struct {
	r    *bufio.Reader
	w    *bufio.Writer
	buf  []byte
	bufi int
	bufc int
}

func NewIO() *IO {
	return &IO{
		r:   bufio.NewReader(os.Stdin),
		w:   bufio.NewWriter(os.Stdout),
		buf: make([]byte, 1<<15),
	}
}

func (io *IO) next() string {
	for io.bufi == io.bufc {
		io.bufc, _ = io.r.Read(io.buf)
		io.bufi = 0
	}
	for io.buf[io.bufi] == ' ' || io.buf[io.bufi] == '\n' || io.buf[io.bufi] == '\t' || io.buf[io.bufi] == '\r' {
		io.bufi++
	}
	start := io.bufi
	for io.bufi < io.bufc && io.buf[io.bufi] != ' ' && io.buf[io.bufi] != '\n' && io.buf[io.bufi] != '\t' && io.buf[io.bufi] != '\r' {
		io.bufi++
	}
	return string(io.buf[start:io.bufi])
}

func (io *IO) nextInt() int {
	n, _ := strconv.Atoi(io.next())
	return n
}

func (io *IO) nextLong() int64 {
	n, _ := strconv.ParseInt(io.next(), 10, 64)
	return n
}

func (io *IO) nextDouble() float64 {
	n, _ := strconv.ParseFloat(io.next(), 64)
	return n
}

func (io *IO) println(a ...interface{}) {
	fmt.Fprintln(io.w, a...)
}

func (io *IO) flush() {
	io.w.Flush()
}

func main() {
	io := NewIO()
	defer io.flush()

	solver := NewSolver(io)
	solver.solve()
}

type Solver struct {
	io *IO
}

func NewSolver(io *IO) *Solver {
	return &Solver{
		io: io,
	}
}

func (solver *Solver) solve() {
	n := solver.io.nextLong()
	m := solver.io.nextLong()
	if m < n {
		helper := m
		m = n
		n = helper
	}

	if n == 1 {
		solver.io.println(solver.brute1(m))
		return
	}
	if n == 2 {
		if m < 3 {
			solver.io.println(0)
		} else if m == 3 {
			solver.io.println(4)
		} else if m == 7 {
			solver.io.println(12)
		} else {
			solver.io.println(2 * m)
		}
		return
	}

	solver.io.println(2 * (n * m / 2))
}

func (solver *Solver) brute1(m int64) int64 {
	ans := 6 * (m / 6)
	if m%6 == 5 {
		ans += 4
	} else if m%6 == 4 {
		ans += 2
	}
	return ans
}

func (solver *Solver) closeToZero(v float64) bool {
	return math.Abs(v) <= 0.0000000000001
}
