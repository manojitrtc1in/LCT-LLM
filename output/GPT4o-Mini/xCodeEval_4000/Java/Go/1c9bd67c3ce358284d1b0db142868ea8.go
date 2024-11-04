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

func (in *MyInput) nextInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

func (in *MyInput) nextLong() int64 {
	in.scanner.Scan()
	var x int64
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

type Solver struct {
	zone int
	x1, y1, x2, y2 int
	m int
}

func (solver *Solver) solve(in *MyInput) {
	solver.m = in.nextInt()
	h1 := in.nextInt()
	a1 := in.nextInt()
	solver.x1 = in.nextInt()
	solver.y1 = in.nextInt()

	h2 := in.nextInt()
	a2 := in.nextInt()
	solver.x2 = in.nextInt()
	solver.y2 = in.nextInt()

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
		fmt.Println(ans)
		return
	}

	M := len2 - len1
	gcd := GCD(r1, r2)
	if M%gcd != 0 {
		can = false
	}

	if can {
		for k := 0; ; k++ {
			kPrim := (int64(r1)*int64(k) - int64(M)) / int64(r2)
			if kPrim < 0 {
				continue
			}
			if int64(r1)*int64(k)-int64(r2)*kPrim == int64(M) {
				fmt.Println(int64(r1)*int64(k) + int64(len1))
				return
			}
		}
	}

	fmt.Println(-1)
}

func (solver *Solver) cycleFinding(a int) (int, int) {
	mu := 0
	lambda := 0

	turtle := solver.f(a)
	hare := solver.f(turtle)
	for turtle != hare {
		turtle = solver.f(turtle)
		hare = solver.f(solver.f(hare))
	}
	mu = 0
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
	return lambda, mu
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
	solver := Solver{}

	for {
		solver.solve(in)
	}
}
