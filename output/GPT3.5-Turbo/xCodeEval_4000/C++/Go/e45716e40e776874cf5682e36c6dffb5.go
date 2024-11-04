package main

import (
	"fmt"
)

type SegmentTree struct {
	n      int
	n0     int
	max_v  []int
	smax_v []int
	max_c  []int
	min_v  []int
	smin_v []int
	min_c  []int
	sum    []int
	len    []int
	ladd   []int
	lval   []int
}

func NewSegmentTree(n int, a []int) *SegmentTree {
	seg := &SegmentTree{
		n:      n,
		n0:     1,
		max_v:  make([]int, 4*n),
		smax_v: make([]int, 4*n),
		max_c:  make([]int, 4*n),
		min_v:  make([]int, 4*n),
		smin_v: make([]int, 4*n),
		min_c:  make([]int, 4*n),
		sum:    make([]int, 4*n),
		len:    make([]int, 4*n),
		ladd:   make([]int, 4*n),
		lval:   make([]int, 4*n),
	}

	seg.n0 = 1
	for seg.n0 < n {
		seg.n0 <<= 1
	}

	for i := 0; i < 2*seg.n0; i++ {
		seg.ladd[i] = 0
		seg.lval[i] = 1<<31 - 1
	}
	seg.len[0] = seg.n0
	for i := 0; i < seg.n0-1; i++ {
		seg.len[2*i+1] = seg.len[2*i+2] = (seg.len[i] >> 1)
	}

	for i := 0; i < n; i++ {
		seg.max_v[seg.n0-1+i] = a[i]
		seg.min_v[seg.n0-1+i] = a[i]
		seg.sum[seg.n0-1+i] = a[i]
		seg.smax_v[seg.n0-1+i] = -1 << 31
		seg.smin_v[seg.n0-1+i] = 1 << 31
		seg.max_c[seg.n0-1+i] = 1
		seg.min_c[seg.n0-1+i] = 1
	}

	for i := n; i < seg.n0; i++ {
		seg.max_v[seg.n0-1+i] = -1 << 31
		seg.min_v[seg.n0-1+i] = 1 << 31
		seg.max_c[seg.n0-1+i] = 0
		seg.min_c[seg.n0-1+i] = 0
	}
	for i := seg.n0 - 2; i >= 0; i-- {
		seg.update(i)
	}

	return seg
}

func (seg *SegmentTree) update_node_max(k, x int) {
	seg.sum[k] += (x - seg.max_v[k]) * seg.max_c[k]

	if seg.max_v[k] == seg.min_v[k] {
		seg.max_v[k] = seg.min_v[k] = x
	} else if seg.max_v[k] == seg.smin_v[k] {
		seg.max_v[k] = seg.smin_v[k] = x
	} else {
		seg.max_v[k] = x
	}

	if seg.lval[k] != 1<<31-1 && x < seg.lval[k] {
		seg.lval[k] = x
	}
}

func (seg *SegmentTree) update_node_min(k, x int) {
	seg.sum[k] += (x - seg.min_v[k]) * seg.min_c[k]

	if seg.max_v[k] == seg.min_v[k] {
		seg.max_v[k] = seg.min_v[k] = x
	} else if seg.smax_v[k] == seg.min_v[k] {
		seg.min_v[k] = seg.smax_v[k] = x
	} else {
		seg.min_v[k] = x
	}

	if seg.lval[k] != 1<<31-1 && seg.lval[k] < x {
		seg.lval[k] = x
	}
}

func (seg *SegmentTree) push(k int) {
	if seg.n0-1 <= k {
		return
	}

	if seg.lval[k] != 1<<31-1 {
		seg.updateall(2*k+1, seg.lval[k])
		seg.updateall(2*k+2, seg.lval[k])
		seg.lval[k] = 1<<31 - 1
		return
	}

	if seg.ladd[k] != 0 {
		seg.addall(2*k+1, seg.ladd[k])
		seg.addall(2*k+2, seg.ladd[k])
		seg.ladd[k] = 0
	}

	if seg.max_v[k] < seg.max_v[2*k+1] {
		seg.update_node_max(2*k+1, seg.max_v[k])
	}
	if seg.min_v[2*k+1] < seg.min_v[k] {
		seg.update_node_min(2*k+1, seg.min_v[k])
	}

	if seg.max_v[k] < seg.max_v[2*k+2] {
		seg.update_node_max(2*k+2, seg.max_v[k])
	}
	if seg.min_v[2*k+2] < seg.min_v[k] {
		seg.update_node_min(2*k+2, seg.min_v[k])
	}
}

func (seg *SegmentTree) update(k int) {
	seg.sum[k] = seg.sum[2*k+1] + seg.sum[2*k+2]

	if seg.max_v[2*k+1] < seg.max_v[2*k+2] {
		seg.max_v[k] = seg.max_v[2*k+2]
		seg.max_c[k] = seg.max_c[2*k+2]
		seg.smax_v[k] = max(seg.max_v[2*k+1], seg.smax_v[2*k+2])
	} else if seg.max_v[2*k+1] > seg.max_v[2*k+2] {
		seg.max_v[k] = seg.max_v[2*k+1]
		seg.max_c[k] = seg.max_c[2*k+1]
		seg.smax_v[k] = max(seg.smax_v[2*k+1], seg.max_v[2*k+2])
	} else {
		seg.max_v[k] = seg.max_v[2*k+1]
		seg.max_c[k] = seg.max_c[2*k+1] + seg.max_c[2*k+2]
		seg.smax_v[k] = max(seg.smax_v[2*k+1], seg.smax_v[2*k+2])
	}

	if seg.min_v[2*k+1] < seg.min_v[2*k+2] {
		seg.min_v[k] = seg.min_v[2*k+1]
		seg.min_c[k] = seg.min_c[2*k+1]
		seg.smin_v[k] = min(seg.smin_v[2*k+1], seg.min_v[2*k+2])
	} else if seg.min_v[2*k+1] > seg.min_v[2*k+2] {
		seg.min_v[k] = seg.min_v[2*k+2]
		seg.min_c[k] = seg.min_c[2*k+2]
		seg.smin_v[k] = min(seg.min_v[2*k+1], seg.smin_v[2*k+2])
	} else {
		seg.min_v[k] = seg.min_v[2*k+1]
		seg.min_c[k] = seg.min_c[2*k+1] + seg.min_c[2*k+2]
		seg.smin_v[k] = min(seg.smin_v[2*k+1], seg.smin_v[2*k+2])
	}
}

func (seg *SegmentTree) update_min(x, a, b, k, l, r int) {
	if b <= l || r <= a || seg.max_v[k] <= x {
		return
	}
	if a <= l && r <= b && seg.smax_v[k] < x {
		seg.update_node_max(k, x)
		return
	}

	seg.push(k)
	seg.update_min(x, a, b, 2*k+1, l, (l+r)/2)
	seg.update_min(x, a, b, 2*k+2, (l+r)/2, r)
	seg.update(k)
}

func (seg *SegmentTree) update_max(x, a, b, k, l, r int) {
	if b <= l || r <= a || x <= seg.min_v[k] {
		return
	}
	if a <= l && r <= b && x < seg.smin_v[k] {
		seg.update_node_min(k, x)
		return
	}

	seg.push(k)
	seg.update_max(x, a, b, 2*k+1, l, (l+r)/2)
	seg.update_max(x, a, b, 2*k+2, (l+r)/2, r)
	seg.update(k)
}

func (seg *SegmentTree) addall(k, x int) {
	seg.max_v[k] += x
	if seg.smax_v[k] != -1<<31 {
		seg.smax_v[k] += x
	}
	seg.min_v[k] += x
	if seg.smin_v[k] != 1<<31 {
		seg.smin_v[k] += x
	}

	seg.sum[k] += seg.len[k] * x
	if seg.lval[k] != 1<<31-1 {
		seg.lval[k] += x
	} else {
		seg.ladd[k] += x
	}
}

func (seg *SegmentTree) updateall(k, x int) {
	seg.max_v[k] = x
	seg.smax_v[k] = -1 << 31
	seg.min_v[k] = x
	seg.smin_v[k] = 1 << 31
	seg.max_c[k] = seg.len[k]
	seg.min_c[k] = seg.len[k]

	seg.sum[k] = x * seg.len[k]
	seg.lval[k] = x
	seg.ladd[k] = 0
}

func (seg *SegmentTree) add_val(a, b, x int) {
	seg._add_val(x, a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) update_val(a, b, x int) {
	seg._update_val(x, a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) _add_val(x, a, b, k, l, r int) {
	if b <= l || r <= a {
		return
	}
	if a <= l && r <= b {
		seg.addall(k, x)
		return
	}

	seg.push(k)
	seg._add_val(x, a, b, 2*k+1, l, (l+r)/2)
	seg._add_val(x, a, b, 2*k+2, (l+r)/2, r)
	seg.update(k)
}

func (seg *SegmentTree) _update_val(x, a, b, k, l, r int) {
	if b <= l || r <= a {
		return
	}
	if a <= l && r <= b {
		seg.updateall(k, x)
		return
	}

	seg.push(k)
	seg._update_val(x, a, b, 2*k+1, l, (l+r)/2)
	seg._update_val(x, a, b, 2*k+2, (l+r)/2, r)
	seg.update(k)
}

func (seg *SegmentTree) query_max(a, b int) int {
	return seg._query_max(a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) query_min(a, b int) int {
	return seg._query_min(a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) query_sum(a, b int) int {
	return seg._query_sum(a, b, 0, 0, seg.n0)
}

func (seg *SegmentTree) _query_max(a, b, k, l, r int) int {
	if b <= l || r <= a {
		return -1 << 31
	}
	if a <= l && r <= b {
		return seg.max_v[k]
	}
	seg.push(k)
	lv := seg._query_max(a, b, 2*k+1, l, (l+r)/2)
	rv := seg._query_max(a, b, 2*k+2, (l+r)/2, r)
	return max(lv, rv)
}

func (seg *SegmentTree) _query_min(a, b, k, l, r int) int {
	if b <= l || r <= a {
		return 1 << 31
	}
	if a <= l && r <= b {
		return seg.min_v[k]
	}
	seg.push(k)
	lv := seg._query_min(a, b, 2*k+1, l, (l+r)/2)
	rv := seg._query_min(a, b, 2*k+2, (l+r)/2, r)
	return min(lv, rv)
}

func (seg *SegmentTree) _query_sum(a, b, k, l, r int) int {
	if b <= l || r <= a {
		return 0
	}
	if a <= l && r <= b {
		return seg.sum[k]
	}
	seg.push(k)
	lv := seg._query_sum(a, b, 2*k+1, l, (l+r)/2)
	rv := seg._query_sum(a, b, 2*k+2, (l+r)/2, r)
	return lv + rv
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	seg := NewSegmentTree(n, a)

	d := make([][]int, 200001)
	for i := 0; i < n; i++ {
		for j := 1; j*j <= a[i]; j++ {
			if a[i]%j == 0 {
				d[j] = append(d[j], i)
				if a[i] != j*j {
					d[a[i]/j] = append(d[a[i]/j], i)
				}
			}
		}
	}

	ans := 0
	for i := 200000; i >= 1; i-- {
		w := d[i]
		if len(w) <= 1 {
			continue
		}

		s := []int{w[0], w[1], w[len(w)-2], w[len(w)-1]}
		F := func(l, r int) { seg.update_max(l, r, r-1) }
		pre := seg.query_sum(0, n)
		F(w[0]+1, w[len(w)-1])
		F(0, w[len(w)-2])
		F(w[1]+1, n)
		ans += (seg.query_sum(0, n) - pre) * i
	}

	fmt.Println(ans)
}
