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

type pii pair
type pll pair
type pbl pair
type pdd pair

type vpii []pii
type vvpii []vpii
type vpbl []pbl
type vpdd []pdd

type vi []int
type vvi []vi
type vl []int
type vvl []vl
type vb []bool
type vvb []vb

func make_pair(x, y int) pii {
	return pii{x, y}
}

func mp(x, y int) pii {
	return make_pair(x, y)
}

func make_pdd(x, y float64) pdd {
	return pdd{x, y}
}

func make_vpdd(size int) vpdd {
	return make([]pdd, size)
}

func sz(x interface{}) int {
	switch x := x.(type) {
	case vi:
		return len(x)
	case vvi:
		return len(x)
	case vl:
		return len(x)
	case vvl:
		return len(x)
	case vb:
		return len(x)
	case vvb:
		return len(x)
	case vpii:
		return len(x)
	case vvpii:
		return len(x)
	case vpbl:
		return len(x)
	case vpdd:
		return len(x)
	default:
		return -1
	}
}

func getline() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return line
}

func stoi(s string) int {
	var res int
	fmt.Sscanf(s, "%d", &res)
	return res
}

func stof(s string) float64 {
	var res float64
	fmt.Sscanf(s, "%f", &res)
	return res
}

func stov(s string) vi {
	var res vi
	for _, c := range s {
		if c >= '0' && c <= '9' {
			res = append(res, int(c-'0'))
		}
	}
	return res
}

func stovv(s string) vvi {
	var res vvi
	lines := stov(s)
	for _, line := range lines {
		res = append(res, stov(line))
	}
	return res
}

func stovl(s string) vl {
	var res vl
	for _, c := range s {
		if c >= '0' && c <= '9' {
			res = append(res, int(c-'0'))
		}
	}
	return res
}

func stovvl(s string) vvl {
	var res vvl
	lines := stovl(s)
	for _, line := range lines {
		res = append(res, stovl(line))
	}
	return res
}

func stovb(s string) vb {
	var res vb
	for _, c := range s {
		if c == '0' {
			res = append(res, false)
		} else if c == '1' {
			res = append(res, true)
		}
	}
	return res
}

func stovvb(s string) vvb {
	var res vvb
	lines := stovb(s)
	for _, line := range lines {
		res = append(res, stovb(line))
	}
	return res
}

func stovpii(s string) vpii {
	var res vpii
	lines := stov(s)
	for _, line := range lines {
		res = append(res, make_pair(line[0], line[1]))
	}
	return res
}

func stovvpii(s string) vvpii {
	var res vvpii
	lines := stovv(s)
	for _, line := range lines {
		var temp vpii
		for i := 0; i < len(line); i += 2 {
			temp = append(temp, make_pair(line[i], line[i+1]))
		}
		res = append(res, temp)
	}
	return res
}

func stovpbl(s string) vpbl {
	var res vpbl
	lines := stov(s)
	for _, line := range lines {
		res = append(res, make_pair(line[0], line[1]))
	}
	return res
}

func stovpdd(s string) vpdd {
	var res vpdd
	lines := stov(s)
	for _, line := range lines {
		res = append(res, make_pair(line[0], line[1]))
	}
	return res
}

func stovpddf(s string) vpdd {
	var res vpdd
	lines := stov(s)
	for _, line := range lines {
		res = append(res, make_pair(float64(line[0]), float64(line[1])))
	}
	return res
}

func stovpddff(s string) vpdd {
	var res vpdd
	lines := stovv(s)
	for _, line := range lines {
		var temp vpdd
		for i := 0; i < len(line); i += 2 {
			temp = append(temp, make_pair(float64(line[i]), float64(line[i+1])))
		}
		res = append(res, temp)
	}
	return res
}

func stovpddl(s string) vpdd {
	var res vpdd
	lines := stovl(s)
	for _, line := range lines {
		res = append(res, make_pair(float64(line[0]), float64(line[1])))
	}
	return res
}

func stovpddll(s string) vpdd {
	var res vpdd
	lines := stovvl(s)
	for _, line := range lines {
		var temp vpdd
		for i := 0; i < len(line); i += 2 {
			temp = append(temp, make_pair(float64(line[i]), float64(line[i+1])))
		}
		res = append(res, temp)
	}
	return res
}

func stovpddb(s string) vpdd {
	var res vpdd
	lines := stovb(s)
	for _, line := range lines {
		res = append(res, make_pair(float64(line[0]), float64(line[1])))
	}
	return res
}

func stovpddbb(s string) vpdd {
	var res vpdd
	lines := stovvb(s)
	for _, line := range lines {
		var temp vpdd
		for i := 0; i < len(line); i += 2 {
			temp = append(temp, make_pair(float64(line[i]), float64(line[i+1])))
		}
		res = append(res, temp)
	}
	return res
}

func operator_in(fin *bufio.Reader, v *vi) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		fmt.Fscanf(fin, "%d", &(*v)[i])
	}
}

func operator_in_pair(fin *bufio.Reader, p *pii) {
	fmt.Fscanf(fin, "%d %d", &p.X, &p.Y)
}

func operator_in_vector(fin *bufio.Reader, v *vi) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		fmt.Fscanf(fin, "%d", &(*v)[i])
	}
}

func operator_in_vector_pair(fin *bufio.Reader, v *vpii) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		fmt.Fscanf(fin, "%d %d", &(*v)[i].X, &(*v)[i].Y)
	}
}

func operator_in_vector_vector(fin *bufio.Reader, v *vvi) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		operator_in_vector(fin, &(*v)[i])
	}
}

func operator_in_vector_vector_pair(fin *bufio.Reader, v *vvpii) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		operator_in_vector_pair(fin, &(*v)[i])
	}
}

func operator_in_vector_bool(fin *bufio.Reader, v *vb) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		var temp int
		fmt.Fscanf(fin, "%d", &temp)
		(*v)[i] = temp != 0
	}
}

func operator_in_vector_vector_bool(fin *bufio.Reader, v *vvb) {
	n := sz(*v)
	for i := 0; i < n; i++ {
		operator_in_vector_bool(fin, &(*v)[i])
	}
}

func operator_out(fout *bufio.Writer, v vi) {
	n := sz(v)
	for i := 0; i < n; i++ {
		fmt.Fprintf(fout, "%d ", v[i])
	}
	fmt.Fprintln(fout)
}

func operator_out_pair(fout *bufio.Writer, p pii) {
	fmt.Fprintf(fout, "%d %d\n", p.X, p.Y)
}

func operator_out_vector(fout *bufio.Writer, v vi) {
	n := sz(v)
	for i := 0; i < n; i++ {
		fmt.Fprintf(fout, "%d ", v[i])
	}
	fmt.Fprintln(fout)
}

func operator_out_vector_pair(fout *bufio.Writer, v vpii) {
	n := sz(v)
	for i := 0; i < n; i++ {
		fmt.Fprintf(fout, "%d %d\n", v[i].X, v[i].Y)
	}
}

func operator_out_vector_vector(fout *bufio.Writer, v vvi) {
	n := sz(v)
	for i := 0; i < n; i++ {
		operator_out_vector(fout, v[i])
	}
}

func operator_out_vector_vector_pair(fout *bufio.Writer, v vvpii) {
	n := sz(v)
	for i := 0; i < n; i++ {
		operator_out_vector_pair(fout, v[i])
	}
}

func operator_out_vector_bool(fout *bufio.Writer, v vb) {
	n := sz(v)
	for i := 0; i < n; i++ {
		if v[i] {
			fmt.Fprintf(fout, "1 ")
		} else {
			fmt.Fprintf(fout, "0 ")
		}
	}
	fmt.Fprintln(fout)
}

func operator_out_vector_vector_bool(fout *bufio.Writer, v vvb) {
	n := sz(v)
	for i := 0; i < n; i++ {
		operator_out_vector_bool(fout, v[i])
	}
}

func operator_plus(a, b pii) pii {
	return make_pair(a.X+b.X, a.Y+b.Y)
}

func operator_plus_equal(a *pii, b pii) pii {
	a.X += b.X
	a.Y += b.Y
	return *a
}

func operator_minus(a, b pii) pii {
	return make_pair(a.X-b.X, a.Y-b.Y)
}

func operator_minus_unary(a pii) pii {
	return make_pair(-a.X, -a.Y)
}

func operator_minus_equal(a *pii, b pii) pii {
	a.X -= b.X
	a.Y -= b.Y
	return *a
}

func operator_multiply(a, b pii) int {
	return a.X*b.X + a.Y*b.Y
}

func operator_multiply(a, b pii) pii {
	return make_pair(a.X*b.X, a.Y*b.Y)
}

func operator_multiply(a pii, b int) pii {
	return make_pair(a.X*b, a.Y*b)
}

func operator_modulo(a, b pii) int {
	return a.X*b.Y - a.Y*b.X
}

func sq_len(p pii) int {
	return operator_multiply(p, p)
}

func sq_dist(p, q pii) int {
	return sq_len(operator_minus(p, q))
}

func len(p pii) float64 {
	return math.Sqrt(float64(sq_len(p)))
}

func dist(p, q pii) float64 {
	return len(operator_minus(p, q))
}

func is_rhombus(a, b, c, d pii) bool {
	x := sq_dist(a, b)
	y := sq_dist(b, c)
	z := sq_dist(c, d)
	t := sq_dist(d, a)
	return x == y && y == z && z == t
}

func is_rectangle(a, b, c, d pii) bool {
	x := operator_minus(a, b)
	y := operator_minus(b, c)
	z := operator_minus(c, d)
	t := operator_minus(d, a)
	return operator_multiply(x, y) == 0 && operator_multiply(y, z) == 0 && operator_multiply(z, t) == 0 && operator_multiply(t, x) == 0
}

func are_parallel(a, b pii) bool {
	return operator_modulo(a, b) == 0
}

func are_orthogonal(a, b pii) bool {
	return operator_multiply(a, b) == 0
}

func are_codirected(a, b pii) bool {
	return are_parallel(a, b) && operator_multiply(a, b) >= 0
}

func is_parallelogram(a, b, c, d pii) bool {
	return operator_minus(a, b) == operator_minus(d, c)
}

func is_trapezoid(a, b, c, d pii) bool {
	x := operator_minus(a, b)
	z := operator_minus(d, c)
	return are_codirected(x, z)
}

func is_convex_polygon(a, b, c, d pii) bool {
	x := operator_minus(a, b)
	y := operator_minus(b, c)
	z := operator_minus(c, d)
	t := operator_minus(d, a)
	p := operator_modulo(x, y)
	q := operator_modulo(y, z)
	r := operator_modulo(z, t)
	s := operator_modulo(t, x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func nprcs(a, c pii) bool {
	return operator_modulo(a, c) >= 0
}

func nprcs(a, b, c pii) bool {
	return nprcs(operator_minus(a, b), operator_minus(a, c))
}

func npocs(a, c pii) bool {
	return operator_modulo(a, c) <= 0
}

func npocs(a, b, c pii) bool {
	return npocs(operator_minus(a, b), operator_minus(a, c))
}

func prcs(a, c pii) bool {
	return operator_modulo(a, c) > 0
}

func prcs(a, b, c pii) bool {
	return prcs(operator_minus(a, b), operator_minus(a, c))
}

func pocs(a, c pii) bool {
	return operator_modulo(a, c) < 0
}

func pocs(a, b, c pii) bool {
	return pocs(operator_minus(a, b), operator_minus(a, c))
}

func different_sides(a, b, c, d pii) bool {
	x := operator_minus(b, a)
	p := operator_modulo(x, operator_minus(c, b))
	q := operator_modulo(x, operator_minus(d, b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func sharply_different_sides(a, b, c, d pii) bool {
	x := operator_minus(b, a)
	p := operator_modulo(x, operator_minus(c, b))
	q := operator_modulo(x, operator_minus(d, b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func rot_90(p pii) pii {
	return make_pair(-p.Y, p.X)
}

func rot_90(p, c pii) pii {
	return operator_plus(c, rot_90(operator_minus(p, c)))
}

func intersecting_segments(a, b, c, d pii) bool {
	return different_sides(a, b, c, d) && different_sides(c, d, a, b)
}

func sharply_intersecting_segments(a, b, c, d pii) bool {
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b)
}

func line_with_normal_vector_through_point(normal, point pii) (pii, int) {
	return normal, -(operator_multiply(normal, point))
}

func serper(a, b pii) (pii, int) {
	p := operator_minus(b, a)
	return operator_plus(p, p), -(operator_multiply(p, operator_plus(a, b)))
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := operator_modulo(p, q)
	E := operator_modulo(make_pdd(-a, p.Y), make_pdd(-b, q.Y))
	F := operator_modulo(make_pdd(p.X, -a), make_pdd(q.X, -b))
	return make_pdd(E/D, F/D)
}

func circumcenter(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func l_th_2(p, q pii) (pii, int) {
	return make_pair(q.Y-p.Y, p.X-q.X), -operator_modulo(p, q)
}

func circle_intersection(a, b pair[pii, int]) []pdd {
	c := operator_minus(b.X, a.X)
	rr1 := a.Y * a.Y
	rr2 := b.Y * b.Y
	cc := operator_multiply(c, c)
	rrrr1 := rr1 * rr1
	rrrr2 := rr2 * rr2
	cccc := cc * cc
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1+rrrr2+cccc)
	if D >= 0 {
		E := float64(rr1-rr2)/float64(cc) + 1/2
		baza := operator_plus(make_pdd(float64(a.X.X), float64(a.X.Y)), operator_multiply(make_pdd(c.X, c.Y), E))
		if D != 0 {
			lll := math.Sqrt(float64(D)) / (2 * cc)
			cr := rot_90(c)
			pmm := operator_multiply(make_pdd(cr.X, cr.Y), lll)
			return []pdd{operator_plus(baza, pmm), operator_minus(baza, pmm)}
		} else {
			return []pdd{baza}
		}
	} else {
		return []pdd{}
	}
}

func nprcs(a, c pair[pii, int]) bool {
	return operator_modulo(a, c) >= 0
}

func nprcs(a, b, c pair[pii, int]) bool {
	return nprcs(operator_minus(a, b), operator_minus(a, c))
}

func npocs(a, c pair[pii, int]) bool {
	return operator_modulo(a, c) <= 0
}

func npocs(a, b, c pair[pii, int]) bool {
	return npocs(operator_minus(a, b), operator_minus(a, c))
}

func prcs(a, c pair[pii, int]) bool {
	return operator_modulo(a, c) > 0
}

func prcs(a, b, c pair[pii, int]) bool {
	return prcs(operator_minus(a, b), operator_minus(a, c))
}

func pocs(a, c pair[pii, int]) bool {
	return operator_modulo(a, c) < 0
}

func pocs(a, b, c pair[pii, int]) bool {
	return pocs(operator_minus(a, b), operator_minus(a, c))
}

func different_sides(a, b, c, d pair[pii, int]) bool {
	x := operator_minus(b, a)
	p := operator_modulo(x, operator_minus(c, b))
	q := operator_modulo(x, operator_minus(d, b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func sharply_different_sides(a, b, c, d pair[pii, int]) bool {
	x := operator_minus(b, a)
	p := operator_modulo(x, operator_minus(c, b))
	q := operator_modulo(x, operator_minus(d, b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func rot_90(p pair[pii, int]) pair[pii, int] {
	return make_pair(make_pdd(-p.Y, p.X), p.Y)
}

func rot_90(p, c pair[pii, int]) pair[pii, int] {
	return operator_plus(c, rot_90(operator_minus(p, c)))
}

func intersecting_segments(a, b, c, d pair[pii, int]) bool {
	return different_sides(a, b, c, d) && different_sides(c, d, a, b)
}

func sharply_intersecting_segments(a, b, c, d pair[pii, int]) bool {
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b)
}

func line_with_normal_vector_through_point(normal, point pair[pii, int]) (pair[pii, int], int) {
	return normal, -(operator_multiply(normal, point))
}

func serper(a, b pair[pii, int]) (pair[pii, int], int) {
	p := operator_minus(b, a)
	return operator_plus(p, p), -(operator_multiply(p, operator_plus(a, b)))
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := operator_modulo(p, q)
	E := operator_modulo(make_pdd(-a, p.Y), make_pdd(-b, q.Y))
	F := operator_modulo(make_pdd(p.X, -a), make_pdd(q.X, -b))
	return make_pdd(E/D, F/D)
}

func circumcenter(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func l_th_2(p, q pii) (pii, int) {
	return make_pair(q.Y-p.Y, p.X-q.X), -operator_modulo(p, q)
}

func circle_intersection(a, b pair[pii, int]) []pdd {
	c := operator_minus(b.X, a.X)
	rr1 := a.Y * a.Y
	rr2 := b.Y * b.Y
	cc := operator_multiply(c, c)
	rrrr1 := rr1 * rr1
	rrrr2 := rr2 * rr2
	cccc := cc * cc
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1+rrrr2+cccc)
	if D >= 0 {
		E := float64(rr1-rr2)/float64(cc) + 1/2
		baza := operator_plus(make_pdd(float64(a.X.X), float64(a.X.Y)), operator_multiply(make_pdd(c.X, c.Y), E))
		if D != 0 {
			lll := math.Sqrt(float64(D)) / (2 * cc)
			cr := rot_90(c)
			pmm := operator_multiply(make_pdd(cr.X, cr.Y), lll)
			return []pdd{operator_plus(baza, pmm), operator_minus(baza, pmm)}
		} else {
			return []pdd{baza}
		}
	} else {
		return []pdd{}
	}
}

func count_tro(r int) int {
	ans := 0
	for r != 0 {
		ans++
		r >>= 1
	}
	return ans
}

func unite_seg(p1, p2 pii, n int) pii {
	if p1.X == -1 || p2.X == -1 {
		return make_pair(-1, -1)
	}
	np1 := make_pair(0, raz(p1.Y, p1.X, n))
	np2 := make_pair(raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n))
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return make_pair(-1, -1)
		} else {
			return make_pair(sum(np1.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n))
		}
	} else {
		if np2.X <= np1.Y+1 {
			return make_pair(-1, -1)
		} else {
			return make_pair(sum(np2.X, p1.X, n), sum(max(np1.Y, np2.Y), p1.X, n))
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
		return make_pair(-1, -1)
	}
	szz := raz(r, l, s.n)
	if l == r {
		return s.sp[0][l]
	}
	g := count_tro(szz) - 1
	return unite_seg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
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
	zz := count_tro(n) + 1
	v := make([]sparse, zz)
	prs := make([]pii, n)
	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = make_pair(-1, -1)
		} else {
			prs[i] = unite_seg(make_pair(raz(i, r[i], n), i), make_pair(i, sum(i, r[i], n)), n)
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
		my_pr := make_pair(i, i)
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
