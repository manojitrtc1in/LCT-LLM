package main

import (
	"bytes"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
)

type FastIO struct {
	cache   bytes.Buffer
	is      io.Reader
	os      io.Writer
	next    int
	buf     [1 << 13]byte
	bufLen  int
	bufOffset int
}

func NewFastIO(is io.Reader, os io.Writer) *FastIO {
	return &FastIO{is: is, os: os}
}

func (io *FastIO) read() int {
	if io.bufLen == io.bufOffset {
		io.bufOffset = 0
		n, err := io.is.Read(io.buf[:])
		if err != nil {
			panic(err)
		}
		io.bufLen = n
		if n == 0 {
			return -1
		}
	}
	val := io.buf[io.bufOffset]
	io.bufOffset++
	return int(val)
}

func (io *FastIO) skipBlank() {
	for io.next >= 0 && io.next <= 32 {
		io.next = io.read()
	}
}

func (io *FastIO) readInt() int {
	sign := 1
	io.skipBlank()
	if io.next == '+' || io.next == '-' {
		if io.next == '-' {
			sign = -1
		}
		io.next = io.read()
	}

	val := 0
	for io.next >= '0' && io.next <= '9' {
		val = val*10 + io.next - '0'
		io.next = io.read()
	}
	return val * sign
}

func (io *FastIO) readChar() byte {
	io.skipBlank()
	c := byte(io.next)
	io.next = io.read()
	return c
}

func (io *FastIO) flush() {
	_, err := io.os.Write(io.cache.Bytes())
	if err != nil {
		panic(err)
	}
	io.cache.Reset()
}

type Point2 struct {
	x, y float64
}

func (p Point2) add(other Point2) Point2 {
	return Point2{p.x + other.x, p.y + other.y}
}

func (p Point2) sub(other Point2) Point2 {
	return Point2{p.x - other.x, p.y - other.y}
}

type Line2 struct {
	begin, end Point2
}

func (l Line2) getVector() Point2 {
	return l.end.sub(l.begin)
}

func (l Line2) id0(alpha float64) Point2 {
	return Point2{
		(1-alpha)*l.begin.x + alpha*l.end.x,
		(1-alpha)*l.begin.y + alpha*l.end.y,
	}
}

func cross(x1, y1, x2, y2 int) int64 {
	return int64(x1)*int64(y2) - int64(y1)*int64(x2)
}

func (p Point2) cross(other Point2) float64 {
	return p.x*other.y - p.y*other.x
}

type Task struct {
	io *FastIO
}

func (t *Task) run() {
	t.solve()
}

func (t *Task) solve() {
	n := t.io.readInt()
	points := make([][4]int, n)
	for i := 0; i < n; i++ {
		points[i][0] = t.io.readInt()
		points[i][1] = t.io.readInt()
		points[i][3] = i + 1
	}

	last := points[0]
	for _, pt := range points {
		if pt[0] == last[0] {
			if pt[1] < last[1] {
				last = pt
			}
		} else if pt[0] > last[0] {
			last = pt
		}
	}

	last[2] = 1
	t.io.cache.WriteString(fmt.Sprintf("%d ", last[3]))
	for i := 0; i < n-2; i++ {
		c := t.io.readChar()
		var choose *[4]int
		cmp := func(a, b *[4]int) int {
			if c == 'L' {
				return -int(math.Signbit(float64(cross(a[0]-last[0], a[1]-last[1], b[0]-last[0], b[1]-last[1]))))
			}
			return int(math.Signbit(float64(cross(a[0]-last[0], a[1]-last[1], b[0]-last[0], b[1]-last[1]))))
		}
		for _, pt := range points {
			if pt[2] == 1 {
				continue
			}
			if choose == nil || cmp(&pt, choose) < 0 {
				choose = &pt
			}
		}
		last = *choose
		last[2] = 1
		t.io.cache.WriteString(fmt.Sprintf("%d ", last[3]))
	}

	for _, pt := range points {
		if pt[2] == 1 {
			continue
		}
		t.io.cache.WriteString(fmt.Sprintf("%d ", pt[3]))
	}
}

func main() {
	local := os.Getenv("ONLINE_JUDGE") == ""
	io := NewFastIO(os.Stdin, os.Stdout)
	task := &Task{io: io}
	task.run()
	io.flush()
}
