package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	X, Y float64
}

const EPS = 1e-5
const OO = 1e9

func (p Point) Vec(q Point) Point {
	return Point{q.X - p.X, q.Y - p.Y}
}

func (p Point) Length() float64 {
	return math.Hypot(p.X, p.Y)
}

func (p Point) LengthSqr() float64 {
	return p.X*p.X + p.Y*p.Y
}

func (p Point) Dot(q Point) float64 {
	return p.X*q.X + p.Y*q.Y
}

func (p Point) Cross(q Point) float64 {
	return p.X*q.Y - p.Y*q.X
}

func (p Point) Rotate(theta float64) Point {
	return Point{
		X: p.X*math.Cos(theta) - p.Y*math.Sin(theta),
		Y: p.X*math.Sin(theta) + p.Y*math.Cos(theta),
	}
}

func (p Point) Normalize() Point {
	length := p.Length()
	if length == 0 {
		return Point{0, 0}
	}
	return Point{p.X / length, p.Y / length}
}

func intersect(a, b, p, q Point) (Point, bool) {
	d1 := p.Vec(a).Cross(b.Vec(a))
	d2 := q.Vec(a).Cross(b.Vec(a))
	if math.Abs(d1-d2) <= EPS {
		return Point{}, false
	}
	ret := Point{
		X: (d1*q.X - d2*p.X) / (d1 - d2),
		Y: (d1*q.Y - d2*p.Y) / (d1 - d2),
	}
	return ret, true
}

func pointOnSegment(a, b, p Point) bool {
	return p.Vec(a).Cross(b.Vec(a)) == 0 && p.Vec(a).Dot(b.Vec(a)) > -EPS && p.Vec(b).Dot(a.Vec(b)) > -EPS
}

func pointSegmentDist(a, b, p Point) float64 {
	if a.Vec(b).Dot(a.Vec(p)) < EPS {
		return p.Vec(a).Length()
	}
	if b.Vec(a).Dot(b.Vec(p)) < EPS {
		return p.Vec(b).Length()
	}
	return math.Abs(a.Vec(b).Cross(a.Vec(p))) / a.Vec(b).Length()
}

func tangentPoints(cen Point, r float64, p Point) (Point, Point, int) {
	cp := cen.Vec(p)
	h := cp.Length()
	if h < r {
		return p, p, 0
	}
	a := math.Acos(r / h)
	cp = cp.Normalize()
	r1 := cp.Rotate(a)
	r2 := cp.Rotate(-a)
	return Point{r1.X + cen.X, r1.Y + cen.Y}, Point{r2.X + cen.X, r2.Y + cen.Y}, 2
}

func arcLength(a, b Point, r float64) float64 {
	ang := math.Atan2(a.Y, a.X) - math.Atan2(b.Y, b.X)
	if ang < 0 {
		ang += 2 * math.Pi
	}
	if ang > math.Pi {
		ang = 2*math.Pi - ang
	}
	return ang * r
}

func main() {
	var Xc, Yc, Vc int
	var Xb, Yb, Vb, r int
	fmt.Scan(&Xc, &Yc, &Vc)
	fmt.Scan(&Xb, &Yb, &Vb, &r)

	planet := Point{float64(Xc), float64(Yc)}
	ship := Point{float64(Xb), float64(Yb)}
	R := planet.Length()
	w := float64(Vc) / R

	left, right := 0.0, float64(1<<30)
	for i := 0; i < 300; i++ {
		mid := (right + left) / 2
		newPlanet := planet.Rotate(w * mid)
		var distance float64

		if pointSegmentDist(ship, newPlanet, Point{0, 0}) < float64(r) {
			a, b, _ := tangentPoints(Point{0, 0}, float64(r), ship)
			c, d, _ := tangentPoints(Point{0, 0}, float64(r), newPlanet)

			distance = OO
			distance = math.Min(distance, ship.Vec(a).Length()+newPlanet.Vec(c).Length()+arcLength(a, c, float64(r)))
			distance = math.Min(distance, ship.Vec(b).Length()+newPlanet.Vec(c).Length()+arcLength(b, c, float64(r)))
			distance = math.Min(distance, ship.Vec(a).Length()+newPlanet.Vec(d).Length()+arcLength(a, d, float64(r)))
			distance = math.Min(distance, ship.Vec(b).Length()+newPlanet.Vec(d).Length()+arcLength(b, d, float64(r)))
		} else {
			distance = ship.Vec(newPlanet).Length()
		}

		if distance/float64(Vb) < mid {
			right = mid
		} else {
			left = mid
		}
	}

	fmt.Printf("%.10f\n", left)
}
