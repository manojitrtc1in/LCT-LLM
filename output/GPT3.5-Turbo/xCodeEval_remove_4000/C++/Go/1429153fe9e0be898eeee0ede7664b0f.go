package main

import (
	"fmt"
)

func solve() {
	var n int
	fmt.Scan(&n)
	a := make([][]int, n)
	for i := 0; i < n; i++ {
		a[i] = make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&a[i][j])
		}
	}
	idx := make([][2]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if a[i][j] == a[j][i] || a[i][j] == a[n-1-j][n-1-i] || a[i][j] == a[n/2][n/2] || a[j][i] == a[n/2][n/2] {
				idx = append(idx, [2]int{i, j})
			}
		}
	}
	sum := 0
	for _, pair := range idx {
		sum += a[pair[0]][pair[1]]
	}
	fmt.Println(sum)
}

func main() {
	solve()
}
