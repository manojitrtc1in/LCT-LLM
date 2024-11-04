package main

import (
	"fmt"
	"math"
)

var pr [32000]int
var epr int
var U1 [32000]bool
var U [105000]bool

var nakop = [3333]int{}

func getAns(x, y int) int {
	ret := 0
	if x <= 2 && y >= 2 {
		ret++
	}
	for i := range U {
		U[i] = false
	}
	for i := x; i <= y; i++ {
		prime := false
		if !U[i-x] {
			prime = true
			for u := 0; pr[u]*pr[u] <= i; u++ {
				if i%pr[u] == 0 {
					prime = false
					for j := i + pr[u]; j < 104000; j += pr[u] {
						U[j-x] = true
					}
					break
				}
			}
		}
		if prime && i > 1 && (i%4) == 1 {
			ret++
		}
	}
	return ret
}

func main() {
	for i := 1; i < 3333; i++ {
		nakop[i]++
	}

	for i := 2; i < 32000; i++ {
		if !U1[i] {
			pr[epr] = i
			epr++
			for u := i * i; u < 32000; u += i {
				U1[u] = true
			}
		}
	}

	var a, b int
	fmt.Scan(&a, &b)

	y := nakop[b/100000]
	y += getAns(b/100000*100000+1, b)

	a--
	x := nakop[a/100000]
	x += getAns(a/100000*100000+1, a)

	fmt.Println(y - x)
}
