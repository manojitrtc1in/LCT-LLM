package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const PI = 3.14159265358979323846

type Point struct {
	x, y float64
}

func (p Point) squaredDistance(o Point) float64 {
	return (p.x-o.x)*(p.x-o.x) + (p.y-o.y)*(p.y-o.y)
}

func (p Point) distance(o Point) float64 {
	return math.Sqrt(p.squaredDistance(o))
}

type Circle struct {
	center   Point
	sqRadius float64
}

func (c Circle) contains(p Point) bool {
	return p.squaredDistance(c.center) <= c.sqRadius
}

func (c Circle) intersections(c2 Circle) (Point, Point) {
	P0 := c.center
	P1 := c2.center
	d := P0.distance(P1)
	a := (c.sqRadius - c2.sqRadius + d*d) / (2 * d)
	h := math.Sqrt(c.sqRadius - a*a)
	P2 := Point{(P1.x-P0.x)*(a/d) + P0.x, (P1.y-P0.y)*(a/d) + P0.y}
	x3 := P2.x + h*(P1.y-P0.y)/d
	y3 := P2.y - h*(P1.x-P0.x)/d
	x4 := P2.x - h*(P1.y-P0.y)/d
	y4 := P2.y + h*(P1.x-P0.x)/d

	return Point{x3, y3}, Point{x4, y4}
}

type Segment struct {
	a, b Point
}

func (s Segment) distance(p Point) float64 {
	dx := s.b.x - s.a.x
	dy := s.b.y - s.a.y
	dL := dx*dx + dy*dy
	u := ((p.x-s.b.x)*dx + (p.y-s.b.y)*dy) / dL
	if u > 1 {
		u = 1
	}
	if u < 0 {
		u = 0
	}
	return p.distance(Point{s.b.x + u*dx, s.b.y + u*dy})
}

type CDeliveringCarcinogen struct{}

func (solver CDeliveringCarcinogen) solve(cin *fmt.Scanner, cout *fmt.Writer) {
	var XP, YP, VP float64
	cin.Scan(&XP, &YP, &VP)

	var X, Y, V, R float64
	cin.Scan(&X, &Y, &V, &R)
	Orig := Point{X, Y}
	Zero := Point{0, 0}
	Forbidden := Circle{Zero, R * R}

	RR := math.Sqrt(XP*XP + YP*YP)
	init := math.Atan2(YP, XP)

	bsld := func(l, h float64, f func(float64) bool, p float64) float64 {
		for r := 0; r < 100; r++ {
			m := (l + h) / 2
			if f(m) {
				l = m
			} else {
				h = m
			}
		}
		return (l + h) / 2
	}

	cout.Printf("%.10f\n", bsld(0.0, 1e5, func(t float64) bool {
		angle := (t * VP) / RR
		New := Point{RR * math.Cos(angle + init), RR * math.Sin(angle + init)}
		straight := Segment{New, Orig}

		dist := straight.distance(Zero)
		if dist >= R {
			return math.Sqrt(straight.a.squaredDistance(straight.b)) <= t*V
		} else {
			solve := func(a, b Point) float64 {
				ang1 := math.Atan2(a.y, a.x)
				ang2 := math.Atan2(b.y, b.x)
				if ang2 < ang1 {
					ang2 += 2 * PI
				}
				ang := ang2 - ang1
				if ang > PI {
					ang = 2*PI - ang
				}
				return Orig.distance(a) + New.distance(b) + ang*R
			}

			Thales1 := Circle{Orig, Zero}
			Thales2 := Circle{New, Zero}

			Inter1, Inter2 := Thales1.intersections(Forbidden)
			dist1 := math.Min(solve(Inter1, Inter2), solve(Inter1, Inter2))
			return dist1 <= t*V
		}
	}, 1e-9))
}

func main() {
	rand.Seed(time.Now().UnixNano())
	solver := CDeliveringCarcinogen{}
	solver.solve(fmt.NewScanner(os.Stdin), fmt.NewWriter(os.Stdout))
}
