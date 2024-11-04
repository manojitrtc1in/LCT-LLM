package main

import (
	"fmt"
)

type TreeSegment struct {
	S         []Node
	n         int
	magic     func(a, b int) int
	applyMod  func(value, mod, tl, tr int) int
	mergeMods func(a, b, tl, tr int) int
}

type Node struct {
	haveMod bool
	value   int
	mod     int
}

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
}

func (ts *TreeSegment) getValue(i, tl, tr int) int {
	if !ts.S[i].haveMod {
		return ts.S[i].value
	}
	return ts.applyMod(ts.S[i].value, ts.S[i].mod, tl, tr)
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].value = ts.magic(ts.getValue(i+1, tl, mid), ts.getValue(i+(mid-tl)*2, mid, tr))
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

func (ts *TreeSegment) query(i, tl, tr, ql, qr int) int {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(ts.query(i+1, tl, mid, ql, qr), ts.query(i+(mid-tl)*2, mid, tr, ql, qr))
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(i+1, tl, mid, ql, qr)
		} else {
			return ts.query(i+(mid-tl)*2, mid, tr, ql, qr)
		}
	}
}

func (ts *TreeSegment) change(i, tl, tr, j, newValue int) {
	ts.push(i, tl, tr)
	if tl+1 == tr {
		ts.S[i].value = newValue
	} else {
		m := (tl + tr) / 2
		if j < m {
			ts.change(ts.S[i].l, tl, m, j, newValue)
		} else {
			ts.change(ts.S[i].r, m, tr, j, newValue)
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
				return t.first, t.second
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
			_right := ts.magic(pref, ts.getValue(ts.S[i].r, mid, tr))
			if checker(_right) {
				return ts.findLeft(ts.S[i].r, mid, tr, R, checker, pref)
			} else {
				return ts.findLeft(ts.S[i].l, tl, mid, R, checker, _right)
			}
		} else {
			t := ts.findLeft(ts.S[i].r, mid, tr, R, checker, pref)
			if t.first != -1 {
				return t.first, t.second
			}
			return ts.findLeft(ts.S[i].l, tl, mid, R, checker, t.second)
		}
	}
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
		S: make([]Node, 2*n+1),
		n: n,
		magic: func(a, b int) int {
			return a + b
		},
		applyMod: func(value, mod, tl, tr int) int {
			return mod
		},
		mergeMods: func(old, _new, tl, tr int) int {
			return _new
		},
	}

	resp := TreeSegment{
		S: make([]Node, 2*n+1),
		n: n,
		magic: func(a, b int) int {
			return (a + b) % MOD
		},
		applyMod: func(value, mod, tl, tr int) int {
			return mod
		},
		mergeMods: func(old, _new, tl, tr int) int {
			return _new
		},
	}

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
			ts.update(0, 0, n, ind, ind+1, _new)
			resp.update(0, 0, n, ind, ind+1, (_new*(ind-pos[ind]))%MOD)
		} else {
			l, r := x, y
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
