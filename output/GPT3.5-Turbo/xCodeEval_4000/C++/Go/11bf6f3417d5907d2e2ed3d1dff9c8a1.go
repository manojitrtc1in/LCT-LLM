package main

import (
	"bufio"
	"fmt"
	"os"
)

type pii struct {
	f, s int
}

type SegmentTree_SAM_RQ struct {
	N  int
	T  []pii
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
	st.T = make([]pii, 2*size)
	for i := 0; i < 2*size; i++ {
		st.T[i] = st.def
	}
}

func (st *SegmentTree_SAM_RQ) update(i int, v pii) {
	for i += st.N - 1; i > 0; i >>= 1 {
		st.T[i] = st.applyVal(st.T[i], v)
	}
}

func (st *SegmentTree_SAM_RQ) query(l, r int) pii {
	ql, qr := st.qdef, st.qdef
	for l <= r {
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

const (
	MAXN   = 1e5 + 5
	MAXLGN = 20
)

var (
	N     int
	R     [MAXN]int
	ans   [MAXN]int
	T     [MAXLGN]SegmentTree_SAM_RQ
	RANGE [MAXLGN][MAXN * 3]pii
)

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

	fmt.Fscan(reader, &N)
	for i := 0; i < N; i++ {
		fmt.Fscan(reader, &R[i])
	}
	if N == 1 {
		fmt.Fprintln(writer, 0)
		return
	}
	for i := 0; i < MAXLGN; i++ {
		T[i].init(3 * N)
	}
	for j := 0; j < 3*N; j++ {
		T[0].update(j, RANGE[0][j] = pii{max(0, j-R[j%N]), min(3*N-1, j+R[j%N])})
	}
	for i := 1; i < MAXLGN; i++ {
		for j := 0; j < 3*N; j++ {
			T[i].update(j, RANGE[i][j] = T[i-1].query(RANGE[i-1][j].f, RANGE[i-1][j].s))
		}
	}
	for i := 0; i < N; i++ {
		ans[i] = 1
		cur := pii{N + i, N + i}
		for j := MAXLGN - 1; j >= 0; j-- {
			nxt := T[j].query(cur.f, cur.s)
			if nxt.s-nxt.f+1 < N {
				ans[i] += 1 << j
				cur = nxt
			}
		}
	}
	fmt.Fprintln(writer, ans[:N])
}

