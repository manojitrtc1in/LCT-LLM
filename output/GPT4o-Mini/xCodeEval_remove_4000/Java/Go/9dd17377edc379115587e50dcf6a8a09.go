package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Position struct {
	row  int
	id   int
	last *Position
	next *Position
	link *Position
}

func (p *Position) Compare(o *Position) int {
	if p.row != o.row {
		return p.row - o.row
	}
	return p.id - o.id
}

func (p *Position) Value(r int) int64 {
	if p.link == nil {
		return 0
	}
	return int64(p.row-p.last.row) * int64(r-p.link.row)
}

type TaskE struct{}

func (t *TaskE) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	r := in.ReadInt()
	c := in.ReadInt()
	n := in.ReadInt()
	k := in.ReadInt()
	x := make([]int, n)
	y := make([]int, n)
	id5(in, x, y)
	id4(x, y)
	orderBy(y, x)
	headPosition := make([]*Position, k)
	for i := 0; i < k; i++ {
		headPosition[i] = &Position{-1, -1, nil, nil, nil}
		if i != 0 {
			headPosition[i].last = headPosition[i-1]
			headPosition[i-1].next = headPosition[i]
		}
	}
	tailPosition := make([]*Position, k)
	for i := 0; i < k; i++ {
		tailPosition[i] = &Position{r, -2, nil, nil, nil}
		if i != 0 {
			tailPosition[i].last = tailPosition[i-1]
			tailPosition[i-1].next = tailPosition[i]
		}
	}
	positions := make([]*Position, n)
	for i := 0; i < n; i++ {
		positions[i] = &Position{x[i], i, nil, nil, nil}
	}
	var answer int64
	for i := 0; i < c; i++ {
		at := 0
		for at < n && y[at] < i {
			at++
		}
		for j := 0; j < k-1; j++ {
			headPosition[j+1].link = tailPosition[j]
		}
		set := make(map[*Position]struct{})
		set[headPosition[k-1]] = struct{}{}
		set[tailPosition[0]] = struct{}{}
		headPosition[k-1].next = tailPosition[0]
		tailPosition[0].last = headPosition[k-1]
		var delta int64
		for j := i; j < c; j++ {
			for at < n && y[at] == j {
				var where *Position
				for pos := range set {
					if where == nil || pos.Compare(positions[at]) < 0 {
						where = pos
					}
				}
				current := where
				for l := 1; l < k; l++ {
					delta -= current.Value(r)
					current = current.last
				}
				next := where.next
				delta -= next.Value(r)
				current = positions[at]
				where.next = current
				current.last = where
				next.last = current
				current.next = next
				if k == 1 {
					current.link = current
				} else {
					current.link = where.link
				}
				set[current] = struct{}{}
				delta += next.Value(r)
				delta += current.Value(r)
				current = where
				for l := 1; l < k; l++ {
					current.link = current.link.last
					delta += current.Value(r)
					current = current.last
				}
				at++
			}
			answer += delta
		}
	}
	out.PrintLine(answer)
}

func id5(in *InputReader, arrays ...[]int) {
	for i := 0; i < len(arrays[0]); i++ {
		for j := range arrays {
			arrays[j][i] = in.ReadInt()
		}
	}
}

func id4(arrays ...[]int) {
	for _, array := range arrays {
		for i := range array {
			array[i]--
		}
	}
}

func orderBy(base []int, arrays ...[]int) {
	order := createOrder(len(base))
	sort.Slice(order, func(i, j int) bool {
		return base[order[i]] < base[order[j]]
	})
	for _, array := range arrays {
		temp := make([]int, len(array))
		for i, idx := range order {
			temp[i] = array[idx]
		}
		copy(array, temp)
	}
}

func createOrder(size int) []int {
	order := make([]int, size)
	for i := range order {
		order[i] = i
	}
	return order
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader() *InputReader {
	return &InputReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (in *InputReader) ReadInt() int {
	in.scanner.Scan()
	var x int
	fmt.Sscanf(in.scanner.Text(), "%d", &x)
	return x
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(os.Stdout)}
}

func (out *OutputWriter) PrintLine(i int64) {
	fmt.Fprintln(out.writer, i)
}

func (out *OutputWriter) Close() {
	out.writer.Flush()
}

func main() {
	in := NewInputReader()
	out := NewOutputWriter()
	solver := TaskE{}
	solver.Solve(1, in, out)
	out.Close()
}
