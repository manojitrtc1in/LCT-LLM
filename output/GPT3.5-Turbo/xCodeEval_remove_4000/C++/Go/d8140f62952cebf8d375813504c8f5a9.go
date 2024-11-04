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

func (p Point) String() string {
	return fmt.Sprintf("(%.10lf, %.10lf)", p.x, p.y)
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

func (l Line) String() string {
	return fmt.Sprintf("%v-%v", l.a, l.b)
}

func (s Segment) String() string {
	return fmt.Sprintf("%v-%v", s.a, s.b)
}

func Dot(x1, y1, x2, y2 float64) float64 {
	return x1*x2 + y1*y2
}

func DotPoints(a, b Point) float64 {
	return Dot(a.x, a.y, b.x, b.y)
}

func DotLine(l1, l2 Line) float64 {
	return DotPoints(l1.b.Subtract(l1.a), l2.b.Subtract(l2.a))
}

func Det(x1, y1, x2, y2 float64) float64 {
	return x1*y2 - x2*y1
}

func DetPoints(a, b Point) float64 {
	return Det(a.x, a.y, b.x, b.y)
}

func DetLine(l1, l2 Line) float64 {
	return DetPoints(l1.b.Subtract(l1.a), l2.b.Subtract(l2.a))
}

func IsIntersect(l1, l2 Segment) bool {
	return math.Min(l1.a.x, l1.b.x) <= math.Max(l2.a.x, l2.b.x) &&
		math.Min(l2.a.x, l2.b.x) <= math.Max(l1.a.x, l1.b.x) &&
		math.Min(l1.a.y, l1.b.y) <= math.Max(l2.a.y, l2.b.y) &&
		math.Min(l2.a.y, l2.b.y) <= math.Max(l1.a.y, l1.b.y) &&
		DetPoints(l1.a, l2.a, l2.b)*DetPoints(l1.b, l2.a, l2.b) <= 0 &&
		DetPoints(l2.a, l1.a, l1.b)*DetPoints(l2.b, l1.a, l1.b) <= 0
}

func Id1(p Point, l Segment) float64 {
	v0 := l.b.Subtract(l.a)
	v1 := p.Subtract(l.a)
	v2 := p.Subtract(l.b)
	if math.Signbit(DotPoints(v0, v1))*math.Signbit(DotPoints(v0, v2)) <= 0 {
		return 0
	} else {
		return math.Min(v1.Length()*v1.Length(), v2.Length()*v2.Length())
	}
}

func Id1Line(l1 Line, l2 Line) float64 {
	if IsIntersect(Segment{l1.a, l1.b}, Segment{l2.a, l2.b}) {
		return 0
	} else {
		return math.Min(Id1(l1.a, Segment{l2.a, l2.b}), Id1(l1.b, Segment{l2.a, l2.b}))
	}
}

func Id1Segment(l1, l2 Segment) float64 {
	if IsIntersect(l1, l2) {
		return 0
	} else {
		return math.Min(Id1(l1.a, l2), Id1(l1.b, l2))
	}
}

func Rand32() int {
	return (bool(Rand()&1) << 30) | (Rand() << 15) + Rand()
}

func Random32(l, r int) int {
	return Rand32()%(r-l+1) + l
}

func Random(l, r int) int {
	return Rand()%(r-l+1) + l
}

func Dice() int {
	return Rand() % 6
}

func Coin() bool {
	return Rand()%2 == 0
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
	beta := math.Acos(r/R_) + math.Acos(r/R)

	ll := 0.0
	rr := 1e10
	for i := 0; i < 1000; i++ {
		m := (ll + rr) / 2
		if f(m) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Println(ll)
}

func f(x float64) bool {
	theta := x*vp + alpha
	theta = math.Mod(theta, 2*math.Pi)
	return d() <= vs*x
}

func d() float64 {
	if theta <= beta || theta >= 2*math.Pi-beta {
		return math.Sqrt(R_*R_ + R*R - 2*R_*R*math.Cos(theta))
	} else {
		delta := math.Pi - beta - math.Abs(math.Pi-theta)
		return ss + delta*r
	}
}
