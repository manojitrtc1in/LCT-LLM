package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Point struct {
	x, y int
}

type PointD struct {
	x, y float64
}

type Fraction struct {
	numerator   int64
	denominator int64
}

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func (f *Fraction) Cancellation() {
	g := gcd(abs(f.numerator), abs(f.denominator))
	f.numerator /= g
	f.denominator /= g
	if f.denominator < 0 {
		f.numerator *= -1
		f.denominator *= -1
	}
}

func (f *Fraction) Add(other Fraction) Fraction {
	result := Fraction{}
	result.denominator = lcm(f.denominator, other.denominator)
	result.numerator = f.numerator*result.denominator/f.denominator + other.numerator*result.denominator/other.denominator
	result.Cancellation()
	return result
}

func (f *Fraction) Subtract(other Fraction) Fraction {
	result := Fraction{}
	result.denominator = lcm(f.denominator, other.denominator)
	result.numerator = f.numerator*result.denominator/f.denominator - other.numerator*result.denominator/other.denominator
	result.Cancellation()
	return result
}

func (f *Fraction) Multiply(other Fraction) Fraction {
	result := Fraction{}
	result.numerator = f.numerator * other.numerator
	result.denominator = f.denominator * other.denominator
	result.Cancellation()
	return result
}

func (f *Fraction) Divide(other Fraction) Fraction {
	result := Fraction{}
	result.numerator = f.numerator * other.denominator
	result.denominator = f.denominator * other.numerator
	result.Cancellation()
	return result
}

func (f *Fraction) String() string {
	if f.numerator == 0 {
		return "0"
	}
	s := ""
	if f.numerator < 0 {
		s += "-"
	}
	if abs(f.numerator) >= f.denominator {
		s += strconv.FormatInt(abs(f.numerator)/f.denominator, 10) + " "
	}
	if abs(f.numerator)%f.denominator != 0 {
		s += strconv.FormatInt(abs(f.numerator)%f.denominator, 10)
	} else {
		s = s[:len(s)-1]
	}
	if f.denominator != 1 {
		s += "/" + strconv.FormatInt(f.denominator, 10)
	}
	return s
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}

func readLong(scanner *bufio.Scanner) int64 {
	scanner.Scan()
	val, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return val
}

func readDouble(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	val, _ := strconv.ParseFloat(scanner.Text(), 64)
	return val
}

func solve(scanner *bufio.Scanner, out *bufio.Writer) {
	n := readInt(scanner) - 1
	m := readInt(scanner)
	a := readInt(scanner) - 1
	b := readInt(scanner) - 1
	i := a / m
	j := b / m
	l := a % m
	r := b
	if b == n {
		r = m - 1
	}
	if l == 0 && r == m-1 {
		fmt.Fprint(out, 1)
		return
	}
	if j-i < 2 {
		fmt.Fprint(out, j-i+1)
		return
	}
	if (l != 0 && r == m-1) || (l == 0 && r != m-1) {
		fmt.Fprint(out, 2)
		return
	}
	if l-r == 1 {
		fmt.Fprint(out, 2)
		return
	}
	fmt.Fprint(out, 3)
}

func main() {
	var in *os.File
	var out *os.File
	if os.Getenv("id5") != "" {
		in = os.Stdin
		out = os.Stdout
	} else {
		in, _ = os.Open("input.txt")
		out, _ = os.Create("output.txt")
	}
	defer in.Close()
	defer out.Close()

	scanner := bufio.NewScanner(in)
	writer := bufio.NewWriter(out)

	solve(scanner, writer)

	writer.Flush()
}
