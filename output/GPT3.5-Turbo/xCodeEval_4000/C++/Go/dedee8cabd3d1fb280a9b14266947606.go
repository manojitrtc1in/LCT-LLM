package main

import (
	"fmt"
	"sort"
)

const (
	MOD = 1000000007
	INF = 0x7fffffff
	PI  = 3.14159265358979323846264338327950288419716939937510582097494459
	EPS = 1e-6
	OO  = 1e15
)

type PII struct {
	first  int
	second int
}

type VII []PII

func (a VII) Len() int           { return len(a) }
func (a VII) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a VII) Less(i, j int) bool { return a[i].first < a[j].first }

func main() {
	A := make([]int, 0)
	B := make([]int, 0)
	pl, pr, vl, vr, k := 0, 0, 0, 0, 0
	cnt := int64(0)

	dfs := func(k int, n int) {
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
	A = append(A, INF)

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

	fmt.Printf("%.12lf\n", float64(cnt)/float64((pr-pl+1)*(vr-vl+1)))
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
