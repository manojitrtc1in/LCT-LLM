package main

import (
	"fmt"
	"math"
)

const (
	N1 = 1e5
	B  = 1e5
	N  = 3e8
)

var (
	lp    = make([]int, N1+1)
	prime []int
