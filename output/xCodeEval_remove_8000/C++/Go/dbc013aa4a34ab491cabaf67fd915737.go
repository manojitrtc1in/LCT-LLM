package main

import (
	"fmt"
	"math"
	"strings"
)

type xyPoint struct {
	x, y float64
}

type xyCircle struct {
	center xyPoint
	radius float64
}

func triangleArea(a, b, c xyPoint) float64 {
	return math.Abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) / 2)
}

func main() {
	var a, b, c xyPoint
	fmt.Scan(&a.x, &a.y, &b.x, &b.y, &c.x, &c.y)

	area := triangleArea(a, b, c)
	fmt.Println(area)
}
