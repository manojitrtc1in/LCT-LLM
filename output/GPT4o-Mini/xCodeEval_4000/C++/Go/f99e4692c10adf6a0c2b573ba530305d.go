package main

import (
	"fmt"
	"math"
)

const N = int(1e6) + 9

var a [N]int
var s [N]int
var top int

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}

	var x int
	fmt.Scan(&x)
	a[x-1] *= -1

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
			fmt.Print(a[i], " ")
		}
	}
}
