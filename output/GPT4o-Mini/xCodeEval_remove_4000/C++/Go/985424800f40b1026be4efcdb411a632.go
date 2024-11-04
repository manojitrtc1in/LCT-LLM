package main

import (
	"fmt"
	"math"
	"sort"
)

const MOD = 1000000007
const INF = 1 << 60

type Pair struct {
	first, second int64
}

func gcd(a, b int64) int64 {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

func lcm(a, b int64) int64 {
	return a / gcd(a, b) * b
}

func isPrime(x int64) bool {
	if x == 1 {
		return false
	}
	for i := int64(2); i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func divisor(n int64) []int64 {
	var ret []int64
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

func modpow(a, n, mod int64) int64 {
	res := int64(1)
	for n > 0 {
		if n&1 == 1 {
			res = res * a % mod
		}
		a = a * a % mod
		n >>= 1
	}
	return res
}

func modinv(a, mod int64) int64 {
	return modpow(a, mod-2, mod)
}

const MAX = 510000

var fac, finv, inv [MAX]int64

func COMinit() {
	fac[0], fac[1] = 1, 1
	finv[0], finv[1] = 1, 1
	inv[1] = 1
	for i := int64(2); i < MAX; i++ {
		fac[i] = fac[i-1] * i % MOD
		inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD
		finv[i] = finv[i-1] * inv[i] % MOD
	}
}

func COM(n, k int64) int64 {
	if n < k || n < 0 || k < 0 {
		return 0
	}
	return fac[n] * (finv[k] * finv[n-k % MOD]) % MOD
}

type UnionFind struct {
	par []int
}

func NewUnionFind(n int) *UnionFind {
	par := make([]int, n)
	for i := range par {
		par[i] = -1
	}
	return &UnionFind{par: par}
}

func (uf *UnionFind) root(x int) int {
	if uf.par[x] < 0 {
		return x
	}
	uf.par[x] = uf.root(uf.par[x])
	return uf.par[x]
}

func (uf *UnionFind) issame(x, y int) bool {
	return uf.root(x) == uf.root(y)
}

func (uf *UnionFind) merge(x, y int) bool {
	x = uf.root(x)
	y = uf.root(y)
	if x == y {
		return false
	}
	if uf.par[x] > uf.par[y] {
		x, y = y, x
	}
	uf.par[x] += uf.par[y]
	uf.par[y] = x
	return true
}

func (uf *UnionFind) size(x int) int {
	return -uf.par[uf.root(x)]
}

type BIT struct {
	n  int
	bit []int
}

func NewBIT(n int) *BIT {
	bit := make([]int, n+1)
	return &BIT{n: n, bit: bit}
}

func (bit *BIT) sum(i int) int {
	s := 0
	for i > 0 {
		s += bit.bit[i]
		i -= i & -i
	}
	return s
}

func (bit *BIT) add(i, x int) {
	for i <= bit.n {
		bit.bit[i] += x
		i += i & -i
	}
}

func (bit *BIT) lowerBound(w int) int {
	if w <= 0 {
		return 0
	}
	x, r := 0, 1
	for r < bit.n {
		r <<= 1
	}
	for k := r; k > 0; k >>= 1 {
		if x+k <= bit.n && bit.bit[x+k] < w {
			w -= bit.bit[x+k]
			x += k
		}
	}
	return x + 1
}

func digitSum(v int64) int64 {
	ret := int64(0)
	for v > 0 {
		ret += v % 10
		v /= 10
	}
	return ret
}

func LIS(a []int, n int) int {
	A := make([]int, n)
	for i := range A {
		A[i] = math.MaxInt32
	}
	for i := 0; i < n; i++ {
		*lowerBound(A, a[i]) = a[i]
	}
	return find(A, math.MaxInt32)
}

func lowerBound(arr []int, x int) *int {
	i := sort.Search(len(arr), func(i int) bool {
		return arr[i] >= x
	})
	if i < len(arr) {
		return &arr[i]
	}
	return nil
}

func find(arr []int, x int) int {
	for i, v := range arr {
		if v == x {
			return i
		}
	}
	return -1
}

var maze [100][100]int64

func id2(H, W, sx, sy, gx, gy int64) int64 {
	dx := []int64{1, 0, -1, 0}
	dy := []int64{0, 1, 0, -1}

	dist := make([][]int64, H)
	for i := range dist {
		dist[i] = make([]int64, W)
		for j := range dist[i] {
			dist[i][j] = -1
		}
	}
	dist[sy][sx] = 0

	q := []Pair{{sy, sx}}
	for len(q) > 0 {
		x, y := q[0].second, q[0].first
		q = q[1:]
		if y == gy && x == gx {
			break
		}
		for t := 0; t < 4; t++ {
			nx, ny := x+dx[t], y+dy[t]
			if nx < 0 || ny < 0 || nx >= W || ny >= H || dist[ny][nx] != -1 || maze[ny][nx] == 1 {
				continue
			}
			dist[ny][nx] = dist[y][x] + 1
			q = append(q, Pair{ny, nx})
		}
	}

	return dist[gy][gx]
}

func id3(n int64, g [][]int64, INF int64) [][]int64 {
	for k := int64(0); k < n; k++ {
		for i := int64(0); i < n; i++ {
			for j := int64(0); j < n; j++ {
				if g[i][k] == INF || g[k][j] == INF {
					continue
				}
				g[i][j] = min(g[i][j], g[i][k]+g[k][j])
			}
		}
	}
	return g
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

type Dijkstra struct {
	n      int64
	Edges  [][]Pair
	Dist   []int64
	Prev   []int64
	PathNum []int64
}

func NewDijkstra(n int64) *Dijkstra {
	Edges := make([][]Pair, n)
	Dist := make([]int64, n)
	Prev := make([]int64, n)
	PathNum := make([]int64, n)
	return &Dijkstra{n: n, Edges: Edges, Dist: Dist, Prev: Prev, PathNum: PathNum}
}

func (d *Dijkstra) addEdge(a, b, c int64, directed bool) {
	if directed {
		d.Edges[a] = append(d.Edges[a], Pair{b, c})
	} else {
		d.Edges[a] = append(d.Edges[a], Pair{b, c})
		d.Edges[b] = append(d.Edges[b], Pair{a, c})
	}
}

func (d *Dijkstra) build(start int64) {
	queue := make([]Pair, 0)
	for i := range d.Dist {
		d.Dist[i] = 1e+18
		d.Prev[i] = -1
	}
	d.Dist[start] = 0
	d.PathNum[start] = 1
	queue = append(queue, Pair{0, start})

	for len(queue) > 0 {
		p := queue[0]
		queue = queue[1:]
		v := p.second
		if d.Dist[v] < p.first {
			continue
		}

		for _, e := range d.Edges[v] {
			if d.Dist[e.first] > d.Dist[v]+e.second {
				d.Dist[e.first] = d.Dist[v] + e.second
				queue = append(queue, Pair{d.Dist[e.first], e.first})
				d.Prev[e.first] = v
				d.PathNum[e.first] = d.PathNum[v]
			} else if d.Dist[e.first] == d.Dist[v]+e.second {
				d.PathNum[e.first] += d.PathNum[v]
				d.PathNum[e.first] %= MOD
			}
		}
	}
}

func (d *Dijkstra) dist(t int64) int64 {
	return d.Dist[t]
}

func (d *Dijkstra) getPath(t int64) []int64 {
	var path []int64
	for t != -1 {
		path = append(path, t)
		t = d.Prev[t]
	}
	reverse(path)
	return path
}

func reverse(arr []int64) {
	for i, j := 0, len(arr)-1; i < j; i, j = i+1, j-1 {
		arr[i], arr[j] = arr[j], arr[i]
	}
}

func (d *Dijkstra) getPathNum(t int64) int64 {
	return d.PathNum[t]
}

type id1 struct {
	H, W int
	data [][]int64
}

func NewId1(H, W int) *id1 {
	data := make([][]int64, H+1)
	for i := range data {
		data[i] = make([]int64, W+1)
	}
	return &id1{H: H, W: W, data: data}
}

func (id *id1) add(x, y int, z int64) {
	id.data[x+1][y+1] += z
}

func (id *id1) build() {
	for i := 1; i < len(id.data); i++ {
		for j := 1; j < len(id.data[i]); j++ {
			id.data[i][j] += id.data[i][j-1] + id.data[i-1][j] - id.data[i-1][j-1]
		}
	}
}

func (id *id1) query(sx, sy, gx, gy int) int64 {
	return id.data[gy][gx] - id.data[sy-1][gx] - id.data[gy][sx-1] + id.data[sy-1][sx-1]
}

type LCA struct {
	n, h   int
	par    [][]int
	v      [][]Pair
	depth  []int64
	dis    []int64
}

func NewLCA(sz int) *LCA {
	h := 1
	for (1 << h) < sz {
		h++
	}
	par := make([][]int, h)
	for i := range par {
		par[i] = make([]int, sz)
	}
	v := make([][]Pair, sz)
	depth := make([]int64, sz)
	dis := make([]int64, sz)
	return &LCA{n: sz, h: h, par: par, v: v, depth: depth, dis: dis}
}

func (l *LCA) addEdge(x, y int, z int64) {
	l.v[x] = append(l.v[x], Pair{y, z})
	l.v[y] = append(l.v[y], Pair{x, z})
}

func (l *LCA) dfs(x, p int, d int64, di int64) {
	l.par[0][x] = p
	l.depth[x] = d
	l.dis[x] = di
	for _, to := range l.v[x] {
		if to.first != p {
			l.dfs(to.first, x, d+1, di+to.second)
		}
	}
}

func (l *LCA) build() {
	l.dfs(0, -1, 0, 0)
	for i := 0; i < l.h-1; i++ {
		for j := 0; j < l.n; j++ {
			if l.par[i][j] < 0 {
				l.par[i+1][j] = -1
			} else {
				l.par[i+1][j] = l.par[i][l.par[i][j]]
			}
		}
	}
}

func (l *LCA) lca(u, v int) int {
	if l.depth[u] > l.depth[v] {
		u, v = v, u
	}
	for i := 0; i < l.h; i++ {
		if (l.depth[v]-l.depth[u])>>i&1 == 1 {
			v = l.par[i][v]
		}
	}
	if u == v {
		return u
	}
	for i := l.h - 1; i >= 0; i-- {
		if l.par[i][u] != l.par[i][v] {
			u = l.par[i][u]
			v = l.par[i][v]
		}
	}
	return l.par[0][u]
}

func (l *LCA) dist(u, v int) int64 {
	return l.dis[u] + l.dis[v] - 2*l.dis[l.lca(u, v)]
}

var a [101010]int64

func cnk(n, k int64) int64 {
	ret := int64(1)
	for i := n - k + 1; i <= n; i++ {
		ret *= i
	}
	for i := int64(1); i <= k; i++ {
		ret /= i
	}
	return ret
}

func solve() {
	var n, k int64
	fmt.Scan(&n, &k)
	if k == 1 {
		fmt.Println(1)
		return
	}
	a[2] = 1
	for i := int64(3); i <= 10; i++ {
		a[i] = (i - 1) * (a[i-1] + a[i-2])
	}

	ans := int64(1)
	for i := int64(0); i < k; i++ {
		ans += cnk(n, k-i) * a[k-i]
	}

	fmt.Println(ans)
}

func main() {
	fmt.Printf("%.10f\n", 0.0)
	solve()
}
