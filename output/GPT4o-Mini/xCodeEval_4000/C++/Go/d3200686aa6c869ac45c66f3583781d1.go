package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 1000000007
const INF = 0x7fffffff
const EPS = 1e-6
const OO = 1e15

var A []int
var cnt int64

func dfs(k int, n int) {
	A = append(A, n)
	if k == 9 {
		return
	} else {
		dfs(k+1, n*10+4)
		dfs(k+1, n*10+7)
	}
}

func I(l, r, l_, r_ int64) int64 {
	if l < l_ {
		l = l_
	}
	if r > r_ {
		r = r_
	}
	if r < l {
		return 0
	}
	return r - l + 1
}

func main() {
	dfs(0, 0)
	sort.Ints(A)
	A = append(A, INF)

	var pl, pr, vl, vr, k int64
	fmt.Scan(&pl, &pr, &vl, &vr, &k)

	for i := 0; i < len(A)-int(k); i++ {
		l1 := A[i-1] + 1
		r1 := A[i]
		l2 := A[i+int(k)-1]
		r2 := A[i+int(k)] - 1

		d1 := I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
		d2 := I(l1, r1, vl, vr) * I(l2, r2, pl, pr)

		cnt += d1 + d2
		if d2 > 0 && k == 1 {
			cnt--
		}
	}

	fmt.Printf("%.12f\n", float64(cnt)/float64((pr-pl+1)*(vr-vl+1)))
}
