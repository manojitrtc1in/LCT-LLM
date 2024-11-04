package main

import (
	"fmt"
	"sort"
)

type VI []int

func (a VI) Len() int           { return len(a) }
func (a VI) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a VI) Less(i, j int) bool { return a[i] < a[j] }

func dfs(k, n int, A *VI) {
	*A = append(*A, n)
	if k == 9 {
		return
	} else {
		dfs(k+1, n*10+4, A)
		dfs(k+1, n*10+7, A)
	}
}

func I(l, r, l_, r_ int) int {
	if l > l_ {
		l = l_
	}
	if r < r_ {
		r = r_
	}
	return max(0, r-l+1)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var pl, pr, vl, vr, k int64
	fmt.Scan(&pl, &pr, &vl, &vr, &k)

	A := make(VI, 0)
	dfs(0, 0, &A)
	sort.Sort(A)
	A = append(A, int(1e9))

	cnt := int64(0)
	for i := 0; i < len(A)-int(k); i++ {
		l1, r1 := A[i-1]+1, A[i]
		l2, r2 := A[i+int(k)-1], A[i+int(k)]-1
		d1 := int64(I(l1, r1, int(pl), int(pr))) * int64(I(l2, r2, int(vl), int(vr)))
		d2 := int64(I(l1, r1, int(vl), int(vr))) * int64(I(l2, r2, int(pl), int(pr)))
		cnt += d1 + d2
		if d1 != 0 && d2 != 0 && k == 1 {
			cnt--
		}
	}

	fmt.Printf("%.12f\n", float64(cnt)/float64((pr-pl+1)*(vr-vl+1)))
}
