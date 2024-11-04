package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
)

type PairInt struct {
	X, Y int
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput() *MyInput {
	return &MyInput{scanner: bufio.NewScanner(os.Stdin)}
}

func (in *MyInput) NextInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscan(in.scanner.Text(), &x)
	return x
}

type Solver struct {
	zone int
	x1, y1, x2, y2, m int
}

func (solver *Solver) solve(in *MyInput, out *bufio.Writer, testCase int) {
	solver.m = in.NextInt()
	h1 := in.NextInt()
	a1 := in.NextInt()
	solver.x1 = in.NextInt()
	solver.y1 = in.NextInt()

	h2 := in.NextInt()
	a2 := in.NextInt()
	solver.x2 = in.NextInt()
	solver.y2 = in.NextInt()

	r1, mu1 := solver.cycleFinding(h1)
	r2, mu2 := solver.cycleFinding(h2)

	can := true

	solver.zone = 1
	len1 := 0
	for h1 != a1 {
		h1 = solver.f(h1)
		len1++
		if len1 > solver.m {
			can = false
			break
		}
	}

	solver.zone = 2
	len2 := 0
	for h2 != a2 {
		h2 = solver.f(h2)
		len2++
		if len2 > solver.m {
			can = false
			break
		}
	}

	ans := -2
	if mu1 > len1 {
		if mu2 > len2 {
			if len1 == len2 {
				ans = len1
			} else {
				can = false
			}
		} else {
			temp := len1 - len2
			if temp%r2 == 0 && temp >= 0 {
				ans = len1
			} else {
				can = false
			}
		}
	} else {
		if mu2 > len2 {
			temp := len2 - len1
			if temp%r1 == 0 && temp >= 0 {
				ans = len2
			} else {
				can = false
			}
		}
	}

	if ans != -2 {
		fmt.Fprintln(out, ans)
		return
	}

	M := len2 - len1
	gcd := GCD(r1, r2)
	if M%gcd != 0 {
		can = false
	}

	if can {
		for k := 0; ; k++ {
			kPrim := (r1*k - M) / r2
			if kPrim < 0 {
				continue
			}
			if r1*k-r2*kPrim == M {
				fmt.Fprintln(out, r1*k+len1)
				return
			}
		}
	}

	fmt.Fprintln(out, -1)
}

func (solver *Solver) cycleFinding(a int) (int, int) {
	mu, lambda := 0, 0
	turtle, hare := solver.f(a), solver.f(solver.f(a))
	for turtle != hare {
		turtle = solver.f(turtle)
		hare = solver.f(solver.f(hare))
	}
	turtle = a
	for turtle != hare {
		turtle = solver.f(turtle)
		hare = solver.f(hare)
		mu++
	}
	lambda = 1
	hare = solver.f(turtle)
	for turtle != hare {
		hare = solver.f(hare)
		lambda++
	}
	return mu, lambda
}

func (solver *Solver) f(h int) int {
	if solver.zone == 1 {
		return (solver.x1*h + solver.y1) % solver.m
	}
	return (solver.x2*h + solver.y2) % solver.m
}

func GCD(a, b int) int {
	if b == 0 {
		return a
	}
	return GCD(b, a%b)
}

func main() {
	in := NewMyInput()
	out := bufio.NewWriter(os.Stdout)
	solver := &Solver{}

	test := 1
	for {
		solver.solve(in, out, test)
		test++
		out.Flush()
	}
}
