package main

import (
	"bufio"
	"fmt"
	"io"
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

type PositionList []*Position

func (p PositionList) Len() int           { return len(p) }
func (p PositionList) Swap(i, j int)      { p[i], p[j] = p[j], p[i] }
func (p PositionList) Less(i, j int) bool { return p[i].row < p[j].row || (p[i].row == p[j].row && p[i].id < p[j].id) }

type TaskE struct{}

func (t *TaskE) solve(testNumber int, in *InputReader, out *OutputWriter) {
	r := in.readInt()
	c := in.readInt()
	n := in.readInt()
	k := in.readInt()
	x := make([]int, n)
	y := make([]int, n)
	in.readIntArrays(&x, &y)
	sort.Ints(x)
	sort.Ints(y)
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
	answer := int64(0)
	for i := 0; i < c; i++ {
		at := 0
		for at < n && y[at] < i {
			at++
		}
		for j := 0; j < k-1; j++ {
			headPosition[j+1].link = tailPosition[j]
		}
		set := make(PositionList, 0)
		set = append(set, headPosition[k-1])
		set = append(set, tailPosition[0])
		headPosition[k-1].next = tailPosition[0]
		tailPosition[0].last = headPosition[k-1]
		delta := int64(0)
		for j := i; j < c; j++ {
			for at < n && y[at] == j {
				where := set.lowerBound(positions[at])
				current := where
				for l := 1; l < k; l++ {
					delta -= current.value(r)
					current = current.last
				}
				next := where.next
				delta -= next.value(r)
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
				delta += next.value(r)
				delta += current.value(r)
				current = where
				for l := 1; l < k; l++ {
					current.link = current.link.last
					delta += current.value(r)
					current = current.last
				}
				at++
			}
			answer += delta
		}
	}
	out.printLine(answer)
}

func (p *Position) value(r int) int64 {
	if p.link == nil {
		return 0
	}
	return int64((p.row - p.last.row) * (r - p.link.row))
}

type IntIterator interface {
	value() int
	advance() bool
	isValid() bool
}

type IntComparator interface {
	compare(first, second int) int
}

type IntCollection interface {
	IntStream
	size() int
	add(value int)
	addAll(values IntStream)
}

type IntList interface {
	IntCollection
	get(index int) int
	set(index, value int)
	addAt(index, value int)
	removeAt(index int)
	sort(comparator IntComparator) IntList
	subList(from, to int) IntList
}

type IntArray struct {
	data []int
}

func (a *IntArray) size() int {
	return len(a.data)
}

func (a *IntArray) get(index int) int {
	return a.data[index]
}

func (a *IntArray) set(index, value int) {
	a.data[index] = value
}

func (a *IntArray) addAt(index, value int) {
	a.data = append(a.data[:index], append([]int{value}, a.data[index:]...)...)
}

func (a *IntArray) removeAt(index int) {
	a.data = append(a.data[:index], a.data[index+1:]...)
}

func (a *IntArray) add(value int) {
	a.data = append(a.data, value)
}

func (a *IntArray) addAll(values IntStream) {
	for it := values.intIterator(); it.isValid(); it.advance() {
		a.add(it.value())
	}
}

func (a *IntArray) sort(comparator IntComparator) IntList {
	sort.Slice(a.data, func(i, j int) bool {
		return comparator.compare(a.data[i], a.data[j]) < 0
	})
	return a
}

func (a *IntArray) subList(from, to int) IntList {
	return &IntArray{data: a.data[from:to]}
}

type IntStream interface {
	IntIterator
	iterator() Iterator
	compareTo(c IntStream) int
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(r)}
}

func (r *InputReader) readInt() int {
	var sign, num int = 1, 0
	var err error
	for {
		var b byte
		b, err = r.reader.ReadByte()
		if err != nil {
			break
		}
		if b >= '0' && b <= '9' {
			num = int(b - '0')
			break
		}
		if b == '-' {
			sign = -1
			break
		}
	}
	for {
		var b byte
		b, err = r.reader.ReadByte()
		if err != nil || b < '0' || b > '9' {
			break
		}
		num = num*10 + int(b-'0')
	}
	return num * sign
}

func (r *InputReader) readIntArrays(arrays ...*[]int) {
	for i := 0; i < len((*arrays)[0]); i++ {
		for j := 0; j < len(arrays); j++ {
			(*arrays)[j][i] = r.readInt()
		}
	}
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (w *OutputWriter) printLine(i int64) {
	fmt.Fprintln(w.writer, i)
}

func (w *OutputWriter) close() {
	w.writer.Flush()
}

func main() {
	input := NewInputReader(os.Stdin)
	output := NewOutputWriter(os.Stdout)
	defer output.close()
	taskE := &TaskE{}
	taskE.solve(1, input, output)
}
