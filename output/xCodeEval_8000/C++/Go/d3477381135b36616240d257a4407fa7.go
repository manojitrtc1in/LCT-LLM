package main

import (
	"fmt"
)

func main() {
	var b, d int
	fmt.Scan(&b, &d)
	var a, c string
	fmt.Scan(&a, &c)
	an := len(a)
	cn := len(c)

	t := make([]int, cn)
	for i := 0; i < cn; i++ {
		k := 0
		for j := 0; j < an; j++ {
			if a[j] == c[(i+k)%cn] {
				k++
			}
		}
		t[i] = k
	}

	s := 0
	for i := 0; i < b; i++ {
		s += t[s%cn]
	}
	s /= cn * d
	fmt.Println(s)
}
