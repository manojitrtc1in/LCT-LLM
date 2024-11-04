package main

import (
	"fmt"
	"math"
)

const MOD = 1e9 + 7

type TreeSegment struct {
	S       []Node
	n       int
	magic   func(int, int) int
	applyMod func(int, int, int, int) int
	mergeMods func(int, int, int, int) int
}

type Node struct {
	haveMod bool
	l, r    int
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
	return ts.applyMod(ts.S[i].value, ts.S[i].mod, tl, tr)
}

func (ts *TreeSegment) push(i, tl, tr int) {
	if ts.S[i].haveMod {
		ts.S[i].value = ts.applyMod(ts.S[i].value, ts.S[i].mod, tl, tr)
		if tl+1 != tr {
			mid := (tl + tr) / 2
			ts.addMod(ts.S[i].l, tl, mid, ts.S[i].mod)
			ts.addMod(ts.S[i].r, mid, tr, ts.S[i].mod)
		}
		ts.S[i].haveMod = false
	}
}

func (ts *TreeSegment) addMod(i, tl, tr int, sub int) {
	if ts.S[i].haveMod {
		ts.S[i].mod = ts.mergeMods(ts.S[i].mod, sub, tl, tr)
	} else {
		ts.S[i].mod = sub
		ts.S[i].haveMod = true
	}
}

func (ts *TreeSegment) query(i, tl, tr, ql, qr int) int {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(ts.query(ts.S[i].l, tl, mid, ql, qr), ts.query(ts.S[i].r, mid, tr, ql, qr))
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(ts.S[i].l, tl, mid, ql, qr)
		} else if ts.intersects(mid, tr, ql, qr) {
			return ts.query(ts.S[i].r, mid, tr, ql, qr)
		} else {
			panic("should not reach here")
		}
	}
}

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
}

func (ts *TreeSegment) update(i, tl, tr, ql, qr, mod int) {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		ts.addMod(i, tl, tr, mod)
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) {
			ts.update(ts.S[i].l, tl, mid, ql, qr, mod)
		}
		if ts.intersects(mid, tr, ql, qr) {
			ts.update(ts.S[i].r, mid, tr, ql, qr, mod)
		}
		ts.recalcValue(i, tl, tr)
	}
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
	fmt.Scan(&n, &q)
	pos := make([]int, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&pos[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}

	ts := TreeSegment{
		magic: func(a, b int) int {
			return a + b
		},
		applyMod: func(value, mod, tl, tr int) int {
			return mod
		},
		mergeMods: func(old, newMod, tl, tr int) int {
			return newMod
		},
	}
	ts.S = make([]Node, 0)
	ts.init(0, n, w)

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % MOD
	}

	resp := TreeSegment{
		magic: func(a, b int) int {
			return (a + b) % MOD
		},
		applyMod: func(value, mod, tl, tr int) int {
			return mod
		},
		mergeMods: func(old, newMod, tl, tr int) int {
			return newMod
		},
	}
	resp.S = make([]Node, 0)
	resp.init(0, n, subw)

	for i := 0; i < q; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			ind := -x - 1
			newVal := y
			ts.update(ind, ind+1, newVal)
			resp.update(ind, ind+1, (newVal*(ind-pos[ind]))%MOD)
		} else {
			l := x - 1
			r := y

			sm := ts.query(0, 0, ts.n, l, r)

			bestL := ts.findRight(l, func(x int) bool {
				return x*2 >= sm
			}, 0)

			x := pos[bestL] - bestL + l

			left := 0
			if l < bestL {
				left = (resp.query(0, 0, resp.n, l, bestL) + ts.query(0, 0, ts.n, l, bestL)*(x-l)) % MOD
			}
			right := 0
			if bestL < r {
				right = (resp.query(0, 0, resp.n, bestL, r) + ts.query(0, 0, ts.n, bestL, r)*(x-l)) % MOD
			}
			fmt.Println(floorMod(left-right, MOD))
		}
	}
}
