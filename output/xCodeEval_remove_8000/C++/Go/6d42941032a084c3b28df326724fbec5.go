package main

import (
	"fmt"
)

const M = 998244353

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	w := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&w[i])
	}
	W1 := 0
	W2 := 0
	for i := 0; i < n; i++ {
		if a[i] != 0 {
			W1 += w[i]
		} else {
			W2 += w[i]
		}
	}
	probs := make([]int, m+1)
	probs[0] = 1
	for i := 0; i < m; i++ {
		newProbs := make([]int, m+1)
		for d1 := 0; d1 <= i; d1++ {
			d2 := d1 - i
			w1 := W1 + d1
			w2 := W2 + d2
			w0 := w1 + w2
			if probs[d1] != 0 && w2 >= 0 {
				id16 := inverse(w0, M)
				if w2 > 0 {
					newProbs[d1] = sum(newProbs[d1], prod(probs[d1], prod(w2, id16, M), M), M)
				}
				newProbs[d1+1] = sum(newProbs[d1+1], prod(probs[d1], prod(w1, id16, M), M), M)
			}
		}
		probs = newProbs
	}
	id4 := make([]int, m+1)
	id29 := make([]int, m+1)
	id4[0] = 1
	id29[0] = 1
	for i := 1; i <= m; i++ {
		id4[i] = prod(id4[i-1], sum(1, inverse(W1+i-1, M), M), M)
	}
	for i := 1; i <= m; i++ {
		id29[i] = prod(id29[i-1], raz(1, inverse(W2-i+1, M), M), M)
	}
	coef1 := 0
	coef2 := 0
	for i := 0; i <= m; i++ {
		coef1 = sum(coef1, prod(id4[i], probs[i], M), M)
	}
	for i := 0; i <= m; i++ {
		coef2 = sum(coef2, prod(id29[i], probs[m-i], M), M)
	}
	for i := 0; i < n; i++ {
		if a[i] != 0 {
			fmt.Println(prod(w[i], coef1, M))
		} else {
			fmt.Println(prod(w[i], coef2, M))
		}
	}
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func prod(a, b, M int) int {
	return (a * b) % M
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

func inverse(a, n int) int {
	c := id20(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id20(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	t := a / b
	ans1 := id20(b, a-t*b)
	return ans1.Y, ans1.X - ans1.Y*t
}

func id19(a, b, n int) int {
	k := sqrt(n)
	a1 := id39(a, n)
	l := k + 20
	a2 := po_p(a1, k, n)
	seq1 := make([]int, k)
	seq2 := make([]int, l)
	seq1[0] = 1
	for i := 1; i < k; i++ {
		seq1[i] = pr_p(seq1[i-1], a, n)
	}
	seq2[0] = b
	for i := 1; i < l; i++ {
		seq2[i] = pr_p(seq2[i-1], a2, n)
	}
	e := equal_elements(seq1, seq2)
	if e.X == -1 {
		return -1
	}
	return e.X + e.Y*k
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func pr_p(a, b, p int) int {
	if b < 1000000 {
		return (a * b) % p
	}
	temp := pr_p(a, b>>1, p)
	temp = sumll(temp, temp, p)
	if b&1 != 0 {
		return sumll(temp, a, p)
	} else {
		return temp
	}
}

func po_p(a, b, p int) int {
	if b < 2 {
		if b == 0 {
			return 1
		} else {
			return a
		}
	}
	temp := po_p(a, b>>1, p)
	temp = pr_p(temp, temp, p)
	if b&1 != 0 {
		return pr_p(temp, a, p)
	} else {
		return temp
	}
}

func sqrt(x int) int {
	ans := 1
	for ans*ans <= x {
		ans++
	}
	return ans - 1
}

func equal_elements(u, v []int) (int, int) {
	ans := []int{INT_MAX, INT_MAX}
	m := len(u)
	n := len(v)
	i := 0
	j := 0
	for i < m && j < n {
		if u[i] < v[j] {
			ans = []int{u[i], ans[1]}
			i++
		} else if u[i] > v[j] {
			ans = []int{v[j], ans[1]}
			j++
		} else {
			ans = []int{v[j], u[i]}
			i++
			j++
		}
	}
	if ans[0] == INT_MAX {
		return -1, -1
	} else {
		return ans[1], ans[0]
	}
}

func id35(a, p, b, q int) int {
	c := id20(p, q)
	pr := p * q
	ans := ((a*c.Y*q + b*c.X*p) % pr + pr) % pr
	return ans
}

func id13(c, n, pr, k int) int {
	c %= n
	if c != 0 {
		kek := power_v(c, pr)
		l := kek.X
		if l&1 != 0 {
			return -1
		}
		if l > 0 {
			pwl := 1
			for i := 0; i < l; i++ {
				pwl *= pr
			}
			n /= pwl
			c /= pwl
			ans1 := id13(c, n, pr, k-l)
			if ans1 == -1 {
				return -1
			}
			for i := 0; i < l>>1; i++ {
				ans1 *= pr
			}
			return ans1
		} else {
			var primitive int
			if n&1 != 0 {
				primitive = primitive_root(n)
			} else {
				primitive = 5
			}
			u := id19(primitive, c, n)
			if u == -1 {
				return -1
			}
			if u&1 != 0 {
				return -1
			}
			return pow_mod(primitive, u>>1, n)
		}
	} else {
		return 0
	}
}

func power_v(n, p int) (int, int) {
	ans := 0
	for n%p == 0 {
		n /= p
		ans++
	}
	return ans, n
}

func primitive_root(n int) int {
	if n < 3 {
		return n - 1
	}
	p := phi(n)
	f := factorize(p)
	toCheck := make([]int, len(f))
	for i := 0; i < len(f); i++ {
		toCheck[i] = p / f[i].X
	}
	for i := 2; i < n; i++ {
		if id0(p, toCheck, i, n) {
			return i
		}
	}
	return -1
}

func id0(ph int, toCheck []int, r int, n int) bool {
	for i := 0; i < len(toCheck); i++ {
		if pow_mod(r, toCheck[i], n) == 1 {
			return false
		}
	}
	return pow_mod(r, ph, n) == 1
}

func phi(v []pii) int {
	ans := 1
	for i := 0; i < len(v); i++ {
		ans *= v[i].X - 1
		for j := 1; j < v[i].Y; j++ {
			ans *= v[i].X
		}
	}
	return ans
}

func phi(n int) int {
	return phi(factorize(n))
}

func factorize(n int) []pii {
	ans := make([]pii, 0)
	for i := 2; i*i <= n; i++ {
		if n%i == 0 {
			cnt := 0
			for n%i == 0 {
				n /= i
				cnt++
			}
			ans = append(ans, pii{i, cnt})
		}
	}
	if n > 1 {
		ans = append(ans, pii{n, 1})
	}
	return ans
}

func merge(p1, p2 []pii) []pii {
	ans := make([]pii, 0)
	m := len(p1)
	n := len(p2)
	i := 0
	j := 0
	for i < m || j < n {
		if i < m {
			if j < n {
				if p1[i].X < p2[j].X {
					ans = append(ans, p1[i])
					i++
				} else if p1[i].X > p2[j].X {
					ans = append(ans, p2[j])
					j++
				} else {
					ans = append(ans, pii{p1[i].X, p1[i].Y + p2[j].Y})
					i++
					j++
				}
			} else {
				ans = append(ans, p1[i])
				i++
			}
		} else {
			ans = append(ans, p2[j])
			j++
		}
	}
	return ans
}

func id23(a, b pii) bool {
	if p := a % b; p != 0 {
		return p > 0
	} else {
		return sq_len(a) < sq_len(b)
	}
}

func id24(x int) int {
	ans := 0
	for x != 0 {
		if x&1 != 0 {
			ans++
		}
		x >>= 1
	}
	return ans
}

func id6(x int) int {
	ans := 32
	for x != 0 {
		ans--
		x >>= 1
	}
	return ans
}

func id40(x int) int {
	ans := 0
	for x&1 == 0 {
		ans++
		x >>= 1
	}
	return ans
}

func id4(x int) int {
	ans := 0
	for x != 0 {
		if x&1 != 0 {
			ans++
		}
		x >>= 1
	}
	return ans
}

func id12(x int) int {
	ans := 0
	for x != 0 {
		if x&1 != 0 {
			ans++
		}
		x >>= 1
	}
	return ans
}

func id29(x int) int {
	ans := 64
	for x != 0 {
		ans--
		x >>= 1
	}
	return ans
}

func id10(x int) int {
	ans := 64
	for x != 0 {
		ans--
		x >>= 1
	}
	return ans
}

func id2(x int) int {
	ans := 0
	for x&1 == 0 {
		ans++
		x >>= 1
	}
	return ans
}

func id5(x int) int {
	ans := 0
	for x != 0 {
		if x&1 != 0 {
			ans++
		}
		x >>= 1
	}
	return ans
}

func id32(a, b int) int {
	for b != 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0])).div(c[1].sub(c[0]).dot(c[1].sub(c[0]))))
}

type pdd struct {
	X, Y float64
}

func (p pdd) add(q pdd) pdd {
	return pdd{p.X + q.X, p.Y + q.Y}
}

func (p pdd) sub(q pdd) pdd {
	return pdd{p.X - q.X, p.Y - q.Y}
}

func (p pdd) mul(q pdd) float64 {
	return p.X*q.X + p.Y*q.Y
}

func (p pdd) mulScalar(q float64) pdd {
	return pdd{p.X * q, p.Y * q}
}

func (p pdd) div(q float64) pdd {
	return pdd{p.X / q, p.Y / q}
}

func (p pdd) dot(q pdd) float64 {
	return p.X*q.X + p.Y*q.Y
}

func (p pdd) rotate90() pdd {
	return pdd{-p.Y, p.X}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.cross(q)
	E := pdd{-a, p.Y}.cross(pdd{-b, q.Y})
	F := pdd{p.X, -a}.cross(pdd{q.X, -b})
	return pdd{E / D, F / D}
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func sqLen(p pdd) float64 {
	return p.mul(p)
}

func sqDist(p, q pdd) float64 {
	return sqLen(p.sub(q))
}

func len(p pdd) float64 {
	return sqrt(sqLen(p))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func id17(a, b, c, d pdd) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

func isRectangle(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return x.mul(y) == 0 && y.mul(z) == 0 && z.mul(t) == 0 && t.mul(x) == 0
}

func areParallel(a, b pdd) bool {
	return a.cross(b) == 0
}

func id18(a, b pdd) bool {
	return a.mul(b) == 0
}

func id30(a, b pdd) bool {
	return areParallel(a, b) && a.mul(b) >= 0
}

func id36(a, b, c, d pdd) bool {
	return a.sub(b) == d.sub(c)
}

func id26(a, b, c, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id30(x, z)
}

func id21(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	p := x.cross(y)
	q := y.cross(z)
	r := z.cross(t)
	s := t.cross(x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id37(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id15(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id8(a, b, c, d pdd) bool {
	return id37(a, b, c, d) && id37(c, d, a, b)
}

func id27(a, b, c, d pdd) bool {
	return id15(a, b, c, d) && id15(c, d, a, b)
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0]))).div(c[1].sub(c[0]).dot(c[1].sub(c[0])))
}

func id7(p, point pdd) (pair pdd) {
	return id3(id31(p), point)
}

func id3(normal, point pdd) (pair pdd) {
	return pair{normal, -(normal.mul(point))}
}

func id33(x, y, z pdd) pdd {
	p1 := serper(x, y)
	p2 := serper(x, z)
	return ints(p1.X, p1.Y, p2.X, p2.Y)
}

func serper(a, b pdd) (pair pdd) {
	p := b.sub(a)
	return pair{p.add(p), -(p.mul(a.add(b)))}
}

func height(a, b, c pdd) pdd {
	return projection(id7(a, c), b)
}

func unitvector(a pdd) pdd {
	return a.mulScalar(1 / len(a))
}

func onSegment(a, b, c pdd) bool {
	return id30(b.sub(a), c.sub(b))
}

func perpendicular(line, point pair) (pair pdd) {
	return id3(id31(line), point)
}

func projection(line pair, point pdd) pdd {
	temp := perpendicular(line, point)
	return ints(line.X, line.Y, temp.X, temp.Y)
}

type pair struct {
	X, Y float64
}

type pii struct {
	X, Y int
}

type pdd struct {
	X, Y float64
}

func pr_p(a, b, p int) int {
	if b < 1000000 {
		return (a * b) % p
	}
	temp := pr_p(a, b>>1, p)
	temp = sumll(temp, temp, p)
	if b&1 != 0 {
		return sumll(temp, a, p)
	} else {
		return temp
	}
}

func po_p(a, b, p int) int {
	if b < 2 {
		if b == 0 {
			return 1
		} else {
			return a
		}
	}
	temp := po_p(a, b>>1, p)
	temp = pr_p(temp, temp, p)
	if b&1 != 0 {
		return pr_p(temp, a, p)
	} else {
		return temp
	}
}

func sum(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func raz(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

func prod(a, b, M int) int {
	return (a * b) % M
}

func sumll(a, b, M int) int {
	c := a + b
	if c >= M {
		c -= M
	}
	return c
}

func razll(a, b, M int) int {
	c := a - b
	if c < 0 {
		c += M
	}
	return c
}

func prodll(a, b, M int) int {
	return (a * b) % M
}

func inverse(a, n int) int {
	c := id20(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id20(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	t := a / b
	ans1 := id20(b, a-t*b)
	return ans1.Y, ans1.X - ans1.Y*t
}

func id11(a, b int) (int, int) {
	if b == 0 {
		return 1, 0
	}
	c := a / b
	ans1 := id11(b, a-c*b)
	return ans1.Y, ans1.X - ans1.Y*c
}

func id39(a, n int) int {
	c := id11(a, n).X
	if c < 0 {
		c += n
	}
	return c
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0]))).div(c[1].sub(c[0]).dot(c[1].sub(c[0])))
}

func id7(p pdd, c ...pdd) (pair pdd) {
	return id3(id31(p), c...)
}

func id3(normal, point pdd) (pair pdd) {
	return pair{normal, -(normal.mul(point))}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.cross(q)
	E := pdd{-a, p.Y}.cross(pdd{-b, q.Y})
	F := pdd{p.X, -a}.cross(pdd{q.X, -b})
	return pdd{E / D, F / D}
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func sqLen(p pdd) float64 {
	return p.mul(p)
}

func sqDist(p, q pdd) float64 {
	return sqLen(p.sub(q))
}

func len(p pdd) float64 {
	return sqrt(sqLen(p))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func id17(a, b, c, d pdd) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

func isRectangle(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return x.mul(y) == 0 && y.mul(z) == 0 && z.mul(t) == 0 && t.mul(x) == 0
}

func areParallel(a, b pdd) bool {
	return a.cross(b) == 0
}

func id18(a, b pdd) bool {
	return a.mul(b) == 0
}

func id30(a, b pdd) bool {
	return areParallel(a, b) && a.mul(b) >= 0
}

func id36(a, b, c, d pdd) bool {
	return a.sub(b) == d.sub(c)
}

func id26(a, b, c, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id30(x, z)
}

func id21(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	p := x.cross(y)
	q := y.cross(z)
	r := z.cross(t)
	s := t.cross(x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id37(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id15(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id8(a, b, c, d pdd) bool {
	return id37(a, b, c, d) && id37(c, d, a, b)
}

func id27(a, b, c, d pdd) bool {
	return id15(a, b, c, d) && id15(c, d, a, b)
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0]))).div(c[1].sub(c[0]).dot(c[1].sub(c[0])))
}

func id7(p pdd, c ...pdd) (pair pdd) {
	return id3(id31(p), c...)
}

func id3(normal, point pdd) (pair pdd) {
	return pair{normal, -(normal.mul(point))}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.cross(q)
	E := pdd{-a, p.Y}.cross(pdd{-b, q.Y})
	F := pdd{p.X, -a}.cross(pdd{q.X, -b})
	return pdd{E / D, F / D}
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func sqLen(p pdd) float64 {
	return p.mul(p)
}

func sqDist(p, q pdd) float64 {
	return sqLen(p.sub(q))
}

func len(p pdd) float64 {
	return sqrt(sqLen(p))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func id17(a, b, c, d pdd) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

func isRectangle(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return x.mul(y) == 0 && y.mul(z) == 0 && z.mul(t) == 0 && t.mul(x) == 0
}

func areParallel(a, b pdd) bool {
	return a.cross(b) == 0
}

func id18(a, b pdd) bool {
	return a.mul(b) == 0
}

func id30(a, b pdd) bool {
	return areParallel(a, b) && a.mul(b) >= 0
}

func id36(a, b, c, d pdd) bool {
	return a.sub(b) == d.sub(c)
}

func id26(a, b, c, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id30(x, z)
}

func id21(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	p := x.cross(y)
	q := y.cross(z)
	r := z.cross(t)
	s := t.cross(x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id37(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id15(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id8(a, b, c, d pdd) bool {
	return id37(a, b, c, d) && id37(c, d, a, b)
}

func id27(a, b, c, d pdd) bool {
	return id15(a, b, c, d) && id15(c, d, a, b)
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0]))).div(c[1].sub(c[0]).dot(c[1].sub(c[0])))
}

func id7(p pdd, c ...pdd) (pair pdd) {
	return id3(id31(p), c...)
}

func id3(normal, point pdd) (pair pdd) {
	return pair{normal, -(normal.mul(point))}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.cross(q)
	E := pdd{-a, p.Y}.cross(pdd{-b, q.Y})
	F := pdd{p.X, -a}.cross(pdd{q.X, -b})
	return pdd{E / D, F / D}
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func sqLen(p pdd) float64 {
	return p.mul(p)
}

func sqDist(p, q pdd) float64 {
	return sqLen(p.sub(q))
}

func len(p pdd) float64 {
	return sqrt(sqLen(p))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func id17(a, b, c, d pdd) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

func isRectangle(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	return x.mul(y) == 0 && y.mul(z) == 0 && z.mul(t) == 0 && t.mul(x) == 0
}

func areParallel(a, b pdd) bool {
	return a.cross(b) == 0
}

func id18(a, b pdd) bool {
	return a.mul(b) == 0
}

func id30(a, b pdd) bool {
	return areParallel(a, b) && a.mul(b) >= 0
}

func id36(a, b, c, d pdd) bool {
	return a.sub(b) == d.sub(c)
}

func id26(a, b, c, d pdd) bool {
	x := a.sub(b)
	z := d.sub(c)
	return id30(x, z)
}

func id21(a, b, c, d pdd) bool {
	x := a.sub(b)
	y := b.sub(c)
	z := c.sub(d)
	t := d.sub(a)
	p := x.cross(y)
	q := y.cross(z)
	r := z.cross(t)
	s := t.cross(x)
	return (p >= 0 && q >= 0 && r >= 0 && s >= 0) || (p <= 0 && q <= 0 && r <= 0 && s <= 0)
}

func id37(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p >= 0 && q <= 0) || (p <= 0 && q >= 0)
}

func id15(a, b, c, d pdd) bool {
	x := b.sub(a)
	p := x.cross(c.sub(b))
	q := x.cross(d.sub(b))
	return (p > 0 && q < 0) || (p < 0 && q > 0)
}

func id8(a, b, c, d pdd) bool {
	return id37(a, b, c, d) && id37(c, d, a, b)
}

func id27(a, b, c, d pdd) bool {
	return id15(a, b, c, d) && id15(c, d, a, b)
}

func id31(p pdd, c ...pdd) pdd {
	if len(c) == 1 {
		return c[0].add(p.sub(c[0]).rotate90())
	}
	return c[0].add(p.sub(c[0]).rotate90().mul(c[1].sub(c[0]))).div(c[1].sub(c[0]).dot(c[1].sub(c[0])))
}

func id7(p pdd, c ...pdd) (pair pdd) {
	return id3(id31(p), c...)
}

func id3(normal, point pdd) (pair pdd) {
	return pair{normal, -(normal.mul(point))}
}

func ints(p pdd, a float64, q pdd, b float64) pdd {
	D := p.cross(q)
	E := pdd{-a, p.Y}.cross(pdd{-b, q.Y})
	F := pdd{p.X, -a}.cross(pdd{q.X, -b})
	return pdd{E / D, F / D}
}

func (p pdd) cross(q pdd) float64 {
	return p.X*q.Y - p.Y*q.X
}

func sqLen(p pdd) float64 {
	return p.mul(p)
}

func sqDist(p, q pdd) float64 {
	return sqLen(p.sub(q))
}

func len(p pdd) float64 {
	return sqrt(sqLen(p))
}

func dist(p, q pdd) float64 {
	return len(p.sub(q))
}

func id17(a, b, c, d pdd) bool {
	x := sqDist(a, b)
	y := sqDist(b, c)
	z := sqDist(c, d)
	t := sqDist(d, a)
	return x == y && y == z && z == t
}

