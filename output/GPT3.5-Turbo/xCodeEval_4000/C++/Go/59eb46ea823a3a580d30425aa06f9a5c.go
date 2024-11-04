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
	P pair
	I int
}

func take(k int, perm *[]point, points *[]point) {
	n := len(*points)
	for i := 0; i < n; i++ {
		if (*points)[i].I == k {
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
		fmt.Scan(&p[i].P.X, &p[i].P.Y)
		p[i].I = i
	}
	var s string
	fmt.Scan(&s)
	perm := make([]point, 0)
	firstIdx := 0
	for i := 0; i < n; i++ {
		if p[i].P.X < p[firstIdx].P.X || (p[i].P.X == p[firstIdx].P.X && p[i].P.Y < p[firstIdx].P.Y) {
			firstIdx = i
		}
	}
	take(firstIdx, &perm, &p)
	for i := 0; i < n-2; i++ {
		q := perm[len(perm)-1].P
		best := 0
		for j := 1; j < len(p); j++ {
			if (((p[best].P.X-q.X)*(p[j].P.Y-q.Y)-(p[best].P.Y-q.Y)*(p[j].P.X-q.X)) > 0) == (s[i] == 'R') {
				best = j
			}
		}
		take(p[best].I, &perm, &p)
	}
	take(p[0].I, &perm, &p)
	sort.Slice(perm, func(i, j int) bool {
		return perm[i].I < perm[j].I
	})
	for i := 0; i < len(perm); i++ {
		fmt.Printf("%d ", perm[i].I+1)
	}
	fmt.Println()
}
