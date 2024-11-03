package main

import (
	"fmt"
)

func main() {
	var q int
	fmt.Scan(&q)
	for i := 0; i < q; i++ {
		var n int
		fmt.Scan(&n)
		M := n/4 + 1
		m := mint(M)
		if n%4 <= 1 {
			fmt.Println((m * m).val())
		} else {
			fmt.Println((m * (m + 1)).val())
		}
	}
}
