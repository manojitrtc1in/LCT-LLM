package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func cross(a, b point) float64 {
	return a.X*b.Y - a.Y*b.X
}

func vec(a, b point) point {
	return point{b.X - a.X, b.Y - a.Y}
}

func rotate(v point, t float64) point {
	cosT := math.Cos(t)
	sinT := math.Sin(t)
	return point{v.X*cosT - v.Y*sinT, v.X*sinT + v.Y*cosT}
}

func length(v point) float64 {
	return math.Hypot(v.X, v.Y)
}

func circleLineIntersection(p0, p1, cen point, rad float64) (point, point, int) {
	a := dot(vec(p1, p0), vec(p1, p0))
	b := 2 * dot(vec(p1, p0), vec(p0, cen))
	c := dot(vec(p0, cen), vec(p0, cen)) - rad*rad
	det := b*b - 4*a*c
	if math.Abs(det) < 1e-7 {
		det = 0
		return point{}, point{}, 1
	} else if det < 0 {
		return point{}, point{}, 0
	} else {
		det = math.Sqrt(det)
		t1 := (-b + det) / (2 * a)
		t2 := (-b - det) / (2 * a)
		r1 := point{p0.X + t1*(p1.X-p0.X), p0.Y + t1*(p1.Y-p0.Y)}
		r2 := point{p0.X + t2*(p1.X-p0.X), p0.Y + t2*(p1.Y-p0.Y)}
		return r1, r2, 2
	}
}

func pointOnSegment(a, b, p point) bool {
	return pointOnRay(a, b, p) && pointOnRay(b, a, p)
}

func pointOnRay(a, b, p point) bool {
	return dot(vec(a, p), vec(a, b)) > -1e-7
}

func dot(a, b point) float64 {
	return a.X*b.X + a.Y*b.Y
}

func normalize(p point) point {
	l := length(p)
	return point{p.X / l, p.Y / l}
}

func same(a, b point) bool {
	return lengthSqr(vec(a, b)) < 1e-7
}

func lengthSqr(v point) float64 {
	return dot(v, v)
}

func Calc(st, en point) float64 {
	var a, b, c, d point
	tangentPoints(point{0, 0}, r, st, &a, &b)
	tangentPoints(point{0, 0}, r, en, &c, &d)
	res := calcDis(a, c)
	res = math.Min(res, calcDis(a, d))
	res = math.Min(res, calcDis(b, c))
	res = math.Min(res, calcDis(b, d))
	return res
}

func calcDis(a, c point) float64 {
	arc := calcArc(a, c)
	res := arc + math.Abs(length(vec(a, st))) + math.Abs(length(vec(c, en)))
	return res
}

func calcArc(a, b point) float64 {
	theta := math.Abs(angle(b) - angle(a))
	if theta > math.Pi {
		theta = 2*math.Pi - theta
	}
	res := theta * r
	return res
}

func angle(v point) float64 {
	return math.Atan2(v.Y, v.X)
}

func can(t float64) bool {
	start := st
	fin := en
	theta := t * vp / R
	fin = rotate(fin, theta)
	var a, b point
	intersection := false
	num, _ := circleLineIntersection(start, fin, point{0, 0}, r)
	if num > 0 {
		if pointOnSegment(start, fin, a) {
			intersection = true
		}
		if num == 2 && pointOnSegment(start, fin, b) {
			intersection = true
		}
	}
	if num <= 1 || !intersection {
		return length(vec(start, fin)) < v*t+1e-7
	}
	dis := Calc(st, fin)
	return dis < v*t+1e-7
}

func main() {
	var xp, yp, vp, x, y, v, r, R float64
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R = length(point{xp, yp})
	ans := 10000000.0
	hi := 1000000.0
	lo := 0.0
	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if can(m) {
			ans = m
			hi = m
		} else {
			lo = m
		}
	}
	fmt.Printf("%.10f\n", ans)
}
