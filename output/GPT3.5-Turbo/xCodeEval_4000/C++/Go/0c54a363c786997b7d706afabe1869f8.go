package main

import (
	"fmt"
)

type TreeSegment struct {
	S []Node
	n int
}

type Node struct {
	haveMod bool
	value   int
	mod     int
}

type Magic func(a, b int) int
type ApplyMod func(value, mod, tl, tr int) int
type MergeMods func(a, b, tl, tr int) int

func (ts *TreeSegment) init(i, tl, tr int, src []int) {
	if tl+1 == tr {
		ts.S[i].value = src[tl]
	} else {
		mid := (tl + tr) / 2
		ts.init(i+1, tl, mid, src)
		ts.init(i+(mid-tl)*2, mid, tr, src)
		ts.recalcValue(i, tl, tr)
	}
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].value = ts.magic(
			ts.getValue(i+1, tl, mid),
			ts.getValue(i+(mid-tl)*2, mid, tr),
		)
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

func (ts *TreeSegment) push(i, tl, tr int) {
	if ts.S[i].haveMod {
		ts.S[i].value = ts.applyMod(ts.S[i].value, ts.S[i].mod, tl, tr)
		if tl+1 != tr {
			mid := (tl + tr) / 2
			ts.addMod(i+1, tl, mid, ts.S[i].mod)
			ts.addMod(i+(mid-tl)*2, mid, tr, ts.S[i].mod)
		}
		ts.S[i].haveMod = false
	}
}

func (ts *TreeSegment) getValue(i, tl, tr int) int {
	ts.push(i, tl, tr)
	if !ts.intersects(tl, tr, ql, qr) {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(
				ts.query(i+1, tl, mid, ql, qr),
				ts.query(i+(mid-tl)*2, mid, tr, ql, qr),
			)
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(i+1, tl, mid, ql, qr)
		} else {
			return ts.query(i+(mid-tl)*2, mid, tr, ql, qr)
		}
	}
}

func (ts *TreeSegment) query(i, tl, tr, ql, qr int) int {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(
				ts.query(i+1, tl, mid, ql, qr),
				ts.query(i+(mid-tl)*2, mid, tr, ql, qr),
			)
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(i+1, tl, mid, ql, qr)
		} else {
			return ts.query(i+(mid-tl)*2, mid, tr, ql, qr)
		}
	}
}

func (ts *TreeSegment) update(i, tl, tr, j, _new int) {
	ts.push(i, tl, tr)
	if tl+1 == tr {
		ts.S[i].value = _new
	} else {
		m := (tl + tr) / 2
		if j < m {
			ts.update(S[i].l, tl, m, j, _new)
		} else {
			ts.update(S[i].r, m, tr, j, _new)
		}
		ts.recalcValue(i, tl, tr)
	}
}

func (ts *TreeSegment) update(i, tl, tr, ql, qr, mod int) {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		ts.addMod(i, tl, tr, mod)
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) {
			ts.update(i+1, tl, mid, ql, qr, mod)
		}
		if ts.intersects(mid, tr, ql, qr) {
			ts.update(i+(mid-tl)*2, mid, tr, ql, qr, mod)
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
			_left := ts.magic(pref, ts.getValue(i+1, tl, mid))
			if checker(_left) {
				return ts.findRight(i+1, tl, mid, L, checker, pref)
			} else {
				return ts.findRight(i+(mid-tl)*2, mid, tr, L, checker, _left)
			}
		} else {
			t := ts.findRight(i+1, tl, mid, L, checker, pref)
			if t.first != -1 {
				return t
			}
			return ts.findRight(i+(mid-tl)*2, mid, tr, L, checker, t.second)
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
			_right := ts.magic(pref, ts.getValue(S[i].r, mid, tr))
			if checker(_right) {
				return ts.findLeft(S[i].r, mid, tr, R, checker, pref)
			} else {
				return ts.findLeft(S[i].l, tl, mid, R, checker, _right)
			}
		} else {
			t := ts.findLeft(S[i].r, mid, tr, R, checker, pref)
			if t.first != -1 {
				return t
			}
			return ts.findLeft(S[i].l, tl, mid, R, checker, t.second)
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
	return abs(b) - (abs(a) % abs(b))
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
	resp := TreeSegment{}

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % MOD
	}

	ts.init(0, 0, len(w), w)
	resp.init(0, 0, len(subw), subw)

	for i := 0; i < q; i++ {
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			ind := -x
			_new := y
			ind--
			ts.update(0, 0, len(w), ind, _new)
			resp.update(0, 0, len(subw), ind, (_new*(ind-pos[ind]))%MOD)
		} else {
			l, r := x, y
			l--

			sm := ts.query(0, 0, len(w), l, r)

			bestL := ts.findRight(0, 0, len(w), l, func(x int) bool {
				return x*2 >= sm
			}, 0)

			x := pos[bestL] - bestL + l

			left := 0
			if l < bestL {
				left = resp.query(0, 0, len(subw), l, bestL) + ts.query(0, 0, len(w), l, bestL)*(x-l)
			}
			right := 0
			if bestL < r {
				right = resp.query(0, 0, len(subw), bestL, r) + ts.query(0, 0, len(w), bestL, r)*(x-l)
			}
			fmt.Println(floorMod(left-right, MOD))
		}
	}
}