package main

import (
	"fmt"
	"math"
)

const eps = 1e-8
const pi = math.Acos(-1.0)

func dblcmp(d float64) int {
	if math.Abs(d) < eps {
		return 0
	}
	if d > eps {
		return 1
	}
	return -1
}

type Point struct {
	x, y float64
}

func NewPoint(x, y float64) Point {
	return Point{x: x, y: y}
}

func (p *Point) Input() {
	fmt.Scan(&p.x, &p.y)
}

func (p *Point) Output() {
	fmt.Printf("%.12f %.12f\n", p.x, p.y)
}

func (p Point) Len() float64 {
	return math.Hypot(p.x, p.y)
}

func (p Point) Distance(q Point) float64 {
	return math.Hypot(p.x-q.x, p.y-q.y)
}

func (p Point) Add(q Point) Point {
	return NewPoint(p.x+q.x, p.y+q.y)
}

func (p Point) Sub(q Point) Point {
	return NewPoint(p.x-q.x, p.y-q.y)
}

func (p Point) Dot(q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p Point) Det(q Point) float64 {
	return p.x*q.y - p.y*q.x
}

func (p Point) Rotate(center Point, angle float64) Point {
	v := p.Sub(center)
	c, s := math.Cos(angle), math.Sin(angle)
	return NewPoint(center.x+v.x*c-v.y*s, center.y+v.x*s+v.y*c)
}

type Line struct {
	a, b Point
}

func NewLine(a, b Point) Line {
	return Line{a: a, b: b}
}

func (l Line) Length() float64 {
	return l.a.Distance(l.b)
}

func (l Line) DisPointToLine(p Point) float64 {
	return math.Abs(p.Sub(l.a).Det(l.b.Sub(l.a))) / l.Length()
}

type Circle struct {
	p Point
	r float64
}

func NewCircle(p Point, r float64) Circle {
	return Circle{p: p, r: r}
}

func (c Circle) Relation(p Point) int {
	dst := p.Distance(c.p)
	if dblcmp(dst-c.r) < 0 {
		return 2
	}
	if dblcmp(dst-c.r) == 0 {
		return 1
	}
	return 0
}

func dist(a, b Point, c Circle) float64 {
	l := NewLine(a, b)
	var p1, p2 Point

	if !c.PointCrossLine(l, &p1, &p2) {
		return a.Distance(b)
	}

	rd := a.Distance(b) - p1.Distance(p2)
	ds := a.Distance(b) - p1.Distance(p2) + rd*c.r

	return ds
}

func (c Circle) PointCrossLine(l Line, p1, p2 *Point) bool {
	// Implementation of point crossing line logic
	return false // Placeholder
}

func main() {
	var xp, yp, vp float64
	fmt.Scan(&xp, &yp, &vp)
	p := NewPoint(xp, yp)

	var x, y, v, r float64
	fmt.Scan(&x, &y, &v, &r)
	c := NewCircle(NewPoint(0, 0), r)

	d := 2 * pi * p.Distance(NewPoint(0, 0))
	low, high := 0.0, 1e6
	k := 1000

	for k > 0 {
		k--
		mid := (low + high) / 2.0
		s := vp * mid
		w := math.Mod(s, d)

		w = (w / d) * 2 * pi

		where := p.Rotate(NewPoint(0, 0), w)
		md := dist(where, NewPoint(x, y), c)

		if dblcmp(mid*v-md) >= 0 {
			high = mid
		} else {
			low = mid
		}
	}
	fmt.Printf("%.12f\n", low)
}
