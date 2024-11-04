package main

import (
	"fmt"
	"math"
)

type Point struct {
	x, y float64
}

type Circle struct {
	center   Point
	sqRadius float64
}

func (c Circle) contains(p Point) bool {
	return p.squaredDistance(c.center) <= c.sqRadius
}

func (c Circle) intersections(c2 Circle) (Point, Point) {
	p0 := c.center
	p1 := c2.center
	d := p0.distance(p1)
	a := (c.sqRadius - c2.sqRadius + d*d) / (2 * d)
	h := math.Sqrt(c.sqRadius - a*a)
	p2 := Point{(p1.x-p0.x)*(a/d) + p0.x, (p1.y-p0.y)*(a/d) + p0.y}
	x3 := p2.x + h*(p1.y-p0.y)/d
	y3 := p2.y - h*(p1.x-p0.x)/d
	x4 := p2.x - h*(p1.y-p0.y)/d
	y4 := p2.y + h*(p1.x-p0.x)/d
	return Point{x3, y3}, Point{x4, y4}
}

func (p Point) distance(p2 Point) float64 {
	return math.Sqrt(p.squaredDistance(p2))
}

func (p Point) squaredDistance(p2 Point) float64 {
	return (p.x-p2.x)*(p.x-p2.x) + (p.y-p2.y)*(p.y-p2.y)
}

func (p Point) invert(t Point) Point {
	return Point{p.center.x + (t.x-p.center.x)*(p.sqRadius/t.squaredDistance(p.center)), p.center.y + (t.y-p.center.y)*(p.sqRadius/t.squaredDistance(p.center))}
}

func minimumEnclosing(p []Point, randomize bool) Circle {
	if randomize {
		// shuffle p
	}
	var V []Point
	return welzl(p, V)
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
		if d.contains(it[0]) {
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

		dist := straight.distance(Zero)
		if dist >= R {
			return straight.length() <= t*V
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
				return Orig.distance(a) + New.distance(b) + ang*R
			}

			id1 := Circle{Orig, Zero}
			id3 := Circle{New, Zero}

			Inter1, Inter2 := id1.intersections(Forbidden)
			dist := math.Min(solve(Inter1.x, Inter2.x), solve(Inter1.x, Inter2.y))
			dist = math.Min(dist, math.Min(solve(Inter1.y, Inter2.x), solve(Inter1.y, Inter2.y)))
			return dist <= t*V
		}
	}, 1e-9))
}
