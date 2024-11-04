package main

import (
	"fmt"
	"math"
	"sort"
)

func gcd(a, b int64) int64 {
	c := b % a
	for c > 0 {
		b = a
		a = c
		c = b % a
	}
	return a
}

func main() {
	var n, k int64
	fmt.Scan(&n, &k)
	bamboo := make([]int64, n)
	for i := 0; i < int(n); i++ {
		fmt.Scan(&bamboo[i])
	}
	sort.Slice(bamboo, func(i, j int) bool {
		return bamboo[i] < bamboo[j]
	})
	bambooSum := make([]int64, n)
	bambooSum[0] = bamboo[0]
	maxval := int64(0)
	for i := 1; i < int(n); i++ {
		bambooSum[i] = bamboo[i] + bambooSum[i-1]
		m := int64(i)*bamboo[i] - bambooSum[i-1]
		if m > k && maxval == 0 {
			maxval = bamboo[i]
		}
	}
	if maxval == 0 {
		remaining := k + bambooSum[n-1] - (n * bamboo[n-1])
		fmt.Println((remaining/n) + bamboo[n-1])
		return
	}
	candidatePoints := make(map[int64]bool)
	for i := 0; i < int(n); i++ {
		bambooSum[i] += k
		lim := int64(1 + math.Sqrt(float64(bamboo[i]+1)))
		for j := int64(1); j < lim; j++ {
			r1 := bamboo[i] / j
			r2 := j
			if r1 < maxval {
				if r1*j == bamboo[i] {
					candidatePoints[r1] = true
				} else {
					candidatePoints[r1+1] = true
				}
			}
		}
	}
	lim := int64(math.Sqrt(float64(bamboo[n-1])))
	if lim > maxval {
		lim = maxval
	}
	for i := int64(1); i < lim; i++ {
		candidatePoints[i] = true
	}
	var cp int64
	for cp = range candidatePoints {
		total := int64(0)
		d1 := int64(0)
		flag := true
		for i := 0; i < int(n); i++ {
			d1 = (bamboo[i] + cp - 1) / cp
			total += (d1 * cp)
			if total > bambooSum[i] {
				flag = false
				break
			}
		}
		if flag {
			dv := int64(0)
			for i := 0; i < int(n); i++ {
				dv += (bamboo[i] + cp - 1) / cp
			}
			fmt.Println(cp + (bambooSum[n-1]-total)/dv)
			return
		}
	}
	fmt.Println(1)
}
