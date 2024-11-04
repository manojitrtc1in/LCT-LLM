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

func (p PT) sub(o PT) PT {
	return PT{p.x - o.x, p.y - o.y}
}

func (p *PT) subAssign(o PT) {
	p.x -= o.x
	p.y -= o.y
}

func (p PT) mul(c float64) PT {
	return PT{p.x * c, p.y * c}
}

func (p *PT) mulAssign(c float64) {
	p.x *= c
	p.y *= c
}

func (p PT) div(c float64) PT {
	return PT{p.x / c, p.y / c}
}

func (p *PT) divAssign(c float64) {
	p.x /= c
	p.y /= c
}

func (p PT) neg() PT {
	return PT{-p.x, -p.y}
}

func (p PT) equals(o PT) bool {
	return math.Abs(p.x-o.x) < EPS && math.Abs(p.y-o.y) < EPS
}

func (p PT) notEquals(o PT) bool {
	return !p.equals(o)
}

func (p PT) lessThan(o PT) bool {
	if math.Abs(p.x-o.x) > EPS {
		return p.x < o.x
	}
	return p.y < o.y
}

func (p PT) length() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y)
}

func (p PT) lengthSquared() float64 {
	return p.x*p.x + p.y*p.y
}

func (p PT) distance(o PT) float64 {
	return p.sub(o).length()
}

func (p PT) distanceSquared(o PT) float64 {
	return p.sub(o).lengthSquared()
}

func (p PT) vect(o PT) float64 {
	return p.x*o.y - o.x*p.y
}

func (p PT) scal(o PT) float64 {
	return p.x*o.x + p.y*o.y
}

func (p PT) onLine(p1, p2 PT) bool {
	return math.Abs(p.vect(p1, p2)) < EPS
}

func (p PT) onSegment(p1, p2 PT) bool {
	return p.onLine(p1, p2) && p.scal(p1, p2) <= 0
}

func (p PT) inAngle(p0, p1, p2 PT) bool {
	d0 := p.vect(p0, p1, p2)
	d1 := p.vect(p0, p1, p)
	d2 := p.vect(p0, p2, p)
	if d0 >= 0 {
		return d1 >= 0 && d2 <= 0
	}
	return d1 >= 0 || d2 <= 0
}

func (p PT) id12(q []PT, n int) int {
	o := (q[0].add(q[1]).add(q[2])).div(3)
	if o.equals(p) {
		return 1
	}
	l, h := 0, n
	for h-l > 1 {
		m := (l + h) / 2
		if p.inAngle(o, q[l%n], q[m%n]) {
			h = m
		} else {
			l = m
		}
	}
	l %= n
	h %= n
	if math.Abs(p.vect(q[l], q[h], p)) < EPS {
		return 2
	}
	if p.vect(q[l], q[h], o)*p.vect(q[l], q[h], p) > 0 {
		return -1
	}
	return 0
}

func (p PT) id6(p1, p2, p3, p4 PT) (int, PT) {
	s1 := p.vect(p1, p2, p3)
	s2 := p.vect(p1, p2, p4)
	if math.Abs(s1-s2) < EPS {
		if math.Abs(s1) < EPS {
			return 2, PT{}
		}
		return 0, PT{}
	}
	return 1, p3.sub(p4).mul(s1 / (s1 - s2)).add(p4)
}

func (p PT) id0(p1, p2, p3, p4 PT) (int, PT) {
	ret, q := p.id6(p1, p2, p3, p4)
	if ret == 1 && p.onSegment(q, p1, p2) && p.onSegment(q, p3, p4) {
		return 2, q
	}
	return ret, PT{}
}

func (p PT) inPolygon(q []PT, n int) int {
	c := 0
	r := PT{INF, INF * math.Sqrt(3)}
	for i := 0; i < n; i++ {
		if p.onLine(q[i], q[(i+1)%n]) {
			return 2
		}
		ret, _ := p.id0(r, q[i], q[(i+1)%n], q[(i+2)%n])
		if ret == 1 {
			c++
		}
	}
	return c % 2
}

func (p PT) id7(o PT, r float64, p1, p2 PT, q []PT) int {
	a := p1.distanceSquared(p2)
	b := p1.scal(o, p2)
	c := p1.distanceSquared(o) - r*r
	d2 := b*b - a*c
	if d2 < 0 {
		return 0
	}
	d := math.Sqrt(math.Abs(d2))
	if q != nil {
		q[0] = p1.add(p2.sub(p1).mul((b + d) / a))
	}
	if d2 == 0 {
		return 1
	}
	if q != nil {
		q[1] = p1.add(p2.sub(p1).mul((b - d) / a))
	}
	return 2
}

func (p PT) id3(o1 PT, r1 float64, o2 PT, r2 float64, q []PT) int {
	if o1.equals(o2) {
		if math.Abs(r1-r2) < EPS {
			return 3
		}
		return 0
	}
	d := o1.distance(o2)
	e := (o1.distanceSquared() - o2.distanceSquared() + d*d) / (2 * d)
	f2 := r1*r1 - e*e
	if f2 < 0 {
		return 0
	}
	f := math.Sqrt(math.Abs(f2))
	dx := o2.x - o1.x
	dy := o2.y - o1.y
	if q != nil {
		q[0] = PT{o1.x + (e*dx-f*dy)/d, o1.y + (e*dy+f*dx)/d}
	}
	if f2 == 0 {
		return 1
	}
	if q != nil {
		q[1] = PT{o1.x + (e*dx+f*dy)/d, o1.y + (e*dy-f*dx)/d}
	}
	return 2
}

func (p PT) normalLine(p1, p2 PT) PT {
	return PT{-(p2.y - p1.y), p2.x - p1.x}
}

func (p PT) innerCenter(a, b, c PT) PT {
	A := b.distance(c)
	B := c.distance(a)
	C := a.distance(b)
	return PT{(A*a.x + B*b.x + C*c.x) / (A + B + C), (A*a.y + B*b.y + C*c.y) / (A + B + C)}
}

func (p PT) outerCenter(a, b, c PT) PT {
	d1 := (a.distanceSquared() - b.distanceSquared()) / 2
	d2 := (a.distanceSquared() - c.distanceSquared()) / 2
	x := (d1*(a.y-c.y) - d2*(a.y-b.y)) / p.vect(a.sub(b), a.sub(c))
	y := (d1*(a.x-c.x) - d2*(a.x-b.x)) / p.vect(a.sub(c), a.sub(b))
	return PT{x, y}
}

func (p PT) gravityCenter(points []PT, n int) PT {
	o := PT{}
	for i := 0; i < n; i++ {
		o.addAssign(points[i])
	}
	return o.div(float64(n))
}

func (p PT) id9(p1 PT, r1 float64, p2 PT, r2 float64) float64 {
	d := p1.distance(p2)
	if d >= r1+r2 {
		return 0
	}
	p := (r1 + r2 + d) / 2
	s := math.Sqrt(p * (p - r1) * (p - r2) * (p - d))
	l := 2 * s / d
	return r1*r1*math.Asin(l/r1) + r2*r2*math.Asin(l/r2) - s*2
}

func isSimple(points []PT, n int) bool {
	for i := 0; i < n; i++ {
		for j := i + 3; j < n; j++ {
			if points[i].equals(points[j]) {
				return false
			}
		}
	}
	return true
}

func id1(points []PT, n int) bool {
	for i := 0; i < n; i++ {
		if points[i].vect(points[(i+1)%n], points[(i+2)%n]) <= 0 {
			return false
		}
	}
	return true
}

func id10(points []PT, n int) float64 {
	S := 0.0
	for i := 0; i < n; i++ {
		S += points[i].vect(points[(i+1)%n])
	}
	return math.Abs(S) / 2
}

func id5(points []PT, n int) []PT {
	sort.Slice(points, func(i, j int) bool {
		if points[i].sect() != points[j].sect() {
			return points[i].sect() < points[j].sect()
		}
		return points[i].vect(points[j]) > 0
	})
	v := make([]PT, 0)
	for i := 0; i < n; i++ {
		for m := len(v); m >= 2 && points[i].vect(v[m-2], v[m-1]) <= 0; m-- {
			v = v[:m-1]
		}
		v = append(v, points[i])
	}
	for i := n - 2; i >= 0; i-- {
		for m := len(v); m > len(v)-2 && points[i].vect(v[m-2], v[m-1]) <= 0; m-- {
			v = v[:m-1]
		}
		v = append(v, points[i])
	}
	return v
}

type HP struct {
	s, e PT
}

func (h HP) lessThan(o HP) bool {
	if h.e.sect() != o.e.sect() {
		return h.e.sect() < o.e.sect()
	}
	d := h.e.vect(o.e.sub(o.s).add(h.s))
	return d > 0
}

func (h HP) equals(o HP) bool {
	return math.Abs(h.s.vect(h.e.sub(h.s).add(o.s))) < EPS
}

func id4(hp []HP, n int) int {
	hp = append(hp, HP{PT{-INF, -INF}, PT{INF, -INF}})
	hp = append(hp, HP{PT{INF, -INF}, PT{INF, INF}})
	hp = append(hp, HP{PT{INF, INF}, PT{-INF, INF}})
	hp = append(hp, HP{PT{-INF, INF}, PT{-INF, -INF}})
	sort.Slice(hp, func(i, j int) bool {
		if hp[i].e.sect() != hp[j].e.sect() {
			return hp[i].e.sect() < hp[j].e.sect()
		}
		d := hp[i].e.vect(hp[j].e.sub(hp[j].s).add(hp[i].s))
		return d > 0
	})
	m := 0
	for i := 0; i < len(hp); i++ {
		t := INF
		t = math.Min(t, math.Abs(hp[i].s.x))
		t = math.Min(t, math.Abs(hp[i].s.y))
		t = math.Min(t, math.Abs(hp[i].e.x))
		t = math.Min(t, math.Abs(hp[i].e.y))
		if math.Abs(t-INF) > EPS {
			hp[m] = hp[i]
			m++
		}
	}
	return m
}

type PT3 struct {
	x, y, z float64
}

func (p PT3) add(o PT3) PT3 {
	return PT3{p.x + o.x, p.y + o.y, p.z + o.z}
}

func (p *PT3) addAssign(o PT3) {
	p.x += o.x
	p.y += o.y
	p.z += o.z
}

func (p PT3) sub(o PT3) PT3 {
	return PT3{p.x - o.x, p.y - o.y, p.z - o.z}
}

func (p *PT3) subAssign(o PT3) {
	p.x -= o.x
	p.y -= o.y
	p.z -= o.z
}

func (p PT3) mul(c float64) PT3 {
	return PT3{p.x * c, p.y * c, p.z * c}
}

func (p *PT3) mulAssign(c float64) {
	p.x *= c
	p.y *= c
	p.z *= c
}

func (p PT3) div(c float64) PT3 {
	return PT3{p.x / c, p.y / c, p.z / c}
}

func (p *PT3) divAssign(c float64) {
	p.x /= c
	p.y /= c
	p.z /= c
}

func (p PT3) equals(o PT3) bool {
	return math.Abs(p.x-o.x) < EPS && math.Abs(p.y-o.y) < EPS && math.Abs(p.z-o.z) < EPS
}

func (p PT3) notEquals(o PT3) bool {
	return !p.equals(o)
}

func (p PT3) lessThan(o PT3) bool {
	if math.Abs(p.x-o.x) > EPS {
		return p.x < o.x
	}
	if math.Abs(p.y-o.y) > EPS {
		return p.y < o.y
	}
	return p.z < o.z
}

func (p PT3) length() float64 {
	return math.Sqrt(p.x*p.x + p.y*p.y + p.z*p.z)
}

func (p PT3) lengthSquared() float64 {
	return p.x*p.x + p.y*p.y + p.z*p.z
}

func (p PT3) distance(o PT3) float64 {
	return p.sub(o).length()
}

func (p PT3) distanceSquared(o PT3) float64 {
	return p.sub(o).lengthSquared()
}

func (p PT3) vect(o PT3) PT3 {
	return PT3{p.x*o.y - o.x*p.y, -(p.x*o.z - o.x*p.z), p.x*o.y - o.x*p.y}
}

func (p PT3) scal(o PT3) float64 {
	return p.x*o.x + p.y*o.y + p.z*o.z
}

func id11(p PT3, a, b, c, d float64) float64 {
	return math.Abs(a*p.x + b*p.y + c*p.z + d) / math.Sqrt(a*a+b*b+c*c)
}

const (
	INF = 1e10
	EPS = 1e-8
)

func solve() {
	var n int
	fmt.Scan(&n)
	points := make([]PT, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&points[i].x, &points[i].y)
	}
	g := PT{}.gravityCenter(points, n)
	for i := 0; i < n; i++ {
		points[i].subAssign(g)
	}
	sort.Slice(points, func(i, j int) bool {
		if points[i].lessThan(-points[j]) {
			return true
		}
		return false
	})
	var q PT
	for i := 0; i < n; i++ {
		fp := sort.Search(n, func(j int) bool {
			return points[j].lessThan(-points[i])
		})
		if !points[fp].equals(-points[i]) {
			q = points[i]
			break
		}
		if i == n-1 {
			fmt.Println("-1")
			return
		}
	}
	v := make([]PT, 0)
	for i := 0; i < n; i++ {
		m := points[i].add(q).div(2)
		nv := PT{}.normalLine(PT{}, m)
		if nv.sect() >= 3 {
			nv = nv.neg()
		}
		v = append(v, nv)
	}
	sort.Slice(v, func(i, j int) bool {
		if v[i].sect() != v[j].sect() {
			return v[i].sect() < v[j].sect()
		}
		return v[i].vect(v[j]) > 0
	})
	m := 0
	for i := 0; i < len(v); i++ {
		for m >= 2 && v[i].vect(v[m-2], v[m-1]) <= 0 {
			m--
		}
		v[m] = v[i]
		m++
	}
	v = v[:m]
	ans := 0
	for i := 0; i < len(v); i++ {
		d := make([]float64, n)
		for j := 0; j < n; j++ {
			d[j] = v[i].scal(v[i].proj(points[j], PT{}, v[i])) / v[i].length()
		}
		sort.Float64s(d)
		flg := true
		for j := 0; j < n/2; j++ {
			if math.Abs(d[j]+d[n-1-j]) > EPS {
				flg = false
				break
			}
		}
		if flg {
			ans++
		}
	}
	fmt.Println(ans)
}

func main() {
	solve()
}
