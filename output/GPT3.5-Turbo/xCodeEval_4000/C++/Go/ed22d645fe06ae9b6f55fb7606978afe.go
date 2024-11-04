package main

import (
	"fmt"
)

type Po struct {
	x float64
	y float64
}

type Line struct {
	a Po
	b Po
}

type Seg Line

func dot(x1 float64, y1 float64, x2 float64, y2 float64) float64 {
	return x1*x2 + y1*y2
}

func det(x1 float64, y1 float64, x2 float64, y2 float64) float64 {
	return x1*y2 - x2*y1
}

