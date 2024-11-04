package main

import (
	"fmt"
	"math"
	"sort"
)

type statistic struct {
	p   [2][2]inte
	l   int
	r   int
}

type col struct {
	i   int
	tp  int
	t1  int
	t2  int
}

type inte struct {
	v int
}

func (a inte) wrapAround() {
	if a.v < 0 {
		a.v = (a.v % p + p) % p
	} else if a.v >= p {
		a.v %= p
	}
}

func (a inte) add(b inte) inte {
	c := inte{a.v + b.v}
	if c.v >= a.p {
		c.v -= a.p
	}
	return c
}

func (a inte) subtract(b inte) inte {
	c := inte{a.v - b.v}
	if c.v < 0 {
		c.v += a.p
	}
	return c
}

func (a inte) multiply(b inte) inte {
	c := inte{}
	if a.t == "int64" {
		c.v = (a.v * b.v - (int64)(((float64)a.v * b.v + 0.5) / a.p) * a.p + a.p) % a.p
	} else if a.t == "int" {
		c.v = int((int64(a.v) * b.v) % a.p)
	} else {
		c.v = (a.v * b.v) % a.p
	}
	return c
}

func (a inte) power(b int) inte {
	r := inte{1}
	for b > 0 {
		if b & 1 == 1 {
			r = r.multiply(a)
		}
		a = a.multiply(a)
		b >>= 1
	}
	return r
}

func (a inte) divide(b inte) inte {
	return a.multiply(inverse(b))
}

func (a inte) inverse() inte {
	assert(a.v)
	if a.v < len(inverseCache) {
		return inverseCache[a.v]
	}
	return a.power(a.p - 2)
}

func (a inte) inverseCached() inte {
	assert(a.v)
	for len(inverseCache) <= a.v {
		inverseCache = append(inverseCache, inte{-p / len(inverseCache)} * inverseCache[p % len(inverseCache)])
	}
	return inverseCache[a.v]
}

func (a inte) factorial() inte {
	assert(a.v >= 0)
	for len(factorialCache) <= a.v {
		factorialCache = append(factorialCache, factorialCache[len(factorialCache) - 1].multiply(inte{len(factorialCache)}))
	}
	return factorialCache[a.v]
}

func (a inte) id1(k inte) inte {
	assert(a.v >= 0 && k.v >= 0)
	if a.v < k.v {
		return inte{}
	}
	return a.factorial().divide(k.factorial()).divide((a.subtract(k)).factorial())
}

func (a inte) id0(y []inte, x inte) inte {
	t := make([]inte, len(y))
	copy(t, y)
	return id0(t, x)
}

func id0(y []inte, x inte) inte {
	f := []inte{inte{1}}
	g := make([]inte, len(y))
	h := make([]inte, len(y))
	for i := 1; i < len(y); i++ {
		f = append(f, f[len(f) - 1].multiply(inverseCached(inte{i})))
		g[i] = h[i] = x
		g[i] = g[i].subtract(inte{i})
		h[i] = h[i].subtract(inte{i})
		g[i] = g[i].multiply(g[i - 1])
	}
	for i := len(y) - 2; i >= 0; i-- {
		h[i] = h[i].multiply(h[i + 1])
	}
	r := inte{0}
	for i := 0; i < len(y); i++ {
		t := f[i].multiply(f[len(y) - 1 - i])
		if i > 0 {
			t = t.multiply(g[i - 1])
		}
		if i + 1 < len(y) {
			t = t.multiply(h[i + 1])
		}
		if (len(y) - i - 1) % 2 == 1 {
			t = t.multiply(inte{-1})
		}
		r = r.add(t.multiply(y[i]))
	}
	return r
}

func assert(b bool) {
	if !b {
		panic("Assertion failed")
	}
}

var p = 998244353
var inverseCache = []inte{{1}, {1}}
var factorialCache = []inte{{1}}

func main() {
	var n int
	fmt.Scan(&n)
	policy := make([][]int, n - 1)
	s := make([]statistic, 0)
	x := make([]int, n)
	v := make([]int, n)
	p := make([]int, n)
	for i := 0; i < n - 1; i++ {
		fmt.Scan(&x[i], &v[i], &p[i])
		s = append(s, statistic{inte{p[i] / 100}, i})
		policy[i] = []int{1, 1, 1, 1}
	}
	tree := build(s, 0, len(s) - 1)
	ans := inte{0}
	cols := make([]col, 0)
	for i := 0; i < n - 2; i++ {
		tmp := col{i, 2, x[i + 1] - x[i], v[i] + v[i + 1]}
		cols = append(cols, tmp)
		if v[i] > v[i + 1] {
			tmp.tp = 1
			tmp.t2 = v[i] - v[i + 1]
			cols = append(cols, tmp)
		}
		if v[i] < v[i + 1] {
			tmp.tp = 0
			tmp.t2 = v[i + 1] - v[i]
			cols = append(cols, tmp)
		}
	}
	sort.Slice(cols, func(i, j int) bool {
		return int64(cols[i].t1) * int64(cols[j].t2) < int64(cols[j].t1) * int64(cols[i].t2)
	})
	for _, c := range cols {
		old := make([]int, len(policy[c.i]))
		copy(old, policy[c.i])
		for i := 0; i < len(policy[c.i]); i++ {
			policy[c.i][i] = 0
		}
		policy[c.i][c.tp] = 1
		modifySingle(tree, c.i, statistic{inte{p[c.i] / 100}, c.i})
		ans = ans.add(tree.root.s.ans().multiply(c.ans()))
		copy(policy[c.i], old)
		policy[c.i][c.tp] = 0
		modifySingle(tree, c.i, statistic{inte{p[c.i] / 100}, c.i})
		if tree.root.s.ans().v == 0 {
			break
		}
	}
	fmt.Println(ans)
}

func build(a []statistic, l, r int) *node {
	u := &node{}
	if l == r {
		u.c[0] = nil
		u.c[1] = nil
		u.s = a[l]
	} else {
		m := (l + r) / 2
		u.c[0] = build(a, l, m)
		u.c[1] = build(a, m + 1, r)
		u.s.merge(u.c[0].s, u.c[1].s)
	}
	u.l = l
	u.r = r
	return u
}

func modifySingle(u *node, p int, s statistic) {
	if u.l == u.r {
		assert(p == u.l)
		u.s = s
	} else {
		modifySingle(u.c[p > u.c[0].r], p, s)
		u.s.merge(u.c[0].s, u.c[1].s)
	}
}

type node struct {
	c [2]*node
	s statistic
	l int
	r int
}

func (u *node) push() {
	if u.c[0] != nil {
		u.c[0].s.tag(u.s.tag())
		u.c[1].s.tag(u.s.tag())
	}
	u.s.push()
}

func (u *node) merge() {
	u.s.merge(u.c[0].s, u.c[1].s)
}

func (u *node) destroy() {
	if u != nil {
		u.c[0].destroy()
		u.c[1].destroy()
	}
}

func modifySegment(u *node, l, r int, t inte) {
	if l <= u.l && u.r <= r {
		u.s.tag(t)
	} else {
		if l <= u.c[0].r {
			modifySegment(u.c[0], l, r, t)
		}
		if r >= u.c[1].l {
			modifySegment(u.c[1], l, r, t)
		}
	}
	u.push()
	u.merge()
}

func querySingle(u *node, p int) statistic {
	if u.l == u.r {
		assert(p == u.l)
		return u.s
	} else {
		return querySingle(u.c[p > u.c[0].r], p)
	}
}

func querySegment(u *node, l, r int) statistic {
	if l <= u.l && u.r <= r {
		return u.s
	} else {
		if r <= u.c[0].r {
			return querySegment(u.c[0], l, r)
		}
		if l >= u.c[1].l {
			return querySegment(u.c[1], l, r)
		}
		t := statistic{}
		t.merge(querySegment(u.c[0], l, r), querySegment(u.c[1], l, r))
		return t
	}
}
