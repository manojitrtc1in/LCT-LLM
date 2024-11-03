package main

import (
	"fmt"
	"sort"
)

const MAGIC = 20000000

var (
	t, la, ma, at int
	to            [1000005]int
	p             [1000005]int
	pp            [1000005]struct {
		first  []int
		second int
	}
	s  = make(map[vector[int]]bool)
	m  [300]map[int]int
	x  [289][289]int
