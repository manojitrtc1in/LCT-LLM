package main

import (
	"fmt"
	"math"
	"math/rand"
	"time"
)

const EPS = 1e-9
const PI = math.Atan(1) * 4
const M = 1000000007

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
	C []int64
}

func NewUnionFind(n int64) *UnionFind {
	C := make([]int64, n)
	for i := int64(0); i < n; i++ {
		C[i] = i
	}
	return &UnionFind{C}
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

func id11(a, b int64, x, y *int64) int64 {
	xx, yy := *y, *x
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

func modInverse(a, n int64) int64 {
	var x, y int64
	d := id11(a, n, &x, &y)
	if d > 1 {
		return -1
	}
	return mod(x, n)
}

type id3 struct {
	m, n int64
	B, N []int64
	D   [][]float64
}

func NewId3(A [][]float64, b, c []float64) *id3 {
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
	return &id3{m, n, B, N, D}
}

func (id *id3) Pivot(r, s int64) {
	for i := int64(0); i < id.m+2; i++ {
		if i != r {
			for j := int64(0); j < id.n+2; j++ {
				if j != s {
					id.D[i][j] -= id.D[r][j] * id.D[i][s] / id.D[r][s]
				}
			}
		}
	}
	for j := int64(0); j < id.n+2; j++ {
		if j != s {
			id.D[r][j] /= id.D[r][s]
		}
	}
	for i := int64(0); i < id.m+2; i++ {
		if i != r {
			id.D[i][s] /= -id.D[r][s]
		}
	}
	id.D[r][s] = 1.0 / id.D[r][s]
	id.B[r], id.N[s] = id.N[s], id.B[r]
}

func (id *id3) Simplex(phase int64) bool {
	x := id.m + 1
	if phase == 2 {
		x = id.m
	}
	for {
		s := int64(-1)
		for j := int64(0); j <= id.n; j++ {
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
		r := int64(-1)
		for i := int64(0); i < id.m; i++ {
			if id.D[i][s] < EPS {
				continue
			}
			if r == -1 || id.D[i][id.n+1]/id.D[i][s] < id.D[r][id.n+1]/id.D[r][s] ||
				(id.D[i][id.n+1]/id.D[i][s] == id.D[r][id.n+1]/id.D[r][s] && id.B[i] < id.B[r]) {
				r = i
			}
		}
		if r == -1 {
			return false
		}
		id.Pivot(r, s)
	}
}

func (id *id3) solve(x *[]float64) float64 {
	r := int64(0)
	for i := int64(1); i < id.m; i++ {
		if id.D[i][id.n+1] < id.D[r][id.n+1] {
			r = i
		}
	}
	if id.D[r][id.n+1] < -EPS {
		id.Pivot(r, id.n)
		if !id.Simplex(1) || id.D[id.m+1][id.n+1] < -EPS {
			return -math.MaxFloat64
		}
		for i := int64(0); i < id.m; i++ {
			if id.B[i] == -1 {
				s := int64(-1)
				for j := int64(0); j <= id.n; j++ {
					if s == -1 || id.D[i][j] < id.D[i][s] || (id.D[i][j] == id.D[i][s] && id.N[j] < id.N[s]) {
						s = j
					}
				}
				id.Pivot(i, s)
			}
		}
	}
	if !id.Simplex(2) {
		return math.MaxFloat64
	}
	*x = make([]float64, id.n)
	for i := int64(0); i < id.m; i++ {
		if id.B[i] < id.n {
			(*x)[id.B[i]] = id.D[i][id.n+1]
		}
	}
	return id.D[id.m][id.n+1]
}

func id8(n int64, froms, tos []int64, id16, id4 *[]int64) {
	*id16 = make([]int64, n)
	for i := range *id16 {
		(*id16)[i] = -1
	}
	en := int64(len(froms))
	*id4 = make([]int64, en)
	for i := int64(0); i < en; i++ {
		f := froms[i]
		t := tos[i]
		(*id4)[i] = (*id16)[f]
		(*id16)[f] = i
	}
}

type id18 struct {
	id16, id13, id7, id9, id4 []int64
	s, t                      int64
}

func NewId18(id23, id2, id26, id14, id5 []int64, _s, _t int64) *id18 {
	return &id18{id23, id2, id26, id14, id5, _s, _t}
}

func (id *id18) _findAugPath(id16, id13, id7, id9, id4 []int64, s, t int64, epath *[]int64) int64 {
	id24 := []int64{s}
	id0 := []int64{-1}
	id21 := []int64{-1}
	id27 := []int64{math.MaxInt64}
	inq := make([]bool, len(id16))
	inq[s] = true
	for i := int64(0); i < int64(len(id24)); i++ {
		crt := id24[i]
		f := id27[i]
		for j := id16[crt]; j != -1; j = id4[j] {
			to := id7[j]
			rem := id9[j]
			if inq[to] || rem <= 0 {
				continue
			}
			id24 = append(id24, to)
			id0 = append(id0, i)
			id21 = append(id21, j)
			id27 = append(id27, int64(math.Min(float64(f), float64(rem))))
			inq[to] = true
		}
	}
	for i := int64(0); i < int64(len(id24)); i++ {
		if id24[i] != t {
			continue
		}
		var stk []int64
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

func (id *id18) eval() int64 {
	en := int64(len(id.id13))
	rsd := make(map[[2]int64]int64)
	for i := int64(0); i < en; i++ {
		f := id.id13[i]
		t := id.id7[i]
		rsd[[2]int64{f, t}] += id.id9[i]
		rsd[[2]int64{t, f}] += 0
	}
	nei := make(map[[2]int64]int64)
	ren := int64(0)
	for er := range rsd {
		nei[er] = ren
		ren++
	}
	rvn := int64(len(id.id16))
	id12 := make([]int64, rvn)
	for i := range id12 {
		id12[i] = -1
	}
	id20 := make([]int64, ren)
	id1 := make([]int64, ren)
	id10 := make([]int64, ren)
	id15 := make([]int64, ren)
	id25 := make([]int64, ren)

	rei := int64(0)
	for er := range rsd {
		f := er[0]
		t := er[1]
		c := rsd[er]
		id20[rei] = f
		id1[rei] = t
		id10[rei] = c
		id25[rei] = nei[[2]int64{t, f}]
		id15[rei] = id12[f]
		id12[f] = rei
		rei++
	}

	sol := int64(0)
	var epath []int64
	for {
		epath = epath[:0]
		res := id._findAugPath(id12, id20, id1, id10, id15, id.s, id.t, &epath)
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
	fmt.Scan(&a, &b)
	n := int64(len(a))
	ar := make([]byte, n)
	for i := int64(0); i < n; i++ {
		ar[i] = ccinv(a[n-i-1])
	}
	va, vb := int64(0), int64(0)
	p := int64(1)
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
