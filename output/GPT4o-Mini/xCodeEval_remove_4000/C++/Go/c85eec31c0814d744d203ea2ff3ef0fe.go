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
	if _ptr >= MAXMEM {
		panic("Memory limit exceeded")
	}
	return &_memory[_ptr-size]
}

func delete(ptr *byte) {}

var stringInBuffer [260]byte

func fastScanInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func fastScanLong() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}

func fastScanUnsignedLong() uint64 {
	var x uint64
	fmt.Scan(&x)
	return x
}

func fastScanDouble() float64 {
	var x float64
	fmt.Scan(&x)
	return x
}

func fastScanString() string {
	var x string
	fmt.Scan(&x)
	return x
}

func fastPrintInt(x int) {
	fmt.Print(x)
}

func fastPrintLong(x int64) {
	fmt.Print(x)
}

func fastPrintUnsignedLong(x uint64) {
	fmt.Print(x)
}

func fastPrintDouble(x float64) {
	fmt.Printf("%.15f", x)
}

func fastPrintString(x string) {
	fmt.Print(x)
}

type Pair struct {
	first  int
	second int
}

type TreeSegment struct {
	S      []Node
	n      int
	magic  func(int, int) int
	apply  func(int, int, int, int) int
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
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(ts.__query(i+1, tl, mid, ql, qr), ts.__query(i+(mid-tl)*2, mid, tr, ql, qr))
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.__query(i+1, tl, mid, ql, qr)
		} else {
			return ts.__query(i+(mid-tl)*2, mid, tr, ql, qr)
		}
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
	n := fastScanInt()
	q := fastScanInt()
	pos := make([]int, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		pos[i] = fastScanInt()
	}
	for i := 0; i < n; i++ {
		w[i] = fastScanInt()
	}

	ts := TreeSegment{
		magic: func(a, b int) int {
			return a + b
		},
		apply: func(value, mod, _, _ int) int {
			return mod
		},
		merge: func(old, newMod, _, _ int) int {
			return newMod
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
		merge: func(old, newMod, _, _ int) int {
			return newMod
		},
	}
	resp.init(subw)

	for i := 0; i < q; i++ {
		x := fastScanInt()
		y := fastScanInt()
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
				left = (resp.query(l, bestL) + ts.query(l, bestL)*(x-l)) % 1000000007
			}
			right := 0
			if bestL < r {
				right = (resp.query(bestL, r) + ts.query(bestL, r)*(x-l)) % 1000000007
			}
			fmt.Println(floorMod(left-right, 1000000007))
		}
	}
}
