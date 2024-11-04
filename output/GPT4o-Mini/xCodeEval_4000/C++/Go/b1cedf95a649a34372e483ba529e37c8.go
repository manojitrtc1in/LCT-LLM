package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	e5 = 1e5
	e9 = 1e9
	MD = 1e9 + 7
)

func sum(a []int) int64 {
	var s int64 = 0
	for _, e := range a {
		s += int64(e)
	}
	return s
}

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	K := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&K[i])
	}

	vv := make([][]int, 4*int(e5)+1)
	for _ := 0; _ < M; _++ {
		var D, T int
		fmt.Scan(&D, &T)
		vv[D-1] = append(vv[D-1], T-1)
	}

	ok := 2 * sum(K)
	ng := sum(K) - 1

	for ok-ng > 1 {
		k := (ok + ng) >> 1
		v := make([]int, k)
		b := make([]bool, N)

		for i := k - 1; i >= 0; i-- {
			for _, j := range vv[i] {
				if !b[j] {
					b[j] = true
					v[i] += K[j]
				}
			}
		}

		t := 0
		s := sum(K)

		for i := 0; i < k; i++ {
			t++
			m := int(math.Min(float64(t), float64(v[i])))
			t -= m
			s -= m
		}

		if t >= s*2 {
			ok = k
		} else {
			ng = k
		}
	}

	fmt.Println(ok)
}
