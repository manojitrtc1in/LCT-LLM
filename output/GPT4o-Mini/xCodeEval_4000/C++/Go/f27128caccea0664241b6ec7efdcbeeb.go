package main

import (
	"fmt"
	"math/big"
)

const md = 1e9 + 7

type Mint struct {
	value int64
}

func NewMint(x int64) Mint {
	return Mint{normalize(x)}
}

func normalize(x int64) int64 {
	if x < 0 {
		x += md
	}
	return x % int64(md)
}

func (m *Mint) Add(other Mint) Mint {
	m.value = normalize(m.value + other.value)
	return *m
}

func (m *Mint) Sub(other Mint) Mint {
	m.value = normalize(m.value - other.value)
	return *m
}

func (m *Mint) Mul(other Mint) Mint {
	m.value = normalize(m.value * other.value)
	return *m
}

func (m *Mint) String() string {
	return fmt.Sprintf("%d", m.value)
}

type Node struct {
	w  int64
	Wp Mint
	fp Mint
	tp Mint
}

func (n *Node) Apply(l, r, v, id, rid, a int64) {
	n.w = v
	n.Wp = NewMint(v).Mul(NewMint(a))
	n.fp = NewMint(v).Mul(NewMint(id))
	n.tp = NewMint(v).Mul(NewMint(rid))
}

type SegTree struct {
	n    int
	tree []Node
}

func NewSegTree(v []int64, a []int64) *SegTree {
	n := len(v)
	st := &SegTree{n: n, tree: make([]Node, 2*n-1)}
	st.build(0, 0, n-1, v, a)
	return st
}

func (st *SegTree) build(x, l, r int, v []int64, a []int64) {
	if l == r {
		st.tree[x].Apply(l, r, v[l], int64(l), int64(st.n-1-r), a[l])
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	st.build(x+1, l, y, v, a)
	st.build(z, y+1, r, v, a)
	st.pull(x, z)
}

func (st *SegTree) pull(x, z int) {
	st.tree[x] = unite(st.tree[x+1], st.tree[z])
}

func unite(a, b Node) Node {
	return Node{
		w:  a.w + b.w,
		Wp: a.Wp.Add(b.Wp),
		fp: a.fp.Add(b.fp),
		tp: a.tp.Add(b.tp),
	}
}

func (st *SegTree) Get(ll, rr int) Node {
	return st.get(0, 0, st.n-1, ll, rr)
}

func (st *SegTree) get(x, l, r, ll, rr int) Node {
	if ll <= l && r <= rr {
		return st.tree[x]
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	res := Node{}
	if rr <= y {
		res = st.get(x+1, l, y, ll, rr)
	} else if ll > y {
		res = st.get(z, y+1, r, ll, rr)
	} else {
		res = unite(st.get(x+1, l, y, ll, rr), st.get(z, y+1, r, ll, rr))
	}
	st.pull(x, z)
	return res
}

func (st *SegTree) Modify(ll, rr, v, id, rid, a int64) {
	st.modify(0, 0, st.n-1, ll, rr, v, id, rid, a)
}

func (st *SegTree) modify(x, l, r, ll, rr, v, id, rid, a int64) {
	if ll <= l && r <= rr {
		st.tree[x].Apply(l, r, v, id, rid, a)
		return
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	if ll <= y {
		st.modify(x+1, l, y, ll, rr, v, id, rid, a)
	}
	if rr > y {
		st.modify(z, y+1, r, ll, rr, v, id, rid, a)
	}
	st.pull(x, z)
}

func main() {
	var n, q int
	fmt.Scan(&n, &q)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	w := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	st := NewSegTree(w, a)
	for q > 0 {
		q--
		var x, y int
		fmt.Scan(&x, &y)
		if x < 0 {
			x = -x - 1
			st.Modify(int64(x), int64(x), int64(y), int64(x), int64(n-1-x), a[x])
		} else {
			x--
			y--
			var v int64 = 0
			sum := st.Get(x, y).w
			pos := st.findFirst(x, y, func(n Node) bool {
				if (v+n.w)*2 >= sum {
					return true
				}
				v += n.w
				return false
			})
			if pos == -1 {
				panic("position not found")
			}
			l := st.Get(x, pos)
			r := st.Get(pos, y)
			res := NewMint(0)

			res = res.Add(r.Wp).Sub(r.fp).Sub(NewMint(a[pos]-int64(pos)).Mul(r.w))
			res = res.Add(NewMint(a[pos]-int64(pos)).Mul(l.w)).Add(l.fp).Sub(l.Wp)
			fmt.Println(res)
		}
	}
}

func (st *SegTree) findFirst(x, y int, f func(Node) bool) int {
	return st.findFirstHelper(0, 0, st.n-1, x, y, f)
}

func (st *SegTree) findFirstHelper(x, l, r, ll, rr int, f func(Node) bool) int {
	if ll <= l && r <= rr {
		if !f(st.tree[x]) {
			return -1
		}
		return st.findFirstKnowingly(x, l, r, f)
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	res := -1
	if ll <= y {
		res = st.findFirstHelper(x+1, l, y, ll, rr, f)
	}
	if rr > y && res == -1 {
		res = st.findFirstHelper(z, y+1, r, ll, rr, f)
	}
	return res
}

func (st *SegTree) findFirstKnowingly(x, l, r int, f func(Node) bool) int {
	if l == r {
		return l
	}
	y := (l + r) >> 1
	z := x + ((y - l + 1) << 1)
	if f(st.tree[x+1]) {
		return st.findFirstKnowingly(x+1, l, y, f)
	}
	return st.findFirstKnowingly(z, y+1, r, f)
}
