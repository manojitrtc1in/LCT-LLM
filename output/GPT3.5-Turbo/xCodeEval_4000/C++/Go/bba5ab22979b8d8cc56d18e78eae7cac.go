package main

import (
	"fmt"
	"math"
)

type point struct {
	x, y float64
}

func (p point) add(q point) point {
	return point{p.x + q.x, p.y + q.y}
}

func (p point) sub(q point) point {
	return point{p.x - q.x, p.y - q.y}
}

func (p point) mul(t float64) point {
	return point{p.x * t, p.y * t}
}

func (p point) div(t float64) point {
	return point{p.x / t, p.y / t}
}

func (p point) dot(q point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p point) cross(q point) float64 {
	return p.x*q.y - p.y*q.x
}

func cmp(x, y, tol float64) int {
	if x <= y+tol {
		if x+tol < y {
			return -1
		}
		return 0
	}
	return 1
}

type polygon []point

func ccw(p, q, r point) int {
	return cmp((p.sub(r)).cross(q.sub(r)), 0, 0)
}

func angle(p, q, r point) float64 {
	u := p.sub(q)
	v := r.sub(q)
	return math.Atan2(u.cross(v), u.dot(v))
}

func dist2(p, q point) float64 {
	return p.sub(q).dot(p.sub(q))
}

func rotateCCW90(p point) point {
	return point{-p.y, p.x}
}

func rotateCW90(p point) point {
	return point{p.y, -p.x}
}

func rotateCCW(p point, t float64) point {
	cosT := math.Cos(t)
	sinT := math.Sin(t)
	return point{p.x*cosT - p.y*sinT, p.x*sinT + p.y*cosT}
}

func projectPointLine(a, b, c point) point {
	return a.add(b.sub(a).mul(c.sub(a).dot(b.sub(a)) / b.sub(a).dot(b.sub(a))))
}

func projectPointSegment(a, b, c point) point {
	r := b.sub(a).dot(b.sub(a))
	if math.Abs(r) < 1e-8 {
		return a
	}
	r = c.sub(a).dot(b.sub(a)) / r
	if r < 0 {
		return a
	}
	if r > 1 {
		return b
	}
	return a.add(b.sub(a).mul(r))
}

func between(p, q, r point) bool {
	return ccw(p, q, r) == 0 && cmp((p.sub(q)).cross(r.sub(q)), 0, 0) <= 0
}

func distancePointSegment(a, b, c point) float64 {
	return math.Sqrt(dist2(c, projectPointSegment(a, b, c)))
}

func distancePointPlane(x, y, z, a, b, c, d float64) float64 {
	return math.Abs(a*x+b*y+c*z-d) / math.Sqrt(a*a+b*b+c*c)
}

func linesParallel(a, b, c, d point) bool {
	return math.Abs((b.sub(a)).cross(c.sub(d))) < 1e-8
}

func linesCollinear(a, b, c, d point) bool {
	return linesParallel(a, b, c, d) && math.Abs((a.sub(b)).cross(a.sub(c))) < 1e-8 && math.Abs((c.sub(d)).cross(c.sub(a))) < 1e-8
}

func segIntersect(p, q, r, s point) bool {
	A := q.sub(p)
	B := s.sub(r)
	C := r.sub(p)
	D := s.sub(q)
	a := cmp(A.cross(C)) + 2*cmp(A.cross(D))
	b := cmp(B.cross(C)) + 2*cmp(B.cross(D))
	if a == 3 || a == -3 || b == 3 || b == -3 {
		return false
	}
	if a != 0 || b != 0 || p == r || p == s || q == r || q == s {
		return true
	}
	t := cmp(p, r) + cmp(p, s) + cmp(q, r) + cmp(q, s)
	return t != 0 && t != 4
}

func lineIntersect(p, q, r, s point) point {
	a := q.sub(p)
	b := s.sub(r)
	c := point{a.cross(b), r.sub(p).cross(s.sub(r))}
	return point{point{a.x, b.x}.cross(c), point{a.y, b.y}.cross(c)}.div(a.cross(b))
}

func circle2PtsRad(p1, p2 point, r float64) (point, bool) {
	d2 := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	det := (r*r)/d2 - 0.25
	if det < 0.0 {
		return point{}, false
	}
	h := math.Sqrt(det)
	c := point{(p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h, (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h}
	return c, true
}

func computeCircleCenter(a, b, c point) point {
	b = a.add(b).div(2)
	c = a.add(c).div(2)
	return lineIntersect(b, b.add(rotateCW90(a.sub(b))), c, c.add(rotateCW90(a.sub(c))))
}

func computeCircleIncenter(a, b, c point) point {
	d := b.add(rotateCCW(c.sub(b), angle(c, b, a)/2))
	e := c.add(rotateCCW(a.sub(c), angle(a, c, b)/2))
	return lineIntersect(b, d, c, e)
}

func circleLineIntersection(a, b, c point, r float64) []point {
	ret := []point{}
	b = b.sub(a)
	a = a.sub(c)
	A := b.dot(b)
	B := a.dot(b)
	C := a.dot(a) - r*r
	D := B*B - A*C
	if D < -1e-8 {
		return ret
	}
	ret = append(ret, c.add(a).add(b.mul(-B+math.Sqrt(D+1e-8))/A))
	if D > 1e-8 {
		ret = append(ret, c.add(a).add(b.mul(-B-math.Sqrt(D))/A))
	}
	return ret
}

func circleCircleIntersection(a, b point, r, R float64) []point {
	ret := []point{}
	d := math.Sqrt(dist2(a, b))
	if d > r+R || d+math.Min(r, R) < math.Max(r, R) {
		return ret
	}
	x := (d*d - R*R + r*r) / (2 * d)
	y := math.Sqrt(r*r - x*x)
	v := b.sub(a).div(d)
	ret = append(ret, a.add(v.mul(x)).add(rotateCCW90(v).mul(y)))
	if y > 0 {
		ret = append(ret, a.add(v.mul(x)).add(rotateCW90(v).mul(y)))
	}
	return ret
}

func tangentSegments(c point, r float64, p point) []point {
	resp := []point{}
	toCenter := c.sub(p)
	if cmp(r-math.Sqrt(dist2(toCenter, point{0, 0})), 0, 0) <= 0 {
		resp = append(resp, p)
		resp = append(resp, p)
		return resp
	}
	angle := math.Asin(r / math.Sqrt(dist2(toCenter, point{0, 0})))
	uni := toCenter.div(math.Sqrt(dist2(toCenter, point{0, 0})))
	tam := math.Sqrt(dist2(toCenter, point{0, 0}) - r*r)
	origi := uni.mul(tam)
	p1 := p.add(rotateCCW(origi, angle))
	resp = append(resp, p1)
	p2 := p.add(rotateCCW(origi, -angle))
	resp = append(resp, p2)
	return resp
}

func inPoly(p point, T polygon) int {
	a := 0
	N := len(T)
	for i := 0; i < N; i++ {
		if between(T[i], p, T[(i+1)%N]) {
			return -1
		}
		a += cmp(angle(T[i], p, T[(i+1)%N]), 0, 0)
	}
	if cmp(float64(a), 0, 0) != 0 {
		return 1
	}
	return 0
}

func polyArea(T polygon) float64 {
	s := 0.0
	n := len(T)
	for i := 0; i < n; i++ {
		s += T[i].cross(T[(i+1)%n])
	}
	return s / 2
}

func computeCentroid(p []point) point {
	c := point{0, 0}
	scale := 6.0 * polyArea(p)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		c = c.add(p[i].add(p[j]).mul(p[i].x*p[j].y - p[j].x*p[i].y))
	}
	return c.div(scale)
}

func radialLt(p, q point) bool {
	P := p.sub(point{0, 0})
	Q := q.sub(point{0, 0})
	R := P.cross(Q)
	if cmp(R, 0, 0) != 0 {
		return R > 0
	}
	return cmp(P.dot(P), Q.dot(Q), 0) < 0
}

func convexHull(T []point) polygon {
	j := 0
	k := 0
	n := len(T)
	U := make(polygon, n)
	pointPivot := minElement(T)
	for i := 0; i < n; i++ {
		if between(T[0], T[n-1], T[i]) {
			k = n - 2
			for k >= 0 && ccw(T[0], T[n-1], T[k]) == 0 {
				k--
			}
			reverse(k+1, T)
			break
		}
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

func polyIntersect(P, Q polygon) polygon {
	m := len(Q)
	n := len(P)
	a := 0
	b := 0
	aa := 0
	ba := 0
	inflag := 0
	R := make(polygon, 0)
	for (aa < n || ba < m) && aa < 2*n && ba < 2*m {
		p1 := P[a]
		p2 := P[(a+1)%n]
		q1 := Q[b]
		q2 := Q[(b+1)%m]
		A := p2.sub(p1)
		B := q2.sub(q1)
		cross := cmp(A.cross(B), 0, 0)
		ha := ccw(p2, q2, p1)
		hb := ccw(q2, p2, q1)
		if cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.dot(B), 0, 0) < 0 {
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
				return polygon{}
			}
			inflag = 1
			break
		} else if cross != 0 && segIntersect(p1, p2, q1, q2) {
			if inflag == 0 {
				aa = 0
				ba = 0
			}
			R = append(R, lineIntersect(p1, p2, q1, q2))
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
		if t && (inflag == 1 || cross >= 0 && ha <= 0 || cross < 0 && hb > 0) {
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
		if inPoly(P[0], Q) == 1 {
			return P
		}
		if inPoly(Q[0], P) == 1 {
			return Q
		}
	}
	R = unique(R)
	if len(R) > 1 && R[0] == R[len(R)-1] {
		R = R[:len(R)-1]
	}
	return R
}

func unique(p polygon) polygon {
	m := make(map[point]bool)
	res := make(polygon, 0)
	for _, val := range p {
		if _, ok := m[val]; !ok {
			m[val] = true
			res = append(res, val)
		}
	}
	return res
}

func minElement(p []point) point {
	minP := p[0]
	for _, val := range p {
		if val.y < minP.y || (val.y == minP.y && val.x < minP.x) {
			minP = val
		}
	}
	return minP
}

func reverse(k int, p []point) {
	for i, j := 0, k; i < j; i, j = i+1, j-1 {
		p[i], p[j] = p[j], p[i]
	}
}

func main() {
	var xp, yp, vp, x, y, v, r int
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R := math.Hypot(float64(yp), float64(xp))
	initial := math.Atan2(float64(yp), float64(xp))
	bot := 0.0
	timeTot := (2 * math.Pi * R) / float64(vp)
	top := 100000000000000.0
	for cmp(top, bot, 0) == 1 {
		mid := (top + bot) / 2
		angle := ((2 * math.Pi * mid) / timeTot) + initial
		loc := point{math.Cos(angle) * R, math.Sin(angle) * R}
		if pode(loc, mid, x, y, v, r) {
			top = mid
		} else {
			bot = mid
		}
	}
	fmt.Printf("%.7f\n", bot)
}

func pode(loc point, time float64, x, y, v, r int) bool {
	nave := point{float64(x), float64(y)}
	if cmp(distancePointSegment(loc, nave, point{0, 0}), float64(r), 0) >= 0 {
		return cmp(time, math.Abs(nave.sub(loc))/float64(v), 0) >= 0
	} else {
		distN := math.Sqrt(dist2(nave, point{0, 0}) - float64(r)*float64(r))
		distL := math.Sqrt(dist2(loc, point{0, 0}) - float64(r)*float64(r))
		a := math.Abs(nave.sub(loc))
		b := math.Abs(nave)
		c := math.Abs(loc)
		bigcos := (b*b + c*c - a*a) / (2 * b * c)
		angNOL := math.Acos(bigcos) - math.Abs(math.Atan(distN/float64(r))) - math.Abs(math.Atan(distL/float64(r)))
		menor := distN + distL + math.Abs(float64(r)*angNOL)
		return cmp(time, menor/float64(v), 0) >= 0
	}
}
