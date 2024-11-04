package main

import (
	"fmt"
	"math"
)

const (
	N   = 65536
	M   = int(1e6) + 9
	INF = int(1e9)
)

var (
	D      [N]int
	hd     [N]int
	suc    [M]int
	to     [M]int
	cap    [M]int
	cst    [M]int
	n, m   int
	s, t   int
	flow   int64
	cost   int64
	mask   = 65535
	Q      [N]int
	F      [N]int
	pre    [N]int
	cz, op int
	inQ    [N]bool
	c      [100][100]int
)

func addEdge(x, y, c, w int) {
	suc[m] = hd[x]
	to[m] = y
	cap[m] = c
	cst[m] = w
	hd[x] = m
	m++
	suc[m] = hd[y]
	to[m] = x
	cap[m] = 0
	cst[m] = -w
	hd[y] = m
	m++
}

func id11(x, y, c, w int) {
	if w == 0 {
		suc[m] = hd[x]
		to[m] = y
		cap[m] = c
		cst[m] = 0
		hd[x] = m
		m++
		suc[m] = hd[y]
		to[m] = x
		cap[m] = c
		cst[m] = 0
		hd[y] = m
		m++
	} else {
		addEdge(x, y, c, w)
		addEdge(y, x, c, w)
	}
}

func id5(x, y, c, w int) {
	id11(x, y, c, 0)
	id11(x, y, INF, w)
}

func spfa() bool {
	cz = 0
	op = 1
	for i := 0; i < n; i++ {
		inQ[i] = false
		D[i] = INF
	}
	D[Q[cz]] = 0
	F[s] = INF
	for cz < op {
		u := Q[cz&mask]
		cz++
		inQ[u] = false
