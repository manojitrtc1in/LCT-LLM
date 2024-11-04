package main

import (
	"fmt"
	"math/rand"
	"strings"
)

type S struct {
	l, r int
	le, ri, tot, all int64
}

var (
	f, b, str, h, ne, to, fa, aa []int
	clr                          [][]int
	s1, s2                       int
	a                            []S
	o                            []int
)

func main() {
	new(Main).run()
}

type Main struct{}

func (m *Main) run() {
	m.solve()
}

func (m *Main) mul(a, b, p int64) int64 {
	res := int64(0)
	base := a
	for b > 0 {
		if b&1 > 0 {
			res = (res + base) % p
		}
		base = (base + base) % p
		b >>= 1
	}
	return res
}

func (m *Main) modPow(k, n, p int64) int64 {
	res := int64(1)
	temp := k
	for n != 0 {
		if n&1 == 1 {
			res = (res * temp) % p
		}
		temp = (temp * temp) % p
		n >>= 1
	}
	return res % p
}

func (m *Main) go(rt int, g [][]int) {
	str[ct] = rt
	f[rt] = ct
	for _, cd := range g[rt] {
		ct++
		m.go(cd, g)
	}
	b[rt] = ct
}

func (m *Main) sort(a []int64) {
	for i := 1; i < len(a); i++ {
		p := rand.Intn(i)
		a[p], a[i] = a[i], a[p]
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func (m *Main) dfs(from, k int) {}

func (m *Main) add(u, v int) {
	to[ct] = u
	ne[ct] = h[v]
	h[v] = ct
	ct++
}

func (m *Main) dfs1(c, ff int) {
	clr[c][aa[c]]++
	for j := h[c]; j != -1; j = ne[j] {
		if to[j] == ff {
			continue
		}
		m.dfs1(to[j], c)
		clr[c][1] += clr[to[j]][1]
		clr[c][2] += clr[to[j]][2]
		if (clr[to[j]][1] == s1 && clr[to[j]][2] == 0) || (clr[to[j]][2] == s2 && clr[to[j]][1] == 0) {
			r++
		}
	}
}

func (m *Main) f(n int) bool {
	c := 0
	for n > 0 {
		c += n % 10
		n /= 10
	}
	return (c & 3) == 0
}

func (m *Main) next(s string) [][]int {
	lenS := len(s)
	ne := make([][]int, lenS+1)
	for i := range ne {
		ne[i] = make([]int, 26)
		for j := range ne[i] {
			ne[i][j] = -1
		}
	}
	for i := lenS - 1; i >= 0; i-- {
		copy(ne[i], ne[i+1])
		ne[i][s[i]-'a'] = i + 1
	}
	return ne
}

func (m *Main) solve() {
	s := m.ns()
	t := m.ns()
	lenS := len(s)
	pref := make([]int, lenS)
	suf := make([]int, lenS+1)
	p := 0
	tlen := len(t)
	for i := 0; i < lenS; i++ {
		if p < tlen && s[i] == t[p] {
			p++
		}
		pref[i] = p
	}
	p = 0
	for i := lenS - 1; i >= 0; i-- {
		if p < tlen && s[i] == t[tlen-1-p] {
			p++
		}
		suf[i] = p
	}
	e := -1
	all := 0
	for i := -1; i < lenS; i++ {
		r := tlen - func() int {
			if i < 0 {
				return 0
			}
			return pref[i]
		}()
		for e+1 <= lenS && suf[e+1] >= r {
			e++
		}
		all = max(all, e-i-1)
	}
	fmt.Println(all)
}

func (m *Main) update(t []int64, i int, v int64) {
	for ; i < len(t); i += (i & -i) {
		t[i] += v
	}
}

func (m *Main) get(t []int64, i int) int64 {
	s := int64(0)
	for ; i > 0; i -= (i & -i) {
		s += t[i]
	}
	return s
}

func (m *Main) id0(t []int64, v int64) int {
	s, p := 0, 0
	for i := 31; i >= 0; i-- {
		if p+(1<<i) < len(t) && s+ t[p+(1<<i)] < v {
			v -= t[p+(1<<i)]
			p |= 1 << i
		}
	}
	return p + 1
}

func (m *Main) init(f []int) {
	o = f
	lenO := len(o)
	a = make([]S, lenO*4)
	m.build(1, 0, lenO-1)
}

func (m *Main) build(num, l, r int) {
	cur := S{l: l, r: r}
	if l == r {
		a[num] = cur
		return
	} else {
		m := (l + r) >> 1
		le := num << 1
		ri := le | 1
		m.build(le, l, m)
		m.build(ri, m+1, r)
		a[num] = cur
		m.pushup(num, le, ri)
	}
}

func (m *Main) update(num, l int, v int64) {
	if a[num].l == a[num].r {
		a[num].le = v % dd
		a[num].ri = v % dd
		a[num].all = v % dd
		a[num].tot = v % dd
	} else {
		m := (a[num].l + a[num].r) >> 1
		le := num << 1
		ri := le | 1
		m.pushdown(num, le, ri)
		if l <= m {
			m.update(le, l, v)
		}
		if l > m {
			m.update(ri, l, v)
		}
		m.pushup(num, le, ri)
	}
}

func (m *Main) pushup(num, le, ri int) {
	a[num].all = (a[le].all * a[ri].all) % dd
	a[num].le = (a[le].le + a[le].all*a[ri].le) % dd
	a[num].ri = (a[ri].ri + a[ri].all*a[le].ri) % dd
	a[num].tot = (a[le].tot + a[ri].tot + a[le].ri*a[ri].le) % dd
}

func (m *Main) pushdown(num, le, ri int) {}

func (m *Main) gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return m.gcd(b, a%b)
}

func (m *Main) gcdInt(a, b int) int {
	if b == 0 {
		return a
	}
	return m.gcdInt(b, a%b)
}

func (m *Main) ns() string {
	var s string
	fmt.Scan(&s)
	return s
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
