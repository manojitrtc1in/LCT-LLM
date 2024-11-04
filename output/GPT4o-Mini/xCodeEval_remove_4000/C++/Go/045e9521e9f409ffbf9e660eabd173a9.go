package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

type Point struct {
	x, y float64
}

type Circle struct {
	center   Point
	sqRadius float64
}

type Segment struct {
	a, b Point
}

func (p Point) squaredDistance(o Point) float64 {
	return (p.x-o.x)*(p.x-o.x) + (p.y-o.y)*(p.y-o.y)
}

func (c Circle) contains(p Point) bool {
	return p.squaredDistance(c.center) <= c.sqRadius
}

func (s Segment) distance(p Point) float64 {
	dx := s.b.x - s.a.x
	dy := s.b.y - s.a.y
	dL := dx*dx + dy*dy
	u := ((p.x-s.a.x)*dx + (p.y-s.a.y)*dy) / dL
	if u > 1 {
		u = 1
	}
	if u < 0 {
		u = 0
	}
	return Point{p.x, p.y}.squaredDistance(Point{s.a.x + u*dx, s.a.y + u*dy})
}

func (c Circle) intersections(other Circle) (Point, Point) {
	d := c.center.squaredDistance(other.center)
	a := (c.sqRadius - other.sqRadius + d) / (2 * math.Sqrt(d))
	h := math.Sqrt(c.sqRadius - a*a)
	P2 := Point{
		x: other.center.x + a*(c.center.x-other.center.x)/math.Sqrt(d),
		y: other.center.y + a*(c.center.y-other.center.y)/math.Sqrt(d),
	}
	x3 := P2.x + h*(other.center.y-c.center.y)/math.Sqrt(d)
	y3 := P2.y - h*(other.center.x-c.center.x)/math.Sqrt(d)
	x4 := P2.x - h*(other.center.y-c.center.y)/math.Sqrt(d)
	y4 := P2.y + h*(other.center.x-c.center.x)/math.Sqrt(d)

	return Point{x3, y3}, Point{x4, y4}
}

func bsld(l, h float64, f func(float64) bool, p float64) float64 {
	for r := 0; r < 100; r++ {
		m := (l + h) / 2
		if f(m) {
			h = m
		} else {
			l = m
		}
	}
	return (l + h) / 2
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var XP, YP, VP float64
	fmt.Scan(&XP, &YP, &VP)

	var X, Y, V, R float64
	fmt.Scan(&X, &Y, &V, &R)

	Orig := Point{X, Y}
	Zero := Point{0, 0}
	Forbidden := Circle{Zero, R * R}

	RR := math.Sqrt(XP*XP + YP*YP)
	init := math.Atan2(YP, XP)

	result := bsld(0.0, 1e5, func(t float64) bool {
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
					ang2 += 2 * math.Pi
				}
				ang := ang2 - ang1
				if ang > math.Pi {
					ang = 2*math.Pi - ang
				}
				return Orig.squaredDistance(a) + New.squaredDistance(b) + ang*R
			}

			id1 := Circle{Orig, 0}
			id3 := Circle{New, 0}

			Inter1a, Inter1b := id1.intersections(Forbidden)
			Inter2a, Inter2b := id3.intersections(Forbidden)

			dist := math.Min(solve(Inter1a, Inter2a), solve(Inter1a, Inter2b))
			dist = math.Min(dist, math.Min(solve(Inter1b, Inter2a), solve(Inter1b, Inter2b)))
			return dist <= t*V
		}
	}, 1e-9)

	fmt.Printf("%.10f\n", result)
}
