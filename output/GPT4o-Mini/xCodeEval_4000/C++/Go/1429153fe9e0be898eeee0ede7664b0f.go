package main

import (
	"fmt"
)

func solve() {
	var n int
	fmt.Scan(&n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var idx []int
	for i := 0; i < n; i++ {
		if i == 0 || i == n-1 || i == n/2 {
			idx = append(idx, i)
		}
	}

	sum := 0
	for _, i := range idx {
		sum += a[i]
	}

	fmt.Println(sum)
}

func main() {
	solve()
}
