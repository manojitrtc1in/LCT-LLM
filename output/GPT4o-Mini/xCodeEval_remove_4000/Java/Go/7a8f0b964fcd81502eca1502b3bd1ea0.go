package main

import (
	"fmt"
	"math"
	"os"
	"sync"
)

const EPS = 1e-7

type id9 struct {
	x, y float64
}

func (p *id9) set(x, y float64) *id9 {
	p.x = x
	p.y = y
	return p
}

func (p *id9) add(v *id9) *id9 {
	return &id9{p.x + v.x, p.y + v.y}
}

func (p *id9) sub(v *id9) *id9 {
	return &id9{p.x - v.x, p.y - v.y}
}

func (p *id9) len() float64 {
	return sqrt(p.x*p.x + p.y*p.y)
}

func (p *id9) rotate(cos, sin float64) *id9 {
	return &id9{p.x*cos - p.y*sin, p.x*sin + p.y*cos}
}

type id5 struct {
	p1, p2 *id9
	A, B, C float64
}

func (l *id5) set(p1, p2 *id9) *id5 {
	l.p1 = p1
	l.p2 = p2
	l.A = p2.y - p1.y
	l.B = p1.x - p2.x
	l.C = -(l.A*p1.x + l.B*p1.y)
	return l
}

type id6 struct {
	c *id9
	r float64
}

func (c *id6) set(center *id9, radius float64) *id6 {
	c.c = center
	c.r = radius
	return c
}

var wg sync.WaitGroup

func main() {
	wg.Add(1)
	go func() {
		defer wg.Done()
		run()
	}()
	wg.Wait()
}

func run() {
	var xp, yp, vP, vs float64
	fmt.Scan(&xp, &yp)
	pp := &id9{}.set(xp, yp)
	rP := sqrt(xp*xp + yp*yp)
	fmt.Scan(&vP)
	ps := &id9{}
	fmt.Scan(&ps.x, &ps.y)
	fmt.Scan(&vs)

	tvp := 1.0
	vP /= tvp
	vs /= tvp
	omegaP := vP / rP
	star := &id6{&id9{0.0, 0.0}, 0.0}
	fmt.Scan(&star.r)

	ans := 3e6
	left, right := 0.0, ans

	for it := 0; it < 10000; it++ {
		mid := 0.5 * (left + right)
		if can(mid, ps, pp, star, vs) {
			right = mid
			ans = math.Min(ans, mid)
		} else {
			left = mid
		}
	}

	fmt.Println(ans / tvp)
}

func can(t float64, ps, pp *id9, star *id6, vs float64) bool {
	return id4(ps, pp.rotate(t*vs/pp.len())) < t*vs
}

func id4(p1, p2 *id9) float64 {
	// Implement the logic for id4 function
	return 0.0 // Placeholder
}

func sqrt(x float64) float64 {
	if x < -EPS {
		panic("negative value")
	}
	return math.Sqrt(math.Max(0.0, x))
}
