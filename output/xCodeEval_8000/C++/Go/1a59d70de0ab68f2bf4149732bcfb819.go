package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

type xyPoint struct {
	x float64
	y float64
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
	slope     float64
	intercept float64
	vertical  bool
	xcross    float64
}

func newXYLine(a, b xyPoint) xyLine {
	if a.x == b.x {
		return xyLine{
			vertical: true,
			xcross:   a.x,
		}
	} else {
		return xyLine{
			slope:     (b.y - a.y) / (b.x - a.x),
			intercept: a.y - (a.x * (b.y-a.y) / (b.x - a.x)),
			vertical:  false,
			xcross:    math.NaN(),
		}
	}
}

func (l xyLine) orthDist(o xyPoint) float64 {
	if l.vertical {
		return o.x - l.xcross
	} else {
		return (l.slope*o.x - o.y + l.intercept) / math.Sqrt(l.slope*l.slope+1.0)
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

	xs := make([][]int, n)
	for i := 0; i < n; i++ {
		var m int
		fmt.Scan(&m)
		xs[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&xs[i][j])
		}
	}

	k := 0
	for _, row := range xs {
		k += len(row)
	}
	fmt.Println(k)

	acc := 0
	for _, row := range xs {
		for _, val := range row {
			acc += val
		}
	}
	fmt.Println(acc)

	left := make([]int, n)
	right := make([]int, n)
	leftAcc := 0

	for j := 0; j < k; j++ {
		imax := 0
		for len(xs[imax]) == left[imax]+right[imax] {
			imax++
		}

		val := xs[imax][left[imax]+(len(xs[imax])-left[imax]-right[imax])/2]

		for i := imax + 1; i < n; i++ {
			if left[i]+right[i] < len(xs[i]) {
				g := xs[i][left[i]+(len(xs[i])-left[i]-right[i])/2]
				if val < g {
					val = g
					imax = i
				}
			}
		}

		if j%2 == 1 {
			right[imax]++
		} else {
			leftAcc += xs[imax][left[imax]]
			left[imax]++
		}
	}

	fmt.Println(leftAcc, acc-leftAcc)
}
