package main

import (
	"bufio"
	"fmt"
	"math/big"
	"sort"
	"strings"
)

const BIG = 1000000007

type Point struct {
	index int
	x     int
	y     int
}

func (p *Point) GetX() int {
	return p.x
}

func (p *Point) GetY() int {
	return p.y
}

func countLines(points map[Point]struct{}) int {
	xs := make(map[int]struct{})
	ys := make(map[int]struct{})
	for point := range points {
		xs[point.GetX()] = struct{}{}
		ys[point.GetY()] = struct{}{}
	}
	return len(xs) + len(ys)
}

func modMultiply(a, b int64) int64 {
	return (a * b) % BIG
}

func modAdd(a, b int64) int64 {
	return (a + b) % BIG
}

func modSubtract(a, b int64) int64 {
	return (a - b + BIG) % BIG
}

func id12(a int) int64 {
	result := int64(1)
	for index := 0; index < a; index++ {
		result = modMultiply(result, 2)
	}
	return result
}

func solve() {
	reader := bufio.NewReaderSize(strings.NewReader(""), 1024)
	n := readInt(reader)
	points := make([]Point, n)
	id3 := make(map[int][]Point)

	for index := 0; index < n; index++ {
		x, y := readInt(reader), readInt(reader)
		point := Point{index: index, x: x, y: y}
		points[index] = point
		id3[y] = append(id3[y], point)
	}

	id49 := make(map[int]Point)
	for _, set := range id3 {
		var lastX *Point
		for _, point := range set {
			if lastX != nil {
				// Create edge (not implemented)
			}
			lastX = &point
			if lastY, ok := id49[point.GetX()]; ok {
				// Create edge (not implemented)
			}
			id49[point.GetX()] = point
		}
	}

	id35 := make(map[Point]struct{})
	id29 := make(map[Point]struct{})
	pointsProcessed := make(map[Point]struct{})

	for _, point := range points {
