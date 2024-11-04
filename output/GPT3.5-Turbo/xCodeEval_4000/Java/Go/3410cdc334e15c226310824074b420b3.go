package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	inf     = int(1e8)
	modular = 998244353
)

type FastIO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewFastIO() *FastIO {
	return &FastIO{
		reader: bufio.NewReader(os.Stdin),
		writer: bufio.NewWriter(os.Stdout),
	}
}

func (io *FastIO) ReadInt() int {
	num, _ := strconv.Atoi(io.ReadString())
	return num
}

func (io *FastIO) ReadString() string {
	str, _ := io.reader.ReadString('\n')
	return str[:len(str)-1]
}

func (io *FastIO) WriteString(str string) {
	io.writer.WriteString(str)
}

func (io *FastIO) Flush() {
	io.writer.Flush()
}

type Task struct {
	io    *FastIO
	debug bool
}

func NewTask(io *FastIO, debug bool) *Task {
	return &Task{
		io:    io,
		debug: debug,
	}
}

func (task *Task) Run() {
	task.Solve()
}

func (task *Task) Solve() {
	n := task.io.ReadInt()
	m := task.io.ReadInt()
	a := make([]int, n)
	count := make([]int, 2)
	for i := 0; i < n; i++ {
		a[i] = task.io.ReadInt()
		count[a[i]%2]++
	}
	w := make([]int, n)
	fW := 0
	hW := 0
	for i := 0; i < n; i++ {
		w[i] = task.io.ReadInt()
		if a[i]%2 == 0 {
			hW += w[i]
		} else {
			fW += w[i]
		}
	}

	inv := make([]int, m*2+1)
	for i := 0; i < m*2+1; i++ {
		inv[i] = inverse(hW + fW + i - m)
	}

	f := make([][]int, m+1)
	h := make([][]int, m+1)
	for i := 0; i <= m; i++ {
		f[i] = make([]int, m+1)
		h[i] = make([]int, m+1)
	}

	for i := 0; i <= m; i++ {
		for j := 0; j <= m; j++ {
			f[i][j] = -1
			h[i][j] = -1
		}
	}

	for i := 0; i <= m; i++ {
		f[i][0] = 1
		h[i][0] = 1
	}

	for i := 0; i < n; i++ {
		if a[i]%2 == 1 {
			task.io.WriteString(fmt.Sprintf("%d\n", mul(w[i], f(0, m, fW, hW, inv))))
		} else {
			task.io.WriteString(fmt.Sprintf("%d\n", mul(w[i], h(0, m, fW, hW, inv))))
		}
	}
}

func f(i, k, fW, hW int, inv []int) int {
	if f[i][k] == -1 {
		j := (m - k) - i
		fixI := plus(i, fW)
		fixJ := plus(hW, -j)
		f[i][k] = 0
		f[i][k] = plus(f[i][k], mul(mul(plus(fixI, 1), inv[i-j+m]), f(i+1, k-1, fW, hW, inv)))
		f[i][k] = plus(f[i][k], mul(mul(fixJ, inv[i-j+m]), f(i, k-1, fW, hW, inv)))
	}
	return f[i][k]
}

func h(i, k, fW, hW int, inv []int) int {
	if h[i][k] == -1 {
		j := (m - k) - i
		fixI := plus(i, fW)
		fixJ := plus(hW, -j)
		h[i][k] = 0
		h[i][k] = plus(h[i][k], mul(mul(plus(fixJ, -1), inv[i-j+m]), h(i, k-1, fW, hW, inv)))
		h[i][k] = plus(h[i][k], mul(mul(fixI, inv[i-j+m]), h(i+1, k-1, fW, hW, inv)))
	}
	return h[i][k]
}

func plus(a, b int) int {
	return (a + b) % modular
}

func mul(a, b int) int {
	return (a * b) % modular
}

func inverse(a int) int {
	return pow(a, modular-2)
}

func pow(a, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(a, n>>1)
	r = mul(r, r)
	if n&1 == 1 {
		r = mul(r, a)
	}
	return r
}

func main() {
	io := NewFastIO()
	task := NewTask(io, false)
	task.Run()
	io.Flush()
}
