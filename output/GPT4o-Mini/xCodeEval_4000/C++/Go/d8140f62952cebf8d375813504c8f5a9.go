package main

import (
	"fmt"
	"math"
	"os"
)

const (
	MOD = 1000000007
	PI  = 3.14159265358979323846264
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

func fmod(x, mod float64) float64 {
	x = math.Mod(x, mod)
	if x < 0 {
		x += mod
	}
	return x
}

func d(R_, R, r, theta, ss, vs, vp float64) float64 {
	beta := math.Acos(r / R_)
	if theta <= beta || theta >= 2*PI-beta {
		return math.Sqrt(R_*R_ + R*R - 2*R_*R*math.Cos(theta))
	} else {
		delta := PI - beta - math.Abs(PI-theta)
		return ss + delta*r
	}
}

func f(x, R_, R, r, ss, vs, vp float64) bool {
	theta := fmod(x*vp+alpha, 2*PI)
	return d(R_, R, r, theta, ss, vs, vp) <= vs*x
}

var (
	s, p, o Po
	R_, R, r, ss, vs, vp float64
	alpha, beta, theta, delta float64
)

func main() {
	if len(os.Args) > 1 {
		file, err := os.Open(os.Args[1])
		if err != nil {
			fmt.Println(err)
			return
		}
		defer file.Close()
		fmt.Scan(file)
	}

	p.input()
	fmt.Scan(&vp)
	s.input()
	fmt.Scan(&vs, &r)

	R_ = s.length()
	R = p.length()
	vp /= R
	ss = math.Sqrt(R_*R_ - r*r) + math.Sqrt(R*R - r*r)
	alpha = p.atan() - s.atan()
	alpha = fmod(alpha, 2*PI)
	beta = math.Acos(r/R_) + math.Acos(r/R)
	beta = fmod(beta, 2*PI)

	ll, rr := 0.0, 1e10
	for i := 0; i < 1000; i++ {
		m := (ll + rr) / 2
		if f(m, R_, R, r, ss, vs, vp) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
