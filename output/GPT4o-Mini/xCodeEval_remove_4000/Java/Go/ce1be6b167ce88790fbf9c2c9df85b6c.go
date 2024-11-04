package main

import (
	"fmt"
	"math"
)

type FastWriter struct {
	out string
}

func (fw *FastWriter) p(object interface{}) *FastWriter {
	fw.out += fmt.Sprintf("%v", object)
	return fw
}

func (fw *FastWriter) pp(args ...interface{}) *FastWriter {
	for _, ob := range args {
		fw.out += fmt.Sprintf("%v ", ob)
	}
	fw.out += "\n"
	return fw
}

func (fw *FastWriter) close() {
	fmt.Print(fw.out)
}

type FastScanner struct {
	buffer []byte
	ptr    int
	buflen int
}

func NewFastScanner() *FastScanner {
	return &FastScanner{buffer: make([]byte, 1024)}
}

func (fs *FastScanner) hasNext() bool {
	for fs.ptr < fs.buflen {
		if fs.buffer[fs.ptr] > 32 && fs.buffer[fs.ptr] < 127 {
			return true
		}
		fs.ptr++
	}
	return false
}

func (fs *FastScanner) next() string {
	if !fs.hasNext() {
		panic("No such element")
	}
	start := fs.ptr
	for fs.ptr < fs.buflen && (fs.buffer[fs.ptr] > 32 && fs.buffer[fs.ptr] < 127) {
		fs.ptr++
	}
	return string(fs.buffer[start:fs.ptr])
}

func (fs *FastScanner) longNext() int64 {
	if !fs.hasNext() {
		panic("No such element")
	}
	var n int64
	var minus bool
	b := fs.buffer[fs.ptr]
	if b == '-' {
		minus = true
		fs.ptr++
		b = fs.buffer[fs.ptr]
	}
	if b < '0' || b > '9' {
		panic("Number format exception")
	}
	for {
		if b >= '0' && b <= '9' {
			n = n*10 + int64(b-'0')
		} else {
			break
		}
		fs.ptr++
		if fs.ptr >= fs.buflen {
			break
		}
		b = fs.buffer[fs.ptr]
	}
	if minus {
		return -n
	}
	return n
}

func (fs *FastScanner) intNext() int {
	nl := fs.longNext()
	if nl < math.MinInt32 || nl > math.MaxInt32 {
		panic("Number format exception")
	}
	return int(nl)
}

func (fs *FastScanner) id23(n int) []int64 {
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		a[i] = fs.longNext()
	}
	return a
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func solver(in *FastScanner, out *FastWriter) {
	n := in.intNext()
	ar := in.id23(3)
	br := in.id23(3)
	mxWins := int64(0)
	id19 := int64(0)
	for i := 0; i < 3; i++ {
		mxWins += min(ar[i], br[(i+1)%3])
		mxLose := min(br[i], ar[(i+1)%3])
		mxDraw := min(br[i], ar[i])
		id19 += min(br[i], mxLose+mxDraw)
	}
	out.pp(n-id19, mxWins)
}

func main() {
	in := NewFastScanner()
	out := &FastWriter{}
	solver(in, out)
	out.close()
}
