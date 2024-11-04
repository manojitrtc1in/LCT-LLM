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

func mp(a, b int) pair {
	return pair{a, b}
}

func sz(v interface{}) int {
	switch v := v.(type) {
	case []pair:
		return len(v)
	case []int:
		return len(v)
	case []float64:
		return len(v)
	case []bool:
		return len(v)
	case [][]pair:
		return len(v)
	default:
		return 0
	}
}

func sqrt(x float64) float64 {
	return math.Sqrt(x)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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

func id10(a, b pair) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return a.X*a.X+a.Y*a.Y < b.X*b.X+b.Y*b.Y
	}
}

func id15(a, b pair) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id16(p pair, c ...pair) pair {
	if len(c) == 0 {
		return pair{-p.Y, p.X}
	}
	return pair{c[0].X + (-p.Y), c[0].Y + p.X}
}

func id17(r int) int {
	return 32 - int(math.Log2(float64(r)))
}

func id19(a []pair) []int {
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
				if id15(a[h[len(h)-1]], temp) {
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

func (s *sparse) construct(v []pair) {
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

func id9(v []pair) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i].X < v[ans].X {
			ans = i
		}
	}
	return ans
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
	prs := make([]pair, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pair{-1, -1}
		} else {
			prs[i] = id1(pair{raz(i, r[i], n), i}, pair{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		id14 := make([]pair, n)
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
		fmt.Print(ans+1, " ")
	}
	fmt.Println()
}
