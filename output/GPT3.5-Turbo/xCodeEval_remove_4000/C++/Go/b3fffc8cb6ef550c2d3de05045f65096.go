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
	x unsigned
}

func (m *mint) _norm(x int) int {
	if x < 0 {
		x += MOD
	}
	return x
}

func (m *mint) get() int {
	return int(m.x)
}

func (m *mint) add(that mint) mint {
	if (m.x += that.x) >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *mint) sub(that mint) mint {
	if (m.x += MOD - that.x) >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *mint) mul(that mint) mint {
	m.x = (unsigned(m.x) * that.x) % MOD
	return *m
}

func (m *mint) div(that mint) mint {
	return m.mul(that.inverse())
}

func (m *mint) addInt(that int) mint {
	that = m._norm(that)
	if (m.x += that) >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *mint) subInt(that int) mint {
	that = m._norm(that)
	if (m.x += MOD - that) >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *mint) mulInt(that int) mint {
	that = m._norm(that)
	m.x = (unsigned(m.x) * that) % MOD
	return *m
}

func (m *mint) divInt(that int) mint {
	that = m._norm(that)
	return m.mul(mint(that).inverse())
}

func (m *mint) inverse() mint {
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

func (m *mint) equals(that mint) bool {
	return m.x == that.x
}

func (m *mint) notEquals(that mint) bool {
	return m.x != that.x
}

func (m *mint) neg() mint {
	if m.x == 0 {
		return mint(0)
	}
	return mint(MOD - m.x)
}

func (m *mint) pow(k unsigned) mint {
	a := *m
	r := mint(1)
	for k != 0 {
		if k&1 != 0 {
			r.mul(a)
		}
		a.mul(a)
		k >>= 1
	}
	return r
}

type id5 struct {
	nu int64
	de int64
}

func (i *id5) add(b id5) id5 {
	return id5{i.nu*b.de + i.de*b.nu, i.de*b.de}
}

func (i *id5) sub(b id5) id5 {
	return id5{i.nu*b.de - i.de*b.nu, i.de*b.de}
}

func (i *id5) neg() id5 {
	return id5{-i.nu, i.de}
}

func (i *id5) mul(b id5) id5 {
	return id5{i.nu*b.nu, i.de*b.de}
}

func (i *id5) div(b id5) id5 {
	return id5{i.nu*b.de, i.de*b.nu}
}

func (i *id5) equals(b id5) bool {
	return i.nu*b.de == b.nu*i.de
}

func (i *id5) lessThan(b id5) bool {
	return i.nu*b.de < b.nu*i.de
}

func (i *id5) lessThanOrEqual(b id5) bool {
	return i.nu*b.de <= b.nu*i.de
}

func (i *id5) greaterThan(b id5) bool {
	return i.nu*b.de > b.nu*i.de
}

func (i *id5) greaterThanOrEqual(b id5) bool {
	return i.nu*b.de >= b.nu*i.de
}

type SegNode struct {
	prod   [2]mint
	sumlr  mint
	ident  bool
}

type MulSegTree struct {
	SEGSZ    int
	segn     int
	t        [2 * SEGSZ]SegNode
	identity SegNode
}

func (m *MulSegTree) combine(x, y SegNode) SegNode {
	if x.ident {
		return y
	}
	if y.ident {
		return x
	}
	ans := SegNode{}
	for d := 0; d < 2; d++ {
		ans.prod[d] = x.prod[d].mul(y.prod[d])
	}
	ans.sumlr = x.sumlr.mul(y.prod[R]).add(x.prod[L].mul(y.sumlr)).sub(x.prod[L].mul(y.prod[R]))
	ans.ident = false
	return ans
}

func (m *MulSegTree) init(n int) {
	m.segn = n
}

func (m *MulSegTree) build() {
	n := m.segn
	for i := n - 1; i > 0; i-- {
		m.t[i] = m.combine(m.t[i<<1], m.t[i<<1|1])
	}
}

func (m *MulSegTree) setBeforeBuild(p int, value SegNode) {
	m.t[m.segn+p] = value
}

func (m *MulSegTree) sset(p int, value SegNode) {
	n := m.segn
	for m.t[p += n] = value; p >>= 1; {
		m.t[p] = m.combine(m.t[p<<1], m.t[p<<1|1])
	}
}

func (m *MulSegTree) query(l, r int) SegNode {
	if l > r {
		return m.identity
	}
	r++
	n := m.segn
	resl := m.identity
	resr := m.identity
	for l < r {
		if l&1 != 0 {
			resl = m.combine(resl, m.t[l])
			l++
		}
		if r&1 != 0 {
			r--
			resr = m.combine(m.t[r], resr)
		}
		l >>= 1
		r >>= 1
	}
	return m.combine(resl, resr)
}

type Group struct {
	l         int
	r         int
	forceDir  int
}

type GroupSet struct {
	s []Group
}

func (g *GroupSet) combine(x, y Group) Group {
	if min(x.forceDir, y.forceDir) >= 0 {
		if x.forceDir != y.forceDir {
			panic("forceDir mismatch")
		}
	}
	return Group{min(x.l, y.l), max(x.r, y.r), max(x.forceDir, y.forceDir)}
}

func (g *GroupSet) getInitialValue(x int) Group {
	return Group{x, x, -1}
}

func (g *GroupSet) ufreset(x int) {
	g.s = append(g.s, g.getInitialValue(x))
}

func (g *GroupSet) init(n int) {
	for x := 0; x < n; x++ {
		g.ufreset(x)
	}
}

func (g *GroupSet) lb(x int) int {
	lo := 0
	hi := len(g.s)
	for lo < hi {
		mid := (lo + hi) / 2
		if g.s[mid].r < x {
			lo = mid + 1
		} else {
			hi = mid
		}
	}
	return lo
}

func (g *GroupSet) funion(x, y int) {
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

func (g *GroupSet) getData(x int) Group {
	it := g.lb(x)
	return g.s[it]
}

func (g *GroupSet) setData(x int, dat Group) {
	it := g.lb(x)
	g.s[it] = dat
}

func (g *GroupSet) split(pl, pr, dl, dr int) {
	if !(UNDEF <= dl && dl < 2) {
		panic("dl out of range")
	}
	if !(UNDEF <= dr && dr < 2) {
		panic("dr out of range")
	}
	if pl+1 != pr {
		panic("pl and pr must be adjacent")
	}
	itl := g.lb(pl)
	itr := g.lb(pr)
	if itl == itr {
		gs := g.s[itl]
		g.s = append(g.s[:itl], g.s[itl+1:]...)
		g.s = append(g.s, Group{gs.l, pl, dl})
		g.s = append(g.s, Group{pr, gs.r, dr})
	} else {
		panic("itl and itr must be equal")
	}
}

func (g *GroupSet) check() {
}

func (g *GroupSet) getDir(x int) int {
	return g.getData(x).forceDir
}

type Collision struct {
	id7   id5
	pos   int
	dirL  int
	dirR  int
}

func (c *Collision) lessThan(other Collision) bool {
	return c.id7.lessThan(other.id7)
}

func probForce(dir, l, r int) mint {
	return seg.query(l, r).prod[dir]
}

func id1(l, r int) mint {
	return seg.query(l, r).sumlr
}

func id2(l, r int) mint {
	lo := INF
	hi := -INF
	ans := mint(1)
	gs.check()
	for pos := l; pos <= r; {
		dat := gs.getData(pos)
		if dat.forceDir == UNDEF {
			mult := seg.query(dat.l, dat.r).sumlr
			ans.mul(mult)
		} else {
			mult := seg.query(dat.l, dat.r).prod[dat.forceDir]
			ans.mul(mult)
		}
		pos = dat.r + 1
	}
	return ans
}

func id12(l, r int) {
	dl := gs.getDir(l)
	dr := gs.getDir(r)
	if (dl != UNDEF && dl != R) || (dr != UNDEF && dr != L) {
		return
	}
	if dl == R && dr == L {
		id12(l, l+1)
	} else if dl == R && dr == R {
		if dl == R {
			id10 = 0
		} else {
			den := id2(l, l+1)
			gs.split(l, l+1, L, UNDEF)
			num := id2(l, l+1)
			id10.mul(num.div(den))
		}
	} else if dl == L && dr == L {
		if dr == L {
			id10 = 0
		} else {
			den := id2(l, l+1)
			gs.split(l, l+1, UNDEF, R)
			num := id2(l, l+1)
			id10.mul(num.div(den))
		}
	} else {
		panic("invalid direction")
	}
}

func id3(r id5) mint {
	return mint(r.nu).divInt(r.de)
}

func main() {
	n := rint()
	alln := n
	vpos := make([]int, n)
	v := make([]int, n)
	probBallDir := make([][2]mint, n)
	for i := 0; i < n; i++ {
		vpos[i] = rint()
		v[i] = rint()
		probBallDir[i][R] = mint(rint()).divInt(100)
		probBallDir[i][L] = mint(1).sub(probBallDir[i][R])
	}
	gs.init(n)
	seg.init(n)
	for pos := 0; pos < n; pos++ {
		seg.setBeforeBuild(pos, SegNode{[2]mint{probBallDir[pos][L], probBallDir[pos][R]}, probBallDir[pos][L].add(probBallDir[pos][R]), false})
	}
	seg.build()
	collisions := make([]Collision, 0, n-1)
	for i := 0; i < n-1; i++ {
		dist := vpos[i+1] - vpos[i]
		id8 := id5{int64(dist), int64(v[i+1] + v[i])}
		collisions = append(collisions, Collision{id8, i, R, L})
		if v[i] > v[i+1] {
			id6 := id5{int64(dist), int64(v[i] - v[i+1])}
			collisions = append(collisions, Collision{id6, i, R, R})
		}
		if v[i] < v[i+1] {
			id11 := id5{int64(dist), int64(v[i+1] - v[i])}
			collisions = append(collisions, Collision{id11, i, L, L})
		}
	}
	sort.Slice(collisions, func(i, j int) bool {
		return collisions[i].lessThan(collisions[j])
	})
	finalSum := mint(0)
	for _, c := range collisions {
		pos := c.pos
		id9 := id10
		dl := gs.getDir(c.pos)
		dr := gs.getDir(c.pos + 1)
		if dl != UNDEF && dl != c.dirL {
			continue
		}
		if dr != UNDEF && dr != c.dirR {
			continue
		}
		if c.dirL == R && c.dirR == L {
			id12(pos, pos+1)
		} else if c.dirL == R && c.dirR == R {
			if dl == R {
				id10 = 0
			} else {
				den := id2(pos, pos+1)
				gs.split(c.pos, c.pos+1, L, UNDEF)
				num := id2(pos, pos+1)
				id10.mul(num.div(den))
			}
		} else if c.dirL == L && c.dirR == L {
			if dr == L {
				id10 = 0
			} else {
				den := id2(pos, pos+1)
				gs.split(c.pos, c.pos+1, UNDEF, R)
				num := id2(pos, pos+1)
				id10.mul(num.div(den))
			}
		} else {
			panic("invalid direction")
		}
		gs.check()
		id7 := id3(c.id7)
		finalSum.add(id7.mul(id9.sub(id10)))
		if id10.equals(mint(0)) {
			break
		}
	}
	fmt.Println(finalSum.get())
}

func rint() int {
	var x int
	fmt.Scan(&x)
	return x
}

func rlong() int64 {
	var x int64
	fmt.Scan(&x)
	return x
}
