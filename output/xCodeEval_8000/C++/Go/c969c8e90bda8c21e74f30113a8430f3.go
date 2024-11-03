package main

import (
	"fmt"
	"math"
	"sort"
)

func calc(l, r int) int {
	cand := make([]int64, 0)
	for a := int64(1); a*a <= int64(r); a++ {
		cand = append(cand, a*a)
	}
	n := len(cand)

	cand2 := make([]int, 0)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			if cand[i]+cand[j] < int64(l) {
				continue
			}
			if cand[i]+cand[j] > int64(r) {
				break
			}
			cand2 = append(cand2, int(cand[i]+cand[j]))
		}
	}
	sort.Ints(cand2)
	m := len(cand2)
	res := 0
	for i := 0; i < m; i++ {
		v := cand2[i]
		if v == 1 {
			continue
		}
		ok := true
		for j := int64(2); j*j <= int64(v); j++ {
			if v%j == 0 {
				ok = false
				break
			}
		}
		if ok {
			res++
		}
	}

	return res
}

func calc2(v int) int {
	res := 0
	r := v / 100000
	for i := 0; i < r; i++ {
		res += pre[i]
	}
	res += calc(r*100000, v)
	return res
}

func main() {
	var l, r int
	fmt.Scan(&l, &r)

	res := calc2(r) - calc2(l-1)

	fmt.Println(res)
}
