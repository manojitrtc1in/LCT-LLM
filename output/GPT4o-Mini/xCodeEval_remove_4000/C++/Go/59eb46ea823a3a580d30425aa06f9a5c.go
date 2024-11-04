package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	X, Y int64
}

type Pll struct {
	X, Y int64
}

type Pii struct {
	X, Y int
}

type Vpii []Pii

type Vpll []Pll

type Vpair []Pair

func take(k int, perm *Vpair, points *Vpair) {
	n := len(*points)
	for i := 0; i < n; i++ {
		if (*points)[i].Y == int64(k) {
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
	p := make(Vpair, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i].X, &p[i].Y)
		p[i].Y = int64(i)
	}
	var s string
	fmt.Scan(&s)
	perm := make(Vpair, 0)
	firstIdx := 0
	for i := 1; i < n; i++ {
		if p[i].X < p[firstIdx].X {
			firstIdx = i
		}
	}
	take(firstIdx, &perm, &p)
	for i := 0; i < n-2; i++ {
		q := perm[len(perm)-1].X
		best := 0
		for j := 1; j < len(p); j++ {
			if ((p[best].X-q)%(p[j].X-q) > 0) == (s[i] == 'R') {
				best = j
			}
		}
		take(int(p[best].Y), &perm, &p)
	}
	take(int(p[0].Y), &perm, &p)
	for i := 0; i < len(perm); i++ {
		fmt.Print(perm[i].Y + 1, " ")
	}
	fmt.Println()
}
