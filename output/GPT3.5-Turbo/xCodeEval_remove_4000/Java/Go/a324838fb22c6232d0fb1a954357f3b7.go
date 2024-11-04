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

type ProblemSolver struct{}

func (ps *ProblemSolver) id13(in *InputReader, out *OutputWriter, nt *NumberTheory) {
	test := 1

	for test > 0 {
		n := in.nextInt()
		ar := make([][]int, n)
		for i := 0; i < n; i++ {
			ar[i] = make([]int, n)
			for j := 0; j < n; j++ {
				ar[i][j] = in.nextInt()
			}
		}

		sum := int64(0)
		for i := 0; i < n; i++ {
			sum += int64(ar[i][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[n-i-1][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[(n-1)/2][i])
		}

		for i := 0; i < n; i++ {
			sum += int64(ar[i][(n-1)/2])
		}
		fmt.Println(sum - int64(ar[(n-1)/2][(n-1)/2]*3))
		test--
	}
}

func main() {
	inputStream := os.Stdin
	outputStream := os.Stdout
	in := NewInputReader(inputStream)
	out := NewOutputWriter(outputStream)
	nt := NewNumberTheory()
	problemSolver := ProblemSolver{}
	problemSolver.id13(in, out, nt)
	out.flush()
	out.close()
}

type InputReader struct {
	finished bool
	stream   io.Reader
	buf      []byte
	curChar  int
	numChars int
	filter   id27
}

func NewInputReader(stream io.Reader) *InputReader {
	return &InputReader{
		stream: stream,
	}
}

func (in *InputReader) read() int {
	if in.numChars == -1 {
		panic("InputMismatchException")
	}
	if in.curChar >= in.numChars {
		in.curChar = 0
		numChars := 0
		var err error
		for numChars == 0 {
			numChars, err = in.stream.Read(in.buf)
			if err != nil {
				panic("InputMismatchException")
			}
		}
		if numChars <= 0 {
			return -1
		}
	}
	in.numChars = numChars
	return int(in.buf[in.curChar])
}

func (in *InputReader) peek() int {
	if in.numChars == -1 {
		return -1
	}
	if in.curChar >= in.numChars {
		in.curChar = 0
		numChars := 0
		var err error
		for numChars == 0 {
			numChars, err = in.stream.Read(in.buf)
			if err != nil {
				return -1
			}
		}
		if numChars <= 0 {
			return -1
		}
	}
	return int(in.buf[in.curChar])
}

func (in *InputReader) nextInt() int {
	c := in.read()
	for id5(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !id5(c) {
		if c < '0' || c > '9' {
			panic("InputMismatchException")
		}
		res *= 10
		res += c - '0'
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) nextLong() int64 {
	c := in.read()
	for id5(c) {
		c = in.read()
	}
	sgn := int64(1)
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := int64(0)
	for !id5(c) {
		if c < '0' || c > '9' {
			panic("InputMismatchException")
		}
		res *= 10
		res += int64(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) nextLine() string {
	c := in.read()
	for id5(c) {
		c = in.read()
	}
	res := strings.Builder{}
	for !id5(c) {
		if c != '\r' {
			res.WriteRune(rune(c))
		}
		c = in.read()
	}
	return res.String()
}

func id5(c int) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1
}

type id27 func(int) bool

func (in *InputReader) id1() string {
	buf := strings.Builder{}
	c := in.read()
	for c != '\n' && c != -1 {
		if c != '\r' {
			buf.WriteRune(rune(c))
		}
		c = in.read()
	}
	return buf.String()
}

func (in *InputReader) readLine() string {
	s := in.id1()
	for strings.TrimSpace(s) == "" {
		s = in.id1()
	}
	return s
}

func (in *InputReader) id20() int64 {
	s := in.nextLine()
	num, err := strconv.ParseInt(s, 10, 64)
	if err != nil {
		panic("InputMismatchException")
	}
	return num
}

func (in *InputReader) nextCharacter() byte {
	c := in.read()
	for id5(c) {
		c = in.read()
	}
	return byte(c)
}

func (in *InputReader) nextDouble() float64 {
	c := in.read()
	for id5(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0.0
	for !id5(c) && c != '.' {
		if c == 'e' || c == 'E' {
			return res * math.Pow(10, float64(in.nextInt()))
		}
		if c < '0' || c > '9' {
			panic("InputMismatchException")
		}
		res *= 10
		res += float64(c - '0')
		c = in.read()
	}
	if c == '.' {
		c = in.read()
		m := 1.0
		for !id5(c) {
			if c == 'e' || c == 'E' {
				return res * math.Pow(10, float64(in.nextInt()))
			}
			if c < '0' || c > '9' {
				panic("InputMismatchException")
			}
			m /= 10
			res += float64(c-'0') * m
			c = in.read()
		}
	}
	return res * float64(sgn)
}

func (in *InputReader) id4() bool {
	value := 0
	for id5(value) && value != -1 {
		value = in.read()
	}
	return value == -1
}

func (in *InputReader) next() string {
	return in.nextLine()
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(writer io.Writer) *OutputWriter {
	return &OutputWriter{
		writer: bufio.NewWriter(writer),
	}
}

func (out *OutputWriter) print(objects ...interface{}) {
	for i, obj := range objects {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, obj)
	}
}

func (out *OutputWriter) println(objects ...interface{}) {
	out.print(objects...)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printf(format string, objects ...interface{}) {
	fmt.Fprintf(out.writer, format, objects...)
}

func (out *OutputWriter) close() {
	out.writer.Flush()
}

func (out *OutputWriter) flush() {
	out.writer.Flush()
}

func (out *OutputWriter) printIntArray(array []int) {
	for i, val := range array {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, val)
	}
}

func (out *OutputWriter) printlnIntArray(array []int) {
	out.printIntArray(array)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printDoubleArray(array []float64) {
	for i, val := range array {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, val)
	}
}

func (out *OutputWriter) printlnDoubleArray(array []float64) {
	out.printDoubleArray(array)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printLongArray(array []int64) {
	for i, val := range array {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, val)
	}
}

func (out *OutputWriter) printlnLongArray(array []int64) {
	out.printLongArray(array)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printCharArray(array []byte) {
	for i, val := range array {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, val)
	}
}

func (out *OutputWriter) printlnCharArray(array []byte) {
	out.printCharArray(array)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printStringArray(array []string) {
	for i, val := range array {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		fmt.Fprint(out.writer, val)
	}
}

func (out *OutputWriter) printlnStringArray(array []string) {
	out.printStringArray(array)
	out.writer.WriteByte('\n')
}

type NumberTheory struct{}

func NewNumberTheory() *NumberTheory {
	return &NumberTheory{}
}

func (nt *NumberTheory) id11(a, b, MOD int) int {
	return (a%MOD + b%MOD) % MOD
}

func (nt *NumberTheory) id19(a, b, MOD int) int {
	return ((a%MOD)*(b%MOD)) % MOD
}

func (nt *NumberTheory) id15(a, b, MOD int) int {
	return (a%MOD - b%MOD + MOD) % MOD
}

func (nt *NumberTheory) id26(x, n int) int {
	if n == 0 {
		return 1
	} else if n%2 == 0 {
		return nt.id26(x*x, n/2)
	} else {
		return x * nt.id26(x*x, (n-1)/2)
	}
}

func (nt *NumberTheory) id23(x, n, MOD int64) int64 {
	result := int64(1)
	for n > 0 {
		if n%2 == 1 {
			result = nt.id19(result, x, MOD)
		}
		x = nt.id19(x, x, MOD)
		n /= 2
	}
	return result
}

func (nt *NumberTheory) factorials(n int64) int64 {
	if n == 0 {
		return 1
	}
	return n * nt.factorials(n-1)
}

func (nt *NumberTheory) id16(n int) []int {
	factorials := []int{}
	limit := int(math.Sqrt(float64(n)))
	if n%2 == 0 {
		factorials = append(factorials, 2)
		for n%2 == 0 {
			n /= 2
		}
	}
	for i := 3; i <= limit; i += 2 {
		if n%i == 0 {
			factorials = append(factorials, i)
			for n%i == 0 {
				n /= i
			}
		}
	}
	if n > 2 {
		factorials = append(factorials, n)
	}
	return factorials
}

func (nt *NumberTheory) primeFactors(n int) []int {
	factorials := []int{}
	limit := int(math.Sqrt(float64(n)))
	if n%2 == 0 {
		factorials = append(factorials, 2)
		for n%2 == 0 {
			n /= 2
		}
	}
	for i := 3; i <= limit; i += 2 {
		if n%i == 0 {
			factorials = append(factorials, i)
			for n%i == 0 {
				n /= i
			}
		}
	}
	if n > 2 {
		factorials = append(factorials, n)
	}
	return factorials
}

func (nt *NumberTheory) gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return nt.gcd(b, a%b)
}

func (nt *NumberTheory) lcm(a, b int) int {
	return (a * b) / nt.gcd(a, b)
}

func main() {
	// Your code here
}
