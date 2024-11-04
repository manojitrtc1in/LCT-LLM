package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

type FastIO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewFastIO(reader io.Reader, writer io.Writer) *FastIO {
	return &FastIO{
		reader: bufio.NewReader(reader),
		writer: bufio.NewWriter(writer),
	}
}

func (io *FastIO) ReadInt() int {
	num, _ := strconv.Atoi(io.ReadString())
	return num
}

func (io *FastIO) ReadString() string {
	str, _ := io.reader.ReadString('\n')
	return str[:len(str)-1]
}

func (io *FastIO) WriteString(str string) {
	io.writer.WriteString(str)
}

func (io *FastIO) Flush() {
	io.writer.Flush()
}

type Point struct {
	x, y int
}

type Points []Point

func (p Points) Len() int {
	return len(p)
}

func (p Points) Less(i, j int) bool {
	if p[i].x == p[j].x {
		return p[i].y < p[j].y
	}
	return p[i].x < p[j].x
}

func (p Points) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func main() {
	io := NewFastIO(os.Stdin, os.Stdout)
	defer io.Flush()

	n := io.ReadInt()
	points := make(Points, n)
	for i := 0; i < n; i++ {
		points[i].x = io.ReadInt()
		points[i].y = io.ReadInt()
	}

	sort.Sort(points)

	last := points[0]
	for i := 1; i < n; i++ {
		if points[i].x > last.x {
			last = points[i]
		} else if points[i].x == last.x && points[i].y < last.y {
			last = points[i]
		}
	}

	last.x = 1
	io.WriteString(strconv.Itoa(last.y) + " ")
	for i := 0; i < n-2; i++ {
		c := io.ReadString()
		var cmp func(a, b Point) int
		if c == "L" {
			cmp = func(a, b Point) int {
				return -cross(a.x-last.x, a.y-last.y, b.x-last.x, b.y-last.y)
			}
		} else {
			cmp = func(a, b Point) int {
				return cross(a.x-last.x, a.y-last.y, b.x-last.x, b.y-last.y)
			}
		}

		var choose Point
		for _, pt := range points {
			if pt.x == last.x && pt.y == last.y {
				continue
			}
			if choose == (Point{}) || cmp(pt, choose) < 0 {
				choose = pt
			}
		}

		last = choose
		last.x = 1
		io.WriteString(strconv.Itoa(last.y) + " ")
	}

	for _, pt := range points {
		if pt.x == last.x && pt.y == last.y {
			continue
		}
		io.WriteString(strconv.Itoa(pt.y) + " ")
	}
}

func cross(x1, y1, x2, y2 int) int {
	return x1*y2 - y1*x2
}
