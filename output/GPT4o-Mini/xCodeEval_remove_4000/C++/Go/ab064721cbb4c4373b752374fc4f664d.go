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

func read() (int, []Point, string) {
	var n int
	if _, err := fmt.Scan(&n); err != nil {
		return 0, nil, ""
	}
	a := make([]Point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].i = i + 1
	}
	var s string
	fmt.Scan(&s)
	return n, a, s
}

func (a Point) Sub(b Point) Point {
	return Point{a.x - b.x, a.y - b.y, -1}
}

func (a Point) Add(b Point) Point {
	return Point{a.x + b.x, a.y + b.y, -1}
}

func (a Point) Equals(b Point) bool {
	return a.x == b.x && a.y == b.y
}

func sqr(x int64) int64 {
	return x * x
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

func build(n int, a []Point) []Point {
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

func solve(n int, a []Point, s string) {
	sort.Slice(a, func(i, j int) bool {
		return a[i].Less(a[j])
	})

	ans := []Point{}
	ch := build(n, a)
	ans = append(ans, ch[0])
	if s[0] == 'L' {
		ans = append(ans, ch[len(ch)-1])
	} else {
		ans = append(ans, ch[1])
	}

	for i := 0; i < len(s); i++ {
		x := sort.Search(n, func(j int) bool {
			return a[j].Equals(ans[len(ans)-2])
		})
		copy(a[x:], a[x+1:])
		n--

		ch = build(n, a)
		pos := sort.Search(len(ch), func(j int) bool {
			return ch[j].Equals(ans[len(ans)-1])
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
	start := time.Now()

	for {
		n, a, s := read()
		if n == 0 {
			break
		}
		solve(n, a, s)
		fmt.Printf("TIME = %v\n", time.Since(start))
		start = time.Now()
	}
}
