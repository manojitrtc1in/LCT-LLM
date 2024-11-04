package main

import (
	"fmt"
	"math"
)

type pair struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

type vvpii [][]pair
type vpii []pair
type vi []int

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
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

func npocs(a, c pair) bool {
	return (a.X*c.Y - a.Y*c.X) <= 0
}

func id15(a, b pair) bool {
	return npocs(a, b) && npocs(b, a)
}

func id10(a, b pair) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return a.X*a.X+a.Y*a.Y < b.X*b.X+b.Y*b.Y
	}
}

func id1(p1, p2 pair, n int) pair {
	if p1.X == -1 || p2.X == -1 {
		return pair{-1, -1}
	}
	np1 := pair{0, raz(p1.Y, p1.X, n)}
	np2 := pair{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
		}
	} else {
		if np2.X <= np1.Y+1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
		}
	}
}

type sparse struct {
	n  int
	sp vvpii
}

func (s *sparse) construct(v vpii) {
	s.n = len(v)
	r := id17(s.n - 1)
	s.sp = make(vvpii, r)
	for i := 0; i < s.n; i++ {
		s.sp[0][i] = v[i]
	}
	for i := 1; i < r; i++ {
		for j := 0; j < s.n; j++ {
			p1 := s.sp[i-1][j]
			p2 := s.sp[i-1][(j+(1<<(i-1)))%s.n]
			s.sp[i][j] = id1(p1, p2, s.n)
		}
	}
}

func (s *sparse) segment(l, r int) pair {
	if l == -1 || r == -1 {
		return pair{-1, -1}
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := id17(szz) - 1
	return id1(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
}

func id17(r int) int {
	return 32 - int(math.Log2(float64(r)))
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
	zz := id17(n) + 1
	v := make([]sparse, zz)
	prs := make(vpii, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pair{-1, -1}
		} else {
			prs[i] = id1(pair{raz(i, r[i], n), i}, pair{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		id14 := make(vpii, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			id14[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(id14)
	}

	for i := 0; i < n; i++ {
		my_pr := pair{i, i}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			new_pr := v[j].segment(my_pr.X, my_pr.Y)
			if new_pr.X != -1 {
				ans += 1 << j
				my_pr = new_pr
			}
		}
		fmt.Printf("%d ", ans+1)
	}
	fmt.Println()
}
