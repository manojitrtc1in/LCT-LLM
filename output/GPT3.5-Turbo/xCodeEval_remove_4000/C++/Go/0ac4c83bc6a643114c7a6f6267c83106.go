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

func id2(p, q pii) (pair pii) {
	pair.X = q.Y - p.Y
	pair.Y = p.X - q.X
	return
}

func id11(a, b []pii) []pdd {
	n := len(a)
	if n > 0 {
		id14 := make([]pii, n)
		for j := 0; j < n; j++ {
			pairr := segment(a, b, j, j)
			id14[j] = segment(a, b, pairr.X, pairr.Y)
		}
		return id14
	} else {
		return []pdd{}
	}
}

func segment(a, b []pii, l, r int) (pair pii) {
	if l == -1 || r == -1 {
		return pii{-1, -1}
	}
	szz := raz(r, l, len(a))
	if l == r {
		return a[l]
	}
	g := id17(szz) - 1
	return id1(a[l], a[(r+1-(1<<g))%len(a)], len(a))
}

func projection(line pdd, point pii) pdd {
	temp := perpendicular(line, point)
	return ints(line, temp.X, temp.Y)
}

func perpendicular(line pdd, point pii) (pair pdd) {
	pair = id0(id16(line), point)
	return
}

func ints(p pdd, a float64, q pdd, b float64) (pair pdd) {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b)
	F := (p.Y*q.X - p.X*q.Y)
	pair.X = E / D
	pair.Y = F / D
	return
}

func id18(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func serper(a, b pdd) (pair pdd) {
	p := b.sub(a)
	pair = p.add(p)
	return
}

func id16(p pdd, c ...pdd) (pair pdd) {
	if len(c) > 0 {
		pair = c[0].add(p.sub(c[0]))
	} else {
		pair = p.neg()
	}
	return
}

func id5(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id3(a, b, c, d pdd) bool {
	return id21(a, b, c, d) && id21(c, d, a, b)
}

func id13(a, b, c, d pdd) bool {
	return id5(a, b, c, d) && id5(c, d, a, b)
}

func id21(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func pocs(a, b pdd, c ...pdd) bool {
	return (a.cross(b) < 0)
}

func pocs3(a, b, c pdd) bool {
	return pocs(a.sub(b), a.sub(c))
}

func prcs(a, b pdd, c ...pdd) bool {
	return (a.cross(b) > 0)
}

func prcs3(a, b, c pdd) bool {
	return prcs(a.sub(b), a.sub(c))
}

func npocs(a, b pdd, c ...pdd) bool {
	return (a.cross(b) <= 0)
}

func npocs3(a, b, c pdd) bool {
	return npocs(a.sub(b), a.sub(c))
}

func id4(a, b pdd, c ...pdd) bool {
	return (a.cross(b) >= 0)
}

func id4_3(a, b, c pdd) bool {
	return id4(a.sub(b), a.sub(c))
}

func id8(a, b, c, d pdd) bool {
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

func id12(a, b, c, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id15(x, z)
}

func id20(a, b, c, d pdd) bool {
	return (a.sub(b) == d.sub(c))
}

func are_parallel(a, b pdd) bool {
	return (a.cross(b) == 0)
}

func is_rectangle(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return ((x.cross(y) == 0) && (y.cross(z) == 0) && (z.cross(t) == 0) && (t.cross(x) == 0))
}

func id6(a, b, c, d pdd) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return ((x == y) && (y == z) && (z == t))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func len(p pdd) float64 {
	return math.Sqrt(sq_len(p))
}

func sq_dist(p, q pdd) float64 {
	return sq_len(p.sub(q))
}

func sq_len(p pdd) float64 {
	return p.dot(p)
}

func (p pdd) dot(q pdd) float64 {
	return p.X*q.X + p.Y*q.Y
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func (p pdd) sub(q pdd) pdd {
	return pdd{p.X - q.X, p.Y - q.Y}
}

func (p pdd) add(q pdd) pdd {
	return pdd{p.X + q.X, p.Y + q.Y}
}

func (p pdd) neg() pdd {
	return pdd{-p.X, -p.Y}
}

func (p pdd) mul(q float64) pdd {
	return pdd{p.X * q, p.Y * q}
}

func (p pdd) mod(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func (p pdd) sq_len() float64 {
	return p.dot(p)
}

func (p pdd) sq_dist(q pdd) float64 {
	return p.sub(q).sq_len()
}

func (p pdd) len() float64 {
	return math.Sqrt(p.sq_len())
}

func (p pdd) dist(q pdd) float64 {
	return p.sub(q).len()
}

func (p pdd) id16(c ...pdd) pdd {
	if len(c) > 0 {
		return c[0].add(p.id16(p.sub(c[0])))
	} else {
		return p.neg()
	}
}

func (p pdd) id16_2(c pdd) pdd {
	return c.add(p.id16(p.sub(c)))
}

func (p pdd) id16_1() pdd {
	return p.neg()
}

func (p pdd) id16_0() pdd {
	return p
}

func id0(normal, point pdd) (pair pdd) {
	pair = pdd{normal.X, normal.Y}
	pair = pair.mul(-point.dot(normal))
	return
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		return c - M
	}
	return c
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		return c + M
	}
	return c
}

func prod(a, b, M int) int {
	return (int64(a) * int64(b)) % int64(M)
}

func euc(m, n int) pii {
	if n == 0 {
		if m >= 0 {
			return pii{1, 0}
		} else {
			return pii{-1, 0}
		}
	}
	t := m / n
	ans1 := euc(n, m-t*n)
	return pii{ans1.Y, ans1.X - ans1.Y*t}
}

func z_function(s []int) []int {
	n := len(s)
	z := make([]int, n)
	l, r := 0, 1
	for i := 1; i < n; i++ {
		z[i] = max(0, min(r-i, z[i-l]))
		for i+z[i] < n && s[i+z[i]] == s[z[i]] {
			z[i]++
		}
		if r < i+z[i] {
			l = i
			r = i + z[i]
		}
	}
	return z
}

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
		my_pr := pii{i, i}
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
