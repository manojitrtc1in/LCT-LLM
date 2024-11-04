package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
	"strconv"
)

type Point struct {
	x, y int64
}

func crossProduct(a, b Point) int64 {
	return a.x*b.y - b.x*a.y
}

func contains(a, b Point) bool {
	return crossProduct(Point{a.x - b.x, a.y - b.y}, Point{a.x - a.x, a.y - a.y}) == 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := readInt(reader)
	a := make([]Point, n)
	index := make(map[Point]int)

	for i := 0; i < n; i++ {
		a[i] = Point{readInt64(reader), readInt64(reader)}
		index[a[i]] = i
	}

	sort.Slice(a, func(i, j int) bool {
		return a[i].x < a[j].x
	})

	d := readString(reader)
	reverseString(&d)

	ans := []Point{a[0]}
	a = a[1:]

	for len(a) > 0 {
		td := 1
		if len(d) > 0 {
			if d[len(d)-1] == 'L' {
				td = 1
			} else {
				td = -1
			}
			d = d[:len(d)-1]
		}

		cur := 0
		for i := 0; i < len(a); i++ {
			if crossProduct(Point{a[cur].x - ans[len(ans)-1].x, a[cur].y - ans[len(ans)-1].y}, Point{a[i].x - ans[len(ans)-1].x, a[i].y - ans[len(ans)-1].y})*int64(td) < 0 {
				cur = i
			}
		}
		ans = append(ans, a[cur])
		a = append(a[:cur], a[cur+1:]...)
	}

	aaa := make([]int, len(ans))
	for i, t := range ans {
		aaa[i] = index[t] + 1
	}
	for _, v := range aaa {
		fmt.Fprint(writer, v, " ")
	}
	fmt.Fprintln(writer)
}

func readInt(reader *bufio.Reader) int {
	line, _ := reader.ReadString('\n')
	val, _ := strconv.Atoi(line[:len(line)-1])
	return val
}

func readInt64(reader *bufio.Reader) int64 {
	line, _ := reader.ReadString('\n')
	val, _ := strconv.ParseInt(line[:len(line)-1], 10, 64)
	return val
}

func readString(reader *bufio.Reader) string {
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

func reverseString(s *string) {
	r := []rune(*s)
	for i, j := 0, len(r)-1; i < j; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	*s = string(r)
}
