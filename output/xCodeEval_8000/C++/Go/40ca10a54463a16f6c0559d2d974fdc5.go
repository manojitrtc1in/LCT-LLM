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

func getr(l, r int) int {
	isp := make([]bool, r-l+1)
	for i := 0; prm[i]*prm[i] <= r; i++ {
		j := l/prm[i]*prm[i]
		if j < l {
			j += prm[i]
		}
		if j <= prm[i]*prm[i] {
			j = prm[i] * prm[i]
		}
		for ; j <= r; j += prm[i] {
			isp[j-l] = false
		}
	}
	ret := 0
	for i := l; i <= r; i++ {
		if isp[i-l] && i%4 == 1 {
			ret++
		}
	}
	return ret
}

func get(n int) int {
	if n == 1 {
		return 0
	}
	if n%100000 == 0 {
		return f[n/100000] + boolToInt(n >= 2)
	} else {
		return f[n/100000] + boolToInt(n > 100000) + getr(n/100000*100000+1, n)
	}
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

