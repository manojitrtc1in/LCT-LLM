package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	X, Y int64
}

type Point struct {
	Coord Pair
	Index int
}

func take(k int, perm *[]Point, points *[]Point) {
	n := len(*points)
	for i := 0; i < n; i++ {
		if (*points)[i].Index == k {
			(*points)[i], (*points)[n-1] = (*points)[n-1], (*points)[i]
		}
	}
	*perm = append(*perm, (*points)[n-1])
	*points = (*points)[:n-1]
}

func main() {
	var n int
	fmt.Scan(&n)
	points := make([]Point, n)
	for i := 0; i < n; i++ {
		var x, y int64
		fmt.Scan(&x, &y)
		points[i] = Point{Coord: Pair{X: x, Y: y}, Index: i}
	}
	var s string
	fmt.Scan(&s)

	perm := []Point{}
	firstIdx := 0
	for i := 1; i < n; i++ {
		if points[i].Coord.X < points[firstIdx].Coord.X {
			firstIdx = i
		}
	}
	take(firstIdx, &perm, &points)

	for i := 0; i < n-2; i++ {
		q := perm[len(perm)-1].Coord
		best := 0
		for j := 1; j < len(points); j++ {
			if (crossProduct(points[best].Coord, q, points[j].Coord) > 0) == (s[i] == 'R') {
				best = j
			}
		}
		take(points[best].Index, &perm, &points)
	}
	take(points[0].Index, &perm, &points)

	for _, p := range perm {
		fmt.Printf("%d ", p.Index+1)
	}
	fmt.Println()
}

func crossProduct(a, b, c Pair) int64 {
	return (b.X-a.X)*(c.Y-a.Y) - (b.Y-a.Y)*(c.X-a.X)
}
