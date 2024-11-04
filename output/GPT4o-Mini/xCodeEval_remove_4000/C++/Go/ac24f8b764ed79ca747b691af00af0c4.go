package main

import (
	"fmt"
	"math"
	"os"
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

func fmod(x float64) float64 {
	x = math.Mod(x, 2*PI)
	if x < 0 {
		x += 2 * PI
	}
	return x
}

func d(R_, R, r, ss, vs, vp, theta, beta float64) float64 {
	if theta <= beta || theta >= 2*PI-beta {
		return math.Sqrt(R_*R_ + R*R - 2*R_*R*math.Cos(theta))
	} else {
		delta := PI - beta - math.Abs(PI-theta)
		return ss + delta*r
	}
}

func f(x, R_, R, r, ss, vs, vp, alpha, beta float64) bool {
	theta := x*vp + alpha
	theta = fmod(theta)
	return d(R_, R, r, ss, vs, vp, theta, beta) <= vs*x
}

func main() {
	file, _ := os.Open("in.txt")
	defer file.Close()
	fmt.Scan(file)

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
	alpha = fmod(alpha)
	beta := math.Acos(r/R_) + math.Acos(r/R)
	beta = fmod(beta)

	ll, rr := 0.0, (ss+PI*R)*vs
	for i := 0; i < 100; i++ {
		m := (ll + rr) / 2
		if f(m, R_, R, r, ss, vs, vp, alpha, beta) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
