package main

import (
	"fmt"
)

const (
	INF = int(1e9)
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func LIS(n int, a []int) int {
	b := make([]int, 0)
	b = append(b, a[0])
	for i := 1; i < n; i++ {
		if b[len(b)-1] < a[i] {
			b = append(b, a[i])
		} else {
			l, r := 0, len(b)
			for l < r {
				m := (l + r) / 2
				if b[m] < a[i] {
					l = m + 1
				} else {
					r = m
				}
			}
			b[r] = a[i]
		}
	}
	return len(b)
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	c := make([][]int, n)
	for i := 0; i < n; i++ {
		c[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&c[i][j])
		}
	}

	s := 0
	t := n*m + 1
	n = t + 1
	m = 2

	D := make([]int, n)
	hd := make([]int, n)
	suc := make([]int, 2*m)
	to := make([]int, 2*m)
	cap := make([]int, 2*m)
	cst := make([]int, 2*m)

	m = 0
	add_edge := func(x, y, c, w int) {
		suc[m] = hd[x]
		to[m] = y
		cap[m] = c
		cst[m] = w
		hd[x] = m
		m++
	}

	id11 := func(x, y, c, w int) {
		if w == 0 {
			suc[m] = hd[x]
			to[m] = y
			cap[m] = c
			cst[m] = 0
			hd[x] = m
			m++
			suc[m] = hd[y]
			to[m] = x
