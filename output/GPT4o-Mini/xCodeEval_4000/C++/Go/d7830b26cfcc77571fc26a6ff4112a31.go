package main

import (
	"fmt"
	"math"
	"sort"
)

const (
	PI   = 3.1415926535897932384626433832795
	mdlo = 1000000007
	maxBits = 40
)

var (
	pwr2       [100]int64
	parent     [1010]int64
	bambooSum  [111]int64
)

func getParent(node int64) int64 {
	if parent[node] != node {
		parent[node] = getParent(parent[node])
	}
	return parent[node]
}

func unionNode(node1, node2 int64) {
	if getParent(node1) != getParent(node2) {
		parent[parent[node1]] = parent[node2]
	}
}

func buildPwr2(lim int64) {
	pwr2[0] = 1
	for i := int64(0); i < lim; i++ {
		pwr2[i+1] = pwr2[i] << 1
	}
}

func onNthBit(pos int64, val int64) int64 {
	return val | pwr2[pos]
}

func isNthBitOn(pos int64, val int64) bool {
	return (val&pwr2[pos]) > 0
}

func gcd(a, b int64) int64 {
	var c int64
	c = b % a
	for c > 0 {
		b = a
		a = c
		c = b % a
	}
	return a
}

func getLen(num int64) int64 {
	len := int64(1)
	for num > 9 {
		num /= 10
		len++
	}
	return len
}

func main() {
	var testCases int64 = 1
	pow2[0] = 1
	for i := int64(1); i < 18; i++ {
		pow2[i] = pow2[i-1] * 2
	}

	fmt.Printf("%.10f\n", 0.0)

	for T := int64(0); T < testCases; T++ {
		var n, k int64
		fmt.Scan(&n, &k)
		var bamboo [111]int64
		for i := int64(0); i < n; i++ {
			fmt.Scan(&bamboo[i])
		}
		sort.Slice(bamboo[:n], func(i, j int) bool {
			return bamboo[i] < bamboo[j]
		})

		bambooSum[0] = bamboo[0]
		maxval := int64(0)
		for i := int64(1); i < n; i++ {
			bambooSum[i] = bamboo[i] + bambooSum[i-1]
			m := i*bamboo[i] - bambooSum[i-1]
			if m > k && maxval == 0 {
				maxval = bamboo[i]
			}
		}
		if maxval == 0 {
			remaining := k + bambooSum[n-1] - (n * bamboo[n-1])
			fmt.Println((remaining/n) + bamboo[n-1])
			return
		}

		candidatePoints := make(map[int64]struct{})

		for i := int64(0); i < n; i++ {
			bambooSum[i] += k
			lim := int64(1 + math.Sqrt(float64(bamboo[i]+1)))
			for j := int64(1); j < lim; j++ {
				r1 := bamboo[i] / j
				r2 := j
				if r1 < maxval {
					if r1*j == bamboo[i] {
						candidatePoints[r1] = struct{}{}
					} else {
						candidatePoints[r1+1] = struct{}{}
					}
				}
			}
		}
		lim = int64(math.Sqrt(float64(bamboo[n-1])))
		if lim > maxval {
			lim = maxval
		}
		for i := int64(1); i < lim; i++ {
			candidatePoints[i] = struct{}{}
		}

		for cp := range candidatePoints {
			total := int64(0)
			d1 := int64(0)
			flag := int64(1)
			for i := int64(0); i < n; i++ {
				d1 = (bamboo[i] + cp - 1) / cp
				total += (d1 * cp)
				if total > bambooSum[i] {
					flag = 0
					break
				}
			}
			if flag == 1 {
				dv := int64(0)
				for i := int64(0); i < n; i++ {
					dv += (bamboo[i] + cp - 1) / cp
				}
				fmt.Println(cp + (bambooSum[n-1] - total) / dv)
				return
			}
		}
		fmt.Println(1)
	}
}
