package main

import (
	"fmt"
	"math"
	"sort"
)

type Vector struct {
	X, Y int64
}

type Line struct {
	P, Q Vector
	A    float64
}

type Segment struct {
	P, Q Vector
	A    float64
}

func Angle(a Vector) float64 {
	return math.Atan2(float64(a.X), float64(a.Y))
}

func SquaredEuclideanNorm(a Vector) int64 {
	return a.X*a.X + a.Y*a.Y
}

func EuclideanNorm(a Vector) float64 {
	return math.Sqrt(float64(SquaredEuclideanNorm(a)))
}

func CrossProduct(a, b Vector) int64 {
	return a.X*b.Y - b.X*a.Y
}

func DotProduct(a, b Vector) int64 {
	return a.X*b.X + b.Y*a.Y
}

func Intersection(a, b Line) []Vector {
	a1 := CrossProduct(b.P-a.Q, b.Q-b.P)
	a2 := CrossProduct(a.P-b.Q, b.Q-b.P)
	if math.Abs(float64(a1+a2)) < 1e-8 {
		return []Vector{}
	} else {
		return []Vector{(a.P*a1 + a.Q*a2) / (a1 + a2)}
	}
}

func Contains(a Segment, b Vector) bool {
	return math.Abs(float64(CrossProduct(a.Q-a.P, b-a.P))) < 1e-8 &&
		DotProduct(b-a.P, b-a.Q) < 1e-8
}

func IntersectionSegment(a, b Segment) []Vector {
	i := Intersection(Line(a), Line(b))
	r, t := []Vector{}, []Vector{}
	if len(i) > 0 {
		r = i
	} else {
		r = []Vector{a.P, a.Q, b.P, b.Q}
	}
	for _, p := range r {
		if Contains(a, p) && Contains(b, p) {
			t = append(t, p)
		}
	}
	return t
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]Vector, n)
	index := make(map[Vector]int)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].X, &a[i].Y)
		index[a[i]] = i
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i].X < a[j].X
	})
	var d string
	fmt.Scan(&d)
	ans := []Vector{a[0]}
	a = a[1:]
	for len(a) > 0 {
		var td int
		if len(d) == 0 {
			td = 1
		} else if d[len(d)-1] == 'L' {
			td = 1
		} else {
			td = -1
		}
		if len(d) > 0 {
			d = d[:len(d)-1]
		}
		cur := 0
		for i := 0; i < len(a); i++ {
			if CrossProduct(a[cur]-ans[len(ans)-1], a[i]-ans[len(ans)-1])*td < 0 {
				cur = i
			}
		}
		ans = append(ans, a[cur])
		a = append(a[:cur], a[cur+1:]...)
	}
	aaa := make([]int, len(ans))
	for i, t := range ans {
		aaa[i] = index[t] + 1
	}
	fmt.Println(aaa)
}
