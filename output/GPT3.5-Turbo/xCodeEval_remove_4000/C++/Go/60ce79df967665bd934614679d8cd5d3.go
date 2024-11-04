package main

import (
	"fmt"
	"math"
)

const (
	eps = 1e-8
	pi  = math.Acos(-1.0)
)

func dblcmp(d float64) int {
	if math.Abs(d) < eps {
		return 0
	}
	if d > eps {
		return 1
	}
	return -1
}

type point struct {
	x, y float64
}

func (p point) input() {
	fmt.Scanf("%lf%lf", &p.x, &p.y)
}

func (p point) output() {
	fmt.Printf("%.12f %.12f\n", p.x, p.y)
}

func (p point) equal(a point) bool {
	return dblcmp(a.x-p.x) == 0 && dblcmp(a.y-p.y) == 0
}

func (p point) less(a point) bool {
	if dblcmp(a.x-p.x) == 0 {
		return dblcmp(p.y-a.y) < 0
	}
	return p.x < a.x
}

func (p point) len() float64 {
	return math.Hypot(p.x, p.y)
}

func (p point) len2() float64 {
	return p.x*p.x + p.y*p.y
}

func (p point) distance(q point) float64 {
	return math.Hypot(p.x-q.x, p.y-q.y)
}

func (p point) add(q point) point {
	return point{p.x + q.x, p.y + q.y}
}

func (p point) sub(q point) point {
	return point{p.x - q.x, p.y - q.y}
}

func (p point) mul(b float64) point {
	return point{p.x * b, p.y * b}
}

func (p point) div(b float64) point {
	return point{p.x / b, p.y / b}
}

func (p point) dot(q point) float64 {
	return p.x*q.x + p.y*q.y
}

func (p point) det(q point) float64 {
	return p.x*q.y - p.y*q.x
}

func (p point) rad(a, b point) float64 {
	v := p.sub(a)
	c := math.Acos(v.dot(p.sub(b)) / (v.len() * (p.sub(b)).len()))
	return c
}

func (p point) trunc(r float64) point {
	l := p.len()
	if dblcmp(l) == 0 {
		return p
	}
	r /= l
	return point{p.x * r, p.y * r}
}

func (p point) rotleft() point {
	return point{-p.y, p.x}
}

func (p point) rotright() point {
	return point{p.y, -p.x}
}

func (p point) rotate(q point, angle float64) point {
	v := p.sub(q)
	c := math.Cos(angle)
	s := math.Sin(angle)
	return point{q.x + v.x*c - v.y*s, q.y + v.x*s + v.y*c}
}

type line struct {
	a, b point
}

func (l line) equal(v line) bool {
	return l.a.equal(v.a) && l.b.equal(v.b)
}

func (l line) adjust() {
	if l.b.less(l.a) {
		l.a, l.b = l.b, l.a
	}
}

func (l line) length() float64 {
	return l.a.distance(l.b)
}

func (l line) angle() float64 {
	k := math.Atan2(l.b.y-l.a.y, l.b.x-l.a.x)
	if dblcmp(k) < 0 {
		k += pi
	}
	if dblcmp(k-pi) == 0 {
		k -= pi
	}
	return k
}

func (l line) relation(p point) int {
	c := dblcmp(p.sub(l.a).det(l.b.sub(l.a)))
	if c < 0 {
		return 1
	}
	if c > 0 {
		return 2
	}
	return 3
}

func (l line) pointonseg(p point) bool {
	return dblcmp(p.sub(l.a).det(l.b.sub(l.a))) == 0 && dblcmp(p.sub(l.a).dot(p.sub(l.b))) <= 0
}

func (l line) parallel(v line) bool {
	return dblcmp(l.b.sub(l.a).det(v.b.sub(v.a))) == 0
}

func (l line) segcrossseg(v line) int {
	d1 := dblcmp(l.b.sub(l.a).det(v.a.sub(l.a)))
	d2 := dblcmp(l.b.sub(l.a).det(v.b.sub(l.a)))
	d3 := dblcmp(v.b.sub(v.a).det(l.a.sub(v.a)))
	d4 := dblcmp(v.b.sub(v.a).det(l.b.sub(v.a)))
	if (d1^d2) == -2 && (d3^d4) == -2 {
		return 2
	}
	if (d1 == 0 && dblcmp(v.a.sub(l.a).dot(v.a.sub(l.b))) <= 0) ||
		(d2 == 0 && dblcmp(v.b.sub(l.a).dot(v.b.sub(l.b))) <= 0) ||
		(d3 == 0 && dblcmp(l.a.sub(v.a).dot(l.a.sub(v.b))) <= 0) ||
		(d4 == 0 && dblcmp(l.b.sub(v.a).dot(l.b.sub(v.b))) <= 0) {
		return 1
	}
	return 0
}

func (l line) linecrossseg(v line) int {
	d1 := dblcmp(l.b.sub(l.a).det(v.a.sub(l.a)))
	d2 := dblcmp(l.b.sub(l.a).det(v.b.sub(l.a)))
	if (d1^d2) == -2 {
		return 2
	}
	if d1 == 0 || d2 == 0 {
		return 1
	}
	return 0
}

func (l line) linecrossline(v line) int {
	if l.parallel(v) {
		if v.relation(l.a) == 3 {
			return 1
		}
		return 0
	}
	return 2
}

func (l line) crosspoint(v line) point {
	a1 := v.b.sub(v.a).det(l.a.sub(v.a))
	a2 := v.b.sub(v.a).det(l.b.sub(v.a))
	return point{(l.a.x*a2 - l.b.x*a1) / (a2 - a1), (l.a.y*a2 - l.b.y*a1) / (a2 - a1)}
}

func (l line) dispointtoline(p point) float64 {
	return math.Abs(p.sub(l.a).det(l.b.sub(l.a))) / l.length()
}

func (l line) dispointtoseg(p point) float64 {
	if dblcmp(p.sub(l.b).dot(l.a.sub(l.b))) < 0 || dblcmp(p.sub(l.a).dot(l.b.sub(l.a))) < 0 {
		return math.Min(p.distance(l.a), p.distance(l.b))
	}
	return l.dispointtoline(p)
}

func (l line) lineprog(p point) point {
	return l.a.add(l.b.sub(l.a).mul(l.b.sub(l.a).dot(p.sub(l.a)) / l.b.sub(l.a).len2()))
}

func (l line) symmetrypoint(p point) point {
	q := l.lineprog(p)
	return point{2*q.x - p.x, 2*q.y - p.y}
}

type circle struct {
	p point
	r float64
}

func (c circle) equal(v circle) bool {
	return c.p.equal(v.p) && dblcmp(c.r-v.r) == 0
}

func (c circle) less(v circle) bool {
	if c.p.less(v.p) {
		return true
	}
	if c.p.equal(v.p) && dblcmp(c.r-v.r) < 0 {
		return true
	}
	return false
}

func (c circle) area() float64 {
	return pi * c.r * c.r
}

func (c circle) circumference() float64 {
	return 2 * pi * c.r
}

func (c circle) relation(p point) int {
	d := p.distance(c.p)
	if dblcmp(d-c.r) < 0 {
		return 2
	}
	if dblcmp(d-c.r) == 0 {
		return 1
	}
	return 0
}

func (c circle) relationseg(l line) int {
	d := l.dispointtoseg(c.p)
	if dblcmp(d-c.r) < 0 {
		return 2
	}
	if dblcmp(d-c.r) == 0 {
		return 1
	}
	return 0
}

func (c circle) relationline(l line) int {
	d := l.dispointtoline(c.p)
	if dblcmp(d-c.r) < 0 {
		return 2
	}
	if dblcmp(d-c.r) == 0 {
		return 1
	}
	return 0
}

func (c circle) getcircle(a, b point, r float64) (circle, circle) {
	x := circle{a, r}
	y := circle{b, r}
	var c1, c2 circle
	t := x.pointcrosscircle(y, &c1.p, &c2.p)
	if t == 0 {
		return c1, c2
	}
	c1.r = r
	c2.r = r
	return c1, c2
}

func (c circle) getcircle1(l line, q point, r1 float64) (circle, circle) {
	dis := l.dispointtoline(q)
	if dblcmp(dis-r1*2) > 0 {
		return circle{}, circle{}
	}
	if dblcmp(dis) == 0 {
		c1 := circle{q.add(l.b.sub(l.a).rotleft().trunc(r1)), r1}
		c2 := circle{q.add(l.b.sub(l.a).rotright().trunc(r1)), r1}
		return c1, c2
	}
	u1 := line{l.a.add(l.b.sub(l.a).rotleft().trunc(r1)), l.b.add(l.b.sub(l.a).rotleft().trunc(r1))}
	u2 := line{l.a.add(l.b.sub(l.a).rotright().trunc(r1)), l.b.add(l.b.sub(l.a).rotright().trunc(r1))}
	cc := circle{q, r1}
	var p1, p2 point
	if !cc.pointcrossline(u1, &p1, &p2) {
		cc.pointcrossline(u2, &p1, &p2)
	}
	c1 := circle{p1, r1}
	if p1.equal(p2) {
		c2 := c1
		return c1, c2
	}
	c2 := circle{p2, r1}
	return c1, c2
}

func (c circle) getcircle2(u, v line, r1 float64) (circle, circle, circle, circle) {
	if u.parallel(v) {
		return circle{}, circle{}, circle{}, circle{}
	}
	u1 := line{u.a.add(u.b.sub(u.a).rotleft().trunc(r1)), u.b.add(u.b.sub(u.a).rotleft().trunc(r1))}
	u2 := line{u.a.add(u.b.sub(u.a).rotright().trunc(r1)), u.b.add(u.b.sub(u.a).rotright().trunc(r1))}
	v1 := line{v.a.add(v.b.sub(v.a).rotleft().trunc(r1)), v.b.add(v.b.sub(v.a).rotleft().trunc(r1))}
	v2 := line{v.a.add(v.b.sub(v.a).rotright().trunc(r1)), v.b.add(v.b.sub(v.a).rotright().trunc(r1))}
	c1 := circle{u1.crosspoint(v1), r1}
	c2 := circle{u1.crosspoint(v2), r1}
	c3 := circle{u2.crosspoint(v1), r1}
	c4 := circle{u2.crosspoint(v2), r1}
	return c1, c2, c3, c4
}

func (c circle) getcircle3(cx, cy circle, r1 float64) (circle, circle) {
	x := circle{cx.p, r1 + cx.r}
	y := circle{cy.p, r1 + cy.r}
	var c1, c2 circle
	t := x.pointcrosscircle(y, &c1.p, &c2.p)
	if t == 0 {
		return c1, c2
	}
	c1.r = r1
	c2.r = r1
	return c1, c2
}

func (c circle) pointcrossline(l line, p1, p2 *point) bool {
	if !c.relationline(l) {
		return false
	}
	a := l.lineprog(c.p)
	d := l.dispointtoline(c.p)
	d = math.Sqrt(c.r*c.r - d*d)
	if dblcmp(d) == 0 {
		*p1 = a
		*p2 = a
		return true
	}
	*p1 = a.sub(l.b.sub(l.a).trunc(d))
	*p2 = a.add(l.b.sub(l.a).trunc(d))
	return true
}

func (c circle) pointcrosscircle(v circle, p1, p2 *point) int {
	rel := c.relationcircle(v)
	if rel == 1 || rel == 5 {
		return 0
	}
	d := c.p.distance(v.p)
	l := (d + (c.r*c.r-v.r*v.r)/d) / 2.0
	h := math.Sqrt(c.r*c.r - l*l)
	*p1 = c.p.add(v.p.sub(c.p).trunc(l).add(v.p.sub(c.p).rotleft().trunc(h)))
	*p2 = c.p.add(v.p.sub(c.p).trunc(l).add(v.p.sub(c.p).rotright().trunc(h)))
	if rel == 2 || rel == 4 {
		return 1
	}
	return 2
}

func (c circle) tangentline(q point, u, v *line) int {
	x := c.relation(q)
	if x == 2 {
		return 0
	}
	if x == 1 {
		*u = line{q, q.add(q.sub(c.p).rotleft())}
		*v = *u
		return 1
	}
	d := c.p.distance(q)
	l := sqr(c.r) / d
	h := math.Sqrt(sqr(c.r) - sqr(l))
	*u = line{q, c.p.add(q.sub(c.p).trunc(l).add(q.sub(c.p).rotleft().trunc(h)))}
	*v = line{q, c.p.add(q.sub(c.p).trunc(l).add(q.sub(c.p).rotright().trunc(h)))}
	return 2
}

func dist(a, b point, c circle) float64 {
	l := line{a, b}
	var p11, p12 point
	if !c.pointcrossline(l, &p11, &p12) {
		return a.distance(b)
	}
	rd := point{0, 0}.rad(p11, p12)
	rd = math.Min(rd, 2*pi-rd)
	ds := a.distance(b) - p11.distance(p12) + rd*c.r
	var l1, l2 line
	c.tangentline(a, &l1, &l2)
	p1 := [3]point{l1.b, l2.b}
	c.tangentline(b, &l1, &l2)
	p2 := [3]point{l1.b, l2.b}
	for i := 0; i < 2; i++ {
		for j := 0; j < 2; j++ {
			ds = math.Min(ds, a.distance(p1[i])+point{0, 0}.rad(p1[i], p2[j])*c.r+b.distance(p2[j]))
		}
	}
	return ds
}

func main() {
	var xp, yp, vp float64
	fmt.Scan(&xp, &yp, &vp)
	p := point{xp, yp}
	var x, y, v, r float64
	fmt.Scan(&x, &y, &v, &r)
	c := circle{point{0, 0}, r}
	d := 2 * pi * p.distance(point{0, 0})
	k := 1000
	low, high := 0.0, 1e6
	for k > 0 {
		mid := (low + high) / 2.0
		s := vp * mid
		w := math.Mod(s, d)
		w = (w / d) * 2 * pi
		where := p.rotate(point{0, 0}, w)
		md := dist(where, point{x, y}, c)
		if dblcmp(mid*v-md) >= 0 {
			high = mid
		} else {
			low = mid
		}
		k--
	}
	fmt.Printf("%.12lf\n", low)
}
