package main

import (
	"fmt"
	"math"
	"sort"
)

const INF = 10000000
const EPS = 1e-8

func cmp(x, y float64) int {
	if x <= y+EPS {
		if x+EPS < y {
			return -1
		}
		return 0
	}
	return 1
}

type point struct {
	x, y float64
}

func newPoint(x, y float64) point {
	return point{x: x, y: y}
}

func (p point) add(q point) point {
	return newPoint(p.x+q.x, p.y+q.y)
}

func (p point) sub(q point) point {
	return newPoint(p.x-q.x, p.y-q.y)
}

func (p point) mul(t float64) point {
	return newPoint(p.x*t, p.y*t)
}

func (p point) div(t float64) point {
	return newPoint(p.x/t, p.y/t)
}

func (p point) dot(q point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p point) cross(q point) float64 {
	return p.x*q.y - p.y*q.x
}

func (p point) cmp(q point) int {
	if t := cmp(p.x, q.x); t != 0 {
		return t
	}
	return cmp(p.y, q.y)
}

func (p point) equal(q point) bool {
	return p.cmp(q) == 0
}

func (p point) notEqual(q point) bool {
	return p.cmp(q) != 0
}

func (p point) less(q point) bool {
	return p.cmp(q) < 0
}

func (p point) String() string {
	return fmt.Sprintf("(%f, %f)", p.x, p.y)
}

var pivot point

func abs(p point) float64 {
	return math.Hypot(p.x, p.y)
}

func arg(p point) float64 {
	return math.Atan2(p.y, p.x)
}

type polygon []point
type circle struct {
	center point
	radius float64
}

func ccw(p, q, r point) int {
	return cmp((p.sub(r)).cross(q.sub(r)), 0)
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
	return newPoint(-p.y, p.x)
}

func id5(p point) point {
	return newPoint(p.y, -p.x)
}

func id14(p point, t float64) point {
	return newPoint(p.x*math.Cos(t)-p.y*math.Sin(t), p.x*math.Sin(t)+p.y*math.Cos(t))
}

func id9(a, b, c point) point {
	return a.add(b.sub(a).mul((c.sub(a).dot(b.sub(a))) / (b.sub(a).dot(b.sub(a)))))
}

func id20(a, b, c point) point {
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

func between(p, q, r point) bool {
	return ccw(p, q, r) == 0 && cmp((p.sub(q)).cross(r.sub(q)), 0) <= 0
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
	a := cmp(A.cross(C), 0) + 2*cmp(A.cross(D), 0)
	b := cmp(B.cross(C), 0) + 2*cmp(B.cross(D), 0)
	if a == 3 || a == -3 || b == 3 || b == -3 {
		return false
	}
	if a != 0 || b != 0 || p.equal(r) || p.equal(s) || q.equal(r) || q.equal(s) {
		return true
	}
	t := 0
	if p.less(r) {
		t++
	}
	if p.less(s) {
		t++
	}
	if q.less(r) {
		t++
	}
	if q.less(s) {
		t++
	}
	return t != 0 && t != 4
}

func id8(p, q, r, s point) point {
	a := q.sub(p)
	b := s.sub(r)
	c := point{p.cross(q), r.cross(s)}
	return point{(a.x*b.x*c.x + a.y*b.y*c.y) / (a.cross(b)), (a.x*b.x*c.y + a.y*b.y*c.x) / (a.cross(b))}
}

func id1(p1, p2 point, r float64, c *point) bool {
	d2 := (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)
	det := (r * r / d2) - 0.25
	if det < 0.0 {
		return false
	}
	h := math.Sqrt(det)
	c.x = (p1.x + p2.x)*0.5 + (p1.y-p2.y)*h
	c.y = (p1.y + p2.y)*0.5 + (p2.x-p1.x)*h
	return true
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
	C := (a.dot(a)) - r*r
	D := B*B - A*C
	if D < -EPS {
		return ret
	}
	ret = append(ret, c.add(a).add(b.mul((-B + math.Sqrt(D+EPS)) / A)))
	if D > EPS {
		ret = append(ret, c.add(a).add(b.mul((-B - math.Sqrt(D)) / A)))
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
	if cmp(r-sqrt(dist2(toCenter, newPoint(0, 0)))) <= 0 {
		resp = append(resp, p, p)
		return resp
	}
	angle := math.Asin(r / sqrt(dist2(toCenter, newPoint(0, 0))))
	uni := toCenter.div(sqrt(dist2(toCenter, newPoint(0, 0))))
	tam := sqrt(dist2(toCenter, newPoint(0, 0))) - r*r
	origi := uni.mul(tam)
	p1 := p.add(id14(origi, angle))
	resp = append(resp, p1)
	p2 := p.add(id14(origi, -angle))
	resp = append(resp, p2)
	return resp
}

func inPoly(p point, T polygon) int {
	a := 0.0
	N := len(T)
	for i := 0; i < N; i++ {
		if between(T[i], p, T[(i+1)%N]) {
			return -1
		}
		a += angle(T[i], p, T[(i+1)%N])
	}
	return cmp(a, 0) != 0
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
	c := newPoint(0, 0)
	scale := 6.0 * polyArea(p)
	for i := 0; i < len(p); i++ {
		j := (i + 1) % len(p)
		c = c.add(p[i].add(p[j]).mul(p[i].x*p[j].y - p[j].x*p[i].y))
	}
	return c.div(scale)
}

func id6(p, q point) bool {
	P := p.sub(pivot)
	Q := q.sub(pivot)
	R := P.cross(Q)
	if cmp(R, 0) != 0 {
		return R > 0
	}
	return cmp(P.dot(P), Q.dot(Q)) < 0
}

func id15(T []point) polygon {
	j := 0
	k := 0
	n := len(T)
	U := make(polygon, n)
	pivot = T[0]
	sort.Slice(T, func(i, j int) bool {
		return id6(T[i], T[j])
	})
	for k = n - 2; k >= 0 && ccw(T[0], T[n-1], T[k]) == 0; k-- {
	}
	reverse(T[k+1:])
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
	a, b, aa, ba, inflag := 0, 0, 0, 0, 0
	var R polygon
	for (aa < n || ba < m) && aa < 2*n && ba < 2*m {
		p1 := P[a]
		p2 := P[(a+1)%n]
		q1 := Q[b]
		q2 := Q[(b+1)%m]
		A := p2.sub(p1)
		B := q2.sub(q1)
		cross := cmp(A.cross(B), 0)
		ha := ccw(p2, q2, p1)
		hb := ccw(q2, p2, q1)
		if cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A.dot(B), 0) < 0 {
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
				aa = ba = 0
			}
			R = append(R, id8(p1, p2, q1, q2))
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
	R = unique(R)
	if len(R) > 1 && R[0].equal(R[len(R)-1]) {
		R = R[:len(R)-1]
	}
	return R
}

const PI = math.Acos(-1)

var xp, yp, vp, x, y, v, r int

var origin = newPoint(0, 0)

func pode(loc point, time float64) bool {
	nave := newPoint(float64(x), float64(y))
	if cmp(id10(loc, nave, origin), float64(r)) >= 0 {
		return cmp(time, abs(nave.sub(loc))/float64(v)) >= 0
	} else {
		distN := math.Sqrt(dist2(nave, origin) - float64(r)*float64(r))
		distL := math.Sqrt(dist2(loc, origin) - float64(r)*float64(r))
		id12 := math.Abs(angle(nave, origin, loc)) - math.Abs(math.Atan(distN/float64(r))) - math.Abs(math.Atan(distL/float64(r)))
		menor := distN + distL + math.Abs(float64(r)*id12)
		return cmp(time, menor/float64(v)) >= 0
	}
}

func main() {
	fmt.Scan(&xp, &yp, &vp, &x, &y, &v, &r)
	cont := 1000000
	R := math.Hypot(float64(yp), float64(xp))
	initial := math.Atan2(float64(yp), float64(xp))
	bot := 0.0
	timeTot := 1000000.0
	t1 := (2 * PI * R) / float64(vp)

	top := timeTot
	for top-bot > EPS {
		mid := (top + bot) / 2

		angle := ((2 * PI * mid) / t1) + initial
		loc := newPoint(math.Cos(angle)*R, math.Sin(angle)*R)

		if pode(loc, mid) {
			top = mid - EPS
		} else {
			bot = mid + EPS
		}
	}
	fmt.Printf("%.7f\n", bot)
}
