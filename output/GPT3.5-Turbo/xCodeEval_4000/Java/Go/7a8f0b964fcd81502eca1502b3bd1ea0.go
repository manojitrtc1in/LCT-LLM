package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type Point2D struct {
	x float64
	y float64
}

type Line2D struct {
	p1 Point2D
	p2 Point2D
	A  float64
	B  float64
	C  float64
}

type Circle2D struct {
	c Point2D
	r float64
}

var (
	in  *bufio.Reader
	out *bufio.Writer
)

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var pp Point2D
	var rP, vP, omegaP float64
	var ps Point2D
	var vs float64
	var star Circle2D

	xp, _ := nextFloat64()
	yp, _ := nextFloat64()
	pp.x = xp
	pp.y = yp
	rP = math.Sqrt(xp*xp + yp*yp)
	vP, _ = nextFloat64()

	ps.x, _ = nextFloat64()
	ps.y, _ = nextFloat64()
	vs, _ = nextFloat64()

	tvp := 1.0

	vP /= tvp
	vs /= tvp

	omegaP = vP / rP
	star.c = Point2D{0.0, 0.0}
	star.r, _ = nextFloat64()

	ans := 3e6

	left := 0.0
	right := ans

	for it := 0; it < 10000; it++ {

		mid := 0.5 * (left + right)

		if can(mid, pp, rP, vP, omegaP, ps, vs, star) {
			right = mid
			ans = math.Min(ans, mid)
		} else {
			left = mid
		}

	}

	out.Printf("%.6f\n", ans/tvp)
}

func can(t float64, pp Point2D, rP float64, vP float64, omegaP float64, ps Point2D, vs float64, star Circle2D) bool {

	return distPlanetar(ps, pp.rotate(t*vP/rP)) < t*vs
}

func distPlanetar(p1 Point2D, p2 Point2D) float64 {

	if hasCSC(p1, p2, star) {

		tp1 := tppc(p1, star)
		tp2 := tppc(p2, star)

		ret := 1e100

		ret = math.Min(ret, distWithStar(p1, p2, tp1[0], tp2[0]))
		ret = math.Min(ret, distWithStar(p1, p2, tp1[0], tp2[1]))
		ret = math.Min(ret, distWithStar(p1, p2, tp1[1], tp2[0]))
		ret = math.Min(ret, distWithStar(p1, p2, tp1[1], tp2[1]))

		return ret
	}

	return dist(p1, p2)
}

func hasCSC(p1 Point2D, p2 Point2D, c Circle2D) bool {
	A := p2.y - p1.y
	B := p1.x - p2.x
	d := A*A + B*B

	var dist float64

	if math.Abs(d) < EPS {
		dist = dist(p1, c.c)
	} else {
		t := (B*(p1.x-c.c.x) - A*(p1.y-c.c.y)) / d
		if 0.0 <= t && t <= 1.0 {
			dist = math.Sqrt(sqr(p1.x-B*t-c.c.x) + sqr(p1.y+A*t-c.c.y))
		} else {
			dist = math.Min(dist(p1, c.c), dist(p2, c.c))
		}
	}

	return dist <= c.r+EPS
}

func distWithStar(p1 Point2D, p2 Point2D, tp1 Point2D, tp2 Point2D) float64 {
	phi := math.Acos(math.Max(-1.0, math.Min(1.0, tp1.scalarProduct(tp2)/tp1.len()/tp2.len())))
	return dist(p1, tp1) + dist(p2, tp2) + star.r*phi
}

func cll(l1 Line2D, l2 Line2D) *Point2D {
	det := -det2x2(l1.A, l1.B, l2.A, l2.B)
	if math.Abs(det) < EPS {
		return nil
	}
	return &Point2D{det2x2(l1.C, l1.B, l2.C, l2.B) / det, det2x2(l1.A, l1.C, l2.A, l2.C) / det}
}

func css(s1 Line2D, s2 Line2D) *Point2D {
	its := cll(s1, s2)
	if its != nil && s1.contains(*its) && s2.contains(*its) {
		return its
	}
	return nil
}

func clc(l Line2D, c Circle2D) []*Point2D {
	d := l.dist(c.c)
	if d > c.r+EPS {
		return nil
	}
	h := l.projection(c.c)
	v := l.dir().normalize(math.Sqrt(c.r*c.r - d*d))
	return []*Point2D{h.sub(v), h.add(v)}
}

func ccc(c1 Circle2D, c2 Circle2D) []*Point2D {
	d := dist(c1.c, c2.c)
	if d < EPS && c1.r < EPS && c2.r < EPS {
		return []*Point2D{&c1.c}
	}
	if d < math.Abs(c1.r-c2.r)-EPS || d > c1.r+c2.r+EPS || d < EPS {
		return nil
	}
	cos := getCos(d, c1.r, c2.r)
	sin := math.Sqrt(1.0 - cos*cos)
	v := c2.c.sub(c1.c).normalize(c1.r)
	return []*Point2D{c1.c.add(v.rotate(cos, sin)), c1.c.add(v.rotate(cos, -sin))}
}

func tcpc(p Point2D, c Circle2D) *Line2D {
	if c.r < EPS || !c.lay(p) {
		return nil
	}
	n := c.c.sub(p).turn90()
	return &Line2D{p.sub(n), p.add(n), -n.x, -n.y, n.x*p.x + n.y*p.y}
}

func tppc(p Point2D, c Circle2D) []*Point2D {
	d := dist(p, c.c)
	cos := c.r / d
	sin := math.Sqrt(1.0 - cos*cos)
	v := p.sub(c.c).normalize(c.r)
	return []*Point2D{v.rotate(cos, sin), v.rotate(cos, -sin)}
}

func tpc(p Point2D, c Circle2D) []*Line2D {
	d := dist(p, c.c)
	sin := c.r / d
	cos := math.Sqrt(1.0 - sin*sin)
	v := c.c.sub(p).normalize(math.Sqrt(d*d-c.r*c.r))
	return []*Line2D{{p, p.add(v.rotate(cos, sin))}, {p, p.add(v.rotate(cos, -sin))}}
}

func intcc(c1 Circle2D, c2 Circle2D) []*Line2D {
	h := tpc(c2.c, Circle2D{c1.c, c1.r + c2.r})
	if h != nil {
		h[0].shift(-c1.r)
		h[1].shift(c1.r)
	}
	return h
}

func outtcc(c1 Circle2D, c2 Circle2D) []*Line2D {
	if c1.r > c2.r+EPS {
		return outtcc(c2, c1)
	}
	h := tpc(c1.c, Circle2D{c2.c, c2.r - c1.r})
	if h != nil {
		h[0].shift(-c1.r)
		h[1].shift(c1.r)
	}
	return h
}

func sqr(x float64) float64 {
	return x * x
}

func det2x2(a11 float64, a12 float64, a21 float64, a22 float64) float64 {
	return a11*a22 - a12*a21
}

func cross(p0 Point2D, p1 Point2D, p2 Point2D) float64 {
	return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y)
}

func getCos(a float64, b float64, c float64) float64 {
	return 0.5 * (a*a + b*b - c*c) / (a * b)
}

func getPolarAngle(c Point2D, p Point2D) float64 {
	return math.Atan2(p.y-c.y, p.x-c.x)
}

func distSqr(p1 Point2D, p2 Point2D) float64 {
	return sqr(p2.x-p1.x) + sqr(p2.y-p1.y)
}

func dist(p1 Point2D, p2 Point2D) float64 {
	return math.Sqrt(distSqr(p1, p2))
}

func between(a float64, x float64, b float64) bool {
	return a <= x && x <= b
}

func rangeCheck(a float64, x float64, b float64) bool {
	return between(a-EPS, x, b+EPS)
}

func interval(a float64, x float64, b float64) bool {
	return between(a+EPS, x, b-EPS)
}

func sqrt(x float64) float64 {
	check(x >= -EPS)
	return math.Sqrt(math.Max(0.0, x))
}

func acos(x float64) float64 {
	check(rangeCheck(-1.0, x, 1.0))
	return math.Acos(math.Max(-1.0, math.Min(1.0, x)))
}

func asin(x float64) float64 {
	check(rangeCheck(-1.0, x, 1.0))
	return math.Asin(math.Max(-1.0, math.Min(1.0, x)))
}

func check(state bool) {
	if !state {
		panic("Error")
	}
}

func nextToken() string {
	token, _ := in.ReadString('\n')
	return strings.TrimSpace(token)
}

func nextInt() int {
	token := nextToken()
	num, _ := strconv.Atoi(token)
	return num
}

func nextFloat64() (float64, error) {
	token := nextToken()
	num, err := strconv.ParseFloat(token, 64)
	return num, err
}

func dist(p1 Point2D, p2 Point2D) float64 {
	return math.Sqrt(distSqr(p1, p2))
}

func sqr(x float64) float64 {
	return x * x
}

const EPS = 1e-7
const PI = math.Pi

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Your code here
}
