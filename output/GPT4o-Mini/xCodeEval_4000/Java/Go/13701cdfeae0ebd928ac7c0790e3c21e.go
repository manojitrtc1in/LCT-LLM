package main

import (
	"fmt"
	"io"
	"math/rand"
	"sync"
)

type Modular struct {
	m int
}

func NewModular(m int) *Modular {
	return &Modular{m: m}
}

func (mod *Modular) ValueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod *Modular) Mul(x, y int) int {
	return mod.ValueOf(x * y)
}

func (mod *Modular) Plus(x, y int) int {
	return mod.ValueOf(x + y)
}

type FastInput struct {
	r io.Reader
	buf []byte
}

func NewFastInput(r io.Reader) *FastInput {
	return &FastInput{r: r, buf: make([]byte, 1<<13)}
}

func (in *FastInput) ReadInt() (int, error) {
	var sign, val int = 1, 0
	for {
		n, err := in.r.Read(in.buf)
		if err != nil {
			return 0, err
		}
		for i := 0; i < n; i++ {
			if in.buf[i] >= '0' && in.buf[i] <= '9' {
				val = val*10 + int(in.buf[i]-'0')
			} else if in.buf[i] == '-' {
				sign = -1
			} else if in.buf[i] == '+' {
				sign = 1
			} else if val > 0 {
				return sign * val, nil
			}
		}
	}
}

type FastOutput struct {
	w io.Writer
}

func NewFastOutput(w io.Writer) *FastOutput {
	return &FastOutput{w: w}
}

func (out *FastOutput) Println(c int) {
	fmt.Fprintln(out.w, c)
}

type TaskG struct {
	mod *Modular
}

func NewTaskG() *TaskG {
	return &TaskG{mod: NewModular(998244353)}
}

func (t *TaskG) Solve(in *FastInput, out *FastOutput) {
	n, _ := in.ReadInt()
	k, _ := in.ReadInt()
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		val, _ := in.ReadInt()
		allow[val] = 1
	}
	p := make([]int, 0)
	for _, v := range allow {
		if v > 0 {
			p = append(p, v)
		}
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)

	// Placeholder for NumberTheoryTransform and Polynomials
	// Implement the necessary logic here

	ans := 0
	for _, plus := range last {
		ans = t.mod.Plus(ans, t.mod.Mul(plus, plus))
	}

	out.Println(ans)
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := NewFastInput(io.Stdin)
		out := NewFastOutput(io.Stdout)
		solver := NewTaskG()
		solver.Solve(in, out)
	}()
	wg.Wait()
}
