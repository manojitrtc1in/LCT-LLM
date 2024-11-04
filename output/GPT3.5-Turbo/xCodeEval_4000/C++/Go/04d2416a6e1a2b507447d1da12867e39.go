package main

import (
	"fmt"
)

func win(a, b int64) bool {
	if a%2 != 0 {
		var cnt int64 = 0
		for b != 0 {
			cnt += b % a
			b /= a
		}
		return cnt%2 == 0
	} else {
		return b%(a+1)%2 == 0
	}
}

func ss(a, b int64) bool {
	if a == 0 {
		return false
	}
	if !ss(b%a, a) {
		return true
	}
	return win(a, b/a)
}

func main() {
	var t int
	fmt.Scan(&t)
	for t > 0 {
		var a, b int64
		fmt.Scan(&a, &b)
		if ss(min(a, b), max(a, b)) {
			fmt.Println("First")
		} else {
			fmt.Println("Second")
		}
		t--
	}
}
