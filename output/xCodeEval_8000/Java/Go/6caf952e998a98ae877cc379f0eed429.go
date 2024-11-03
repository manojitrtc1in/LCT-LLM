package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
	"strings"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	num, _ := strconv.Atoi(in.readString())
	return num
}

func (in *InputReader) ReadString() string {
	str, _ := in.reader.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

type Task interface {
	Solve(testNumber int, in *InputReader, out *OutputWriter)
}

type A struct{}

func (task *A) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	str := in.ReadString()
	ret := 0
	n := len(str)
	c := 0
	for i := 1; i < n; i++ {
		if str[i] != str[i-1] {
			ret += c % 2
			c = 0
		} else {
			c++
		}
	}
	ret += c % 2
	out.Println(ret)
}

type B struct{}

func (task *B) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	str := in.ReadString()
	ret := strings.Builder{}
	for i := 0; i < len(str); i++ {
		c := str[i]
		if c == '>' {
			ret.WriteString("1000")
		} else if c == '<' {
			ret.WriteString("1001")
		} else if c == '+' {
			ret.WriteString("1010")
		} else if c == '-' {
			ret.WriteString("1011")
		} else if c == '.' {
			ret.WriteString("1100")
		} else if c == ',' {
			ret.WriteString("1101")
		} else if c == '[' {
			ret.WriteString("1110")
		} else {
			ret.WriteString("1111")
		}
	}
	n := 0
	for i := 0; i < ret.Len(); i++ {
		n = (2*n + int(ret[i]) - '0') % 1000003
	}
	out.Println(n)
}

type C struct{}

func (task *C) Solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type D struct{}

func (task *D) Solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type E struct{}

func (task *E) Solve(testNumber int, in *InputReader, out *OutputWriter) {

}

type F struct{}

func (task *F) Solve(testNumber int, in *InputReader, out *OutputWriter) {

}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	defer out.Flush()

	task := &A{}
	task.Solve(1, in, out)
}
