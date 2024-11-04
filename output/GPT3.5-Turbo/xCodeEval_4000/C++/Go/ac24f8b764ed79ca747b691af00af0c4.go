package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

func (p Point) Length() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Point) Atan() float64 {
	return math.Atan2(p.y, p.x)
}

func (p Point) Subtract(q Point) Point {
	return Point{p.x - q.x, p.y - q.y}
}

func (p Point) Multiply(k float64) Point {
	return Point{p.x * k, p.y * k}
}

func (p Point) Divide(k float64) Point {
	return Point{p.x / k, p.y / k}
}

func (p Point) Equals(q Point) bool {
	return math.Abs(p.x-q.x) < 1e-9 && math.Abs(p.y-q.y) < 1e-9
}

type Line struct {
	a, b Point
}

type Segment struct {
	a, b Point
}

func NewSegment(x0, y0, x1, y1 float64) Segment {
	return Segment{Point{x0, y0}, Point{x1, y1}}
}

func (l Line) ToSegment() Segment {
	return Segment{l.a, l.b}
}

func Dot(p, q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func Det(p, q Point) float64 {
	return p.x*q.y - p.y*q.x
}

func DistSqr(p, q Point) float64 {
	dx := p.x - q.x
	dy := p.y - q.y
	return dx*dx + dy*dy
}

func DistSqrPointLine(p Point, l Line) float64 {
	v0 := l.b.Subtract(l.a)
	v1 := p.Subtract(l.a)
	return math.Pow(math.Abs(Det(v0, v1)), 2) / v0.Length()
}

func DistSqrPointSegment(p Point, s Segment) float64 {
	v0 := s.b.Subtract(s.a)
	v1 := p.Subtract(s.a)
	v2 := p.Subtract(s.b)
	if math.Signbit(Dot(v0, v1)) != math.Signbit(Dot(v0, v2)) {
		return 0
	} else {
		return math.Min(v1.Length(), v2.Length())
	}
}

func IsIntersect(s1, s2 Segment) bool {
	return math.Min(s1.a.x, s1.b.x) <= math.Max(s2.a.x, s2.b.x) &&
		math.Min(s2.a.x, s2.b.x) <= math.Max(s1.a.x, s1.b.x) &&
		math.Min(s1.a.y, s1.b.y) <= math.Max(s2.a.y, s2.b.y) &&
		math.Min(s2.a.y, s2.b.y) <= math.Max(s1.a.y, s1.b.y) &&
		math.Signbit(Det(s1.a, s2.a, s2.b))*math.Signbit(Det(s1.b, s2.a, s2.b)) <= 0 &&
		math.Signbit(Det(s2.a, s1.a, s1.b))*math.Signbit(Det(s2.b, s1.a, s1.b)) <= 0
}

func F(x float64, s, p Point, vp, vs, r float64) bool {
	theta := x*vp + math.Atan2(s.y, s.x) - math.Atan2(p.y, p.x)
	theta = math.Mod(theta, 2*math.Pi)
	if theta <= math.Pi/2 || theta >= 3*math.Pi/2 {
		return math.Sqrt(s.x*s.x+s.y*s.y+p.x*p.x+p.y*p.y-2*(s.x*p.x+s.y*p.y*math.Cos(theta))) <= vs*x
	} else {
		delta := math.Pi/2 - math.Abs(math.Pi/2-theta)
		return math.Sqrt(s.x*s.x+s.y*s.y+p.x*p.x+p.y*p.y-2*(s.x*p.x+s.y*p.y*math.Cos(theta))) <= vs*x+delta*r
	}
}

func main() {
	var s, p Point
	var vp, vs, r float64
	fmt.Scan(&p.x, &p.y, &vp, &s.x, &s.y, &vs, &r)

	R_ := s.Length()
	R := p.Length()
	vp /= R
	ss := math.Sqrt(R_*R_-r*r) + math.Sqrt(R*R-r*r)
	alpha := p.Atan() - s.Atan()
	beta := math.Acos(r / R_) + math.Acos(r / R)
	ll := 0.0
	rr := (ss + math.Pi*R) * vs
	for i := 0; i < 100; i++ {
		m := (ll + rr) / 2
		if F(m, s, p, vp, vs, r) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
