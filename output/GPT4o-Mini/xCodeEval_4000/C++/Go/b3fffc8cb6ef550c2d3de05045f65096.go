package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

const MOD = 998244353
const UNDEF = -1
const INF = 1 << 30

type mint struct {
	x uint32
}

func (m *mint) norm(x int) int {
	if x < 0 {
		x += MOD
	}
	return x
}

func newMint(sig int) mint {
	sig = new(mint).norm(sig)
	return mint{uint32(sig)}
}

func (m *mint) get() int {
	return int(m.x)
}

func (m *mint) add(that mint) {
	m.x += that.x
	if m.x >= MOD {
		m.x -= MOD
	}
}

func (m *mint) sub(that mint) {
	m.x += MOD - that.x
	if m.x >= MOD {
		m.x -= MOD
	}
}

func (m *mint) mul(that mint) {
	m.x = (uint64(m.x) * uint64(that.x)) % MOD
}

func (m *mint) inverse() mint {
	a, b := int(m.x), MOD
	u, v := 1, 0
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
	return mint{uint32(u)}
}

func (m *mint) div(that mint) {
	*m = *m * that.inverse()
}

type rational struct {
	nu, de int64
}

func newRational(n, d int64) rational {
	if d < 0 {
		n = -n
		d = -d
	}
	return rational{n, d}
}

func (r rational) add(b rational) rational {
	return newRational(r.nu*b.de+b.nu*r.de, r.de*b.de)
}

func (r rational) sub(b rational) rational {
	return newRational(r.nu*b.de-r.de*b.nu, r.de*b.de)
}

func (r rational) mul(b rational) rational {
	return newRational(r.nu*b.nu, r.de*b.de)
}

func (r rational) div(b rational) rational {
	return newRational(r.nu*b.de, r.de*b.nu)
}

func (r rational) less(b rational) bool {
	return r.nu*b.de < b.nu*r.de
}

type SegNode struct {
	prod   [2]mint
	sumlr  mint
	ident  bool
}

const mn = 100004
const L = 0
const R = 1

type MulSegTree struct {
	segn int
	t    [2 * mn]SegNode
	identity SegNode
}

func (seg *MulSegTree) init(n int) {
	seg.segn = n
	seg.identity = SegNode{{newMint(1), newMint(1)}, newMint(1), true}
}

func (seg *MulSegTree) combine(x, y SegNode) SegNode {
	if x.ident {
		return y
	}
	if y.ident {
		return x
	}
	var ans SegNode
	for d := 0; d < 2; d++ {
		ans.prod[d] = x.prod[d]
		ans.prod[d].mul(y.prod[d])
	}
	ans.sumlr = x.sumlr.mul(y.prod[R]).add(x.prod[L].mul(y.sumlr)).sub(x.prod[L].mul(y.prod[R]))
	ans.ident = false
	return ans
}

func (seg *MulSegTree) build() {
	n := seg.segn
	for i := n - 1; i > 0; i-- {
		seg.t[i] = seg.combine(seg.t[i<<1], seg.t[i<<1|1])
	}
}

func (seg *MulSegTree) setBeforeBuild(p int, value SegNode) {
	seg.t[seg.segn+p] = value
}

func (seg *MulSegTree) sset(p int, value SegNode) {
	n := seg.segn
	for seg.t[p += n] = value; p >>= 1; {
		seg.t[p] = seg.combine(seg.t[p<<1], seg.t[p<<1|1])
	}
}

func (seg *MulSegTree) query(l, r int) SegNode {
	if l > r {
		return seg.identity
	}
	r++
	n := seg.segn
	resl, resr := seg.identity, seg.identity
	for l += n; r += n; l < r {
		if l&1 != 0 {
			resl = seg.combine(resl, seg.t[l])
			l++
		}
		if r&1 != 0 {
			r--
			resr = seg.combine(seg.t[r], resr)
		}
		l >>= 1
		r >>= 1
	}
	return seg.combine(resl, resr)
}

type Group struct {
	l, r, forceDir int
}

func (g Group) less(other Group) bool {
	return g.r < other.r || (g.r == other.r && (g.l < other.l || (g.l == other.l && g.forceDir < other.forceDir)))
}

type GroupSet struct {
	s map[Group]struct{}
}

func (gs *GroupSet) init(n int) {
	gs.s = make(map[Group]struct{})
	for x := 0; x < n; x++ {
		gs.ufreset(x)
	}
}

func (gs *GroupSet) ufreset(x int) {
	gs.s[Group{x, x, -1}] = struct{}{}
}

func (gs *GroupSet) lb(x int) (Group, bool) {
	for g := range gs.s {
		if g.l <= x && x <= g.r {
			return g, true
		}
	}
	return Group{}, false
}

func (gs *GroupSet) funion(x, y int) {
	it1, _ := gs.lb(x)
	it2, _ := gs.lb(y)
	if it1 != it2 {
		combined := Group{min(it1.l, it2.l), max(it1.r, it2.r), max(it1.forceDir, it2.forceDir)}
		delete(gs.s, it1)
		delete(gs.s, it2)
		gs.s[combined] = struct{}{}
	}
}

func (gs *GroupSet) getData(x int) Group {
	g, _ := gs.lb(x)
	return g
}

func (gs *GroupSet) setData(x int, dat Group) {
	g, _ := gs.lb(x)
	delete(gs.s, g)
	gs.s[dat] = struct{}{}
}

func (gs *GroupSet) split(pl, pr, dl, dr int) {
	itl, _ := gs.lb(pl)
	itr, _ := gs.lb(pr)
	if itl.forceDir == -1 && itr.forceDir == -1 {
		delete(gs.s, itl)
		gs.s[Group{itl.l, pl, dl}] = struct{}{}
		gs.s[Group{pr, itr.r, dr}] = struct{}{}
	} else {
		panic("Invalid split")
	}
}

func (gs *GroupSet) getDir(x int) int {
	return gs.getData(x).forceDir
}

type Collision struct {
	collideTime rational
	pos         int
	dirL, dirR  int
}

func (c Collision) less(other Collision) bool {
	return c.collideTime.less(other.collideTime)
}

var (
	vpos       [mn]int
	v          [mn]int
	probBallDir [mn][2]mint
	gs         GroupSet
	seg        MulSegTree
	probNoCollide mint
)

func rat2Mint(r rational) mint {
	return newMint(int(r.nu)) / newMint(int(r.de))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n := readInt(reader)
	for i := 0; i < n; i++ {
		vpos[i] = readInt(reader)
		v[i] = readInt(reader)
		probBallDir[i][R] = newMint(readInt(reader)) / newMint(100)
		probBallDir[i][L] = newMint(1).sub(probBallDir[i][R])
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
		rlCollideTime := newRational(int64(dist), int64(v[i+1]+v[i]))
		collisions = append(collisions, Collision{rlCollideTime, i, R, L})

		if v[i] > v[i+1] {
			rrCollideTime := newRational(int64(dist), int64(v[i]-v[i+1]))
			collisions = append(collisions, Collision{rrCollideTime, i, R, R})
		}

		if v[i] < v[i+1] {
			llCollideTime := newRational(int64(dist), int64(v[i+1]-v[i]))
			collisions = append(collisions, Collision{llCollideTime, i, L, L})
		}
	}
	sort.Slice(collisions, func(i, j int) bool {
		return collisions[i].less(collisions[j])
	})

	finalSum := mint{0}
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
				probNoCollide = mint{0}
			} else {
				den := getProdOfRange(pos, pos+1)
				gs.split(c.pos, c.pos+1, L, UNDEF)
				num := getProdOfRange(pos, pos+1)
				probNoCollide.mul(num.div(den))
			}
		} else if c.dirL == L && c.dirR == L {
			if dr == L {
				probNoCollide = mint{0}
			} else {
				den := getProdOfRange(pos, pos+1)
				gs.split(c.pos, c.pos+1, UNDEF, R)
				num := getProdOfRange(pos, pos+1)
				probNoCollide.mul(num.div(den))
			}
		} else {
			panic("Invalid direction")
		}

		collideTime := rat2Mint(c.collideTime)
		finalSum.add(collideTime.mul(prevProbNoCollide.sub(probNoCollide)))
		if probNoCollide.get() == 0 {
			break
		}
	}
	fmt.Println(finalSum.get())
}

func readInt(reader *bufio.Reader) int {
	var x int
	fmt.Fscan(reader, &x)
	return x
}
