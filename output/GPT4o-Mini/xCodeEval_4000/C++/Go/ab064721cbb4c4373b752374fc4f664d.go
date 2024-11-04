package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	x, y, i int
}

var n int
var a []Point
var s string

func read() bool {
	if _, err := fmt.Scan(&n); err != nil {
		return false
	}
	a = make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].i = i + 1
	}
	fmt.Scan(&s)
	return true
}

func (p Point) subtract(q Point) Point {
	return Point{p.x - q.x, p.y - q.y, -1}
}

func (p Point) add(q Point) Point {
	return Point{p.x + q.x, p.y + q.y, -1}
}

func (p Point) equals(q Point) bool {
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

func build() []Point {
	if n <= 1 {
		return a[:n]
	}

	up := []Point{a[0]}
	dw := []Point{a[0]}

	for i := 1; i < n; i++ {
		if i == n-1 || cross(a[n-1].subtract(a[0]), a[i].subtract(a[0])) >= 0 {
			for len(up) > 1 && cross(a[i].subtract(up[len(up)-2]), up[len(up)-1].subtract(up[len(up)-2])) < 0 {
				up = up[:len(up)-1]
			}
			up = append(up, a[i])
		}
		if i == n-1 || cross(a[n-1].subtract(a[0]), a[i].subtract(a[0])) < 0 {
			for len(dw) > 1 && cross(a[i].subtract(dw[len(dw)-2]), dw[len(dw)-1].subtract(dw[len(dw)-2])) > 0 {
				dw = dw[:len(dw)-1]
			}
			dw = append(dw, a[i])
		}
	}

	res := up
	for i := len(dw) - 2; i >= 1; i-- {
		res = append(res, dw[i])
	}

	return res
}

func solve() {
	sort.Slice(a, func(i, j int) bool {
		if a[i].x != a[j].x {
			return a[i].x < a[j].x
		}
		return a[i].y < a[j].y
	})

	ans := []Point{}
	ch := build()
	ans = append(ans, ch[0])
	if s[0] == 'L' {
		ans = append(ans, ch[len(ch)-1])
	} else {
		ans = append(ans, ch[1])
	}

	for i := 0; i < len(s); i++ {
		x := sort.Search(len(a), func(j int) bool {
			return a[j].equals(ans[len(ans)-2])
		})
		copy(a[x:], a[x+1:])
		n--

		ch = build()
		pos := sort.Search(len(ch), func(j int) bool {
			return ch[j].equals(ans[len(ans)-1])
		})

		if s[i+1] == 'L' {
			ans = append(ans, ch[(pos-1+len(ch))%len(ch)])
		} else {
			ans = append(ans, ch[(pos+1)%len(ch)])
		}
	}

	for _, it := range ans {
		fmt.Printf("%d ", it.i)
	}
	fmt.Println()
}

func main() {
	if read() {
		solve()
	}
}
