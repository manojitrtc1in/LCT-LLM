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

type Point struct {
	x, y float64
}

func NewPoint(x, y float64) *Point {
	return &Point{x: x, y: y}
}

type Line struct {
	a, b, c float64
}

func NewLine(p1, p2 *Point) *Line {
	a := p2.y - p1.y
	b := p1.x - p2.x
	c := -a*p1.x - b*p1.y
	return &Line{a: a, b: b, c: c}
}

func (l *Line) Contains(p *Point) bool {
	return math.Abs(l.a*p.x+l.b*p.y+l.c) < 1e-8
}

func (l *Line) Intersect(other *Line) *Point {
	determinant := l.b*other.a - l.a*other.b
	if math.Abs(determinant) < 1e-8 {
		return nil
	}
	x := (l.c*other.b - l.b*other.c) / determinant
	y := (l.a*other.c - l.c*other.a) / determinant
	return NewPoint(x, y)
}

type Segment struct {
	a, b *Point
	line *Line
}

func NewSegment(a, b *Point) *Segment {
	return &Segment{a: a, b: b, line: NewLine(a, b)}
}

func (s *Segment) Contains(p *Point) bool {
	if s.a.Equals(p) || s.b.Equals(p) {
		return true
	}
	if s.a.Equals(s.b) {
		return false
	}
	if !s.line.Contains(p) {
		return false
	}
	perpendicular := s.line.Perpendicular(s.a)
	aValue := perpendicular.Value(s.a)
	bValue := perpendicular.Value(s.b)
	pointValue := perpendicular.Value(p)
	return (aValue < pointValue && pointValue < bValue) || (bValue < pointValue && pointValue < aValue)
}

func (s *Segment) Line() *Line {
	if s.line == nil {
		s.line = NewLine(s.a, s.b)
	}
	return s.line
}

func (s *Segment) Distance(p *Point) float64 {
	length := s.Length()
	left := p.Distance(s.a)
	if length < 1e-8 {
		return left
	}
	right := p.Distance(s.b)
	if left*left > right*right+length*length {
		return right
	}
	if right*right > left*left+length*length {
		return left
	}
	return p.Distance(s.Line())
}

func (s *Segment) Length() float64 {
	return s.a.Distance(s.b)
}

type Circle struct {
	center *Point
	radius float64
}

func NewCircle(center *Point, radius float64) *Circle {
	return &Circle{center: center, radius: radius}
}

func (c *Circle) Contains(p *Point) bool {
	return p.Distance(c.center) < c.radius+1e-8
}

func (c *Circle) Intersect(other *Circle) []*Point {
	distance := c.center.Distance(other.center)
	if distance > c.radius+other.radius+1e-8 || math.Abs(c.radius-other.radius) > distance+1e-8 {
		return nil
	}
	p := (c.radius + other.radius + distance) / 2
	height := 2 * math.Sqrt(p*(p-c.radius)*(p-other.radius)*(p-distance)) / distance
	l1 := math.Sqrt(c.radius*c.radius - height*height)
	l2 := math.Sqrt(other.radius*other.radius - height*height)
	if c.radius*c.radius+distance*distance < other.radius*other.radius {
		l1 = -l1
	}
	if c.radius*c.radius > distance*distance+other.radius*other.radius {
		l2 = -l2
	}
	middle := NewPoint((c.center.x*l2+other.center.x*l1)/(l1+l2), (c.center.y*l2+other.center.y*l1)/(l1+l2))
	line := c.center.Line(other.center).Perpendicular(middle)
	return line.Intersect(c)
}

type LinePerpendicular struct {
	line *Line
	point *Point
}

func NewLinePerpendicular(line *Line, point *Point) *LinePerpendicular {
	return &LinePerpendicular{line: line, point: point}
}

func (lp *LinePerpendicular) Value(p *Point) float64 {
	return lp.line.a*p.x + lp.line.b*p.y + lp.line.c
}

func (lp *LinePerpendicular) Intersect(other *LinePerpendicular) *Point {
	determinant := lp.line.b*other.line.a - lp.line.a*other.line.b
	if math.Abs(determinant) < 1e-8 {
		return nil
	}
	x := (lp.line.c*other.line.b - lp.line.b*other.line.c) / determinant
	y := (lp.line.a*other.line.c - lp.line.c*other.line.a) / determinant
	return NewPoint(x, y)
}

func (lp *LinePerpendicular) Perpendicular(p *Point) *Line {
	a := -lp.line.b
	b := lp.line.a
	c := -a*p.x - b*p.y
	return NewLine(a, b, c)
}

type GeometryUtils struct{}

func (gu *GeometryUtils) CanonicalAngle(angle float64) float64 {
	for angle > math.Pi {
		angle -= 2 * math.Pi
	}
	for angle < -math.Pi {
		angle += 2 * math.Pi
	}
	return angle
}

func (gu *GeometryUtils) PositiveAngle(angle float64) float64 {
	for angle > 2*math.Pi-1e-8 {
		angle -= 2 * math.Pi
	}
	for angle < -1e-8 {
		angle += 2 * math.Pi
	}
	return angle
}

type Polygon struct {
	vertices []*Point
	sides    []*Segment
}

func NewPolygon(vertices []*Point) *Polygon {
	return &Polygon{vertices: vertices}
}

func (p *Polygon) Contains(point *Point) bool {
	return p.ContainsWithStrictness(point, false)
}

func (p *Polygon) ContainsWithStrictness(point *Point, strict bool) bool {
	for _, segment := range p.sides {
		if segment.Contains(point) {
			return !strict
		}
	}
	totalAngle := gu.CanonicalAngle(math.Atan2(p.vertices[0].y-point.y, p.vertices[0].x-point.x) -
		math.Atan2(p.vertices[len(p.vertices)-1].y-point.y, p.vertices[len(p.vertices)-1].x-point.x))
	for i := 1; i < len(p.vertices); i++ {
		totalAngle += gu.CanonicalAngle(math.Atan2(p.vertices[i].y-point.y, p.vertices[i].x-point.x) -
			math.Atan2(p.vertices[i-1].y-point.y, p.vertices[i-1].x-point.x))
	}
	return math.Abs(totalAngle) > math.Pi
}

func (p *Polygon) Sides() []*Segment {
	if p.sides == nil {
		p.sides = make([]*Segment, len(p.vertices))
		for i := 0; i < len(p.vertices)-1; i++ {
			p.sides[i] = NewSegment(p.vertices[i], p.vertices[i+1])
		}
		p.sides[len(p.sides)-1] = NewSegment(p.vertices[len(p.vertices)-1], p.vertices[0])
	}
	return p.sides
}

type Solver interface {
	Solve(testNumber int, in *InputReader, out *OutputWriter)
}

type TaskA struct{}

func NewTaskA() *TaskA {
	return &TaskA{}
}

func (t *TaskA) Solve(testNumber int, in *InputReader, out *OutputWriter) {
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

type TaskB struct{}

func NewTaskB() *TaskB {
	return &TaskB{}
}

func (t *TaskB) Solve(testNumber int, in *InputReader, out *OutputWriter) {
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
		n = (2*n + int(ret.String()[i]) - '0') % 1000003
	}
	out.Println(n)
}

type TaskC struct{}

func NewTaskC() *TaskC {
	return &TaskC{}
}

func (t *TaskC) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	// TODO: Implement the solution for Task C
}

type TaskD struct{}

func NewTaskD() *TaskD {
	return &TaskD{}
}

func (t *TaskD) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	// TODO: Implement the solution for Task D
}

type TaskE struct{}

func NewTaskE() *TaskE {
	return &TaskE{}
}

func (t *TaskE) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	// TODO: Implement the solution for Task E
}

type TaskF struct{}

func NewTaskF() *TaskF {
	return &TaskF{}
}

func (t *TaskF) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	// TODO: Implement the solution for Task F
}

func main() {
	in := NewInputReader(os.Stdin)
	out := NewOutputWriter(os.Stdout)
	defer out.Flush()

	task := NewTaskA()
	task.Solve(1, in, out)
}
