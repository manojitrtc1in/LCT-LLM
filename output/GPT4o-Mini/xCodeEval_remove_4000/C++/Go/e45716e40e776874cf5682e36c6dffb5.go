package main

import (
	"fmt"
	"math"
	"sort"
)

type SegmentTree struct {
	n       int
	n0      int
	maxV    []int64
	smaxV   []int64
	maxC    []int64
	minV    []int64
	sminV   []int64
	minC    []int64
	sum     []int64
	len     []int64
	ladd    []int64
	lval    []int64
	inf     int64
}

func NewSegmentTree(n int, a []int64) *SegmentTree {
	st := &SegmentTree{
		n:    n,
		inf:  math.MaxInt64,
		n0:   1,
		maxV: make([]int64, 4*n),
		smaxV: make([]int64, 4*n),
		maxC: make([]int64, 4*n),
		minV: make([]int64, 4*n),
		sminV: make([]int64, 4*n),
		minC: make([]int64, 4*n),
		sum:  make([]int64, 4*n),
		len:  make([]int64, 4*n),
		ladd: make([]int64, 4*n),
		lval: make([]int64, 4*n),
	}

	for st.n0 < n {
		st.n0 <<= 1
	}

	for i := 0; i < 2*st.n0; i++ {
		st.ladd[i] = 0
		st.lval[i] = st.inf
	}
	st.len[0] = st.n0
	for i := 0; i < st.n0-1; i++ {
		st.len[2*i+1] = st.len[i] >> 1
		st.len[2*i+2] = st.len[i] >> 1
	}

	for i := 0; i < n; i++ {
		st.maxV[st.n0-1+i] = a[i]
		st.minV[st.n0-1+i] = a[i]
		st.sum[st.n0-1+i] = a[i]
		st.smaxV[st.n0-1+i] = -st.inf
		st.sminV[st.n0-1+i] = st.inf
		st.maxC[st.n0-1+i] = 1
		st.minC[st.n0-1+i] = 1
	}

	for i := n; i < st.n0; i++ {
		st.maxV[st.n0-1+i] = -st.inf
		st.smaxV[st.n0-1+i] = -st.inf
		st.minV[st.n0-1+i] = st.inf
		st.sminV[st.n0-1+i] = st.inf
		st.maxC[st.n0-1+i] = 0
		st.minC[st.n0-1+i] = 0
	}
	for i := st.n0 - 2; i >= 0; i-- {
		st.update(i)
	}

	return st
}

func (st *SegmentTree) update(k int) {
	st.sum[k] = st.sum[2*k+1] + st.sum[2*k+2]

	if st.maxV[2*k+1] < st.maxV[2*k+2] {
		st.maxV[k] = st.maxV[2*k+2]
		st.maxC[k] = st.maxC[2*k+2]
		st.smaxV[k] = max(st.maxV[2*k+1], st.smaxV[2*k+2])
	} else if st.maxV[2*k+1] > st.maxV[2*k+2] {
		st.maxV[k] = st.maxV[2*k+1]
		st.maxC[k] = st.maxC[2*k+1]
		st.smaxV[k] = max(st.smaxV[2*k+1], st.maxV[2*k+2])
	} else {
		st.maxV[k] = st.maxV[2*k+1]
		st.maxC[k] = st.maxC[2*k+1] + st.maxC[2*k+2]
		st.smaxV[k] = max(st.smaxV[2*k+1], st.smaxV[2*k+2])
	}

	if st.minV[2*k+1] < st.minV[2*k+2] {
		st.minV[k] = st.minV[2*k+1]
		st.minC[k] = st.minC[2*k+1]
		st.sminV[k] = min(st.sminV[2*k+1], st.minV[2*k+2])
	} else if st.minV[2*k+1] > st.minV[2*k+2] {
		st.minV[k] = st.minV[2*k+2]
		st.minC[k] = st.minC[2*k+2]
		st.sminV[k] = min(st.minV[2*k+1], st.sminV[2*k+2])
	} else {
		st.minV[k] = st.minV[2*k+1]
		st.minC[k] = st.minC[2*k+1] + st.minC[2*k+2]
		st.sminV[k] = min(st.sminV[2*k+1], st.sminV[2*k+2])
	}
}

func (st *SegmentTree) push(k int) {
	if st.n0-1 <= k {
		return
	}

	if st.lval[k] != st.inf {
		st.updateAll(2*k+1, st.lval[k])
		st.updateAll(2*k+2, st.lval[k])
		st.lval[k] = st.inf
		return
	}

	if st.ladd[k] != 0 {
		st.addAll(2*k+1, st.ladd[k])
		st.addAll(2*k+2, st.ladd[k])
		st.ladd[k] = 0
	}

	if st.maxV[k] < st.maxV[2*k+1] {
		st.updateNodeMax(2*k+1, st.maxV[k])
	}
	if st.minV[2*k+1] < st.minV[k] {
		st.updateNodeMin(2*k+1, st.minV[k])
	}

	if st.maxV[k] < st.maxV[2*k+2] {
		st.updateNodeMax(2*k+2, st.maxV[k])
	}
	if st.minV[2*k+2] < st.minV[k] {
		st.updateNodeMin(2*k+2, st.minV[k])
	}
}

func (st *SegmentTree) updateNodeMax(k int, x int64) {
	st.sum[k] += (x - st.maxV[k]) * st.maxC[k]

	if st.maxV[k] == st.minV[k] {
		st.maxV[k] = st.minV[k] = x
	} else if st.maxV[k] == st.sminV[k] {
		st.maxV[k] = st.sminV[k] = x
	} else {
		st.maxV[k] = x
	}

	if st.lval[k] != st.inf && x < st.lval[k] {
		st.lval[k] = x
	}
}

func (st *SegmentTree) updateNodeMin(k int, x int64) {
	st.sum[k] += (x - st.minV[k]) * st.minC[k]

	if st.maxV[k] == st.minV[k] {
		st.maxV[k] = st.minV[k] = x
	} else if st.smaxV[k] == st.minV[k] {
		st.minV[k] = st.smaxV[k] = x
	} else {
		st.minV[k] = x
	}

	if st.lval[k] != st.inf && st.lval[k] < x {
		st.lval[k] = x
	}
}

func (st *SegmentTree) addAll(k int, x int64) {
	st.maxV[k] += x
	if st.smaxV[k] != -st.inf {
		st.smaxV[k] += x
	}
	st.minV[k] += x
	if st.sminV[k] != st.inf {
		st.sminV[k] += x
	}

	st.sum[k] += st.len[k] * x
	if st.lval[k] != st.inf {
		st.lval[k] += x
	} else {
		st.ladd[k] += x
	}
}

func (st *SegmentTree) updateAll(k int, x int64) {
	st.maxV[k] = x
	st.smaxV[k] = -st.inf
	st.minV[k] = x
	st.sminV[k] = st.inf
	st.maxC[k] = st.len[k]
	st.minC[k] = st.len[k]

	st.sum[k] = x * st.len[k]
	st.lval[k] = x
	st.ladd[k] = 0
}

func (st *SegmentTree) queryMax(a, b int) int64 {
	return st._queryMax(a, b, 0, 0, st.n0)
}

func (st *SegmentTree) queryMin(a, b int) int64 {
	return st._queryMin(a, b, 0, 0, st.n0)
}

func (st *SegmentTree) querySum(a, b int) int64 {
	return st._querySum(a, b, 0, 0, st.n0)
}

func (st *SegmentTree) _queryMax(a, b, k, l, r int) int64 {
	if b <= l || r <= a {
		return -st.inf
	}
	if a <= l && r <= b {
		return st.maxV[k]
	}
	st.push(k)
	lv := st._queryMax(a, b, 2*k+1, l, (l+r)/2)
	rv := st._queryMax(a, b, 2*k+2, (l+r)/2, r)
	return max(lv, rv)
}

func (st *SegmentTree) _queryMin(a, b, k, l, r int) int64 {
	if b <= l || r <= a {
		return st.inf
	}
	if a <= l && r <= b {
		return st.minV[k]
	}
	st.push(k)
	lv := st._queryMin(a, b, 2*k+1, l, (l+r)/2)
	rv := st._queryMin(a, b, 2*k+2, (l+r)/2, r)
	return min(lv, rv)
}

func (st *SegmentTree) _querySum(a, b, k, l, r int) int64 {
	if b <= l || r <= a {
		return 0
	}
	if a <= l && r <= b {
		return st.sum[k]
	}
	st.push(k)
	lv := st._querySum(a, b, 2*k+1, l, (l+r)/2)
	rv := st._querySum(a, b, 2*k+2, (l+r)/2, r)
	return lv + rv
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	v := make([]int64, n)
	for i := 0; i < n; i++ {
		v[i] = int64(i - 1)
	}
	seg := NewSegmentTree(n, v)

	d := make([][]int, 200001)
	for i := 0; i < n; i++ {
		for j := 1; j*j <= a[i]; j++ {
			if a[i]%int64(j) == 0 {
				d[j] = append(d[j], i)
				if a[i] != int64(j*j) {
					d[a[i]/int64(j)] = append(d[a[i]/int64(j)], i)
				}
			}
		}
	}
	ans := int64(0)
	for i := 200000; i >= 1; i-- {
		w := d[i]
		if len(w) <= 1 {
			continue
		}

		s := []int{}
		s = append(s, w[0], w[1], w[len(w)-2], w[len(w)-1])
		F := func(l, r int) {
			seg.updateMax(l, r, int64(r-1))
		}
		pre := seg.querySum(0, n)
		F(w[0]+1, w[len(w)-1])
		F(0, w[len(w)-2])
		F(w[1]+1, n)
		ans += (seg.querySum(0, n) - pre) * int64(i)
	}
	fmt.Println(ans)
}
