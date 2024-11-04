package main

import (
	"bytes"
	"fmt"
	"io"
	"math/big"
	"math/rand"
	"os"
)

type FastIO struct {
	cache   bytes.Buffer
	is      io.Reader
	os      io.Writer
	next    int
	buf     []byte
	bufLen  int
	bufOffset int
}

func NewFastIO(is io.Reader, os io.Writer) *FastIO {
	return &FastIO{
		is: is,
		os: os,
		buf: make([]byte, 1<<13),
	}
}

func (io *FastIO) read() int {
	if io.bufLen == io.bufOffset {
		io.bufOffset = 0
		n, err := io.is.Read(io.buf)
		if err != nil {
			panic(err)
		}
		io.bufLen = n
		if n == 0 {
			return -1
		}
	}
	b := io.buf[io.bufOffset]
	io.bufOffset++
	return int(b)
}

func (io *FastIO) skipBlank() {
	for io.next >= 0 && io.next <= 32 {
		io.next = io.read()
	}
}

func (io *FastIO) readInt() int {
	sign := 1
	io.skipBlank()
	if io.next == '+' || io.next == '-' {
		if io.next == '-' {
			sign = -1
		}
		io.next = io.read()
	}

	val := 0
	if sign == 1 {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 + io.next - '0'
			io.next = io.read()
		}
	} else {
		for io.next >= '0' && io.next <= '9' {
			val = val*10 - io.next + '0'
			io.next = io.read()
		}
	}

	return val * sign
}

func (io *FastIO) flush() {
	_, err := io.os.Write(io.cache.Bytes())
	if err != nil {
		panic(err)
	}
	io.cache.Reset()
}

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) valueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) mul(x, y int) int {
	return mod.valueOf(x * y)
}

func (mod *Modular) plus(x, y int) int {
	return mod.valueOf(x + y)
}

type Power struct {
	modular *Modular
}

func NewPower(modular *Modular) *Power {
	return &Power{modular: modular}
}

func (p *Power) pow(x int, n int64) int {
	if n == 0 {
		return 1
	}
	r := p.pow(x, n>>1)
	r = p.modular.valueOf(r * r)
	if n&1 == 1 {
		r = p.modular.valueOf(r * x)
	}
	return r
}

type Task struct {
	io      *FastIO
	modular *Modular
	power   *Power
	n       int
	m       int
	fW      int
	hW      int
	inv     []int
	f       [][]int
	h       [][]int
}

func NewTask(io *FastIO) *Task {
	modular := NewModular(998244353)
	power := NewPower(modular)
	return &Task{io: io, modular: modular, power: power}
}

func (task *Task) solve() {
	task.n = task.io.readInt()
	task.m = task.io.readInt()
	a := make([]int, task.n)
	count := make([]int, 2)

	for i := 0; i < task.n; i++ {
		a[i] = task.io.readInt()
		count[a[i]%2]++
	}

	w := make([]int, task.n)
	for i := 0; i < task.n; i++ {
		w[i] = task.io.readInt()
		if a[i]%2 == 0 {
			task.hW += w[i]
		} else {
			task.fW += w[i]
		}
	}

	task.inv = make([]int, task.m*2+1)
	for i := 0; i < task.m*2+1; i++ {
		task.inv[i] = task.power.pow(task.hW+task.fW+i-task.m, int64(task.modular.m-2))
	}

	task.f = make([][]int, task.m+1)
	task.h = make([][]int, task.m+1)
	for i := 0; i <= task.m; i++ {
		task.f[i] = make([]int, task.m+1)
		task.h[i] = make([]int, task.m+1)
		for j := 0; j <= task.m; j++ {
			task.f[i][j] = -1
			task.h[i][j] = -1
		}
		task.f[i][0] = 1
		task.h[i][0] = 1
	}

	for i := 0; i < task.n; i++ {
		if a[i]%2 == 1 {
			task.io.cache.WriteString(fmt.Sprintf("%d\n", task.modular.mul(w[i], task.fFunc(0, task.m))))
		} else {
			task.io.cache.WriteString(fmt.Sprintf("%d\n", task.modular.mul(w[i], task.hFunc(0, task.m))))
		}
	}
}

func (task *Task) fFunc(i, k int) int {
	if task.f[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.modular.plus(i, task.fW)
		fixJ := task.modular.plus(task.hW, -j)
		task.f[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.f[i][k] = task.modular.plus(task.f[i][k], task.modular.mul(task.modular.mul(fixI+1, inv), task.fFunc(i+1, k-1)))
		task.f[i][k] = task.modular.plus(task.f[i][k], task.modular.mul(task.modular.mul(fixJ, inv), task.fFunc(i, k-1)))
	}
	return task.f[i][k]
}

func (task *Task) hFunc(i, k int) int {
	if task.h[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.modular.plus(i, task.fW)
		fixJ := task.modular.plus(task.hW, -j)
		task.h[i][k] = 0
		inv := task.inv[i-j+task.m]

		task.h[i][k] = task.modular.plus(task.h[i][k], task.modular.mul(task.modular.mul(fixJ-1, inv), task.hFunc(i, k-1)))
		task.h[i][k] = task.modular.plus(task.h[i][k], task.modular.mul(task.modular.mul(fixI, inv), task.hFunc(i+1, k-1)))
	}
	return task.h[i][k]
}

func main() {
	local := os.Getenv("ONLINE_JUDGE") == ""
	io := NewFastIO(os.Stdin, os.Stdout)
	task := NewTask(io)

	task.solve()
	io.flush()
}
