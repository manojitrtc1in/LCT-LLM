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

	var solver Task = &A{}
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
		switch str[i] {
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
	for i := 0; i < len(ret); i++ {
		n = (2*n + int(ret[i]-'0')) % 1000003
	}
	fmt.Fprintln(out, n)
}

type C struct{}

func (c *C) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation for C
}

type D struct{}

func (d *D) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation for D
}

type E struct{}

func (e *E) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation for E
}

type F struct{}

func (f *F) Solve(testNumber int, in *bufio.Reader, out io.Writer) {
	// Implementation for F
}
