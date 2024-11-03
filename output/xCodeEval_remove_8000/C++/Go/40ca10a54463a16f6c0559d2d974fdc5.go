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

func id0(n int) int {
	k := 0
	s := int(math.Sqrt(float64(n)) + 1)
	for i := 0; i < n; i++ {
		is[i] = true
	}
	prm[k] = 2
	is[0] = false
	is[1] = false
	k++
	for i := 4; i < n; i += 2 {
		is[i] = false
	}
	for i := 3; i < s; i += 2 {
		if is[i] {
			prm[k] = i
			k++
			for j, s := i*2, i*i; j < n; j += s {
				is[j] = false
			}
		}
	}
	for i := s; i < n; i += 2 {
		if is[i] {
			prm[k] = i
			k++
		}
	}
	return k
}

