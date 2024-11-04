package main

import (
	"fmt"
	"math"
)

type pii struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

type sparse struct {
	n  int
	sp [][]pii
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

func id10(a, b pii) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return sq_len(a) < sq_len(b)
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

func id2(p, q pii) (pii, int) {
	return pii{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func id11(a, b pii) []pdd {
	c := pii{b.X - a.X, b.Y - a.Y}
	rr1 := a.Y*a.Y - a.X*a.X
	rr2 := b.Y*b.Y - b.X*b.X
	cc := c.Y*c.Y - c.X*c.X
	rrrr1 := rr1*rr1 - 2*rr1*a.X + a.X*a.X
	rrrr2 := rr2*rr2 - 2*rr2*a.X + a.X*a.X
	cccc := cc*cc - 2*cc*a.X + a.X*a.X
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1+rrrr2+cccc)
	if D >= 0 {
		E := (float64(rr1-rr2)/float64(cc) + 1) / 2
		baza := pdd{float64(a.X) + float64(c.X)*E, float64(a.Y) + float64(c.Y)*E}
		if D != 0 {
			lll := math.Sqrt(float64(D)) / (2 * float64(cc))
			cr := id16(c)
			pmm := pdd{float64(cr.X) * lll, float64(cr.Y) * lll}
			return []pdd{pdd{baza.X + pmm.X, baza.Y + pmm.Y}, pdd{baza.X - pmm.X, baza.Y - pmm.Y}}
		} else {
			return []pdd{baza}
		}
	} else {
		return []pdd{}
	}
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id3(a, b, c, d pii) bool {
	return id21(a, b, c, d) && id21(c, d, a, b)
}

func id13(a, b, c, d pii) bool {
	return id5(a, b, c, d) && id5(c, d, a, b)
}

func id18(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b) * -1
	F := (a*q.X - q.Y*b) * -1
	return pdd{E / D, F / D}
}

func serper(a, b pdd) pdd {
	p := pdd{b.X - a.X, b.Y - a.Y}
	return pdd{p.X + p.X, p.Y + p.Y}
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X + p.Y, c[0].Y - p.X}
	} else {
		return pdd{p.Y, -p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func id2(p, q pii) (pii, int) {
	return pii{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func id11(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id3(a, b, c, d pii) bool {
	return id21(a, b, c, d) && id21(c, d, a, b)
}

func id13(a, b, c, d pii) bool {
	return id5(a, b, c, d) && id5(c, d, a, b)
}

func id18(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b) * -1
	F := (a*q.X - q.Y*b) * -1
	return pdd{E / D, F / D}
}

func serper(a, b pdd) pdd {
	p := pdd{b.X - a.X, b.Y - a.Y}
	return pdd{p.X + p.X, p.Y + p.Y}
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X + p.Y, c[0].Y - p.X}
	} else {
		return pdd{p.Y, -p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	return x.X*y.Y == x.Y*y.X && y.X*z.Y == y.Y*z.X && z.X*t.Y == z.Y*t.X && t.X*x.Y == t.Y*x.X
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y-a.Y*b.X == 0
}

func id7(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func id15(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X >= 0
}

func id20(a, b, c, d pii) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func id12(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	z := pii{d.X - c.X, d.Y - c.Y}
	return id15(x, z)
}

func id8(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id4(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func id4_2(a, b, c pii) bool {
	return id4(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs_2(a, b, c pii) bool {
	return npocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs_2(a, b, c pii) bool {
	return prcs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs_2(a, b, c pii) bool {
	return pocs(pii{a.X - b.X, a.Y - b.Y}, pii{a.X - c.X, a.Y - c.Y})
}

func id21(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id5(a, b, c, d pii) bool {
	x := b.X - a.X
	p := x*(c.Y-b.Y) - (c.X-b.X)*(b.Y-a.Y)
	q := x*(d.Y-b.Y) - (d.X-b.X)*(b.Y-a.Y)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id16(p pdd, c ...pdd) pdd {
	if len(c) > 0 {
		return pdd{c[0].X - p.Y, p.X - c[0].Y}
	} else {
		return pdd{-p.Y, p.X}
	}
}

func id0(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func projection(line pii, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp, 0)
}

func perpendicular(line pii, point pdd) pii {
	return id0(id16(line), pdd{point.X, point.Y})
}

func height(a, b, c pdd) pdd {
	return projection(id2(a, c), b)
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(pii{p.X - q.X, p.Y - q.Y})
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(pii{p.X - q.X, p.Y - q.Y})
}

func id6(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := pii{a.X - b.X, a.Y - b.Y}
	y := pii{b.X - c.X, b.Y - c.Y}
	z := pii{c.X - d.X, c.Y - d.Y}
	t := pii{d.X - a.X, d.Y - a.Y}
