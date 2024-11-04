package main

import (
	"fmt"
	"math/rand"
	"os"
)

var groups int
var fa []int
var sz []int

func init1(n int) {
	groups = n
	fa = make([]int, n)
	for i := 1; i < n; i++ {
		fa[i] = i
	}
	sz = make([]int, n)
	for i := range sz {
		sz[i] = 1
	}
}

func root(p int) int {
	for p != fa[p] {
		fa[p] = fa[fa[p]]
		p = fa[p]
	}
	return p
}

func combine(p, q int) {
	i := root(p)
	j := root(q)
	if i == j {
		return
	}
	fa[i] = j
	if sz[i] < sz[j] {
		fa[i] = j
		sz[j] += sz[i]
	} else {
		fa[j] = i
		sz[i] += sz[j]
	}
	groups--
}

func roundS(result float64, scale int) string {
	return fmt.Sprintf(fmt.Sprintf("%%.%df", scale), result)
}

func unique(a []int) []int {
	p := 1
	for i := 1; i < len(a); i++ {
		if a[i] != a[i-1] {
			a[p] = a[i]
			p++
		}
	}
	return a[:p]
}

func bigger(a []int64, key int64) int {
	return biggerRec(a, 0, len(a), key)
}

func biggerRec(a []int64, lo, hi int, key int64) int {
	for lo < hi {
		mid := (lo + hi) >> 1
		if a[mid] > key {
			hi = mid
		} else {
			lo = mid + 1
		}
	}
	return lo
}

var h []int
var to []int
var ne []int
var m int

func addEdge(u, v, w int) {
	m++
	to = append(to, v)
	ne = append(ne, h[u])
	h[u] = m
}

var w []int
var cc int

func add(u, v, ww int) {
	cc++
	to = append(to, u)
	w = append(w, ww)
	ne = append(ne, h[v])
	h[v] = cc

	cc++
	to = append(to, v)
	w = append(w, ww)
	ne = append(ne, h[u])
	h[u] = cc
}

type S struct {
	l, r, miss, cnt, c int
}

var a []S
var o []int

func init11(f []int) {
	o = f
	lenO := len(o)
	a = make([]S, lenO*4)
	build1(1, 0, lenO-1)
}

func build1(num, l, r int) {
	cur := S{l: l, r: r}
	if l == r {
		cur.c = o[l]
		a[num] = cur
		return
	} else {
		m := (l + r) >> 1
		le := num << 1
		ri := le | 1
		build1(le, l, m)
		build1(ri, m+1, r)
		a[num] = cur
		pushup(num, le, ri)
	}
}

func query1(num, l, r int) int {
	if a[num].l >= l && a[num].r <= r {
		return a[num].c
	} else {
		m := (a[num].l + a[num].r) >> 1
		le := num << 1
		ri := le | 1

		mi := -1

		if r > m {
			res := query1(ri, l, r)
			mi = max(mi, res)
		}

		if l <= m {
			res := query1(le, l, r)
			mi = max(mi, res)
		}

		return mi
	}
}

func pushup(num, le, ri int) {
	a[num].c = max(a[le].c, a[ri].c)
}

var clr []int
var qr [][]int
var qs [][]int

var rr = 100
var cao []int

func df(n int, li []int) {
	sz := len(li)
	if sz >= rr || sz >= 11 {
		return
	}
	v := li[len(li)-1]
	if v == n {
		cao = make([]int, sz)
		copy(cao, li)
		rr = sz
		return
	}
	res := make([]int, sz)
	copy(res, li)
	reverse(res)

	for _, u := range res {
		for _, vv := range res {
			if u+vv > v && u+vv <= n {
				li = append(li, u+vv)
				df(n, li)
				li = li[:len(li)-1]
			} else if u+vv > n {
				break
			}
		}
	}
}

func reverse(s []int) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func mul(a, b, p int64) int64 {
	res := int64(0)
	base := a
	for b > 0 {
		if (b & 1) > 0 {
			res = (res + base) % p
		}
		base = (base + base) % p
		b >>= 1
	}
	return res
}

func modPow(k, n, p int64) int64 {
	res := int64(1)
	temp := k % p
	for n != 0 {
		if (n & 1) == 1 {
			res = mul(res, temp, p)
		}
		temp = mul(temp, temp, p)
		n >>= 1
	}
	return res % p
}

func gen(x int64) int64 {
	for {
		f := rand.Int63() % x
		if f >= 1 && f <= x-1 {
			return f
		}
	}
}

func id1(x int64) bool {
	if x == 1 {
		return false
	}
	if x == 2 || x == 3 {
		return true
	}
	if (x & 1) == 0 {
		return false
	}
	y := x % 6
	if y == 1 || y == 5 {
		ck := x - 1
		for (ck & 1) == 0 {
			ck >>= 1
		}

		as := []int64{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}

		for _, a := range as {
			ck1 := ck
			a = modPow(a, ck1, x)
			for ck1 < x {
				y = modPow(a, 2, x)
				if y == 1 && a != 1 && a != x-1 {
					return false
				}
				a = y
				ck1 <<= 1
			}
			if a != 1 {
				return false
			}
		}
		return true
	} else {
		return false
	}
}

func inv(a, MOD int64) int64 {
	if a == 1 {
		return 1
	}
	return (MOD - MOD/a) * inv(MOD%a, MOD) % MOD
}

func C(n, m, MOD int64) int64 {
	if m+m > n {
		m = n - m
	}
	up := int64(1)
	down := int64(1)
	for i := int64(0); i < m; i++ {
		up = up * (n - i) % MOD
		down = down * (i + 1) % MOD
	}
	return up * inv(down, MOD) % MOD
}

func id3(a, b int64) (int64, int64, int64) {
	if b == 0 {
		return 1, 0, a
	}
	r1, r2, r3 := id3(b, a%b)
	return r2, r1 - (a/b)*r2, r3
}

func go(i, c int, cl []int) {
	cl[i] = c
	for j := h[i]; j != -1; j = ne[j] {
		v := to[j]
		if cl[v] == 0 {
			go(v, -c, cl)
		}
	}
}

func solve() {
	var t int
	fmt.Scan(&t)
	dp := make([]int, 1000001)
	for i := 0; i < t; i++ {
		var n, k, d int
		fmt.Scan(&n, &k, &d)
		a := make([]int, n)
		for j := 0; j < n; j++ {
			fmt.Scan(&a[j])
		}

		g := 0
		for j := 0; j < d; j++ {
			if dp[a[j]] == 0 {
				g++
			}
			dp[a[j]]++
		}
		all := g
		for j := d; j < n; j++ {
			if dp[a[j-d]]--; dp[a[j-d]] == 0 {
				g--
			}
			if dp[a[j]]++; dp[a[j]] == 0 {
				g++
			}
			all = min(all, g)
		}
		fmt.Println(all)
		for j := 0; j < d; j++ {
			dp[a[n-j-1]]--
		}
	}
}

func pushdown(num, le, ri int) {}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func main() {
	solve()
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
