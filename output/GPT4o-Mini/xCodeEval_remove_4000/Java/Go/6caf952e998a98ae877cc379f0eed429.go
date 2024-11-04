package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solver := &A{}
	solver.Solve(1, in, out)
}

type Task interface {
	Solve(testNumber int, in *bufio.Reader, out io.Writer)
}

type A struct{}

func (a *A) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	var str string
	fmt.Fscan(in, &str)
	ret, n, c := 0, len(str), 0
	for i := 1; i < n; i++ {
		if str[i] != str[i-1] {
			ret += c % 2
			c = 0
		} else {
			c++
		}
	}
	ret += c % 2
	fmt.Fprintln(out, ret)
}

type B struct{}

func (b *B) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	var str string
	fmt.Fscan(in, &str)
	var ret []byte
	for i := 0; i < len(str); i++ {
		c := str[i]
		switch c {
		case '>':
			ret = append(ret, "1000"...)
		case '<':
			ret = append(ret, "1001"...)
		case '+':
			ret = append(ret, "1010"...)
		case '-':
			ret = append(ret, "1011"...)
		case '.':
			ret = append(ret, "1100"...)
		case ',':
			ret = append(ret, "1101"...)
		case '[':
			ret = append(ret, "1110"...)
		default:
			ret = append(ret, "1111"...)
		}
	}
	n := 0
	for _, r := range ret {
		n = (2*n + int(r-'0')) % 1000003
	}
	fmt.Fprintln(out, n)
}

type C struct{}

func (c *C) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation here
}

type D struct{}

func (d *D) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation here
}

type E struct{}

func (e *E) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation here
}

type F struct{}

func (f *F) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation here
}
