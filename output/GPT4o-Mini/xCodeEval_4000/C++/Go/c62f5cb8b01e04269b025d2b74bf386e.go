package main

import (
	"fmt"
	"strings"
)

func main() {
	var b, d int
	fmt.Scan(&b, &d)
	a := make([]rune, 128)
	c := make([]rune, 128)
	fmt.Scanf("%s %s", &a, &c)

	s := 0
	n := len(c)
	t := make([]int, 128)

	for i := 0; i < n; i++ {
		k := &t[i]
		for j := 0; j < len(a); j++ {
			if a[j] == c[(i+*k)%n] {
				*k++
			}
		}
	}

	for i := 0; i < b; i++ {
		s += t[s%n]
	}

	fmt.Println(s / n / d)
}
