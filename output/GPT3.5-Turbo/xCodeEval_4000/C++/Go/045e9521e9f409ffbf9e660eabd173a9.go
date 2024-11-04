package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Segment struct {
	p1, p2 Point
}

type Circle struct {
	center   Point
	sqRadius float64
}

func (p Point) Distance(q Point) float64 {
	return math.Sqrt(math.Pow(q.x-p.x, 2) + math.Pow(q.y-p.y, 2))
}

func (s Segment) Length() float64 {
	return s.p1.Distance(s.p2)
}

func (c Circle) Contains(p Point) bool {
	return p.Distance(c.center) <= math.Sqrt(c.sqRadius)
}

func (c Circle) Intersections(d Circle) (Point, Point) {
	p0 := c.center
	p1 := d.center
	d := p0.Distance(p1)
	a := (c.sqRadius - d*d + d*d) / (2 * d)
	h := math.Sqrt(c.sqRadius - a*a)
	p2 := Point{
		x: (p1.x-p0.x)*(a/d) + p0.x,
		y: (p1.y-p0.y)*(a/d) + p0.y,
	}
	x3 := p2.x + h*(p1.y-p0.y)/d
	y3 := p2.y - h*(p1.x-p0.x)/d
	x4 := p2.x - h*(p1.y-p0.y)/d
	y4 := p2.y + h*(p1.x-p0.x)/d
	return Point{x3, y3}, Point{x4, y4}
}

func (c Circle) Invert(t Point) Point {
	return Point{
		x: c.center.x + (t.x-c.center.x)*(c.sqRadius/t.Distance(c.center)),
		y: c.center.y + (t.y-c.center.y)*(c.sqRadius/t.Distance(c.center)),
	}
}

func (c Circle) MinimumEnclosing(p []Point, randomize bool) Circle {
	if randomize {
		// shuffle p
	}
	var v []Point
	return welzl(p, v)
}

func welzl(it []Point, itend []Point, p []Point) Circle {
	if len(it) == 0 || len(p) == 3 {
		if len(p) == 1 {
			return Circle{p[0], 0}
		} else if len(p) == 2 {
			return Circle{p[0], p[1]}
		} else if len(p) == 3 {
			return Circle{p[0], p[1], p[2]}
		} else {
			return Circle{Point{0, 0}, 0}
		}
	} else {
		d := welzl(it[1:], itend, p)
		if d.Contains(it[0]) {
			return d
		} else {
			p = append(p, it[0])
			d = welzl(it[1:], itend, p)
			p = p[:len(p)-1]
			return d
		}
	}
}

func main() {
	var XP, YP, VP float64
	fmt.Scan(&XP, &YP, &VP)

	var X, Y, V, R float64
	fmt.Scan(&X, &Y, &V, &R)
	Orig := Point{X, Y}
	Zero := Point{0, 0}
	Forbidden := Circle{Zero, R * R}

	RR := math.Sqrt(XP*XP + YP*YP)
	init := math.Atan2(YP, XP)
	fmt.Printf("%.10f\n", bsld(0.0, 1e5, func(t float64) bool {
		angle := (t * VP) / RR
		New := Point{RR * math.Cos(angle+init), RR * math.Sin(angle+init)}
		straight := Segment{New, Orig}

		dist := straight.Distance(Zero)
		if dist >= R {
			return straight.Length() <= t*V
		} else {
			solve := func(a, b Point) float64 {
				ang1 := math.Atan2(a.y, a.x)
				ang2 := math.Atan2(b.y, b.x)
				if ang2 < ang1 {
					ang2 += 2 * math.Pi
				}
				ang := ang2 - ang1
				if ang > math.Pi {
					ang = 2 * math.Pi - ang
				}
				return Orig.Distance(a) + New.Distance(b) + ang*R
			}

			Thales1 := Circle{Orig, Zero}
			Thales2 := Circle{New, Zero}

			Inter1 := Thales1.Intersections(Forbidden)
			Inter2 := Thales2.Intersections(Forbidden)

			dist := math.Min(solve(Inter1.x, Inter2.x), solve(Inter1.x, Inter2.y))
			dist = math.Min(dist, math.Min(solve(Inter1.y, Inter2.x), solve(Inter1.y, Inter2.y)))
			return dist <= t*V
		}
	}, 1e-9))
}

func bsld(l, h float64, f func(float64) bool, p float64) float64 {
	r := 3 + uint(math.Log2((h-l)/p))
	for r > 0 {
		m := (l + h) / 2
		if f(m) {
			l = m
		} else {
			h = m
		}
		r--
	}
	return (l + h) / 2
}
