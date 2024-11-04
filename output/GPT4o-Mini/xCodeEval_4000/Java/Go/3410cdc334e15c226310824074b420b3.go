package main

import (
	"fmt"
	"math/big"
	"os"
)

type FastIO struct {
	cache []byte
}

func (io *FastIO) flush() {
	_, err := os.Stdout.Write(io.cache)
	if err != nil {
		panic(err)
	}
	io.cache = nil
}

func (io *FastIO) readInt() int {
	var x int
	fmt.Scan(&x)
	return x
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
	io     *FastIO
	mod    *Modular
	n, m   int
	fW, hW int
	inv    []int
	f, h   [][]int
}

func NewTask(io *FastIO, mod *Modular) *Task {
	return &Task{
		io:  io,
		mod: mod,
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
			task.io.cache = append(task.io.cache, fmt.Sprintf("%d\n", task.mod.mul(w[i], task.fFunc(0, task.m)))...)
		} else {
			task.io.cache = append(task.io.cache, fmt.Sprintf("%d\n", task.mod.mul(w[i], task.hFunc(0, task.m)))...)
		}
	}
}

func (task *Task) fFunc(i, k int) int {
	if task.f[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.mod.valueOf(i + task.fW)
		fixJ := task.mod.valueOf(task.hW - j)
		task.f[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.f[i][k] = task.mod.valueOf(task.f[i][k] + task.mod.mul(task.mod.mul(fixI+1, inv), task.fFunc(i+1, k-1)))
		task.f[i][k] = task.mod.valueOf(task.f[i][k] + task.mod.mul(task.mod.mul(fixJ, inv), task.fFunc(i, k-1)))
	}
	return task.f[i][k]
}

func (task *Task) hFunc(i, k int) int {
	if task.h[i][k] == -1 {
		j := (task.m - k) - i
		fixI := task.mod.valueOf(i + task.fW)
		fixJ := task.mod.valueOf(task.hW - j)
		task.h[i][k] = 0
		inv := task.inv[i-j+task.m]
		task.h[i][k] = task.mod.valueOf(task.h[i][k] + task.mod.mul(task.mod.mul(fixJ-1, inv), task.hFunc(i, k-1)))
		task.h[i][k] = task.mod.valueOf(task.h[i][k] + task.mod.mul(task.mod.mul(fixI, inv), task.hFunc(i+1, k-1)))
	}
	return task.h[i][k]
}

func main() {
	local := os.Getenv("ONLINE_JUDGE") == ""
	io := &FastIO{}
	mod := NewModular(998244353)
	task := NewTask(io, mod)

	task.solve()
	io.flush()
}
