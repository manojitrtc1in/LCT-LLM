package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Pair struct {
	X int
	Y int
}

type Solver struct {
	zone int
	x1   int
	y1   int
	x2   int
	y2   int
}

func main() {
	in := NewMyInput(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solver := Solver{}

	for test := 1; ; test++ {
		solver.Solve(in, out, test)
		out.Flush()
	}

	out.Flush()
	out.Close()
}

func (solver *Solver) Solve(in *MyInput, out *bufio.Writer, testCase int) {
	m := in.NextInt()
	h1 := in.NextInt()
	a1 := in.NextInt()
	solver.x1 = in.NextInt()
	solver.y1 = in.NextInt()

	h2 := in.NextInt()
	a2 := in.NextInt()
	solver.x2 = in.NextInt()
	solver.y2 = in.NextInt()

	zone := 1
	r1, mu1 := solver.CycleFinding(h1)
	zone = 2
	r2, mu2 := solver.CycleFinding(h2)

	can := true

	zone = 1
	len1 := 0
	for h1 != a1 {
		h1 = solver.F(h1)
		len1++
		if len1 > m {
			can = false
			break
		}
	}

	zone = 2
	len2 := 0
	for h2 != a2 {
		h2 = solver.F(h2)
		len2++
		if len2 > m {
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
			kPrim := (int64(r1)*int64(k) - int64(M)) / int64(r2)
			if kPrim < 0 {
				continue
			}
			if int64(r1)*int64(k)-int64(r2)*kPrim == int64(M) {
				fmt.Fprintln(out, int64(r1)*int64(k)+int64(len1))
				return
			}
		}
	}

	fmt.Fprintln(out, -1)
}

func (solver *Solver) CycleFinding(a int) (int, int) {
	var mu, lambda int

	turtle, hare := solver.F(a), solver.F(solver.F(a))
	for turtle != hare {
		turtle = solver.F(turtle)
		hare = solver.F(solver.F(hare))
	}
	mu = 0
	turtle = a
	for turtle != hare {
		turtle = solver.F(turtle)
		hare = solver.F(hare)
		mu++
	}
	lambda = 1

	hare = solver.F(turtle)
	for turtle != hare {
		hare = solver.F(hare)
		lambda++
	}
	return mu, lambda
}

func (solver *Solver) F(h int) int {
	if solver.zone == 1 {
		return (solver.x1*h + solver.y1) % m
	} else {
		return (solver.x2*h + solver.y2) % m
	}
}

func GCD(a, b int) int {
	if b != 0 {
		return GCD(b, a%b)
	}
	return a
}

type MyInput struct {
	scanner *bufio.Scanner
}

func NewMyInput(reader *os.File) *MyInput {
	scanner := bufio.NewScanner(reader)
	scanner.Split(bufio.ScanWords)
	return &MyInput{scanner}
}

func (in *MyInput) Next() string {
	if !in.scanner.Scan() {
		panic("input ended unexpectedly")
	}
	return in.scanner.Text()
}

func (in *MyInput) NextInt() int {
	i, err := strconv.Atoi(in.Next())
	if err != nil {
		panic(err)
	}
	return i
}

func (in *MyInput) NextLine() string {
	if !in.scanner.Scan() {
		panic("input ended unexpectedly")
	}
	return in.scanner.Text()
}
