package main

import (
	"fmt"
	"strings"
)

const N = int(1e2) + 9

func main() {
	var b, d int
	var a, c string
	var t [N]int

	fmt.Scan(&b, &d)
	fmt.Scan(&a, &c)

	an := len(a)
	cn := len(c)

	for i := 0; i < cn; i++ {
		k := &t[i]
		for j := 0; j < an; j++ {
			if a[j] == c[(*k+i)%cn] {
				(*k)++
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
