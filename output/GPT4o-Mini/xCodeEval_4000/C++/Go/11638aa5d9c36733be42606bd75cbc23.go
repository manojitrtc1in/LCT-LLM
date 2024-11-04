package main

import (
	"fmt"
	"math"
	"math/cmplx"
	"sort"
)

type Point complex128

const (
	EPS = 1e-7
	OO  = 1e9
)

func (p Point) X() float64 {
	return real(p)
}

func (p Point) Y() float64 {
	return imag(p)
}

func vec(a, b Point) Point {
	return b - a
}

func length(v Point) float64 {
	return cmplx.Abs(complex(v.X(), v.Y()))
}

func cross(a, b Point) float64 {
	return real(conj(a) * b)
}

func dot(a, b Point) float64 {
	return real(conj(a) * b)
}

func same(a, b Point) bool {
	return length(vec(a, b)) < EPS
}

func intersect(a, b, p, q Point) (Point, bool) {
	d1 := cross(p-a, b-a)
	d2 := cross(q-a, b-a)
	if math.Abs(d1-d2) > EPS {
		return (d1*q - d2*p) / (d1 - d2), true
	}
	return Point(0), false
}

func pointOnSegment(a, b, p Point) bool {
	return same(vec(a, b), vec(a, p)) && dot(vec(a, p), vec(a, b)) > -EPS && dot(vec(b, a), vec(b, p)) > -EPS
}

func circleLineIntersection(p0, p1, cen Point, rad float64) (Point, Point, int) {
	a := dot(p1-p0, p1-p0)
	b := 2 * dot(p1-p0, p0-cen)
	c := dot(p0-cen, p0-cen) - rad*rad
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
	r1 := p0 + t1*(p1-p0)
	r2 := p0 + t2*(p1-p0)
	return r1, r2, res
}

func tangentPoints(cen Point, r float64, p Point) (Point, Point, int) {
	cp := vec(cen, p)
	h := length(cp)
	if h < r {
		return p, p, 0
	}
	a := math.Acos(r / h)
	cp = cp / complex(h, 0) * complex(r, 0)
	r1 := rotate(cp, a) + cen
	r2 := rotate(cp, -a) + cen
	return r1, r2, 2
}

func rotate(v Point, theta float64) Point {
	return Point(complex(real(v)*math.Cos(theta)-imag(v)*math.Sin(theta), real(v)*math.Sin(theta)+imag(v)*math.Cos(theta)))
}

func can(t float64, st, en Point, vp, v, r float64) bool {
	theta := t * vp / r
	fin := rotate(en, theta)
	a, b, num := circleLineIntersection(st, fin, Point(0, 0), r)
	intersection := false
	if num > 0 {
		if pointOnSegment(st, fin, a) {
			intersection = true
		}
		if num == 2 && pointOnSegment(st, fin, b) {
			intersection = true
		}
	}
	if num <= 1 || !intersection {
		return length(vec(st, fin)) < v*t+EPS
	}
	return false // Placeholder for distance calculation
}

func main() {
	var xp, yp, vp, x, y, v, r float64
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R := length(Point(xp, yp))
	ans := 1e7
	hi := 1e6
	lo := 0.0

	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if can(m, Point(x, y), Point(xp, yp), vp, v, r) {
			ans = m
			hi = m
		} else {
			lo = m
		}
	}
	fmt.Printf("%.10f\n", ans)
}
