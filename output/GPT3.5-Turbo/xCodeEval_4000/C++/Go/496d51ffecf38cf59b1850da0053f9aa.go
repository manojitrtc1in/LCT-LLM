package main

import (
	"fmt"
	"sort"
)

const N = 101

var powcnt [N]int
var ans int

func preprocess(num int) {
	for i := 30; i >= 0; i-- {
		if num >= (1 << i) {
			num -= (1 << i)
			powcnt[i]++
		}
	}
}

func solve(curp int) {
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
	v := make([]int, n)
	for i := 0; i < n; i++ {
		var x int
		fmt.Scan(&x)
		preprocess(x)
	}
	for i := 0; i < m; i++ {
		var x int
		fmt.Scan(&x)
		v[i] = x
	}
	sort.Ints(v)
	for i := 0; i < len(v); i++ {
		solve(v[i])
	}
	fmt.Println(ans)
}
