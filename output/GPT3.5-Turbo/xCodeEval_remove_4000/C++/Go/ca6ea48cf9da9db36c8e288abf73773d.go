package main

import (
	"fmt"
)

type Value int
type Mod int

type TreeSegment struct {
	S         []Node
	n         int
	magic     func(Value, Value) Value
	applyMod  func(Value, Mod, int, int) Value
	mergeMods func(Mod, Mod, int, int) Mod
}

type Node struct {
	haveMod bool
	l, r    int
	value   Value
	mod     Mod
}

func (ts *TreeSegment) intersects(tl, tr, ql, qr int) bool {
	return !(tr <= ql || qr <= tl)
}

func (ts *TreeSegment) createNode() int {
	node := Node{}
	ts.S = append(ts.S, node)
	return len(ts.S) - 1
}

func (ts *TreeSegment) getValue(i, tl, tr int) Value {
	if !ts.S[i].haveMod {
		return ts.S[i].value
	}
	return ts.applyMod(ts.S[i].value, ts.S[i].mod, tl, tr)
}

func (ts *TreeSegment) recalcValue(i, tl, tr int) {
	if tl+1 != tr {
		mid := (tl + tr) / 2
		ts.S[i].value = ts.magic(
			ts.getValue(ts.S[i].l, tl, mid),
			ts.getValue(ts.S[i].r, mid, tr),
		)
	}
}

func (ts *TreeSegment) addMod(i, tl, tr int, sub Mod) {
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
			ts.addMod(ts.S[i].l, tl, mid, ts.S[i].mod)
			ts.addMod(ts.S[i].r, mid, tr, ts.S[i].mod)
		}
		ts.S[i].haveMod = false
	}
}

func (ts *TreeSegment) init(tl, tr int, src []Value) int {
	i := ts.createNode()
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

func (ts *TreeSegment) query(i, tl, tr, ql, qr int) Value {
	ts.push(i, tl, tr)
	if ql <= tl && tr <= qr {
		return ts.S[i].value
	} else {
		mid := (tl + tr) / 2
		if ts.intersects(tl, mid, ql, qr) && ts.intersects(mid, tr, ql, qr) {
			return ts.magic(
				ts.query(ts.S[i].l, tl, mid, ql, qr),
				ts.query(ts.S[i].r, mid, tr, ql, qr),
			)
		} else if ts.intersects(tl, mid, ql, qr) {
			return ts.query(ts.S[i].l, tl, mid, ql, qr)
		} else if ts.intersects(mid, tr, ql, qr) {
			return ts.query(ts.S[i].r, mid, tr, ql, qr)
		} else {
			panic("Invalid query range")
		}
	}
}

func (ts *TreeSegment) update(i, tl, tr, ql, qr int, mod Mod) {
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

func (ts *TreeSegment) findRight(i, tl, tr, L int, checker func(Value) bool, pref Value) (int, Value) {
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
			_left := ts.magic(pref, ts.getValue(ts.S[i].l, tl, mid))
			if checker(_left) {
				return ts.findRight(ts.S[i].l, tl, mid, L, checker, pref)
			} else {
				return ts.findRight(ts.S[i].r, mid, tr, L, checker, _left)
			}
		} else {
			t := ts.findRight(ts.S[i].l, tl, mid, L, checker, pref)
			if t.first != -1 {
				return t.first, t.second
			}
			return ts.findRight(ts.S[i].r, mid, tr, L, checker, t.second)
		}
	}
}

func (ts *TreeSegment) findLeft(i, tl, tr, R int, checker func(Value) bool, pref Value) (int, Value) {
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
		magic: func(a, b Value) Value {
			return a + b
		},
		applyMod: func(value Value, mod Mod, tl, tr int) Value {
			return mod
		},
		mergeMods: func(old, _new Mod, tl, tr int) Mod {
			return _new
		},
	}

	subw := make([]int, n)
	for i := 0; i < n; i++ {
		subw[i] = (w[i] * (i - pos[i])) % MOD
	}

	resp := TreeSegment{
		magic: func(a, b Value) Value {
			return (a + b) % MOD
		},
		applyMod: func(value Value, mod Mod, tl, tr int) Value {
			return mod
		},
		mergeMods: func(old, _new Mod, tl, tr int) Mod {
			return _new
		},
	}

	ts.init(0, len(w), w)
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
			l, r := x, y
			l--

			sm := ts.query(0, 0, n, l, r)

			bestL := ts.findRight(0, 0, n, l, func(x Value) bool {
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
