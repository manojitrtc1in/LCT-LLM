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

func mp(x, y int) pair {
	return pair{x, y}
}

func pb(v []int, x int) []int {
	return append(v, x)
}

func sz(x []int) int {
	return len(x)
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func areParallel(a, b pair) bool {
	return a.X*b.Y == a.Y*b.X
}

func areOrthogonal(a, b pair) bool {
	return a.X*b.X+a.Y*b.Y == 0
}

func areCodirected(a, b pair) bool {
	return areParallel(a, b) && a.X*b.X+a.Y*b.Y >= 0
}

func sqLen(p pair) int {
	return p.X*p.X + p.Y*p.Y
}

func sqDist(p, q pair) int {
	return sqLen(pair{p.X - q.X, p.Y - q.Y})
}

func len(p pair) float64 {
	return math.Sqrt(float64(sqLen(p)))
}

func dist(p, q pair) float64 {
	return len(pair{p.X - q.X, p.Y - q.Y})
}

func isRhombus(a, b, c, d pair) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

func isRectangle(a, b, c, d pair) bool {
	x := a.X - b.X
	y := a.Y - b.Y
	z := c.X - b.X
	t := c.Y - b.Y
	return x*y+z*t == 0 && x*z+y*t == 0
}

func isParallelogram(a, b, c, d pair) bool {
	return a.X-b.X == d.X-c.X && a.Y-b.Y == d.Y-c.Y
}

func isTrapezoid(a, b, c, d pair) bool {
	x := a.X - b.X
	y := a.Y - b.Y
	z := d.X - c.X
	t := d.Y - c.Y
	return areCodirected(pair{x, y}, pair{z, t})
}

func isConvexPolygon(a, b, c, d pair) bool {
	x := a.X - b.X
	y := a.Y - b.Y
	z := c.X - b.X
	t := c.Y - b.Y
	p := x*z + y*t
	q := y*z - x*t
	return (p >= 0 && q >= 0) || (p <= 0 && q <= 0)
}

func rot90(p pair) pair {
	return pair{-p.Y, p.X}
}

func rot90WithCenter(p, c pair) pair {
	return pair{c.X + rot90(pair{p.X - c.X, p.Y - c.Y}).X, c.Y + rot90(pair{p.X - c.X, p.Y - c.Y}).Y}
}

func intersectingSegments(a, b, c, d pair) bool {
	return differentSides(a, b, c, d) && differentSides(c, d, a, b)
}

func differentSides(a, b, c, d pair) bool {
	x := pair{b.X - a.X, b.Y - a.Y}
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func sharplyDifferentSides(a, b, c, d pair) bool {
	x := pair{b.X - a.X, b.Y - a.Y}
	p := x.X*(c.Y-b.Y) - x.Y*(c.X-b.X)
	q := x.X*(d.Y-b.Y) - x.Y*(d.X-b.X)
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func lineWithNormalVectorThroughPoint(normal, point pair) (pair, int) {
	return normal, -(normal.X*point.X + normal.Y*point.Y)
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.X*q.Y - p.Y*q.X
	E := (-a*p.Y + p.X)*(-b*q.Y + q.X)
	F := (a*q.X - q.Y)*(p.Y - b*p.X)
	return pdd{E / D, F / D}
}

func circumcenter(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func lth2(p, q pair) (pair, int) {
	return pair{q.Y - p.Y, p.X - q.X}, -p.X*q.Y + p.Y*q.X
}

func circleIntersection(a, b pair) []pdd {
	c := pair{b.X - a.X, b.Y - a.Y}
	rr1 := a.Y*a.Y - a.X*a.X
	rr2 := b.Y*b.Y - b.X*b.X
	cc := c.X*c.X + c.Y*c.Y
	rrrr1 := rr1 * rr1
	rrrr2 := rr2 * rr2
	cccc := cc * cc
	D := 2*(rr1*rr2+rr2*cc+cc*rr1) - (rrrr1 + rrrr2 + cccc)
	if D >= 0 {
		E := (float64(rr1-rr2)/float64(cc) + 1) / 2
		baza := pdd{float64(a.X) + float64(c.X)*E, float64(a.Y) + float64(c.Y)*E}
		if D > 0 {
			lll := math.Sqrt(float64(D)) / (2 * math.Sqrt(float64(cc)))
			cr := rot90(c)
			pmm := pdd{float64(cr.X) * lll, float64(cr.Y) * lll}
			return []pdd{pdd{baza.X + pmm.X, baza.Y + pmm.Y}, pdd{baza.X - pmm.X, baza.Y - pmm.Y}}
		} else {
			return []pdd{baza}
		}
	} else {
		return []pdd{}
	}
}

func serper(a, b pair) (pair, int) {
	p := pair{b.X - a.X, b.Y - a.Y}
	return pair{p.X + p.X, -p.X*a.X - p.Y*a.Y}, p.X*a.Y - p.Y*a.X
}

func projection(line pair, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line, 0, temp.X, temp.Y)
}

func height(a, b, c pdd) pdd {
	return projection(lth2(a, c), b)
}

func findMinIdx(v []int) int {
	ans := 0
	n := len(v)
	for i := 1; i < n; i++ {
		if v[i] < v[ans] {
			ans = i
		}
	}
	return ans
}

func convexHull(a []pair) []int {
	n := len(a)
	if n > 0 {
		mt := findMinIdx(a)
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
			return angdisCmp(a[idx[i]], a[idx[j]])
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

func angdisCmp(a, b pair) bool {
	p := a.X*b.Y - a.Y*b.X
	if p != 0 {
		return p > 0
	} else {
		return sqLen(a) < sqLen(b)
	}
}

func nprcs(a, c pair) bool {
	return a.X*c.Y-a.Y*c.X >= 0
}

func npocs(a, c pair) bool {
	return a.X*c.Y-a.Y*c.X <= 0
}

func prcs(a, c pair) bool {
	return a.X*c.Y-a.Y*c.X > 0
}

func pocs(a, c pair) bool {
	return a.X*c.Y-a.Y*c.X < 0
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

	zz := count_tro(n-1) + 1
	v := make([]sparse, zz)
	prs := make([]pair, n)

	for i := 0; i < n; i++ {
		if r[i] >= n-1 {
			prs[i] = pair{-1, -1}
		} else {
			prs[i] = uniteSeg(pair{raz(i, r[i], n), i}, pair{i, sum(i, r[i], n)}, n)
		}
	}

	v[0].construct(prs)

	for i := 1; i < zz; i++ {
		newPrs := make([]pair, n)
		for j := 0; j < n; j++ {
			pairr := v[i-1].segment(j, j)
			newPrs[j] = v[i-1].segment(pairr.X, pairr.Y)
		}
		v[i].construct(newPrs)
	}

	for i := 0; i < n; i++ {
		myPr := pair{i, i}
		ans := 0
		for j := zz - 1; j >= 0; j-- {
			newPr := v[j].segment(myPr.X, myPr.Y)
			if newPr.X != -1 {
				ans += 1 << j
				myPr = newPr
			}
		}
		fmt.Fprint(writer, ans+1, " ")
	}
	fmt.Fprintln(writer)
}

type sparse struct {
	n  int
	sp [][]pair
}

func (s *sparse) construct(v []pair) {
	s.n = len(v)
	r := count_tro(s.n - 1)
	s.sp = make([][]pair, r)
	for i := 0; i < r; i++ {
		s.sp[i] = make([]pair, s.n)
	}
	for i := 0; i < s.n; i++ {
		s.sp[0][i] = v[i]
	}
	for i := 1; i < r; i++ {
		for j := 0; j < s.n; j++ {
			p1 := s.sp[i-1][j]
			p2 := s.sp[i-1][(j+(1<<(i-1)))%s.n]
			s.sp[i][j] = uniteSeg(p1, p2, s.n)
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
	g := count_tro(szz) - 1
	return uniteSeg(s.sp[g][l], s.sp[g][((r+1-(1<<g))%s.n+s.n)%s.n], s.n)
}

func uniteSeg(p1, p2 pair, n int) pair {
	if p1.X == -1 || p2.X == -1 {
		return pair{-1, -1}
	}
	np1 := pair{0, raz(p1.Y, p1.X, n)}
	np2 := pair{raz(p2.X, p1.X, n), raz(p2.Y, p1.X, n)}
	if np2.X <= np2.Y {
		if np2.Y == n-1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np1.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	} else {
		if np2.X <= np1.Y+1 {
			return pair{-1, -1}
		} else {
			return pair{sum(np2.X, p1.X, n), sum(int(math.Max(float64(np1.Y), float64(np2.Y))), p1.X, n)}
		}
	}
}

func count_tro(r int) int {
	return 32 - int(math.Log2(float64(r)))
}
