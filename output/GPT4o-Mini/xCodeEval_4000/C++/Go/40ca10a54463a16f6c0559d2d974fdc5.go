package main

import (
	"fmt"
	"math"
)

const N = 18000
const M = 18000

var is [N]bool
var prm [M]int
var cntp int

func getprm(n int) int {
	var k int
	e := int(math.Sqrt(float64(n)) + 1)
	for i := range is {
		is[i] = true
	}
	prm[k] = 2
	k++
	is[0] = false
	is[1] = false
	for i := 4; i < n; i += 2 {
		is[i] = false
	}
	for i := 3; i < e; i += 2 {
		if is[i] {
			prm[k] = i
			k++
			for s, j := i*2, i*i; j < n; j += s {
				is[j] = false
			}
		}
	}
	for i := e; i < n; i += 2 {
		if is[i] {
			prm[k] = i
			k++
		}
	}
	return k
}

