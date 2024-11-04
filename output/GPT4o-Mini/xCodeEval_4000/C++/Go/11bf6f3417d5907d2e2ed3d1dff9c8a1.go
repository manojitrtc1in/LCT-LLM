package main

import (
	"fmt"
	"math"
)

const MAXN = 1e5 + 5
const MAXLGN = 20

type Data struct {
	f int
	s int
}

type SegmentTree struct {
	N   int
	T   [2 * MAXN]Data
	def Data
	qdef Data
}

func (st *SegmentTree) merge(l, r Data) Data {
	return Data{min(l.f, r.f), max(l.s, r.s)}
}

func (st *SegmentTree) applyVal(l, r Data) Data {
	return r
}

func (st *SegmentTree) init(arr []Data) {
	st.N = len(arr)
	for i := 0; i < st.N; i++ {
		st.T[st.N+i] = arr[i]
	}
	for i := st.N - 1; i > 0; i-- {
		st.T[i] = st.merge(st.T[i<<1], st.T[i<<1|1])
	}
}

func (st *SegmentTree) update(i int, v Data) {
	for i += st.N; i > 0; i >>= 1 {
		if i < st.N {
			st.T[i] = st.applyVal(st.T[i], v)
		}
		st.T[i] = st.merge(st.T[i<<1], st.T[i<<1|1])
	}
}

func (st *SegmentTree) query(l, r int) Data {
	ql := st.qdef
	qr := st.qdef
	for l += st.N; l <= r; l >>= 1 {
		if l&1 != 0 {
			ql = st.merge(ql, st.T[l])
			l++
		}
		if r&1 == 0 {
			qr = st.merge(st.T[r], qr)
			r--
		}
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
	var T [MAXLGN]SegmentTree
	var RANGE [MAXLGN][3 * MAXN]Data

	for i := 0; i < MAXLGN; i++ {
		T[i].def = Data{math.MaxInt32, math.MinInt32}
		T[i].qdef = Data{math.MaxInt32, math.MinInt32}
		T[i].init(make([]Data, 3*MAXN))
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
		T[0].update(j, Data{max(0, j-R[j%N]), min(3*N-1, j+R[j%N])})
		RANGE[0][j] = Data{max(0, j-R[j%N]), min(3*N-1, j+R[j%N])}
	}

	for i := 1; i < MAXLGN; i++ {
		for j := 0; j < 3*N; j++ {
			T[i].update(j, T[i-1].query(RANGE[i-1][j].f, RANGE[i-1][j].s))
			RANGE[i][j] = T[i].query(RANGE[i-1][j].f, RANGE[i-1][j].s)
		}
	}

	for i := 0; i < N; i++ {
		ans[i] = 1
		cur := Data{N + i, N + i}
		for j := MAXLGN - 1; j >= 0; j-- {
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
