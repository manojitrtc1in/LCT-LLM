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

func f(x, theta, vp, vs, R_, R, r, ss float64) bool {
	theta = fmod(x*vp+alpha, 2*PI)
	return d(theta, R_, R, r, ss, vs, x) <= vs*x
}

var (
	s, p, o          Po
	R_, R, r, ss, vs float64
	alpha, beta      float64
)

func main() {
	file, err := os.Open("in.txt")
	if err != nil {
		fmt.Println(err)
		return
	}
	defer file.Close()

	_, err = fmt.Fscanf(file, "%f %f\n", &p.x, &p.y)
	if err != nil {
		fmt.Println(err)
		return
	}
	var vp float64
	_, err = fmt.Fscanf(file, "%f\n", &vp)
	if err != nil {
		fmt.Println(err)
		return
	}
	_, err = fmt.Fscanf(file, "%f %f\n", &s.x, &s.y)
	if err != nil {
		fmt.Println(err)
		return
	}
	_, err = fmt.Fscanf(file, "%f %f\n", &vs, &r)
	if err != nil {
		fmt.Println(err)
		return
	}

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
		if f(m, alpha, vp, vs, R_, R, r, ss) {
			rr = m
		} else {
			ll = m
		}
	}
	fmt.Printf("%.10f\n", ll)
}
