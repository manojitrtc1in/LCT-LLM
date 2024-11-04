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
	OO  = 1e15
	PI  = 3.14159265358979323846264
	N   = 100009
)

type Po struct {
	x, y float64
}

func (p *Po) input() {
	fmt.Scan(&p.x, &p.y)
}

func (p Po) length() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p Po) atan() float64 {
	return math.Atan2(p.y, p.x)
}

func (p Po) subtract(q Po) Po {
	return Po{p.x - q.x, p.y - q.y}
}

func (p Po) add(q Po) Po {
	return Po{p.x + q.x, p.y + q.y}
}

func (p Po) multiply(k float64) Po {
	return Po{p.x * k, p.y * k}
}

func (p Po) lengthSqr() float64 {
	return p.x*p.x + p.y*p.y
}

func sgn(x float64) int {
	if x < -EPS {
		return -1
	} else if x > EPS {
		return 1
	}
	return 0
}

func fmod(x, mod float64) float64 {
	x = math.Mod(x, mod)
	if x < 0 {
		x += mod
	}
	return x
}

func d(theta, R_, R, r, ss, vs, vp float64) float64 {
	var delta float64
	if theta <= beta || theta >= 2*PI-beta {
		return math.Sqrt(R_*R_ + R*R - 2*R_*R*math.Cos(theta))
	} else {
		delta = PI - beta - math.Abs(PI-theta)
		return ss + delta*r
	}
}

func f(theta, vp, vs, R_, R, r, ss float64) bool {
	theta = fmod(theta*vp+alpha, 2*PI)
	return d(theta, R_, R, r, ss, vs, vp) <= vs*theta
}

var (
	s, p, o Po
	R_, R, r, ss, vs, vp float64
	alpha, beta, theta, delta float64
)

func main() {
	s.input()
	fmt.Scan(&vp)
	p.input()
	fmt.Scan(&vs, &r)

	R_ = s.length()
	R = p.length()
	vp /= R
	ss = math.Sqrt(R_*R_ - r*r) + math.Sqrt(R*R - r*r)
	alpha = p.atan() - s.atan()
	alpha = fmod(alpha, 2*PI)
	beta = math.Acos(r/R_) + math.Acos(r/R)
	beta = fmod(beta, 2*PI)

	ll := 0.0
	rr := (ss + PI*R) * vs

	for i := 0; i < 200; i++ {
		m := (ll + rr) / 2
		if f(m, vp, vs, R_, R, r, ss) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
