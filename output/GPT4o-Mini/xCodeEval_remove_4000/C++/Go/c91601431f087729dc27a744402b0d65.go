package main

import (
	"fmt"
	"math"
	"sort"
)

type Point struct {
	x, y int
}

func (p Point) Less(other Point) bool {
	return p.x*other.y < p.y*other.x
}

var p [10101]Point
var a [10101]Point
var used [101010]bool

func solve() int {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i].x, &p[i].y)
	}
	cur := 0
	for i := 0; i < n; i++ {
		if p[i].x < p[cur].x || (p[i].x == p[cur].x && p[i].y < p[cur].y) {
			cur = i
		}
	}
	var s string
	fmt.Scan(&s)
	s += "R"
	ans := []int{cur}
	for i := 0; i+1 < n; i++ {
		used[cur] = true
		zero := p[cur]
		for j := 0; j < n; j++ {
			a[j] = Point{p[j].x - zero.x, p[j].y - zero.y}
		}
		idx := -1
		for j := 0; j < n; j++ {
			if !used[j] {
				if idx == -1 {
					idx = j
				} else {
					if s[i] == 'R' && a[j].Less(a[idx]) {
						idx = j
					}
					if s[i] == 'L' && a[idx].Less(a[j]) {
						idx = j
					}
				}
			}
		}
		cur = idx
		ans = append(ans, cur)
	}
	for _, x := range ans {
		fmt.Print(x + 1, " ")
	}
	fmt.Println()

	return 0
}

func main() {
	solve()
}
