package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type SegmentTree struct {
	data     []int
	size     int
	defaults int
	merge    func(a, b int) int
}

func NewSegmentTree(arr []int, defaults int, merge func(a, b int) int) *SegmentTree {
	n := len(arr)
	size := 1 << (32 - bits.LeadingZeros32(uint32(n-1)))
	data := make([]int, 2*size)
	copy(data[size:], arr)
	for i := size - 1; i > 0; i-- {
		data[i] = merge(data[i*2], data[i*2+1])
	}
	return &SegmentTree{
		data:     data,
		size:     size,
		defaults: defaults,
		merge:    merge,
	}
}

func (st *SegmentTree) Update(idx, value int) {
	idx += st.size
	st.data[idx] = value
	idx >>= 1
	for idx > 0 {
		st.data[idx] = st.merge(st.data[idx*2], st.data[idx*2+1])
		idx >>= 1
	}
}

func (st *SegmentTree) Query(start, stop int) int {
	if start == stop {
		return st.data[start+st.size]
	}
	stop++
	start += st.size
	stop += st.size

	res := st.defaults
	for start < stop {
		if start&1 == 1 {
			res = st.merge(res, st.data[start])
			start++
		}
		if stop&1 == 1 {
			stop--
			res = st.merge(res, st.data[stop])
		}
		start >>= 1
		stop >>= 1
	}
	return res
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n, m := nextInt(scanner), nextInt(scanner)
	cnt := make([]int, m+1)
	for i := 0; i < n; i++ {
		a, b := nextInt(scanner), nextInt(scanner)
		cnt[a-1]++
		cnt[b]--
	}
	for i := 1; i <= m; i++ {
		cnt[i] += cnt[i-1]
	}
	l := make([]int, m)
	l1 := make([]int, m)
	cntPairs := make([]pair, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = pair{cnt[i], i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		if cntPairs[i].first == cntPairs[j].first {
			return cntPairs[i].second < cntPairs[j].second
		}
		return cntPairs[i].first < cntPairs[j].first
	})
	ind := make(map[int]int)
	for i, p := range cntPairs {
		ind[p.second] = i
	}
	s := NewSegmentTree(l, 0, func(a, b int) int {
		return max(a, b)
	})
	s1 := NewSegmentTree(l1, 0, func(a, b int) int {
		return max(a, b)
	})
	cur := 0
	cur1 := 0
	fi := make([]int, m)
	for i := 0; i < m; i++ {
		mw := s.Query(0, ind[i]) + 1
		l[ind[i]] = mw
		fi[i] = mw
		cur1 = max(cur1, mw)
		s.Update(ind[i], mw)
	}
	cntPairs = make([]pair, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = pair{cnt[i], -i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		if cntPairs[i].first == cntPairs[j].first {
			return cntPairs[i].second < cntPairs[j].second
		}
		return cntPairs[i].first < cntPairs[j].first
	})
	cntPairs = make([]pair, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = pair{cnt[i], -i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		if cntPairs[i].first == cntPairs[j].first {
			return cntPairs[i].second < cntPairs[j].second
		}
		return cntPairs[i].first < cntPairs[j].first
	})
	for i, p := range cntPairs {
		ind[p.second] = i
	}
	for i := m - 1; i >= 0; i-- {
		mw := s1.Query(0, ind[i]) + 1
		fi[i] += mw
		l1[ind[i]] = mw
		s1.Update(ind[i], mw)
	}
	fmt.Println(max(fi) - 1)
}

type pair struct {
	first, second int
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
