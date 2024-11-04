package main

import (
	"fmt"
	"math"
	"sort"
)

type Pair struct {
	X, Y int64
}

type Sparse struct {
	n int
	sp [][]Pair
}

func (s *Sparse) construct(v []Pair) {
	s.n = len(v)
	r := countTro(s.n - 1)
	s.sp = make([][]Pair, r)
	for i := range s.sp {
		s.sp[i] = make([]Pair, s.n)
	}
	for i := 0; i < s.n; i++ {
		s.sp[0][i] = v[i]
	}
	for i := 1; i < r; i++ {
		for j := 0; j < s.n; j++ {
			p1 := s.sp[i-1][j]
			p2 := s.sp[i-1][(j+(1<<(i-1)))%s.n]
			s.sp[i][j] = uniteSeg(p1, p2, s.n)
		}
	}
}

func (s *Sparse) segment(l, r int) Pair {
	if l == -1 || r == -1 {
		return Pair{-1, -1}
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := countTro(szz) - 1
	return uniteSeg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+n)%s.n], s.n)
}

func countTro(r int) int {
	return 32 - bits.LeadingZeros32(uint32(r))
}

func uniteSeg(p1, p2 Pair, n int) Pair {
	if p1.X == -1 || p2.X == -1 {
		return Pair{-1, -1}
	}
	np1 := Pair{0, raz(p1.Y, p1.X, n)}
	np2 := Pair{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == int64(n-1) {
			return Pair{-1, -1}
		}
		return Pair{sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
	} else {
		if np2.X <= np1.Y+1 {
			return Pair{-1, -1}
		}
		return Pair{sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
	}
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		return c + M
	}
	return c
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		return c - M
	}
	return c
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)
	if n == 1 {
		fmt.Println("0")
		return
	}
	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i])
	}
	zz := countTro(n)
	v := make([]Sparse, zz)
	prs := make([]Pair, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = Pair{-1, -1}
		} else {
			prs[i] = uniteSeg(Pair{raz(i, r[i], n), int64(i)}, Pair{int64(i), sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		newPrs := make([]Pair, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			newPrs[j] = v[i-1].segment(int(pairr.X), int(pairr.Y))
		}
		v[i].construct(newPrs)
	}

	for i := 0; i < n; i++ {
		myPr := Pair{int64(i), int64(i)}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			newPr := v[j].segment(int(myPr.X), int(myPr.Y))
			if newPr.X != -1 {
				ans += (1 << j)
				myPr = newPr
			}
		}
		fmt.Print(ans + 1, " ")
	}
	fmt.Println()
}
