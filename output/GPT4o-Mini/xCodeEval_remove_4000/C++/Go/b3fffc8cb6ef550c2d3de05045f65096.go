package main

import (
	"fmt"
	"math/big"
	"sort"
)

const MOD = 998244353
const UNDEF = -1
const INF = 1 << 30

type Mint struct {
	x uint64
}

func (m *Mint) norm(x int) int {
	if x < 0 {
		x += MOD
	}
	return x
}

func NewMint(sig int) Mint {
	sig = (sig % MOD + MOD) % MOD
	return Mint{uint64(sig)}
}

func (m *Mint) Get() int {
	return int(m.x)
}

func (m *Mint) Add(that Mint) Mint {
	m.x += that.x
	if m.x >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *Mint) Sub(that Mint) Mint {
	m.x += MOD - that.x
	if m.x >= MOD {
		m.x -= MOD
	}
	return *m
}

func (m *Mint) Mul(that Mint) Mint {
	m.x = (m.x * that.x) % MOD
	return *m
}

func (m *Mint) Div(that Mint) Mint {
	return m.Mul(that.Inverse())
}

func (m *Mint) Inverse() Mint {
	a, b := int(m.x), MOD
	u, v := 1, 0
	for b != 0 {
		t := a / b
		a -= t * b
		u -= t * v
		a, b = b, a
		u, v = v, u
	}
	if u < 0 {
		u += MOD
	}
	return NewMint(u)
}

type Id5 struct {
	nu, de int64
}

func NewId5(n, d int64) Id5 {
	if d < 0 {
		n = -n
		d = -d
	}
	return Id5{n, d}
}

func (a Id5) Add(b Id5) Id5 {
	return NewId5(a.nu*b.de+b.nu*a.de, a.de*b.de)
}

func (a Id5) Sub(b Id5) Id5 {
	return NewId5(a.nu*b.de-a.de*b.nu, a.de*b.de)
}

func (a Id5) Mul(b Id5) Id5 {
	return NewId5(a.nu*b.nu, a.de*b.de)
}

func (a Id5) Div(b Id5) Id5 {
	return NewId5(a.nu*b.de, a.de*b.nu)
}

type SegNode struct {
	prod   [2]Mint
	sumlr  Mint
	ident  bool
}

type MulSegTree struct {
	segn int
	t    []SegNode
	identity SegNode
}

func NewMulSegTree(size int) *MulSegTree {
	tree := &MulSegTree{
		segn: size,
		t:    make([]SegNode, 2*size),
		identity: SegNode{[2]Mint{NewMint(1), NewMint(1)}, NewMint(1), true},
	}
	return tree
}

func (tree *MulSegTree) Combine(x, y SegNode) SegNode {
	if x.ident {
		return y
	}
	if y.ident {
		return x
	}
	ans := SegNode{}
	for d := 0; d < 2; d++ {
		ans.prod[d] = x.prod[d].Mul(y.prod[d])
	}
	ans.sumlr = x.sumlr.Mul(y.prod[1]).Add(x.prod[0].Mul(y.sumlr)).Sub(x.prod[0].Mul(y.prod[1]))
	ans.ident = false
	return ans
}

func (tree *MulSegTree) Build() {
	n := tree.segn
	for i := n - 1; i > 0; i-- {
		tree.t[i] = tree.Combine(tree.t[i<<1], tree.t[i<<1|1])
	}
}

func (tree *MulSegTree) SetBeforeBuild(p int, value SegNode) {
	tree.t[tree.segn+p] = value
}

func (tree *MulSegTree) SSet(p int, value SegNode) {
	n := tree.segn
	for tree.t[p += n] = value; p >>= 1; {
		tree.t[p] = tree.Combine(tree.t[p<<1], tree.t[p<<1|1])
	}
}

func (tree *MulSegTree) Query(l, r int) SegNode {
	if l > r {
		return tree.identity
	}
	r++
	n := tree.segn
	resl, resr := tree.identity, tree.identity
	for l += n; r += n; l < r {
		if l&1 != 0 {
			resl = tree.Combine(resl, tree.t[l])
			l++
		}
		if r&1 != 0 {
			r--
			resr = tree.Combine(tree.t[r], resr)
		}
		l >>= 1
		r >>= 1
	}
	return tree.Combine(resl, resr)
}

type Group struct {
	l, r, forceDir int
}

func (g Group) Less(other Group) bool {
	return g.r < other.r || (g.r == other.r && (g.l < other.l || (g.l == other.l && g.forceDir < other.forceDir)))
}

type GroupSet struct {
	s map[Group]struct{}
}

func NewGroupSet() *GroupSet {
	return &GroupSet{s: make(map[Group]struct{})}
}

func (gs *GroupSet) Combine(x, y Group) Group {
	if min(x.forceDir, y.forceDir) >= 0 {
		if x.forceDir != y.forceDir {
			panic("Invalid force direction")
		}
	}
	return Group{min(x.l, y.l), max(x.r, y.r), max(x.forceDir, y.forceDir)}
}

func (gs *GroupSet) GetInitialValue(x int) Group {
	return Group{x, x, -1}
}

func (gs *GroupSet) UfReset(x int) {
	gs.s[gs.GetInitialValue(x)] = struct{}{}
}

func (gs *GroupSet) Init(n int) {
	for x := 0; x < n; x++ {
		gs.UfReset(x)
	}
}

func (gs *GroupSet) Lb(x int) (Group, bool) {
	for g := range gs.s {
		if g.l > x {
			return g, false
		}
	}
	return Group{}, true
}

func (gs *GroupSet) Funion(x, y int) {
	it1, found1 := gs.Lb(x)
	it2, found2 := gs.Lb(y)
	if found1 && found2 && it1 != it2 {
		combined := gs.Combine(it1, it2)
		delete(gs.s, it1)
		delete(gs.s, it2)
		gs.s[combined] = struct{}{}
	}
}

func (gs *GroupSet) GetData(x int) Group {
	it, _ := gs.Lb(x)
	return it
}

func (gs *GroupSet) SetData(x int, dat Group) {
	it, _ := gs.Lb(x)
	delete(gs.s, it)
	gs.s[dat] = struct{}{}
}

func (gs *GroupSet) Split(pl, pr, dl, dr int) {
	if !(UNDEF <= dl && dl < 2) || !(UNDEF <= dr && dr < 2) || pl+1 != pr {
		panic("Invalid split parameters")
	}
	itl, _ := gs.Lb(pl)
	itr, _ := gs.Lb(pr)
	if itl.forceDir == -1 && itr.forceDir == -1 {
		g := itl
		delete(gs.s, itl)
		gs.s[Group{g.l, pl, dl}] = struct{}{}
		gs.s[Group{pr, g.r, dr}] = struct{}{}
	} else {
		panic("Invalid split")
	}
}

func (gs *GroupSet) GetDir(x int) int {
	return gs.GetData(x).forceDir
}

type Collision struct {
	id7   Id5
	pos   int
	dirL  int
	dirR  int
}

func (c Collision) Less(other Collision) bool {
	return c.id7 < other.id7
}

var (
	vpos        [100004]int
	v           [100004]int
	probBallDir [100004][2]Mint
	gs          = NewGroupSet()
	seg         = NewMulSegTree(100004)
	id10        = NewMint(1)
)

func ProbForce(dir, l, r int) Mint {
	return seg.Query(l, r).prod[dir]
}

func Id1(l, r int) Mint {
	return seg.Query(l, r).sumlr
}

func Id2(l, r int) Mint {
	lo, hi := INF, -INF
	ans := NewMint(1)
	for pos := l; pos <= r; {
		dat := gs.GetData(pos)
		lo = min(lo, dat.l)
		hi = max(hi, dat.r)
		var mult Mint
		if dat.forceDir == UNDEF {
			mult = seg.Query(dat.l, dat.r).sumlr
		} else {
			mult = seg.Query(dat.l, dat.r).prod[dat.forceDir]
		}
		ans = ans.Mul(mult)
		pos = dat.r + 1
	}
	return ans
}

func Id12(l, r int) {
	dl := gs.GetData(l)
	dr := gs.GetData(r)

	if (dl.forceDir == 1 && dr.forceDir == -1) || (dl.forceDir == -1 && dr.forceDir == 0) || (dl.forceDir == -1 && dr.forceDir == -1) {
		den := Id2(dl.l, dr.r)
		gs.Funion(l, r)
		num := Id2(dl.l, dr.r)
		id10 = id10.Mul(num.Div(den))
	} else if dl.forceDir == 0 && dr.forceDir == -1 {
		// Do nothing
	} else if dl.forceDir == -1 && dr.forceDir == 1 {
		// Do nothing
	} else if dl.forceDir >= 0 && dr.forceDir >= 0 {
		if dl.forceDir == dr.forceDir {
			// Do nothing
		} else {
			id10 = NewMint(0)
		}
	} else {
		panic("Invalid direction")
	}
}

func Id3(r Id5) Mint {
	return NewMint(int(r.nu)) // Assuming r.de is always 1 for simplicity
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&vpos[i], &v[i])
		var probR int
		fmt.Scan(&probR)
		probBallDir[i][1] = NewMint(probR).Div(NewMint(100))
		probBallDir[i][0] = NewMint(1).Sub(probBallDir[i][1])
	}
	gs.Init(n)
	seg.Init(n)
	for pos := 0; pos < n; pos++ {
		seg.SetBeforeBuild(pos, SegNode{[2]Mint{probBallDir[pos][0], probBallDir[pos][1]}, probBallDir[pos][0].Add(probBallDir[pos][1]), false})
	}
	seg.Build()

	collisions := make([]Collision, 0, n-1)
	for i := 0; i < n-1; i++ {
		dist := vpos[i+1] - vpos[i]
		id8 := NewId5(int64(dist), int64(v[i+1]+v[i]))
		collisions = append(collisions, Collision{id8, i, 1, 0})

		if v[i] > v[i+1] {
			id6 := NewId5(int64(dist), int64(v[i]-v[i+1]))
			collisions = append(collisions, Collision{id6, i, 1, 1})
		}

		if v[i] < v[i+1] {
			id11 := NewId5(int64(dist), int64(v[i+1]-v[i]))
			collisions = append(collisions, Collision{id11, i, 0, 0})
		}
	}
	sort.Slice(collisions, func(i, j int) bool {
		return collisions[i].Less(collisions[j])
	})

	finalSum := NewMint(0)
	for _, c := range collisions {
		pos := c.pos
		id9 := id10

		dl := gs.GetDir(c.pos)
		dr := gs.GetDir(c.pos + 1)

		if dl != UNDEF && dl != c.dirL {
			continue
		}
		if dr != UNDEF && dr != c.dirR {
			continue
		}
		if c.dirL == 1 && c.dirR == 0 {
			Id12(pos, pos+1)
		} else if c.dirL == 1 && c.dirR == 1 {
			if dl == 1 {
				id10 = NewMint(0)
			} else {
				den := Id2(pos, pos+1)
				gs.Split(c.pos, c.pos+1, 0, UNDEF)
				num := Id2(pos, pos+1)
				id10 = id10.Mul(num.Div(den))
			}
		} else if c.dirL == 0 && c.dirR == 0 {
			if dr == 0 {
				id10 = NewMint(0)
			} else {
				den := Id2(pos, pos+1)
				gs.Split(c.pos, c.pos+1, UNDEF, 1)
				num := Id2(pos, pos+1)
				id10 = id10.Mul(num.Div(den))
			}
		} else {
			panic("Invalid collision direction")
		}

		mintId7 := Id3(c.id7)
		finalSum = finalSum.Add(mintId7.Mul(NewMint(id9.Get() - id10.Get())))
		if id10.Get() == 0 {
			break
		}
	}
	fmt.Println(finalSum.Get())
}
