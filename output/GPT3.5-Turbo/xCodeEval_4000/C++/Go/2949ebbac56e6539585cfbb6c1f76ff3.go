package main

import (
	"fmt"
	"math"
	"sort"
)

type PT struct {
	x, y float64
}

func (p PT) add(o PT) PT {
	return PT{p.x + o.x, p.y + o.y}
}

func (p *PT) addAssign(o PT) {
	p.x += o.x
	p.y += o.y
}

func (p PT) subtract(o PT) PT {
	return PT{p.x - o.x, p.y - o.y}
}

func (p *PT) subtractAssign(o PT) {
	p.x -= o.x
	p.y -= o.y
}

func (p PT) multiply(c float64) PT {
	return PT{p.x * c, p.y * c}
}

func (p *PT) multiplyAssign(c float64) {
	p.x *= c
	p.y *= c
}

func (p PT) divide(c float64) PT {
	return PT{p.x / c, p.y / c}
}

func (p *PT) divideAssign(c float64) {
	p.x /= c
	p.y /= c
}

func (p PT) negative() PT {
	return PT{-p.x, -p.y}
}

func (p PT) lessThan(o PT) bool {
	if math.Abs(p.x-o.x) > 1e-8 {
		return p.x < o.x
	}
	if math.Abs(p.y-o.y) > 1e-8 {
		return p.y < o.y
	}
	return false
}

func (p PT) equals(o PT) bool {
	return math.Abs(p.x-o.x) < 1e-8 && math.Abs(p.y-o.y) < 1e-8
}

func (p PT) notEquals(o PT) bool {
	return math.Abs(p.x-o.x) > 1e-8 || math.Abs(p.y-o.y) > 1e-8
}

func sqr(v float64) float64 {
	return v * v
}

func sgn(v float64) int {
	if v < -1e-8 {
		return -1
	} else if v > 1e-8 {
		return 1
	} else {
		return 0
	}
}

func dis(v PT) float64 {
	return math.Sqrt(sqr(v.x) + sqr(v.y))
}

func dis2(v PT) float64 {
	return sqr(v.x) + sqr(v.y)
}

func disPoints(p1, p2 PT) float64 {
	return dis(p1.subtract(p2))
}

func dis2Points(p1, p2 PT) float64 {
	return dis2(p1.subtract(p2))
}

func vect(v1, v2 PT) float64 {
	return v1.x*v2.y - v2.x*v1.y
}

func vectPoints(p, p1, p2 PT) float64 {
	return vect(p1.subtract(p), p2.subtract(p))
}

func scal(v1, v2 PT) float64 {
	return v1.x*v2.x + v1.y*v2.y
}

func scalPoints(p, p1, p2 PT) float64 {
	return scal(p1.subtract(p), p2.subtract(p))
}

func sect(p PT) int {
	if sgn(p.x) == 0 && sgn(p.y) == 0 {
		return 0
	}
	if sgn(p.x) == 0 {
		if sgn(p.y) > 0 {
			return 2
		} else {
			return 4
		}
	}
	if sgn(p.y) == 0 {
		if sgn(p.x) > 0 {
			return 1
		} else {
			return 3
		}
	}
	if sgn(p.x) == 1 {
		if sgn(p.y) == 1 {
			return 1
		} else {
			return 4
		}
	} else {
		if sgn(p.y) == 1 {
			return 2
		} else {
			return 3
		}
	}
}

func ang(v PT) float64 {
	return math.Atan2(v.y, v.x)
}

func angPoints(p1, p2 PT) float64 {
	return ang(p2.subtract(p1))
}

func angPoints3(p, p1, p2 PT) float64 {
	dy := vectPoints(p, p1, p2)
	dx := scalPoints(p, p1, p2)
	if sgn(dy) == 0 {
		dy = 0
	}
	if sgn(dx) == 0 {
		dx = 0
	}
	return math.Atan2(dy, dx)
}

func ang2(p, p1, p2 PT) float64 {
	return math.Acos(scalPoints(p, p1, p2) / dis(p, p1) / dis(p, p2))
}

func proj(p, p1, p2 PT) PT {
	return p1.add(p2.subtract(p1).multiply(scalPoints(p1, p, p2) / dis2Points(p1, p2)))
}

func rot(v PT, t float64) PT {
	return PT{v.x*math.Cos(t) - v.y*math.Sin(t), v.x*math.Sin(t) + v.y*math.Cos(t)}
}

func rotPoints(p, o PT, t float64) PT {
	return rot(p.subtract(o), t).add(o)
}

func polar(o PT, r, t float64) PT {
	return o.add(PT{r * math.Cos(t), r * math.Sin(t)})
}

func disToLine(p, p1, p2 PT) float64 {
	return math.Abs(vectPoints(p, p1, p2)) / disPoints(p1, p2)
}

func disToSeg(p, p1, p2 PT) float64 {
	if scalPoints(p1, p, p2) < 0 {
		return dis(p, p1)
	}
	if scalPoints(p2, p, p1) < 0 {
		return dis(p, p2)
	}
	return disToLine(p, p1, p2)
}

func onLine(p, p1, p2 PT) bool {
	return sgn(vectPoints(p, p1, p2)) == 0
}

func onSeg(p, p1, p2 PT) bool {
	return onLine(p, p1, p2) && sgn(scalPoints(p, p1, p2)) <= 0
}

func inAngle(p, p0, p1, p2 PT) bool {
	d0 := vectPoints(p0, p1, p2)
	d1 := vectPoints(p0, p1, p)
	d2 := vectPoints(p0, p2, p)
	if sgn(d0) >= 0 {
		return sgn(d1) >= 0 && sgn(d2) <= 0
	}
	return sgn(d1) >= 0 || sgn(d2) <= 0
}

func inConvex(p PT, q []PT, n int) int {
	o := (q[0].add(q[1]).add(q[2])).divide(3)
	if o.equals(p) {
		return 1
	}
	l, h := 0, n
	for h-l > 1 {
		m := (l + h) / 2
		if inAngle(p, o, q[l%n], q[m%n]) {
			h = m
		} else {
			l = m
		}
	}
	l %= n
	h %= n
	if sgn(vectPoints(q[l], q[h], p)) == 0 {
		return 2
	}
	if sgn(vectPoints(q[l], q[h], o)*vectPoints(q[l], q[h], p)) > 0 {
		return 0
	}
	return -1
}

func posLineLine(p1, p2, p3, p4, p *PT) int {
	s1 := vectPoints(p1, p2, p3)
	s2 := vectPoints(p1, p2, p4)
	if sgn(s1-s2) == 0 {
		if sgn(s1) != 0 {
			return 0
		} else {
			return 2
		}
	}
	*p = p3.subtract(p4).multiply(s1 / (s1 - s2)).add(p3)
	return 1
}

func posSegSeg(p1, p2, p3, p4, p *PT) int {
	ret := posLineLine(p1, p2, p3, p4, p)
	if ret == 1 {
		if onSeg(*p, p1, p2) && onSeg(*p, p3, p4) {
			return 1
		}
		if ret == 2 && (onSeg(p1, p3, p4) || onSeg(p2, p3, p4)) {
			return 2
		}
	}
	return 0
}

func inPolygon(p PT, q []PT, n int) int {
	c := 0
	r := PT{INF, INF * math.Sqrt(3)}
	for i := 0; i < n; i++ {
		if onLine(p, q[i], q[(i+1)%n]) {
			return 2
		}
		if posSegSeg(p, r, q[i], q[(i+1)%n], &t) == 1 {
			c++
		}
	}
	return c % 2
}

func posCirLine(o PT, r float64, p1, p2 PT, q []PT) int {
	a := dis2Points(p1, p2)
	b := scalPoints(p1, o, p2)
	c := dis2(o, p1) - sqr(r)
	d2 := sqr(b) - a*c
	if sgn(d2) < 0 {
		return 0
	}
	d := math.Sqrt(math.Abs(d2))
	q[0] = p1.add(p2.subtract(p1).multiply((b + d) / a))
	if sgn(d2) == 0 {
		return 1
	}
	q[1] = p1.add(p2.subtract(p1).multiply((b - d) / a))
	return 2
}

func posCirCir(o1 PT, r1 float64, o2 PT, r2 float64, q []PT) int {
	if o1.equals(o2) {
		if sgn(r1-r2) != 0 {
			return 0
		} else {
			return 3
		}
	}
	d := dis(o1, o2)
	e := (sqr(r1) - sqr(r2) + sqr(d)) / (2 * d)
	f2 := sqr(r1) - sqr(e)
	if sgn(f2) < 0 {
		return 0
	}
	f := math.Sqrt(math.Abs(f2))
	dx := o2.x - o1.x
	dy := o2.y - o1.y
	q[0] = PT{o1.x + (e*dx-f*dy)/d, o1.y + (e*dy+f*dx)/d}
	if sgn(f2) == 0 {
		return 1
	}
	q[1] = PT{o1.x + (e*dx+f*dy)/d, o1.y + (e*dy-f*dx)/d}
	return 2
}

func normalLine(p1, p2 PT) PT {
	return PT{-(p2.y - p1.y), p2.x - p1.x}
}

func innerCenter(a, b, c PT) PT {
	A := dis(b, c)
	B := dis(c, a)
	C := dis(a, b)
	return PT{(A*a.x + B*b.x + C*c.x) / (A + B + C), (A*a.y + B*b.y + C*c.y) / (A + B + C)}
}

func outerCenter(a, b, c PT) PT {
	d1 := (dis2(a) - dis2(b)) / 2
	d2 := (dis2(a) - dis2(c)) / 2
	x := (d1*(a.y-c.y) - d2*(a.y-b.y)) / vectPoints(a.subtract(b), a.subtract(c))
	y := (d1*(a.x-c.x) - d2*(a.x-b.x)) / vectPoints(a.subtract(c), a.subtract(b))
	return PT{x, y}
}

func gravityCenter(p []PT, n int) PT {
	o := PT{}
	for i := 0; i < n; i++ {
		o.addAssign(p[i])
	}
	return o.divide(float64(n))
}

func CircleSharedArea(p1 PT, r1 float64, p2 PT, r2 float64) float64 {
	d := dis(p1.subtract(p2))
	if sgn(d - r1 - r2) >= 0 {
		return 0
	}
	p := (r1 + r2 + d) / 2
	s := math.Sqrt(p * (p - r1) * (p - r2) * (p - d))
	l := 2 * s / d
	return r1*r1*math.Asin(l/r1) + r2*r2*math.Asin(l/r2) - s*2
}

func isSimple(p []PT, n int) bool {
	for i := 0; i < n; i++ {
		for j := i + 3; j < n; j++ {
			if false {
				return false
			}
		}
	}
	return true
}

func isConvex(p []PT, n int) bool {
	for i := 0; i < n; i++ {
		if sgn(vectPoints(p[i], p[(i+1)%n], p[(i+2)%n])) <= 0 {
			return false
		}
	}
	return true
}

func PolygonArea(p []PT, n int) float64 {
	S := 0.0
	for i := 0; i < n; i++ {
		S += vectPoints(p[i], p[(i+1)%n])
	}
	return math.Abs(S) / 2
}

func ConvexHull(p []PT, n int, q []PT) int {
	sort.Slice(p, func(i, j int) bool {
		return p[i].lessThan(p[j])
	})
	n = unique(p, n)
	if n == 1 {
		q[0] = p[0]
		return 1
	}
	m := 0
	for i := 0; i < n; i++ {
		for m >= 2 && sgn(vectPoints(q[m-2], q[m-1], p[i])) <= 0 {
			m--
		}
		q[m] = p[i]
		m++
	}
	m0 := m
	for i := n - 2; i >= 0; i-- {
		for m > m0 && sgn(vectPoints(q[m-2], q[m-1], p[i])) <= 0 {
			m--
		}
		q[m] = p[i]
		m++
	}
	return m - 1
}

type HP struct {
	s, e PT
}

func (h HP) lessThan(o HP) bool {
	if sect(h.e.subtract(h.s)) != sect(o.e.subtract(o.s)) {
		return sect(h.e.subtract(h.s)) < sect(o.e.subtract(o.s))
	}
	d := vect(h.s, h.e, o.e.subtract(o.s).add(h.s))
	return sgn(d) > 0
}

func (h HP) equals(o HP) bool {
	return sgn(vect(h.s, h.e, o.e)) == 0
}

func HalfPlaneIntersection(p []HP, n int) int {
	p = append(p, HP{PT{-INF, -INF}, PT{INF, -INF}})
	p = append(p, HP{PT{INF, -INF}, PT{INF, INF}})
	p = append(p, HP{PT{INF, INF}, PT{-INF, INF}})
	p = append(p, HP{PT{-INF, INF}, PT{-INF, -INF}})
	sort.Slice(p, func(i, j int) bool {
		return p[i].lessThan(p[j])
	})
	n = uniqueHP(p, n)
	l, r := 0, 0
	for i := 0; i < n; i++ {
		var c PT
		for r-l >= 2 {
			posLineLine(p[r-2].s, p[r-2].e, p[r-1].s, p[r-1].e, &c)
			if sgn(vect(p[i].s, p[i].e, c)) > 0 {
				break
			}
			r--
		}
		for r-l >= 2 {
			posLineLine(p[l].s, p[l].e, p[l+1].s, p[l+1].e, &c)
			if sgn(vect(p[i].s, p[i].e, c)) > 0 {
				break
			}
			l++
		}
		if r-l < 2 {
			p[r] = p[i]
			r++
		} else {
			posLineLine(p[r-1].s, p[r-1].e, p[i].s, p[i].e, &c)
			if sgn(vect(p[0].s, p[0].e, c)) > 0 {
				p[r] = p[i]
				r++
			}
		}
	}
	m := 0
	for i := l; i < r; i++ {
		t := INF
		t = math.Min(t, math.Abs(p[i].s.x))
		t = math.Min(t, math.Abs(p[i].s.y))
		t = math.Min(t, math.Abs(p[i].e.x))
		t = math.Min(t, math.Abs(p[i].e.y))
		if sgn(t-INF) != 0 {
			p[m] = p[i]
			m++
		}
	}
	return m
}

func unique(p []PT, n int) int {
	m := 0
	for i := 0; i < n; i++ {
		if i == 0 || p[i].notEquals(p[i-1]) {
			p[m] = p[i]
			m++
		}
	}
	return m
}

func uniqueHP(p []HP, n int) int {
	m := 0
	for i := 0; i < n; i++ {
		if i == 0 || !p[i].equals(p[i-1]) {
			p[m] = p[i]
			m++
		}
	}
	return m
}

const N = 2100
const INF = 1e10

var d [N]float64
var p [N]PT
var v []PT

func cmp1(a, b PT) bool {
	if sect(a) != sect(b) {
		return sect(a) < sect(b)
	}
	d := vect(a, b)
	return sgn(d) > 0
}

func cmp2(a, b PT) bool {
	return sect(a) == sect(b) && sgn(vect(a, b)) == 0
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&p[i].x, &p[i].y)
	}
	g := gravityCenter(p[:n], n)
	for i := 0; i < n; i++ {
		p[i] = p[i].subtract(g)
	}
	sort.Slice(p[:n], func(i, j int) bool {
		return cmp1(p[i], p[j])
	})
	q := PT{}
	for i := 0; i < n; i++ {
		fp := sort.Search(n, func(j int) bool {
			return !p[j].lessThan(p[i])
		})
		if !p[fp].equals(p[i]) {
			q = p[i]
			break
		}
		if i == n-1 {
			fmt.Println("-1")
			return
		}
	}
	for i := 0; i < n; i++ {
		m := (p[i].add(q)).divide(2)
		nv := normalLine(PT{}, m)
		if sect(nv) >= 3 {
			nv = nv.negative()
		}
		v = append(v, nv)
	}
	sort.Slice(v, func(i, j int) bool {
		return cmp1(v[i], v[j])
	})
	v = v[:unique(v, len(v))]
	ans := 0
	for i := 0; i < len(v); i++ {
		for j := 0; j < n; j++ {
			d[j] = scal(v[i], proj(p[j], PT{}, v[i])) / dis(v[i])
		}
		sort.Float64s(d[:n])
		flg := true
		for j := 0; j < n/2; j++ {
			if sgn(d[j]+d[n-1-j]) != 0 {
				flg = false
			}
		}
		if flg {
			ans++
		}
	}
	fmt.Println(ans)
}
