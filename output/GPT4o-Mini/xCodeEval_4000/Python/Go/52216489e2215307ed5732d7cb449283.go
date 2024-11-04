package main

import (
	"bytes"
	"fmt"
	"os"
	"sort"
)

const mod = 1e9 + 7

type SegmentTree struct {
	data     []int
	defaultV int
	funcV    func(int, int) int
	len      int
	size     int
}

func NewSegmentTree(data []int, defaultV int, funcV func(int, int) int) *SegmentTree {
	lenData := len(data)
	size := 1 << (lenData - 1).bitLen()
	st := &SegmentTree{
		data:     make([]int, 2*size),
		defaultV: defaultV,
		funcV:    funcV,
		len:      lenData,
		size:     size,
	}
	copy(st.data[size:size+lenData], data)
	for i := size - 1; i > 0; i-- {
		st.data[i] = funcV(st.data[i*2], st.data[i*2+1])
	}
	return st
}

func (st *SegmentTree) Set(idx, value int) {
	idx += st.size
	st.data[idx] = value
	for idx >>= 1; idx > 0; idx >>= 1 {
		st.data[idx] = st.funcV(st.data[idx*2], st.data[idx*2+1])
	}
}

func (st *SegmentTree) Query(start, stop int) int {
	if start == stop {
		return st.data[start+st.size]
	}
	stop++
	start += st.size
	stop += st.size

	res := st.defaultV
	for start < stop {
		if start&1 != 0 {
			res = st.funcV(res, st.data[start])
			start++
		}
		if stop&1 != 0 {
			stop--
			res = st.funcV(res, st.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	cnt := make([]int, m+1)

	for i := 0; i < n; i++ {
		var a, b int
		fmt.Scan(&a, &b)
		cnt[a-1]++
		cnt[b]--
	}

	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}

	l := make([]int, m)
	l1 := make([]int, m)
	cntPairs := make([][2]int, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = [2]int{cnt[i], i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		return cntPairs[i][0] < cntPairs[j][0]
	})

	ind := make(map[int]int)
	for i := range cntPairs {
		ind[cntPairs[i][1]] = i
	}

	s := NewSegmentTree(l, 0, func(a, b int) int { return a })
	s1 := NewSegmentTree(l1, 0, func(a, b int) int { return a })
	cou := make([]int, m)
	cur := 0
	cur1 := 0
	fi := make([]int, m)

	for i := 0; i < m; i++ {
		mw := s.Query(0, ind[i]) + 1
		l[ind[i]] = mw
		fi[i] = mw
		cur1 = max(cur1, mw)
		s.Set(ind[i], mw)
	}

	cntPairs = make([][2]int, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = [2]int{cnt[i], -cnt[i]}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		return cntPairs[i][0] < cntPairs[j][0]
	})

	for i := range cntPairs {
		ind[-cntPairs[i][1]] = i
	}

	for i := m - 1; i >= 0; i-- {
		mw := s1.Query(0, ind[i]) + 1
		fi[i] += mw
		l1[ind[i]] = mw
		s1.Set(ind[i], mw)
	}

	maxFi := 0
	for _, v := range fi {
		if v > maxFi {
			maxFi = v
		}
	}
	fmt.Println(maxFi - 1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
