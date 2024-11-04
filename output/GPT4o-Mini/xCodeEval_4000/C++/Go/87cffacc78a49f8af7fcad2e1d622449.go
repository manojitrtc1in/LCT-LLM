package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const (
	EPS = 1e-9
	PI  = math.Atan(1) * 4
	M   = 1000000007
)

type PT struct {
	x, y float64
}

func (p PT) add(q PT) PT {
	return PT{p.x + q.x, p.y + q.y}
}

func (p PT) sub(q PT) PT {
	return PT{p.x - q.x, p.y - q.y}
}

func (p PT) mul(c float64) PT {
	return PT{p.x * c, p.y * c}
}

func (p PT) div(c float64) PT {
	return PT{p.x / c, p.y / c}
}

func dot(p, q PT) float64 {
	return p.x*q.x + p.y*q.y
}

func dist2(p, q PT) float64 {
	return dot(p.sub(q), p.sub(q))
}

func cross(p, q PT) float64 {
	return p.x*q.y - p.y*q.x
}

func cosU2V(u, v PT) float64 {
	return dot(u, v) / math.Sqrt(dot(u, u)*dot(v, v))
}

func sinU2V(u, v PT) float64 {
	return cross(u, v) / math.Sqrt(dot(u, u)*dot(v, v))
}

func vector2angle(v PT) float64 {
	return math.Atan2(v.y, v.x)
}

type UnionFind struct {
	C []int64
}

func NewUnionFind(n int64) UnionFind {
	C := make([]int64, n)
	for i := int64(0); i < n; i++ {
		C[i] = i
	}
	return UnionFind{C: C}
}

func (uf *UnionFind) find(x int64) int64 {
	if uf.C[x] == x {
		return x
	}
	uf.C[x] = uf.find(uf.C[x])
	return uf.C[x]
}

func (uf *UnionFind) merge(x, y int64) {
	uf.C[uf.find(x)] = uf.find(y)
}

func mod(x, m int64) int64 {
	return ((x % m) + m) % m
}

func gcd(a, b int64) int64 {
	for b > 0 {
		a, b = b, a%b
	}
	return a
}

func extendedEuclid(a, b int64, x, y *int64) int64 {
	xx, yy := *y, *x
	*x, *y = 0, 1
	for b != 0 {
		q := a / b
		t := b
		b = a % b
		a = t
		t = xx
		xx = *x - q*xx
		*x = t
		t = yy
		yy = *y - q*yy
		*y = t
	}
	return a
}

func modInverse(a, n int64) int64 {
	var x, y int64
	d := extendedEuclid(a, n, &x, &y)
	if d > 1 {
		return -1
	}
	return mod(x, n)
}

type LPSolver struct {
	m, n int64
	B, N []int64
	D    [][]float64
}

func NewLPSolver(A [][]float64, b, c []float64) LPSolver {
	m := int64(len(b))
	n := int64(len(c))
	N := make([]int64, n+1)
	B := make([]int64, m)
	D := make([][]float64, m+2)
	for i := range D {
		D[i] = make([]float64, n+2)
	}
	for i := int64(0); i < m; i++ {
		for j := int64(0); j < n; j++ {
			D[i][j] = A[i][j]
		}
		B[i] = n + i
		D[i][n] = -1
		D[i][n+1] = b[i]
	}
	for j := int64(0); j < n; j++ {
		N[j] = j
		D[m][j] = -c[j]
	}
	N[n] = -1
	D[m+1][n] = 1
	return LPSolver{m: m, n: n, B: B, N: N, D: D}
}

func (lp *LPSolver) Pivot(r, s int64) {
	for i := int64(0); i < lp.m+2; i++ {
		if i != r {
			for j := int64(0); j < lp.n+2; j++ {
				if j != s {
					lp.D[i][j] -= lp.D[r][j] * lp.D[i][s] / lp.D[r][s]
				}
			}
		}
	}
	for j := int64(0); j < lp.n+2; j++ {
		if j != s {
			lp.D[r][j] /= lp.D[r][s]
		}
	}
	for i := int64(0); i < lp.m+2; i++ {
		if i != r {
			lp.D[i][s] /= -lp.D[r][s]
		}
	}
	lp.D[r][s] = 1.0 / lp.D[r][s]
	lp.B[r], lp.N[s] = lp.N[s], lp.B[r]
}

func (lp *LPSolver) Simplex(phase int64) bool {
	x := lp.m + 1
	if phase == 2 {
		x = lp.m
	}
	for {
		s := int64(-1)
		for j := int64(0); j <= lp.n; j++ {
			if phase == 2 && lp.N[j] == -1 {
				continue
			}
			if s == -1 || lp.D[x][j] < lp.D[x][s] || (lp.D[x][j] == lp.D[x][s] && lp.N[j] < lp.N[s]) {
				s = j
			}
		}
		if lp.D[x][s] > -EPS {
			return true
		}
		r := int64(-1)
		for i := int64(0); i < lp.m; i++ {
			if lp.D[i][s] < EPS {
				continue
			}
			if r == -1 || lp.D[i][lp.n+1]/lp.D[i][s] < lp.D[r][lp.n+1]/lp.D[r][s] ||
				(lp.D[i][lp.n+1]/lp.D[i][s] == lp.D[r][lp.n+1]/lp.D[r][s] && lp.B[i] < lp.B[r]) {
				r = i
			}
		}
		if r == -1 {
			return false
		}
		lp.Pivot(r, s)
	}
}

func (lp *LPSolver) Solve(x []float64) float64 {
	r := int64(0)
	for i := int64(1); i < lp.m; i++ {
		if lp.D[i][lp.n+1] < lp.D[r][lp.n+1] {
			r = i
		}
	}
	if lp.D[r][lp.n+1] < -EPS {
		lp.Pivot(r, lp.n)
		if !lp.Simplex(1) || lp.D[lp.m+1][lp.n+1] < -EPS {
			return -math.MaxFloat64
		}
		for i := int64(0); i < lp.m; i++ {
			if lp.B[i] == -1 {
				s := int64(-1)
				for j := int64(0); j <= lp.n; j++ {
					if s == -1 || lp.D[i][j] < lp.D[i][s] || (lp.D[i][j] == lp.D[i][s] && lp.N[j] < lp.N[s]) {
						s = j
					}
				}
				lp.Pivot(i, s)
			}
		}
	}
	if !lp.Simplex(2) {
		return math.MaxFloat64
	}
	x = make([]float64, lp.n)
	for i := int64(0); i < lp.m; i++ {
		if lp.B[i] < lp.n {
			x[lp.B[i]] = lp.D[i][lp.n+1]
		}
	}
	return lp.D[lp.m][lp.n+1]
}

func edgelist2adjlists(n int64, froms, tos []int64, v2e0, e2n *[]int64) {
	*v2e0 = make([]int64, n)
	for i := range *v2e0 {
		(*v2e0)[i] = -1
	}
	en := int64(len(froms))
	*e2n = make([]int64, en)
	for i := int64(0); i < en; i++ {
		f := froms[i]
		t := tos[i]
		(*e2n)[i] = (*v2e0)[f]
		(*v2e0)[f] = i
	}
}

type FordFulk struct {
	v2e0, e2f, e2t, e2c, e2n []int64
	s, t                       int64
}

func NewFordFulk(v2e0, e2f, e2t, e2c, e2n []int64, s, t int64) FordFulk {
	return FordFulk{v2e0: v2e0, e2f: e2f, e2t: e2t, e2c: e2c, e2n: e2n, s: s, t: t}
}

func (ff *FordFulk) findAugPath(v2e0, e2f, e2t, e2c, e2n []int64, s, t int64, epath *[]int64) int64 {
	q2v := []int64{s}
	q2p := []int64{-1}
	q2e := []int64{-1}
	q2f := []int64{int64(math.MaxInt64)}
	inq := make([]bool, len(v2e0))
	inq[s] = true

	for i := int64(0); i < int64(len(q2v)); i++ {
		crt := q2v[i]
		f := q2f[i]
		for j := v2e0[crt]; j != -1; j = e2n[j] {
			to := e2t[j]
			rem := e2c[j]
			if inq[to] || rem <= 0 {
				continue
			}
			q2v = append(q2v, to)
			q2p = append(q2p, i)
			q2e = append(q2e, j)
			q2f = append(q2f, min(f, rem))
			inq[to] = true
		}
	}

	for i := int64(0); i < int64(len(q2v)); i++ {
		if q2v[i] != t {
			continue
		}
		var stk []int64
		for j := i; j > 0; j = q2p[j] {
			stk = append(stk, q2e[j])
		}
		*epath = append(*epath, stk...)
		return q2f[i]
	}
	return 0
}

func (ff *FordFulk) eval() int64 {
	en := int64(len(ff.e2f))
	rsd := make(map[[2]int64]int64)
	for i := int64(0); i < en; i++ {
		f := ff.e2f[i]
		t := ff.e2t[i]
		rsd[[2]int64{f, t}] += ff.e2c[i]
		rsd[[2]int64{t, f}] += 0
	}
	nei := make(map[[2]int64]int64)
	ren := int64(0)
	for er := range rsd {
		nei[er] = ren
		ren++
	}
	rvn := int64(len(ff.v2e0))
	rv2e0 := make([]int64, rvn)
	for i := range rv2e0 {
		rv2e0[i] = -1
	}
	re2f := make([]int64, ren)
	re2t := make([]int64, ren)
	re2c := make([]int64, ren)
	re2n := make([]int64, ren)
	re2p := make([]int64, ren)

	rei := int64(0)
	for er, c := range rsd {
		f := er[0]
		t := er[1]
		re2f[rei] = f
		re2t[rei] = t
		re2c[rei] = c
		re2p[rei] = nei[[2]int64{t, f}]
		re2n[rei] = rv2e0[f]
		rv2e0[f] = rei
		rei++
	}

	sol := int64(0)
	var epath []int64
	for {
		epath = nil
		res := ff.findAugPath(rv2e0, re2f, re2t, re2c, re2n, ff.s, ff.t, &epath)
		if res == 0 {
			break
		}
		for _, ei := range epath {
			re2c[ei] -= res
			re2c[re2p[ei]] += res
		}
		sol += res
	}
	return sol
}

type LazySegTree1D struct {
	v, opr, opd, nxt []int64
	LEFT, RGHT      int64
	fnx             func(int64, int64) int64
	fab             func(int64, int64) int64
}

func NewLazySegTree1D(_l, _r int64, _v int64, _fnx func(int64, int64) int64, _fab func(int64, int64) int64) LazySegTree1D {
	v := make([]int64, 1)
	opr := make([]int64, 1)
	opd := make([]int64, 1)
	nxt := make([]int64, 1)
	v[0] = _fnx(_r-_l+1, _v)
	opr[0] = 0
	opd[0] = _v
	nxt[0] = -1
	return LazySegTree1D{v: v, opr: opr, opd: opd, nxt: nxt, LEFT: _l, RGHT: _r, fnx: _fnx, fab: _fab}
}

func (lst *LazySegTree1D) split(i, l0, r0 int64) {
	if lst.nxt[i] != -1 || lst.opr[i] != 0 || l0 >= r0 {
		return
	}
	n := len(lst.v)
	lst.nxt[i] = int64(n)
	m0 := (l0 + r0) / 2
	lst.v = append(lst.v, lst.fnx(m0-l0+1, lst.opd[i]))
	lst.v = append(lst.v, lst.fnx(r0-m0, lst.opd[i]))
	lst.opr = append(lst.opr, 0)
	lst.opr = append(lst.opr, 0)
	lst.opd = append(lst.opd, lst.opd[i])
	lst.opd = append(lst.opd, lst.opd[i])
	lst.nxt = append(lst.nxt, -1)
	lst.nxt = append(lst.nxt, -1)
}

func (lst *LazySegTree1D) pushdown(i, l0, r0 int64) {
	if lst.opr[i] == -1 {
		return
	}
	m0 := (l0 + r0) / 2
	if lst.nxt[i] == -1 {
		lst.split(i, l0, r0)
	} else if lst.opr[i] >= 0 {
		lst.set(lst.nxt[i], l0, m0, l0, m0, lst.opr[i], lst.opd[i])
		lst.set(lst.nxt[i]+1, m0+1, r0, m0+1, r0, lst.opr[i], lst.opd[i])
	}
	lst.opr[i] = -1
}

func (lst *LazySegTree1D) set(i, l0, r0, l1, r1, o1 int64, v1 int64) {
	if l1 >= l0 && r1 <= r0 {
		if l0 == l1 && r0 == r1 {
			if o1 == 0 {
				lst.v[i] = lst.fnx(r0-l0+1, v1)
				lst.opr[i] = 0
				lst.opd[i] = v1
			} else if o1 == 1 {
				lst.v[i] = lst.fab(lst.v[i], lst.fnx(r0-l0+1, v1))
				if lst.opr[i] == -1 {
					lst.opr[i] = 1
					lst.opd[i] = v1
				} else if lst.opr[i] == 0 {
					lst.opr[i] = 0
					lst.opd[i] = lst.fab(lst.opd[i], v1)
				} else if lst.opr[i] == 1 {
					lst.opr[i] = 1
					lst.opd[i] = lst.fab(lst.opd[i], v1)
				}
			}
			return
		}
		m0 := (l0 + r0) / 2
		lst.pushdown(i, l0, r0)
		if l1 <= m0 {
			lst.set(lst.nxt[i], l0, m0, l1, min(r1, m0), o1, v1)
		}
		if r1 > m0 {
			lst.set(lst.nxt[i]+1, m0+1, r0, max(l1, m0+1), r1, o1, v1)
		}
		lst.v[i] = lst.fab(lst.v[lst.nxt[i]], lst.v[lst.nxt[i]+1])
	}
}

func (lst *LazySegTree1D) get(i, l0, r0, l1, r1 int64) int64 {
	if l0 <= l1 && r1 <= r0 {
		if l0 == l1 && r1 == r0 {
			return lst.v[i]
		}
		lst.pushdown(i, l0, r0)
		m0 := (l0 + r0) / 2
		if r1 <= m0 {
			return lst.get(lst.nxt[i], l0, m0, l1, r1)
		}
		if m0+1 <= l1 {
			return lst.get(lst.nxt[i]+1, m0+1, r0, l1, r1)
		}
		lv := lst.get(lst.nxt[i], l0, m0, l1, m0)
		rv := lst.get(lst.nxt[i]+1, m0+1, r0, m0+1, r1)
		return lst.fab(lv, rv)
	}
	return 0
}

func (lst *LazySegTree1D) updres(l1, r1 int64, v1 int64) {
	lst.set(0, lst.LEFT, lst.RGHT, l1, r1, 1, v1)
}

func (lst *LazySegTree1D) setval(l1, r1 int64, v1 int64) {
	lst.set(0, lst.LEFT, lst.RGHT, l1, r1, 0, v1)
}

func (lst *LazySegTree1D) getVal(l1, r1 int64) int64 {
	return lst.get(0, lst.LEFT, lst.RGHT, l1, r1)
}

func opp(a, b byte) bool {
	return (a == 'W' && b == 'E') || (a == 'E' && b == 'W') || (a == 'S' && b == 'N') || (a == 'N' && b == 'S')
}

func ccinv(x byte) byte {
	switch x {
	case 'N':
		return 'S'
	case 'S':
		return 'N'
	case 'W':
		return 'E'
	case 'E':
		return 'W'
	}
	return 'W'
}

func main() {
	rand.Seed(time.Now().UnixNano())
	var r string
	fmt.Scan(&r)
	var a, b string
	fmt.Scan(&a)
	fmt.Scan(&b)
	n := int64(len(a))
	ar := make([]byte, n)
	for i := int64(0); i < n; i++ {
		ar[i] = ccinv(a[n-i-1])
	}
	va, vb, p := int64(0), int64(0), int64(1)
	for i, j := int64(0), n-1; i < n; i, j = i+1, j-1 {
		va = (va*131 + int64(ar[i])) % M
		vb = (vb + int64(b[j])*p) % M
		p = (p * 131) % M
		if vb == va {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
