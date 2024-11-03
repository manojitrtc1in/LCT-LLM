package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Line struct {
	a, b, c float64
}

type Segment struct {
	a, b Point
}

type Circle struct {
	center Point
	radius float64
}

type Polygon struct {
	vertices []Point
}

func NewPoint(x, y float64) Point {
	return Point{x, y}
}

func NewLine(p, q Point) Line {
	a := q.y - p.y
	b := p.x - q.x
	c := -a*p.x - b*p.y
	return Line{a, b, c}
}

func NewSegment(p, q Point) Segment {
	return Segment{p, q}
}

func NewCircle(center Point, radius float64) Circle {
	return Circle{center, radius}
}

func NewPolygon(vertices []Point) Polygon {
	return Polygon{vertices}
}

func (p Point) Distance(q Point) float64 {
	return math.Sqrt(math.Pow(q.x-p.x, 2) + math.Pow(q.y-p.y, 2))
}

func (l Line) Contains(p Point) bool {
	return math.Abs(l.a*p.x+l.b*p.y+l.c) < 1e-8
}

func (l Line) Intersect(m Line) Point {
	determinant := l.a*m.b - l.b*m.a
	if math.Abs(determinant) < 1e-8 {
		return Point{}
	}
	x := (l.b*m.c - l.c*m.b) / determinant
	y := (l.c*m.a - l.a*m.c) / determinant
	return Point{x, y}
}

func (s Segment) Contains(p Point, includeEnds bool) bool {
	if includeEnds && (p == s.a || p == s.b) {
		return true
	}
	if s.a == s.b {
		return false
	}
	l := NewLine(s.a, s.b)
	if !l.Contains(p) {
		return false
	}
	perpendicular := NewLine(s.a, s.a.Perpendicular())
	aValue := perpendicular.Value(s.a)
	bValue := perpendicular.Value(s.b)
	pValue := perpendicular.Value(p)
	return (aValue < pValue && pValue < bValue) || (bValue < pValue && pValue < aValue)
}

func (s Segment) Distance(p Point) float64 {
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
	return p.Distance(NewLine(s.a, s.b))
}

func (s Segment) Length() float64 {
	return s.a.Distance(s.b)
}

func (s Segment) Line() Line {
	return NewLine(s.a, s.b)
}

func (p Point) Perpendicular() Point {
	return Point{-p.y, p.x}
}

func (p Point) Line(q Point) Line {
	return NewLine(p, q)
}

func (p Point) Distance(l Line) float64 {
	return math.Abs(l.a*p.x + l.b*p.y + l.c)
}

func (p Point) Angle() float64 {
	return math.Atan2(p.y, p.x)
}

func (p Point) Rotate(angle float64) Point {
	nx := p.x*math.Cos(angle) - p.y*math.Sin(angle)
	ny := p.y*math.Cos(angle) + p.x*math.Sin(angle)
	return Point{nx, ny}
}

func (p Point) String() string {
	return fmt.Sprintf("(%f, %f)", p.x, p.y)
}

func main() {
	fmt.Println("Hello world!")
}
