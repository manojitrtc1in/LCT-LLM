package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

type Point struct {
	X int64
	Y int64
}

type Line struct {
	P Point
	Q Point
	Angle float64
}

func Angle(p Point) float64 {
	return math.Atan2(float64(p.X), float64(p.Y))
}

func CrossProduct(a Point, b Point) int64 {
	return a.X * b.Y - b.X * a.Y
}

func DotProduct(a Point, b Point) int64 {
	return a.X * b.X + b.Y * a.Y
}

func Intersection(a Line, b Line) []Point {
	a1 := CrossProduct(b.P.Sub(a.Q), b.Q.Sub(b.P))
	a2 := CrossProduct(a.P.Sub(b.Q), b.Q.Sub(b.P))
	if math.Abs(float64(a1 + a2)) < 1e-8 {
		return []Point{}
	} else {
		return []Point{(a.P.Mul(a1).Add(a.Q.Mul(a2))).Div(a1 + a2)}
	}
}

func Contains(a Line, b Point) bool {
	return math.Abs(float64(CrossProduct(a.Q.Sub(a.P), b.Sub(a.P)))) < 1e-8 &&
		DotProduct(b.Sub(a.P), b.Sub(a.Q)) < 1e-8
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	// Read n
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Read points
	points := make([]Point, n)
	index := make(map[Point]int)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		scanner.Scan()
		y, _ := strconv.ParseInt(scanner.Text(), 10, 64)
		points[i] = Point{x, y}
		index[Point{x, y}] = i
	}

	// Read direction
	scanner.Scan()
	direction := scanner.Text()
	direction = strings.TrimSpace(direction)
	direction = Reverse(direction)

	// Sort points by x-coordinate
	sort.Slice(points, func(i, j int) bool {
		return points[i].X < points[j].X
	})

	// Reverse direction
	reversedDirection := Reverse(direction)

	// Initialize answer with first point
	answer := []Point{points[0]}
	points = points[1:]

	// Iterate through remaining points
	for len(points) > 0 {
		var td int
		if len(reversedDirection) == 0 {
			td = 1
		} else if reversedDirection[len(reversedDirection)-1] == 'L' {
			td = 1
		} else {
			td = -1
		}

		if len(reversedDirection) > 0 {
			reversedDirection = reversedDirection[:len(reversedDirection)-1]
		}

		cur := 0
		for i := 0; i < len(points); i++ {
			if CrossProduct(points[cur].Sub(answer[len(answer)-1]), points[i].Sub(answer[len(answer)-1])) * int64(td) < 0 {
				cur = i
			}
		}

		answer = append(answer, points[cur])
		points = append(points[:cur], points[cur+1:]...)
	}

	// Convert answer to indices
	indices := make([]int, len(answer))
	for i, p := range answer {
		indices[i] = index[p] + 1
	}

	// Print answer
	fmt.Println(indices)
}

func Reverse(s string) string {
	runes := []rune(s)
	for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
		runes[i], runes[j] = runes[j], runes[i]
	}
	return string(runes)
}

func (p Point) Sub(q Point) Point {
	return Point{p.X - q.X, p.Y - q.Y}
}

func (p Point) Mul(k int64) Point {
	return Point{p.X * k, p.Y * k}
}

func (p Point) Add(q Point) Point {
	return Point{p.X + q.X, p.Y + q.Y}
}

func (p Point) Div(k int64) Point {
	return Point{p.X / k, p.Y / k}
}
