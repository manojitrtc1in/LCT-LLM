package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	MOD = 1000000007
	INF = 10009
	EPS = 1e-2
	PI  = 3.14159265358979323846264
)

type Po struct {
	x, y float64
}

func (p *Po) input() {
	fmt.Scan(&p.x, &p.y)
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

func (a Po) add(b Po) Po {
	return Po{a.x + b.x, a.y + b.y}
}

func (a Po) sub(b Po) Po {
	return Po{a.x - b.x, a.y - b.y}
}

func (a Po) mul(k float64) Po {
	return Po{a.x * k, a.y * k}
}

func (a Po) div(k float64) Po {
	return Po{a.x / k, a.y / k}
}

func dot(a, b Po) float64 {
	return a.x*b.x + a.y*b.y
}

func det(a, b Po) float64 {
	return a.x*b.y - a.y*b.x
}

func distSqr(a, b Po) float64 {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)
}

type Line struct {
	a, b Po
}

type Seg struct {
	a, b Po
}

func (l Line) distSqr(p Po) float64 {
	v0 := l.b.sub(l.a)
	v1 := p.sub(l.a)
	return (det(v0, v1) * det(v0, v1)) / v0.lengthSqr()
}

func isIntersect(l1, l2 Seg) bool {
	return min(l1.a.x, l1.b.x) <= max(l2.a.x, l2.b.x) &&
		min(l2.a.x, l2.b.x) <= max(l1.a.x, l1.b.x) &&
		min(l1.a.y, l1.b.y) <= max(l2.a.y, l2.b.y) &&
		min(l2.a.y, l2.b.y) <= max(l1.a.y, l1.b.y) &&
		sgn(det(l1.a, l2.a, l2.b))*sgn(det(l1.b, l2.a, l2.b)) <= 0 &&
		sgn(det(l2.a, l1.a, l1.b))*sgn(det(l2.b, l1.a, l1.b)) <= 0
}

func sgn(x float64) int {
	if x < -EPS {
		return -1
	} else if x > EPS {
		return 1
	}
	return 0
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

func intersect(l1, l2 Line) Po {
	return l1.a.add(l1.b.sub(l1.a).mul(det(l2.a, l1.a, l2.b) / det(l2, l1)))
}

func rotate(p Po, alpha float64, o Po) Po {
	p = p.sub(o)
	return Po{
		p.x*math.Cos(alpha) - p.y*math.Sin(alpha) + o.x,
		p.y*math.Cos(alpha) + p.x*math.Sin(alpha) + o.y,
	}
}

func f(x float64, theta, R_, R, r, ss, vs, vp float64) bool {
	theta = math.Mod(theta, 2*PI)
	if theta < 0 {
		theta += 2 * PI
	}
	d := func() float64 {
		if theta <= beta || theta >= 2*PI-beta {
			return math.Sqrt(R_*R_ + R*R - 2*R_*R*math.Cos(theta))
		} else {
			delta := PI - beta - math.Abs(PI-theta)
			return ss + delta*r
		}
	}()
	return d <= vs*x
}

func main() {
	var s, p Po
	var vp, vs, r float64
	s.input()
	fmt.Scan(&vp)
	p.input()
	fmt.Scan(&vs, &r)

	R_ := s.length()
	R := p.length()
	vp /= R
	ss := math.Sqrt(R_*R_ - r*r) + math.Sqrt(R*R - r*r)
	alpha := p.atan() - s.atan()
	alpha = math.Mod(alpha, 2*PI)
	beta := math.Acos(r/R_) + math.Acos(r/R)
	beta = math.Mod(beta, 2*PI)

	ll, rr := 0.0, (ss+PI*R)*vs
	for i := 0; i < 100; i++ {
		m := (ll + rr) / 2
		if f(m, alpha, R_, R, r, ss, vs, vp) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
