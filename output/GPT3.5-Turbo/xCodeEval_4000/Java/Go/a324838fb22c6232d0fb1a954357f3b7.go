package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"strconv"
)

type ProblemSolver struct{}

func (ps *ProblemSolver) solveTheProblem(in *InputReader, out *OutputWriter, nt *NumberTheory) {
	test := 1

	for test > 0 {
		n := in.nextInt()
		ar := make([][]int, n)
		for i := 0; i < n; i++ {
			ar[i] = in.nextIntArray(n)
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
	problemSolver := &ProblemSolver{}
	problemSolver.solveTheProblem(in, out, nt)
	out.flush()
	out.close()
}

type InputReader struct {
	finished bool
	reader   *bufio.Reader
}

func NewInputReader(reader io.Reader) *InputReader {
	return &InputReader{false, bufio.NewReader(reader)}
}

func (in *InputReader) read() int {
	if in.finished {
		panic("InputReader: read called after EOF")
	}
	c, err := in.reader.ReadByte()
	if err != nil {
		if err == io.EOF {
			in.finished = true
			return -1
		}
		panic(err)
	}
	return int(c)
}

func (in *InputReader) peek() int {
	if in.finished {
		panic("InputReader: peek called after EOF")
	}
	c, err := in.reader.Peek(1)
	if err != nil {
		if err == io.EOF {
			in.finished = true
			return -1
		}
		panic(err)
	}
	return int(c[0])
}

func (in *InputReader) nextInt() int {
	c := in.read()
	for isSpaceChar(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !isSpaceChar(c) {
		if c < '0' || c > '9' {
			panic("InputReader: nextInt: Invalid input format")
		}
		res *= 10
		res += c - '0'
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) nextLong() int64 {
	c := in.read()
	for isSpaceChar(c) {
		c = in.read()
	}
	sgn := int64(1)
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := int64(0)
	for !isSpaceChar(c) {
		if c < '0' || c > '9' {
			panic("InputReader: nextLong: Invalid input format")
		}
		res *= 10
		res += int64(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) nextLine() string {
	c := in.read()
	for isSpaceChar(c) {
		c = in.read()
	}
	var res []byte
	for !isSpaceChar(c) {
		if !isValidCodePoint(c) {
			panic("InputReader: nextLine: Invalid input format")
		}
		res = append(res, byte(c))
		c = in.read()
	}
	return string(res)
}

func isSpaceChar(c int) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1
}

func isValidCodePoint(c int) bool {
	return c >= 0 && c <= 0x10FFFF
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(writer io.Writer) *OutputWriter {
	return &OutputWriter{bufio.NewWriter(writer)}
}

func (out *OutputWriter) print(objects ...interface{}) {
	for i, obj := range objects {
		if i != 0 {
			out.writer.WriteByte(' ')
		}
		switch v := obj.(type) {
		case int:
			out.writer.WriteString(strconv.Itoa(v))
		case int64:
			out.writer.WriteString(strconv.FormatInt(v, 10))
		case string:
			out.writer.WriteString(v)
		default:
			panic("OutputWriter: print: Invalid argument type")
		}
	}
}

func (out *OutputWriter) println(objects ...interface{}) {
	out.print(objects...)
	out.writer.WriteByte('\n')
}

func (out *OutputWriter) printf(format string, objects ...interface{}) {
	out.writer.WriteString(fmt.Sprintf(format, objects...))
}

func (out *OutputWriter) flush() {
	out.writer.Flush()
}

func (out *OutputWriter) close() {
	out.writer.Flush()
}

type NumberTheory struct{}

func (nt *NumberTheory) modularAddition(a, b, MOD int) int {
	return (a%MOD + b%MOD) % MOD
}

func (nt *NumberTheory) modularMultiplication(a, b, MOD int) int {
	return ((a%MOD)*(b%MOD)) % MOD
}

func (nt *NumberTheory) modularSubtraction(a, b, MOD int) int {
	return (a%MOD - b%MOD + MOD) % MOD
}

func (nt *NumberTheory) binaryExponentiation(x, n int) int {
	if n == 0 {
		return 1
	} else if n%2 == 0 {
		return nt.binaryExponentiation(x*x, n/2)
	} else {
		return x * nt.binaryExponentiation(x*x, (n-1)/2)
	}
}

func (nt *NumberTheory) modularExponentiation(x, n, MOD int) int {
	if n == 0 {
		return 1 % MOD
	} else if n%2 == 0 {
		return nt.modularExponentiation(nt.modularMultiplication(x, x, MOD), n/2, MOD)
	} else {
		return nt.modularMultiplication(x, nt.modularExponentiation(nt.modularMultiplication(x, x, MOD), (n-1)/2, MOD), MOD)
	}
}

func (nt *NumberTheory) factorials(n int) int64 {
	if n == 0 {
		return 1
	}
	return int64(n) * nt.factorials(n-1)
}

func (nt *NumberTheory) distinctPrimeFactors(n int) []int {
	factorials := make([]int, 0)
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
	factorials := make([]int, 0)
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
