package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type id9 struct {
	x float64
	y float64
}

type id6 struct {
	c id9
	r float64
}

type id5 struct {
	p1 id9
	p2 id9
	A  float64
	B  float64
	C  float64
}

var (
	initTime int64
	rnd      = NewRandom(7777)
	in       *bufio.Reader
	out      *bufio.Writer
)

func main() {
	initTime = currentTimeMillis()
	go func() {
		if _, err := os.Stat("input.txt"); err == nil {
			in, _ = os.Open("input.txt")
		}
		solve()
		out.Flush()
	}()
}

func solve() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)

	const EPS = 1e-7

	var pp id9
	var rP, vP, omegaP float64

	var ps id9
	var vs float64

	var star id6

	xp, _ := nextDouble()
	yp, _ := nextDouble()

	pp.set(xp, yp)
	rP = math.Sqrt(xp*xp + yp*yp)
	vP, _ = nextDouble()

	ps.set(nextDouble(), nextDouble())
	vs, _ = nextDouble()

	tvp := 1.0

	vP /= tvp
	vs /= tvp

	omegaP = vP / rP
	star = id6{id9{0.0, 0.0}, nextDouble()}

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

func can(t float64, pp id9, rP float64, vP float64, omegaP float64, ps id9, vs float64, star id6) bool {
	return id4(ps, pp.rotate(t*vP/rP)) < t*vs
}

func id4(p1 id9, p2 id9) float64 {
	if hasCSC(p1, p2, star) {
		tp1 := id10(p1, star)
		tp2 := id10(p2, star)

		ret := 1e100

		ret = math.Min(ret, id1(p1, p2, tp1[0], tp2[0]))
		ret = math.Min(ret, id1(p1, p2, tp1[0], tp2[1]))
		ret = math.Min(ret, id1(p1, p2, tp1[1], tp2[0]))
		ret = math.Min(ret, id1(p1, p2, tp1[1], tp2[1]))

		return ret
	}

	return dist(p1, p2)
}

func hasCSC(p1 id9, p2 id9, c id6) bool {
	A := p2.y - p1.y
	B := p1.x - p2.x
	d := A*A + B*B

	dist := 0.0

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

func id1(p1 id9, p2 id9, tp1 id9, tp2 id9) float64 {
	phi := math.Acos(math.Max(-1.0, math.Min(1.0, tp1.scalarProduct(tp2)/tp1.len()/tp2.len())))
	return dist(p1, tp1) + dist(p2, tp2) + star.r*phi
}

func cll(l1 id5, l2 id5) *id9 {
	det := -id13(l1.A, l1.B, l2.A, l2.B)
	if math.Abs(det) < EPS {
		return nil
	}
	return &id9{id13(l1.C, l1.B, l2.C, l2.B) / det, id13(l1.A, l1.C, l2.A, l2.C) / det}
}

func css(s1 id5, s2 id5) *id9 {
	its := cll(s1, s2)
	if its != nil && s1.contains(*its) && s2.contains(*its) {
		return its
	}
	return nil
}

func clc(l id5, c id6) []*id9 {
	d := l.dist(c.c)
	if d > c.r+EPS {
		return nil
	}
	h := l.projection(c.c)
	v := l.dir().normalize(math.Sqrt(c.r*c.r - d*d))
	return []*id9{h.sub(v), h.add(v)}
}

func ccc(c1 id6, c2 id6) []*id9 {
	d := dist(c1.c, c2.c)
	if d < EPS && c1.r < EPS && c2.r < EPS {
		return []*id9{&c1.c}
	}
	if d < math.Abs(c1.r-c2.r)-EPS || d > c1.r+c2.r+EPS || d < EPS {
		return nil
	}
	cos := getCos(d, c1.r, c2.r)
	sin := math.Sqrt(1.0 - cos*cos)
	v := c2.c.sub(c1.c).normalize(c1.r)
	return []*id9{c1.c.add(v.rotate(cos, sin)), c1.c.add(v.rotate(cos, -sin))}
}

func tcpc(p id9, c id6) *id5 {
	if c.r < EPS || !c.lay(p) {
		return nil
	}
	n := c.c.sub(p).turn90()
	return &id5{p.sub(n), p.add(n), -n.y, n.x, -(n.y*p.x - n.x*p.y)}
}

func id10(p id9, c id6) []*id9 {
	d := dist(p, c.c)
	cos := c.r / d
	sin := math.Sqrt(1.0 - cos*cos)
	v := p.sub(c.c).normalize(c.r)
	return []*id9{v.rotate(cos, sin), v.rotate(cos, -sin)}
}

func tpc(p id9, c id6) []*id5 {
	d := dist(p, c.c)
	sin := c.r / d
	cos := math.Sqrt(1.0 - sin*sin)
	v := c.c.sub(p).normalize(math.Sqrt(d*d-c.r*c.r))
	return []*id5{{p, p.add(v.rotate(cos, sin))}, {p, p.add(v.rotate(cos, -sin))}}
}

func intcc(c1 id6, c2 id6) []*id5 {
	h := tpc(c2.c, id6{c1.c, c1.r + c2.r})
	if h != nil {
		h[0].shift(-c1.r)
		h[1].shift(c1.r)
	}
	return h
}

func id7(c1 id6, c2 id6) []*id5 {
	if c1.r > c2.r+EPS {
		return id7(c2, c1)
	}
	h := tpc(c1.c, id6{c2.c, c2.r - c1.r})
	if h != nil {
		h[0].shift(-c1.r)
		h[1].shift(c1.r)
	}
	return h
}

func sqr(x float64) float64 {
	return x * x
}

func id13(a11 float64, a12 float64, a21 float64, a22 float64) float64 {
	return a11*a22 - a12*a21
}

func cross(p0 id9, p1 id9, p2 id9) float64 {
	return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y)
}

func getCos(a float64, b float64, c float64) float64 {
	return 0.5 * (a*a + b*b - c*c) / (a * b)
}

func id0(c id9, p id9) float64 {
	return math.Atan2(p.y-c.y, p.x-c.x)
}

func id2(p1 id9, p2 id9) float64 {
	return sqr(p2.x-p1.x) + sqr(p2.y-p1.y)
}

func dist(p1 id9, p2 id9) float64 {
	return math.Sqrt(id2(p1, p2))
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
		fmt.Println("Error")
		panic("Error")
	}
}

func sqr(x float64) float64 {
	return x * x
}

func currentTimeMillis() int64 {
	return time.Now().UnixNano() / int64(time.Millisecond)
}

func NewRandom(seed int64) *rand.Rand {
	return rand.New(rand.NewSource(seed))
}

func nextToken() string {
	for !st.hasMoreTokens() {
		st = bufio.NewTokenizer(in.ReadString('\n'))
	}
	return st.nextToken()
}

func nextInt() int {
	n, _ := strconv.Atoi(nextToken())
	return n
}

func nextLong() int64 {
	n, _ := strconv.ParseInt(nextToken(), 10, 64)
	return n
}

func nextDouble() float64 {
	n, _ := strconv.ParseFloat(nextToken(), 64)
	return n
}

func nextLine() string {
	st = bufio.NewTokenizer("")
	return in.ReadString('\n')
}

func EOF() bool {
	for !st.hasMoreTokens() {
		if _, err := in.Peek(1); err != nil {
			return true
		}
		st = bufio.NewTokenizer(in.ReadString('\n'))
	}
	return false
}

func printArray(array []int) {
	if len(array) == 0 {
		return
	}
	for i := 0; i < len(array); i++ {
		if i > 0 {
			out.WriteByte(' ')
		}
		out.WriteString(strconv.Itoa(array[i]))
	}
	out.WriteByte('\n')
}

func printArray(array []int64) {
	if len(array) == 0 {
		return
	}
	for i := 0; i < len(array); i++ {
		if i > 0 {
			out.WriteByte(' ')
		}
		out.WriteString(strconv.FormatInt(array[i], 10))
	}
	out.WriteByte('\n')
}

func printArray(array []float64) {
	if len(array) == 0 {
		return
	}
	for i := 0; i < len(array); i++ {
		if i > 0 {
			out.WriteByte(' ')
		}
		out.WriteString(strconv.FormatFloat(array[i], 'f', -1, 64))
	}
	out.WriteByte('\n')
}

func printArray(array []float64, spec string) {
	if len(array) == 0 {
		return
	}
	for i := 0; i < len(array); i++ {
		if i > 0 {
			out.WriteByte(' ')
		}
		out.WriteString(fmt.Sprintf(spec, array[i]))
	}
	out.WriteByte('\n')
}

func printArray(array []interface{}) {
	if len(array) == 0 {
		return
	}
	blank := false
	for _, x := range array {
		if blank {
			out.WriteByte(' ')
		} else {
			blank = true
		}
		out.WriteString(fmt.Sprintf("%v", x))
	}
	out.WriteByte('\n')
}

func printCollection(collection []interface{}) {
	if len(collection) == 0 {
		return
	}
	blank := false
	for _, x := range collection {
		if blank {
			out.WriteByte(' ')
		} else {
			blank = true
		}
		out.WriteString(fmt.Sprintf("%v", x))
	}
	out.WriteByte('\n')
}

func memoryStatus() string {
	return fmt.Sprintf("%d/%d MB", (runtime.MemStats.Alloc>>20), (runtime.MemStats.Sys>>20))
}

func checkMemory() {
	fmt.Println(memoryStatus())
}

func updateTimer() {
	initTime = currentTimeMillis()
}

func elapsedTime() int64 {
	return currentTimeMillis() - initTime
}

func checkTimer() {
	fmt.Println(elapsedTime(), "ms")
}

func main() {
	solve()
}
