package main

import (
	"fmt"
	"math"
)

type pii struct {
	X int
	Y int
}

type pdd struct {
	X float64
	Y float64
}

func id10(a, b pii) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return a.X*a.X+a.Y*a.Y < b.X*b.X+b.Y*b.Y
	}
}

func id9(v []pii) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i].X < v[ans].X || (v[i].X == v[ans].X && v[i].Y < v[ans].Y) {
			ans = i
		}
	}
	return ans
}

func id19(a []pii) []int {
	n := len(a)
	if n > 0 {
		mt := id9(a)
		d := a[mt]
		for i := 0; i < n; i++ {
			a[i].X -= d.X
			a[i].Y -= d.Y
		}

		idx := make([]int, n)
		for i := 0; i < n; i++ {
			idx[i] = i
		}
		sort.Slice(idx, func(i, j int) bool {
			return id10(a[idx[i]], a[idx[j]])
		})

		h := []int{idx[0]}
		for _, it := range idx[1:] {
			temp := a[it]
			if len(h) >= 2 {
				if areParallel(a[h[len(h)-1]], temp) {
					h = h[:len(h)-1]
				}
				for len(h) >= 3 && npocs(a[h[len(h)-2]], a[h[len(h)-1]], temp) {
					h = h[:len(h)-1]
				}
			}
			h = append(h, it)
		}

		for i := 0; i < n; i++ {
			a[i].X += d.X
			a[i].Y += d.Y
		}
		return h
	} else {
		return []int{}
	}
}

func id17(r int) int {
	return 32 - int(math.BuiltinClz(uint(r)))
}

func id1(p1, p2 pii, n int) pii {
	if p1.X == -1 || p2.X == -1 {
		return pii{-1, -1}
	}
	np1 := pii{0, raz(p1.Y, p1.X, n)}
	np2 := pii{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return pii{-1, -1}
		} else {
			return pii{sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
		}
	} else {
		if np2.X <= np1.Y+1 {
			return pii{-1, -1}
		} else {
			return pii{sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n)}
		}
	}
}

type sparse struct {
	n  int
	sp [][]pii
}

func (s *sparse) construct(v []pii) {
	s.n = len(v)
	r := id17(s.n - 1)
	s.sp = make([][]pii, r)
	for i := 0; i < r; i++ {
		s.sp[i] = make([]pii, s.n)
	}
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

func (s *sparse) segment(l, r int) pii {
	if l == -1 || r == -1 {
		return pii{-1, -1}
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := id17(szz) - 1
	return id1(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
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
	zz := id17(n)
	v := make([]sparse, zz)
	prs := make([]pii, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pii{-1, -1}
		} else {
			prs[i] = id1(pii{raz(i, r[i], n), i}, pii{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		id14 := make([]pii, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			id14[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(id14)
	}

	for i := 0; i < n; i++ {
		myPr := pii{i, i}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			newPr := v[j].segment(myPr.X, myPr.Y)
			if newPr.X != -1 {
				ans += 1 << j
				myPr = newPr
			}
		}
		fmt.Printf("%d ", ans+1)
	}
	fmt.Println()
}
