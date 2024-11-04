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

func (p Point) Sub(q Point) Point {
	return Point{p.X - q.X, p.Y - q.Y}
}

func (p Point) Add(q Point) Point {
	return Point{p.X + q.X, p.Y + q.Y}
}

func (p Point) Mul(s float64) Point {
	return Point{p.X * s, p.Y * s}
}

func (p Point) Length() float64 {
	return math.Sqrt(p.X*p.X + p.Y*p.Y)
}

func (p Point) LengthSqr() float64 {
	return p.X*p.X + p.Y*p.Y
}

func Cross(p, q Point) float64 {
	return p.X*q.Y - p.Y*q.X
}

func Dot(p, q Point) float64 {
	return p.X*q.X + p.Y*q.Y
}

func Normalize(p Point) Point {
	l := p.Length()
	if l < EPS {
		return Point{0, 0}
	}
	return Point{p.X / l, p.Y / l}
}

func Rotate(p Point, angle float64) Point {
	cosA := math.Cos(angle)
	sinA := math.Sin(angle)
	return Point{p.X*cosA - p.Y*sinA, p.X*sinA + p.Y*cosA}
}

func Mid(p, q Point) Point {
	return Point{(p.X + q.X) / 2, (p.Y + q.Y) / 2}
}

func Perp(p Point) Point {
	return Point{-p.Y, p.X}
}

func Intersect(a, b, p, q Point) (bool, Point) {
	d1 := Cross(p.Sub(a), b.Sub(a))
	d2 := Cross(q.Sub(a), b.Sub(a))
	if math.Abs(d1-d2) < EPS {
		return false, Point{}
	}
	ret := Point{(d1*q.X - d2*p.X) / (d1 - d2), (d1*q.Y - d2*p.Y) / (d1 - d2)}
	return true, ret
}

func CirclePoint(cen Point, r float64, p Point) int {
	lensqr := p.Sub(cen).LengthSqr()
	if math.Abs(lensqr-r*r) < EPS {
		return 2 // BOUNDRY
	}
	if lensqr < r*r {
		return 0 // IN
	}
	return 1 // OUT
}

func Can(t float64, st, en Point, r, vp, v float64) bool {
	start := st
	fin := Rotate(en, t*vp/r)
	intersection := false
	num := 0 // Placeholder for intersection count
	var a, b Point

	// Placeholder for intersection logic
	if num <= 1 || !intersection {
		return start.Sub(fin).Length() < v*t+EPS
	}
	dis := Calc(start, fin, r)
	return dis < v*t+EPS
}

func Calc(st, en Point, r float64) float64 {
	a, b, c, d := Point{}, Point{}, Point{}, Point{}
	// Placeholder for id1 logic
	res := CalcDis(a, c, st, en)
	res = math.Min(res, CalcDis(a, d, st, en))
	res = math.Min(res, CalcDis(b, c, st, en))
	res = math.Min(res, CalcDis(b, d, st, en))
	return res
}

func CalcDis(a, c, st, en Point) float64 {
	arc := CalcArc(a, c)
	return arc + math.Abs(st.Sub(a).Length()) + math.Abs(en.Sub(c).Length())
}

func CalcArc(a, c Point) float64 {
	theta := math.Abs(math.Atan2(c.Y, c.X) - math.Atan2(a.Y, a.X))
	if theta > math.Pi {
		theta = 2*math.Pi - theta
	}
	return theta * r
}

func main() {
	var xp, yp, vp, x, y, v, r float64
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)

	R := Point{xp, yp}.Length()
	ans := 1e7
	hi := 1e6
	lo := 0.0

	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if Can(m, Point{x, y}, Point{xp, yp}, r, vp, v) {
			ans = m
			hi = m - EPS
		} else {
			lo = m + EPS
		}
	}
	fmt.Printf("%.10f\n", ans)
}
