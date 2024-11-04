package main

import (
	"fmt"
	"math"
	"sort"
)

const INF = 10000000
const EPS = 1e-8
const PI = math.Pi

type Point struct {
	x, y float64
}

func (p Point) add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y}
}

func (p Point) sub(q Point) Point {
	return Point{p.x - q.x, p.y - q.y}
}

func (p Point) mul(t float64) Point {
	return Point{p.x * t, p.y * t}
}

func (p Point) div(t float64) Point {
	return Point{p.x / t, p.y / t}
}

func (p Point) dot(q Point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p Point) cross(q Point) float64 {
	return p.x*q.y - p.y*q.x
}

func (p Point) cmp(q Point) int {
	if cmp := compare(p.x, q.x); cmp != 0 {
		return cmp
	}
	return compare(p.y, q.y)
}

func (p Point) equals(q Point) bool {
	return p.cmp(q) == 0
}

func (p Point) notEquals(q Point) bool {
	return p.cmp(q) != 0
}

func (p Point) lessThan(q Point) bool {
	return p.cmp(q) < 0
}

func compare(x, y float64) int {
	if x < y-EPS {
		return -1
	} else if x > y+EPS {
		return 1
	}
	return 0
}

func abs(p Point) float64 {
	return math.Hypot(p.x, p.y)
}

func arg(p Point) float64 {
	return math.Atan2(p.y, p.x)
}

func ccw(p, q, r Point) int {
	return compare((p.sub(r)).cross(q.sub(r)), 0)
}

func angle(p, q, r Point) float64 {
	u := p.sub(q)
	v := r.sub(q)
	return math.Atan2(u.cross(v), u.dot(v))
}

func dist2(p, q Point) float64 {
	return (p.sub(q)).dot(p.sub(q))
}

func rotateCCW90(p Point) Point {
	return Point{-p.y, p.x}
}

func rotateCW90(p Point) Point {
	return Point{p.y, -p.x}
}

func projectPointLine(a, b, c Point) Point {
	return a.add(b.sub(a).mul((c.sub(a).dot(b.sub(a))) / (b.sub(a).dot(b.sub(a)))))
}

func projectPointSegment(a, b, c Point) Point {
	r := (b.sub(a)).dot(b.sub(a))
	if math.Abs(r) < EPS {
		return a
	}
	r = (c.sub(a).dot(b.sub(a))) / r
	if r < 0 {
		return a
	}
	if r > 1 {
		return b
	}
	return a.add(b.sub(a).mul(r))
}

func between(p, q, r Point) bool {
	return ccw(p, q, r) == 0 && compare((p.sub(q)).cross(r.sub(q)), 0) <= 0
}

func distancePointSegment(a, b, c Point) float64 {
	return math.Sqrt(dist2(c, projectPointSegment(a, b, c)))
}

func distancePointPlane(x, y, z, a, b, c, d float64) float64 {
	return math.Abs(a*x+b*y+c*z-d) / math.Sqrt(a*a+b*b+c*c)
}

func linesParallel(a, b, c, d Point) bool {
	return math.Abs((b.sub(a)).cross(c.sub(d))) < EPS
}

func linesCollinear(a, b, c, d Point) bool {
	return linesParallel(a, b, c, d) &&
		math.Abs((a.sub(b)).cross(a.sub(c))) < EPS &&
		math.Abs((c.sub(d)).cross(c.sub(a))) < EPS
}

func segIntersect(p, q, r, s Point) bool {
	A := q.sub(p)
	B := s.sub(r)
	C := r.sub(p)
	D := s.sub(q)
	a := compare(A.cross(C), 0) + 2*compare(A.cross(D), 0)
	b := compare(B.cross(C), 0) + 2*compare(B.cross(D), 0)
	if a == 3 || a == -3 || b == 3 || b == -3 {
		return false
	}
	if a != 0 || b != 0 || p.equals(r) || p.equals(s) || q.equals(r) || q.equals(s) {
		return true
	}
	t := 0
	if p.lessThan(r) {
		t++
	}
	if p.lessThan(s) {
		t++
	}
	if q.lessThan(r) {
		t++
	}
	if q.lessThan(s) {
		t++
	}
	return t != 0 && t != 4
}

func lineIntersect(p, q, r, s Point) Point {
	a := q.sub(p)
	b := s.sub(r)
	c := Point{p.cross(q), r.cross(s)}
	return Point{Point{a.x, b.x}.cross(c), Point{a.y, b.y}.cross(c)}.div(a.cross(b))
}

func circle2PtsRad(p1, p2 Point, r float64) (Point, bool) {
	d2 := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	det := (r * r / d2) - 0.25
	if det < 0.0 {
		return Point{}, false
	}
	h := math.Sqrt(det)
	c := Point{
		(p1.x + p2.x)*0.5 + (p1.y-p2.y)*h,
		(p1.y + p2.y)*0.5 + (p2.x-p1.x)*h,
	}
	return c, true
}

func computeCircleCenter(a, b, c Point) Point {
	b = a.add(b).div(2)
	c = a.add(c).div(2)
	return lineIntersect(b, b.add(rotateCW90(a.sub(b))), c, c.add(rotateCW90(a.sub(c))))
}

func computeCircleIncenter(a, b, c Point) Point {
	d := b.add(rotateCCW(c.sub(b), angle(c, b, a)/2))
	e := c.add(rotateCCW(a.sub(c), angle(a, c, b)/2))
	return lineIntersect(b, d, c, e)
}

func circleLineIntersection(a, b, c Point, r float64) []Point {
	var ret []Point
	b = b.sub(a)
	a = a.sub(c)
	A := b.dot(b)
	B := a.dot(b)
	C := (a.dot(a) - r*r)
	D := B*B - A*C
	if D < -EPS {
		return ret
	}
	ret = append(ret, c.add(a.add(b.mul((-B + math.Sqrt(D+EPS)) / A))))
	if D > EPS {
		ret = append(ret, c.add(a.add(b.mul((-B - math.Sqrt(D)) / A))))
	}
	return ret
}

func circleCircleIntersection(a, b Point, r, R float64) []Point {
	var ret []Point
	d := math.Sqrt(dist2(a, b))
	if d > r+R || d+math.Min(r, R) < math.Max(r, R) {
		return ret
	}
	x := (d*d - R*R + r*r) / (2 * d)
	y := math.Sqrt(r*r - x*x)
	v := (b.sub(a)).div(d)
	ret = append(ret, a.add(v.mul(x)).add(rotateCCW90(v).mul(y)))
	if y > 0 {
		ret = append(ret, a.add(v.mul(x)).sub(rotateCCW90(v).mul(y)))
	}
	return ret
}

func tangentSegments(c Point, r float64, p Point) []Point {
	var resp []Point
	toCenter := c.sub(p)
	if compare(r-sqrt(dist2(toCenter, Point{0, 0}))) <= 0 {
		resp = append(resp, p, p)
		return resp
	}
	angle := math.Asin(r / sqrt(dist2(toCenter, Point{0, 0})))
	uni := toCenter.div(sqrt(dist2(toCenter, Point{0, 0})))
	tam := sqrt(dist2(toCenter, Point{0, 0})) - r*r
	origi := uni.mul(tam)
	p1 := p.add(rotateCCW(origi, angle))
	resp = append(resp, p1)
	p2 := p.add(rotateCCW(origi, -angle))
	resp = append(resp, p2)
	return resp
}

func inPoly(p Point, T []Point) int {
	a := 0.0
	N := len(T)
	for i := 0; i < N; i++ {
		if between(T[i], p, T[(i+1)%N]) {
			return -1
		}
		a += angle(T[i], p, T[(i+1)%N])
	}
	return compare(a, 0) != 0
}

func polyArea(T []Point) float64 {
	s := 0.0
	n := len(T)
	for i := 0; i < n; i++ {
		s += T[i].cross(T[(i+1)%n])
	}
	return s / 2
}

func computeCentroid(p []Point) Point {
	c := Point{0, 0}
	scale := 6.0 * polyArea(p)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		c = c.add((p[i].add(p[j])).mul(p[i].x*p[j].y - p[j].x*p[i].y))
	}
	return c.div(scale)
}

func radialLt(p, q Point) bool {
	P := p.sub(Point{0, 0})
	Q := q.sub(Point{0, 0})
	R := P.cross(Q)
	if compare(R, 0) != 0 {
		return R > 0
	}
	return compare(P.dot(P), Q.dot(Q)) < 0
}

func convexHull(T []Point) []Point {
	j := 0
	k := 0
	n := len(T)
	U := make([]Point, n)
	pivot := T[0]
	for _, pt := range T {
		if pt.y < pivot.y || (pt.y == pivot.y && pt.x < pivot.x) {
			pivot = pt
		}
	}
	sort.Slice(T, func(i, j int) bool {
		return radialLt(T[i], T[j])
	})
	for k = n - 2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k-- {
	}
	for i := 0; i < n; i++ {
		for j > 1 && ccw(U[j-1], U[j-2], T[i]) >= 0 {
			j--
		}
		U[j] = T[i]
		j++
	}
	U = U[:j]
	return U
}

func polyIntersect(P, Q []Point) []Point {
	m := len(Q)
	n := len(P)
	a, b, aa, ba, inflag := 0, 0, 0, 0, 0
	var R []Point
	for (aa < n || ba < m) && aa < 2*n && ba < 2*m {
		p1 := P[a]
		p2 := P[(a+1)%n]
		q1 := Q[b]
		q2 := Q[(b+1)%m]
		A := p2.sub(p1)
		B := q2.sub(q1)
		cross := compare(A.cross(B), 0)
		ha := ccw(p2, q2, p1)
		hb := ccw(q2, p2, q1)
		if cross == 0 && ccw(p1, q1, p2) == 0 && compare(A.dot(B), 0) < 0 {
			if between(p1, q1, p2) {
				R = append(R, q1)
			}
			if between(p1, q2, p2) {
				R = append(R, q2)
			}
			if between(q1, p1, q2) {
				R = append(R, p1)
			}
			if between(q1, p2, q2) {
				R = append(R, p2)
			}
			if len(R) < 2 {
				return []Point{}
			}
			inflag = 1
			break
		} else if cross != 0 && segIntersect(p1, p2, q1, q2) {
			if inflag == 0 {
				aa = ba = 0
			}
			R = append(R, lineIntersect(p1, p2, q1, q2))
			inflag = 1
			if hb > 0 {
				inflag = 1
			} else {
				inflag = -1
			}
		}
		if cross == 0 && hb < 0 && ha < 0 {
			return R
		}
		t := cross == 0 && hb == 0 && ha == 0
		if t {
			if inflag == 1 {
				R = append(R, q2)
			}
			ba++
			b++
			b %= m
		} else if cross >= 0 && ha <= 0 {
			if inflag == -1 {
				R = append(R, q2)
			}
			ba++
			b++
			b %= m
		} else {
			if inflag == 1 {
				R = append(R, p2)
			}
			aa++
			a++
			a %= n
		}
	}
	if inflag == 0 {
		if inPoly(P[0], Q) != 0 {
			return P
		}
		if inPoly(Q[0], P) != 0 {
			return Q
		}
	}
	uniqueR := make([]Point, 0, len(R))
	seen := make(map[Point]struct{})
	for _, pt := range R {
		if _, ok := seen[pt]; !ok {
			seen[pt] = struct{}{}
			uniqueR = append(uniqueR, pt)
		}
	}
	if len(uniqueR) > 1 && uniqueR[0].equals(uniqueR[len(uniqueR)-1]) {
		uniqueR = uniqueR[:len(uniqueR)-1]
	}
	return uniqueR
}

func pode(loc Point, time float64, x, y, v, r int) bool {
	nave := Point{float64(x), float64(y)}
	if compare(distancePointSegment(loc, nave, Point{0, 0}), float64(r)) >= 0 {
		return compare(time, abs(nave.sub(loc))/float64(v)) >= 0
	} else {
		distN := math.Sqrt(dist2(nave, Point{0, 0}) - float64(r)*float64(r))
		distL := math.Sqrt(dist2(loc, Point{0, 0}) - float64(r)*float64(r))

		a := abs(nave.sub(loc))
		b := abs(nave)
		c := abs(loc)
		bigcos := (b*b + c*c - a*a) / (2 * b * c)
		angNOL := math.Acos(bigcos) - math.Abs(math.Atan(distN/float64(r))) - math.Abs(math.Atan(distL/float64(r)))
		menor := distN + distL + math.Abs(float64(r)*angNOL)

		return compare(time, menor/float64(v)) >= 0
	}
}

func main() {
	var xp, yp, vp, x, y, v, r int
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R := math.Hypot(float64(yp), float64(xp))
	initial := math.Atan2(float64(yp), float64(xp))
	bot := 0.0
	timeTot := (2 * PI * R) / float64(vp)
	top := 1e14
	for compare(top, bot) == 1 {
		mid := (top + bot) / 2
		angle := ((2 * PI * mid) / timeTot) + initial
		loc := Point{math.Cos(angle) * R, math.Sin(angle) * R}

		if pode(loc, mid, x, y, v, r) {
			top = mid
		} else {
			bot = mid
		}
	}
	fmt.Printf("%.7f\n", bot)
}
