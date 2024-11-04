package main

import (
	"fmt"
	"math"
	"sort"
	"strings"
)

type xyPoint struct {
	x, y float64
}

type xyCircle struct {
	center xyPoint
	radius float64
}

func cartesianDist(a, b xyPoint) float64 {
	d := a.x - b.x
	e := a.y - b.y
	return math.Sqrt(d*d + e*e)
}

type xyLine struct {
	slope, intercept, normfac float64
	vertical                  bool
	xcross                    float64
}

func newXYLine(a, b xyPoint) xyLine {
	if a.x == b.x {
		return xyLine{
			vertical: true,
			xcross:   a.x,
		}
	} else {
		return xyLine{
			vertical:  false,
			xcross:    math.NaN(),
			slope:     (b.y - a.y) / (b.x - a.x),
			intercept: a.y - (a.x*(b.y-a.y))/(b.x-a.x),
			normfac:   math.Sqrt(math.Pow((b.y-a.y)/(b.x-a.x), 2) + 1),
		}
	}
}

func (l xyLine) orthDist(o xyPoint) float64 {
	if l.vertical {
		return o.x - l.xcross
	} else {
		return (l.slope*o.x - o.y + l.intercept) / l.normfac
	}
}

func triangleArea(a, b, c xyPoint) float64 {
	l := newXYLine(a, b)
	h := math.Abs(l.orthDist(c))
	e := cartesianDist(a, b)
	return h * e
}

type HopcroftKarp struct {
	adj  []map[int]bool
	tag  []bool
	npair int
	NIL  int
	INF  int
	g1   []int
	dist []int
	pair []int
}

func newHopcroftKarp(adj []map[int]bool, tag []bool) *HopcroftKarp {
	hk := &HopcroftKarp{
		adj:  adj,
		tag:  tag,
		npair: 0,
		NIL:  len(adj),
		INF:  len(adj) + 1,
		dist: make([]int, len(adj)+1),
		pair: make([]int, len(adj)),
	}
	for i := range hk.pair {
		hk.pair[i] = hk.NIL
	}
	return hk
}

func (hk *HopcroftKarp) getMap() map[int]int {
	m := make(map[int]int)
	for j := 0; j < len(hk.pair); j++ {
		if hk.pair[j] != hk.NIL && hk.tag[j] {
			m[j] = hk.pair[j]
		}
	}
	return m
}

func (hk *HopcroftKarp) mfBreadthFirstSearch() bool {
	bfsQueue := make([]int, 0)
	for _, v := range hk.g1 {
		if hk.pair[v] == hk.NIL {
			hk.dist[v] = 0
			bfsQueue = append(bfsQueue, v)
		} else {
			hk.dist[v] = hk.INF
		}
	}
	hk.dist[hk.NIL] = hk.INF

	for len(bfsQueue) > 0 {
		v := bfsQueue[0]
		bfsQueue = bfsQueue[1:]

		if hk.dist[v] < hk.dist[hk.NIL] {
			for u := range hk.adj[v] {
				if hk.dist[hk.pair[u]] == hk.INF {
					hk.dist[hk.pair[u]] = hk.dist[v] + 1
					bfsQueue = append(bfsQueue, hk.pair[u])
				}
			}
		}
	}

	return hk.dist[hk.NIL] != hk.INF
}

func (hk *HopcroftKarp) mfDepthFirstSearch(v int) bool {
	if v == hk.NIL {
		return true
	} else {
		for u := range hk.adj[v] {
			if hk.dist[hk.pair[u]] == hk.dist[v]+1 && hk.mfDepthFirstSearch(hk.pair[u]) {
				hk.pair[u] = v
				hk.pair[v] = u
				return true
			}
		}
		hk.dist[v] = hk.INF
		return false
	}
}

func main() {
	c388()
}
