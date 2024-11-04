package main

import (
	"fmt"
	"math"
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

func id22(u, v PT) float64 {
	return dot(u, v) / math.Sqrt(dot(u, u)*dot(v, v))
}

func id6(u, v PT) float64 {
	return cross(u, v) / math.Sqrt(dot(u, u)*dot(v, v))
}

func id17(v PT) float64 {
	return math.Atan2(v.y, v.x)
}

type UnionFind struct {
	C []int
}

func NewUnionFind(n int) *UnionFind {
	c := make([]int, n)
	for i := 0; i < n; i++ {
		c[i] = i
	}
	return &UnionFind{C: c}
}

func (uf *UnionFind) find(x int) int {
	if uf.C[x] == x {
		return x
	}
	uf.C[x] = uf.find(uf.C[x])
	return uf.C[x]
}

func (uf *UnionFind) merge(x, y int) {
	uf.C[uf.find(x)] = uf.find(y)
}

func mod(x, m int) int {
	return ((x%m) + m) % m
}

func gcd(a, b int) int {
	for b > 0 {
		a %= b
		a, b = b, a
	}
	return a
}

func id11(a, b int, x, y *int) int {
	xx, yy := 0, 1
	*x, *y = 1, 0
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

func mod_inverse(a, n int) int {
	var x, y int
	d := id11(a, n, &x, &y)
	if d > 1 {
		return -1
	}
	return mod(x, n)
}

type id3 struct {
	m, n int
	B, N []int
	D    [][]float64
}

func Newid3(A [][]float64, b, c []float64) *id3 {
	m, n := len(b), len(c)
	N := make([]int, n+1)
	B := make([]int, m)
	D := make([][]float64, m+2)
	for i := 0; i < m+2; i++ {
		D[i] = make([]float64, n+2)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			D[i][j] = A[i][j]
		}
		B[i] = n + i
		D[i][n] = -1
		D[i][n+1] = b[i]
	}
	for j := 0; j < n; j++ {
		N[j] = j
		D[m][j] = -c[j]
	}
	N[n] = -1
	D[m+1][n] = 1
	return &id3{
		m: m, n: n, B: B, N: N, D: D,
	}
}

func (id *id3) Pivot(r, s int) {
	for i := 0; i < id.m+2; i++ {
		if i != r {
			for j := 0; j < id.n+2; j++ {
				if j != s {
					id.D[i][j] -= id.D[r][j] * id.D[i][s] / id.D[r][s]
				}
			}
		}
	}
	for j := 0; j < id.n+2; j++ {
		if j != s {
			id.D[r][j] /= id.D[r][s]
		}
	}
	for i := 0; i < id.m+2; i++ {
		if i != r {
			id.D[i][s] /= -id.D[r][s]
		}
	}
	id.D[r][s] = 1.0 / id.D[r][s]
	id.B[r], id.N[s] = id.N[s], id.B[r]
}

func (id *id3) Simplex(phase int) bool {
	x := id.m + 1
	for {
		s := -1
		for j := 0; j <= id.n; j++ {
			if phase == 2 && id.N[j] == -1 {
				continue
			}
			if s == -1 || id.D[x][j] < id.D[x][s] || (id.D[x][j] == id.D[x][s] && id.N[j] < id.N[s]) {
				s = j
			}
		}
		if id.D[x][s] > -EPS {
			return true
		}
		r := -1
		for i := 0; i < id.m; i++ {
			if id.D[i][s] < EPS {
				continue
			}
			if r == -1 || id.D[i][n+1]/id.D[i][s] < id.D[r][n+1]/id.D[r][s] || (id.D[i][n+1]/id.D[i][s]) == (id.D[r][n+1]/id.D[r][s]) && id.B[i] < id.B[r] {
				r = i
			}
		}
		if r == -1 {
			return false
		}
		id.Pivot(r, s)
	}
}

func (id *id3) solve(x []float64) float64 {
	r := 0
	for i := 1; i < id.m; i++ {
		if id.D[i][n+1] < id.D[r][n+1] {
			r = i
		}
	}
	if id.D[r][n+1] < -EPS {
		id.Pivot(r, n)
		if !id.Simplex(1) || id.D[m+1][n+1] < -EPS {
			return -math.Inf(1)
		}
		for i := 0; i < id.m; i++ {
			if id.B[i] == -1 {
				s := -1
				for j := 0; j <= id.n; j++ {
					if s == -1 || id.D[i][j] < id.D[i][s] || (id.D[i][j] == id.D[i][s] && id.N[j] < id.N[s]) {
						s = j
					}
				}
				id.Pivot(i, s)
			}
		}
	}
	if !id.Simplex(2) {
		return math.Inf(1)
	}
	for i := 0; i < id.m; i++ {
		if id.B[i] < id.n {
			x[id.B[i]] = id.D[i][n+1]
		}
	}
	return id.D[id.m][n+1]
}

type id8 struct {
	id16 []int
	id4  []int
}

func Newid8(n int, froms, tos []int) *id8 {
	id16 := make([]int, n)
	for i := 0; i < n; i++ {
		id16[i] = -1
	}
	en := len(froms)
	id4 := make([]int, en)
	for i := 0; i < en; i++ {
		f := froms[i]
		t := tos[i]
		id4[i] = id16[f]
		id16[f] = i
	}
	return &id8{
		id16: id16,
		id4:  id4,
	}
}

type id18 struct {
	id23, id2, id26, id14, id5, id4 []int
	s, t                            int
}

func Newid18(id23, id2, id26, id14, id5, id4 []int, s, t int) *id18 {
	return &id18{
		id23: id23,
		id2:  id2,
		id26: id26,
		id14: id14,
		id5:  id5,
		id4:  id4,
		s:    s,
		t:    t,
	}
}

func (id *id18) _find_aug_path(id16, id13, id7, id9, id4 []int, s, t int, epath *[]int) int {
	var id24, id0, id21, id27 []int
	inq := make([]bool, len(id16))

	id24 = append(id24, s)
	id0 = append(id0, -1)
	id21 = append(id21, -1)
	id27 = append(id27, math.MaxInt64)
	inq[s] = true
	for i := 0; i < len(id24); i++ {
		crt := id24[i]
		f := id27[i]
		for j := id16[crt]; j != -1; j = id4[j] {
			to := id7[j]
			rem := id9[j]
			if inq[to] {
				continue
			}
			if rem <= 0 {
				continue
			}
			id24 = append(id24, to)
			id0 = append(id0, i)
			id21 = append(id21, j)
			id27 = append(id27, int(math.Min(float64(f), float64(rem))))
			inq[to] = true
		}
	}

	for i := 0; i < len(id24); i++ {
		if id24[i] != t {
			continue
		}
		var stk []int
		for j := i; j > 0; j = id0[j] {
			stk = append(stk, id21[j])
		}
		for len(stk) > 0 {
			*epath = append(*epath, stk[len(stk)-1])
			stk = stk[:len(stk)-1]
		}
		return id27[i]
	}
	return 0
}

func (id *id18) eval() int {
	rsd := make(map[[2]int]int)
	for i := 0; i < len(id.id13); i++ {
		f := id.id13[i]
		t := id.id7[i]
		rsd[[2]int{f, t}] += id.id9[i]
		rsd[[2]int{t, f}] += 0
	}
	nei := make(map[[2]int]int)
	ren := 0
	for er := range rsd {
		nei[er] = ren
		ren++
	}
	rvn := len(id.id16)
	id12 := make([]int, rvn)
	id20 := make([]int, ren)
	id1 := make([]int, ren)
	id10 := make([]int, ren)
	id15 := make([]int, ren)
	id25 := make([]int, ren)
	rei := 0
	for er, c := range rsd {
		f := er[0]
		t := er[1]
		id20[rei] = f
		id1[rei] = t
		id10[rei] = c
		id25[rei] = nei[[2]int{t, f}]
		id15[rei] = id12[f]
		id12[f] = rei
		rei++
	}

	sol := 0
	var epath []int
	for {
		epath = nil
		res := id._find_aug_path(id12, id20, id1, id10, id15, id.s, id.t, &epath)
		if res == 0 {
			break
		}
		for _, ei := range epath {
			id10[ei] -= res
			id10[id25[ei]] += res
		}
		sol += res
	}
	return sol
}

type id19 struct {
	v   []float64
	opr []int

	opd []float64
	nxt []int
	LEFT, RGHT int
	fnx        func(int, float64) float64
	fab        func(float64, float64) float64
}

func Newid19(l, r int, v float64, fnx func(int, float64) float64, fab func(float64, float64) float64) *id19 {
	vs := []float64{fnx(r-l+1, v)}
	opr := []int{0}
	opd := []float64{v}
	nxt := []int{-1}
	return &id19{
		v:    vs,
		opr:  opr,
		opd:  opd,
		nxt:  nxt,
		LEFT: l,
		RGHT: r,
		fnx:  fnx,
		fab:  fab,
	}
}

func (id *id19) _split(i, l0, r0 int) {
	if id.nxt[i] != -1 {
		return
	}
	if id.opr[i] != 0 {
		return
	}
	if l0 >= r0 {
		return
	}
	n := len(id.v)
	id.nxt[i] = n
	m0 := (l0 + r0) / 2
	id.v = append(id.v, id.fnx(m0-l0+1, id.opd[i]))
	id.v = append(id.v, id.fnx(r0-m0, id.opd[i]))
	id.opr = append(id.opr, 0)
	id.opr = append(id.opr, 0)
	id.opd = append(id.opd, id.opd[i])
	id.opd = append(id.opd, id.opd[i])
	id.nxt = append(id.nxt, -1)
	id.nxt = append(id.nxt, -1)
}

func (id *id19) _pushdown(i, l0, r0 int) {
	if id.opr[i] == -1 {
		return
	}
	m0 := (l0 + r0) / 2
	if id.nxt[i] == -1 {
		id._split(i, l0, r0)
	} else if id.opr[i] >= 0 {
		id._set(id.nxt[i], l0, m0, l0, m0, id.opr[i], id.opd[i])
		id._set(id.nxt[i]+1, m0+1, r0, m0+1, r0, id.opr[i], id.opd[i])
	}
	id.opr[i] = -1
}

func (id *id19) _set(i, l0, r0, l1, r1, o1 int, v1 float64) {
	if l1 < l0 || r1 > r0 {
		return
	}
	if l0 == l1 && r0 == r1 {
		if o1 == 0 {
			id.v[i] = id.fnx(r0-l0+1, v1)
			id.opr[i] = 0
			id.opd[i] = v1
		} else if o1 == 1 {
			id.v[i] = id.fab(id.v[i], id.fnx(r0-l0+1, v1))
			if id.opr[i] == -1 {
				id.opr[i] = 1
				id.opd[i] = v1
			} else if id.opr[i] == 0 {
				id.opr[i] = 0
				id.opd[i] = id.fab(id.opd[i], v1)
			} else if id.opr[i] == 1 {
				id.opr[i] = 1
				id.opd[i] = id.fab(id.opd[i], v1)
			}
		}
		return
	}
	m0 := (l0 + r0) / 2
	id._pushdown(i, l0, r0)
	if l1 <= m0 {
		id._set(id.nxt[i], l0, m0, l1, int(math.Min(float64(r1), float64(m0))), o1, v1)
	}
	if r1 > m0 {
		id._set(id.nxt[i]+1, m0+1, r0, int(math.Max(float64(l1), float64(m0+1))), r1, o1, v1)
	}
	id.v[i] = id.fab(id.v[id.nxt[i]], id.v[id.nxt[i]+1])
}

func (id *id19) get(i, l0, r0, l1, r1 int) float64 {
	if l0 <= l1 && r1 <= r0 {
		if l0 == l1 && r1 == r0 {
			return id.v[i]
		}
		id._pushdown(i, l0, r0)
		m0 := (l0 + r0) / 2
		if r1 <= m0 {
			return id.get(id.nxt[i], l0, m0, l1, r1)
		}
		if m0+1 <= l1 {
			return id.get(id.nxt[i]+1, m0+1, r0, l1, r1)
		}
		lv := id.get(id.nxt[i], l0, m0, l1, m0)
		rv := id.get(id.nxt[i]+1, m0+1, r0, m0+1, r1)
		return id.fab(lv, rv)
	}
	return 0
}

func (id *id19) updres(l1, r1 int, v1 float64) {
	id._set(0, id.LEFT, id.RGHT, l1, r1, 1, v1)
}

func (id *id19) setval(l1, r1 int, v1 float64) {
	id._set(0, id.LEFT, id.RGHT, l1, r1, 0, v1)
}

func (id *id19) getVal(l1, r1 int) float64 {
	return id.get(0, id.LEFT, id.RGHT, l1, r1)
}

func opp(a, b byte) bool {
	return a == 'W' && b == 'E' || a == 'E' && b == 'W' || a == 'S' && b == 'N' || a == 'N' && b == 'S'
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
	var r string
	fmt.Scan(&r)
	var a string
	fmt.Scan(&a)
	var b string
	fmt.Scan(&b)
	n := len(a)
	ar := make([]byte, n)
	for i := 0; i < n; i++ {
		ar[i] = ccinv(a[n-1-i])
	}
	va := 0
	vb := 0
	p := 1
	for i := 0; i < n; i++ {
		va = (va*131 + int(ar[i])) % M
		vb = (vb + int(b[n-1-i])*p) % M
		p = (p * 131) % M
		if vb == va {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
