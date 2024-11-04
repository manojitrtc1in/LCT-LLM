package main

import (
	"fmt"
	"math"
	"sort"
)

type pair struct {
	X, Y int64
}

type point struct {
	Pair pair
	Idx  int
}

type byPair []point

func (a byPair) Len() int           { return len(a) }
func (a byPair) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a byPair) Less(i, j int) bool { return a[i].Pair.X < a[j].Pair.X || (a[i].Pair.X == a[j].Pair.X && a[i].Pair.Y < a[j].Pair.Y) }

func take(k int, perm *[]point, points *[]point) {
	n := len(*points)
	for i := 0; i < n; i++ {
		if (*points)[i].Idx == k {
			(*points)[i], (*points)[n-1] = (*points)[n-1], (*points)[i]
			break
		}
	}
	*perm = append(*perm, (*points)[n-1])
	*points = (*points)[:n-1]
}

func main() {
	var n int
	fmt.Scan(&n)
	p := make([]point, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i].Pair.X)
		p[i].Idx = i
	}
	var s string
	fmt.Scan(&s)
	sort.Sort(byPair(p))
	perm := make([]point, 0)
	firstIdx := 0
	for i := 0; i < n; i++ {
		if p[i].Pair.Less(p[firstIdx].Pair) {
			firstIdx = i
		}
	}
	take(firstIdx, &perm, &p)
	for i := 0; i < n-2; i++ {
		q := perm[len(perm)-1].Pair
		best := 0
		for j := 1; j < len(p); j++ {
			if ((p[best].Pair.X-q.X)*(p[j].Pair.Y-q.Y)-(p[best].Pair.Y-q.Y)*(p[j].Pair.X-q.X) > 0) == (s[i] == 'R') {
				best = j
			}
		}
		take(p[best].Idx, &perm, &p)
	}
	take(p[0].Idx, &perm, &p)
	for i := 0; i < len(perm); i++ {
		fmt.Printf("%d ", perm[i].Idx+1)
	}
	fmt.Println()
}
