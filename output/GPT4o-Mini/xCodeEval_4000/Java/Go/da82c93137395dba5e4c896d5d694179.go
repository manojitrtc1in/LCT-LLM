package main

import (
	"fmt"
	"math/big"
	"math/rand"
	"os"
)

type FastIO struct {
	cache   []byte
	is      *os.File
	os      *os.File
	next    int
}

func NewFastIO(is *os.File, os *os.File) *FastIO {
	return &FastIO{
		is:  is,
		os:  os,
		cache: make([]byte, 0),
	}
}

func (io *FastIO) read() int {
	buf := make([]byte, 1<<13)
	n, err := io.is.Read(buf)
	if err != nil {
		return -1
	}
	io.cache = append(io.cache, buf[:n]...)
	if len(io.cache) == 0 {
		return -1
	}
	ch := io.cache[0]
	io.cache = io.cache[1:]
	return int(ch)
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

type Task struct {
	io    *FastIO
	fW    int
	hW    int
	inv   []int
	f     [][]int
	h     [][]int
	n     int
	m     int
}

func NewTask(io *FastIO) *Task {
	return &Task{
		io: io,
	}
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
		task.inv[i] = task.inverse(task.hW + task.fW + i - task.m)
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
	}

	for i := 0; i <= task.m; i++ {
		task.f[i][0] = 1
		task.h[i][0] = 1
	}

	for i := 0; i < task.n; i++ {
		if a[i]%2 == 1 {
			fmt.Println(task.mul(w[i], task.f(0, task.m)))
		} else {
			fmt.Println(task.mul(w[i], task.h(0, task.m)))
		}
	}
}

func (task *Task) f(i, k int) int {
	if task.f[i][k] == -1 {
		j := (task.m - k) - i
		fixI := (i + task.fW) % 998244353
		fixJ := (task.hW - j) % 998244353
		task.f[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.f[i][k] = (task.f[i][k] + task.mul(fixI+1, inv*task.f(i+1, k-1))) % 998244353
		task.f[i][k] = (task.f[i][k] + task.mul(fixJ, inv*task.f(i, k-1))) % 998244353
	}
	return task.f[i][k]
}

func (task *Task) h(i, k int) int {
	if task.h[i][k] == -1 {
		j := (task.m - k) - i
		fixI := (i + task.fW) % 998244353
		fixJ := (task.hW - j) % 998244353
		task.h[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.h[i][k] = (task.h[i][k] + task.mul(fixJ-1, inv*task.h(i, k-1))) % 998244353
		task.h[i][k] = (task.h[i][k] + task.mul(fixI, inv*task.h(i+1, k-1))) % 998244353
	}
	return task.h[i][k]
}

func (task *Task) mul(x, y int) int {
	return (x * y) % 998244353
}

func (task *Task) inverse(x int) int {
	return pow(x, 998244353-2)
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = (r * r) % 998244353
	if n&1 == 1 {
		r = (r * x) % 998244353
	}
	return r
}

func main() {
	local := true
	var io *FastIO
	if local {
		file, _ := os.Open("D:\\DATABASE\\TESTCASE\\Code.in")
		io = NewFastIO(file, os.Stdout)
	} else {
		io = NewFastIO(os.Stdin, os.Stdout)
	}
	task := NewTask(io)
	task.solve()
}
