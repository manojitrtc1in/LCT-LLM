package main

import (
	"bufio"
	"fmt"
	"io"
	"math/rand"
	"time"
)

type TaskB struct {
	x int64
}

func (t *TaskB) solve(testNumber int, in *InputReader, out *OutputWriter) {
	count := in.readInt()
	ones := in.readInt()
	t.x = in.readLong()
	a := make([]int, count)
	for i := 0; i < count; i++ {
		a[i] = i + 1
	}
	t.shuffle(count, a)
	b := make([]int, count)
	for i := 0; i < ones; i++ {
		b[i] = 1
	}
	t.shuffle(count, b)
	answer := make([]int, count)
	size := (count + 31) >> 5
	ready := make([]int, size)
	mask := make([]int, size)
	for i := 0; i < size; i++ {
		for j := i * 32; j < (i+1)*32 && j < count; j++ {
			if b[j] == 1 {
				mask[i] += 1 << (j - i*32)
			}
		}
	}
	upMasks := make([][]int, 32)
	downMasks := make([][]int, 32)
	for i := 0; i < 32; i++ {
		filter := -1
		if i != 0 {
			filter = (1 << (32 - i)) - 1
		}
		otherShift := 32 - i
		upMasks[i] = make([]int, size)
		downMasks[i] = make([]int, size)
		for j := 0; j < size; j++ {
			upMasks[i][j] = mask[j] & filter
			downMasks[i][j] = mask[j] >> otherShift
		}
	}
	order := createOrder(a)
	reverse(order)
	for _, i := range order {
		value := a[i]
		shift := i & 31
		otherShift := 32 - shift
		filter := -1
		if shift != 0 {
			filter = (1 << (32 - shift)) - 1
		}
		start := i >> 5
		upTo := size - start - 1
		otherFilter := (1 << shift) - 1
		if otherFilter == -1 {
			otherFilter = 0
		}
		for j := 0; j < upTo; j++ {
			if (ready[j+start]>>shift&upMasks[shift][j]) != upMasks[shift][j] {
				for k := (j+start)*32 + shift; k < (j+start+1)*32 && k < count; k++ {
					if b[k-i] == 1 && answer[k] == 0 {
						answer[k] = value
						ready[k>>5] += 1 << (k & 31)
					}
				}
			}
			if (ready[j+start+1]&downMasks[shift][j]) != downMasks[shift][j] {
				for k := (j+start+1)*32; k < (j+start+1)*32+shift && k < count; k++ {
					if b[k-i] == 1 && answer[k] == 0 {
						answer[k] = value
						ready[k>>5] += 1 << (k & 31)
					}
				}
			}
		}
		if (ready[upTo+start]>>shift&upMasks[shift][upTo]) != upMasks[shift][upTo] {
			for k := (upTo+start)*32 + shift; k < (upTo+start+1)*32 && k < count; k++ {
				if b[k-i] == 1 && answer[k] == 0 {
					answer[k] = value
					ready[k>>5] += 1 << (k & 31)
				}
			}
		}
	}
	out.printLine(answer)
}

func (t *TaskB) shuffle(count int, a []int) {
	rand.Seed(time.Now().UnixNano())
	for i := 0; i < count; i++ {
		index := t.next() % (i + 1)
		a[i], a[index] = a[index], a[i]
	}
}

func (t *TaskB) next() int {
	t.x = (t.x*37 + 10007) % 1000000007
	return int(t.x)
}

type InputReader struct {
	scanner *bufio.Scanner
}

func NewInputReader(r io.Reader) *InputReader {
	return &InputReader{scanner: bufio.NewScanner(r)}
}

func (in *InputReader) readInt() int {
	in.scanner.Scan()
	var res int
	fmt.Sscanf(in.scanner.Text(), "%d", &res)
	return res
}

func (in *InputReader) readLong() int64 {
	in.scanner.Scan()
	var res int64
	fmt.Sscanf(in.scanner.Text(), "%d", &res)
	return res
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(w io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(w)}
}

func (out *OutputWriter) printLine(array []int) {
	for i, v := range array {
		if i != 0 {
			out.writer.WriteString(" ")
		}
		fmt.Fprintf(out.writer, "%d", v)
	}
	out.writer.WriteString("\n")
	out.writer.Flush()
}

func createOrder(size int) []int {
	order := make([]int, size)
	for i := 0; i < size; i++ {
		order[i] = i
	}
	return order
}

func reverse(array []int) {
	for i, j := 0, len(array)-1; i < j; i, j = i+1, j-1 {
		array[i], array[j] = array[j], array[i]
	}
}

func main() {
	in := NewInputReader(io.Stdin)
	out := NewOutputWriter(io.Stdout)
	solver := &TaskB{}
	solver.solve(1, in, out)
}
