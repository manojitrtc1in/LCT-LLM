package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (in *InputReader) ReadInt() int {
	var x int
	_, _ = fmt.Fscan(in.reader, &x)
	return x
}

func (in *InputReader) ReadInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = in.ReadInt()
	}
	return arr
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	_, _ = fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	_ = out.writer.Flush()
}

type Position struct {
	row  int
	id   int
	last *Position
	next *Position
	link *Position
}

func NewPosition(row, id int) *Position {
	return &Position{row: row, id: id}
}

func (p *Position) CompareTo(o *Position) int {
	if p.row != o.row {
		return p.row - o.row
	}
	return p.id - o.id
}

func (p *Position) Value(r int) int64 {
	if p.link == nil {
		return 0
	}
	return int64((p.row - p.last.row) * (r - p.link.row))
}

type TaskE struct{}

func (t *TaskE) Solve(testNumber int, in *InputReader, out *OutputWriter) {
	r := in.ReadInt()
	c := in.ReadInt()
	n := in.ReadInt()
	k := in.ReadInt()
	x := in.ReadInts(n)
	y := in.ReadInts(n)
	decreaseByOne(x, y)
	orderBy(y, x)
	headPosition := make([]*Position, k)
	for i := 0; i < k; i++ {
		headPosition[i] = NewPosition(-1, -1)
		if i != 0 {
			headPosition[i].last = headPosition[i-1]
			headPosition[i-1].next = headPosition[i]
		}
	}
	tailPosition := make([]*Position, k)
	for i := 0; i < k; i++ {
		tailPosition[i] = NewPosition(r, -2)
		if i != 0 {
			tailPosition[i].last = tailPosition[i-1]
			tailPosition[i-1].next = tailPosition[i]
		}
	}
	positions := make([]*Position, n)
	for i := 0; i < n; i++ {
		positions[i] = NewPosition(x[i], i)
	}
	answer := int64(0)
	for i := 0; i < c; i++ {
		at := 0
		for at < n && y[at] < i {
			at++
		}
		for j := 0; j < k-1; j++ {
			headPosition[j+1].link = tailPosition[j]
		}
		set := make([]*Position, 0)
		set = append(set, headPosition[k-1])
		set = append(set, tailPosition[0])
		headPosition[k-1].next = tailPosition[0]
		tailPosition[0].last = headPosition[k-1]
		delta := int64(0)
		for j := i; j < c; j++ {
			for at < n && y[at] == j {
				where := lowerBound(set, positions[at])
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
				set = append(set, current)
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
	out.Println(answer)
}

func lowerBound(arr []*Position, target *Position) *Position {
	left, right := 0, len(arr)
	for left < right {
		mid := (left + right) / 2
		if arr[mid].CompareTo(target) < 0 {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return arr[left]
}

func decreaseByOne(arrs ...[]int) {
	for _, arr := range arrs {
		for i := 0; i < len(arr); i++ {
			arr[i]--
		}
	}
}

func orderBy(base []int, arrays ...[]int) {
	order := createOrder(len(base))
	orderInts(order, base)
	for _, arr := range arrays {
		orderInts(order, arr)
	}
}

func createOrder(size int) []int {
	arr := make([]int, size)
	for i := 0; i < size; i++ {
		arr[i] = i
	}
	return arr
}

func orderInts(order, arr []int) {
	temp := make([]int, len(order))
	for i := 0; i < len(order); i++ {
		temp[i] = arr[order[i]]
	}
	copy(arr, temp)
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	task := &TaskE{}
	task.Solve(1, input, output)
	output.Flush()
}
