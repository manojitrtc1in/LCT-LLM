package main

import (
	"fmt"
	"math"
	"sort"
)

type Tuple struct {
	first, second, third int
}

func refill(k int, left, right []Tuple) int {
	comp := func(i, j int) bool {
		return right[i].second-left[i].first < right[j].second-left[j].first
	}

	idx := make([]int, len(left))
	for i := range idx {
		idx[i] = i
	}

	sort.Slice(idx, func(i, j int) bool {
		return comp(idx[i], idx[j])
	})

	val := 0
	for len(idx) > 0 && k > 0 {
		i := idx[0]
		idx = idx[1:]

		if left[i].first < right[i].second {
			w := min(k, left[i].third)
			k -= w
			val += w * (right[i].second - left[i].first)
		}
	}
	return val
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func a176() int {
	var n, m, k int
	fmt.Scan(&n, &m, &k)

	a := make([][]Tuple, n)
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		for j := 0; j < m; j++ {
			var t Tuple
			fmt.Scan(&t.first, &t.second, &t.third)
			a[i] = append(a[i], t)
		}
	}

	val := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if i != j {
				val = max(val, refill(k, a[i], a[j]))
			}
		}
	}
	return val
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	fmt.Println(a176())
}
