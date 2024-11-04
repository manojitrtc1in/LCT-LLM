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

func (mod *Modular) getMod() int {
	return mod.m
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

type FastInput struct {
	is      io.Reader
	buf     []byte
	bufLen  int
	bufOffset int
	next    int
}

func NewFastInput(is io.Reader) *FastInput {
	return &FastInput{is: is, buf: make([]byte, 1<<13)}
}

func (in *FastInput) read() int {
	if in.bufLen == in.bufOffset {
		in.bufOffset = 0
		n, err := in.is.Read(in.buf)
		if err != nil {
			in.bufLen = -1
		} else {
			in.bufLen = n
		}
		if in.bufLen == -1 {
			return -1
		}
	}
	b := in.buf[in.bufOffset]
	in.bufOffset++
	return int(b)
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

type TaskG struct {
	mod Modular
}

func (solver *TaskG) solve(testNumber int, in *FastInput, out io.Writer) {
	n := in.readInt()
	k := in.readInt()
	allow := make([]int, 10)
	for i := 0; i < k; i++ {
		allow[in.readInt()] = 1
	}
	p := make([]int, 0)
	for _, v := range allow {
		if v == 1 {
			p = append(p, v)
		}
	}

	m := n / 2
	last := make([]int, len(p))
	copy(last, p)
	ntt := NewNumberTheoryTransform(&solver.mod, 3)

	lists := make([][]int, 0)
	for m > 1 {
		if m%2 == 1 {
			lists = append(lists, last)
		}
		proper := ceilLog(2 * len(last))
		last = append(last, make([]int, 1<<proper-len(last))...)
		NTT(last, 1<<proper, false, solver.mod.getMod(), 3)
		ntt.dotMul(last, last, last, proper)
		NTT(last, 1<<proper, true, solver.mod.getMod(), 3)
		normalize(last)
		m /= 2
	}
	lists = append(lists, last)

	prod := make([]int, 0)
	ntt.mulByPQ(lists, &prod)

	ans := 0
	for _, plus := range prod {
		ans = solver.mod.plus(ans, solver.mod.mul(plus, plus))
	}

	fmt.Fprintln(out, ans)
}

func main() {
	var wg sync.WaitGroup
	wg.Add(1)
	go func() {
		defer wg.Done()
		in := NewFastInput(io.Stdin)
		out := io.Writer(os.Stdout)
		solver := TaskG{mod: Modular{m: 998244353}}
		solver.solve(1, in, out)
	}()
	wg.Wait()
}

func ceilLog(x int) int {
	ans := floorLog(x)
	if (1 << ans) < x {
		ans++
	}
	return ans
}

func floorLog(x int) int {
	return 0 // Implement the logic for floorLog
}

func normalize(list []int) {
	// Implement normalization logic
}

func NTT(a []int, n int, invert bool, mod int, root int) {
	// Implement NTT logic
}

type NumberTheoryTransform struct {
	modular *Modular
	power   *Power
	g       int
}

func NewNumberTheoryTransform(mod *Modular, g int) *NumberTheoryTransform {
	return &NumberTheoryTransform{modular: mod, power: NewPower(mod), g: g}
}

func (ntt *NumberTheoryTransform) dotMul(a, b, c []int, m int) {
	for i := 0; i < 1<<m; i++ {
		c[i] = ntt.modular.mul(a[i], b[i])
	}
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
