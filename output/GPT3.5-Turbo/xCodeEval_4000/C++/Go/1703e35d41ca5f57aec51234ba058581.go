package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func vec(a, b point) point {
	return point{b.X - a.X, b.Y - a.Y}
}

func polar(r, t float64) point {
	return point{r * math.Cos(t), r * math.Sin(t)}
}

func angle(v point) float64 {
	return math.Atan2(v.Y, v.X)
}

func length(v point) float64 {
	return math.Hypot(v.Y, v.X)
}

func lengthSqr(v point) float64 {
	return dot(v, v)
}

func dot(a, b point) float64 {
	return (conj(a).X * b.X) + (conj(a).Y * b.Y)
}

func cross(a, b point) float64 {
	return (conj(a).X * b.Y) - (conj(a).Y * b.X)
}

func rotate(v point, t float64) point {
	return polar(length(v), angle(v)+t)
}

func rotateabout(v point, t float64, a point) point {
	return point{rotate(vec(a, v), t).X + a.X, rotate(vec(a, v), t).Y + a.Y}
}

func reflect(p, m point) point {
	return point{(conj(p).X / m.X) * m.X, (conj(p).Y / m.Y) * m.Y}
}

func normalize(p point) point {
	return point{p.X / length(p), p.Y / length(p)}
}

func same(a, b point) bool {
	return lengthSqr(vec(a, b)) < EPS
}

func mid(a, b point) point {
	return point{(a.X + b.X) / 2, (a.Y + b.Y) / 2}
}

func perp(a point) point {
	return point{-a.Y, a.X}
}

func colliner(a, b, p point) bool {
	return pointOnLine(a, b, p)
}

type STATE int

const (
	IN STATE = iota
	OUT
	BOUNDRY
)

func intersect(a, b, p, q, ret point) bool {
	d1 := cross(p-a, b-a)
	d2 := cross(q-a, b-a)
	ret = point{(d1 * q.X - d2 * p.X) / (d1 - d2), (d1 * q.Y - d2 * p.Y) / (d1 - d2)}
	if math.Abs(d1-d2) > EPS {
		return true
	}
	return false
}

func pointOnLine(a, b, p point) bool {
	return math.Abs(cross(vec(a, b), vec(a, p))) < EPS
}

func pointOnRay(a, b, p point) bool {
	return dot(vec(a, p), vec(a, b)) > -EPS
}

func pointOnSegment(a, b, p point) bool {
	if !colliner(a, b, p) {
		return false
	}
	return pointOnRay(a, b, p) && pointOnRay(b, a, p)
}

func pointLineDist(a, b, p point) float64 {
	return math.Abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)))
}

func pointSegmentDist(a, b, p point) float64 {
	if dot(vec(a, b), vec(a, p)) < EPS {
		return length(vec(a, p))
	}
	if dot(vec(b, a), vec(b, p)) < EPS {
		return length(vec(b, p))
	}
	return pointLineDist(a, b, p)
}

func segmentLatticePointsCount(x1, y1, x2, y2 int) int {
	return int(math.Abs(float64(gcd(x1-x2, y1-y2)))) + 1
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func triangleAreaBH(b, h float64) float64 {
	return b * h / 2
}

func triangleArea2sidesAngle(a, b, t float64) float64 {
	return math.Abs(a * b * math.Sin(t) / 2)
}

func triangleArea2anglesSide(t1, t2, s float64) float64 {
	return math.Abs(s * s * math.Sin(t1) * math.Sin(t2) / (2 * math.Sin(t1+t2)))
}

func triangleArea3sides(a, b, c float64) float64 {
	s := (a + b + c) / 2
	return math.Sqrt(s * (s - a) * (s - b) * (s - c))
}

func triangleArea3points(a, b, c point) float64 {
	return math.Abs(cross(a, b) + cross(b, c) + cross(c, a)) / 2
}

func picksTheorm(a, b int) int {
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

func sinRuleAngle(s1, s2, a1 float64) float64 {
	res := s2 * math.Sin(a1) / s1
	if math.Abs(res-1) < EPS {
		res = 1
	}
	if math.Abs(res+1) < EPS {
		res = -1
	}
	return math.Asin(res)
}

func sinRuleSide(s1, a1, a2 float64) float64 {
	return math.Abs(s1 * math.Sin(a2) / math.Sin(a1))
}

func circleLineIntersection(p0, p1, cen point, rad float64, r1, r2 point) int {
	a := dot(p1.Sub(p0), p1.Sub(p0))
	b := 2 * dot(p1.Sub(p0), p0.Sub(cen))
	c := dot(p0.Sub(cen), p0.Sub(cen)) - rad*rad
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
	r1 = p0.Add(p1.Sub(p0).Mul(t1))
	r2 = p0.Add(p1.Sub(p0).Mul(t2))
	return res
}

func circleCircleIntersection(c1 point, r1 float64, c2 point, r2 float64, res1, res2 point) int {
	if same(c1, c2) && math.Abs(r1-r2) < EPS {
		res1 = res2 = c1
		if math.Abs(r1) < EPS {
			return 1
		}
		return OO
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
		res1 = normalize(d).Mul(r).Add(c)
		res2 = normalize(d).Mul(-r).Add(c)
		return 1
	}
	if len > r1+r2 || len < math.Abs(r1-r2) {
		return 0
	}
	a := cosRule(r2, r1, len)
	c1c2 := normalize(vec(c1, c2)).Mul(r1)
	res1 = rotate(c1c2, a).Add(c1)
	res2 = rotate(c1c2, -a).Add(c1)
	return 2
}

func circle2(p1, p2 point, cen *point, r *float64) {
	*cen = mid(p1, p2)
	*r = length(vec(p1, p2)) / 2
}

func circle3(p1, p2, p3 point, cen *point, r *float64) bool {
	m1 := mid(p1, p2)
	m2 := mid(p2, p3)
	perp1 := perp(vec(p1, p2))
	perp2 := perp(vec(p2, p3))
	res := intersect(m1, m1.Add(perp1), m2, m2.Add(perp2), *cen)
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

func tangentPoints(cen point, r float64, p point, r1, r2 point) int {
	s := circlePoint(cen, r, p)
	if s != OUT {
		r1 = r2 = p
		if s == BOUNDRY {
			return 1
		}
		return 0
	}
	cp := vec(cen, p)
	h := length(cp)
	a := math.Acos(r / h)
	cp = normalize(cp).Mul(r)
	r1 = rotate(cp, a).Add(cen)
	r2 = rotate(cp, -a).Add(cen)
	return 2
}

func polygonArea(p []point) float64 {
	res := 0.0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		res += cross(p[i], p[j])
	}
	return math.Abs(res) / 2
}

func polygonCentroid(polygon []point) point {
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

func picksTheorem(p []point) int {
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
	return int(math.Round(area - float64(bound)/2 + 1))
}

func polygonCut(p []point, a, b point, res []point) {
	res = []point{}
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

func convexPolygonIntersect(p, q []point, res []point) {
	res = q
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		var temp []point
		polygonCut(res, p[i], p[j], temp)
		res = temp
		if len(res) == 0 {
			return
		}
	}
}

func voronoi(pnts, rect []point, res [][]point) {
	res = [][]point{}
	for i := 0; i < len(pnts); i++ {
		res = append(res, rect)
		for j := 0; j < len(pnts); j++ {
			if j == i {
				continue
			}
			p := perp(vec(pnts[i], pnts[j]))
			m := mid(pnts[i], pnts[j])
			var temp []point
			polygonCut(res[len(res)-1], m, m.Add(p), temp)
			res[len(res)-1] = temp
		}
	}
}

func pointInPolygon(p []point, pnt point) STATE {
	p2 := pnt.Add(point{1, 0})
	cnt := 0
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		if pointOnSegment(p[i], p[j], pnt) {
			return BOUNDRY
		}
		var r point
		if !intersect(pnt, p2, p[i], p[j], r) {
			continue
		}
		if !pointOnRay(pnt, p2, r) {
			continue
		}
		if same(r, p[i]) || same(r, p[j]) {
			if math.Abs(r.Y-min(p[i].Y, p[j].Y)) < EPS {
				continue
			}
		}
		if !pointOnSegment(p[i], p[j], r) {
			continue
		}
		cnt++
	}
	if cnt&1 == 1 {
		return IN
	}
	return OUT
}

func cmp(about point) func(p, q point) bool {
	return func(p, q point) bool {
		cr := cross(vec(about, p), vec(about, q))
		if math.Abs(cr) < EPS {
			return makePair(p.Y, p.X) < makePair(q.Y, q.X)
		}
		return cr > 0
	}
}

func sortAntiClockWise(pnts []point) {
	mn := point{1 / 0.0, 1 / 0.0}
	for i := 0; i < len(pnts); i++ {
		if makePair(pnts[i].Y, pnts[i].X) < makePair(mn.Y, mn.X) {
			mn = pnts[i]
		}
	}

	sort.Slice(pnts, cmp(mn))
}

func convexHull(pnts []point, convex *[]point) {
	sortAntiClockWise(pnts)
	*convex = []point{}
	*convex = append(*convex, pnts[0])
	if len(pnts) == 1 {
		return
	}
	*convex = append(*convex, pnts[1])
	if len(pnts) == 2 {
		if same(pnts[0], pnts[1]) {
			*convex = (*convex)[:len(*convex)-1]
		}
		return
	}
	for i := 2; i <= len(pnts); i++ {
		c := pnts[i%len(pnts)]
		for len(*convex) > 1 {
			b := (*convex)[len(*convex)-1]
			a := (*convex)[len(*convex)-2]
			if cross(vec(b, a), vec(b, c)) < -EPS {
				break
			}
			*convex = (*convex)[:len(*convex)-1]
		}
		if i < len(pnts) {
			*convex = append(*convex, pnts[i])
		}
	}
}

const (
	EPS = 1e-5
	OO  = 1e9
)

func makePair(a, b float64) float64 {
	return a + b/1e6
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func main() {
	var Xc, Yc, Vc int
	var Xb, Yb, Vb, r int
	fmt.Scan(&Xc, &Yc, &Vc)
	fmt.Scan(&Xb, &Yb, &Vb, &r)
	planet := point{float64(Xc), float64(Yc)}
	ship := point{float64(Xb), float64(Yb)}
	R := length(planet)
	w := float64(Vc) / R
	left := 0.0
	right := 1 << 30
	for i := 0; i < 300; i++ {
		mid := (right + left) / 2
		new_planet := rotate(planet, w*mid)
		var distance float64
		if pointSegmentDist(ship, new_planet, point{0, 0}) < float64(r) {
			var a, b, c, d point
			tangentPoints(point{0, 0}, float64(r), ship, &a, &b)
			tangentPoints(point{0, 0}, float64(r), new_planet, &c, &d)
			distance = 1 << 30
			distance = math.Min(distance, length(vec(ship, a))+
				length(vec(c, new_planet))+
				arc_length(a, c, float64(r)))

			distance = math.Min(distance, length(vec(ship, b))+
				length(vec(c, new_planet))+
				arc_length(b, c, float64(r)))

			distance = math.Min(distance, length(vec(ship, a))+
				length(vec(d, new_planet))+
				arc_length(a, d, float64(r)))

			distance = math.Min(distance, length(vec(ship, b))+
				length(vec(d, new_planet))+
				arc_length(b, d, float64(r)))
		} else {
			distance = length(vec(ship, new_planet))
		}

		if distance/float64(Vb) < mid {
			right = mid
		} else {
			left = mid
		}
	}
	fmt.Printf("%.10f\n", left)
}
