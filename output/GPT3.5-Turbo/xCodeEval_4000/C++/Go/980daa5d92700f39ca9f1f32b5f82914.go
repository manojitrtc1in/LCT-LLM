package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func complexPoint(x, y float64) point {
	return point{x, y}
}

func (p point) real() float64 {
	return p.X
}

func (p point) imag() float64 {
	return p.Y
}

func (p point) length() float64 {
	return math.Hypot(p.Y, p.X)
}

func (p point) normalize() point {
	l := p.length()
	return point{p.X / l, p.Y / l}
}

func (p point) rotate(t float64) point {
	cosT := math.Cos(t)
	sinT := math.Sin(t)
	return point{p.X*cosT - p.Y*sinT, p.X*sinT + p.Y*cosT}
}

func (p point) rotateAbout(t float64, a point) point {
	v := point{p.X - a.X, p.Y - a.Y}
	return v.rotate(t).add(a)
}

func (p point) add(q point) point {
	return point{p.X + q.X, p.Y + q.Y}
}

func (p point) subtract(q point) point {
	return point{p.X - q.X, p.Y - q.Y}
}

func (p point) multiply(a float64) point {
	return point{a * p.X, a * p.Y}
}

func (p point) dot(q point) float64 {
	return p.X*q.X + p.Y*q.Y
}

func (p point) cross(q point) float64 {
	return p.X*q.Y - p.Y*q.X
}

func (p point) equal(q point) bool {
	return math.Abs(p.X-q.X) < 1e-8 && math.Abs(p.Y-q.Y) < 1e-8
}

func (p point) collinear(q, r point) bool {
	return math.Abs(p.cross(q)+q.cross(r)+r.cross(p)) < 1e-8
}

func (p point) onLine(q, r point) bool {
	return math.Abs(p.cross(q)+q.cross(r)+r.cross(p)) < 1e-8
}

func (p point) onRay(q, r point) bool {
	return p.subtract(q).dot(r.subtract(q)) > -1e-8
}

func (p point) onSegment(q, r point) bool {
	if !p.collinear(q, r) {
		return false
	}
	return p.onRay(q, r) && p.onRay(r, q)
}

func (p point) lineDist(q, r point) float64 {
	return math.Abs(p.subtract(q).cross(p.subtract(r))) / q.subtract(r).length()
}

func (p point) segmentDist(q, r point) float64 {
	if p.dot(q.subtract(r)) < 1e-8 {
		return p.subtract(r).length()
	}
	if p.dot(r.subtract(q)) < 1e-8 {
		return p.subtract(q).length()
	}
	return p.lineDist(q, r)
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func segmentLatticePointsCount(x1, y1, x2, y2 int) int {
	return int(math.Abs(float64(gcd(x1-x2, y1-y2)))) + 1
}

func triangleAreaBH(b, h float64) float64 {
	return b * h / 2
}

func triangleArea2sidesAngle(a, b, t float64) float64 {
	return math.Abs(a * b * math.Sin(t) / 2)
}

func triangleArea2anglesSide(t1, t2, s float64) float64 {
	return math.Abs(s*s*math.Sin(t1)*math.Sin(t2) / (2 * math.Sin(t1+t2)))
}

func triangleArea3sides(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func triangleArea3points(a, b, c point) float64 {
	return math.Abs(a.cross(b) + b.cross(c) + c.cross(a)) / 2
}

func picksTheorem(a, b int) int {
	return a - b/2 + 1
}

func cosRule(a, b, c float64) float64 {
	res := (b*b + c*c - a*a) / (2 * b * c)
	if math.Abs(res-1) < 1e-8 {
		res = 1
	}
	if math.Abs(res+1) < 1e-8 {
		res = -1
	}
	return math.Acos(res)
}

func sinRuleAngle(s1, s2, a1 float64) float64 {
	res := s2 * math.Sin(a1) / s1
	if math.Abs(res-1) < 1e-8 {
		res = 1
	}
	if math.Abs(res+1) < 1e-8 {
		res = -1
	}
	return math.Asin(res)
}

func sinRuleSide(s1, a1, a2 float64) float64 {
	return math.Abs(s1 * math.Sin(a2) / math.Sin(a1))
}

func circleLineIntersection(p0, p1, cen point, rad float64) (point, point, int) {
	a := p1.subtract(p0).dot(p1.subtract(p0))
	b := 2 * p1.subtract(p0).dot(p0.subtract(cen))
	c := p0.subtract(cen).dot(p0.subtract(cen)) - rad*rad
	det := b*b - 4*a*c
	if math.Abs(det) < 1e-8 {
		det = 0
		return point{}, point{}, 1
	} else if det < 0 {
		return point{}, point{}, 0
	}
	det = math.Sqrt(det)
	t1 := (-b + det) / (2 * a)
	t2 := (-b - det) / (2 * a)
	r1 := p0.add(p1.subtract(p0).multiply(t1))
	r2 := p0.add(p1.subtract(p0).multiply(t2))
	return r1, r2, 2
}

func circleCircleIntersection(c1 point, r1 float64, c2 point, r2 float64) (point, point, int) {
	if c1.equal(c2) && math.Abs(r1-r2) < 1e-8 {
		return c1, c2, 1
	}
	len := c1.subtract(c2).length()
	if math.Abs(len-(r1+r2)) < 1e-8 || math.Abs(math.Abs(r1-r2)-len) < 1e-8 {
		var d, c point
		var r float64
		if r1 > r2 {
			d = c1.subtract(c2)
			c = c1
			r = r1
		} else {
			d = c2.subtract(c1)
			c = c2
			r = r2
		}
		res1 := d.normalize().multiply(r).add(c)
		res2 := d.normalize().multiply(-r).add(c)
		return res1, res2, 1
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return point{}, point{}, 0
	}
	a := cosRule(r2, r1, len)
	c1c2 := c1.subtract(c2).normalize().multiply(r1)
	res1 := c1c2.rotate(a).add(c1)
	res2 := c1c2.rotate(-a).add(c1)
	return res1, res2, 2
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func convexPolygonIntersect(p, q []point) []point {
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

func getCommonTangents(c1 point, r1 float64, c2 point, r2 float64) ([]point, []point) {
	if r1 < r2 {
		r1, r2 = r2, r1
		c1, c2 = c2, c1
	}
	d := c1.subtract(c2).length()
	theta := math.Acos((r1 - r2) / d)
	v := c2.subtract(c1).normalize()
	v1 := v.rotate(theta)
	v2 := v.rotate(-theta)
	res := make([]point, 0)
	res = append(res, c1.add(v1.multiply(r1)), c2.add(v1.multiply(r2)))
	res = append(res, c1.add(v2.multiply(r1)), c2.add(v2.multiply(r2)))
	theta = math.Acos((r1 + r2) / d)
	v1 = v.rotate(theta)
	v2 = v.rotate(-theta)
	res = append(res, c1.add(v1.multiply(r1)), c2.subtract(v1.multiply(r2)))
	res = append(res, c1.add(v2.multiply(r1)), c2.subtract(v2.multiply(r2)))
	return res[:2], res[2:]
}

func polygonArea3points(a, b, c point) float64 {
	return math.Abs(a.cross(b) + b.cross(c) + c.cross(a)) / 2
}

func pointInPolygon(p []point, pnt point) bool {
	p2 := pnt.add(point{1, 0})
	cnt := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		if p[i].onSegment(pnt, p2) {
			return true
		}
		var r point
		if !intersect(pnt, p2, p[i], p[j], &r) {
			continue
		}
		if !pnt.onRay(p2, r) {
			continue
		}
		if r.equal(p[i]) || r.equal(p[j]) {
			if math.Abs(r.Y-min(p[i].Y, p[j].Y)) < 1e-8 {
				continue
			}
		}
		if !r.onSegment(p[i], p[j]) {
			continue
		}
		cnt++
	}
	return cnt&1 == 1
}

func sortAntiClockWise(pnts []point) {
	mn := point{math.Inf(1), math.Inf(1)}
	for i := 0; i < len(pnts); i++ {
		if pnts[i].less(mn) {
			mn = pnts[i]
		}
	}
	sort.Slice(pnts, func(i, j int) bool {
		cr := pnts[i].cross(pnts[j])
		if math.Abs(cr) < 1e-8 {
			return pnts[i].less(pnts[j])
		}
		return cr > 0
	})
}

func convexHull(pnts []point) []point {
	sortAntiClockWise(pnts)
	convex := make([]point, 0)
	convex = append(convex, pnts[0])
	if len(pnts) == 1 {
		return convex
	}
	convex = append(convex, pnts[1])
	if len(pnts) == 2 {
		if pnts[0].equal(pnts[1]) {
			convex = convex[:0]
		}
		return convex
	}
	for i := 2; i <= len(pnts); i++ {
		c := pnts[i%len(pnts)]
		for len(convex) > 1 {
			b := convex[len(convex)-1]
			a := convex[len(convex)-2]
			if b.subtract(a).cross(b.subtract(c)) < -1e-8 {
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

func circleLineIntersection(p0, p1, cen point, rad float64) (point, point, int) {
	a := p1.subtract(p0).dot(p1.subtract(p0))
	b := 2 * p1.subtract(p0).dot(p0.subtract(cen))
	c := p0.subtract(cen).dot(p0.subtract(cen)) - rad*rad
	det := b*b - 4*a*c
	if math.Abs(det) < 1e-8 {
		det = 0
		return point{}, point{}, 1
	} else if det < 0 {
		return point{}, point{}, 0
	}
	det = math.Sqrt(det)
	t1 := (-b + det) / (2 * a)
	t2 := (-b - det) / (2 * a)
	r1 := p0.add(p1.subtract(p0).multiply(t1))
	r2 := p0.add(p1.subtract(p0).multiply(t2))
	return r1, r2, 2
}

func circleCircleIntersection(c1 point, r1 float64, c2 point, r2 float64) (point, point, int) {
	if c1.equal(c2) && math.Abs(r1-r2) < 1e-8 {
		return c1, c2, 1
	}
	len := c1.subtract(c2).length()
	if math.Abs(len-(r1+r2)) < 1e-8 || math.Abs(math.Abs(r1-r2)-len) < 1e-8 {
		var d, c point
		var r float64
		if r1 > r2 {
			d = c1.subtract(c2)
			c = c1
			r = r1
		} else {
			d = c2.subtract(c1)
			c = c2
			r = r2
		}
		res1 := d.normalize().multiply(r).add(c)
		res2 := d.normalize().multiply(-r).add(c)
		return res1, res2, 1
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return point{}, point{}, 0
	}
	a := cosRule(r2, r1, len)
	c1c2 := c1.subtract(c2).normalize().multiply(r1)
	res1 := c1c2.rotate(a).add(c1)
	res2 := c1c2.rotate(-a).add(c1)
	return res1, res2, 2
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		a += p[i].X*p[j].Y - p[i].Y*p[j].X
	}
	a *= 0.5
	x /= 6 * a
	y /= 6 * a
	return point{x, y}
}

func polygonCut(p []point, a, b point) []point {
	res := make([]point, 0)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := p[i].subtract(a).cross(p[i].subtract(b)) > 1e-8
		in2 := p[j].subtract(a).cross(p[j].subtract(b)) > 1e-8
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	return res
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += p[i].cross(p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(p []point) point {
	a := 0.0
	x, y := 0.0, 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		x += (p[i].X + p[j].X) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
		y += (p[i].Y + p[j].Y) * (p[i].X*p[j].Y - p[j].X*p[i].Y)
