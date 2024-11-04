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

func (p1 Point) Less(p2 Point) bool {
	if p1.x != p2.x {
		return p1.x < p2.x
	}
	return p1.y < p2.y
}

var (
	n    int
	a    [2007]Point
	s    string
	INF  = int(1e9)
	INF64 = int64(1e18)
	PI   = math.Acos(-1.0)
)

func read() bool {
	if _, err := fmt.Scan(&n); err != nil {
		return false
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].i = i + 1
	}
	fmt.Scan(&s)
	return true
}

func (p1 Point) Sub(p2 Point) Point {
	return Point{p1.x - p2.x, p1.y - p2.y, -1}
}

func (p1 Point) Add(p2 Point) Point {
	return Point{p1.x + p2.x, p1.y + p2.y, -1}
}

func (p1 Point) Equal(p2 Point) bool {
	return p1.x == p2.x && p1.y == p2.y
}

func sqr(x int64) int64 {
	return x * x
}

func sdist(p1, p2 Point) int64 {
	return sqr(int64(p1.x-p2.x)) + sqr(int64(p1.y-p2.y))
}

func dot(p1, p2 Point) int64 {
	return int64(p1.x)*int64(p2.x) + int64(p1.y)*int64(p2.y)
}

func cross(p1, p2 Point) int64 {
	return int64(p1.x)*int64(p2.y) - int64(p1.y)*int64(p2.x)
}

func build() []Point {
	if n <= 1 {
		return a[:n]
	}

	up := []Point{a[0]}
	dw := []Point{a[0]}

	for i := 1; i < n; i++ {
		if i == n-1 || cross(a[n-1].Sub(a[0]), a[i].Sub(a[0])) >= 0 {
			for len(up) > 1 && cross(a[i].Sub(up[len(up)-2]), up[len(up)-1].Sub(up[len(up)-2])) < 0 {
				up = up[:len(up)-1]
			}
			up = append(up, a[i])
		}
		if i == n-1 || cross(a[n-1].Sub(a[0]), a[i].Sub(a[0])) < 0 {
			for len(dw) > 1 && cross(a[i].Sub(dw[len(dw)-2]), dw[len(dw)-1].Sub(dw[len(dw)-2])) > 0 {
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
	sort.Slice(a[:n], func(i, j int) bool {
		return a[i].Less(a[j])
	})
	cur := make(map[Point]struct{})
	for _, p := range a[:n] {
		cur[p] = struct{}{}
	}
	ans := []Point{}

	ch := build()
	ans = append(ans, ch[0])
	if s[0] == 'L' {
		ans = append(ans, ch[len(ch)-1])
	} else {
		ans = append(ans, ch[1])
	}
	delete(cur, ch[0])

	for i := 0; i < len(s); i++ {
		n = 0
		for p := range cur {
			a[n] = p
			n++
		}
		ch = build()
		pos := -1
		for j, p := range ch {
			if p.Equal(ans[len(ans)-1]) {
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

	for _, p := range ans {
		fmt.Printf("%d ", p.i)
	}
	fmt.Println()
}

func main() {
	start := time.Now()

	for read() {
		solve()
		fmt.Printf("TIME = %v\n", time.Since(start))
		start = time.Now()
	}
}
