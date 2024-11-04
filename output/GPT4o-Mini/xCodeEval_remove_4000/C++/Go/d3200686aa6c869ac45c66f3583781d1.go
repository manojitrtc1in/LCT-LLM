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

var A []int64
var pl, pr, vl, vr, k int64
var cnt int64

func dfs(k, n int) {
	A = append(A, int64(n))
	if k == 9 {
		return
	}
	dfs(k+1, n*10+4)
	dfs(k+1, n*10+7)
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
	sort.Slice(A, func(i, j int) bool {
		return A[i] < A[j]
	})
	A = append(A, INF)

	fmt.Scan(&pl, &pr, &vl, &vr, &k)

	for i := int64(0); i < int64(len(A))-k; i++ {
		l1 := A[i-1] + 1
		r1 := A[i]
		l2 := A[i+k-1]
		r2 := A[i+k] - 1

		d1 := I(l1, r1, pl, pr) * I(l2, r2, vl, vr)
		d2 := I(l1, r1, vl, vr) * I(l2, r2, pl, pr)

		cnt += d1 + d2
		if d2 > 0 && k == 1 {
			cnt--
		}
	}

	result := float64(cnt) / float64((pr-pl+1)*(vr-vl+1))
	fmt.Printf("%.12f\n", result)
}