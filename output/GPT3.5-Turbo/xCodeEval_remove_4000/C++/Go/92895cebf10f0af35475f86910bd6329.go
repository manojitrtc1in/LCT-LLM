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

func id1(p, l Seg) float64 {
	v0 := l.b.sub(l.a)
	v1 := p.sub(l.a)
	v2 := p.sub(l.b)
	if sgn(dot(v0, v1))*sgn(dot(v0, v2)) <= 0 {
		return id1(p, Line{l.a, l.b})
	} else {
		return math.Min(v1.lengthSqr(), v2.lengthSqr())
	}
}

func id1(l1, l2 Seg) float64 {
	if isIntersect(l1, l2) {
		return 0
	} else {
		return math.Min(id1(l1.a, l2), math.Min(id1(l1.b, l2), math.Min(id1(l2.a, l1), id1(l2.b, l1))))
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

func sgn(x float64) int {
	if x < -1e-2 {
		return -1
	} else if x > 1e-2 {
		return 1
	}
	return 0
}

func (p Po) sub(q Po) Po {
	return Po{p.x - q.x, p.y - q.y}
}

func (p Po) lengthSqr() float64 {
	return p.x*p.x + p.y*p.y
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
	return fmt.Sprintf("%s-%s", l.a, l.b)
}

func (s Seg) String() string {
	return fmt.Sprintf("%s-%s", s.a, s.b)
}

func main() {
	var p, s Po
	var vp, vs, r float64
	fmt.Scan(&p.x, &p.y, &vp, &s.x, &s.y, &vs, &r)

	R_ := s.length()
	R := p.length()
	vp /= R
	ss := math.Sqrt(math.Pow(R_, 2)-math.Pow(r, 2)) + math.Sqrt(math.Pow(R, 2)-math.Pow(r, 2))
	alpha := p.atan() - s.atan()
	beta := math.Acos(r/R_) + math.Acos(r/R)

	ll := 0.0
	rr := (ss + math.Pi*R) * vs
	for i := 0; i < 200; i++ {
		m := (ll + rr) / 2
		if f(m, alpha, beta, vp, vs, r, R_, R, ss) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10lf\n", ll)
}

func f(x, alpha, beta, vp, vs, r, R_, R, ss float64) bool {
	theta := x*vp + alpha
	_R(&theta)
	return d(theta, beta, R_, R, r, ss) <= vs*x
}

func _R(x *float64) {
	*x = math.Mod(*x, 2*math.Pi)
	if *x < 0 {
		*x += 2 * math.Pi
	}
}

func d(theta, beta, R_, R, r, ss float64) float64 {
	if theta <= beta || theta >= 2*math.Pi-beta {
		return math.Sqrt(math.Pow(R_, 2) + math.Pow(R, 2) - 2*R_*R*math.Cos(theta))
	} else {
		delta := math.Pi - beta - math.Abs(math.Pi-theta)
		return ss + delta*r
	}
}

func sgn(x float64) int {
	if x < -1e-2 {
		return -1
	} else if x > 1e-2 {
		return 1
	}
	return 0
}
