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

func subtract(a, b point) point {
	return point{a.x - b.x, a.y - b.y, -1}
}

func add(a, b point) point {
	return point{a.x + b.x, a.y + b.y, -1}
}

func equal(a, b point) bool {
	return a.x == b.x && a.y == b.y
}

func squaredDistance(a, b point) int64 {
	return int64((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y))
}

func dot(a, b point) int64 {
	return int64(a.x*b.x + a.y*b.y)
}

func cross(a, b point) int64 {
	return int64(a.x*b.y - a.y*b.x)
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
		if i == n-1 || cross(subtract(a[n-1], a[0]), subtract(a[i], a[0])) >= 0 {
			for len(up) > 1 && cross(subtract(a[i], up[len(up)-2]), subtract(up[len(up)-1], up[len(up)-2])) < 0 {
				up = up[:len(up)-1]
			}
			up = append(up, a[i])
		}
		if i == n-1 || cross(subtract(a[n-1], a[0]), subtract(a[i], a[0])) < 0 {
			for len(dw) > 1 && cross(subtract(a[i], dw[len(dw)-2]), subtract(dw[len(dw)-1], dw[len(dw)-2])) > 0 {
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

	var ans []point

	ch := build(a)
	ans = append(ans, ch[0])
	if s[0] == 'L' {
		ans = append(ans, ch[len(ch)-1])
	} else {
		ans = append(ans, ch[1])
	}

	for i := 0; i < len(s); i++ {
		x := -1
		for j := 0; j < n; j++ {
			if equal(ans[len(ans)-2], a[j]) {
				x = j
				break
			}
		}
		copy(a[x:], a[x+1:])
		a = a[:n-1]
		n--
		ch := build(a)
		pos := -1
		for k := 0; k < len(ch); k++ {
			if equal(ans[len(ans)-1], ch[k]) {
				pos = k
				break
			}
		}
		if s[i+1] == 'L' {
			ans = append(ans, ch[(pos-1+len(ch))%len(ch)])
		} else {
			ans = append(ans, ch[(pos+1)%len(ch)])
		}
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
