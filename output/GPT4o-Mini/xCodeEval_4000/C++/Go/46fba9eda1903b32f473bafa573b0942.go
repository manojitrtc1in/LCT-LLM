package main

import (
	"fmt"
)

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
