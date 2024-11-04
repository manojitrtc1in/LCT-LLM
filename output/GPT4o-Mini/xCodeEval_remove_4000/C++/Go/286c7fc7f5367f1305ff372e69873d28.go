package main

import (
	"fmt"
	"math"
	"sort"
)

type arrInt []int64

func (a arrInt) size() int {
	return len(a)
}

func (a arrInt) view() []int64 {
	return a
}

func readIntArray(size int) arrInt {
	var a arrInt
	for i := 0; i < size; i++ {
		var x int64
		fmt.Scan(&x)
		a = append(a, x)
	}
	return a
}

func bitCount(x uint64) int {
	return int(math.Log2(float64(x))) + 1
}

func isSet(mask uint64, bit int) bool {
	return (mask>>bit)&1 == 1
}

func minim(was *int, cand int) {
	if *was > cand {
		*was = cand
	}
}

func main() {
	var n int
	fmt.Scan(&n)
	a := readIntArray(n)

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	d := make(arrInt, n)
	for i := 0; i < n; i++ {
		c := a[i]
		for j := int64(2); j*j <= c; j++ {
			for c%j == 0 {
				d[i]++
				c /= j
			}
		}
		if c != 1 {
			d[i]++
		}
	}

	infty := math.MaxInt64 / 2
	reachable := make([]int, 1<<n)
	for i := range reachable {
		reachable[i] = infty
	}
	reachable[0] = 0

	for i := 0; i < n; i++ {
		for j := 0; j < (1 << i); j++ {
			rem := a[i]
			good := true
			for k := 0; k < i; k++ {
				if isSet(uint64(j), k) {
					if rem%a[k] != 0 {
						good = false
						break
					}
					rem /= a[k]
				}
			}
			qty := 0
			for c := int64(2); c*c <= rem; c++ {
				for rem%c == 0 {
					qty++
					rem /= c
				}
			}
			if rem != 1 {
				qty++
			}
			lim := 0
			if i > 0 {
				lim = 1 << (i - 1)
			}
			if good {
				for k := 0; k < (1 << i); k++ {
					if (j&k) == 0 && reachable[j+k] != infty && j+k >= lim {
						minim(&reachable[(1<<i)+k], reachable[j+k]+qty+(d[i] == 1 ? 0 : 1))
					}
				}
			}
		}
	}

	answer := infty
	for i := (1 << (n - 1)); i < (1 << n); i++ {
		if reachable[i] == 0 {
			continue
		}
		minim(&answer, reachable[i]+(bitCount(uint64(i)) == 1 ? 0 : 1))
	}
	fmt.Println(answer)
}
