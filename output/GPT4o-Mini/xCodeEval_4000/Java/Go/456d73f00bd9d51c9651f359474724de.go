package main

import (
	"fmt"
	"math"
	"os"
)

type Solver struct {
	io *IO
}

func main() {
	solver := &Solver{io: NewIO()}
	defer solver.io.Close()
	solver.solve()
}

func (s *Solver) solve() {
	n := s.io.NextLong()
	m := s.io.NextLong()
	if m < n {
		m, n = n, m
	}

	if n == 1 {
		s.io.Println(brute1(m))
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

func brute1(m int64) int64 {
	ans := 6 * (m / 6)
	if m%6 == 5 {
		ans += 4
	} else if m%6 == 4 {
		ans += 2
	}
	return ans
}

type IO struct {
	writer *os.File
}

func NewIO() *IO {
	return &IO{writer: os.Stdout}
}

func (io *IO) Close() {
	// No specific close action needed for os.Stdout
}

func (io *IO) Println(v interface{}) {
	fmt.Fprintln(io.writer, v)
}

func (io *IO) NextLong() int64 {
	var v int64
	fmt.Scan(&v)
	return v
}

func closeToZero(v float64) bool {
	return math.Abs(v) <= 0.0000000000001
}
