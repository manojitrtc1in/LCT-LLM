package main

import (
	"bufio"
	"fmt"
	"io"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var count, ones int
	var x int64
	fmt.Fscan(reader, &count, &ones, &x)
	a := make([]int, count)
	for i := 0; i < count; i++ {
		a[i] = i + 1
	}
	shuffle(count, a)
	b := make([]int, count)
	for i := 0; i < ones; i++ {
		b[i] = 1
	}
	shuffle(count, b)
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
		var filter int
		if i == 0 {
			filter = -1
		} else {
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
	order := make([]int, count)
	for i := 0; i < count; i++ {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return a[order[i]] > a[order[j]]
	})
	for _, i := range order {
		value := a[i]
		shift := i & 31
		otherShift := 32 - shift
		var filter int
		if shift == 0 {
			filter = -1
		} else {
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
	fmt.Fprintln(writer, answer)
}

func shuffle(count int, a []int) {
	rand.Seed(10007)
	for i := 0; i < count; i++ {
		index := rand.Intn(i + 1)
		temp := a[i]
		a[i] = a[index]
		a[index] = temp
	}
}

func isWhitespace(c int) bool {
	return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1
}

type InputReader struct {
	reader *bufio.Reader
}

func NewInputReader(reader io.Reader) *InputReader {
	return &InputReader{reader: bufio.NewReader(reader)}
}

func (in *InputReader) ReadInt() int {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := 1
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := 0
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("Invalid input")
		}
		res *= 10
		res += int(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) ReadLong() int64 {
	c := in.read()
	for isWhitespace(c) {
		c = in.read()
	}
	sgn := int64(1)
	if c == '-' {
		sgn = -1
		c = in.read()
	}
	res := int64(0)
	for !isWhitespace(c) {
		if c < '0' || c > '9' {
			panic("Invalid input")
		}
		res *= 10
		res += int64(c - '0')
		c = in.read()
	}
	return res * sgn
}

func (in *InputReader) read() int {
	c, err := in.reader.ReadByte()
	if err != nil {
		panic(err)
	}
	return int(c)
}

type OutputWriter struct {
	writer *bufio.Writer
}

func NewOutputWriter(writer io.Writer) *OutputWriter {
	return &OutputWriter{writer: bufio.NewWriter(writer)}
}

func (out *OutputWriter) Println(a ...interface{}) {
	fmt.Fprintln(out.writer, a...)
}

func (out *OutputWriter) Flush() {
	out.writer.Flush()
}

func main() {
	reader := NewInputReader(os.Stdin)
	writer := NewOutputWriter(os.Stdout)
	defer writer.Flush()

	var count, ones int
	var x int64
	fmt.Fscan(reader, &count, &ones, &x)
	a := make([]int, count)
	for i := 0; i < count; i++ {
		a[i] = i + 1
	}
	shuffle(count, a)
	b := make([]int, count)
	for i := 0; i < ones; i++ {
		b[i] = 1
	}
	shuffle(count, b)
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
		var filter int
		if i == 0 {
			filter = -1
		} else {
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
	order := make([]int, count)
	for i := 0; i < count; i++ {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return a[order[i]] > a[order[j]]
	})
	for _, i := range order {
		value := a[i]
		shift := i & 31
		otherShift := 32 - shift
		var filter int
		if shift == 0 {
			filter = -1
		} else {
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
	fmt.Fprintln(writer, answer)
}
