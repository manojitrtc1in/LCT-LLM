package main

import (
	"fmt"
	"os"
	"strings"
)

func main() {
	var b, d int
	var a, c string
	fmt.Scan(&b, &d)
	fmt.Scan(&a, &c)

	an := len(a)
	cn := len(c)
	t := make([]int, cn)

	for i := 0; i < cn; i++ {
		k := &t[i]
		for j := 0; j < an; j++ {
			if a[j] == c[(i+*k)%cn] {
				*k++
			}
		}
	}

	s := 0
	for i := 0; i < b; i++ {
		s += t[s%cn]
	}
	s /= cn * d

	fmt.Println(s)
}
