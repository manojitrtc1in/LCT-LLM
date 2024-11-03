package main

import (
	"fmt"
	"math"
)

type InputReader struct {
	buf  []byte
	cur  int
	next int
}

func NewInputReader() *InputReader {
	return &InputReader{}
}

func (in *InputReader) read() byte {
	if in.cur == in.next {
		in.next = 0
		buf := make([]byte, 1024)
		n, err := os.Stdin.Read(buf)
		if err != nil || n == 0 {
			return 0
		}
		in.buf = buf[:n]
	}
	in.cur++
	return in.buf[in.cur-1]
}

func (in *InputReader) readInt() int {
	c := in.read()
	for c <= 32 {
		c = in.read()
	}
	sign := 1
	if c == '-' {
		sign = -1
		c = in.read()
	}
	res := 0
	for c > 32 {
		res = res*10 + int(c-'0')
		c = in.read()
	}
	return res * sign
}

func (in *InputReader) readLong() int64 {
	c := in.read()
	for c <= 32 {
		c = in.read()
	}
	sign := int64(1)
	if c == '-' {
		sign = -1
		c = in.read()
	}
	res := int64(0)
	for c > 32 {
		res = res*10 + int64(c-'0')
		c = in.read()
	}
	return res * sign
}

func (in *InputReader) readString() string {
	c := in.read()
	for c <= 32 {
		c = in.read()
	}
	buf := make([]byte, 0)
	for c > 32 {
		buf = append(buf, c)
		c = in.read()
	}
	return string(buf)
}

type OutputWriter struct {
	buf []byte
}

func NewOutputWriter() *OutputWriter {
	return &OutputWriter{}
}

func (out *OutputWriter) print(args ...interface{}) {
	for _, arg := range args {
		switch arg := arg.(type) {
		case int:
			out.buf = strconv.AppendInt(out.buf, int64(arg), 10)
		case int64:
			out.buf = strconv.AppendInt(out.buf, arg, 10)
		case string:
			out.buf = append(out.buf, arg...)
		case []byte:
			out.buf = append(out.buf, arg...)
		}
	}
}

func (out *OutputWriter) println(args ...interface{}) {
	out.print(args...)
	out.buf = append(out.buf, '\n')
}

func (out *OutputWriter) flush() {
	_, err := os.Stdout.Write(out.buf)
	if err != nil {
		panic(err)
	}
	out.buf = out.buf[:0]
}

type Pair struct {
	first  int
	second int
}

type Interval struct {
	left  int
	right int
}

type IntervalTree struct {
	size  int
	value []int
	delta []int
}

func NewIntervalTree(size int) *IntervalTree {
	tree := &IntervalTree{
		size:  size,
		value: make([]int, 4*size),
		delta: make([]int, 4*size),
	}
	tree.init(0, 0, size-1)
	return tree
}

func (tree *IntervalTree) init(root, left, right int) {
	if left == right {
		tree.value[root] = 0
		tree.delta[root] = 0
	} else {
		middle := (left + right) / 2
		tree.init(2*root+1, left, middle)
		tree.init(2*root+2, middle+1, right)
		tree.value[root] = tree.value[2*root+1] + tree.value[2*root+2]
		tree.delta[root] = 0
	}
}

func (tree *IntervalTree) update(root, left, right, from, to, delta int) {
	if left > to || right < from {
		return
	}
	if left >= from && right <= to {
		tree.value[root] += delta
		tree.delta[root] += delta
		return
	}
	middle := (left + right) / 2
	tree.pushDown(root, left, middle, right)
	tree.update(2*root+1, left, middle, from, to, delta)
	tree.update(2*root+2, middle+1, right, from, to, delta)
	tree.value[root] = tree.value[2*root+1] + tree.value[2*root+2]
}

func (tree *IntervalTree) pushDown(root, left, middle, right int) {
	tree.value[2*root+1] += tree.delta[root] * (middle - left + 1)
	tree.value[2*root+2] += tree.delta[root] * (right - middle)
	tree.delta[2*root+1] += tree.delta[root]
	tree.delta[2*root+2] += tree.delta[root]
	tree.delta[root] = 0
}

func (tree *IntervalTree) query(root, left, right, from, to int) int {
	if left > to || right < from {
		return 0
	}
	if left >= from && right <= to {
		return tree.value[root]
	}
	middle := (left + right) / 2
	tree.pushDown(root, left, middle, right)
	return tree.query(2*root+1, left, middle, from, to) +
		tree.query(2*root+2, middle+1, right, from, to)
}

func main() {
	in := NewInputReader()
	out := NewOutputWriter()

	n := in.readInt()
	q := in.readInt()

	tree := NewIntervalTree(n)

	for i := 0; i < q; i++ {
		op := in.readInt()
		if op == 1 {
			l := in.readInt()
			r := in.readInt()
			x := in.readInt()
			tree.update(0, 0, n-1, l-1, r-1, x)
		} else {
			k := in.readInt()
			out.println(tree.query(0, 0, n-1, k-1, k-1))
		}
	}

	out.flush()
}
