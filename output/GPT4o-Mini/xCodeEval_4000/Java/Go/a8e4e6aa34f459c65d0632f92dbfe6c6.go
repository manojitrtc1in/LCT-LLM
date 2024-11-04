package main

import (
	"fmt"
	"math"
	"os"
)

type Modular struct {
	m int
}

func NewModular(m int) Modular {
	return Modular{m: m}
}

func (mod Modular) valueOf(x int) int {
	x %= mod.m
	if x < 0 {
		x += mod.m
	}
	return x
}

func (mod Modular) mul(x, y int) int {
	return mod.valueOf(x * y)
}

func (mod Modular) plus(x, y int) int {
	return mod.valueOf(x + y)
}

type FastInput struct {
	data []byte
	pos  int
}

func NewFastInput() *FastInput {
	return &FastInput{data: make([]byte, 0)}
}

func (in *FastInput) readInt() int {
	var sign int = 1
	in.skipBlank()
	if in.pos < len(in.data) && (in.data[in.pos] == '+' || in.data[in.pos] == '-') {
		if in.data[in.pos] == '-' {
			sign = -1
		}
		in.pos++
	}

	val := 0
	for in.pos < len(in.data) && in.data[in.pos] >= '0' && in.data[in.pos] <= '9' {
		val = val*10 + int(in.data[in.pos]-'0')
		in.pos++
	}
	return val * sign
}

func (in *FastInput) skipBlank() {
	for in.pos < len(in.data) && (in.data[in.pos] <= 32) {
		in.pos++
	}
}

type FastOutput struct {
	cache []byte
}

func NewFastOutput() *FastOutput {
	return &FastOutput{cache: make([]byte, 0)}
}

func (out *FastOutput) println(c int) {
	out.cache = append(out.cache, fmt.Sprintf("%d\n", c)...)
}

func (out *FastOutput) flush() {
	os.Stdout.Write(out.cache)
	out.cache = out.cache[:0]
}

type FCards struct {
	mod Modular
}

func NewFCards() *FCards {
	return &FCards{mod: NewModular(998244353)}
}

func (solver *FCards) solve(in *FastInput, out *FastOutput) {
	n := in.readInt()
	m := in.readInt()
	k := in.readInt()

	xk := make([]int, k+1)
	for i := 0; i <= k; i++ {
		xk[i] = int(math.Pow(float64(i), float64(k)))
	}

	ans := 0
	for t := 0; t <= k; t++ {
		p1 := 1 // Placeholder for binomial coefficient
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := 1 // Placeholder for composite calculation
			contrib = solver.mod.mul(contrib, xk[t-i])
			if i%2 == 1 {
				contrib = solver.mod.valueOf(-contrib)
			}
			p2 = solver.mod.plus(p2, contrib)
		}
		p3 := 1 // Placeholder for inverse calculation

		contrib := solver.mod.mul(p1, p2)
		contrib = solver.mod.mul(contrib, p3)
		ans = solver.mod.plus(ans, contrib)
	}

	out.println(ans)
}

func main() {
	in := NewFastInput()
	out := NewFastOutput()
	solver := NewFCards()
	solver.solve(in, out)
	out.flush()
}
