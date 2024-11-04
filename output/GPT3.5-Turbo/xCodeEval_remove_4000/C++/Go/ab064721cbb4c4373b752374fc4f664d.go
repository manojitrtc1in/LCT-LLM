package main

import (
	"fmt"
	"math"
	"math/rand"
	"sort"
	"time"
)

type point struct {
	x, y, i int
}

func (p point) String() string {
	return fmt.Sprintf("(%d, %d)", p.x, p.y)
}

func less(a, b point) bool {
	if a.x != b.x {
		return a.x < b.x
	}
	return a.y < b.y
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
	return int64(math.Pow(float64(a.x-b.x), 2) + math.Pow(float64(a.y-b.y), 2))
}

func dot(a, b point) int64 {
	return int64(a.x*b.x) + int64(a.y*b.y)
}

func cross(a, b point) int64 {
	return int64(a.x*b.y) - int64(a.y*b.x)
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
		return less(a[i], a[j])
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
			if equal(a[j], ans[len(ans)-2]) {
				x = j
				break
			}
		}
		copy(a[x:], a[x+1:])
		a = a[:n-1]
		n--
		ch = build(a)
		pos := -1
		for j := 0; j < len(ch); j++ {
			if equal(ch[j], ans[len(ans)-1]) {
				pos = j
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
	rand.Seed(time.Now().UnixNano())

	n := 0
	var a []point
	s := ""

	fmt.Scan(&n)
	a = make([]point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i].x, &a[i].y)
		a[i].i = i + 1
	}
	fmt.Scan(&s)

	solve(n, a, s)
}
