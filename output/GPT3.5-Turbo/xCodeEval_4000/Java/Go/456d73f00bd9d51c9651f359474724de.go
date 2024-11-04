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

func (s *Solver) solve() {
	n := s.io.NextInt()
	m := s.io.NextInt()
	if m < n {
		helper := m
		m = n
		n = helper
	}

	if n == 1 {
		s.io.Println(s.brute1(m))
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

func (s *Solver) brute1(m int) int {
	ans := 6 * (m / 6)
	if m%6 == 5 {
		ans += 4
	} else if m%6 == 4 {
		ans += 2
	}
	return ans
}

func (s *Solver) closeToZero(v float64) bool {
	return math.Abs(v) <= 0.0000000000001
}

func main() {
	solver := NewSolver()
	solver.solve()
}

type IO struct {
	r    *bufio.Reader
	w    *bufio.Writer
	next []string
}

func NewIO() *IO {
	return &IO{
		r: bufio.NewReader(os.Stdin),
		w: bufio.NewWriter(os.Stdout),
	}
}

func (io *IO) NextLine() string {
	buf := new(strings.Builder)
	for {
		line, isPrefix, err := io.r.ReadLine()
		if err != nil {
			panic(err)
		}
		buf.Write(line)
		if !isPrefix {
			break
		}
	}
	return buf.String()
}

func (io *IO) Next() string {
	if len(io.next) == 0 {
		io.next = strings.Fields(io.NextLine())
	}
	val := io.next[0]
	io.next = io.next[1:]
	return val
}

func (io *IO) NextInt() int {
	val, _ := strconv.Atoi(io.Next())
	return val
}

func (io *IO) NextLong() int64 {
	val, _ := strconv.ParseInt(io.Next(), 10, 64)
	return val
}

func (io *IO) NextFloat64() float64 {
	val, _ := strconv.ParseFloat(io.Next(), 64)
	return val
}

func (io *IO) Println(a ...interface{}) {
	fmt.Fprintln(io.w, a...)
}

func (io *IO) Flush() {
	io.w.Flush()
}

func (io *IO) Close() {
	io.Flush()
}

func min(v ...int) int {
	ans := v[0]
	for i := 1; i < len(v); i++ {
		if v[i] < ans {
			ans = v[i]
		}
	}
	return ans
}

func max(v ...int) int {
	ans := v[0]
	for i := 1; i < len(v); i++ {
		if v[i] > ans {
			ans = v[i]
		}
	}
	return ans
}

func main() {
	solver := NewSolver()
	solver.solve()
}
