package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type pair struct {
	X int
	Y int
}

type pdd struct {
	X float64
	Y float64
}

type pii pair
type vpii []pii
type vvpii []vpii
type pbl struct {
	X bool
	Y int
}
type vpbl []pbl
type pll pair
type vpll []pll
type pdd pair
type vpdd []pdd
type vi []int
type vvi []vi
type vb []bool
type vvb []vb
type vl []int
type vvl []vl
type vd []float64

func make_pair(x int, y int) pii {
	return pii{x, y}
}

func getline(r *bufio.Reader) string {
	str, _ := r.ReadString('\n')
	return str[:len(str)-1]
}

func push_back(v vi, x int) vi {
	return append(v, x)
}

func emplace_back(v vpii, x pii) vpii {
	return append(v, x)
}

func sz(x []int) int {
	return len(x)
}

func unordered_map() map[int]int {
	return make(map[int]int)
}

func unordered_set() map[int]bool {
	return make(map[int]bool)
}

func first(p pii) int {
	return p.X
}

func second(p pii) int {
	return p.Y
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func sqrt(x float64) float64 {
	return math.Sqrt(x)
}

func pow(x float64, y float64) float64 {
	return math.Pow(x, y)
}

func sq(x int) int {
	return x * x
}

func sq_dist(p pii, q pii) int {
	return sq(p.X-q.X) + sq(p.Y-q.Y)
}

func len(p pii) float64 {
	return sqrt(float64(sq_len(p)))
}

func dist(p pii, q pii) float64 {
	return len(sub(p, q))
}

func sub(p pii, q pii) pii {
	return pii{p.X - q.X, p.Y - q.Y}
}

func add(p pii, q pii) pii {
	return pii{p.X + q.X, p.Y + q.Y}
}

func mul(p pii, q pii) int {
	return p.X*q.X + p.Y*q.Y
}

func cross(p pii, q pii) int {
	return p.X*q.Y - p.Y*q.X
}

func sq_len(p pii) int {
	return mul(p, p)
}

func is_rhombus(a pii, b pii, c pii, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a pii, b pii, c pii, d pii) bool {
	x := sub(a, b)
	y := sub(b, c)
	z := sub(c, d)
	t := sub(d, a)
	return mul(x, y) == 0 && mul(y, z) == 0 && mul(z, t) == 0 && mul(t, x) == 0
}

func are_parallel(a pii, b pii) bool {
	return cross(a, b) == 0
}

func are_orthogonal(a pii, b pii) bool {
	return mul(a, b) == 0
}

func are_codirected(a pii, b pii) bool {
	return are_parallel(a, b) && mul(a, b) >= 0
}

func is_parallelogram(a pii, b pii, c pii, d pii) bool {
	return sub(a, b) == sub(d, c)
}

func is_trapezoid(a pii, b pii, c pii, d pii) bool {
	x := sub(a, b)
	z := sub(d, c)
	return are_codirected(x, z)
}

func is_convex_polygon(a pii, b pii, c pii, d pii) bool {
	x := sub(a, b)
	y := sub(b, c)
	z := sub(c, d)
	t := sub(d, a)
	p := cross(x, y)
	q := cross(y, z)
	r := cross(z, t)
	s := cross(t, x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func nprcs(a pii, c pii) bool {
	return cross(a, c) >= 0
}

func nprcs3(a pii, b pii, c pii) bool {
	return nprcs(sub(a, b), sub(a, c))
}

func npocs(a pii, c pii) bool {
	return cross(a, c) <= 0
}

func npocs3(a pii, b pii, c pii) bool {
	return npocs(sub(a, b), sub(a, c))
}

func prcs(a pii, c pii) bool {
	return cross(a, c) > 0
}

func prcs3(a pii, b pii, c pii) bool {
	return prcs(sub(a, b), sub(a, c))
}

func pocs(a pii, c pii) bool {
	return cross(a, c) < 0
}

func pocs3(a pii, b pii, c pii) bool {
	return pocs(sub(a, b), sub(a, c))
}

func different_sides(a pii, b pii, c pii, d pii) bool {
	x := sub(b, a)
	p := cross(x, sub(c, b))
	q := cross(x, sub(d, b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func sharply_different_sides(a pii, b pii, c pii, d pii) bool {
	x := sub(b, a)
	p := cross(x, sub(c, b))
	q := cross(x, sub(d, b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func rot_90(p pii) pii {
	return pii{-p.Y, p.X}
}

func rot_90_center(p pii, c pii) pii {
	return add(c, rot_90(sub(p, c)))
}

func intersecting_segments(a pii, b pii, c pii, d pii) bool {
	return different_sides(a, b, c, d) && different_sides(c, d, a, b)
}

func sharply_intersecting_segments(a pii, b pii, c pii, d pii) bool {
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b)
}

func line_with_normal_vector_through_point(normal pii, point pii) (pii, int) {
	return normal, -mul(normal, point)
}

func serper(a pii, b pii) (pii, int) {
	p := sub(b, a)
	return add(p, p), -mul(p, add(a, b))
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X*b) * -1
	F := (p.Y*a - p.X*b) * -1
	return pdd{E / D, F / D}
}

func circumcenter(x pdd, y pdd, z pdd) pdd {
	p1, _ := serper(x, y)
	p2, _ := serper(x, z)
	return ints(p1, p1.Y, p2, p2.Y)
}

func l_th_2(p pii, q pii) (pii, int) {
	return pii{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func circle_intersection(a pair, b pair) []pdd {
	c := sub(b.X, a.X)
	rr1 := sq(a.Y)
	rr2 := sq(b.Y)
	cc := sq_len(c)
	rrrr1 := sq(rr1)
	rrrr2 := sq(rr2)
	cccc := sq(cc)
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1+rrrr2+cccc)
	if D >= 0 {
		E := (float64(rr1-rr2)/float64(cc) + 1) / 2
		baza := add(pdd{float64(a.X), float64(a.Y)}, mul(pdd{float64(c.X), float64(c.Y)}, E))
		if D > 0 {
			lll := sqrt(float64(D)) / (2 * sqrt(float64(cc)))
			cr := rot_90(c)
			pmm := mul(pdd{float64(cr.X), float64(cr.Y)}, lll)
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

func on_segment(a pii, b pii, c pii) bool {
	return are_codirected(sub(b, a), sub(c, b))
}

func perpendicular(line pii, point pii) (pii, int) {
	return line_with_normal_vector_through_point(rot_90(line), point)
}

func projection(line pair, point pdd) pdd {
	temp := perpendicular(line.X, point)
	return ints(line.X, line.Y, temp.X, temp.Y)
}

func height(a pdd, b pdd, c pdd) pdd {
	return projection(l_th_2(a, c), b)
}

func z_function(s []int) []int {
	n := len(s)
	z := make([]int, n)
	l := 0
	r := 1
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

func euc(m int, n int) (int, int) {
	if n == 0 {
		if m >= 0 {
			return 1, 0
		}
		return -1, 0
	}
	t := m / n
	ans1, ans2 := euc(n, m-t*n)
	return ans2, ans1 - ans2*t
}

func prod(a int, b int, M int) int {
	return (a * b) % M
}

func sum(a int, b int, M int) int {
	c := a + b
	if c >= M {
		return c - M
	}
	return c
}

func raz(a int, b int, M int) int {
	c := a - b
	if c < 0 {
		return c + M
	}
	return c
}

func angdis_cmp(a pii, b pii) bool {
	p := cross(a, b)
	if p != 0 {
		return p > 0
	}
	return sq_len(a) < sq_len(b)
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

func convex_hull(a []pii) []int {
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
	}
	return []int{}
}

func count_tro(r int) int {
	return 32 - bits.LeadingZeros32(uint32(r))
}

func unite_seg(p1 pii, p2 pii, n int) pii {
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
			s.sp[i][j] = unite_seg(p1, p2, s.n)
		}
	}
}

func (s *sparse) segment(l int, r int) pii {
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

	zz := count_tro(n + 1) - 1
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