package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func complexMult(a complex128, b point) point {
	return point(real(a)*b.X, real(a)*b.Y)
}

func complexMult2(a point, b complex128) point {
	return point(real(b)*a.X, real(b)*a.Y)
}

func complexAdd(a, b point) point {
	return point(a.X+b.X, a.Y+b.Y)
}

func complexSub(a, b point) point {
	return point(a.X-b.X, a.Y-b.Y)
}

func complexDiv(a, b point) point {
	return point(a.X/b.X, a.Y/b.Y)
}

func complexConj(a point) point {
	return point(a.X, -a.Y)
}

func complexDot(a, b point) float64 {
	return real(complexConj(a) * b)
}

func complexCross(a, b point) float64 {
	return imag(complexConj(a) * b)
}

func complexRotate(v point, t float64) point {
	return complexMult2(v, complex(math.Cos(t), math.Sin(t)))
}

func complexRotateAbout(v point, t float64, a point) point {
	return complexAdd(complexRotate(complexSub(v, a), t), a)
}

func complexReflect(p, m point) point {
	return complexMult2(complexConj(complexDiv(p, m)), m)
}

func complexNormalize(p point) point {
	return complexDiv(p, complexLength(p))
}

func complexLength(p point) float64 {
	return math.Hypot(p.Y, p.X)
}

func complexLengthSqr(p point) float64 {
	return complexDot(p, p)
}

func complexMid(a, b point) point {
	return complexDiv(complexAdd(a, b), point(2, 0))
}

func complexPerp(a point) point {
	return point(-a.Y, a.X)
}

func complexCollinear(a, b, p point) bool {
	return math.Abs(complexCross(complexSub(a, b), complexSub(a, p))) < EPS
}

func complexPointOnLine(a, b, p point) bool {
	return math.Abs(complexCross(complexSub(a, b), complexSub(a, p))) < EPS
}

func complexPointOnRay(a, b, p point) bool {
	return complexDot(complexSub(a, p), complexSub(a, b)) > -EPS
}

func complexPointOnSegment(a, b, p point) bool {
	if !complexCollinear(a, b, p) {
		return false
	}
	return complexPointOnRay(a, b, p) && complexPointOnRay(b, a, p)
}

func complexPointLineDist(a, b, p point) float64 {
	return math.Abs(complexCross(complexSub(a, b), complexSub(a, p))) / complexLength(complexSub(a, b))
}

func complexPointSegmentDist(a, b, p point) float64 {
	if complexDot(complexSub(a, b), complexSub(a, p)) < EPS {
		return complexLength(complexSub(a, p))
	}
	if complexDot(complexSub(b, a), complexSub(b, p)) < EPS {
		return complexLength(complexSub(b, p))
	}
	return complexPointLineDist(a, b, p)
}

func complexSegmentLatticePointsCount(x1, y1, x2, y2 int) int {
	return int(math.Abs(float64(gcd(x1-x2, y1-y2)))) + 1
}

func complexTriangleAreaBH(b, h float64) float64 {
	return b * h / 2
}

func complexTriangleArea2sidesAngle(a, b, t float64) float64 {
	return math.Abs(a * b * math.Sin(t) / 2)
}

func complexTriangleArea2anglesSide(t1, t2, s float64) float64 {
	return math.Abs(s * s * math.Sin(t1) * math.Sin(t2) / (2 * math.Sin(t1+t2)))
}

func complexTriangleArea3sides(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func complexTriangleArea3points(a, b, c point) float64 {
	return math.Abs(complexCross(a, b) + complexCross(b, c) + complexCross(c, a)) / 2
}

func complexPicksTheorem(a, b int) int {
	return a - b/2 + 1
}

func complexCosRule(a, b, c float64) float64 {
	res := (b*b + c*c - a*a) / (2 * b * c)
	if math.Abs(res-1) < EPS {
		res = 1
	}
	if math.Abs(res+1) < EPS {
		res = -1
	}
	return math.Acos(res)
}

func complexSinRuleAngle(s1, s2, a1 float64) float64 {
	res := s2 * math.Sin(a1) / s1
	if math.Abs(res-1) < EPS {
		res = 1
	}
	if math.Abs(res+1) < EPS {
		res = -1
	}
	return math.Asin(res)
}

func complexSinRuleSide(s1, a1, a2 float64) float64 {
	return math.Abs(s1 * math.Sin(a2) / math.Sin(a1))
}

func complexCircleLineIntersection(p0, p1, cen point, rad float64) (point, point) {
	var a, b, c, t1, t2 float64
	a = complexDot(complexSub(p1, p0), complexSub(p1, p0))
	b = 2 * complexDot(complexSub(p1, p0), complexSub(p0, cen))
	c = complexDot(complexSub(p0, cen), complexSub(p0, cen)) - rad*rad
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
	t1 = (-b + det) / (2 * a)
	t2 = (-b - det) / (2 * a)
	r1 := complexAdd(p0, complexMult2(complexSub(p1, p0), t1))
	r2 := complexAdd(p0, complexMult2(complexSub(p1, p0), t2))
	return r1, r2
}

func complexCircleCircleIntersection(c1 point, r1 float64, c2 point, r2 float64) (point, point) {
	if complexSame(c1, c2) && math.Abs(r1-r2) < EPS {
		return c1, c1
	}
	len := complexLength(complexSub(c1, c2))
	if math.Abs(len-(r1+r2)) < EPS || math.Abs(math.Abs(r1-r2)-len) < EPS {
		var d, c point
		var r float64
		if r1 > r2 {
			d = complexSub(c1, c2)
			c = c1
			r = r1
		} else {
			d = complexSub(c2, c1)
			c = c2
			r = r2
		}
		res1 := complexAdd(complexMult2(complexNormalize(d), r), c)
		res2 := complexSub(complexMult2(complexNormalize(d), r), c)
		return res1, res2
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return point{}, point{}
	}
	a := complexCosRule(r2, r1, len)
	c1c2 := complexMult2(complexNormalize(complexSub(c1, c2)), r1)
	res1 := complexAdd(complexRotate(c1c2, a), c1)
	res2 := complexAdd(complexRotate(c1c2, -a), c1)
	return res1, res2
}

func complexCircle2(p1, p2 point) (point, float64) {
	cen := complexMid(p1, p2)
	r := complexLength(complexSub(p1, p2)) / 2
	return cen, r
}

func complexCircle3(p1, p2, p3 point) (point, float64, bool) {
	m1 := complexMid(p1, p2)
	m2 := complexMid(p2, p3)
	perp1 := complexPerp(complexSub(p1, p2))
	perp2 := complexPerp(complexSub(p2, p3))
	var res bool
	cen, res := complexCircleLineIntersection(m1, complexAdd(m1, perp1), m2, complexAdd(m2, perp2))
	r := complexLength(complexSub(cen, p1))
	return cen, r, res
}

type STATE int

const (
	IN STATE = iota
	OUT
	BOUNDRY
)

func complexCirclePoint(cen point, r float64, p point) STATE {
	lensqr := complexLengthSqr(complexSub(cen, p))
	if math.Abs(lensqr-r*r) < EPS {
		return BOUNDRY
	}
	if lensqr < r*r {
		return IN
	}
	return OUT
}

func complexTangentPoints(cen point, r float64, p point) (point, point) {
	s := complexCirclePoint(cen, r, p)
	if s != OUT {
		return p, p
	}
	cp := complexSub(cen, p)
	h := complexLength(cp)
	a := math.Acos(r / h)
	cp = complexNormalize(cp)
	r1 := complexRotate(cp, a)
	r2 := complexRotate(cp, -a)
	r1 = complexAdd(r1, cen)
	r2 = complexAdd(r2, cen)
	return r1, r2
}

func complexGetCommonTangents(c1 point, r1 float64, c2 point, r2 float64) ([]point, []point) {
	if r1 < r2 {
		r1, r2 = r2, r1
		c1, c2 = c2, c1
	}
	d := complexLength(complexSub(c1, c2))
	theta := math.Acos((r1 - r2) / d)
	v := complexSub(c2, c1)
	v = complexNormalize(v)
	v1 := complexMult2(v, complex(math.Cos(theta), math.Sin(theta)))
	v2 := complexMult2(v, complex(math.Cos(-theta), math.Sin(-theta)))
	res1 := []point{complexAdd(c1, complexMult2(v1, r1)), complexAdd(c2, complexMult2(v1, r2))}
	res2 := []point{complexAdd(c1, complexMult2(v2, r1)), complexAdd(c2, complexMult2(v2, r2)))}
	theta = math.Acos((r1 + r2) / d)
	v1 = complexMult2(v, complex(math.Cos(theta), math.Sin(theta)))
	v2 = complexMult2(v, complex(math.Cos(-theta), math.Sin(-theta)))
	res1 = append(res1, complexAdd(c1, complexMult2(v1, r1)), complexSub(c2, complexMult2(v1, r2)))
	res2 = append(res2, complexAdd(c1, complexMult2(v2, r1)), complexSub(c2, complexMult2(v2, r2)))
	return res1, res2
}

func complexPolygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += complexCross(p[i], p[j])
	}
	return math.Abs(res) / 2
}

func complexPolygonCentroid(p []point) point {
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

func complexPicksTheorem(p []point) int {
	area := complexPolygonArea(p)
	bound := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		v := complexSub(p[i], p[j])
		bound += abs(gcd(int(v.X), int(v.Y)))
	}
	return int(math.Round(area - float64(bound)/2 + 1))
}

func complexPolygonCut(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
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

func complexConvexPolygonIntersect(p, q []point) []point {
	res := q
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		temp := complexPolygonCut(res, p[i], p[j])
		res = temp
		if len(res) == 0 {
			return res
		}
	}
	return res
}

func complexVoronoi(pnts, rect []point) [][]point {
	res := [][]point{}
	for i := 0; i < len(pnts); i++ {
		res = append(res, rect)
		for j := 0; j < len(pnts); j++ {
			if j == i {
				continue
			}
			p := complexPerp(complexSub(pnts[i], pnts[j]))
			m := complexMid(pnts[i], pnts[j])
			temp := complexPolygonCut(res[len(res)-1], m, complexAdd(m, p))
			res[len(res)-1] = temp
		}
	}
	return res
}

func complexPointInPolygon(p []point, pnt point) STATE {
	p2 := complexAdd(pnt, point{1, 0})
	cnt := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		if complexPointOnSegment(p[i], p[j], pnt) {
			return BOUNDRY
		}
		var r point
		if !intersect(pnt, p2, p[i], p[j], &r) {
			continue
		}
		if !complexPointOnRay(pnt, p2, r) {
			continue
		}
		if complexSame(r, p[i]) || complexSame(r, p[j]) {
			if math.Abs(r.Y-min(p[i].Y, p[j].Y)) < EPS {
				continue
			}
		}
		if !complexPointOnSegment(p[i], p[j], r) {
			continue
		}
		cnt++
	}
	if cnt&1 == 1 {
		return IN
	}
	return OUT
}

func complexSortAntiClockWise(pnts []point) {
	mn := point{1 / 0.0, 1 / 0.0}
	for i := 0; i < len(pnts); i++ {
		if makePair(pnts[i].Y, pnts[i].X) < makePair(mn.Y, mn.X) {
			mn = pnts[i]
		}
	}

	sort.Slice(pnts, func(i, j int) bool {
		cr := complexCross(complexSub(mn, pnts[i]), complexSub(mn, pnts[j]))
		if math.Abs(cr) < EPS {
			return makePair(pnts[i].Y, pnts[i].X) < makePair(pnts[j].Y, pnts[j].X)
		}
		return cr > 0
	})
}

func complexConvexHull(pnts []point) []point {
	complexSortAntiClockWise(pnts)
	convex := []point{}
	convex = append(convex, pnts[0])
	if len(pnts) == 1 {
		return convex
	}
	convex = append(convex, pnts[1])
	if len(pnts) == 2 {
		if complexSame(pnts[0], pnts[1]) {
			convex = convex[:0]
		}
		return convex
	}
	for i := 2; i <= len(pnts); i++ {
		c := pnts[i%len(pnts)]
		for len(convex) > 1 {
			b := convex[len(convex)-1]
			a := convex[len(convex)-2]
			if complexCross(complexSub(b, a), complexSub(b, c)) < -EPS {
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

func complexPolygonCut2(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
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

func complexPolygonCut3(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut4(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut5(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut6(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut7(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut8(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut9(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut10(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut11(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut12(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut13(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut14(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut15(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut16(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut17(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut18(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut19(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut20(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut21(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut22(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut23(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut24(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut25(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut26(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut27(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut28(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut29(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut30(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut31(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func complexPolygonCut32(p []point, a, b point) []point {
	res := []point{}
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		in1 := complexCross(complexSub(a, b), complexSub(a, p[i])) > EPS
		in2 := complexCross(complexSub(a, b), complexSub(a, p[j])) > EPS
		if in1 {
			res = append(res, p[i])
		}
		if in1 != in2 {
			var r point
			intersect(a, b, p[i], p[j], &r)
			res = append(res, r)
		}
	}
	if len(res) > 0 && !complexSame(res[len(res)-1], res[0]) {
		res = append(res, res[0])
	}
	return res
}

func main() {
	var xp, yp, vp, x, y, v, r float64
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R := complexLength(point{xp, yp})
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

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func makePair(a, b float64) float64 {
	return a + b/1e9
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

const EPS = 1e-7
