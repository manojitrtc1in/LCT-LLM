package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type SegmentTree struct {
	data    []int
	defaultVal int
	merge   func(a, b int) int
}

func NewSegmentTree(arr []int, defaultVal int, merge func(a, b int) int) *SegmentTree {
	tree := &SegmentTree{
		data:    make([]int, 4*len(arr)),
		defaultVal: defaultVal,
		merge:   merge,
	}
	tree.build(arr, 0, 0, len(arr)-1)
	return tree
}

func (st *SegmentTree) build(arr []int, v, tl, tr int) {
	if tl == tr {
		st.data[v] = arr[tl]
	} else {
		tm := (tl + tr) / 2
		st.build(arr, 2*v+1, tl, tm)
		st.build(arr, 2*v+2, tm+1, tr)
		st.data[v] = st.merge(st.data[2*v+1], st.data[2*v+2])
	}
}

func (st *SegmentTree) query(v, tl, tr, l, r int) int {
	if l > r {
		return st.defaultVal
	}
	if tl == l && tr == r {
		return st.data[v]
	}
	tm := (tl + tr) / 2
	left := st.query(2*v+1, tl, tm, l, min(r, tm))
	right := st.query(2*v+2, tm+1, tr, max(l, tm+1), r)
	return st.merge(left, right)
}

func (st *SegmentTree) Query(l, r int) int {
	return st.query(0, 0, len(st.data)/4-1, l, r)
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
	ind := make(map[int]int)
	cntPairs := make([][2]int, m)
	for i := 0; i < m; i++ {
		cntPairs[i] = [2]int{cnt[i], i}
	}
	sort.Slice(cntPairs, func(i, j int) bool {
		return cntPairs[i][0] < cntPairs[j][0]
	})
	for i := 0; i < len(cntPairs); i++ {
		ind[cntPairs[i][1]] = i
	}
	s := NewSegmentTree(l, 0, max)
	s1 := NewSegmentTree(l1, 0, max)
	fi := make([]int, m)
	for i := 0; i < m; i++ {
		mw := s.Query(0, ind[i]) + 1
		l[ind[i]] = mw
		fi[i] = mw
		s.Update(ind[i], mw)
	}
	for i := m - 1; i >= 0; i-- {
		mw := s1.Query(0, ind[i]) + 1
		fi[i] += mw
		l1[ind[i]] = mw
		s1.Update(ind[i], mw)
	}
	ans := 0
	for _, v := range fi {
		ans = max(ans, v)
	}
	fmt.Println(ans - 1)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
