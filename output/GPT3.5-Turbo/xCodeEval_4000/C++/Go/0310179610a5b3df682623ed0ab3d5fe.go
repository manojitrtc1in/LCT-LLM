package main

import (
	"fmt"
)

const (
	INF  = 1 << 61
	MOD  = 1000000007
	EPS  = 1e-10
	m_pi = 3.1415926535897932
)

type Edge struct {
	to   int
	rev  int
	cap  int64
}

type Graph [][]Edge

func addEdge(G *Graph, from, to int, cap int64, revFlag bool, revCap int64) {
	G[from] = append(G[from], Edge{to, len(G[to]) + btoi(from == to), cap})
	if revFlag {
		G[to] = append(G[to], Edge{from, len(G[from]) - 1, revCap})
	}
}

func maxFlowDFS(G *Graph, v, t int, f int64, used *[]bool) int64 {
	if v == t {
		return f
	}
	(*used)[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := &(*G)[v][i]
		if !(*used)[e.to] && e.cap > 0 {
			d := maxFlowDFS(G, e.to, t, min(f, e.cap), used)
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
		for i := 0; i < len(used); i++ {
			used[i] = false
		}
		f := maxFlowDFS(G, s, t, INF, &used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func BellmanFord(G *Graph, s int, d, negative *[]int64) {
	*d = make([]int64, len(*G))
	*negative = make([]int64, len(*G))
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	for i := 0; i < len(*d); i++ {
		(*negative)[i] = false
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
					(*negative)[(*G)[i][j].to] = true
				}
				if (*negative)[i] == true {
					(*negative)[(*G)[i][j].to] = true
				}
			}
		}
	}
}

func Dijkstra(G *Graph, s int, d *[]int64) {
	*d = make([]int64, len(*G))
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	(*d)[s] = 0
	q := make([]int, 0)
	q = append(q, s)
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		if (*d)[a] < int64(a) {
			continue
		}
		for i := 0; i < len((*G)[a]); i++ {
			e := (*G)[a][i]
			if (*d)[e.to] > (*d)[a]+e.cap {
				(*d)[e.to] = (*d)[a] + e.cap
				q = append(q, e.to)
			}
		}
	}
}

func WarshallFloyd(G *Graph, d *[][]int64) {
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
	n      int
	log2_n int
	parent [][]int
	depth  []int
}

func NewLca(g *Graph, root int) *Lca {
	lca := new(Lca)
	lca.n = len(*g)
	lca.log2_n = log2(lca.n) + 1
	lca.parent = make([][]int, lca.log2_n)
	for i := 0; i < lca.log2_n; i++ {
		lca.parent[i] = make([]int, lca.n)
	}
	lca.depth = make([]int, lca.n)
	lca.dfs(g, root, -1, 0)
	for k := 0; k+1 < lca.log2_n; k++ {
		for v := 0; v < len(*g); v++ {
			if lca.parent[k][v] < 0 {
				lca.parent[k+1][v] = -1
			} else {
				lca.parent[k+1][v] = lca.parent[k][lca.parent[k][v]]
			}
		}
	}
	return lca
}

func (lca *Lca) dfs(g *Graph, v, p, d int) {
	lca.parent[0][v] = p
	lca.depth[v] = d
	for _, e := range (*g)[v] {
		if e.to != p {
			lca.dfs(g, e.to, v, d+1)
		}
	}
}

func (lca *Lca) get(u, v int) int {
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
	uf := new(UnionFind)
	uf.data = make([]int, size)
	uf.n = size
	for i := 0; i < size; i++ {
		uf.data[i] = -1
	}
	return uf
}

func (uf *UnionFind) merge(x, y int) bool {
	x = uf.root(x)
	y = uf.root(y)
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

func (uf *UnionFind) same(x, y int) bool {
	return uf.root(x) == uf.root(y)
}

func (uf *UnionFind) root(x int) int {
	if uf.data[x] < 0 {
		return x
	} else {
		uf.data[x] = uf.root(uf.data[x])
		return uf.data[x]
	}
}

func (uf *UnionFind) size(x int) int {
	return -uf.data[uf.root(x)]
}

func (uf *UnionFind) num() int {
	return uf.n
}

type SegmentTree struct {
	identity int
	merge    func(int, int) int
	n        int
	dat      []int
}

func NewSegmentTree(f func(int, int) int, id int, v []int) *SegmentTree {
	st := new(SegmentTree)
	st.merge = f
	st.identity = id
	st.n = 1
	for st.n < len(v) {
		st.n *= 2
	}
	st.dat = make([]int, 2*st.n-1)
	for i := 0; i < len(v); i++ {
		st.dat[st.n+i-1] = v[i]
	}
	for i := st.n - 2; i >= 0; i-- {
		st.dat[i] = st.merge(st.dat[i*2+1], st.dat[i*2+2])
	}
	return st
}

func (st *SegmentTree) setVal(i, x int) {
	i += st.n - 1
	st.dat[i] = x
	for i > 0 {
		i = (i - 1) / 2
		st.dat[i] = st.merge(st.dat[i*2+1], st.dat[i*2+2])
	}
}

func (st *SegmentTree) query(l, r int) int {
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
		l = l/2 + 1
		r = (r - 1) / 2
	}
	return st.merge(left, right)
}

type FenwickTree struct {
	data []int
	n    int
	p    int
}

func NewFenwickTree(n int) *FenwickTree {
	ft := new(FenwickTree)
	ft.n = n
	ft.data = make([]int, n+1)
	ft.p = 1
	for ft.p < len(ft.data) {
		ft.p *= 2
	}
	return ft
}

func (ft *FenwickTree) sum(k int) int {
	ret := 0
	for k > 0 {
		ret += ft.data[k]
		k -= k & -k
	}
	return ret
}

func (ft *FenwickTree) add(k, x int) {
	for k <= ft.n {
		ft.data[k] += x
		k += k & -k
	}
}

func (ft *FenwickTree) lowerBound(w int64) int {
	if w <= 0 {
		return -1
	}
	x := 0
	for k := ft.p / 2; k > 0; k /= 2 {
		if x+k <= ft.n && int64(ft.data[x+k]) < w {
			w -= int64(ft.data[x+k])
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
	sort.Slice(ret, func(i, j int) bool {
		return ret[i] < ret[j]
	})
	return ret
}

func primeFactorization(n int64) []Pair {
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

func NewCombination(n int64, mod int64) *Combination {
	c := new(Combination)
	c.mod = mod
	c.fact = make([]int64, n+1)
	c.fact[0] = 1
	for i := int64(1); i <= n; i++ {
		c.fact[i] = c.fact[i-1] * i % mod
	}
	c.factInv = make([]int64, n+1)
	c.factInv[n] = modInv(c.fact[n], mod)
	for i := n - 1; i >= 0; i-- {
		c.factInv[i] = c.factInv[i+1] * (i + 1) % mod
	}
	return c
}

func (c *Combination) nCr(n, r int64) int64 {
	if n < r {
		return 0
	}
	if n < c.mod {
		return c.fact[n] * c.factInv[r] % c.mod * c.factInv[n-r] % c.mod
	}
	ret := int64(1)
	for n > 0 || r > 0 {
		_n := n % c.mod
		_r := r % c.mod
		n /= c.mod
		r /= c.mod
		ret *= c.nCr(_n, _r)
		ret %= c.mod
	}
	return ret
}

func (c *Combination) nPr(n, r int64) int64 {
	return c.fact[n] * c.factInv[n-r] % c.mod
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
			mn1 = now
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
			mn2 = now
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
			x, y := extgcd(l1, l2)
			x *= (mn2 - mn1) / gcd(l1, l2)
			y *= (mn2 - mn1) / gcd(l1, l2)
			if x*l1+mn1 < max(mn1, mn2) {
				x += ((max(mn1, mn2)-x*l1+mn1+l1-1)/l1 + l2/gcd(l1, l2) - 1) / (l2 / gcd(l1, l2)) * (l2 / gcd(l1, l2))
			}
			if x*l1+mn1 >= max(mn1, mn2) {
				x -= (x*l1 + mn1 - max(mn1, mn2)) / l1 / (l2 / gcd(l1, l2)) * (l2 / gcd(l1, l2))
			}
			return x*l1 + mn1
		} else {
			return -1
		}
	}

	fmt.Println(calc())
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

func chmax(a *int64, b int64) bool {
	if *a < b {
		*a = b
		return true
	}
	return false
}

func btoi(b bool) int {
	if b {
		return 1
	}
	return 0
}

func log2(x int) int {
	ret := 0
	for (1 << uint(ret)) < x {
		ret++
	}
	return ret
}

func extgcd(a, b int) (int, int, int) {
	if a < b {
		return extgcd(b, a)
	}
	if b > 0 {
		g, x, y := extgcd(b, a%b)
		y -= (a / b) * x
		return g, y, x
	} else {
		return a, 1, 0
	}
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

type Pair struct {
	first  int64
	second int64
}

func main() {
	// Your code here
}
