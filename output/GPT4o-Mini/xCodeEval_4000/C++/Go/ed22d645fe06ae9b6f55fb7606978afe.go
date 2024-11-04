package main

import (
	"fmt"
	"math"
	"strings"
)

const N = int(1e2) + 9

func main() {
	var b, d int
	var a, c string
	fmt.Scan(&b, &d)
	fmt.Scan(&a, &c)

	an := len(a)
	cn := len(c)
	t := make([]int, cn)

	for i := 0; i < cn; i++ {
		k := &t[i]
		for j := 0; j < an; j++ {
