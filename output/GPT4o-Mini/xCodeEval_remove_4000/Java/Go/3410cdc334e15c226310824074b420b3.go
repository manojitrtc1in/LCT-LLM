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
	cache  bytes.Buffer
	is     io.Reader
	os     io.Writer
	next   int
	buf    []byte
	bufLen int
}

func NewFastIO(is io.Reader, os io.Writer) *FastIO {
	return &FastIO{
		is:  is,
		os:  os,
		buf: make([]byte, 1<<13),
	}
}

func (io *FastIO) read() int {
	if io.bufLen == 0 {
		n, err := io.is.Read(io.buf)
		if err != nil {
			return -1
		}
		io.bufLen = n
	}
	if io.bufLen == 0 {
		return -1
	}
	b := io.buf[0]
	io.buf = io.buf[1:]
	io.bufLen--
	return int(b)
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
	for io.next >= '0' && io.next <= '9' {
		val = val*10 + io.next - '0'
		io.next = io.read()
	}
	return val * sign
}

func (io *FastIO) skipBlank() {
	for io.next >= 0 && io.next <= 32 {
		io.next = io.read()
	}
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

type Task struct {
	io    *FastIO
	mod   *Modular
	n, m  int
	fW, hW int
	inv   []int
	f, h  [][]int
}

func NewTask(io *FastIO) *Task {
	return &Task{
		io:  io,
		mod: NewModular(998244353),
	}
}

func (task *Task) solve() {
	task.n = task.io.readInt()
	task.m = task.io.readInt()
	a := make([]int, task.n)
	count := [2]int{}
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
		task.inv[i] = task.mod.valueOf(task.hW + task.fW + i - task.m)
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
			task.io.cache.WriteString(fmt.Sprintf("%d\n", task.mod.mul(w[i], task.fCalc(0, task.m))))
		} else {
			task.io.cache.WriteString(fmt.Sprintf("%d\n", task.mod.mul(w[i], task.hCalc(0, task.m))))
		}
	}
}

func (task *Task) fCalc(i, k int) int {
	if task.f[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.mod.valueOf(i + task.fW)
		fixJ := task.mod.valueOf(task.hW - j)
		task.f[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.f[i][k] = task.mod.valueOf(task.f[i][k] + task.mod.mul(task.mod.mul(fixI+1, inv), task.fCalc(i+1, k-1)))
		task.f[i][k] = task.mod.valueOf(task.f[i][k] + task.mod.mul(task.mod.mul(fixJ, inv), task.fCalc(i, k-1)))
	}
	return task.f[i][k]
}

func (task *Task) hCalc(i, k int) int {
	if task.h[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.mod.valueOf(i + task.fW)
		fixJ := task.mod.valueOf(task.hW - j)
		task.h[i][k] = 0
		inv := task.inv[i-j+task.m]

		task.h[i][k] = task.mod.valueOf(task.h[i][k] + task.mod.mul(task.mod.mul(fixJ-1, inv), task.hCalc(i, k-1)))
		task.h[i][k] = task.mod.valueOf(task.h[i][k] + task.mod.mul(task.mod.mul(fixI, inv), task.hCalc(i+1, k-1)))
	}
	return task.h[i][k]
}

func main() {
	local := os.Getenv("ONLINE_JUDGE") == ""
	io := NewFastIO(os.Stdin, os.Stdout)
	task := NewTask(io)

	task.solve()
	io.os.Write([]byte(io.cache.String()))
}
