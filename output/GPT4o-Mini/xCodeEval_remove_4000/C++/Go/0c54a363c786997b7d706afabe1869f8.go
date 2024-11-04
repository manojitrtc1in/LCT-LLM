package main

import (
	"fmt"
	"math"
)

const MAXMEM = 200 * 1000 * 1024
var _memory [MAXMEM]byte
var _ptr int

func new(size int) *byte {
	_ptr += size
	if _ptr > MAXMEM {
		panic("Memory limit exceeded")
	}
	return &_memory[_ptr-size]
}

func delete(ptr *byte) {}

var stringInBuffer [260]byte

func fastScanInt(x *int) {
	fmt.Scanf("%d", x)
}

func fastScanLongLong(x *int64) {
	fmt.Scanf("%d64", x)
}

func fastScanUnsignedLongLong(x *uint64) {
	fmt.Scanf("%d64", x)
}

func fastScanDouble(x *float64) {
	fmt.Scanf("%lf", x)
}

func fastScanLongDouble(x *float64) {
	fmt.Scanf("%Lf", x)
}

func fastScanChar(x *byte) {
	fmt.Scanf("%c", x)
}

func fastScanString(x *string) {
	fmt.Scanf("%s", &stringInBuffer)
	*x = string(stringInBuffer[:])
}

func fastPrintInt(x int) {
	fmt.Printf("%d", x)
}

func fastPrintLongLong(x int64) {
	fmt.Printf("%d64", x)
}

func fastPrintUnsignedLongLong(x uint64) {
	fmt.Printf("%d64", x)
}

func fastPrintDouble(x float64) {
	fmt.Printf("%.15lf", x)
}

func fastPrintLongDouble(x float64) {
	fmt.Printf("%.15Lf", x)
}

func fastPrintChar(x byte) {
	fmt.Printf("%c", x)
}

func fastPrintString(x string) {
	fmt.Printf("%s", x)
}

func fastPrintSliceInt(v []int) {
	if len(v) == 0 {
		return
	}
	fastPrintInt(v[0])
	for i := 1; i < len(v); i++ {
		fmt.Print(" ")
		fastPrintInt(v[i])
	}
}

type TreeSegment struct {
	n     int
	S     []Node
	magic func(int, int) int
	apply func(int, int, int, int) int
	merge  func(int, int, int, int) int
}

type Node struct {
	haveMod bool
	value   int
	mod     int
}

func (ts *TreeSegment) init(src []int) {
	ts.n = len(src)
	ts.S = make([]Node, 2*ts.n+1)
	ts.initRec(0, 0, ts.n, src)
}

func (ts *TreeSegment) initRec(i, tl, tr int, src []int) {
	if tl+1 == tr {
		ts.S[i].value = src[tl]
	} else {
		mid := (tl + tr) / 2
		ts.initRec(i+1, tl, mid, src)
		ts.initRec(i+(mid-tl)*2, mid, tr, src)
		ts.recalcValue(i, tl, tr)
	}
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].value = ts.magic(ts.getValue(i+1, tl, mid), ts.getValue(i+(mid-tl)*2, mid, tr))
	}
}

func (ts *TreeSegment) getValue(i, tl, tr int) int {
	if !ts.S[i].haveMod {
		return ts.S[i].value
	}
	return ts.apply(ts.S[i].value, ts.S[i].mod, tl, tr)
}

func (ts *TreeSegment) query(ql, qr int) int {
	return ts.__query(0, 0, ts.n, ql, qr)
}

func (ts *TreeSegment) __query(i, tl, tr, ql, qr int) int {
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	}
	mid := (tl + tr) / 2
	if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
		return ts.magic(ts.__query(i+1, tl, mid, ql, qr), ts.__query(i+(mid-tl)*2, mid, tr, ql, qr))
	} else if ts.intersects(tl, mid, ql, qr) {
		return ts.__query(i+1, tl, mid, ql, qr)
	} else {
		return ts.__query(i+(mid-tl)*2, mid, tr, ql, qr)
	}
}

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
}

func floorMod(a, b int) int {
	if a%b == 0 {
		return 0
	}
	if a >= 0 && b >= 0 {
		return a % b
	}
	if a <= 0 && b <= 0 {
		return a % b
	}
	return int(math.Abs(float64(b))) - (int(math.Abs(float64(a))) % int(math.Abs(float64(b))))
}

func main() {
	var n, q int
	fastScanInt(&n)
	fastScanInt(&q)

	pos := make([]int, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fastScanInt(&pos[i])
	}
	for i := 0; i < n; i++ {
		fastScanInt(&w[i])
	}

	ts := TreeSegment{
		magic: func(a, b int) int {
			return a + b
		},
		apply: func(value, mod, _, _ int) int {
			return mod
		},
		merge: func(old, new, _, _ int) int {
			return new
		},
	}
	ts.init(w)

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % 1000000007
	}

	resp := TreeSegment{
		magic: func(a, b int) int {
			return (a + b) % 1000000007
		},
		apply: func(value, mod, _, _ int) int {
			return mod
		},
		merge: func(old, new, _, _ int) int {
			return new
		},
	}
	resp.init(subw)

	for i := 0; i < q; i++ {
		var x, y int
		fastScanInt(&x)
		fastScanInt(&y)
		if x < 0 {
			ind := -x - 1
			_new := y
			ts.update(ind, ind+1, _new)
			resp.update(ind, ind+1, (_new*(ind-pos[ind]))%1000000007)
		} else {
			l := x - 1
			r := y
			sm := ts.query(l, r)

			bestL := ts.findRight(l, func(x int) bool {
				return x*2 >= sm
			}, 0)

			x := pos[bestL] - bestL + l

			left := 0
			if l < bestL {
				left = resp.query(l, bestL) + ts.query(l, bestL)*(x-l)
			}
			right := 0
			if bestL < r {
				right = resp.query(bestL, r) + ts.query(bestL, r)*(x-l)
			}
			fmt.Println(floorMod(left-right, 1000000007))
		}
	}
}
