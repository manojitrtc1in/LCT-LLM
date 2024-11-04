package main

import (
	"fmt"
	"math"
	"sort"
	"time"
)

type Point struct {
	x, y, i int
}

func (p Point) String() string {
	return fmt.Sprintf("(%d, %d)", p.x, p.y)
}

func (p Point) Sub(q Point) Point {
	return Point{p.x - q.x, p.y - q.y, -1}
}

func (p Point) Add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y, -1}
}

func (p Point) Equals(q Point) bool {
	return p.x == q.x && p.y == q.y
}

func sqr(a int64) int64 {
	return a * a
}

func sdist(a, b Point) int64 {
	return sqr(int64(a.x-b.x)) + sqr(int64(a.y-b.y))
}

func dot(a, b Point) int64 {
	return int64(a.x)*int64(b.x) + int64(a.y)*int64(b.y)
}

func cross(a, b Point) int64 {
	return int64(a.x)*int64(b.y) - int64(a.y)*int64(b.x)
}

func build(points []Point) []Point {
	n := len(points)
	if n <= 1 {
		return points
	}

	up := []Point{points[0]}
	dw := []Point{points[0]}

	for i := 1; i < n; i++ {
		if i == n-1 || cross(points[n-1].Sub(points[0]), points[i].Sub(points[0])) >= 0 {
			for len(up) > 1 && cross(points[i].Sub(up[len(up)-2]), up[len(up)-1].Sub(up[len(up)-2])) < 0 {
				up = up[:len(up)-1]
			}
			up = append(up, points[i])
		}
		if i == n-1 || cross(points[n-1].Sub(points[0]), points[i].Sub(points[0])) < 0 {
			for len(dw) > 1 && cross(points[i].Sub(dw[len(dw)-2]), dw[len(dw)-1].Sub(dw[len(dw)-2])) > 0 {
				dw = dw[:len(dw)-1]
			}
			dw = append(dw, points[i])
		}
	}

	res := up
	for i := len(dw) - 2; i >= 1; i-- {
		res = append(res, dw[i])
	}

	return res
}

func solve(points []Point, s string) {
	sort.Slice(points, func(i, j int) bool {
		if points[i].x != points[j].x {
			return points[i].x < points[j].x
		}
		return points[i].y < points[j].y
	})

	cur := make(map[Point]struct{})
	for _, p := range points {
		cur[p] = struct{}{}
	}

	ans := []Point{}
	ch := build(points)
	ans = append(ans, ch[0])
	if s[0] == 'L' {
		ans = append(ans, ch[len(ch)-1])
	} else {
		ans = append(ans, ch[1])
	}
	delete(cur, ch[0])

	for i := 0; i < len(s); i++ {
		n := 0
		for p := range cur {
			points[n] = p
			n++
		}
		ch = build(points[:n])
		pos := 0
		for j := range ch {
			if ch[j].Equals(ans[len(ans)-1]) {
				pos = j
				break
			}
		}
		if s[i+1] == 'L' {
			ans = append(ans, ch[(pos-1+len(ch))%len(ch)])
		} else {
			ans = append(ans, ch[(pos+1)%len(ch)])
		}
		delete(cur, ans[len(ans)-2])
	}

	for _, it := range ans {
		fmt.Printf("%d ", it.i)
	}
	fmt.Println()
}

func read() (int, []Point, string) {
	var n int
	fmt.Scan(&n)
	points := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&points[i].x, &points[i].y)
		points[i].i = i + 1
	}
	var s string
	fmt.Scan(&s)
	return n, points, s
}

func main() {
	start := time.Now()

	n, points, s := read()
	solve(points, s)

	fmt.Printf("TIME = %v\n", time.Since(start))
}
