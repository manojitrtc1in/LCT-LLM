package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var (
	mod = 1000000007
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int64
	var k int
	fmt.Fscan(reader, &n, &k)

	items := 200
	fib := make([]int, items)
	fib[0] = 1
	fib[1] = 2
	a := make([]int, items)
	for i := 2; i < items; i++ {
		fib[i] = (fib[i-1] + fib[i-2]) % mod
	}
	for i := 0; i < items; i++ {
		a[i] = (fib[i] * pow(i+1, k)) % mod
		if i > 0 {
			a[i] = (a[i] + a[i-1]) % mod
		}
	}

	seq := make([]int, len(a))
	copy(seq, a)
	solver := NewLinearRecurrenceSolver(seq, mod)
	ans := solver.Solve(n-1, seq)

	fmt.Fprintln(writer, ans)
}

func pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := pow(x, n>>1)
	r = (r * r) % mod
	if n&1 == 1 {
		r = (r * x) % mod
	}
	return r
}

type LinearRecurrenceSolver struct {
	coe       []int
	mod       int
	p         []int
	remainder []int
	pow       *Power
	n         int
}

func NewLinearRecurrenceSolver(coe []int, mod int) *LinearRecurrenceSolver {
	solver := new(LinearRecurrenceSolver)
	solver.coe = coe
	solver.mod = mod
	solver.n = len(coe)
	solver.pow = NewPower(mod)
	solver.remainder = make([]int, len(coe))
	solver.p = make([]int, len(coe)+1)
	for i := solver.n - 1; i >= 0; i-- {
		solver.p = append(solver.p, -solver.coe[i])
	}
	solver.p = append(solver.p, 1)
	return solver
}

func (solver *LinearRecurrenceSolver) Solve(k int64, a []int) int {
	if k < int64(len(a)) {
		return a[k]
	}
	module(k, solver.p, solver.remainder, solver.pow)
	return solver.solve(a)
}

func (solver *LinearRecurrenceSolver) solve(a []int) int {
	ans := 0
	remainder := solver.remainder
	for i := 0; i < solver.n; i++ {
		ans = (ans + (remainder[i]*a[i])%solver.mod) % solver.mod
	}
	return ans
}

func module(k int64, p []int, remainder []int, pow *Power) {
	rP := rankOf(p)
	if rP == 0 {
		remainder[0] = 0
		return
	}
	a := make([]int, len(p))
	c := make([]int, len(p))
	moduleHelper(k, a, p, c, remainder, rP, pow)
}

func moduleHelper(k int64, a []int, b []int, c []int, remainder []int, rb int, pow *Power) {
	if k < int64(rb) {
		remainder[0] = 1
		return
	}
	moduleHelper(k/2, a, b, c, remainder, rb, pow)
	mul(remainder, remainder, a, pow.mod)
	if k%2 == 1 {
		ra := rankOf(a)
		a = append(a, 0)
		copy(a[1:], a)
		a[0] = 0
	}
	divide(a, b, c, remainder, pow)
}

func divide(a []int, b []int, c []int, remainder []int, pow *Power) {
	rA := rankOf(a)
	rB := rankOf(b)

	if rA < rB {
		remainder[0] = 0
		copy(remainder[1:], a)
		return
	}

	rC := max(0, rA-rB)
	remainder[0] = 0
	remainder = append(remainder, make([]int, rC+1)...)
	copy(remainder, a)

	if extGCD(b[rB], pow.mod) != 1 {
		panic("Invalid input")
	}
	inv := extGCDGetX()
	for i := rA; i >= rB; i-- {
		if remainder[i] == 0 {
			continue
		}
		factor := (pow.mod - (remainder[i] * inv) % pow.mod) % pow.mod
		c[rC] = (pow.mod - factor) % pow.mod
		for k := rB; k >= 0; k-- {
			remainder[k+rC] = (remainder[k+rC] + (factor * b[k])%pow.mod) % pow.mod
		}
		rC--
	}

	normalize(remainder)
}

func extGCD(x, m int) int {
	if x >= m {
		return extGCD0(x, m)
	}
	g := extGCD0(m, x)
	tmp := extGCDGetX()
	extGCDSetX(extGCDGetY())
	extGCDSetY(tmp)
	return g
}

func extGCD0(a, b int) int {
	if b == 0 {
		extGCDSetX(1)
		extGCDSetY(0)
		return a
	}
	g := extGCD0(b, a%b)
	n := extGCDGetX()
	m := extGCDGetY()
	extGCDSetX(m)
	extGCDSetY(n - m*(a/b))
	return g
}

var (
	extGCDX int
	extGCDY int
)

func extGCDGetX() int {
	return extGCDX
}

func extGCDSetX(x int) {
	extGCDX = x
}

func extGCDGetY() int {
	return extGCDY
}

func extGCDSetY(y int) {
	extGCDY = y
}

func normalize(list []int) {
	r := rankOf(list)
	list = list[:r+1]
}

func mul(a []int, b []int, c []int, mod int) {
	rA := rankOf(a)
	rB := rankOf(b)
	c = make([]int, rA+rB+1)
	for i := 0; i <= rA; i++ {
		for j := 0; j <= rB; j++ {
			c[i+j] = (c[i+j] + (a[i]*b[j])%mod) % mod
		}
	}
}

func rankOf(p []int) int {
	r := len(p) - 1
	for r >= 0 && p[r] == 0 {
		r--
	}
	return max(0, r)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type Power struct {
	mod int
}

func NewPower(mod int) *Power {
	power := new(Power)
	power.mod = mod
	return power
}

func (power *Power) Pow(x, n int) int {
	if n == 0 {
		return 1
	}
	r := power.Pow(x, n>>1)
	r = (r * r) % power.mod
	if n&1 == 1 {
		r = (r * x) % power.mod
	}
	return r
}
