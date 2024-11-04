package main

import (
	"fmt"
)

type orderedSet struct {
}

func (os *orderedSet) insert(val int) {
	// insert implementation
}

func (os *orderedSet) erase(val int) {
	// erase implementation
}

func (os *orderedSet) orderOfKey(val int) int {
	// orderOfKey implementation
	return 0
}

func (os *orderedSet) findKthSmallest(k int) int {
	// findKthSmallest implementation
	return 0
}

func yes() {
	fmt.Println("Yes")
}

func no() {
	fmt.Println("No")
}

func main() {
	var a int64
	fmt.Scan(&a)
	n := int64(1e17)
	n *= 18
	n %= a
	k := n

	for i := 0; i < 44; i++ {
		n = (n + k) % a
	}

	if n < 0 {
		n += a
	}
	c := a - n
	d := c + int64(1e18) - 1
	fmt.Println(c, d)
}
