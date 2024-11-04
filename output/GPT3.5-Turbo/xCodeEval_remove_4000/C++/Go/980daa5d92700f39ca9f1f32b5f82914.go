package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func operatorMul(a float64, b point) point {
	return point{a * b.X, a * b.Y}
}

func operatorMul2(b point, a float64) point {
	return point{a * b.X, a * b.Y}
}

type STATE int

const (
	IN STATE = iota
	OUT
	BOUNDRY
)

func intersect(a, b, p, q, ret point) bool {
	d1 := cross(sub(p, a), sub(b, a))
	d2 := cross(sub(q, a), sub(b, a))
	ret = div(sub(mul(d1, q), mul(d2, p)), d1-d2)
	if math.Abs(d1-d2) > EPS {
		return true
	}
	return false
}

func id8(a, b, p point) bool {
	return math.Abs(cross(vec(a, b), vec(a, p))) < EPS
}

func id23(a, b, p point) bool {
	return dot(vec(a, p), vec(a, b)) > -EPS
}

func id4(a, b, p point) bool {
	if !colliner(a, b, p) {
		return false
	}
	return id23(a, b, p) && id23(b, a, p)
}

func id14(a, b, p point) float64 {
	return math.Abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)))
}

func id22(a, b, p point) float64 {
	if dot(vec(a, b), vec(a, p)) < EPS {
		return length(vec(a, p))
	}
	if dot(vec(b, a), vec(b, p)) < EPS {
		return length(vec(b, p))
	}
	return id14(a, b, p)
}

func id16(x1, y1, x2, y2 int) int {
	return abs(gcd(x1-x2, y1-y2)) + 1
}

func id2(b, h float64) float64 {
	return b * h / 2
}

func id5(a, b, t float64) float64 {
	return math.Abs(a * b * math.Sin(t) / 2)
}

func id19(t1, t2, s float64) float64 {
	return math.Abs(s*s*math.Sin(t1)*math.Sin(t2)/(2*math.Sin(t1+t2)))
}

func id20(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func id10(a, b, c point) float64 {
	return math.Abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2
}

func id18(a, b int) int {
	return a - b/2 + 1
}

func cosRule(a, b, c float64) float64 {
	res := (b*b + c*c - a*a) / (2 * b * c)
	if math.Abs(res-1) < EPS {
		res = 1
	}
	if math.Abs(res+1) < EPS {
		res = -1
	}
	return math.Acos(res)
}

func id26(s1, s2, a1 float64) float64 {
	res := s2 * math.Sin(a1) / s1
	if math.Abs(res-1) < EPS {
		res = 1
	}
	if math.Abs(res+1) < EPS {
		res = -1
	}
	return math.Asin(res)
}

func id0(s1, a1, a2 float64) float64 {
	res := s1 * math.Sin(a2) / math.Sin(a1)
	return math.Abs(res)
}

func id13(p0, p1, cen point, rad float64, r1, r2 point) int {
	a := dot(sub(p1, p0), sub(p1, p0))
	b := 2 * dot(sub(p1, p0), sub(p0, cen))
	c := dot(sub(p0, cen), sub(p0, cen)) - rad*rad
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
	r1 = add(p0, mul(t1, sub(p1, p0)))
	r2 = add(p0, mul(t2, sub(p1, p0)))
	return res
}

func id3(c1 point, r1 float64, c2 point, r2 float64, res1, res2 point) int {
	if same(c1, c2) && math.Abs(r1-r2) < EPS {
		res1 = c1
		res2 = c2
		return 1
	}
	len := length(vec(c1, c2))
	if math.Abs(len-(r1+r2)) < EPS || math.Abs(math.Abs(r1-r2)-len) < EPS {
		var d, c point
		var r float64
		if r1 > r2 {
			d = vec(c1, c2)
			c = c1
			r = r1
		} else {
			d = vec(c2, c1)
			c = c2
			r = r2
		}
		res1 = add(mul(normalize(d), r), c)
		res2 = add(mul(normalize(d), -r), c)
		return 1
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return 0
	}
	a := cosRule(r2, r1, len)
	id11 := mul(normalize(vec(c1, c2)), r1)
	res1 = add(rotate(id11, a), c1)
	res2 = add(rotate(id11, -a), c1)
	return 2
}

func circle2(p1, p2 point, cen *point, r *float64) {
	*cen = mid(p1, p2)
	*r = length(vec(p1, p2)) / 2
}

func circle3(p1, p2, p3 point, cen *point, r *float64) bool {
	m1 := mid(p1, p2)
	m2 := mid(p2, p3)
	id7 := perp(vec(p1, p2))
	id15 := perp(vec(p2, p3))
	res := intersect(m1, add(m1, id7), m2, add(m2, id15), *cen)
	*r = length(vec(*cen, p1))
	return res
}

func circlePoint(cen point, r float64, p point) STATE {
	lensqr := lengthSqr(vec(cen, p))
	if math.Abs(lensqr-r*r) < EPS {
		return BOUNDRY
	}
	if lensqr < r*r {
		return IN
	}
	return OUT
}

func id1(cen point, r float64, p point, r1, r2 point) int {
	s := circlePoint(cen, r, p)
	if s != OUT {
		r1 = p
		r2 = p
		if s == BOUNDRY {
			return 1
		}
	}
	cp := vec(cen, p)
	h := length(cp)
	a := math.Acos(r / h)
	cp = mul(normalize(cp), r)
	r1 = add(rotate(cp, a), cen)
	r2 = add(rotate(cp, -a), cen)
	return 2
}

type segment struct {
	p1, p2 point
}

func id12(c1 point, r1 float64, c2 point, r2 float64, res []segment) {
	if r1 < r2 {
		r1, r2 = r2, r1
		c1, c2 = c2, c1
	}
	d := length(sub(c1, c2))
	theta := math.Acos((r1 - r2) / d)
	v := sub(c2, c1)
	v = div(v, hypot(v.Y, v.X))
	v1 := mul(exp(point{0, theta}), v)
	v2 := mul(exp(point{0, -theta}), v)
	res = make([]segment, 0)
	res = append(res, segment{add(c1, mul(v1, r1)), add(c2, mul(v1, r2))})
	res = append(res, segment{add(c1, mul(v2, r1)), add(c2, mul(v2, r2))})
	theta = math.Acos((r1 + r2) / d)
	v1 = mul(exp(point{0, theta}), v)
	v2 = mul(exp(point{0, -theta}), v)
	res = append(res, segment{add(c1, mul(v1, r1)), sub(c2, mul(v1, r2))})
	res = append(res, segment{add(c1, mul(v2, r1)), sub(c2, mul(v2, r2))})
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += cross(p[i], p[j])
	}
	return math.Abs(res) / 2
}

func id9(polygon []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(polygon); i++ {
		j := (i + 1) % len(polygon)

		x += (polygon[i].X + polygon[j].X) * (polygon[i].X*polygon[j].Y - polygon[j].X*polygon[i].Y)

		y += (polygon[i].Y + polygon[j].Y) * (polygon[i].X*polygon[j].Y - polygon[j].X*polygon[i].Y)

		a += polygon[i].X*polygon[j].Y - polygon[i].Y*polygon[j].X
	}

	a *= 0.5
	x /= 6 * a
	y /= 6 * a

	return point{x, y}
}

func id18(p []point) int {
	area := 0.0
	bound := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		area += cross(p[i], p[j])
		v := vec(p[i], p[j])
		bound += abs(gcd(int(v.X), int(v.Y)))
	}
	area /= 2
	area = math.Abs(area)
	return round(area - float64(bound)/2 + 1)
}

func polygonCut(p []point, a, b point, res []point) {
	res = make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := cross(vec(a, b), vec(a, p[i])) > EPS
		in2 := cross(vec(a, b), vec(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], r)
			res = append(res, r)
		}
	}
}

func id25(p, q []point, res []point) {
	res = q
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		temp := make([]point, 0)
		polygonCut(res, p[i], p[j], temp)
		res = temp
		if len(res) == 0 {
			return
		}
	}
}

func id21(pnts, rect []point, res [][]point) {
	res = make([][]point, 0)
	for i := 0; i < len(pnts); i++ {
		res = append(res, rect)
		for j := 0; j < len(pnts); j++ {
			if j == i {
				continue
			}
			p := perp(vec(pnts[i], pnts[j]))
			m := mid(pnts[i], pnts[j])
			temp := make([]point, 0)
			polygonCut(res[len(res)-1], m, add(m, p), temp)
			res[len(res)-1] = temp
		}
	}
}

func id24(p []point, pnt point) STATE {
	p2 := add(pnt, point{1, 0})
	cnt := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		if id4(p[i], p[j], pnt) {
			return BOUNDRY
		}
		var r point
		if !intersect(pnt, p2, p[i], p[j], r) {
			continue
		}
		if !id23(pnt, p2, r) {
			continue
		}
		if same(r, p[i]) || same(r, p[j]) {
			if math.Abs(r.Y-min(p[i].Y, p[j].Y)) < EPS {
				continue
			}
		}
		if !id4(p[i], p[j], r) {
			continue
		}
		cnt++
	}
	if cnt&1 == 1 {
		return IN
	}
	return OUT
}

type cmp struct {
	about point
}

func (c cmp) compare(p, q point) bool {
	cr := cross(vec(c.about, p), vec(c.about, q))
	if math.Abs(cr) < EPS {
		return makePair(p.Y, p.X) < makePair(q.Y, q.X)
	}
	return cr > 0
}

func id6(pnts []point) {
	mn := point{1 / 0.0, 1 / 0.0}
	for i := 0; i < len(pnts); i++ {
		if makePair(pnts[i].Y, pnts[i].X) < makePair(mn.Y, mn.X) {
			mn = pnts[i]
		}
	}

	sort(pnts, cmp{mn})
}

func id17(pnts []point, convex []point) {
	id6(pnts)
	convex = make([]point, 0)
	convex = append(convex, pnts[0])
	if len(pnts) == 1 {
		return
	}
	convex = append(convex, pnts[1])
	if len(pnts) == 2 {
		if same(pnts[0], pnts[1]) {
			convex = convex[:len(convex)-1]
		}
		return
	}
	for i := 2; i <= len(pnts); i++ {
		c := pnts[i%len(pnts)]
		for len(convex) > 1 {
			b := convex[len(convex)-1]
			a := convex[len(convex)-2]
			if cross(vec(b, a), vec(b, c)) < -EPS {
				break
			}
			convex = convex[:len(convex)-1]
		}
		if i < len(pnts) {
			convex = append(convex, pnts[i])
		}
	}
}

func xp, yp, vp, x, y, v, r, R float64
var pi = math.Acos(-1)
var st, en point

func calcArc(a, b point) float64 {
	theta := math.Abs(angle(b) - angle(a))
	if theta > pi {
		theta = 2*pi - theta
	}
	res := theta * r
	return res
}

func calcDis(a, c point) float64 {
	arc := calcArc(a, c)
	res := arc + math.Abs(length(vec(a, st))) + math.Abs(length(vec(c, en)))
	return res
}

func Calc(st, en point) float64 {
	var a, b, c, d point
	id1(point{0, 0}, r, st, a, b)
	id1(point{0, 0}, r, en, c, d)
	res := calcDis(a, c)
	res = math.Min(res, calcDis(a, d))
	res = math.Min(res, calcDis(b, c))
	res = math.Min(res, calcDis(b, d))
	return res
}

func can(t float64) bool {
	start := st
	st = point{x, y}
	fin := en
	en = point{xp, yp}
	theta := t * vp / R
	fin = en
	en = rotate(fin, theta)
	var a, b point
	intersection := false
	num := id13(start, fin, point{0, 0}, r, a, b)
	if num > 0 {
		if id4(start, fin, a) {
			intersection = true
		}
		if num == 2 && id4(start, fin, b) {
			intersection = true
		}
	}
	if num <= 1 || !intersection {
		return length(vec(start, fin)) < v*t+EPS
	}
	dis := Calc(st, fin)
	return dis < v*t+EPS
}

func main() {
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R = length(point{xp, yp})
	ans := 10000000.0
	hi, lo := 1000000.0, 0.0
	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if can(m) {
			ans = m
			hi = m - EPS
		} else {
			lo = m + EPS
		}
	}
	fmt.Printf("%.10f\n", ans)
}
