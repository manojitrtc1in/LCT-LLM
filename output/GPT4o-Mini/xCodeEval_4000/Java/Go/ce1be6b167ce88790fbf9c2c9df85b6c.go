package main

import (
	"fmt"
	"math"
)

type FastWriter struct {
	out string
}

func (fw *FastWriter) p(object interface{}) *FastWriter {
	fw.out += fmt.Sprint(object)
	return fw
}

func (fw *FastWriter) pp(args ...interface{}) *FastWriter {
	for _, ob := range args {
		fw.out += fmt.Sprint(ob) + " "
	}
	fw.out += "\n"
	return fw
}

func (fw *FastWriter) close() {
	fmt.Print(fw.out)
}

type FastScanner struct {
	data []string
	ptr  int
}

func NewFastScanner() *FastScanner {
	var n int
	fmt.Scan(&n)
	data := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&data[i])
	}
	return &FastScanner{data: data}
}

func (fs *FastScanner) intNext() int {
	val := fs.data[fs.ptr]
	fs.ptr++
	return int(val[0] - '0')
}

func (fs *FastScanner) nextLongArray(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = int64(fs.intNext())
	}
	return arr
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solver() {
	in := NewFastScanner()
	n := in.intNext()
	ar := in.nextLongArray(3)
	br := in.nextLongArray(3)

	var mxWins, mxLosesOrDraw, draws int64
	for i := 0; i < 3; i++ {
		mxWins += min(ar[i], br[(i+1)%3])
		mxLose := min(br[i], ar[(i+1)%3])
		mxDraw := min(br[i], ar[i])
		mxLosesOrDraw += min(br[i], mxLose+mxDraw)
	}

	out := &FastWriter{}
	out.pp(n-mxLosesOrDraw, mxWins)
	out.close()
}

func main() {
	solver()
}
