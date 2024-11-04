package main

import (
	"fmt"
)

const (
	MOD = 1000000007
	INF = 1 << 61
)

type Pair struct {
	first, second int64
}

type Edge struct {
	to, rev int
	cap     int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	G[from] = append(G[from], Edge{to, len((*G)[to]) + btoi(from == to), cap})
	if revFlag {
		(*G)[to] = append((*G)[to], Edge{from, len((*G)[from]) - 1, revCap})
	}
}

func id0(G *Graph, v, t int, f int64, used *[]bool) int64 {
	if v == t {
		return f
	}
	(*used)[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := &(*G)[v][i]
		if !(*used)[e.to] && e.cap > 0 {
			d := id0(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int) int64 {
	flow := int64(0)
	for {
		used := make([]bool, len(*G))
		f := id0(G, s, t, INF, &used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func id2(G *Graph, s int, d, negative *[]int64) {
	*d = make([]int64, len(*G))
	*negative = make([]int64, len(*G))
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	for i := 0; i < len(*d); i++ {
		(*negative)[i] = 0
	}
	(*d)[s] = 0
	for k := 0; k < len(*G)-1; k++ {
		for i := 0; i < len(*G); i++ {
			for j := 0; j < len((*G)[i]); j++ {
				if (*d)[i] != INF && (*d)[(*G)[i][j].to] > (*d)[i]+(*G)[i][j].cap {
					(*d)[(*G)[i][j].to] = (*d)[i] + (*G)[i][j].cap
				}
			}
		}
	}
	for k := 0; k < len(*G)-1; k++ {
		for i := 0; i < len(*G); i++ {
			for j := 0; j < len((*G)[i]); j++ {
				if (*d)[i] != INF && (*d)[(*G)[i][j].to] > (*d)[i]+(*G)[i][j].cap {
					(*d)[(*G)[i][j].to] = (*d)[i] + (*G)[i][j].cap
					(*negative)[(*G)[i][j].to] = 1
				}
				if (*negative)[i] == 1 {
					(*negative)[(*G)[i][j].to] = 1
				}
			}
		}
	}
}

func dijkstra(G *Graph, s int, d *[]int64) {
	*d = make([]int64, len(*G))
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	(*d)[s] = 0
	q := make([]Pair, 0)
	q = append(q, Pair{0, int64(s)})
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		if (*d)[a.second] < a.first {
			continue
		}
		for i := 0; i < len((*G)[a.second]); i++ {
			e := (*G)[a.second][i]
			if (*d)[e.to] > (*d)[a.second]+e.cap {
				(*d)[e.to] = (*d)[a.second] + e.cap
				q = append(q, Pair{(*d)[e.to], int64(e.to)})
			}
		}
	}
}

func id4(G *Graph, d *[][]int64) {
	*d = make([][]int64, len(*G))
	for i := 0; i < len(*d); i++ {
		(*d)[i] = make([]int64, len(*G))
	}
	for i := 0; i < len(*d); i++ {
		for j := 0; j < len((*G)[i]); j++ {
			chmin(&(*d)[i][(*G)[i][j].to], (*G)[i][j].cap)
		}
	}
	for i := 0; i < len(*G); i++ {
		for j := 0; j < len(*G); j++ {
			for k := 0; k < len(*G); k++ {
				if (*d)[j][i] != INF && (*d)[i][k] != INF {
					chmin(&(*d)[j][k], (*d)[j][i]+(*d)[i][k])
				}
			}
		}
	}
}

func tsort(graph *Graph, order *[]int) bool {
	n := len(*graph)
	k := 0
	in := make([]int, n)
	for _, es := range *graph {
		for _, e := range es {
			in[e.to]++
		}
	}
	que := make([]int, 0)
	for i := 0; i < n; i++ {
		if in[i] == 0 {
			que = append(que, i)
		}
	}
	for len(que) > 0 {
		v := que[0]
		que = que[1:]
		*order = append(*order, v)
		for _, e := range (*graph)[v] {
			in[e.to]--
			if in[e.to] == 0 {
				que = append(que, e.to)
			}
		}
	}
	if len(*order) != n {
		return false
	} else {
		return true
	}
}

type Lca struct {
	n, log2_n int
	parent    [][]int
	depth     []int
}

func NewLca(g *Graph, root int) *Lca {
	n := len(*g)
	log2_n := int(log2(float64(n))) + 1
	parent := make([][]int, log2_n)
	for i := 0; i < log2_n; i++ {
		parent[i] = make([]int, n)
	}
	depth := make([]int, n)
	dfs(g, root, -1, 0, &parent, &depth)
	for k := 0; k+1 < log2_n; k++ {
		for v := 0; v < len(*g); v++ {
			if parent[k][v] < 0 {
				parent[k+1][v] = -1
			} else {
				parent[k+1][v] = parent[k][parent[k][v]]
			}
		}
	}
	return &Lca{n, log2_n, parent, depth}
}

func dfs(g *Graph, v, p, d int, parent *[][]int, depth *[]int) {
	(*parent)[0][v] = p
	(*depth)[v] = d
	for _, e := range (*g)[v] {
		if e.to != p {
			dfs(g, e.to, v, d+1, parent, depth)
		}
	}
}

func (lca *Lca) Get(u, v int) int {
	if lca.depth[u] > lca.depth[v] {
		u, v = v, u
	}
	for k := 0; k < lca.log2_n; k++ {
		if (lca.depth[v]-lca.depth[u])>>k&1 == 1 {
			v = lca.parent[k][v]
		}
	}
	if u == v {
		return u
	}
	for k := lca.log2_n - 1; k >= 0; k-- {
		if lca.parent[k][u] != lca.parent[k][v] {
			u = lca.parent[k][u]
			v = lca.parent[k][v]
		}
	}
	return lca.parent[0][u]
}

type UnionFind struct {
	data []int
	n    int
}

func NewUnionFind(size int) *UnionFind {
	data := make([]int, size)
	for i := 0; i < size; i++ {
		data[i] = -1
	}
	return &UnionFind{data, size}
}

func (uf *UnionFind) Merge(x, y int) bool {
	x = uf.Root(x)
	y = uf.Root(y)
	if x != y {
		if uf.data[y] < uf.data[x] {
			x, y = y, x
		}
		uf.data[x] += uf.data[y]
		uf.data[y] = x
	}
	uf.n -= btoi(x != y)
	return x != y
}

func (uf *UnionFind) Same(x, y int) bool {
	return uf.Root(x) == uf.Root(y)
}

func (uf *UnionFind) Root(x int) int {
	if uf.data[x] < 0 {
		return x
	} else {
		uf.data[x] = uf.Root(uf.data[x])
		return uf.data[x]
	}
}

func (uf *UnionFind) Size(x int) int {
	return -uf.data[uf.Root(x)]
}

func (uf *UnionFind) Num() int {
	return uf.n
}

type SegmentTree struct {
	identity int64
	merge    func(int64, int64) int64
	n        int
	dat      []int64
}

func NewSegmentTree(f func(int64, int64) int64, id int64, v []int64) *SegmentTree {
	_n := len(v)
	n := 1
	for n < _n {
		n *= 2
	}
	dat := make([]int64, 2*n-1)
	for i := 0; i < _n; i++ {
		dat[n+i-1] = v[i]
	}
	for i := n - 2; i >= 0; i-- {
		dat[i] = f(dat[i*2+1], dat[i*2+2])
	}
	return &SegmentTree{identity: id, merge: f, n: n, dat: dat}
}

func (st *SegmentTree) SetVal(i int, x int64) {
	i += st.n - 1
	st.dat[i] = x
	for i > 0 {
		i = (i - 1) / 2
		st.dat[i] = st.merge(st.dat[i*2+1], st.dat[i*2+2])
	}
}

func (st *SegmentTree) Query(l, r int) int64 {
	left := st.identity
	right := st.identity
	l += st.n - 1
	r += st.n - 1
	for l < r {
		if l&1 == 0 {
			left = st.merge(left, st.dat[l])
		}
		if r&1 == 0 {
			right = st.merge(st.dat[r-1], right)
		}
		l = l / 2
		r = (r - 1) / 2
	}
	return st.merge(left, right)
}

type id3 struct {
	data []int64
	n    int
	p    int
}

func Newid3(n int) *id3 {
	data := make([]int64, n+1)
	p := 1
	for p < len(data) {
		p *= 2
	}
	return &id3{data, n, p}
}

func (bit *id3) Sum(k int) int64 {
	ret := int64(0)
	for k > 0 {
		ret += bit.data[k]
		k -= k & -k
	}
	return ret
}

func (bit *id3) Add(k int, x int64) {
	k++
	for k <= bit.n {
		bit.data[k] += x
		k += k & -k
	}
}

func (bit *id3) LowerBound(w int64) int {
	if w <= 0 {
		return -1
	}
	x := 0
	for k := bit.p / 2; k > 0; k /= 2 {
		if x+k <= bit.n && bit.data[x+k] < w {
			w -= bit.data[x+k]
			x += k
		}
	}
	return x
}

func divisor(n int64) []int64 {
	ret := make([]int64, 0)
	for i := int64(1); i*i <= n; i++ {
		if n%i == 0 {
			ret = append(ret, i)
			if i*i != n {
				ret = append(ret, n/i)
			}
		}
	}
	return ret
}

func id5(n int64) []Pair {
	ret := make([]Pair, 0)
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			ret = append(ret, Pair{i, 0})
			for n%i == 0 {
				n /= i
				ret[len(ret)-1].second++
			}
		}
	}
	if n != 1 {
		ret = append(ret, Pair{n, 1})
	}
	return ret
}

func modPow(x, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

func modInv(x, mod int64) int64 {
	return modPow(x, mod-2, mod)
}

type Combination struct {
	fact     []int64
	factInv  []int64
	mod      int64
}

func NewCombination(n, mod int64) *Combination {
	fact := make([]int64, n+1)
	fact[0] = 1
	for i := int64(1); i <= n; i++ {
		fact[i] = fact[i-1] * i % mod
	}
	factInv := make([]int64, n+1)
	factInv[n] = modInv(fact[n], mod)
	for i := n - 1; i >= 0; i-- {
		factInv[i] = factInv[i+1] * (i + 1) % mod
	}
	return &Combination{fact, factInv, mod}
}

func (c *Combination) nCr(n, r int64) int64 {
	if n < r {
		return 0
	}
	if n < c.mod {
		return ((c.fact[n] * c.factInv[r] % c.mod) * c.factInv[n-r]) % c.mod
	}
	ret := int64(1)
	for n > 0 || r > 0 {
		_n := n % c.mod
		_r := r % c.mod
		n /= c.mod
		r /= c.mod
		ret = ret * c.nCr(_n, _r) % c.mod
	}
	return ret
}

func (c *Combination) nPr(n, r int64) int64 {
	return (c.fact[n] * c.factInv[n-r]) % c.mod
}

func (c *Combination) nHr(n, r int64) int64 {
	return c.nCr(r+n-1, r)
}

func popcount(x int64) int64 {
	x = (x & 0x5555555555555555) + (x >> 1 & 0x5555555555555555)
	x = (x & 0x3333333333333333) + (x >> 2 & 0x3333333333333333)
	x = (x & 0x0F0F0F0F0F0F0F0F) + (x >> 4 & 0x0F0F0F0F0F0F0F0F)
	x = (x & 0x00FF00FF00FF00FF) + (x >> 8 & 0x00FF00FF00FF00FF)
	x = (x & 0x0000FFFF0000FFFF) + (x >> 16 & 0x0000FFFF0000FFFF)
	x = (x & 0x00000000FFFFFFFF) + (x >> 32 & 0x00000000FFFFFFFF)
	return x
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func chmin(a *int64, b int64) bool {
	if *a > b {
		*a = b
		return true
	}
	return false
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

func main() {
	var m int64
	fmt.Scan(&m)
	var h1, a1, x1, y1 int64
	fmt.Scan(&h1, &a1, &x1, &y1)
	t := []int64{h1}
	used := make([]bool, m)
	used[h1] = true
	for {
		tmp := (t[len(t)-1]*x1 + y1) % m
		t = append(t, tmp)
		if used[tmp] {
			break
		}
		used[tmp] = true
	}
	used = make([]bool, m)
	var h2, a2, x2, y2 int64
	fmt.Scan(&h2, &a2, &x2, &y2)
	used[h2] = true
	s := []int64{h2}
	for {
		tmp := (s[len(s)-1]*x2 + y2) % m
		s = append(s, tmp)
		if used[tmp] {
			break
		}
		used[tmp] = true
	}

	l1, l2 := -1, -1
	mn1, mn2 := INF, INF
	now := 0
	for {
		if t[len(t)-1] == t[now] {
			l1 = len(t) - now - 1
		}
		if t[now] == a1 {
			mn1 = int64(now)
			break
		}
		now++
		if now == len(t) {
			break
		}
	}
	now = 0
	for {
		if s[len(s)-1] == s[now] {
			l2 = len(s) - now - 1
		}
		if s[now] == a2 {
			mn2 = int64(now)
			break
		}
		now++
		if now == len(s) {
			break
		}
	}

	calc := func() int64 {
		if mn1 != INF && mn2 != INF {
			if mn1 == mn2 {
				return mn1
			}
			if mn1 > mn2 && l2 == -1 {
				return -1
			}
			if mn1 < mn2 && l1 == -1 {
				return -1
			}
			if l1 == -1 {
				if (mn1-mn2)%l2 == 0 {
					return mn1
				} else {
					return -1
				}
			}
			if l2 == -1 {
				if (mn2-mn1)%l1 == 0 {
					return mn2
				} else {
					return -1
				}
			}
			if l1 == l2 {
				if abs(mn1-mn2)%l1 == 0 {
					return max(mn1, mn2)
				} else {
					return -1
				}
			}
			if mn2 > mn1 && (mn2-mn1)%l1 == 0 {
				return mn2
			}
			if mn1 > mn2 && (mn1-mn2)%l2 == 0 {
				return mn1
			}
			if abs(mn2-mn1)%abs(gcd(l1, l2)) != 0 {
				return -1
			}
			x, y := 0, 0
			g := id1(l1, l2, &x, &y)
			x *= int((mn2 - mn1) / int64(g))
			y *= int((mn2 - mn1) / int64(g))
			mn := INF
			for x*l1+mn1 < max(mn1, mn2) {
				x += l2 / int(g)
			}
			mn = int(x*l1 + mn1)
			for {
				x -= l2 / int(g)
				if x*l1+mn1 >= max(mn1, mn2) {
					chmin(&mn, x*l1+mn1)
				} else {
					break
				}
			}
			return int64(mn)
		} else {
			return -1
		}
	}

	fmt.Println(calc())
}
