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
	l       int
	r       int
	value   int
	mod     int
}

func (ts *TreeSegment) init(tl, tr int, src []int) int {
	i := len(ts.S)
	ts.S = append(ts.S, Node{})
	if tl+1 == tr {
		ts.S[i].value = src[tl]
	} else {
		mid := (tl + tr) / 2
		ts.S[i].l = ts.init(tl, mid, src)
		ts.S[i].r = ts.init(mid, tr, src)
		ts.recalcValue(i, tl, tr)
	}
	return i
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].value = ts.magic(ts.getValue(ts.S[i].l, tl, mid), ts.getValue(ts.S[i].r, mid, tr))
	}
}

func (ts *TreeSegment) getValue(i, tl, tr int) int {
	if !ts.S[i].haveMod {
		return ts.S[i].value
	}
	return ts.apply(ts.S[i].value, ts.S[i].mod, tl, tr)
}

func (ts *TreeSegment) update(ql, qr, mod int) {
	ts.push(0, 0, ts.n, ql, qr, mod)
}

func (ts *TreeSegment) push(i, tl, tr, ql, qr, mod int) {
	if ts.S[i].haveMod {
		ts.S[i].value = ts.apply(ts.S[i].value, ts.S[i].mod, tl, tr)
		if tl+1 != tr {
			mid := (tl + tr) / 2
			ts.addMod(ts.S[i].l, tl, mid, ts.S[i].mod)
			ts.addMod(ts.S[i].r, mid, tr, ts.S[i].mod)
		}
		ts.S[i].haveMod = false
	}
}

func (ts *TreeSegment) addMod(i, tl, tr, sub int) {
	if ts.S[i].haveMod {
		ts.S[i].mod = ts.merge(ts.S[i].mod, sub, tl, tr)
	} else {
		ts.S[i].mod = sub
		ts.S[i].haveMod = true
	}
}

func (ts *TreeSegment) query(ql, qr int) int {
	return ts.__query(0, 0, ts.n, ql, qr)
}

func (ts *TreeSegment) __query(i, tl, tr, ql, qr int) int {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(ts.__query(ts.S[i].l, tl, mid, ql, qr), ts.__query(ts.S[i].r, mid, tr, ql, qr))
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.__query(ts.S[i].l, tl, mid, ql, qr)
		} else if ts.intersects(mid, tr, ql, qr) {
			return ts.__query(ts.S[i].r, mid, tr, ql, qr)
		} else {
			panic("Should not reach here")
		}
	}
}

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
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
		S:     []Node{},
		magic: func(a, b int) int { return a + b },
		apply: func(value, mod, tl, tr int) int { return mod },
		merge: func(old, newMod, tl, tr int) int { return newMod },
	}
	ts.init(0, n, w)

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % int(1e9+7)
	}

	resp := TreeSegment{
		S:     []Node{},
		magic: func(a, b int) int { return (a + b) % int(1e9+7) },
		apply: func(value, mod, tl, tr int) int { return mod },
		merge: func(old, newMod, tl, tr int) int { return newMod },
	}
	resp.init(0, n, subw)

	for i := 0; i < q; i++ {
		x := fastScanInt()
		y := fastScanInt()
		if x < 0 {
			ind := -x - 1
			newVal := y
			ts.update(ind, ind+1, newVal)
			resp.update(ind, ind+1, (newVal*(ind-pos[ind]))%int(1e9+7))
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
				left = (resp.query(l, bestL) + ts.query(l, bestL)*(x-l)) % int(1e9+7)
			}
			right := 0
			if bestL < r {
				right = (resp.query(bestL, r) + ts.query(bestL, r)*(x-l)) % int(1e9+7)
			}
			fastPrintInt((left - right + int(1e9+7)) % int(1e9+7))
		}
	}
}
