package main

import (
	"fmt"
	"math"
)

const (
	MaxN = 30000
	MaxM = 100000
)

var (
	f  [MaxN]bool
	fd [MaxM + 100]bool
	p  [MaxN]int
	pn int
