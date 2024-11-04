package main

import (
	"fmt"
	"math"
)

const (
	MAXN   = 1e5 + 5
	id0    = 20
	INT_INF = 0x3f3f3f3f
)

type pii struct {
	f, s int
}

type SegmentTree struct {
	N int
	T [2 * MAXN]pii
	def pii
	qdef pii
}

func NewSegmentTree() *SegmentTree {
	return &SegmentTree{
		def:  pii{INT_INF, -INT_INF},
		qdef: pii{INT_INF, -INT_INF},
	}
}

func (st *SegmentTree) merge(l, r pii) pii {
	return pii{min(l.f, r.f), max(l.s, r.s)}
}

func (st *SegmentTree) applyVal(l, r pii) pii {
	return r
}

func (st *SegmentTree) init(arr []pii) {
	st.N = len(arr)
	for i := 0; i < st.N; i++ {
		st.T[st.N+i] = arr[i]
	}
	for i := st.N - 1; i > 0; i-- {
		st.T[i] = st.merge(st.T[i<<1], st.T[i<<1|1])
	}
}

func (st *SegmentTree) update(i int, v pii) {
	for i += st.N; i > 0; i >>= 1 {
		st.T[i] = st.applyVal(st.T[i], v)
		if i > 1 {
			st.T[i>>1] = st.merge(st.T[i<<1], st.T[i<<1|1])
		}
	}
}

func (st *SegmentTree) query(l, r int) pii {
	ql := st.qdef
	qr := st.qdef
	for l += st.N; r += st.N; l <= r {
		if l&1 == 1 {
			ql = st.merge(ql, st.T[l])
			l++
		}
		if r&1 == 0 {
			qr = st.merge(st.T[r], qr)
			r--
		}
		l >>= 1
		r >>= 1
	}
	return st.merge(ql, qr)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var N int
	var R [MAXN]int
	var ans [MAXN]int
	var T [id0]*SegmentTree
	var RANGE [id0][3 * MAXN]pii

	for i := 0; i < id0; i++ {
		T[i] = NewSegmentTree()
	}

	fmt.Scan(&N)
	for i := 0; i < N; i++ {
		fmt.Scan(&R[i])
	}

	if N == 1 {
		fmt.Println(0)
		return
	}

	for j := 0; j < 3*N; j++ {
		RANGE[0][j] = pii{max(0, j - R[j%N]), min(3*N-1, j + R[j%N])}
	}
	T[0].init(RANGE[0][:])

	for i := 1; i < id0; i++ {
		for j := 0; j < 3*N; j++ {
			T[i].update(j, T[i-1].query(RANGE[i-1][j].f, RANGE[i-1][j].s))
		}
	}

	for i := 0; i < N; i++ {
		ans[i] = 1
		cur := pii{N + i, N + i}
		for j := id0 - 1; j >= 0; j-- {
			nxt := T[j].query(cur.f, cur.s)
			if nxt.s-nxt.f+1 < N {
				ans[i] += 1 << j
				cur = nxt
			}
		}
	}

	for i := 0; i < N; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(ans[i])
	}
	fmt.Println()
}
