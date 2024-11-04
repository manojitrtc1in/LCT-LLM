package main

import (
	"fmt"
	"math"
)

type Po struct {
	x, y float64
}

type Line struct {
	a, b Po
}

type Seg struct {
	a, b Po
}

func dot(x1, y1, x2, y2 float64) float64 {
	return x1*x2 + y1*y2
}

func dotPo(a, b Po) float64 {
	return dot(a.x, a.y, b.x, b.y)
}

func dotLine(l1, l2 Line) float64 {
	return dot(l1.b.x-l1.a.x, l1.b.y-l1.a.y, l2.b.x-l2.a.x, l2.b.y-l2.a.y)
}

func det(x1, y1, x2, y2 float64) float64 {
	return x1*y2 - x2*y1
}

func detPo(a, b Po) float64 {
	return det(a.x, a.y, b.x, b.y)
}

func detLine(l1, l2 Line) float64 {
	return det(l1.b.x-l1.a.x, l1.b.y-l1.a.y, l2.b.x-l2.a.x, l2.b.y-l2.a.y)
}

func isIntersect(l1, l2 Seg) bool {
	return min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
		min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
		min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
		min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
		sgn(det(l1.a, l2.a, l2.b))*sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
		sgn(det(l2.a, l1.a, l1.b))*sgn(det(l2.b, l1.a, l1.b)) <= 0
}

func id1(p Po, l Line) float64 {
	v0 := l.b.sub(l.a)
	v1 := p.sub(l.a)
	return sqr(fabs(det(v0, v1))) / v0.lengthSqr()
}

func id1Seg(p Po, l Seg) float64 {
	v0 := l.b.sub(l.a)
	v1 := p.sub(l.a)
	v2 := p.sub(l.b)
	if sgn(dot(v0, v1))*sgn(dot(v0, v2)) <= 0 {
		return id1(p, Line{l.a, l.b})
	} else {
		return min(v1.lengthSqr(), v2.lengthSqr())
	}
}

func id1Line(l1, l2 Line) float64 {
	if sgn(det(l1, l2)) != 0 {
		return 0
	}
	return id1(l1.a, l2)
}

func id1SegLine(l1 Seg, l2 Line) float64 {
	v0 := l1.b.sub(l1.a)
	v1 := l2.a.sub(l1.a)
	v2 := l2.b.sub(l1.a)
	c1 := det(v0, v1)
	c2 := det(v0, v2)
	if sgn(c1) != sgn(c2) {
		return 0
	} else {
		return sqr(min(fabs(c1), fabs(c2))) / v0.lengthSqr()
	}
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func fabs(x float64) float64 {
	if x < 0 {
		return -x
	}
	return x
}

func sqr(x float64) float64 {
	return x * x
}

func sgn(x float64) int {
	if x < -EPS {
		return -1
	} else if x > EPS {
		return 1
	} else {
		return 0
	}
}

func sgn2(x, y float64) int {
	return sgn(x - y)
}

func sgnPo(a, b Po) int {
	return sgn2(a.x, b.x) + sgn2(a.y, b.y)
}

func (p Po) sub(q Po) Po {
	return Po{p.x - q.x, p.y - q.y}
}

func (p Po) lengthSqr() float64 {
	return sqr(p.x) + sqr(p.y)
}

func (p Po) length() float64 {
	return math.Sqrt(p.lengthSqr())
}

func (p Po) atan() float64 {
	return math.Atan2(p.y, p.x)
}

func (p Po) String() string {
	return fmt.Sprintf("(%.10lf, %.10lf)", p.x, p.y)
}

func (l Line) String() string {
	return fmt.Sprintf("%v-%v", l.a, l.b)
}

func (s Seg) String() string {
	return fmt.Sprintf("%v-%v", s.a, s.b)
}

func (p *Po) input() {
	fmt.Scanf("%lf %lf", &p.x, &p.y)
}

func (l Line) intersect() Po {
	return l.a.add(l.b.sub(l.a).mul(det(l.a.sub(o), l.b.sub(o))) / det(l.a.sub(o), l.b.sub(o)))
}

func (p Po) add(q Po) Po {
	return Po{p.x + q.x, p.y + q.y}
}

func (p Po) mul(k float64) Po {
	return Po{p.x * k, p.y * k}
}

func (p Po) div(k float64) Po {
	return Po{p.x / k, p.y / k}
}

func (p Po) neg() Po {
	return Po{-p.x, -p.y}
}

func (p Po) less(rhs Po) bool {
	return sgn(p.x, rhs.x) < 0 || (sgn(p.x, rhs.x) == 0 && sgn(p.y, rhs.y) < 0)
}

func (p Po) equal(rhs Po) bool {
	return sgn(p.x-rhs.x) == 0 && sgn(p.y-rhs.y) == 0
}

func (p Po) rotate(alpha float64, o Po) Po {
	p.x -= o.x
	p.y -= o.y
	return Po{p.x*math.Cos(alpha) - p.y*math.Sin(alpha), p.y*math.Cos(alpha) + p.x*math.Sin(alpha)}.add(o)
}

func (l Line) intersect(p Po) Po {
	return l.a.add(l.b.sub(l.a).mul(det(p.sub(l.a), p.sub(l.b))) / det(l.a.sub(l.b), p.sub(l.b)))
}

func (l Line) equal(rhs Line) bool {
	return l.a.equal(rhs.a) && l.b.equal(rhs.b)
}

func (s Seg) equal(rhs Seg) bool {
	return s.a.equal(rhs.a) && s.b.equal(rhs.b)
}

func (s Seg) length() float64 {
	return s.b.sub(s.a).length()
}

func (s Seg) String() string {
	return fmt.Sprintf("%v-%v", s.a, s.b)
}

func (s Seg) intersect(rhs Seg) bool {
	return isIntersect(s, rhs)
}

func (s Seg) id1(p Po) float64 {
	return id1Seg(p, s)
}

func (s Seg) id2(p Po) bool {
	return sgn(det(p, s.a, s.b)) == 0 &&
		sgn(s.a.x, p.x)*sgn(s.b.x, p.x) <= 0 &&
		sgn(s.a.y, p.y)*sgn(s.b.y, p.y) <= 0
}

func (s Seg) id0(p Po) bool {
	return p.equal(s.a) || p.equal(s.b)
}

const (
	EPS = 1e-2
	PI  = math.Pi
)

var (
	s, p, o Po
	R_, R, r, ss, vs, vp float64
	alpha, beta, theta, delta float64
)

func f(x float64) bool {
	theta = x*vp + alpha
	_R(theta)
	return d() <= vs*x
}

func _R(x *float64) {
	*x = math.Mod(*x, 2*PI)
	if *x < 0 {
		*x += 2 * PI
	}
}

func d() float64 {
	if theta <= beta || theta >= 2*PI-beta {
		return math.Sqrt(sqr(R_)+sqr(R)-2*R_*R*math.Cos(theta))
	} else {
		delta = PI - beta - fabs(PI-theta)
		return ss + delta*r
	}
}

func main() {
	p.input()
	fmt.Scanf("%lf", &vp)
	s.input()
	fmt.Scanf("%lf %lf", &vs, &r)

	R_ = s.length()
	R = p.length()
	vp /= R
	ss = math.Sqrt(sqr(R_)-sqr(r)) + math.Sqrt(sqr(R)-sqr(r))
	alpha = p.atan() - s.atan()
	_R(&alpha)
	beta = math.Acos(r / R_) + math.Acos(r / R)
	_R(&beta)

	ll := 0.0
	rr := (ss + PI*R) * vs
	for i := 0; i < 100; i++ {
		m := (ll + rr) / 2
		if f(m) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10lf\n", ll)
}
