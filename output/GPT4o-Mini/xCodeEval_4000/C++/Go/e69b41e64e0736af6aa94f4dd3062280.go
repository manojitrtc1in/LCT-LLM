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

func NewTreeSegment(src []int, magic func(int, int) int, applyMod func(int, int, int, int) int, mergeMods func(int, int, int, int) int) *TreeSegment {
	ts := &TreeSegment{
		magic:   magic,
		applyMod: applyMod,
		mergeMods: mergeMods,
	}
	ts.init(src)
	return ts
}

func (ts *TreeSegment) init(src []int) {
	ts.n = len(src)
	ts.S = make([]Node, 4*ts.n)
	ts.build(0, 0, ts.n, src)
}

func (ts *TreeSegment) build(i, tl, tr int, src []int) {
	if tl+1 == tr {
		ts.S[i].value = src[tl]
	} else {
		mid := (tl + tr) / 2
		ts.S[i].l = 2*i + 1
		ts.S[i].r = 2*i + 2
		ts.build(ts.S[i].l, tl, mid, src)
		ts.build(ts.S[i].r, mid, tr, src)
		ts.recalcValue(i, tl, tr)
	}
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

func (ts *TreeSegment) update(ql, qr, mod int) {
	ts.updateRec(0, 0, ts.n, ql, qr, mod)
}

func (ts *TreeSegment) updateRec(i, tl, tr, ql, qr, mod int) {
	if ql <= tl && tr <= qr {
		ts.addMod(i, tl, tr, mod)
	} else {
		mid := (tl + tr) / 2
		if ql < mid {
			ts.updateRec(ts.S[i].l, tl, mid, ql, qr, mod)
		}
		if mid < qr {
			ts.updateRec(ts.S[i].r, mid, tr, ql, qr, mod)
		}
		ts.recalcValue(i, tl, tr)
	}
}

func (ts *TreeSegment) addMod(i, tl, tr, sub int) {
	if ts.S[i].haveMod {
		ts.S[i].mod = ts.mergeMods(ts.S[i].mod, sub, tl, tr)
	} else {
		ts.S[i].mod = sub
		ts.S[i].haveMod = true
	}
}

func (ts *TreeSegment) query(ql, qr int) int {
	return ts.queryRec(0, 0, ts.n, ql, qr)
}

func (ts *TreeSegment) queryRec(i, tl, tr, ql, qr int) int {
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	}
	mid := (tl + tr) / 2
	res := 0
	if ql < mid {
		res = ts.queryRec(ts.S[i].l, tl, mid, ql, qr)
	}
	if mid < qr {
		res = ts.magic(res, ts.queryRec(ts.S[i].r, mid, tr, ql, qr))
	}
	return res
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

	ts := NewTreeSegment(w, func(a, b int) int {
		return a + b
	}, func(value, mod, _, _ int) int {
		return mod
	}, func(old, new, _, _ int) int {
		return new
	})

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % MOD
	}

	resp := NewTreeSegment(subw, func(a, b int) int {
		return (a + b) % MOD
	}, func(value, mod, _, _ int) int {
		return mod
	}, func(old, new, _, _ int) int {
		return new
	})

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

			sm := ts.query(l, r)

			bestL := ts.findRight(l, func(x int) bool {
				return x*2 >= sm
			}, 0)

			x := pos[bestL] - bestL + l

			left := 0
			if l < bestL {
				left = (resp.query(l, bestL) + ts.query(l, bestL)*(x-l)) % MOD
			}
			right := 0
			if bestL < r {
				right = (resp.query(bestL, r) + ts.query(bestL, r)*(x-l)) % MOD
			}
			fmt.Println(floorMod(left-right, MOD))
		}
	}
}
