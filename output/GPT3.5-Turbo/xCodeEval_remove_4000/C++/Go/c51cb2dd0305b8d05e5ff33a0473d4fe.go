package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func (p point) add(q point) point {
	return point{p.X + q.X, p.Y + q.Y}
}

func (p point) sub(q point) point {
	return point{p.X - q.X, p.Y - q.Y}
}

func (p point) mul(a float64) point {
	return point{a * p.X, a * p.Y}
}

func (p point) div(a float64) point {
	return point{p.X / a, p.Y / a}
}

func (p point) length() float64 {
	return math.Sqrt(p.X*p.X + p.Y*p.Y)
}

func (p point) normalize() point {
	return p.div(p.length())
}

func (p point) rotate(theta float64) point {
	cosTheta := math.Cos(theta)
	sinTheta := math.Sin(theta)
	return point{cosTheta*p.X - sinTheta*p.Y, sinTheta*p.X + cosTheta*p.Y}
}

func cross(p, q point) float64 {
	return p.X*q.Y - p.Y*q.X
}

func dot(p, q point) float64 {
	return p.X*q.X + p.Y*q.Y
}

func intersect(a, b, p, q point) (point, bool) {
	d1 := cross(p.sub(a), b.sub(a))
	d2 := cross(q.sub(a), b.sub(a))
	if math.Abs(d1-d2) > 1e-9 {
		ret := p.mul(d1).sub(q.mul(d2)).div(d1 - d2)
		return ret, true
	}
	return point{}, false
}

func collinear(a, b, p point) bool {
	return math.Abs(cross(a.sub(b), a.sub(p))) < 1e-9
}

func id8(a, b, p point) bool {
	return math.Abs(cross(a.sub(b), a.sub(p))) < 1e-9
}

func id23(a, b, p point) bool {
	return dot(a.sub(p), b.sub(a)) > -1e-9
}

func id4(a, b, p point) bool {
	if !collinear(a, b, p) {
		return false
	}
	return id23(a, b, p) && id23(b, a, p)
}

func id14(a, b, p point) float64 {
	return math.Abs(cross(a.sub(b), a.sub(p)) / (a.sub(b)).length())
}

func id22(a, b, p point) float64 {
	if dot(a.sub(b), a.sub(p)) < 1e-9 {
		return (a.sub(p)).length()
	}
	if dot(b.sub(a), b.sub(p)) < 1e-9 {
		return (b.sub(p)).length()
	}
	return id14(a, b, p)
}

func id16(x1, y1, x2, y2 int) int {
	return int(math.Abs(float64(gcd(x1-x2, y1-y2))) + 1)
}

func id2(b, h float64) float64 {
	return b * h / 2
}

func id5(a, b, t float64) float64 {
	return math.Abs(a*b*math.Sin(t)/2)
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
	if math.Abs(res-1) < 1e-9 {
		res = 1
	}
	if math.Abs(res+1) < 1e-9 {
		res = -1
	}
	return math.Acos(res)
}

func id26(s1, s2, a1 float64) float64 {
	res := s2 * math.Sin(a1) / s1
	if math.Abs(res-1) < 1e-9 {
		res = 1
	}
	if math.Abs(res+1) < 1e-9 {
		res = -1
	}
	return math.Asin(res)
}

func id0(s1, a1, a2 float64) float64 {
	res := s1 * math.Sin(a2) / math.Sin(a1)
	return math.Abs(res)
}

func id13(p0, p1, cen point, rad float64) (point, point, int) {
	a := dot(p1.sub(p0), p1.sub(p0))
	b := 2 * dot(p1.sub(p0), p0.sub(cen))
	c := dot(p0.sub(cen), p0.sub(cen)) - rad*rad
	det := b*b - 4*a*c
	var res int
	if math.Abs(det) < 1e-9 {
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
	r1 := p0.add(p1.sub(p0).mul(t1))
	r2 := p0.add(p1.sub(p0).mul(t2))
	return r1, r2, res
}

func id3(c1 point, r1 float64, c2 point, r2 float64) (point, point, int) {
	if c1 == c2 && math.Abs(r1-r2) < 1e-9 {
		return c1, c1, 1
	}
	len := (c1.sub(c2)).length()
	if math.Abs(len-(r1+r2)) < 1e-9 || math.Abs(math.Abs(r1-r2)-len) < 1e-9 {
		var d, c point
		var r float64
		if r1 > r2 {
			d = c1.sub(c2)
			c = c1
			r = r1
		} else {
			d = c2.sub(c1)
			c = c2
			r = r2
		}
		res1 := d.normalize().mul(r).add(c)
		res2 := d.normalize().mul(-r).add(c)
		return res1, res2, 1
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return point{}, point{}, 0
	}
	a := cosRule(r2, r1, len)
	id11 := (c1.sub(c2)).normalize().mul(r1)
	res1 := id11.rotate(a).add(c1)
	res2 := id11.rotate(-a).add(c1)
	return res1, res2, 2
}

func circle2(p1, p2 point) (point, float64) {
	cen := p1.add(p2).div(2)
	r := p1.sub(p2).length() / 2
	return cen, r
}

func circle3(p1, p2, p3 point) (point, float64, bool) {
	m1 := p1.add(p2).div(2)
	m2 := p2.add(p3).div(2)
	id7 := point{-(p1.Y - p2.Y), p1.X - p2.X}
	id15 := point{-(p2.Y - p3.Y), p2.X - p3.X}
	res, ok := intersect(m1, m1.add(id7), m2, m2.add(id15))
	if !ok {
		return point{}, 0, false
	}
	r := (cen.sub(p1)).length()
	return res, r, true
}

type STATE int

const (
	IN STATE = iota
	OUT
	BOUNDRY
)

func circlePoint(cen point, r float64, p point) STATE {
	lensqr := (cen.sub(p)).length()
	if math.Abs(lensqr-r*r) < 1e-9 {
		return BOUNDRY
	}
	if lensqr < r*r {
		return IN
	}
	return OUT
}

func id1(cen point, r float64, p point) (point, point, int) {
	s := circlePoint(cen, r, p)
	if s != OUT {
		return p, p, int(s)
	}
	cp := (cen.sub(p)).normalize().mul(r)
	r1 := cp.rotate(math.Pi/2).add(cen)
	r2 := cp.rotate(-math.Pi/2).add(cen)
	return r1, r2, 2
}

type segment struct {
	p, q point
}

func id12(c1 point, r1 float64, c2 point, r2 float64) []segment {
	if r1 < r2 {
		r1, r2 = r2, r1
		c1, c2 = c2, c1
	}
	d := (c1.sub(c2)).length()
	theta := math.Acos((r1 - r2) / d)
	v := c2.sub(c1).normalize()
	v1 := v.rotate(theta)
	v2 := v.rotate(-theta)
	res := []segment{
		segment{c1.add(v1.mul(r1)), c2.add(v1.mul(r2))},
		segment{c1.add(v2.mul(r1)), c2.add(v2.mul(r2))},
	}
	theta = math.Acos((r1 + r2) / d)
	v1 = v.rotate(theta)
	v2 = v.rotate(-theta)
	res = append(res, segment{c1.add(v1.mul(r1)), c2.sub(v1.mul(r2))})
	res = append(res, segment{c1.add(v2.mul(r1)), c2.sub(v2.mul(r2))})
	return res
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
		v := p[i].sub(p[j])
		bound += abs(gcd(int(v.X), int(v.Y)))
	}
	area /= 2
	area = math.Abs(area)
	return int(math.Round(area - float64(bound)/2 + 1))
}

func polygonCut(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := cross(b.sub(a), p[i].sub(a)) > 1e-9
		in2 := cross(b.sub(a), p[j].sub(a)) > 1e-9
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			r, ok := intersect(a, b, p[i], p[j])
			if ok {
				res = append(res, r)
			}
		}
	}
	return res
}

func id25(p, q []point) []point {
	res := q
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		temp := polygonCut(res, p[i], p[j])
		res = temp
		if len(res) == 0 {
			return res
		}
	}
	return res
}

func id21(pnts, rect []point) [][]point {
	res := [][]point{}
	for i := 0; i < len(pnts); i++ {
		res = append(res, rect)
		for j := 0; j < len(pnts); j++ {
			if j == i {
				continue
			}
			p := (pnts[i].sub(pnts[j])).rotate(math.Pi / 2)
			m := pnts[i].add(pnts[j]).div(2)
			temp := polygonCut(res[len(res)-1], m, m.add(p))
			res[len(res)-1] = temp
		}
	}
	return res
}

func id24(p []point, pnt point) STATE {
	p2 := pnt.add(point{1, 0})
	cnt := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		if id4(p[i], p[j], pnt) {
			return BOUNDRY
		}
		r, ok := intersect(pnt, p2, p[i], p[j])
		if !ok {
			continue
		}
		if !id23(pnt, p2, r) {
			continue
		}
		if r == p[i] || r == p[j] {
			if math.Abs(r.Y-min(p[i].Y, p[j].Y)) < 1e-9 {
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

func (c cmp) less(p, q point) bool {
	cr := cross(c.about.sub(p), c.about.sub(q))
	if math.Abs(cr) < 1e-9 {
		return p.Y < q.Y || (p.Y == q.Y && p.X < q.X)
	}
	return cr > 0
}

func id6(pnts []point) {
	mn := point{math.Inf(1), math.Inf(1)}
	for i := 0; i < len(pnts); i++ {
		if pnts[i].less(mn) {
			mn = pnts[i]
		}
	}

	sorter := cmp{mn}
	sort.Slice(pnts, func(i, j int) bool {
		return sorter.less(pnts[i], pnts[j])
	})
}

func id17(pnts []point) []point {
	id6(pnts)
	convex := []point{}
	convex = append(convex, pnts[0])
	if len(pnts) == 1 {
		return convex
	}
	convex = append(convex, pnts[1])
	if len(pnts) == 2 {
		if pnts[0] == pnts[1] {
			convex = convex[:0]
		}
		return convex
	}
	for i := 2; i <= len(pnts); i++ {
		c := pnts[i%len(pnts)]
		for len(convex) > 1 {
			b := convex[len(convex)-1]
			a := convex[len(convex)-2]
			if cross(b.sub(a), b.sub(c)) < -1e-9 {
				break
			}
			convex = convex[:len(convex)-1]
		}
		if i < len(pnts) {
			convex = append(convex, pnts[i])
		}
	}
	return convex
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func calcArc(a, b point) float64 {
	theta := math.Abs(b.angle() - a.angle())
	if theta > math.Pi {
		theta = 2*math.Pi - theta
	}
	res := theta * r
	return res
}

func calcDis(a, c point) float64 {
	arc := calcArc(a, c)
	res := arc + math.Abs((a.sub(st)).length()) + math.Abs((c.sub(en)).length())
	return res
}

var xp, yp, vp, x, y, v, r, R float64
var pi = math.Acos(-1)
var st, en point

func Calc(st, en point) float64 {
	a, b, c, d, res := point{}, point{}, point{}, point{}, 0.0
	id1(point{0, 0}, r, st, &a, &b)
	id1(point{0, 0}, r, en, &c, &d)
	res = calcDis(a, c)
	res = math.Min(res, calcDis(a, d))
	res = math.Min(res, calcDis(b, c))
	res = math.Min(res, calcDis(b, d))
	return res
}

func can(t float64) bool {
	start := st
	fin := en
	theta := t * vp / R
	fin = en.rotate(theta)
	var a, b point
	intersection := false
	num := id13(start, fin, point{0, 0}, r, &a, &b)
	if num > 0 {
		if id4(start, fin, a) {
			intersection = true
		}
		if num == 2 && id4(start, fin, b) {
			intersection = true
		}
	}
	if num <= 1 || !intersection {
		return (start.sub(fin)).length() < v*t+1e-9
	}
	dis := Calc(st, fin)
	return dis < v*t+1e-9
}

func main() {
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R = point{xp, yp}.length()
	ans, hi, lo := 10000000.0, 1000000.0, 0.0
	for iter := 0; iter < 100; iter++ {
		m := lo + (hi-lo)/2.0
		if can(m) {
			ans, hi = m, m-1e-9
		} else {
			lo = m + 1e-9
		}
	}
	fmt.Printf("%.10f\n", ans)
}
