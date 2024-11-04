package main

import (
	"fmt"
)

type TreeSegment struct {
	S []Node
	N int
}

type Node struct {
	haveMod bool
	L, R    int
	Value   int
	Mod     int
}

type Magic func(a, b int) int
type ApplyMod func(value, mod, tl, tr int) int
type MergeMods func(old, new, tl, tr int) int

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
}

func (ts *TreeSegment) createNode() int {
	node := Node{}
	ts.S = append(ts.S, node)
	return len(ts.S) - 1
}

func (ts *TreeSegment) getValue(i, tl, tr int) int {
	if !ts.S[i].haveMod {
		return ts.S[i].Value
	}
	return ts.applyMod(ts.S[i].Value, ts.S[i].Mod, tl, tr)
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].Value = ts.magic(
			ts.getValue(ts.S[i].L, tl, mid),
			ts.getValue(ts.S[i].R, mid, tr),
		)
	}
}

func (ts *TreeSegment) addMod(i, tl, tr, sub int) {
	if ts.S[i].haveMod {
		ts.S[i].Mod = ts.mergeMods(ts.S[i].Mod, sub, tl, tr)
	} else {
		ts.S[i].Mod = sub
		ts.S[i].haveMod = true
	}
}

func (ts *TreeSegment) push(i, tl, tr int) {
	if ts.S[i].haveMod {
		ts.S[i].Value = ts.applyMod(ts.S[i].Value, ts.S[i].Mod, tl, tr)
		if tl+1 != tr {
			mid := (tl + tr) / 2
			ts.addMod(ts.S[i].L, tl, mid, ts.S[i].Mod)
			ts.addMod(ts.S[i].R, mid, tr, ts.S[i].Mod)
		}
		ts.S[i].haveMod = false
	}
}

func (ts *TreeSegment) init(tl, tr int, src []int) int {
	i := ts.createNode()
	if tl+1 == tr {
		ts.S[i].Value = src[tl]
	} else {
		mid := (tl + tr) / 2
		ts.S[i].L = ts.init(tl, mid, src)
		ts.S[i].R = ts.init(mid, tr, src)
		ts.recalcValue(i, tl, tr)
	}
	return i
}

func (ts *TreeSegment) query(i, tl, tr, ql, qr int) int {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].Value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(
				ts.query(ts.S[i].L, tl, mid, ql, qr),
				ts.query(ts.S[i].R, mid, tr, ql, qr),
			)
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(ts.S[i].L, tl, mid, ql, qr)
		} else if ts.intersects(mid, tr, ql, qr) {
			return ts.query(ts.S[i].R, mid, tr, ql, qr)
		} else {
			panic("Invalid query range")
		}
	}
}

func (ts *TreeSegment) update(i, tl, tr, ql, qr, mod int) {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		ts.addMod(i, tl, tr, mod)
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) {
			ts.update(ts.S[i].L, tl, mid, ql, qr, mod)
		}
		if ts.intersects(mid, tr, ql, qr) {
			ts.update(ts.S[i].R, mid, tr, ql, qr, mod)
		}
		ts.recalcValue(i, tl, tr)
	}
}

func (ts *TreeSegment) findRight(i, tl, tr, L int, checker func(int) bool, pref int) (int, int) {
	ts.push(i, tl, tr)
	if tr <= L {
		return -1, pref
	}
	if tl+1 == tr {
		_this := ts.magic(pref, ts.getValue(i, tl, tr))
		if checker(_this) {
			return tl, _this
		} else {
			return -1, _this
		}
	} else {
		mid := (tl + tr) / 2
		if L <= tl {
			_left := ts.magic(pref, ts.getValue(ts.S[i].L, tl, mid))
			if checker(_left) {
				return ts.findRight(ts.S[i].L, tl, mid, L, checker, pref)
			} else {
				return ts.findRight(ts.S[i].R, mid, tr, L, checker, _left)
			}
		} else {
			t := ts.findRight(ts.S[i].L, tl, mid, L, checker, pref)
			if t != -1 {
				return t
			}
			return ts.findRight(ts.S[i].R, mid, tr, L, checker, t)
		}
	}
}

func (ts *TreeSegment) findLeft(i, tl, tr, R int, checker func(int) bool, pref int) (int, int) {
	ts.push(i, tl, tr)
	if R < tl {
		return -1, pref
	}
	if tl+1 == tr {
		_this := ts.magic(pref, ts.getValue(i, tl, tr))
		if checker(_this) {
			return tl, _this
		} else {
			return -1, _this
		}
	} else {
		mid := (tl + tr) / 2
		if tr <= R+1 {
			_right := ts.magic(pref, ts.getValue(ts.S[i].R, mid, tr))
			if checker(_right) {
				return ts.findLeft(ts.S[i].R, mid, tr, R, checker, pref)
			} else {
				return ts.findLeft(ts.S[i].L, tl, mid, R, checker, _right)
			}
		} else {
			t := ts.findLeft(ts.S[i].R, mid, tr, R, checker, pref)
			if t != -1 {
				return t
			}
			return ts.findLeft(ts.S[i].L, tl, mid, R, checker, t)
		}
	}
}

func (ts *TreeSegment) applyMod(value, mod, tl, tr int) int {
	return mod
}

func (ts *TreeSegment) mergeMods(old, new, tl, tr int) int {
	return new
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

	ts := TreeSegment{}
	ts.magic = func(a, b int) int {
		return a + b
	}
	ts.init(0, len(w), w)

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % MOD
	}

	resp := TreeSegment{}
	resp.magic = func(a, b int) int {
		return (a + b) % MOD
	}
	resp.init(0, len(subw), subw)

	for i := 0; i < q; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			ind := -x
			_new := y
			ind--
			ts.update(0, 0, n, ind, ind+1, _new)
			resp.update(0, 0, n, ind, ind+1, (_new*(ind-pos[ind]))%MOD)
		} else {
			l := x
			r := y
			l--

			sm := ts.query(0, 0, n, l, r)

			bestL := ts.findRight(0, 0, n, l, func(x int) bool {
				return x*2 >= sm
			}, 0)

			x := pos[bestL] - bestL + l

			left := 0
			if l < bestL {
				left = resp.query(0, 0, n, l, bestL) + ts.query(0, 0, n, l, bestL)*(x-l)
			}
			right := 0
			if bestL < r {
				right = resp.query(0, 0, n, bestL, r) + ts.query(0, 0, n, bestL, r)*(x-l)
			}

			fmt.Println((left - right + MOD) % MOD)
		}
	}
}
