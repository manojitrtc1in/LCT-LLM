package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type pr struct {
	first  int
	second int64
}

type TaskD struct {
	answer [][]pr
}

func (t *TaskD) solve(inp *bufio.Reader, outp *bufio.Writer) {
	n := readInt(inp)
	m := readInt(inp)
	b := readIntArray(inp, n)
	w := readIntArray(inp, n)
	x := make([]int, n-1)
	y := make([]int, n-1)
	for i := 0; i < n-1; i++ {
		x[i] = readInt(inp)
		y[i] = readInt(inp)
	}

	graph := make([][]int, n)
	for i := 0; i < n-1; i++ {
		x[i]--
		y[i]--
		graph[x[i]] = append(graph[x[i]], y[i])
		graph[y[i]] = append(graph[y[i]], x[i])
	}

	q := make([]int, n)
	var calcQ func(int, int) int
	calcQ = func(vert, last int) int {
		res := 1
		for _, next := range graph[vert] {
			if next == last {
				continue
			}
			res += calcQ(next, vert)
		}
		q[vert] = res
		return res
	}
	calcQ(0, -1)

	answer := make([][]pr, n)
	for i := 0; i < n; i++ {
		answer[i] = make([]pr, n+2)
	}

	temp := make([]pr, n+2)
	var go func(int, int)
	go = func(vert, last int) {
		id := -1
		for _, next := range graph[vert] {
			if next == last {
				continue
			}
			go(next, vert)
			if id == -1 || q[next] > q[id] {
				id = next
			}
		}
		cur := answer[vert]
		delta := w[vert] - b[vert]
		if id == -1 {
			cur[0] = pr{0, delta}
			cur[1] = pr{boolToInt(delta > 0), 0}
			return
		}

		aid := answer[id]
		for i := 0; i <= q[id]; i++ {
			cur[i] = aid[i]
			cur[i].second += delta
		}

		sz := q[id]
		for i := sz + 1; i <= q[vert]; i++ {
			cur[i] = pr{-1, 0}
		}
		for _, next := range graph[vert] {
			if next == last || next == id {
				continue
			}
			anext := answer[next]
			for i := 0; i <= sz; i++ {
				temp[i] = cur[i]
				cur[i] = pr{-1, 0}
			}

			nsz := sz + q[next]
			for i := 0; i <= sz; i++ {
				for j := 0; j <= q[next]; j++ {
					maxim(&cur[i+j], pr{temp[i].first + anext[j].first, temp[i].second + anext[j].second})
				}
			}
			sz = nsz
		}
		if vert == 0 {
			for i := n - 1; i >= 0; i-- {
				cur[i+1] = pr{cur[i].first + boolToInt(cur[i].second > 0), 0}
			}
			return
		}

		for i := sz; i >= 0; i-- {
			maxim(&cur[i+1], pr{cur[i].first + boolToInt(cur[i].second > 0), 0})
		}
	}

	go(0, -1)
	printLine(outp, answer[0][m].first)
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

func maxim(a *pr, b pr) {
	if b.first > a.first || (b.first == a.first && b.second > a.second) {
		*a = b
	}
}

func readInt(inp *bufio.Reader) int {
	num, _ := strconv.Atoi(readString(inp))
	return num
}

func readIntArray(inp *bufio.Reader, n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = readInt(inp)
	}
	return arr
}

func readString(inp *bufio.Reader) string {
	str, _ := inp.ReadString('\n')
	return str[:len(str)-1]
}

func printLine(outp *bufio.Writer, a ...interface{}) {
	fmt.Fprintln(outp, a...)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var solver TaskD
	n := readInt(in)
	for i := 0; i < n; i++ {
		solver.solve(in, out)
	}
}
