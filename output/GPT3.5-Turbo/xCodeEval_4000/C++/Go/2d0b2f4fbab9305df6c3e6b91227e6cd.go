package main

import (
	"fmt"
	"math"
	"sort"
)

type xyPoint struct {
	x, y float64
}

type xyCircle struct {
	center xyPoint
	radius float64
}

func cartesianDist(a, b xyPoint) float64 {
	d := a.x - b.x
	e := a.y - b.y
	return math.Sqrt(d*d + e*e)
}

type xyLine struct {
	slope, intercept float64
}

func newXYLine(a, b xyPoint) xyLine {
	if a.x == b.x {
		return xyLine{
			vertical:  true,
			xcross:    a.x,
			intercept: math.NaN(),
			slope:     math.Inf(1),
			normfac:   math.NaN(),
		}
	} else {
		return xyLine{
			vertical:  false,
			xcross:    math.NaN(),
			slope:     (b.y - a.y) / (b.x - a.x),
			intercept: a.y - slope*a.x,
			normfac:   math.Sqrt(slope*slope + 1.0),
		}
	}
}

func (l xyLine) orthDist(o xyPoint) float64 {
	if l.vertical {
		return o.x - l.xcross
	} else {
		return (l.slope*o.x - o.y + l.intercept) / l.normfac
	}
}

func triangleArea(a, b, c xyPoint) float64 {
	l := newXYLine(a, b)
	h := math.Abs(l.orthDist(c))
	e := cartesianDist(a, b)
	return h * e
}

func main() {
	var n int
	fmt.Scan(&n)

	points := make([]xyPoint, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&points[i].x, &points[i].y)
	}

	maxArea := 0.0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				area := triangleArea(points[i], points[j], points[k])
				if area > maxArea {
					maxArea = area
				}
			}
		}
	}

	fmt.Println(maxArea)
}
