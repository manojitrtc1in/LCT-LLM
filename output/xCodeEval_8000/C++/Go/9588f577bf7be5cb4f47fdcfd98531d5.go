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
		}
	} else {
		return xyLine{
			vertical:  false,
			xcross:    math.NaN(),
			intercept: a.y - (a.x*b.y-a.y*b.x)/(a.x-b.x),
			slope:     (b.y - a.y) / (b.x - a.x),
		}
	}
}

func (l xyLine) orthDist(o xyPoint) float64 {
	if l.vertical {
		return o.x - l.xcross
	} else {
		return (l.slope*o.x - o.y + l.intercept) / math.Sqrt(l.slope*l.slope+1)
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

	areas := make([]float64, n)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if i != j && i != k && j != k {
					areas[i] = math.Max(areas[i], triangleArea(points[i], points[j], points[k]))
				}
			}
		}
	}

	sort.Float64s(areas)
	fmt.Println(areas[n-1])
}
