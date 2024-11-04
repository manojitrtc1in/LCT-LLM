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

type PairInt struct {
	X int
	Y int
}

type Solver struct {
}

func main() {
	in := NewMyInput(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	solver := Solver{}

	{
		test := 1
		for {
			solver.solve(in, out, test)
			out.Flush()
			test++
		}
	}

	out.Flush()
	out.Close()
}

func (s *Solver) solve(in *MyInput, out *bufio.Writer, testCase int) {
	m := in.NextInt()
	h1 := in.NextInt()
	a1 := in.NextInt()
	x1 := in.NextInt()
	y1 := in.NextInt()

	h2 := in.NextInt()
	a2 := in.NextInt()
	x2 := in.NextInt()
	y2 := in.NextInt()

	zone := 1
	r1 := cycleFinding(h1, x1, y1, m).Y
	mu1 := cycleFinding(h1, x1, y1, m).X

	zone = 2
	r2 := cycleFinding(h2, x2, y2, m).Y
	mu2 := cycleFinding(h2, x2, y2, m).X

	can := true

	zone = 1
	len1 := 0
	for h1 != a1 {
		h1 = f(h1, x1, y1, m)
		len1++
		if len1 > m {
			can = false
			break
		}
	}

	zone = 2
	len2 := 0
	for h2 != a2 {
		h2 = f(h2, x2, y2, m)
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

func cycleFinding(a, x, y, m int) PairInt {
	var mu, lambda int

	turtle := f(a, x, y, m)
	hare := f(turtle, x, y, m)
	for turtle != hare {
		turtle = f(turtle, x, y, m)
		hare = f(f(hare, x, y, m), x, y, m)
	}
	mu = 0
	turtle = a
	for turtle != hare {
		turtle = f(turtle, x, y, m)
		hare = f(hare, x, y, m)
		mu++
	}
	lambda = 1

	hare = f(turtle, x, y, m)
	for turtle != hare {
		hare = f(hare, x, y, m)
		lambda++
	}
	return PairInt{mu, lambda}
}

func f(h, x, y, m int) int {
	if zone == 1 {
		return add(mul(x, h, m), y, m)
	} else {
		return add(mul(x, h, m), y, m)
	}
}

func add(a, b, MOD int) int {
	return ((a + b) % MOD + MOD) % MOD
}

func mul(a, b, MOD int) int {
	return ((a * b) % MOD + MOD) % MOD
}

func GCD(a, b int) int {
	if b != 0 {
		return GCD(b, a%b)
	}
	return a
}

func NewMyInput(input *os.File) *MyInput {
	return &MyInput{
		br: bufio.NewReader(input),
	}
}

type MyInput struct {
	br *bufio.Reader
}

func (in *MyInput) Next() string {
	for {
		str, err := in.br.ReadString('\n')
		if err != nil {
			panic(err)
		}
		str = strings.TrimSpace(str)
		if str != "" {
			return str
		}
	}
}

func (in *MyInput) NextInt() int {
	num, err := strconv.Atoi(in.Next())
	if err != nil {
		panic(err)
	}
	return num
}
