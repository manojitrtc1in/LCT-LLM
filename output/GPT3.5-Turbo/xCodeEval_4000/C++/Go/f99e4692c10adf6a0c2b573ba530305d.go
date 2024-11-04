package main

import (
	"fmt"
)

func main() {
	const N = 1000009
	var a [N]int
	var n, top int
	var s [N]int

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var m int
	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		var x int
		fmt.Scan(&x)
		a[x-1] = -a[x-1]
	}

	for i := n - 1; i >= 0; i-- {
		if a[i] > 0 {
			if top > 0 && s[top] == a[i] {
				top--
			} else {
				top++
				s[top] = a[i]
				a[i] = -a[i]
			}
		} else {
			top++
			s[top] = -a[i]
		}
	}

	if top > 0 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
		for i := 0; i < n; i++ {
			fmt.Printf("%d ", a[i])
		}
		fmt.Println()
	}
}
