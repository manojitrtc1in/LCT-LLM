package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scan(&n)
	V := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&V[i])
	}
	sort.Ints(V)
	fmt.Println(V[n/2])
}
