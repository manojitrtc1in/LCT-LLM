package main

import (
	"fmt"
	"math"
	"sort"
)

type DSum struct {
	n   int
	k   int
	arrs [][]int
	sums []int64
	dps  [][]int64
}

func (ds *DSum) readInt() int {
	var x int
	fmt.Scan(&x)
	return x
}

func (ds *DSum) readIntSlice(n int) []int {
	slice := make([]int, n)
	for i := 0; i < n; i++ {
		slice[i] = ds.readInt()
	}
	return slice
}

func (ds *DSum) doCopy(dpi int) {
	copy(ds.dps[dpi+1], ds.dps[dpi])
}

func (ds *DSum) addToKnap(i, dpi int) {
	v := ds.sums[i]
	k1 := len(ds.arrs[i])
	for j := ds.k; j >= k1; j-- {
		ds.dps[dpi][j] = max(ds.dps[dpi][j], ds.dps[dpi][j-k1]+v)
	}
}

func (ds *DSum) rec(l, r, dpi int) int64 {
	var ans int64
	carr := ds.arrs[l]
	dp := ds.dps[dpi]

	if l+1 == r {
		ans = max(ans, dp[ds.k])
		sum := int64(0)
		for i := 0; i < int(math.Min(float64(ds.k), float64(len(carr)))); i++ {
			sum += int64(carr[i])
			ans = max(ans, dp[ds.k-i-1]+sum)
		}
	} else {
		m := (l + r) / 2
		ds.doCopy(dpi)
		for i := l; i < m; i++ {
			ds.addToKnap(i, dpi+1)
		}
		ans = max(ans, ds.rec(m, r, dpi+1))
		ds.doCopy(dpi)
		for i := m; i < r; i++ {
			ds.addToKnap(i, dpi+1)
		}
		ans = max(ans, ds.rec(l, m, dpi+1))
	}
	return ans
}

func (ds *DSum) solve() {
	ds.n = ds.readInt()
	ds.k = ds.readInt()
	ds.sums = make([]int64, ds.n)
	ds.arrs = make([][]int, ds.n)

	for i := 0; i < ds.n; i++ {
		t := ds.readInt()
		ds.arrs[i] = ds.readIntSlice(t)
		if t > ds.k {
			ds.arrs[i] = ds.arrs[i][:ds.k]
		}
		ds.sums[i] = sum(ds.arrs[i])
	}

	ds.dps = make([][]int64, 13)
	for i := range ds.dps {
		ds.dps[i] = make([]int64, ds.k+1)
	}

	fmt.Println(ds.rec(0, ds.n, 0))
}

func sum(arr []int) int64 {
	var total int64
	for _, v := range arr {
		total += int64(v)
	}
	return total
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var solver DSum
	solver.solve()
}
