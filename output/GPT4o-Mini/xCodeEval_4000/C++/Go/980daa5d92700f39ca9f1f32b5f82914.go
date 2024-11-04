package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	X, Y float64
}

const EPS = 1e-8
const OO = 1e9

func (p Point) Length() float64 {
	return math.Hypot(p.X, p.Y)
}

func (p Point) Vec(b Point) Point {
	return Point{b.X - p.X, b.Y - p.Y}
}

func (p Point) Cross(b Point) float64 {
	return p.X*b.Y - p.Y*b.X
}

func (p Point) Dot(b Point) float64 {
	return p.X*b.X + p.Y*b.Y
}

func (p Point) Rotate(theta float64) Point {
	return Point{
		X: p.X*math.Cos(theta) - p.Y*math.Sin(theta),
		Y: p.X*math.Sin(theta) + p.Y*math.Cos(theta),
	}
}

func (p Point) Normalize() Point {
	length := p.Length()
	if length < EPS {
		return Point{0, 0}
	}
	return Point{p.X / length, p.Y / length}
}

func CircleLineIntersection(p0, p1, cen Point, rad float64) (int, Point, Point) {
	a := p1.Vec(p0).Dot(p1.Vec(p0))
	b := 2 * p1.Vec(p0).Dot(p0.Vec(cen))
	c := p0.Vec(cen).Dot(p0.Vec(cen)) - rad*rad
	det := b*b - 4*a*c
	var res int
	if math.Abs(det) < EPS {
		det = 0
		res = 1
	} else if det < 0 {
		res = 0
	} else {
		res = 2
	}
	det = math.Sqrt(det)
	t1 := (-b + det) / (2 * a)
	t2 := (-b - det) / (2 * a)
	r1 := Point{p0.X + t1*(p1.X-p0.X), p0.Y + t1*(p1.Y-p0.Y)}
	r2 := Point{p0.X + t2*(p1.X-p0.X), p0.Y + t2*(p1.Y-p0.Y)}
	return res, r1, r2
}

func TangentPoints(cen Point, r float64, p Point) (int, Point, Point) {
	cp := cen.Vec(p)
	h := cp.Length()
	if h < r {
		return 0, p, p
	}
	a := math.Acos(r / h)
	cp = cp.Normalize()
	r1 := cp.Rotate(a).Add(cen)
	r2 := cp.Rotate(-a).Add(cen)
	return 2, r1, r2
}

func (p Point) Add(b Point) Point {
	return Point{p.X + b.X, p.Y + b.Y}
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
	return arc + math.Abs(st.Vec(a).Length()) + math.Abs(en.Vec(c).Length())
}

func Can(t float64, st, en Point, vp, v, r float64) bool {
	theta := t * vp / r
	fin := en.Rotate(theta)
	num, a, b := CircleLineIntersection(st, fin, Point{0, 0}, r)
	if num <= 1 {
		return st.Vec(fin).Length() < v*t+EPS
	}
	dis := CalcDis(st, fin, st, fin, r)
	return dis < v*t+EPS
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
		if Can(m, Point{x, y}, Point{xp, yp}, vp, v, r) {
			ans = m
			hi = m - EPS
		} else {
			lo = m + EPS
		}
	}
	fmt.Printf("%.10f\n", ans)
}
