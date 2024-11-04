package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
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
		if a[i].x != a[j].x {
			return a[i].x < a[j].x
		}
		return a[i].y < a[j].y
	})

	cur := make(map[point]bool)
	for _, p := range a {
		cur[p] = true
	}

	var ans []point

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
			if equal(p, ans[len(ans)-1]) {
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
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, _ := strconv.Atoi(scanner.Text())
	a := make([]point, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		x, _ := strconv.Atoi(scanner.Text())
		scanner.Scan()
		y, _ := strconv.Atoi(scanner.Text())
		a[i] = point{x, y, i + 1}
	}

	scanner.Scan()
	s := scanner.Text()

	solve(n, a, s)
}
