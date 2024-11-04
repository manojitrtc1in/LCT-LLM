package main

import (
	"fmt"
	"math"
)

type point struct {
	X, Y float64
}

func cross(a, b point) float64 {
	return a.X*b.Y - a.Y*b.X
}

func dot(a, b point) float64 {
	return a.X*b.X + a.Y*b.Y
}

func length(a point) float64 {
	return math.Sqrt(a.X*a.X + a.Y*a.Y)
}

func normalize(a point) point {
	len := length(a)
	return point{a.X / len, a.Y / len}
}

func rotate(a point, angle float64) point {
	cos := math.Cos(angle)
	sin := math.Sin(angle)
	return point{a.X*cos - a.Y*sin, a.X*sin + a.Y*cos}
}

func angle(a point) float64 {
	return math.Atan2(a.Y, a.X)
}

func id1(cen point, r float64, p point, r1, r2 *point) int {
	s := circlePoint(cen, r, p)
	if s != OUT {
		*r1 = p
		*r2 = p
		if s == BOUNDRY {
			return 1
		}
		return 0
	}
	cp := vec(cen, p)
	h := length(cp)
	a := math.Acos(r / h)
	cp = normalize(cp)
	cp = point{cp.X * r, cp.Y * r}
	*r1 = rotate(cp, a)
	*r2 = rotate(cp, -a)
	return 2
}

func vec(a, b point) point {
	return point{b.X - a.X, b.Y - a.Y}
}

func circlePoint(cen point, r float64, p point) STATE {
	lensqr := lengthSqr(vec(cen, p))
	if math.Abs(lensqr-r*r) < EPS {
		return BOUNDRY
	}
	if lensqr < r*r {
		return IN
	}
	return OUT
}

type STATE int

const (
	IN STATE = iota
	OUT
	BOUNDRY
)

const EPS = 1e-9

func main() {
	var Xc, Yc, Vc int
	var Xb, Yb, Vb, r float64
	fmt.Scan(&Xc, &Yc, &Vc)
	fmt.Scan(&Xb, &Yb, &Vb, &r)
	planet := point{float64(Xc), float64(Yc)}
	ship := point{float64(Xb), float64(Yb)}
	R := length(planet)
	w := Vc / R
	left := 0.0
	right := 1 << 30
	for i := 0; i < 300; i++ {
		mid := (right + left) / 2
		id23 := rotate(planet, w*mid)
		var distance float64
		if id21(ship, id23, point{0, 0}) < r {
			var a, b, c, d point
			id1(point{0, 0}, r, ship, &a, &b)
			id1(point{0, 0}, r, id23, &c, &d)
			distance = 1 << 30
			distance = math.Min(distance, length(vec(ship, a))+
				length(vec(c, id23))+
				arcLength(a, c, r))

			distance = math.Min(distance, length(vec(ship, b))+
				length(vec(c, id23))+
				arcLength(b, c, r))

			distance = math.Min(distance, length(vec(ship, a))+
				length(vec(d, id23))+
				arcLength(a, d, r))

			distance = math.Min(distance, length(vec(ship, b))+
				length(vec(d, id23))+
				arcLength(b, d, r))
		} else {
			distance = length(vec(ship, id23))
		}

		if distance/Vb < mid {
			right = mid
		} else {
			left = mid
		}

	}
	fmt.Printf("%.10f\n", left)
}

func arcLength(a, b point, r float64) float64 {
	Ang := angle(a) - angle(b)
	if Ang < 0 {
		Ang += 2 * math.Pi
	}
	if Ang > math.Pi {
		Ang = 2*math.Pi - Ang
	}
	return Ang * r
}

func id21(a, b, p point) float64 {
	if dot(vec(a, b), vec(a, p)) < EPS {
		return length(vec(a, p))
	}
	if dot(vec(b, a), vec(b, p)) < EPS {
		return length(vec(b, p))
	}
	return id13(a, b, p)
}

func id13(a, b, p point) float64 {
	return math.Abs(cross(vec(a, b), vec(a, p)) / length(vec(a, b)))
}

func lengthSqr(a point) float64 {
	return a.X*a.X + a.Y*a.Y
}

func same(a, b point) bool {
	return math.Abs(a.X-b.X) < EPS && math.Abs(a.Y-b.Y) < EPS
}
