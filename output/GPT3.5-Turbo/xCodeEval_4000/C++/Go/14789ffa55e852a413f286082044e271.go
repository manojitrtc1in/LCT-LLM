package main

import (
	"fmt"
	"math"
	"sort"
)

type point struct {
	x, y, i int
}

func (p point) String() string {
	return fmt.Sprintf("(%d, %d)", p.x, p.y)
}

func (p point) Sub(q point) point {
	return point{p.x - q.x, p.y - q.y, -1}
}

func (p point) Add(q point) point {
	return point{p.x + q.x, p.y + q.y, -1}
}

func (p point) Equal(q point) bool {
	return p.x == q.x && p.y == q.y
}

func sqr(a int) int {
	return a * a
}

func sdist(a, b point) int {
	return sqr(a.x-b.x) + sqr(a.y-b.y)
}

func dot(a, b point) int {
	return a.x*b.x + a.y*b.y
}

func cross(a, b point) int {
	return a.x*b.y - a.y*b.x
}

func build(a []point) []point {
	n := len(a)
	if n <= 1 {
		return a[:n]
	}

	var up, dw []point
	up = append(up, a[0])
	dw = append(dw, a[0])

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

	res := append(up, dw[1:len(dw)-1]...)
	return res
}

func solve(n int, a []point, s string) {
	sort.Slice(a, func(i, j int) bool {
		if a[i].x != a[j].x {
			return a[i].x < a[j].x
		}
		return a[i].y < a[j].y
	})

	cur := make(map[point]bool)
	for _, p := range a {
		cur[p] = true
	}

	ans := make([]point, 0)
	ch := build(a)
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
		ch := build(a)
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
	var n int
	fmt.Scan(&n)

	a := make([]point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].i = i + 1
	}

	var s string
	fmt.Scan(&s)

	solve(n, a, s)
}
