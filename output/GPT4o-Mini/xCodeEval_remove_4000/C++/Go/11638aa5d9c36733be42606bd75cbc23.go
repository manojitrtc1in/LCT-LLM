package main

import (
	"fmt"
	"math"
	"sort"
)

const EPS = 1e-9

type Point struct {
	X, Y float64
}

func (a Point) Sub(b Point) Point {
	return Point{a.X - b.X, a.Y - b.Y}
}

func (a Point) Add(b Point) Point {
	return Point{a.X + b.X, a.Y + b.Y}
}

func (a Point) Mul(scalar float64) Point {
	return Point{a.X * scalar, a.Y * scalar}
}

func (a Point) Length() float64 {
	return math.Sqrt(a.X*a.X + a.Y*a.Y)
}

func (a Point) LengthSqr() float64 {
	return a.X*a.X + a.Y*a.Y
}

func Cross(a, b Point) float64 {
	return a.X*b.Y - a.Y*b.X
}

func Dot(a, b Point) float64 {
	return a.X*b.X + a.Y*b.Y
}

func Normalize(a Point) Point {
	length := a.Length()
	if length < EPS {
		return Point{0, 0}
	}
	return Point{a.X / length, a.Y / length}
}

func Rotate(p Point, angle float64) Point {
	cosTheta := math.Cos(angle)
	sinTheta := math.Sin(angle)
	return Point{p.X*cosTheta - p.Y*sinTheta, p.X*sinTheta + p.Y*cosTheta}
}

func Mid(a, b Point) Point {
	return Point{(a.X + b.X) / 2, (a.Y + b.Y) / 2}
}

func Perp(a Point) Point {
	return Point{-a.Y, a.X}
}

func Intersect(a, b, p, q Point) (Point, bool) {
	d1 := Cross(p.Sub(a), b.Sub(a))
	d2 := Cross(q.Sub(a), b.Sub(a))
	if math.Abs(d1-d2) < EPS {
		return Point{}, false
	}
	ret := Point{(d1*q.X - d2*p.X) / (d1 - d2), (d1*q.Y - d2*p.Y) / (d1 - d2)}
	return ret, true
}

func CirclePoint(cen Point, r float64, p Point) int {
	lensqr := p.Sub(cen).LengthSqr()
	if math.Abs(lensqr-r*r) < EPS {
		return 0 // BOUNDRY
	}
	if lensqr < r*r {
		return 1 // IN
	}
	return 2 // OUT
}

func Id1(cen Point, r float64, p Point) (Point, Point, int) {
	s := CirclePoint(cen, r, p)
	if s != 2 {
		return p, p, s
	}
	cp := cen.Sub(p)
	h := cp.Length()
	a := math.Acos(r / h)
	cp = Normalize(cp).Mul(r)
	r1 := Rotate(cp, a).Add(cen)
	r2 := Rotate(cp, -a).Add(cen)
	return r1, r2, 2
}

func CalcArc(a, b Point, r float64) float64 {
	theta := math.Abs(math.Atan2(b.Y, b.X) - math.Atan2(a.Y, a.X))
	if theta > math.Pi {
		theta = 2*math.Pi - theta
	}
	return theta * r
}

func CalcDis(a, c, st, en Point, r float64) float64 {
	arc := CalcArc(a, c, r)
	return arc + math.Abs(st.Sub(a).Length()) + math.Abs(en.Sub(c).Length())
}

func Can(t float64, st, en Point, vp, v, r float64) bool {
	start := st
	fin := en
	theta := t * vp / r
	fin = Rotate(fin, theta)
	a, b, num := Id1(Point{0, 0}, r, start)
	intersection := false
	if num > 0 {
		if Cross(start.Sub(fin), a.Sub(start)) > EPS {
			intersection = true
		}
		if num == 2 && Cross(start.Sub(fin), b.Sub(start)) > EPS {
			intersection = true
		}
	}
	if num <= 1 || !intersection {
		return start.Sub(fin).Length() < v*t+EPS
	}
	dis := CalcDis(start, fin, st, en, r)
	return dis < v*t+EPS
}

func main() {
	var xp, yp, vp, x, y, v, r float64
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)

	R := math.Sqrt(xp*xp + yp*yp)
	ans := 1e7
	hi := 1e6
	lo := 0.0

	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if Can(m, Point{x, y}, Point{xp, yp}, vp, v, r) {
			ans = m
			hi = m
		} else {
			lo = m
		}
	}

	fmt.Printf("%.10f\n", ans)
}
