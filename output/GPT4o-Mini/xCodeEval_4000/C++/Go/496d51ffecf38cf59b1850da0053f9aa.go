package main

import (
	"fmt"
	"math"
	"sort"
)

const N = 100

var powcnt [N]int
var ans int64

func preprocess(num int64) {
	for i := 30; i >= 0; i-- {
		if num >= (1 << i) {
			num -= (1 << i)
			powcnt[i]++
		}
	}
}

func solve(curp int64) {
	for i := curp; i <= 30; i++ {
		if powcnt[i] > 0 {
			powcnt[i]--
			ans++
			for j := curp; j < i; j++ {
				powcnt[j]++
			}
			break
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	var v []int64
	for i := 0; i < n; i++ {
		var x int64
		fmt.Scan(&x)
		preprocess(x)
	}
	for i := 0; i < m; i++ {
		var x int64
		fmt.Scan(&x)
		v = append(v, x)
	}
	sort.Slice(v, func(i, j int) bool {
		return v[i] < v[j]
	})
	for _, value := range v {
		solve(value)
	}
	fmt.Println(ans)
}
