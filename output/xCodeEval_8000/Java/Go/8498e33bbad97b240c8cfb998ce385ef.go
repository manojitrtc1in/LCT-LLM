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
			if line == "" || line[0] != '\n' {
				io.next = strings.Split(line, " ")
				break
			}
		}
	}
	str := io.next[0]
	io.next = io.next[1:]
	return str
}

func (io *IO) nextInt() int {
	str := io.nextString()
	num, _ := strconv.Atoi(str)
	return num
}

func (io *IO) nextLong() int64 {
	str := io.nextString()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func (io *IO) nextDouble() float64 {
	str := io.nextString()
	num, _ := strconv.ParseFloat(str, 64)
	return num
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
