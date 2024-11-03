package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	io := NewIO()

	solver := NewSolver(io)
	defer solver.Close()

	solver.Solve()
}

type Solver struct {
	io *IO
}

func NewSolver(io *IO) *Solver {
	return &Solver{io: io}
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
		s.io.Println(int64(len(prev)) + int64(diff)*49)
	}

	s.io.Println(len(prev))
}

type IO struct {
	r    *bufio.Reader
	w    *bufio.Writer
	buf  []byte
	bufi int
	bufc int
	sb   strings.Builder
}

func NewIO() *IO {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	buf := make([]byte, 1<<15)
	return &IO{r: r, w: w, buf: buf}
}

func (io *IO) Next() string {
	io.id43()
	start := io.bufi

	for {
		if !io.pumpBuf() {
			break
		}
		if io.isDelimiter(io.buf[io.bufi]) {
			if start == io.bufi {
				io.bufi++
				start++
				continue
			}
			break
		}
		io.bufi++
	}

	io.sb.Write(io.buf[start:io.bufi])

	return io.sb.String()
}

func (io *IO) NextInt() int {
	s := io.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (io *IO) NextLong() int64 {
	s := io.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

func (io *IO) NextDouble() float64 {
	s := io.Next()
	n, _ := strconv.ParseFloat(s, 64)
	return n
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

func (io *IO) fillBuf() error {
	io.bufi = 0
	io.bufc = 0
	for io.bufc == 0 {
		n, err := io.r.Read(io.buf)
		if err != nil {
			return err
		}
		io.bufc = n
	}
	return nil
}

func (io *IO) pumpBuf() bool {
	if io.bufi == io.bufc {
		err := io.fillBuf()
		if err != nil {
			return false
		}
	}
	return io.bufc != 0
}

func (io *IO) isDelimiter(c byte) bool {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
}

func (io *IO) id43() {
	for {
		if io.bufi == io.bufc {
			err := io.fillBuf()
			if err != nil {
				panic("IO: Out of input.")
			}
		}

		if !io.isDelimiter(io.buf[io.bufi]) {
			break
		}
		io.bufi++
	}
}

func min(v ...int) int {
	ans := v[0]
	for _, x := range v[1:] {
		if x < ans {
			ans = x
		}
	}
	return ans
}

func min64(v ...int64) int64 {
	ans := v[0]
	for _, x := range v[1:] {
		if x < ans {
			ans = x
		}
	}
	return ans
}

func max(v ...int) int {
	ans := v[0]
	for _, x := range v[1:] {
		if x > ans {
			ans = x
		}
	}
	return ans
}

func max64(v ...int64) int64 {
	ans := v[0]
	for _, x := range v[1:] {
		if x > ans {
			ans = x
		}
	}
	return ans
}

func main() {
	io := NewIO()

	solver := NewSolver(io)
	defer solver.Close()

	solver.Solve()
}

type Solver struct {
	io *IO
}

func NewSolver(io *IO) *Solver {
	return &Solver{io: io}
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
		s.io.Println(int64(len(prev)) + int64(diff)*49)
	}

	s.io.Println(len(prev))
}

type IO struct {
	r    *bufio.Reader
	w    *bufio.Writer
	buf  []byte
	bufi int
	bufc int
	sb   strings.Builder
}

func NewIO() *IO {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	buf := make([]byte, 1<<15)
	return &IO{r: r, w: w, buf: buf}
}

func (io *IO) Next() string {
	io.id43()
	start := io.bufi

	for {
		if !io.pumpBuf() {
			break
		}
		if io.isDelimiter(io.buf[io.bufi]) {
			if start == io.bufi {
				io.bufi++
				start++
				continue
			}
			break
		}
		io.bufi++
	}

	io.sb.Write(io.buf[start:io.bufi])

	return io.sb.String()
}

func (io *IO) NextInt() int {
	s := io.Next()
	n, _ := strconv.Atoi(s)
	return n
}

func (io *IO) NextLong() int64 {
	s := io.Next()
	n, _ := strconv.ParseInt(s, 10, 64)
	return n
}

func (io *IO) NextDouble() float64 {
	s := io.Next()
	n, _ := strconv.ParseFloat(s, 64)
	return n
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

func (io *IO) fillBuf() error {
	io.bufi = 0
	io.bufc = 0
	for io.bufc == 0 {
		n, err := io.r.Read(io.buf)
		if err != nil {
			return err
		}
		io.bufc = n
	}
	return nil
}

func (io *IO) pumpBuf() bool {
	if io.bufi == io.bufc {
		err := io.fillBuf()
		if err != nil {
			return false
		}
	}
	return io.bufc != 0
}

func (io *IO) isDelimiter(c byte) bool {
	return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
}

func (io *IO) id43() {
	for {
		if io.bufi == io.bufc {
			err := io.fillBuf()
			if err != nil {
				panic("IO: Out of input.")
			}
		}

		if !io.isDelimiter(io.buf[io.bufi]) {
			break
		}
		io.bufi++
	}
}

func min(v ...int) int {
	ans := v[0]
	for _, x := range v[1:] {
		if x < ans {
			ans = x
		}
	}
	return ans
}

func min64(v ...int64) int64 {
	ans := v[0]
	for _, x := range v[1:] {
		if x < ans {
			ans = x
		}
	}
	return ans
}

func max(v ...int) int {
	ans := v[0]
	for _, x := range v[1:] {
		if x > ans {
			ans = x
		}
	}
	return ans
}

func max64(v ...int64) int64 {
	ans := v[0]
	for _, x := range v[1:] {
		if x > ans {
			ans = x
		}
	}
	return ans
}
