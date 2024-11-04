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

func (p Point) Add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y}
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

func (s Segment) Length() float64 {
	return s.b.Subtract(s.a).Length()
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

func Det3(p, q, r Point) float64 {
	return Det(p.Subtract(q), r.Subtract(q))
}

func DistSqr(p, q Point) float64 {
	return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y)
}

func DistSqrPointLine(p Point, l Line) float64 {
	v0 := l.b.Subtract(l.a)
	v1 := p.Subtract(l.a)
	return Det(v0, v1)*Det(v0, v1) / v0.Length()
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

func IsIntersect(s, t Segment) bool {
	return math.Max(s.a.x, s.b.x) >= math.Min(t.a.x, t.b.x) &&
		math.Max(t.a.x, t.b.x) >= math.Min(s.a.x, s.b.x) &&
		math.Max(s.a.y, s.b.y) >= math.Min(t.a.y, t.b.y) &&
		math.Max(t.a.y, t.b.y) >= math.Min(s.a.y, s.b.y) &&
		math.Signbit(Det3(s.a, t.a, t.b))*math.Signbit(Det3(s.b, t.a, t.b)) <= 0 &&
		math.Signbit(Det3(t.a, s.a, s.b))*math.Signbit(Det3(t.b, s.a, s.b)) <= 0
}

func Rotate(p Point, alpha float64, o Point) Point {
	p = p.Subtract(o)
	return Point{p.x*math.Cos(alpha) - p.y*math.Sin(alpha), p.y*math.Cos(alpha) + p.x*math.Sin(alpha)}.Add(o)
}

func F(x float64, s, p Point, R_, R, r, ss, vs, vp float64, alpha, beta float64) bool {
	theta := x*vp + alpha
	theta = math.Mod(theta, 2*math.Pi)
	if theta <= beta || theta >= 2*math.Pi-beta {
		return math.Sqrt(R_*R_+R*R-2*R_*R*math.Cos(theta)) <= vs*x
	} else {
		delta := math.Pi - beta - math.Abs(math.Pi-theta)
		return ss+delta*r <= vs*x
	}
}

func main() {
	var p, s Point
	var vp, vs, r float64
	fmt.Scan(&p.x, &p.y, &vp, &s.x, &s.y, &vs, &r)

	R_ := s.Length()
	R := p.Length()
	vp /= R
	ss := math.Sqrt(R_*R_-r*r) + math.Sqrt(R*R-r*r)
	alpha := p.Atan() - s.Atan()
	alpha = math.Mod(alpha, 2*math.Pi)
	beta := math.Acos(r / R_)
	ll := 0.0
	rr := (ss + math.Pi*R) * vs
	for i := 0; i < 200; i++ {
		m := (ll + rr) / 2
		if F(m, s, p, R_, R, r, ss, vs, vp, alpha, beta) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
