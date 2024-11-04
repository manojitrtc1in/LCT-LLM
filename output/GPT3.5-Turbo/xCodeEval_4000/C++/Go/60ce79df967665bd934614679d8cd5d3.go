package main

import (
	"fmt"
	"math"
)

type point struct {
	x, y float64
}

type line struct {
	a, b point
}

type circle struct {
	p point
	r float64
}

func dist(a, b point) float64 {
	c := circle{point{0, 0}, r}
	l := line{a, b}
	p11, p12 := point{}, point{}

	if !c.pointcrossline(l, &p11, &p12) {
		return a.distance(b)
	}

	rd := point{0, 0}.rad(p11, p12)
	rd = math.Min(rd, 2*math.Pi-rd)

	ds := a.distance(b) - p11.distance(p12) + rd*r
	l1, l2 := line{}, line{}
	c.tangentline(a, &l1, &l2)
	p1 := [3]point{l1.b, l2.b}
	c.tangentline(b, &l1, &l2)
	p2 := [3]point{l1.b, l2.b}

	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			ds = math.Min(ds, a.distance(p1[i])+point{0, 0}.rad(p1[i], p2[j])*r+b.distance(p2[j]))
		}
	}

	return ds
}

func main() {
	var xp, yp, vp float64
	fmt.Scan(&xp, &yp, &vp)
	p := point{xp, yp}
	fmt.Scan(&x, &y, &v, &r)
	c := circle{point{0, 0}, r}
	d := 2 * math.Pi * p.distance(point{0, 0})
	k := 1000
	low, high := 0.0, 1e6

	for k > 0 {
		mid := (low + high) / 2.0
		s := vp * mid
		w := math.Mod(s, d)
		w = (w / d) * 2 * math.Pi
		where := p.rotate(point{0, 0}, w)
		md := dist(where, point{x, y})

		if mid*v-md >= 0 {
			high = mid
		} else {
			low = mid
		}

		k--
	}

	fmt.Printf("%.12lf\n", low)
}
