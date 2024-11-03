package main

import (
	"fmt"
	"math"
)

const block = 100000

func gooood(x int) bool {
	if x < 3 {
		return x == 2
	}
	if (x & 3) != 1 {
		return false
	}
	top := int(math.Sqrt(float64(x)))
	for i := 2; i <= top; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var l, r, lb, rb, ans int
	fmt.Scan(&l, &r)
	lb = int(math.Ceil(float64(l) / float64(block)))
	rb = int(math.Ceil(float64(r) / float64(block)))
	if lb == rb {
		for i := l; i <= r; i++ {
			if gooood(i) {
				ans++
			}
		}
		fmt.Println(ans)
		return
	}
	for i := lb + 1; i <= rb-1; i++ {
		ans += a[i]
	}
	for i := l; i <= lb*block; i++ {
		if gooood(i) {
			ans++
		}
	}
	for i := (rb-1)*block + 1; i <= r; i++ {
		if gooood(i) {
			ans++
		}
	}
	fmt.Println(ans)
}
