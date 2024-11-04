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
	next []string
}

func NewIO() *IO {
	return &IO{r: bufio.NewReader(os.Stdin), w: bufio.NewWriter(os.Stdout)}
}

func (io *IO) nextString() string {
	if len(io.next) == 0 {
		for {
			line, _ := io.r.ReadString('\n')
			io.next = strings.Fields(line)
			if len(io.next) > 0 {
				break
			}
		}
	}
	str := io.next[0]
	io.next = io.next[1:]
	return str
}

func (io *IO) nextInt() int {
	i, _ := strconv.Atoi(io.nextString())
	return i
}

func (io *IO) nextLong() int64 {
	i, _ := strconv.ParseInt(io.nextString(), 10, 64)
	return i
}

func (io *IO) nextDouble() float64 {
	i, _ := strconv.ParseFloat(io.nextString(), 64)
	return i
}

func (io *IO) println(a ...interface{}) {
	fmt.Fprintln(io.w, a...)
}

func (io *IO) close() {
	io.w.Flush()
}

func main() {
	io := NewIO()
	defer io.close()

	solver := NewSolver(io)
	solver.solve()
}

type Solver struct {
	io *IO
}

func NewSolver(io *IO) *Solver {
	return &Solver{io: io}
}

func (solver *Solver) solve() {
	n := solver.io.nextInt()

	endOfBrute := min(n, 30)
	prev := make(map[int64]bool)
	prev[0] = true
	for i := 0; i < endOfBrute; i++ {
		next := make(map[int64]bool)
		for v := range prev {
			next[v+1] = true
			next[v+5] = true
			next[v+10] = true
			next[v+50] = true
		}
		prev = next
	}

	if n > endOfBrute {
		diff := n - endOfBrute
		done(int64(len(prev)) + diff*49)
	}

	solver.io.println(len(prev))
}

func done(output interface{}) {
	fmt.Println(output)
	os.Exit(0)
}

func min(v ...int) int {
	ans := v[0]
	for i := 1; i < len(v); i++ {
		ans = int(math.Min(float64(ans), float64(v[i])))
	}
	return ans
}
