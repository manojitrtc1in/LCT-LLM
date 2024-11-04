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

	id13 := min(n, 30)
	prev := make(map[int64]bool)
	prev[0] = true
	for i := 0; i < id13; i++ {
		next := make(map[int64]bool)
		for v := range prev {
			next[v+1] = true
			next[v+5] = true
			next[v+10] = true
			next[v+50] = true
		}
		prev = next
	}

	if n > id13 {
		diff := n - id13
		done(int64(len(prev)) + diff*49)
	}

	s.io.Println(len(prev))
}

func min(v ...int) int {
	ans := v[0]
	for i := 1; i < len(v); i++ {
		ans = int(math.Min(float64(ans), float64(v[i])))
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
	return strings.TrimSuffix(line, "\n")
}

func (io *IO) NextInt() int {
	line := io.NextLine()
	num, _ := strconv.Atoi(line)
	return num
}

func (io *IO) Println(a ...interface{}) {
	fmt.Fprintln(io.w, a...)
}

func (io *IO) Close() {
	io.w.Flush()
}

func done(a ...interface{}) {
	io := NewIO()
	io.Println(a...)
	io.Close()
	os.Exit(0)
}

func main() {
	solver := NewSolver()
	solver.Solve()
}
