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
	num, _ := in.ReadUint64()
	return int(num)
}

func (in *InputReader) ReadUint64() (uint64, error) {
	var num uint64
	for {
		ch, err := in.reader.ReadByte()
		if err != nil {
			return 0, err
		}
		if ch >= '0' && ch <= '9' {
			num = uint64(ch - '0')
			break
		}
	}
	for {
		ch, err := in.reader.ReadByte()
		if err != nil || ch < '0' || ch > '9' {
			break
		}
		num = num*10 + uint64(ch-'0')
	}
	return num, nil
}

func (in *InputReader) ReadString() (string, error) {
	str, err := in.reader.ReadString('\n')
	if err != nil {
		return "", err
	}
	return strings.TrimRight(str, "\r\n"), nil
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

type Point struct {
	X, Y float64
}

type Line struct {
	A, B, C float64
}

func NewLine(p1, p2 Point) Line {
	a := p2.Y - p1.Y
	b := p1.X - p2.X
	c := -a*p1.X - b*p1.Y
	return Line{A: a, B: b, C: c}
}

func (l Line) Contains(p Point) bool {
	return math.Abs(l.A*p.X+l.B*p.Y+l.C) < 1e-8
}

func (l Line) Intersect(other Line) Point {
	determinant := l.B*other.A - l.A*other.B
	x := (l.C*other.B - l.B*other.C) / determinant
	y := (l.A*other.C - l.C*other.A) / determinant
	return Point{X: x, Y: y}
}

type Circle struct {
	Center Point
	Radius float64
}

func (c Circle) Contains(p Point) bool {
	return c.Center.Distance(p) < c.Radius+1e-8
}

func (c Circle) Intersect(other Circle) []Point {
	distance := c.Center.Distance(other.Center)
	if distance > c.Radius+other.Radius+1e-8 || math.Abs(c.Radius-other.Radius) > distance+1e-8 {
		return []Point{}
	}
	p := (c.Radius + other.Radius + distance) / 2
	height := 2 * math.Sqrt(p*(p-c.Radius)*(p-other.Radius)*(p-distance)) / distance
	l1 := math.Sqrt(c.Radius*c.Radius - height*height)
	l2 := math.Sqrt(other.Radius*other.Radius - height*height)
	if c.Radius*c.Radius+distance*distance < other.Radius*other.Radius {
		l1 = -l1
	}
	if c.Radius*c.Radius > distance*distance+other.Radius*other.Radius {
		l2 = -l2
	}
	middle := Point{(c.Center.X*l2 + other.Center.X*l1) / (l1 + l2), (c.Center.Y*l2 + other.Center.Y*l1) / (l1 + l2)}
	line := NewLine(c.Center, other.Center).Perpendicular(middle)
	return []Point{
		Point{X: middle.X + l1*line.B, Y: middle.Y - l1*line.A},
		Point{X: middle.X - l1*line.B, Y: middle.Y + l1*line.A},
	}
}

func (p Point) Distance(other Point) float64 {
	dx := p.X - other.X
	dy := p.Y - other.Y
	return math.Sqrt(dx*dx + dy*dy)
}

func (l Line) Perpendicular(p Point) Line {
	return Line{A: -l.B, B: l.A, C: l.B*p.X - l.A*p.Y}
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)

	var A int64
	fmt.Fscan(in.reader, &A)

	divides := make(map[int64][]int64)
	for i := int64(1); i*i <= A; i++ {
		if A%i == 0 {
			divides[i] = append(divides[i], A/i)
			if i*i != A {
				divides[A/i] = append(divides[A/i], i)
			}
		}
	}

	dp := make([][]int64, 2)
	for i := range dp {
		dp[i] = make([]int64, len(divides))
	}

	dp[0][0] = 1
	idx := 0
	for _, values := range divides {
		idx ^= 1
		for j, x := range divides {
			dp[idx][j] = dp[idx^1][j]
			for _, v := range x {
				if j%v == 0 {
					dp[idx][j] += dp[idx^1][j/v]
				}
			}
		}
	}

	out.Println(dp[idx][len(divides)-1])
	out.Flush()
}
