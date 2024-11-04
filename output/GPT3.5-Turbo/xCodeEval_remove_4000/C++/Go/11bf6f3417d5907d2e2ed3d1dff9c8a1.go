package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	MAXN = 1e5 + 5
	id0  = 20
)

type pii struct {
	f, s int
}

type SegmentTree_SAM_RQ struct {
	N  int
	T  [2 * MAXN]pii
	def pii
	qdef pii
}

func (st *SegmentTree_SAM_RQ) merge(l, r pii) pii {
	return pii{min(l.f, r.f), max(l.s, r.s)}
}

func (st *SegmentTree_SAM_RQ) applyVal(l, r pii) pii {
	return r
}

func (st *SegmentTree_SAM_RQ) init(size int) {
	st.N = size
	for i := 1; i < 2*st.N; i++ {
		st.T[i] = st.def
	}
}

func (st *SegmentTree_SAM_RQ) update(i int, v pii) {
	for i += st.N; i > 0; i >>= 1 {
		st.T[i] = st.applyVal(st.T[i], v)
	}
}

func (st *SegmentTree_SAM_RQ) query(l, r int) pii {
	ql, qr := st.qdef, st.qdef
	for l, r = l+st.N, r+st.N; l <= r; l, r = l>>1, r>>1 {
		if l&1 == 1 {
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
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	R := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &R[i])
	}

	if N == 1 {
		fmt.Fprintln(writer, 0)
		return
	}

	T := make([]SegmentTree_SAM_RQ, id0)
	RANGE := make([][2 * MAXN]pii, id0)

	for i := 0; i < id0; i++ {
		T[i].init(3 * N)
	}

	for j := 0; j < 3*N; j++ {
		T[0].update(j, pii{max(0, j-R[j%N]), min(3*N-1, j+R[j%N])})
		RANGE[0][j] = pii{max(0, j-R[j%N]), min(3*N-1, j+R[j%N])}
	}

	for i := 1; i < id0; i++ {
		for j := 0; j < 3*N; j++ {
			T[i].update(j, RANGE[i-1][j])
			RANGE[i][j] = T[i-1].query(RANGE[i-1][j].f, RANGE[i-1][j].s)
		}
	}

	ans := make([]int, N)
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
		fmt.Fprint(writer, ans[i], " ")
	}
	fmt.Fprintln(writer)
}
