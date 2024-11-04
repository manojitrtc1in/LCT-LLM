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
	len := a.Length()
	if len < EPS {
		return Point{0, 0}
	}
	return Point{a.X / len, a.Y / len}
}

func Rotate(a Point, theta float64) Point {
	cosTheta := math.Cos(theta)
	sinTheta := math.Sin(theta)
	return Point{a.X*cosTheta - a.Y*sinTheta, a.X*sinTheta + a.Y*cosTheta}
}

func Mid(a, b Point) Point {
	return Point{(a.X + b.X) / 2, (a.Y + b.Y) / 2}
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
		return 0 // BOUNDRY
	}
	if lensqr < r*r {
		return 1 // IN
	}
	return 2 // OUT
}

func Id1(cen Point, r float64, p Point) (int, Point, Point) {
	state := CirclePoint(cen, r, p)
	if state != 2 {
		return state, p, p
	}
	cp := p.Sub(cen)
	h := cp.Length()
	a := math.Acos(r / h)
	cp = Normalize(cp).Mul(r)
	r1 := Rotate(cp, a).Add(cen)
	r2 := Rotate(cp, -a).Add(cen)
	return 2, r1, r2
}

func Can(t float64, st, en Point, vp, v, r, R float64) bool {
	start := st
	fin := en
	theta := t * vp / R
	fin = Rotate(fin, theta)
	a, b := Point{}, Point{}
	num := Id1(Point{0, 0}, r, start)
	if num == 0 {
		return start.Sub(fin).Length() < v*t+EPS
	}
	dis := Calc(start, fin, st, en)
	return dis < v*t+EPS
}

func Calc(st, en, a, b Point) float64 {
	// Implementation of Calc function
	return 0.0 // Placeholder
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
		if Can(m, Point{x, y}, Point{xp, yp}, vp, v, r, R) {
			ans = m
			hi = m - EPS
		} else {
			lo = m + EPS
		}
	}
	fmt.Printf("%.10f\n", ans)
}
