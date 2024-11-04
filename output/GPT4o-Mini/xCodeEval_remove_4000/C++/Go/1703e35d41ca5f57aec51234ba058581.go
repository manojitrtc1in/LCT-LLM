package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	X, Y float64
}

const EPS = 1e-9

func cross(a, b Point) float64 {
	return a.X*b.Y - a.Y*b.X
}

func dot(a, b Point) float64 {
	return a.X*b.X + a.Y*b.Y
}

func length(v Point) float64 {
	return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func lengthSqr(v Point) float64 {
	return v.X*v.X + v.Y*v.Y
}

func vec(a, b Point) Point {
	return Point{b.X - a.X, b.Y - a.Y}
}

func normalize(v Point) Point {
	l := length(v)
	if l < EPS {
		return Point{0, 0}
	}
	return Point{v.X / l, v.Y / l}
}

func rotate(p Point, angle float64) Point {
	return Point{
		X: p.X*math.Cos(angle) - p.Y*math.Sin(angle),
		Y: p.X*math.Sin(angle) + p.Y*math.Cos(angle),
	}
}

func same(a, b Point) bool {
	return math.Abs(a.X-b.X) < EPS && math.Abs(a.Y-b.Y) < EPS
}

func mid(a, b Point) Point {
	return Point{(a.X + b.X) / 2, (a.Y + b.Y) / 2}
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
	R := length(planet)
	w := float64(Vc) / R
	left, right := 0.0, float64(1<<30)

	for i := 0; i < 300; i++ {
		mid := (right + left) / 2
		id23 := rotate(planet, w*mid)
		var distance float64

		if length(vec(ship, id23)) < float64(r) {
			var a, b, c, d Point
			id1(Point{0, 0}, float64(r), ship, &a, &b)
			id1(Point{0, 0}, float64(r), id23, &c, &d)
			distance = 1 << 30

			distance = math.Min(distance, length(vec(ship, a))+length(vec(c, id23))+arcLength(a, c, float64(r)))
			distance = math.Min(distance, length(vec(ship, b))+length(vec(c, id23))+arcLength(b, c, float64(r)))
			distance = math.Min(distance, length(vec(ship, a))+length(vec(d, id23))+arcLength(a, d, float64(r)))
			distance = math.Min(distance, length(vec(ship, b))+length(vec(d, id23))+arcLength(b, d, float64(r)))
		} else {
			distance = length(vec(ship, id23))
		}

		if distance/float64(Vb) < mid {
			right = mid
		} else {
			left = mid
		}
	}

	fmt.Printf("%.10f\n", left)
}

func id1(cen Point, r float64, p Point, r1, r2 *Point) int {
	// Implementation of id1 function
	// ...
	return 0 // Placeholder return
}
