package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

type DSum struct {
	in  *bufio.Reader
	out *bufio.Writer
}

func NewDSum() *DSum {
	return &DSum{
		in:  bufio.NewReader(os.Stdin),
		out: bufio.NewWriter(os.Stdout),
	}
}

func (ds *DSum) readInt() int {
	var x int
	fmt.Fscan(ds.in, &x)
	return x
}

func (ds *DSum) readInts(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = ds.readInt()
	}
	return arr
}

func (ds *DSum) println(args ...interface{}) {
	fmt.Fprintln(ds.out, args...)
}

func (ds *DSum) solve() {
	n := ds.readInt()
	k := ds.readInt()
	sums := make([]int64, n)
	arrs := make([][]int64, n)

	for i := 0; i < n; i++ {
		t := ds.readInt()
		arrs[i] = make([]int64, t)
		for j := 0; j < t; j++ {
			arrs[i][j] = int64(ds.readInt())
		}
		if t > k {
			arrs[i] = arrs[i][:k]
		}
		sums[i] = sum(arrs[i])
	}

	dps := make([][]int64, 13)
	for i := range dps {
		dps[i] = make([]int64, k+1)
	}

	ds.println(ds.rec(0, n, 0, k, sums, arrs, dps))
}

func (ds *DSum) rec(l, r, dpi, k int, sums []int64, arrs [][]int64, dps [][]int64) int64 {
	var ans int64
	carr := arrs[l]
	dp := dps[dpi]

	if l+1 == r {
		ans = max(ans, dp[k])
		sum := int64(0)
		for i := 0; i < min(k, len(carr)); i++ {
			sum += carr[i]
			ans = max(ans, dp[k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		ds.doCopy(dpi, dps)
		for i := l; i < m; i++ {
			ds.addToKnap(i, dpi, k, sums, arrs, dps)
		}
		ans = max(ans, ds.rec(m, r, dpi+1, k, sums, arrs, dps))
		ds.doCopy(dpi, dps)
		for i := m; i < r; i++ {
			ds.addToKnap(i, dpi, k, sums, arrs, dps)
		}
		ans = max(ans, ds.rec(l, m, dpi+1, k, sums, arrs, dps))
	}
	return ans
}

func (ds *DSum) doCopy(dpi int, dps [][]int64) {
	copy(dps[dpi+1], dps[dpi])
}

func (ds *DSum) addToKnap(i, dpi, k int, sums []int64, arrs [][]int64, dps [][]int64) {
	v := sums[i]
	k1 := len(arrs[i])
	for j := k; j >= k1; j-- {
		dps[dpi][j] = max(dps[dpi][j], dps[dpi][j-k1]+v)
	}
}

func sum(arr []int64) int64 {
	var total int64
	for _, v := range arr {
		total += v
	}
	return total
}

func max(a, b int64) int64 {
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
	ds := NewDSum()
	defer ds.out.Flush()
	ds.solve()
}
