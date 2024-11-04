package main

import (
	"fmt"
	"sort"
)

func main() {
	A := make([]int, 0)
	pl, pr, vl, vr, k := 0, 0, 0, 0, 0
	cnt := int64(0)

	dfs := func(k, n int) {
		A = append(A, n)
		if k == 9 {
			return
		} else {
			dfs(k+1, n*10+4)
			dfs(k+1, n*10+7)
		}
	}

	dfs(0, 0)
	sort.Ints(A)
	A = append(A, int(1e9))

	fmt.Scan(&pl, &pr, &vl, &vr, &k)

	for i := 0; i < len(A)-k; i++ {
		l1, r1, l2, r2 := A[i-1]+1, A[i], A[i+k-1], A[i+k]-1
		d1 := I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
		d2 := I(l1, r1, vl, vr) * I(l2, r2, pl, pr)
		cnt += d1 + d2
		if d2 != 0 && d2 != 0 && k == 1 {
			cnt--
		}
	}

	fmt.Printf("%.12f\n", float64(cnt)/float64((pr-pl+1)*(vr-vl+1)))
}

func I(l, r, l_, r_ int) int64 {
	if l > l_ {
		l = l_
	}
	if r < r_ {
		r = r_
	}
	return int64(max(0, r-l+1))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
