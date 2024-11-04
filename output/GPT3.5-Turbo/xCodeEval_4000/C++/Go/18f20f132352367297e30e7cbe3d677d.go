package main

import (
	"fmt"
)

func main() {
	var b, d int
	fmt.Scan(&b, &d)
	var a, c string
	fmt.Scan(&a, &c)
	s := 0
	n := len(c)
	t := make([]int, len(c))
	for i := 0; i < len(c); i++ {
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
