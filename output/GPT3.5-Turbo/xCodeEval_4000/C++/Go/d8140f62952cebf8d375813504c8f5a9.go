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

func (p Point) Add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y}
}

func (p Point) Divide(k float64) Point {
	return Point{p.x / k, p.y / k}
}

func (p Point) Equal(q Point) bool {
	return math.Abs(p.x-q.x) < 1e-9 && math.Abs(p.y-q.y) < 1e-9
}

func (p Point) String() string {
	return fmt.Sprintf("(%.10lf, %.10lf)", p.x, p.y)
}

type Line struct {
	a, b Point
}

type Seg struct {
	a, b Point
}

func NewLine(a, b Point) Line {
	return Line{a, b}
}

func NewSeg(a, b Point) Seg {
	return Seg{a, b}
}

func Dot(p, q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func Det(p, q Point) float64 {
	return p.x*q.y - p.y*q.x
}

func DistSqr(p, q Point) float64 {
	return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y)
}

func DistSqrPointLine(p Point, l Line) float64 {
	v0 := l.b.Subtract(l.a)
	v1 := p.Subtract(l.a)
	return Det(v0, v1)*Det(v0, v1) / v0.Length()
}

func DistSqrPointSeg(p Point, s Seg) float64 {
	v0 := s.b.Subtract(s.a)
	v1 := p.Subtract(s.a)
	v2 := p.Subtract(s.b)
	if Dot(v0, v1)*Dot(v0, v2) <= 0 {
		return DistSqrPointLine(p, Line{s.a, s.b})
	} else {
		return math.Min(v1.Length(), v2.Length())
	}
}

func IsIntersect(s, t Seg) bool {
	return math.Min(s.a.x, s.b.x) <= math.Max(t.a.x, t.b.x) &&
		math.Min(t.a.x, t.b.x) <= math.Max(s.a.x, s.b.x) &&
		math.Min(s.a.y, s.b.y) <= math.Max(t.a.y, t.b.y) &&
		math.Min(t.a.y, t.b.y) <= math.Max(s.a.y, s.b.y) &&
		Det(s.a, t.a, t.b)*Det(s.b, t.a, t.b) <= 0 &&
		Det(t.a, s.a, s.b)*Det(t.b, s.a, s.b) <= 0
}

func F(x float64, vp, vs, r float64, s, p Point) bool {
	theta := x*vp + math.Acos(Dot(s, p)/(s.Length()*p.Length()))
	if theta <= math.Acos(r/s.Length()) || theta >= 2*math.Pi-math.Acos(r/s.Length()) {
		return DistSqr(s, p) <= vs*x
	} else {
		delta := math.Pi - math.Acos(r/s.Length()) - math.Abs(math.Pi-theta)
		return DistSqr(s, p) <= vs*x+delta*r
	}
}

func main() {
	var vp, vs, r float64
	var s, p Point
	fmt.Scan(&p.x, &p.y, &vp, &s.x, &s.y, &vs, &r)

	R_ := s.Length()
	R := p.Length()
	vp /= R
	ss := math.Sqrt(R_*R_ - r*r) + math.Sqrt(R*R-r*r)
	alpha := p.Atan() - s.Atan()
	beta := math.Acos(r / R_) + math.Acos(r / R)

	ll := 0.0
	rr := 1e10
	for i := 0; i < 1000; i++ {
		m := (ll + rr) / 2
		if F(m, vp, vs, r, s, p) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10lf\n", ll)
}
