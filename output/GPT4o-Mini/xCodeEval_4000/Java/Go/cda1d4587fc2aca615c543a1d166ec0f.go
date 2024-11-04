package main

import (
	"fmt"
	"math"
	"os"
)

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

type Power struct {
	modular *Modular
}

func NewPower(modular *Modular) *Power {
	return &Power{modular: modular}
}

func (p *Power) pow(x, n int) int {
	if n == 0 {
		return p.modular.valueOf(1)
	}
	r := p.pow(x, n>>1)
	r = p.modular.valueOf(r * r)
	if n&1 == 1 {
		r = p.modular.valueOf(r * x)
	}
	return r
}

type FastInput struct {
	is      *os.File
	buf     []byte
	bufLen  int
	bufOffset int
	next    int
}

func NewFastInput(is *os.File) *FastInput {
	return &FastInput{is: is, buf: make([]byte, 1<<13)}
}

func (in *FastInput) read() int {
	if in.bufLen == in.bufOffset {
		in.bufOffset = 0
		n, err := in.is.Read(in.buf)
		if err != nil {
			in.bufLen = -1
			return -1
		}
		in.bufLen = n
	}
	if in.bufLen == -1 {
		return -1
	}
	in.next = int(in.buf[in.bufOffset])
	in.bufOffset++
	return in.next
}

func (in *FastInput) skipBlank() {
	for in.next >= 0 && in.next <= 32 {
		in.next = in.read()
	}
}

func (in *FastInput) readInt() int {
	sign := 1
	in.skipBlank()
	if in.next == '+' || in.next == '-' {
		if in.next == '-' {
			sign = -1
		}
		in.next = in.read()
	}

	val := 0
	if sign == 1 {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 + in.next - '0'
			in.next = in.read()
		}
	} else {
		for in.next >= '0' && in.next <= '9' {
			val = val*10 - in.next + '0'
			in.next = in.read()
		}
	}

	return val
}

type FCards struct {
	mod *Modular
}

func NewFCards() *FCards {
	return &FCards{mod: NewModular(998244353)}
}

func (f *FCards) solve(testNumber int, in *FastInput) int {
	n := in.readInt()
	m := in.readInt()
	k := in.readInt()

	ans := 0
	for t := 0; t <= k; t++ {
		p1 := f.composite(n, t)
		p2 := 0
		for i := 0; i <= t; i++ {
			contrib := f.composite(t, i)
			if i%2 == 1 {
				contrib = f.mod.valueOf(-contrib)
			}
			p2 = f.mod.valueOf(p2 + contrib)
		}
		p3 := f.inverse(t)

		contrib := f.mod.mul(p1, p2)
		contrib = f.mod.mul(contrib, p3)
		ans = f.mod.valueOf(ans + contrib)
	}

	return ans
}

func (f *FCards) composite(m, n int) int {
	if n > m {
		return 0
	}
	return f.mod.mul(f.factorial(m), f.invFact(n))
}

func (f *FCards) factorial(n int) int {
	if n == 0 {
		return 1
	}
	res := 1
	for i := 1; i <= n; i++ {
		res = f.mod.mul(res, i)
	}
	return res
}

func (f *FCards) invFact(n int) int {
	if n == 0 {
		return 1
	}
	return f.mod.valueOf(1) // Placeholder for inverse factorial logic
}

func main() {
	input := NewFastInput(os.Stdin)
	fcards := NewFCards()
	result := fcards.solve(1, input)
	fmt.Println(result)
}
