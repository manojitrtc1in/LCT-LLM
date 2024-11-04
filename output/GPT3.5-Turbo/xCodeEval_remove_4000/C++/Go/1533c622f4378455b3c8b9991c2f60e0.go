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

func id9(v []pair) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i].X < v[ans].X || (v[i].X == v[ans].X && v[i].Y < v[ans].Y) {
			ans = i
		}
	}
	return ans
}

func id19(a []pair) vi {
	n := len(a)
	if n > 0 {
		mt := id9(a)
		d := a[mt]
		for i := 0; i < n; i++ {
			a[i].X -= d.X
			a[i].Y -= d.Y
		}

		idx := make(vi, n)
		for i := 0; i < n; i++ {
			idx[i] = i
		}
		sort.Slice(idx, func(i, j int) bool {
			return id10(a[idx[i]], a[idx[j]])
		})

		h := make(vi, 0)
		h = append(h, idx[0])
		for _, it := range idx[1:] {
			temp := a[it]
			if len(h) >= 2 {
				if are_parallel(a[h[len(h)-1]], temp) {
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
		return vi{}
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

func id17(r int) int {
	ans := 0
	for r > 0 {
		ans++
		r >>= 1
	}
	return ans
}

func id2(p, q pair) (pair, int) {
	return pair{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func id11(a, b pair) []pdd {
	c := b
	rr1 := a.X*a.X + a.Y*a.Y
	rr2 := b.X*b.X + b.Y*b.Y
	cc := c.X*c.X + c.Y*c.Y
	rrrr1 := rr1 * rr1
	rrrr2 := rr2 * rr2
	cccc := cc * cc
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1 + rrrr2 + cccc)
	if D >= 0 {
		E := ((float64)(rr1-rr2)/float64(cc) + 1) / 2
		baza := pdd{float64(a.X) + float64(c.X)*E, float64(a.Y) + float64(c.Y)*E}
		if D > 0 {
			lll := math.Sqrt((float64)(D)) / (2 * math.Sqrt(float64(cc)))
			cr := id16(c)
			pmm := pdd{float64(cr.X) * lll, float64(cr.Y) * lll}
			return []pdd{{baza.X + pmm.X, baza.Y + pmm.Y}, {baza.X - pmm.X, baza.Y - pmm.Y}}
		} else {
			return []pdd{{baza.X, baza.Y}}
		}
	} else {
		return []pdd{}
	}
}

func id16(p pair) pair {
	return pair{-p.Y, p.X}
}

func id16_2(p, c pair) pair {
	return pair{c.X + id16(pair{p.X - c.X, p.Y - c.Y}).X, c.Y + id16(pair{p.X - c.X, p.Y - c.Y}).Y}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b) - (-b*q.Y + q.X*a)
	F := (p.Y*a - p.X*b) - (q.Y*a - q.X*b)
	return pdd{E / D, F / D}
}

func projection(line pair, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pair, point pdd) pair {
	return id0(id16(line), point)
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func id0(normal, point pair) (pair, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func serper(a, b pair) pair {
	p := pair{b.X - a.X, b.Y - a.Y}
	return pair{p.X + p.X, -(p.X*a.X + p.Y*a.Y)}
}

func are_parallel(a, b pair) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id21(a, b, c, d pair) bool {
	x := b.X - a.X
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pair) bool {
	x := b.X - a.X
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id3(a, b, c, d pair) bool {
	return id21(a, b, c, d) && id21(c, d, a, b)
}

func id13(a, b, c, d pair) bool {
	return id5(a, b, c, d) && id5(c, d, a, b)
}

func on_segment(a, b, c pair) bool {
	return id15(b.sub(a), c.sub(b))
}

func id4(a, c pair) bool {
	return (a.X*c.X + a.Y*c.Y) >= 0
}

func id4_2(a, b, c pair) bool {
	return id4(b.sub(a), c.sub(a))
}

func id6(a, b, c, d pair) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pair) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return (x.dot(y) == 0) && (y.dot(z) == 0) && (z.dot(t) == 0) && (t.dot(x) == 0)
}

func sq_len(p pair) int {
	return p.dot(p)
}

func sq_dist(p, q pair) int {
	return sq_len(p.sub(q))
}

func len(p pair) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pair) float64 {
	return len(p.sub(q))
}

func id7(a, b pair) bool {
	return a.dot(b) == 0
}

func id8(a, b, c, d pair) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	p := x.cross(y)
	q := y.cross(z)
	r := z.cross(t)
	s := t.cross(x)
	return ((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) || ((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0))
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
				ans += (1 << j)
				my_pr = new_pr
			}
		}
		fmt.Print(ans+1, " ")
	}
	fmt.Println()
}
