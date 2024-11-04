package main

import (
	"fmt"
	"sort"
)

const (
	MOD   = 998244353
	UNDEF = -1
	INF   = 1 << 30
)

type mint struct {
	x int
}

func (m mint) norm(x int) int {
	if x < 0 {
		x += MOD
	}
	return x
}

func (m mint) add(a mint) mint {
	m.x += a.x
	if m.x >= MOD {
		m.x -= MOD
	}
	return m
}

func (m mint) sub(a mint) mint {
	m.x += MOD - a.x
	if m.x >= MOD {
		m.x -= MOD
	}
	return m
}

func (m mint) mul(a mint) mint {
	m.x = (m.x * a.x) % MOD
	return m
}

func (m mint) div(a mint) mint {
	return m.mul(a.inv())
}

func (m mint) addInt(a int) mint {
	a = m.norm(a)
	m.x += a
	if m.x >= MOD {
		m.x -= MOD
	}
	return m
}

func (m mint) subInt(a int) mint {
	a = m.norm(a)
	m.x += MOD - a
	if m.x >= MOD {
		m.x -= MOD
	}
	return m
}

func (m mint) mulInt(a int) mint {
	a = m.norm(a)
	m.x = (m.x * a) % MOD
	return m
}

func (m mint) divInt(a int) mint {
	a = m.norm(a)
	return m.mul(mint(a).inv())
}

func (m mint) inv() mint {
	a := m.x
	b := MOD
	u := 1
	v := 0
	for b != 0 {
		t := a / b
		a -= t * b
		a, b = b, a
		u -= t * v
		u, v = v, u
	}
	if u < 0 {
		u += MOD
	}
	return mint(u)
}

func (m mint) equal(a mint) bool {
	return m.x == a.x
}

func (m mint) notEqual(a mint) bool {
	return m.x != a.x
}

func (m mint) neg() mint {
	if m.x == 0 {
		return mint(0)
	}
	return mint(MOD - m.x)
}

func (m mint) pow(k int) mint {
	a := m
	r := mint(1)
	for k != 0 {
		if k&1 == 1 {
			r = r.mul(a)
		}
		a = a.mul(a)
		k >>= 1
	}
	return r
}

type rational struct {
	nu int
	de int
}

func newRational(n, d int) rational {
	return rational{n, d}
}

func (r rational) add(a rational) rational {
	return rational{r.nu*a.de + r.de*a.nu, r.de * a.de}
}

func (r rational) sub(a rational) rational {
	return rational{r.nu*a.de - r.de*a.nu, r.de * a.de}
}

func (r rational) mul(a rational) rational {
	return rational{r.nu * a.nu, r.de * a.de}
}

func (r rational) div(a rational) rational {
	return rational{r.nu * a.de, r.de * a.nu}
}

func (r rational) equal(a rational) bool {
	return r.nu*a.de == a.nu*r.de
}

func (r rational) equalInt(k int) bool {
	return r.nu == k*r.de
}

func (r rational) less(a rational) bool {
	return r.nu*a.de < a.nu*r.de
}

func (r rational) lessEqual(a rational) bool {
	return r.nu*a.de <= a.nu*r.de
}

func (r rational) greater(a rational) bool {
	return r.nu*a.de > a.nu*r.de
}

func (r rational) greaterEqual(a rational) bool {
	return r.nu*a.de >= a.nu*r.de
}

type segNode struct {
	prod   [2]mint
	sumlr  mint
	ident  bool
}

const mn = (1e5) + 4
const L = 0
const R = 1

type mulSegTree struct {
	segn     int
	t        [2 * mn]segNode
	identity segNode
}

func newMulSegTree() *mulSegTree {
	return &mulSegTree{}
}

func (m *mulSegTree) combine(x, y segNode) segNode {
	if x.ident {
		return y
	}
	if y.ident {
		return x
	}
	ans := segNode{}
	for d := 0; d < 2; d++ {
		ans.prod[d] = x.prod[d].mul(y.prod[d])
	}
	ans.sumlr = x.sumlr.mul(y.prod[R]).add(x.prod[L].mul(y.sumlr)).sub(x.prod[L].mul(y.prod[R]))
	ans.ident = false
	return ans
}

func (m *mulSegTree) init(n int) {
	m.segn = n
}

func (m *mulSegTree) build() {
	n := m.segn
	for i := n - 1; i > 0; i-- {
		m.t[i] = m.combine(m.t[i<<1], m.t[i<<1|1])
	}
}

func (m *mulSegTree) setBeforeBuild(p int, value segNode) {
	m.t[m.segn+p] = value
}

func (m *mulSegTree) set(p int, value segNode) {
	n := m.segn
	for t[p += n] = value; p >>= 1; {
		t[p] = m.combine(t[p<<1], t[p<<1|1])
	}
}

func (m *mulSegTree) query(l, r int) segNode {
	if l > r {
		return m.identity
	}
	r++
	n := m.segn
	resl := m.identity
	resr := m.identity
	for l < r {
		if l&1 == 1 {
			resl = m.combine(resl, t[l])
			l++
		}
		if r&1 == 1 {
			r--
			resr = m.combine(t[r], resr)
		}
		l >>= 1
		r >>= 1
	}
	return m.combine(resl, resr)
}

type group struct {
	l        int
	r        int
	forceDir int
}

type groupSet struct {
	s []group
}

func newGroupSet() *groupSet {
	return &groupSet{}
}

func (g *groupSet) combine(x, y group) group {
	if min(x.forceDir, y.forceDir) >= 0 {
		if x.forceDir != y.forceDir {
			panic("Invalid force direction")
		}
	}
	return group{min(x.l, y.l), max(x.r, y.r), max(x.forceDir, y.forceDir)}
}

func (g *groupSet) getInitialValue(x int) group {
	return group{x, x, -1}
}

func (g *groupSet) init(n int) {
	for x := 0; x < n; x++ {
		g.ufreset(x)
	}
}

func (g *groupSet) lb(x int) int {
	lo := -2
	hi := x
	for lo+1 < hi {
		mid := (lo + hi) / 2
		if g.s[mid].r < x {
			lo = mid
		} else {
			hi = mid
		}
	}
	return hi
}

func (g *groupSet) ufreset(x int) {
	g.s = append(g.s, g.getInitialValue(x))
}

func (g *groupSet) funion(x, y int) {
	it1 := g.lb(x)
	it2 := g.lb(y)
	if it1 != it2 {
		combined := g.combine(g.s[it1], g.s[it2])
		g.s = append(g.s[:it1], g.s[it1+1:]...)
		it2 = g.lb(y)
		g.s = append(g.s[:it2], g.s[it2+1:]...)
		g.s = append(g.s, combined)
	}
}

func (g *groupSet) getData(x int) group {
	it := g.lb(x)
	return g.s[it]
}

func (g *groupSet) setData(x int, dat group) {
	it := g.lb(x)
	g.s[it] = dat
}

func (g *groupSet) split(pl, pr, dl, dr int) {
	if !(UNDEF <= dl && dl < 2) {
		panic("Invalid direction")
	}
	if !(UNDEF <= dr && dr < 2) {
		panic("Invalid direction")
	}
	if pl+1 != pr {
		panic("Invalid range")
	}
	itl := g.lb(pl)
	itr := g.lb(pr)
	if itl == itr {
		gs := g.s[itl]
		g.s = append(g.s[:itl], g.s[itl+1:]...)
		g.s = append(g.s, group{gs.l, pl, dl})
		g.s = append(g.s, group{pr, gs.r, dr})
	} else {
		panic("Invalid range")
	}
}

func (g *groupSet) check() {
}

func (g *groupSet) getDir(x int) int {
	return g.getData(x).forceDir
}

type collision struct {
	collideTime rational
	pos         int
	dirL        int
	dirR        int
}

func main() {
	var n int
	fmt.Scan(&n)
	vpos := make([]int, n)
	v := make([]int, n)
	probBallDir := make([][2]mint, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&vpos[i])
		fmt.Scan(&v[i])
		var r int
		fmt.Scan(&r)
		probBallDir[i][R] = mint(r).divInt(100)
		probBallDir[i][L] = mint(1).sub(probBallDir[i][R])
	}
	gs := newGroupSet()
	seg := newMulSegTree()
	seg.init(n)
	for pos := 0; pos < n; pos++ {
		seg.setBeforeBuild(pos, segNode{[2]mint{probBallDir[pos][L], probBallDir[pos][R]}, probBallDir[pos][L].add(probBallDir[pos][R]), false})
	}
	seg.build()
	collisions := make([]collision, 0, n-1)
	for i := 0; i < n-1; i++ {
		dist := vpos[i+1] - vpos[i]
		rlCollideTime := newRational(dist, v[i+1]+v[i])
		collisions = append(collisions, collision{rlCollideTime, i, R, L})
		if v[i] > v[i+1] {
			rrCollideTime := newRational(dist, v[i]-v[i+1])
			collisions = append(collisions, collision{rrCollideTime, i, R, R})
		}
		if v[i] < v[i+1] {
			llCollideTime := newRational(dist, v[i+1]-v[i])
			collisions = append(collisions, collision{llCollideTime, i, L, L})
		}
	}
	sort.Slice(collisions, func(i, j int) bool {
		return collisions[i].collideTime.less(collisions[j].collideTime)
	})
	finalSum := mint(0)
	probNoCollide := mint(1)
	for _, c := range collisions {
		pos := c.pos
		prevProbNoCollide := probNoCollide
		dl := gs.getDir(c.pos)
		dr := gs.getDir(c.pos + 1)
		if dl != UNDEF && dl != c.dirL {
			continue
		}
		if dr != UNDEF && dr != c.dirR {
			continue
		}
		if c.dirL == R && c.dirR == L {
			mergeFates(pos, pos+1)
		} else if c.dirL == R && c.dirR == R {
			if dl == R {
				probNoCollide = mint(0)
			} else {
				den := getProdOfRange(pos, pos+1)
				gs.split(c.pos, c.pos+1, L, UNDEF)
				num := getProdOfRange(pos, pos+1)
				probNoCollide = probNoCollide.mul(num.div(den))
			}
		} else if c.dirL == L && c.dirR == L {
			if dr == L {
				probNoCollide = mint(0)
			} else {
				den := getProdOfRange(pos, pos+1)
				gs.split(c.pos, c.pos+1, UNDEF, R)
				num := getProdOfRange(pos, pos+1)
				probNoCollide = probNoCollide.mul(num.div(den))
			}
		} else {
			panic("Invalid direction")
		}
		finalSum = finalSum.add(c.collideTime.mul(prevProbNoCollide.sub(probNoCollide)))
		if probNoCollide.equalInt(0) {
			break
		}
	}
	fmt.Println(finalSum.x)
}

func mergeFates(l, r int) {
	dl := gs.getDir(l)
	dr := gs.getDir(r)
	if (dl == R && dr == -1) || (dl == -1 && dr == L) || (dl == -1 && dr == -1) {
		num := getProdOfRange(l, r)
		gs.funion(l, r)
		den := getProdOfRange(l, r)
		probNoCollide = probNoCollide.mul(num.div(den))
	} else if dl == L && dr == -1 {
	} else if dl == -1 && dr == R {
	} else if dl >= 0 && dr >= 0 {
		if dl == dr {
		} else {
			probNoCollide = mint(0)
		}
	} else {
		panic("Invalid direction")
	}
}

func getProdOfRange(l, r int) mint {
	lo := INF
	hi := -INF
	ans := mint(1)
	gs.check()
	for pos := l; pos <= r; {
		dat := gs.getData(pos)
		if dat.forceDir != UNDEF {
			panic("Invalid force direction")
		}
		lo = min(lo, dat.l)
		hi = max(hi, dat.r)
		var mult mint
		if dat.forceDir == UNDEF {
			mult = seg.query(dat.l, dat.r).sumlr
		} else {
			mult = seg.query(dat.l, dat.r).prod[dat.forceDir]
		}
		ans = ans.mul(mult)
		pos = dat.r + 1
	}
	return ans
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
