package main

import (
	"fmt"
	"math"
	"sort"
)

const N = 200001

type SegmentTree struct {
	inf      int64
	n, n0    int
	maxV     []int64
	smaxV    []int64
	maxC     []int64
	minV     []int64
	sminV    []int64
	minC     []int64
	sum      []int64
	len      []int64
	ladd     []int64
	lval     []int64
}

func NewSegmentTree(n int, a []int64) *SegmentTree {
	seg := &SegmentTree{
		inf:   1e18,
		n:     n,
		n0:    1,
		maxV:  make([]int64, 4*N),
		smaxV: make([]int64, 4*N),
		maxC:  make([]int64, 4*N),
		minV:  make([]int64, 4*N),
		sminV: make([]int64, 4*N),
		minC:  make([]int64, 4*N),
		sum:   make([]int64, 4*N),
		len:   make([]int64, 4*N),
		ladd:  make([]int64, 4*N),
		lval:  make([]int64, 4*N),
	}

	for seg.n0 < n {
		seg.n0 <<= 1
	}

	for i := 0; i < 2*seg.n0; i++ {
		seg.ladd[i] = 0
		seg.lval[i] = seg.inf
	}
	seg.len[0] = seg.n0
	for i := 0; i < seg.n0-1; i++ {
		seg.len[2*i+1] = seg.len[2*i+2] = seg.len[i] >> 1
	}

	for i := 0; i < n; i++ {
		seg.maxV[seg.n0-1+i] = seg.minV[seg.n0-1+i] = seg.sum[seg.n0-1+i] = a[i]
		seg.smaxV[seg.n0-1+i] = -seg.inf
		seg.sminV[seg.n0-1+i] = seg.inf
		seg.maxC[seg.n0-1+i] = seg.minC[seg.n0-1+i] = 1
	}

	for i := n; i < seg.n0; i++ {
		seg.maxV[seg.n0-1+i] = seg.smaxV[seg.n0-1+i] = -seg.inf
		seg.minV[seg.n0-1+i] = seg.sminV[seg.n0-1+i] = seg.inf
		seg.maxC[seg.n0-1+i] = seg.minC[seg.n0-1+i] = 0
	}
	for i := seg.n0 - 2; i >= 0; i-- {
		seg.update(i)
	}
	return seg
}

func (seg *SegmentTree) update(k int) {
	seg.sum[k] = seg.sum[2*k+1] + seg.sum[2*k+2]

	if seg.maxV[2*k+1] < seg.maxV[2*k+2] {
		seg.maxV[k] = seg.maxV[2*k+2]
		seg.maxC[k] = seg.maxC[2*k+2]
		seg.smaxV[k] = max(seg.maxV[2*k+1], seg.smaxV[2*k+2])
	} else if seg.maxV[2*k+1] > seg.maxV[2*k+2] {
		seg.maxV[k] = seg.maxV[2*k+1]
		seg.maxC[k] = seg.maxC[2*k+1]
		seg.smaxV[k] = max(seg.smaxV[2*k+1], seg.maxV[2*k+2])
	} else {
		seg.maxV[k] = seg.maxV[2*k+1]
		seg.maxC[k] = seg.maxC[2*k+1] + seg.maxC[2*k+2]
		seg.smaxV[k] = max(seg.smaxV[2*k+1], seg.smaxV[2*k+2])
	}

	if seg.minV[2*k+1] < seg.minV[2*k+2] {
		seg.minV[k] = seg.minV[2*k+1]
		seg.minC[k] = seg.minC[2*k+1]
		seg.sminV[k] = min(seg.sminV[2*k+1], seg.minV[2*k+2])
	} else if seg.minV[2*k+1] > seg.minV[2*k+2] {
		seg.minV[k] = seg.minV[2*k+2]
		seg.minC[k] = seg.minC[2*k+2]
		seg.sminV[k] = min(seg.minV[2*k+1], seg.sminV[2*k+2])
	} else {
		seg.minV[k] = seg.minV[2*k+1]
		seg.minC[k] = seg.minC[2*k+1] + seg.minC[2*k+2]
		seg.sminV[k] = min(seg.sminV[2*k+1], seg.sminV[2*k+2])
	}
}

func (seg *SegmentTree) updateMin(a, b int64, x int64) {
	seg._updateMin(x, a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) _updateMin(x, a, b int64, k, l, r int) {
	if b <= l || r <= a || seg.maxV[k] <= x {
		return
	}
	if a <= l && r <= b && seg.smaxV[k] < x {
		seg.updateNodeMax(k, x)
		return
	}

	seg.push(k)
	seg._updateMin(x, a, b, 2*k+1, l, (l+r)/2)
	seg._updateMin(x, a, b, 2*k+2, (l+r)/2, r)
	seg.update(k)
}

func (seg *SegmentTree) updateNodeMax(k int, x int64) {
	seg.sum[k] += (x - seg.maxV[k]) * seg.maxC[k]

	if seg.maxV[k] == seg.minV[k] {
		seg.maxV[k] = seg.minV[k] = x
	} else if seg.maxV[k] == seg.sminV[k] {
		seg.maxV[k] = seg.sminV[k] = x
	} else {
		seg.maxV[k] = x
	}

	if seg.lval[k] != seg.inf && x < seg.lval[k] {
		seg.lval[k] = x
	}
}

func (seg *SegmentTree) querySum(a, b int64) int64 {
	return seg._querySum(a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) _querySum(a, b int64, k, l, r int) int64 {
	if b <= l || r <= a {
		return 0
	}
	if a <= l && r <= b {
		return seg.sum[k]
	}
	seg.push(k)
	lv := seg._querySum(a, b, 2*k+1, l, (l+r)/2)
	rv := seg._querySum(a, b, 2*k+2, (l+r)/2, r)
	return lv + rv
}

func (seg *SegmentTree) push(k int) {
	if seg.n0-1 <= k {
		return
	}

	if seg.lval[k] != seg.inf {
		seg.updateAll(2*k+1, seg.lval[k])
		seg.updateAll(2*k+2, seg.lval[k])
		seg.lval[k] = seg.inf
		return
	}

	if seg.ladd[k] != 0 {
		seg.addAll(2*k+1, seg.ladd[k])
		seg.addAll(2*k+2, seg.ladd[k])
		seg.ladd[k] = 0
	}

	if seg.maxV[k] < seg.maxV[2*k+1] {
		seg.updateNodeMax(2*k+1, seg.maxV[k])
	}
	if seg.minV[2*k+1] < seg.minV[k] {
		seg.updateNodeMin(2*k+1, seg.minV[k])
	}

	if seg.maxV[k] < seg.maxV[2*k+2] {
		seg.updateNodeMax(2*k+2, seg.maxV[k])
	}
	if seg.minV[2*k+2] < seg.minV[k] {
		seg.updateNodeMin(2*k+2, seg.minV[k])
	}
}

func (seg *SegmentTree) updateNodeMin(k int, x int64) {
	seg.sum[k] += (x - seg.minV[k]) * seg.minC[k]

	if seg.maxV[k] == seg.minV[k] {
		seg.maxV[k] = seg.minV[k] = x
	} else if seg.smaxV[k] == seg.minV[k] {
		seg.minV[k] = seg.smaxV[k] = x
	} else {
		seg.minV[k] = x
	}

	if seg.lval[k] != seg.inf && seg.lval[k] < x {
		seg.lval[k] = x
	}
}

func (seg *SegmentTree) addAll(k int, x int64) {
	seg.maxV[k] += x
	if seg.smaxV[k] != -seg.inf {
		seg.smaxV[k] += x
	}
	seg.minV[k] += x
	if seg.sminV[k] != seg.inf {
		seg.sminV[k] += x
	}

	seg.sum[k] += seg.len[k] * x
	if seg.lval[k] != seg.inf {
		seg.lval[k] += x
	} else {
		seg.ladd[k] += x
	}
}

func (seg *SegmentTree) updateAll(k int, x int64) {
	seg.maxV[k] = x
	seg.smaxV[k] = -seg.inf
	seg.minV[k] = x
	seg.sminV[k] = seg.inf
	seg.maxC[k] = seg.len[k]
	seg.minC[k] = seg.len[k]

	seg.sum[k] = x * seg.len[k]
	seg.lval[k] = x
	seg.ladd[k] = 0
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

	d := make([][]int64, 200001)
	for i := 0; i < n; i++ {
		for j := int64(1); j*j <= a[i]; j++ {
			if a[i]%j == 0 {
				d[j] = append(d[j], int64(i))
				if a[i] != j*j {
					d[a[i]/j] = append(d[a[i]/j], int64(i))
				}
			}
		}
	}
	ans := int64(0)
	for i := int64(200000); i >= 1; i-- {
		w := d[i]
		if len(w) <= 1 {
			continue
		}

		s := []int64{w[0], w[1], w[len(w)-2], w[len(w)-1]}
		F := func(l, r int64) {
			seg.updateMax(l, r, r-1)
		}
		pre := seg.querySum(0, int64(n))
		F(w[0]+1, w[len(w)-1])
		F(0, w[len(w)-2])
		F(w[1]+1, int64(n))
		ans += (seg.querySum(0, int64(n)) - pre) * i
	}
	fmt.Println(ans)
}
