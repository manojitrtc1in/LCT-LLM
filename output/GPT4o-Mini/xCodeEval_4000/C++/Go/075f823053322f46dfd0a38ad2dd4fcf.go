package main

import (
	"fmt"
	"math/rand"
	"time"
)

func Random() {
	rand.Seed(time.Now().UnixNano())
}

func main() {
	Random()

	var b, d int
	var a, c [128]byte
	var t [128]int

	fmt.Scanf("%d%d", &b, &d)
	fmt.Scanf("%s%s", &a, &c)

	s := 0
	n := 0
	for c[n] != 0 {
		n++
	}

	for i := 0; i < n; i++ {
		k := 0
		for j := 0; a[j] != 0; j++ {
			if a[j] == c[(i+k)%n] {
				k++
			}
		}
		t[i] = k
	}

	for i := 0; i < b; i++ {
		s += t[s%n]
	}

	fmt.Println(s / n / d)
}
