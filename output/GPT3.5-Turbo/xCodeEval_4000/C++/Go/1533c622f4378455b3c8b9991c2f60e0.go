package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type pair struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

type pll struct {
	X, Y int64
}

type pii struct {
	X, Y int
}

type vpii []pii
type vvpii []vpii
type pbl struct {
	X bool
	Y int64
}

type vpbl []pbl

type vpll []pll
type vi []int
type vvi []vi
type vl []int64
type vvl []vl
type vb []bool
type vd []float64
type vpdd []pdd

func make_pair(a, b int) pii {
	return pii{a, b}
}

func mp(a, b int64) pll {
	return pll{a, b}
}

func gl(r *bufio.Reader) string {
	var s string
	s, _ = r.ReadString('\n')
	return s[:len(s)-1]
}

func pb(v *vi, x int) {
	*v = append(*v, x)
}

func eb(v *vpii, x pii) {
	*v = append(*v, x)
}

func sz(x interface{}) int {
	switch v := x.(type) {
	case vi:
		return len(v)
	case vpii:
		return len(v)
	case vvpii:
		return len(v)
	case vpdd:
		return len(v)
	case vpll:
		return len(v)
	case vl:
		return len(v)
	case vvl:
		return len(v)
	case vb:
		return len(v)
	default:
		return 0
	}
}

func UM() map[int]int {
	return make(map[int]int)
}

func US() map[int]bool {
	return make(map[int]bool)
}

func X(p pii) int {
	return p.X
}

func Y(p pii) int {
	return p.Y
}

func sq_len(p pii) int {
	return p.X*p.X + p.Y*p.Y
}

func sq_dist(p, q pii) int {
	return sq_len(sub(p, q))
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(sub(p, q))
}

func is_rhombus(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := sub(a, b)
	y := sub(b, c)
	z := sub(c, d)
	t := sub(d, a)
	return x.X*y.X == 0 && y.X*z.X == 0 && z.X*t.X == 0 && t.X*x.X == 0
}

func are_parallel(a, b pii) bool {
	return a.X*b.Y == a.Y*b.X
}

func are_orthogonal(a, b pii) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func are_codirected(a, b pii) bool {
	return are_parallel(a, b) && a.X*b.X+a.Y*b.Y >= 0
}

func is_parallelogram(a, b, c, d pii) bool {
	return sub(a, b) == sub(d, c)
}

func is_trapezoid(a, b, c, d pii) bool {
	x := sub(a, b)
	z := sub(d, c)
	return are_codirected(x, z)
}

func is_convex_polygon(a, b, c, d pii) bool {
	x := sub(a, b)
	y := sub(b, c)
	z := sub(c, d)
	t := sub(d, a)
	p := x.X*y.Y - x.Y*y.X
	q := y.X*z.Y - y.Y*z.X
	r := z.X*t.Y - z.Y*t.X
	s := t.X*x.Y - t.Y*x.X
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func nprcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func nprcs3(a, b, c pii) bool {
	return nprcs(sub(a, b), sub(a, c))
}

func npocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func npocs3(a, b, c pii) bool {
	return npocs(sub(a, b), sub(a, c))
}

func prcs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func prcs3(a, b, c pii) bool {
	return prcs(sub(a, b), sub(a, c))
}

func pocs(a, c pii) bool {
	return a.X*c.Y-a.Y*c.X < 0
}

func pocs3(a, b, c pii) bool {
	return pocs(sub(a, b), sub(a, c))
}

func different_sides(a, b, c, d pii) bool {
	x := sub(b, a)
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func sharply_different_sides(a, b, c, d pii) bool {
	x := sub(b, a)
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func rot_90(p pii) pii {
	return pii{-p.Y, p.X}
}

func rot_90c(p, c pii) pii {
	return add(c, rot_90(sub(p, c)))
}

func intersecting_segments(a, b, c, d pii) bool {
	return different_sides(a, b, c, d) && different_sides(c, d, a, b)
}

func sharply_intersecting_segments(a, b, c, d pii) bool {
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b)
}

func line_with_normal_vector_through_point(normal, point pii) (pii, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func serper(a, b pii) (pii, int) {
	p := sub(b, a)
	return add(p, p), -(p.X*a.X + p.Y*a.Y)
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a)*p.Y - (-b)*p.X
	F := p.X*(-a) - q.X*(-b)
	return pdd{E / D, F / D}
}

func circumcenter(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, float64(p1.Y), p2.X, float64(p2.Y))
}

func l_th_2(p, q pii) (pii, int) {
	return pii{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func circle_intersection(a, b pair) []pdd {
	c := sub(b.X, a.X)
	rr1 := int64(a.Y) * int64(a.Y)
	rr2 := int64(b.Y) * int64(b.Y)
	cc := int64(c.X)*int64(c.X) + int64(c.Y)*int64(c.Y)
	rrrr1 := rr1 * rr1
	rrrr2 := rr2 * rr2
	cccc := cc * cc
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1 + rrrr2 + cccc)
	if D >= 0 {
		E := (float64(rr1-rr2)/float64(cc) + 1) / 2
		baza := pdd{float64(a.X.X) + float64(c.X)*E, float64(a.X.Y) + float64(c.Y)*E}
		if D > 0 {
			lll := math.Sqrt(float64(D)) / (2 * math.Sqrt(float64(cc)))
			cr := rot_90(c)
			pmm := pdd{float64(cr.X) * lll, float64(cr.Y) * lll}
			return []pdd{add(baza, pmm), sub(baza, pmm)}
		} else {
			return []pdd{baza}
		}
	} else {
		return []pdd{}
	}
}

func sopr(p pii) pii {
	return pii{p.X, -p.Y}
}

func on_segment(a, b, c pii) bool {
	return are_codirected(sub(b, a), sub(c, b))
}

func perpendicular(line, point pii) (pii, int) {
	return line_with_normal_vector_through_point(rot_90(line), point)
}

func projection(line pair, point pdd) pdd {
	temp := perpendicular(line.X, point)
	return ints(line.X, float64(line.Y), temp.X, float64(temp.Y))
}

func height(a, b, c pdd) pdd {
	return projection(l_th_2(a, c), b)
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

func prod(a, b, M int) int {
	return (int64(a) * int64(b)) % int64(M)
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

func angdis_cmp(a, b pii) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return sq_len(a) < sq_len(b)
	}
}

func find_min_idx(v []pii) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i] < v[ans] {
			ans = i
		}
	}
	return ans
}

func convex_hull(a []pair) []int {
	n := len(a)
	if n > 0 {
		mt := find_min_idx(a)
		d := a[mt]
		for i := 0; i < n; i++ {
			a[i] = sub(a[i], d)
		}

		idx := make([]int, n)
		for i := 0; i < n; i++ {
			idx[i] = i
		}
		sort.Slice(idx, func(i, j int) bool {
			return angdis_cmp(a[idx[i]], a[idx[j]])
		})

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
			a[i] = add(a[i], d)
		}
		return h
	} else {
		return []int{}
	}
}

func count_tro(r int) int {
	ans := 0
	for r > 0 {
		ans++
		r >>= 1
	}
	return ans
}

func unite_seg(p1, p2 pii, n int) pii {
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
	r := count_tro(s.n - 1)
	s.sp = make([][]pii, r)
	for i := 0; i < s.n; i++ {
		s.sp[0][i] = v[i]
	}
	for i := 1; i < r; i++ {
		for j := 0; j < s.n; j++ {
			p1 := s.sp[i-1][j]
			p2 := s.sp[i-1][(j+(1<<(i-1)))%s.n]
			s.sp[i][j] = unite_seg(p1, p2, s.n)
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
	g := count_tro(szz) - 1
	return unite_seg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	if n == 1 {
		fmt.Fprintln(writer, "0")
		return
	}

	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &r[i])
	}

	zz := count_tro(n) + 1
	v := make([]sparse, zz)
	prs := make([]pii, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pii{-1, -1}
		} else {
			prs[i] = unite_seg(pii{raz(i, r[i], n), i}, pii{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		new_prs := make([]pii, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			new_prs[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(new_prs)
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
		fmt.Fprint(writer, ans+1, " ")
	}
	fmt.Fprintln(writer)
}
