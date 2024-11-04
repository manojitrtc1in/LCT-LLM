package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

var (
	inf      = int64(1e10)
	mod      = int64(998244353)
	num      = int64(1e9 + 7)
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	scanner.Scan()
	t := atoi(scanner.Text())
	for t > 0 {
		t--
		scanner.Scan()
		n := atoi(scanner.Text())
		scanner.Scan()
		k := atoi(scanner.Text())
		scanner.Scan()
		d := atoi(scanner.Text())
		a := make([]int, n)
		hm := make(map[int]int)
		occ := make([]int, n+1)
		id := 0
		for i := 0; i < n; i++ {
			scanner.Scan()
			a[i] = atoi(scanner.Text())
			if _, exists := hm[a[i]]; !exists {
				hm[a[i]] = id
				id++
			}
		}
		for i := 0; i < n; i++ {
			a[i] = hm[a[i]]
		}
		ans := 0
		for i := 0; i < d; i++ {
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans++
			}
		}
		ansl := ans
		for i := d; i < n; i++ {
			ans1 := ansl
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans1++
			}
			occ[a[i-d]]--
			if occ[a[i-d]] == 0 {
				ans1--
			}
			ans = min(ans, ans1)
			ansl = ans1
		}
		fmt.Println(ans)
	}
}

func atoi(s string) int {
	n := 0
	for _, c := range s {
		n = n*10 + int(c-'0')
	}
	return n
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

type Pair struct {
	x, y int
}

func (p Pair) String() string {
	return fmt.Sprintf("%d %d", p.x, p.y)
}

type Point struct {
	x, y float64
}

func (p Point) dist(q Point) float64 {
	return math.Sqrt(sq(p.x-q.x) + sq(p.y-q.y))
}

func sq(x float64) float64 {
	return x * x
}

type Vector struct {
	x, y float64
}

func (v Vector) scale(s float64) Vector {
	return Vector{v.x * s, v.y * s}
}

func (v Vector) dot(u Vector) float64 {
	return v.x*u.x + v.y*u.y
}

func (v Vector) cross(u Vector) float64 {
	return v.x*u.y - v.y*u.x
}

func (v Vector) norm2() float64 {
	return v.x*v.x + v.y*v.y
}

func (v Vector) normalize() Vector {
	d := math.Sqrt(v.norm2())
	return v.scale(1 / d)
}

type Line struct {
	a, b, c float64
}

func NewLine(p, q Point) Line {
	if math.Abs(p.x-q.x) < 1e-9 {
		return Line{1, 0, -p.x}
	}
	a := (p.y - q.y) / (q.x - p.x)
	return Line{a, 1.0, -(a*p.x + p.y)}
}

func (l Line) intersect(other Line) *Point {
	if l.parallel(other) {
		return nil
	}
	x := (l.b*other.c - l.c*other.b) / (l.a*other.b - l.b*other.a)
	var y float64
	if math.Abs(l.b) < 1e-9 {
		y = -other.a*x - other.c
	} else {
		y = -l.a*x - l.c
	}
	return &Point{x, y}
}

func (l Line) parallel(other Line) bool {
	return math.Abs(l.a-other.a) < 1e-9 && math.Abs(l.b-other.b) < 1e-9
}

type Polygon struct {
	points []Point
}

func NewPolygon(points []Point) Polygon {
	return Polygon{points}
}

func (p Polygon) perimeter() float64 {
	sum := 0.0
	for i := 0; i < len(p.points)-1; i++ {
		sum += p.points[i].dist(p.points[i+1])
	}
	return sum
}

func (p Polygon) area() float64 {
	area := 0.0
	for i := 0; i < len(p.points)-1; i++ {
		area += p.points[i].x*p.points[i+1].y - p.points[i].y*p.points[i+1].x
	}
	return math.Abs(area) / 2.0
}

func (p Polygon) isConvex() bool {
	if len(p.points) <= 3 {
		return false
	}
	ccw := ccw(p.points[len(p.points)-2], p.points[0], p.points[1])
	for i := 1; i < len(p.points)-1; i++ {
		if ccw(p.points[i-1], p.points[i], p.points[i+1]) != ccw {
			return false
		}
	}
	return true
}

func ccw(p, q, r Point) bool {
	return (q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x) > 0
}
