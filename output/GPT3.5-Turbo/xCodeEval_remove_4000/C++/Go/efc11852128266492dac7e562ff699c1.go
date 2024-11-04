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

type sparse struct {
	n  int
	sp [][]pii
}

func id1(p1 pii, p2 pii, n int) pii {
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

func id10(a pii, b pii) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return sq_len(a) < sq_len(b)
	}
}

func id11(a []pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id17(r int) int {
	return 32 - bits.LeadingZeros32(uint32(r))
}

func id18(x pdd, y pdd, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b) / D
	F := (a*q.X - q.Y*b) / D
	return pdd{E, F}
}

func serper(a pdd, b pdd) pdd {
	p := b.sub(a)
	return p.add(p)
}

func projection(line pdd, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp.X, temp.Y)
}

func perpendicular(line pdd, point pdd) pdd {
	return id0(id16(line), point)
}

func height(a pdd, b pdd, c pdd) pdd {
	return projection(id2(a, c), b)
}

func id2(p pdd, q pdd) (pair pdd, a float64) {
	return pdd{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func id0(normal pdd, point pdd) (pair pdd, a float64) {
	return pdd{normal.X, normal.Y}, -(normal.X*point.X + normal.Y*point.Y)
}

func id16(p pdd, c pdd) pdd {
	return c.add(id16(p.sub(c)))
}

func id16(p pdd) pdd {
	return pdd{-p.Y, p.X}
}

func id5(a pdd, b pdd, c pdd, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id3(a pdd, b pdd, c pdd, d pdd) bool {
	return id21(a, b, c, d) && id21(c, d, a, b)
}

func id13(a pdd, b pdd, c pdd, d pdd) bool {
	return id5(a, b, c, d) && id5(c, d, a, b)
}

func id21(a pdd, b pdd, c pdd, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func pocs(a pdd, b pdd, c pdd) bool {
	return a.cross(c) < 0
}

func pocs(a pdd, b pdd, c pdd, d pdd) bool {
	return pocs(a.sub(b), a.sub(c))
}

func prcs(a pdd, b pdd, c pdd) bool {
	return a.cross(c) > 0
}

func prcs(a pdd, b pdd, c pdd, d pdd) bool {
	return prcs(a.sub(b), a.sub(c))
}

func npocs(a pdd, b pdd, c pdd) bool {
	return a.cross(c) <= 0
}

func npocs(a pdd, b pdd, c pdd, d pdd) bool {
	return npocs(a.sub(b), a.sub(c))
}

func id4(a pdd, c pdd) bool {
	return a.cross(c) >= 0
}

func id4(a pdd, b pdd, c pdd) bool {
	return id4(a.sub(b), a.sub(c))
}

func id20(a pdd, b pdd, c pdd, d pdd) bool {
	return a.sub(b).eq(d.sub(c))
}

func id8(a pdd, b pdd, c pdd, d pdd) bool {
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

func id12(a pdd, b pdd, c pdd, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id15(x, z)
}

func id15(a pdd, b pdd) bool {
	return are_parallel(a, b) && (a.dot(b) >= 0)
}

func are_parallel(a pdd, b pdd) bool {
	return a.cross(b) == 0
}

func id7(a pdd, b pdd) bool {
	return a.dot(b) == 0
}

func id6(a pdd, b pdd, c pdd, d pdd) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return (x == y) && (y == z) && (z == t)
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func sq_len(p pdd) float64 {
	return p.dot(p)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pii) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pii, q pii) int {
	return sq_len(p.sub(q))
}

func dist(p pii, q pii) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_len(p pdd) float64 {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p pdd, q pdd) float64 {
	return sq_len(p.sub(q))
}

func dist(p pdd, q pdd) float64 {
	return len(p.sub(q))
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][][][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
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
		return []int{}
	}
}

func id19(a [][][][][][][][][]pii) []int {
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
		sort.Slice(idx, func(i, j int) bool { return id10(a[idx[i]], a[idx[j]]) })

		h := []int{idx[0]}
		for _, it := range idx[1:] {
			temp := a[it]
			if len(h) >= 2 {
				if are_parallel(a[h[len(h)-1]], temp) {
					h = h[:len(h)-1]
