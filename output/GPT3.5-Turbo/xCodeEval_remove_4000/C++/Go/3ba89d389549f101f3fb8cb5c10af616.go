package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type Edge struct {
	to   int
	cap  int
	rev  int
}

type Graph [][]Edge

func addEdge(G *Graph, from, to, cap int, revFlag bool, revCap int) {
	G[from] = append(G[from], Edge{to, cap, len(G[to])})
	if revFlag {
		G[to] = append(G[to], Edge{from, revCap, len(G[from]) - 1})
	}
}

func id1(G *Graph, v, t, f int, used *[]bool) int {
	if v == t {
		return f
	}
	(*used)[v] = true
	for i := 0; i < len((*G)[v]); i++ {
		e := &(*G)[v][i]
		if !(*used)[e.to] && e.cap > 0 {
			d := id1(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				(*G)[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G *Graph, s, t int) int {
	flow := 0
	for {
		used := make([]bool, len(*G))
		f := id1(G, s, t, INF, &used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func id6(G *Graph, s int, d, negative *[]int) {
	n := len(*G)
	*d = make([]int, n)
	*negative = make([]int, n)
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	for i := 0; i < len(*negative); i++ {
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

func dijkstra(G *Graph, s int, d *[]int) {
	n := len(*G)
	*d = make([]int, n)
	for i := 0; i < len(*d); i++ {
		(*d)[i] = INF
	}
	(*d)[s] = 0
	q := make([]int, 0)
	q = append(q, s)
	for len(q) > 0 {
		a := q[0]
		q = q[1:]
		if (*d)[a] < (*d)[a] {
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

func id9(G *Graph, d *[][]int) {
	n := len(*G)
	*d = make([][]int, n)
	for i := 0; i < len(*d); i++ {
		(*d)[i] = make([]int, n)
		for j := 0; j < len((*d)[i]); j++ {
			(*d)[i][j] = INF
		}
	}
	for i := 0; i < len(*G); i++ {
		for j := 0; j < len((*G)[i]); j++ {
			(*d)[i][(*G)[i][j].to] = (*G)[i][j].cap
		}
	}
	for i := 0; i < len(*G); i++ {
		for j := 0; j < len(*G); j++ {
			for k := 0; k < len(*G); k++ {
				if (*d)[j][k] > (*d)[j][i]+(*d)[i][k] {
					(*d)[j][k] = (*d)[j][i] + (*d)[i][k]
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
		for range es {
			in[es.to]++
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

type lca struct {
	n      int
	log2_n int
	parent [][]int
	depth  []int
}

func newLCA(g *Graph, root int) *lca {
	n := len(*g)
	log2_n := 0
	for 1<<uint(log2_n) < n {
		log2_n++
	}
	parent := make([][]int, log2_n)
	for i := 0; i < log2_n; i++ {
		parent[i] = make([]int, n)
		for j := 0; j < n; j++ {
			parent[i][j] = -1
		}
	}
	depth := make([]int, n)
	l := lca{n, log2_n, parent, depth}
	l.dfs(g, root, -1, 0)
	for k := 0; k+1 < log2_n; k++ {
		for v := 0; v < len(*g); v++ {
			if l.parent[k][v] < 0 {
				l.parent[k+1][v] = -1
			} else {
				l.parent[k+1][v] = l.parent[k][l.parent[k][v]]
			}
		}
	}
	return &l
}

func (l *lca) dfs(g *Graph, v, p, d int) {
	l.parent[0][v] = p
	l.depth[v] = d
	for _, e := range (*g)[v] {
		if e.to != p {
			l.dfs(g, e.to, v, d+1)
		}
	}
}

func (l *lca) get(u, v int) int {
	if l.depth[u] > l.depth[v] {
		u, v = v, u
	}
	for k := 0; k < l.log2_n; k++ {
		if (l.depth[v]-l.depth[u])>>uint(k)&1 == 1 {
			v = l.parent[k][v]
		}
	}
	if u == v {
		return u
	}
	for k := l.log2_n - 1; k >= 0; k-- {
		if l.parent[k][u] != l.parent[k][v] {
			u = l.parent[k][u]
			v = l.parent[k][v]
		}
	}
	return l.parent[0][u]
}

func visit(g *Graph, v int, scc *[][]int, S *[]int, inS, low, num *[]int, time *int) {
	(*low)[v] = (*num)[v]
	(*num)[v] = *time
	*time++
	*S = append(*S, v)
	(*inS)[v] = 1
	for _, e := range (*g)[v] {
		w := e.to
		if (*num)[w] == 0 {
			visit(g, w, scc, S, inS, low, num, time)
			(*low)[v] = min((*low)[v], (*low)[w])
		} else if (*inS)[w] == 1 {
			(*low)[v] = min((*low)[v], (*num)[w])
		}
	}
	if (*low)[v] == (*num)[v] {
		(*scc) = append(*scc, []int{})
		for {
			w := (*S)[len(*S)-1]
			*S = (*S)[:len(*S)-1]
			(*inS)[w] = 0
			(*scc)[len(*scc)-1] = append((*scc)[len(*scc)-1], w)
			if v == w {
				break
			}
		}
	}
}

func id7(g *Graph, scc *[][]int) {
	n := len(*g)
	num := make([]int, n)
	low := make([]int, n)
	inS := make([]int, n)
	S := make([]int, 0)
	time := 0
	for u := 0; u < n; u++ {
		if num[u] == 0 {
			visit(g, u, scc, &S, &inS, &low, &num, &time)
		}
	}
}

type UnionFind struct {
	data []int
	num  int
}

func newUnionFind(size int) *UnionFind {
	data := make([]int, size)
	for i := 0; i < size; i++ {
		data[i] = -1
	}
	return &UnionFind{data, size}
}

func (uf *UnionFind) unite(x, y int) bool {
	x = uf.root(x)
	y = uf.root(y)
	if x != y {
		if uf.data[y] < uf.data[x] {
			x, y = y, x
		}
		uf.data[x] += uf.data[y]
		uf.data[y] = x
	}
	uf.num -= bool(x != y)
	return x != y
}

func (uf *UnionFind) findSet(x, y int) bool {
	return uf.root(x) == uf.root(y)
}

func (uf *UnionFind) root(x int) int {
	if uf.data[x] < 0 {
		return x
	}
	uf.data[x] = uf.root(uf.data[x])
	return uf.data[x]
}

func (uf *UnionFind) size(x int) int {
	return -uf.data[uf.root(x)]
}

func (uf *UnionFind) numSet() int {
	return uf.num
}

type id8 struct {
	n      int
	height int
	dat    []int
}

func newid8(n int) *id8 {
	obj := id8{n: 1, height: 1}
	for obj.n < n {
		obj.n <<= 1
		obj.height++
	}
	obj.dat = make([]int, 2*obj.n-1)
	return &obj
}

func (seg *id8) add(i, x int) {
	i += seg.n - 1
	seg.dat[i] += x
	for i > 0 {
		i = (i - 1) / 2
		seg.dat[i] += x
	}
}

func (seg *id8) sum(a, b int) int {
	return seg._sum(a, b, 0, 0, seg.n)
}

func (seg *id8) _sum(a, b, k, l, r int) int {
	if r <= a || b <= l {
		return 0
	}
	if a <= l && r <= b {
		return seg.dat[k]
	}
	s1 := seg._sum(a, b, 2*k+1, l, (l+r)/2)
	s2 := seg._sum(a, b, 2*k+2, (l+r)/2, r)
	return s1 + s2
}

type id10 struct {
	n      int
	height int
	dat    []int
}

func newid10(n int) *id10 {
	obj := id10{n: 1, height: 1}
	for obj.n < n {
		obj.n <<= 1
		obj.height++
	}
	obj.dat = make([]int, 2*obj.n-1)
	for i := 0; i < len(obj.dat); i++ {
		obj.dat[i] = INF
	}
	return &obj
}

func (seg *id10) update(i, x int) {
	i += seg.n - 1
	seg.dat[i] = x
	for i > 0 {
		i = (i - 1) / 2
		seg.dat[i] = min(seg.dat[i*2+1], seg.dat[i*2+2])
	}
}

func (seg *id10) find(a, b int) int {
	return seg._find(a, b, 0, 0, seg.n)
}

func (seg *id10) _find(a, b, k, l, r int) int {
	if r <= a || b <= l {
		return INF
	}
	if a <= l && r <= b {
		return seg.dat[k]
	}
	s1 := seg._find(a, b, 2*k+1, l, (l+r)/2)
	s2 := seg._find(a, b, 2*k+2, (l+r)/2, r)
	return min(s1, s2)
}

func divisor(n int) []int {
	ret := make([]int, 0)
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			ret = append(ret, i)
			if i*i != n {
				ret = append(ret, n/i)
			}
		}
	}
	sort.Ints(ret)
	return ret
}

func lis_fast(a []int) []int {
	n := len(a)
	A := make([]int, n)
	id := make([]int, n)
	for i := 0; i < n; i++ {
		id[i] = i
		A[i] = INF
	}
	for i := 0; i < n; i++ {
		j := sort.Search(n, func(j int) bool { return A[j] >= a[i] })
		id[i] = j
		A[j] = a[i]
	}
	m := max(id...) + 1
	b := make([]int, m)
	for i := n - 1; i >= 0; i-- {
		if id[i] == m-1 {
			b[m-1] = a[i]
			m--
		}
	}
	return b
}

func z_algorithm(str string, z *[]int) bool {
	L := len(str)
	*z = make([]int, L)
	for i, left, right := 1, 0, 0; i < L; i++ {
		if i <= right {
			(*z)[i] = min(right-i+1, (*z)[i-left])
		}
		for i+(*z)[i] < L && str[(*z)[i]] == str[i+(*z)[i]] {
			(*z)[i]++
		}
		if (*z)[i] == L {
			return true
		}
		if i+(*z)[i]-1 > right {
			left = i
			right = i + (*z)[i] - 1
		}
	}
	return false
}

type RollingHash struct {
	base1, base2, mod1, mod2 int64
	hash1, hash2, power1, power2 []int64
}

func newRollingHash(S string) *RollingHash {
	n := len(S)
	hash1 := make([]int64, n+1)
	hash2 := make([]int64, n+1)
	power1 := make([]int64, n+1)
	power2 := make([]int64, n+1)
	hash1[0], hash2[0], power1[0], power2[0] = 0, 0, 1, 1
	for i := 0; i < n; i++ {
		hash1[i+1] = (hash1[i]*base1 + int64(S[i])) % mod1
		hash2[i+1] = (hash2[i]*base2 + int64(S[i])) % mod2
		power1[i+1] = power1[i] * base1 % mod1
		power2[i+1] = power2[i] * base2 % mod2
	}
	return &RollingHash{base1, base2, mod1, mod2, hash1, hash2, power1, power2}
}

func (rh *RollingHash) get(l, r int) (int64, int64) {
	res1 := (rh.hash1[r] - rh.hash1[l]*rh.power1[r-l]%rh.mod1 + rh.mod1) % rh.mod1
	res2 := (rh.hash2[r] - rh.hash2[l]*rh.power2[r-l]%rh.mod2 + rh.mod2) % rh.mod2
	return res1, res2
}

func (rh *RollingHash) getLCP(a, b int) int {
	len := min(len(rh.hash1)-a, len(rh.hash1)-b)
	low, high := 0, len
	for high-low > 1 {
		mid := (low + high) >> 1
		if rh.get(a, a+mid) != rh.get(b, b+mid) {
			high = mid
		} else {
			low = mid
		}
	}
	return low
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
	fact, inv []int64
	mod       int64
}

func newCombination(n int, mod int64) *Combination {
	fact := make([]int64, n+1)
	fact[0] = 1
	for i := 0; i < n; i++ {
		fact[i+1] = fact[i] * int64(i+1) % mod
	}
	inv := make([]int64, n+1)
	inv[n] = modInv(fact[n], mod)
	for i := n; i > 0; i-- {
		inv[i-1] = inv[i] * int64(i) % mod
	}
	return &Combination{fact, inv, mod}
}

func (c *Combination) nCr(n, r int) int64 {
	return c.fact[n] * c.inv[r] % c.mod * c.inv[n-r] % c.mod
}

func (c *Combination) nPr(n, r int) int64 {
	return c.fact[n] * c.inv[n-r] % c.mod
}

func (c *Combination) nHr(n, r int) int64 {
	return c.nCr(r+n-1, r)
}

func gcd(m, n int64) int64 {
	if n == 0 {
		return m
	}
	return gcd(n, m%n)
}

func lcm(m, n int64) int64 {
	return m / gcd(m, n) * n
}

type RectangleSum struct {
	sum [][]int
}

func newRectangleSum(s [][]int, h, w int) *RectangleSum {
	sum := make([][]int, h)
	for i := 0; i < h; i++ {
		sum[i] = make([]int, w)
	}
	for y := 0; y < h; y++ {
		for x := 0; x < w; x++ {
			sum[y][x] = s[y][x]
			if y > 0 {
				sum[y][x] += sum[y-1][x]
			}
			if x > 0 {
				sum[y][x] += sum[y][x-1]
			}
			if y > 0 && x > 0 {
				sum[y][x] -= sum[y-1][x-1]
			}
		}
	}
	return &RectangleSum{sum}
}

func (rs *RectangleSum) GetSum(left, right, top, bottom int) int {
	res := rs.sum[bottom][right]
	if left > 0 {
		res -= rs.sum[bottom][left-1]
	}
	if top > 0 {
		res -= rs.sum[top-1][right]
	}
	if left > 0 && top > 0 {
		res += rs.sum[top-1][left-1]
	}
	return res
}

func min(a ...int) int {
	res := a[0]
	for _, x := range a[1:] {
		if x < res {
			res = x
		}
	}
	return res
}

func max(a ...int) int {
	res := a[0]
	for _, x := range a[1:] {
		if x > res {
			res = x
		}
	}
	return res
}

func solve() {
	var n, m, a, b int
	fmt.Scan(&n, &m, &a, &b)
	a--
	b--
	g := make(Graph, n)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Scan(&u, &v)
		u--
		v--
		addEdge(&g, u, v, 1, true, 1)
	}
	used := make([]int, n)
	st := make(map[int]bool)
	dfs(&g, a, b, &st, &used, a)
	s, t := 0, 0
	for i := 0; i < n; i++ {
		if used[i] == 1 {
			s++
		} else if used[i] == 0 {
			t++
		}
	}
	s--
	fmt.Println(s * t)
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)
	t := nextInt(scanner)
	for i := 0; i < t; i++ {
		solve()
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	val, _ := strconv.Atoi(scanner.Text())
	return val
}
