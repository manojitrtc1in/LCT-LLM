package main

import (
	"fmt"
	"math"
)

const EPS = 1e-8

func cmp(x, y, tol float64) int {
	if x <= y+tol {
		if x+tol < y {
			return -1
		}
		return 0
	}
	return 1
}

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

func (p point) cmp(q point) int {
	if t := cmp(p.x, q.x, EPS); t != 0 {
		return t
	}
	return cmp(p.y, q.y, EPS)
}

func (p point) equal(q point) bool {
	return p.cmp(q) == 0
}

func (p point) less(q point) bool {
	return p.cmp(q) < 0
}

func (p point) String() string {
	return fmt.Sprintf("(%.7f, %.7f)", p.x, p.y)
}

type polygon []point

type circle struct {
	center point
	radius float64
}

func ccw(p, q, r point) int {
	return cmp((p.sub(r)).cross(q.sub(r)))
}

func angle(p, q, r point) float64 {
	u := p.sub(q)
	v := r.sub(q)
	return math.Atan2(u.cross(v), u.dot(v))
}

func dist2(p, q point) float64 {
	return (p.sub(q)).dot(p.sub(q))
}

func id19(p point) point {
	return point{-p.y, p.x}
}

func id5(p point) point {
	return point{p.y, -p.x}
}

func id14(p point, t float64) point {
	cosT := math.Cos(t)
	sinT := math.Sin(t)
	return point{p.x*cosT - p.y*sinT, p.x*sinT + p.y*cosT}
}

func id9(a, b, c point) point {
	return a.add(b.sub(a).mul(c.sub(a).dot(b.sub(a))) / b.sub(a).dot(b.sub(a)))
}

func id20(a, b, c point) point {
	r := b.sub(a).dot(b.sub(a))
	if math.Abs(r) < EPS {
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
	return ccw(p, q, r) == 0 && cmp((p.sub(q)).dot(r.sub(q)), 0, EPS) <= 0
}

func id10(a, b, c point) float64 {
	return math.Sqrt(dist2(c, id20(a, b, c)))
}

func id2(x, y, z, a, b, c, d float64) float64 {
	return math.Abs(a*x+b*y+c*z-d) / math.Sqrt(a*a+b*b+c*c)
}

func linesParallel(a, b, c, d point) bool {
	return math.Abs((b.sub(a)).cross(c.sub(d))) < EPS
}

func id0(a, b, c, d point) bool {
	return linesParallel(a, b, c, d) &&
		math.Abs((a.sub(b)).cross(a.sub(c))) < EPS &&
		math.Abs((c.sub(d)).cross(c.sub(a))) < EPS
}

func id13(p, q, r, s point) bool {
	A := q.sub(p)
	B := s.sub(r)
	C := r.sub(p)
	D := s.sub(q)
	a := cmp(A.cross(C)) + 2*cmp(A.cross(D))
	b := cmp(B.cross(C)) + 2*cmp(B.cross(D))
	if a == 3 || a == -3 || b == 3 || b == -3 {
		return false
	}
	if a != 0 || b != 0 || p.equal(r) || p.equal(s) || q.equal(r) || q.equal(s) {
		return true
	}
	t := cmp(p, r)
	t += cmp(p, s)
	t += cmp(q, r)
	t += cmp(q, s)
	return t != 0 && t != 4
}

func id8(p, q, r, s point) point {
	a := q.sub(p)
	b := s.sub(r)
	c := point{p.cross(q), r.cross(s)}
	return point{point{a.x, b.x}.cross(c), point{a.y, b.y}.cross(c)}.div(a.cross(b))
}

func id1(p1, p2 point, r float64) (point, bool) {
	d2 := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	det := (r*r)/d2 - 0.25
	if det < 0.0 {
		return point{}, false
	}
	h := math.Sqrt(det)
	c := point{(p1.x + p2.x) * 0.5 + (p1.y-p2.y)*h, (p1.y + p2.y) * 0.5 + (p2.x-p1.x)*h}
	return c, true
}

func id4(a, b, c point) point {
	b = a.add(b).div(2)
	c = a.add(c).div(2)
	return id8(b, b.add(id5(a.sub(b))), c, c.add(id5(a.sub(c))))
}

func id18(a, b, c point) point {
	d := b.add(id14(c.sub(b), angle(c, b, a)/2))
	e := c.add(id14(a.sub(c), angle(a, c, b)/2))
	return id8(b, d, c, e)
}

func id11(a, b, c point, r float64) []point {
	var ret []point
	b = b.sub(a)
	a = a.sub(c)
	A := b.dot(b)
	B := a.dot(b)
	C := a.dot(a) - r*r
	D := B*B - A*C
	if D < -EPS {
		return ret
	}
	ret = append(ret, c.add(a).add(b.mul((-B+math.Sqrt(D+EPS))/A)))
	if D > EPS {
		ret = append(ret, c.add(a).add(b.mul((-B-math.Sqrt(D))/A)))
	}
	return ret
}

func id3(a, b point, r, R float64) []point {
	var ret []point
	d := math.Sqrt(dist2(a, b))
	if d > r+R || d+math.Min(r, R) < math.Max(r, R) {
		return ret
	}
	x := (d*d - R*R + r*r) / (2 * d)
	y := math.Sqrt(r*r - x*x)
	v := b.sub(a).div(d)
	ret = append(ret, a.add(v.mul(x)).add(id19(v).mul(y)))
	if y > 0 {
		ret = append(ret, a.add(v.mul(x)).sub(id19(v).mul(y)))
	}
	return ret
}

func id7(c point, r float64, p point) []point {
	var resp []point
	toCenter := c.sub(p)
	if cmp(r-math.Sqrt(dist2(toCenter, point{})), 0, EPS) <= 0 {
		resp = append(resp, p)
		resp = append(resp, p)
		return resp
	}
	angle := math.Asin(r / math.Sqrt(dist2(toCenter, point{})))
	uni := toCenter.div(math.Sqrt(dist2(toCenter, point{})))
	tam := math.Sqrt(dist2(toCenter, point{}) - r*r)
	origi := uni.mul(tam)
	p1 := p.add(id14(origi, angle))
	resp = append(resp, p1)
	p2 := p.add(id14(origi, -angle))
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
		a += ccw(T[i], p, T[(i+1)%N])
	}
	if cmp(float64(a)) != 0 {
		return cmp(float64(a))
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

func id17(p []point) point {
	c := point{}
	scale := 6.0 * polyArea(p)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		c = c.add(p[i].add(p[j]).mul(p[i].x*p[j].y - p[j].x*p[i].y))
	}
	return c.div(scale)
}

func id6(p, q point) bool {
	P := p.sub(point{})
	Q := q.sub(point{})
	R := P.cross(Q)
	if cmp(R) != 0 {
		return R > 0
	}
	return cmp(P.dot(P), Q.dot(Q)) < 0
}

func id15(T []point) polygon {
	j := 0
	k := 0
	n := len(T)
	U := make(polygon, n)
	pointPivot := minElement(T)
	sortPoints(T, id6)
	for k = n - 2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k-- {
	}
	reversePoints(T, k+1)
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

func id16(P, Q polygon) polygon {
	m := len(Q)
	n := len(P)
	a := 0
	b := 0
	aa := 0
	ba := 0
	inflag := 0
	var R polygon
	for (aa < n || ba < m) && aa < 2*n && ba < 2*m {
		p1 := P[a]
		p2 := P[(a+1)%n]
		q1 := Q[b]
		q2 := Q[(b+1)%m]
		A := p2.sub(p1)
		B := q2.sub(q1)
		cross := cmp(A.cross(B))
		ha := ccw(p2, q2, p1)
		hb := ccw(q2, p2, q1)
		if cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.dot(B), 0, EPS) < 0 {
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
		} else if cross != 0 && id13(p1, p2, q1, q2) {
			if inflag == 0 {
				aa = 0
				ba = 0
			}
			R = append(R, id8(p1, p2, q1, q2))
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
		if inPoly(P[0], Q) != 0 {
			return P
		}
		if inPoly(Q[0], P) != 0 {
			return Q
		}
	}
	R = uniquePoints(R)
	if len(R) > 1 && R[0].equal(R[len(R)-1]) {
		R = R[:len(R)-1]
	}
	return R
}

func minElement(T []point) point {
	minP := T[0]
	for _, p := range T {
		if p.less(minP) {
			minP = p
		}
	}
	return minP
}

func sortPoints(T []point, less func(point, point) bool) {
	for i := 0; i < len(T); i++ {
		for j := i + 1; j < len(T); j++ {
			if less(T[j], T[i]) {
				T[i], T[j] = T[j], T[i]
			}
		}
	}
}

func reversePoints(T []point, k int) {
	for i, j := 0, k; i < j; i, j = i+1, j-1 {
		T[i], T[j] = T[j], T[i]
	}
}

func uniquePoints(T []point) []point {
	n := len(T)
	if n <= 1 {
		return T
	}
	j := 0
	for i := 1; i < n; i++ {
		if !T[j].equal(T[i]) {
			j++
			T[j] = T[i]
		}
	}
	return T[:j+1]
}

func main() {
	var xp, yp, vp, x, y, v, r int
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	R := math.Hypot(float64(yp), float64(xp))
	initial := math.Atan2(float64(yp), float64(xp))
	bot := 0.0
	timeTot := (2 * math.Pi * R) / float64(vp)
	top := 100000000000000.0
	for cmp(top, bot, EPS) == 1 {
		mid := (top + bot) / 2
		angle := (2*math.Pi*mid)/timeTot + initial
		loc := point{math.Cos(angle) * R, math.Sin(angle) * R}
		if pode(loc, mid) {
			top = mid
		} else {
			bot = mid
		}
	}
	fmt.Printf("%.7f\n", bot)
}
