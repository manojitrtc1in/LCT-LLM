package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Point struct {
	X, Y, Index int
}

type Points []Point

func (p Points) Len() int {
	return len(p)
}

func (p Points) Less(i, j int) bool {
	if p[i].X == p[j].X {
		return p[i].Y < p[j].Y
	}
	return p[i].X < p[j].X
}

func (p Points) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	points := make(Points, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &points[i].X, &points[i].Y)
		points[i].Index = i + 1
	}

	sort.Sort(points)

	last := points[0]
	for _, pt := range points {
		if pt.X == last.X {
			if pt.Y < last.Y {
				last = pt
			}
		} else if pt.X > last.X {
			last = pt
		}
	}

	last.Index = 1
	fmt.Fprintf(writer, "%d ", last.Index)

	for i := 0; i < n-2; i++ {
		var c rune
		fmt.Fscan(reader, &c)

		var cmp func(a, b Point) int
		if c == 'L' {
			cmp = func(a, b Point) int {
				return -cross(a.X-last.X, a.Y-last.Y, b.X-last.X, b.Y-last.Y)
			}
		} else {
			cmp = func(a, b Point) int {
				return cross(a.X-last.X, a.Y-last.Y, b.X-last.X, b.Y-last.Y)
			}
		}

		var choose *Point
		for _, pt := range points {
			if pt.Index == 1 {
				continue
			}
			if choose == nil || cmp(pt, *choose) < 0 {
				choose = &pt
			}
		}
		last = choose
		last.Index = 1
		fmt.Fprintf(writer, "%d ", last.Index)
	}

	for _, pt := range points {
		if pt.Index == 1 {
			continue
		}
		fmt.Fprintf(writer, "%d ", pt.Index)
	}
}

func cross(x1, y1, x2, y2 int) int {
	return x1*y2 - y1*x2
}
