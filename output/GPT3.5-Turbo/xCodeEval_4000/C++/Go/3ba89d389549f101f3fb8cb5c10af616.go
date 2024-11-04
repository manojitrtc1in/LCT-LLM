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

func addEdge(G Graph, from, to, cap int, revFlag bool, revCap int) {
	G[from] = append(G[from], Edge{to, cap, len(G[to])})
	if revFlag {
		G[to] = append(G[to], Edge{from, revCap, len(G[from]) - 1})
	}
}

func maxFlow_dfs(G Graph, v, t, f int, used []bool) int {
	if v == t {
		return f
	}
	used[v] = true
	for i := 0; i < len(G[v]); i++ {
		e := &G[v][i]
		if !used[e.to] && e.cap > 0 {
			d := maxFlow_dfs(G, e.to, t, min(f, e.cap), used)
			if d > 0 {
				e.cap -= d
				G[e.to][e.rev].cap += d
				return d
			}
		}
	}
	return 0
}

func maxFlow(G Graph, s, t int) int {
	flow := 0
	for {
		used := make([]bool, len(G))
		f := maxFlow_dfs(G, s, t, INF, used)
		if f == 0 {
			return flow
		}
		flow += f
	}
}

func BellmanFord(G Graph, s int, d, negative []int) {
	n := len(G)
	d = make([]int, n)
	negative = make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = INF
	}
	for i := 0; i < n; i++ {
		negative[i] = false
	}
	d[s] = 0
	for k := 0; k < n-1; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < len(G[i]); j++ {
				if d[i] != INF && d[G[i][j].to] > d[i]+G[i][j].cap {
					d[G[i][j].to] = d[i] + G[i][j].cap
				}
			}
		}
	}
	for k := 0; k < n-1; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < len(G[i]); j++ {
				if d[i] != INF && d[G[i][j].to] > d[i]+G[i][j].cap {
					d[G[i][j].to] = d[i] + G[i][j].cap
					negative[G[i][j].to] = true
				}
				if negative[i] == true {
					negative[G[i][j].to] = true
				}
			}
		}
	}
}

func Dijkstra(G Graph, s int, d []int) {
	n := len(G)
	d = make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = INF
	}
	d[s] = 0
	q := make(PriorityQueue, 0)
	heap.Push(&q, &Item{0, s})
	for q.Len() > 0 {
		item := heap.Pop(&q).(*Item)
		a := item.value
		if d[a] < item.priority {
			continue
		}
		for i := 0; i < len(G[a]); i++ {
			e := G[a][i]
			if d[e.to] > d[a]+e.cap {
				d[e.to] = d[a] + e.cap
				heap.Push(&q, &Item{d[e.to], e.to})
			}
		}
	}
}

func WarshallFloyd(G Graph, d [][]int) {
	n := len(G)
	d = make([][]int, n)
	for i := 0; i < n; i++ {
		d[i] = make([]int, n)
	}
	for i := 0; i < n; i++ {
		for j := 0; j < len(G[i]); j++ {
			d[i][G[i][j].to] = G[i][j].cap
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			for k := 0; k < n; k++ {
				if d[j][k] > d[j][i]+d[i][k] {
					d[j][k] = d[j][i] + d[i][k]
				}
			}
		}
	}
}

func tsort(graph Graph, order []int) bool {
	n := len(graph)
	k := 0
	in := make([]int, n)
	for _, es := range graph {
		for range es {
			in[e.to]++
		}
	}
	que := make(PriorityQueue, 0)
	for i := 0; i < n; i++ {
		if in[i] == 0 {
			heap.Push(&que, &Item{0, i})
		}
	}
	for que.Len() > 0 {
		v := heap.Pop(&que).(*Item).value
		order = append(order, v)
		for _, e := range graph[v] {
			in[e.to]--
			if in[e.to] == 0 {
				heap.Push(&que, &Item{0, e.to})
			}
		}
	}
	if len(order) != n {
		return false
	} else {
		return true
	}
}

type lca struct {
	n       int
	log2_n  int
	parent  [][]int
	depth   []int
}

func newLCA(g Graph, root int) *lca {
	n := len(g)
	log2_n := int(math.Log2(float64(n))) + 1
	parent := make([][]int, log2_n)
	for i := 0; i < log2_n; i++ {
		parent[i] = make([]int, n)
	}
	depth := make([]int, n)
	dfs(g, root, -1, 0, parent, depth)
	for k := 0; k+1 < log2_n; k++ {
		for v := 0; v < n; v++ {
			if parent[k][v] < 0 {
				parent[k+1][v] = -1
			} else {
				parent[k+1][v] = parent[k][parent[k][v]]
			}
		}
	}
	return &lca{n, log2_n, parent, depth}
}

func (l *lca) dfs(g Graph, v, p, d int, parent [][]int, depth []int) {
	parent[0][v] = p
	depth[v] = d
	for _, e := range g[v] {
		if e.to != p {
			dfs(g, e.to, v, d+1, parent, depth)
		}
	}
}

func (l *lca) get(u, v int) int {
	if depth[u] > depth[v] {
		u, v = v, u
	}
	for k := 0; k < log2_n; k++ {
		if (depth[v]-depth[u])>>k&1 == 1 {
			v = parent[k][v]
		}
	}
	if u == v {
		return u
	}
	for k := log2_n - 1; k >= 0; k-- {
		if parent[k][u] != parent[k][v] {
			u = parent[k][u]
			v = parent[k][v]
		}
	}
	return parent[0][u]
}

func visit(g Graph, v int, scc [][]int, S []int, inS, low, num []int, time int) int {
	low[v] = num[v] = time
	time++
	S = append(S, v)
	inS[v] = 1
	for _, e := range g[v] {
		w := e.to
		if num[w] == 0 {
			time = visit(g, w, scc, S, inS, low, num, time)
			low[v] = min(low[v], low[w])
		} else if inS[w] == 1 {
			low[v] = min(low[v], num[w])
		}
	}
	if low[v] == num[v] {
		scc = append(scc, []int{})
		for {
			w := S[len(S)-1]
			S = S[:len(S)-1]
			inS[w] = 0
			scc[len(scc)-1] = append(scc[len(scc)-1], w)
			if v == w {
				break
			}
		}
	}
	return time
}

func stronglyConnectedComponents(g Graph, scc [][]int) {
	n := len(g)
	num := make([]int, n)
	low := make([]int, n)
	inS := make([]int, n)
	S := make([]int, 0)
	time := 0
	for u := 0; u < n; u++ {
		if num[u] == 0 {
			time = visit(g, u, scc, S, inS, low, num, time)
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

type SumSegTree struct {
	n      int
	height int
	dat    []int
}

func newSumSegTree(_n int) *SumSegTree {
	n := 1
	height := 1
	for n < _n {
		n <<= 1
		height++
	}
	dat := make([]int, 2*n-1)
	return &SumSegTree{n, height, dat}
}

func (st *SumSegTree) add(i, x int) {
	i += st.n - 1
	st.dat[i] += x
	for i > 0 {
		i = (i - 1) / 2
		st.dat[i] += x
	}
}

func (st *SumSegTree) sum(a, b int) int {
	return st._sum(a, b, 0, 0, st.n)
}

func (st *SumSegTree) _sum(a, b, k, l, r int) int {
	if r <= a || b <= l {
		return 0
	}
	if a <= l && r <= b {
		return st.dat[k]
	} else {
		s1 := st._sum(a, b, 2*k+1, l, (l+r)/2)
		s2 := st._sum(a, b, 2*k+2, (l+r)/2, r)
		return s1 + s2
	}
}

type RmqTree struct {
	n      int
	height int
	dat    []int
}

func newRmqTree(_n int) *RmqTree {
	n := 1
	height := 1
	for n < _n {
		n <<= 1
		height++
	}
	dat := make([]int, 2*n-1)
	for i := 0; i < 2*n-1; i++ {
		dat[i] = INF
	}
	return &RmqTree{n, height, dat}
}

func (rt *RmqTree) update(i, x int) {
	i += rt.n - 1
	rt.dat[i] = x
	for i > 0 {
		i = (i - 1) / 2
		rt.dat[i] = min(rt.dat[i*2+1], rt.dat[i*2+2])
	}
}

func (rt *RmqTree) find(a, b int) int {
	return rt._find(a, b, 0, 0, rt.n)
}

func (rt *RmqTree) _find(a, b, k, l, r int) int {
	if r <= a || b <= l {
		return INF
	}
	if a <= l && r <= b {
		return rt.dat[k]
	} else {
		s1 := rt._find(a, b, 2*k+1, l, (l+r)/2)
		s2 := rt._find(a, b, 2*k+2, (l+r)/2, r)
		return min(s1, s2)
	}
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
		A[j] = a[i]
		id[i] = j
	}
	m := max(id...)
	b := make([]int, m+1)
	for i := n - 1; i >= 0; i-- {
		if id[i] == m {
			b[m] = a[i]
			m--
		}
	}
	return b
}

func z_algorithm(str string, z []int) bool {
	L := len(str)
	z = make([]int, len(str))
	for i, left, right := 1, 0, 0; i < L; i++ {
		if i > right {
			left, right = i, i
			for right < L && str[right-left] == str[right] {
				right++
			}
			z[i] = right - left
			right--
		} else {
			k := i - left
			if z[k] < right-i+1 {
				z[i] = z[k]
			} else {
				left = i
				for right < L && str[right-left] == str[right] {
					right++
				}
				z[i] = right - left
				right--
			}
		}
		if z[i] == s {
			return true
		}
	}
	return false
}

func z_algorithm(str string, z []int) {
	L := len(str)
	z = make([]int, len(str))
	for i, left, right := 1, 0, 0; i < L; i++ {
		if i > right {
			left, right = i, i
			for right < L && str[right-left] == str[right] {
				right++
			}
			z[i] = right - left
			right--
		} else {
			k := i - left
			if z[k] < right-i+1 {
				z[i] = z[k]
			} else {
				left = i
				for right < L && str[right-left] == str[right] {
					right++
				}
				z[i] = right - left
				right--
			}
		}
	}
}

type RollingHash struct {
	base1  int
	base2  int
	mod1   int
	mod2   int
	hash1  []int
	hash2  []int
	power1 []int
	power2 []int
}

func newRollingHash(S string) *RollingHash {
	n := len(S)
	hash1 := make([]int, n+1)
	hash2 := make([]int, n+1)
	power1 := make([]int, n+1)
	power2 := make([]int, n+1)
	hash1[0] = 0
	hash2[0] = 0
	power1[0] = 1
	power2[0] = 1
	for i := 0; i < n; i++ {
		hash1[i+1] = (hash1[i]*base1 + int(S[i])) % mod1
		hash2[i+1] = (hash2[i]*base2 + int(S[i])) % mod2
		power1[i+1] = (power1[i] * base1) % mod1
		power2[i+1] = (power2[i] * base2) % mod2
	}
	return &RollingHash{base1, base2, mod1, mod2, hash1, hash2, power1, power2}
}

func (rh *RollingHash) get(l, r int) (int, int) {
	res1 := (rh.hash1[r] - rh.hash1[l]*rh.power1[r-l]%rh.mod1 + rh.mod1) % rh.mod1
	res2 := (rh.hash2[r] - rh.hash2[l]*rh.power2[r-l]%rh.mod2 + rh.mod2) % rh.mod2
	return res1, res2
}

func (rh *RollingHash) getLCP(a, b int) int {
	len := min(len(rh.hash1)-a, len(rh.hash1)-b)
	low := 0
	high := len
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

func mod_pow(x, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}

func mod_inv(x, mod int) int {
	return mod_pow(x, mod-2, mod)
}

type Combination struct {
	fact []int
	inv  []int
	mod  int
}

func newCombination(n, mod int) *Combination {
	fact := make([]int, n+1)
	fact[0] = 1
	for i := 0; i < n; i++ {
		fact[i+1] = fact[i] * (i + 1) % mod
	}
	inv := make([]int, n+1)
	inv[n] = mod_inv(fact[n], mod)
	for i := n; i > 0; i-- {
		inv[i-1] = inv[i] * i % mod
	}
	return &Combination{fact, inv, mod}
}

func (c *Combination) nCr(n, r int) int {
	return (c.fact[n] * c.inv[r] % c.mod * c.inv[n-r]) % c.mod
}

func (c *Combination) nPr(n, r int) int {
	return (c.fact[n] * c.inv[n-r]) % c.mod
}

func (c *Combination) nHr(n, r int) int {
	return c.nCr(r+n-1, r)
}

func gcd(m, n int) int {
	if n == 0 {
		return m
	}
	return gcd(n, m%n)
}

func lcm(m, n int) int {
	return m / gcd(m, n) * n
}

type Matrix [][]int

func mIdentity(n int) Matrix {
	A := make(Matrix, n)
	for i := 0; i < n; i++ {
		A[i] = make([]int, n)
		A[i][i] = 1
	}
	return A
}

func mMul(A, B Matrix) Matrix {
	C := make(Matrix, len(A))
	for i := 0; i < len(C); i++ {
		C[i] = make([]int, len(B[0]))
	}
	for i := 0; i < len(C); i++ {
		for j := 0; j < len(C[i]); j++ {
			for k := 0; k < len(A[i]); k++ {
				C[i][j] += (A[i][k] % MOD) * (B[k][j] % MOD)
				C[i][j] %= MOD
			}
		}
	}
	return C
}

func mPow(A Matrix, e int) Matrix {
	if e == 0 {
		return mIdentity(len(A))
	} else if e%2 == 0 {
		return mPow(mMul(A, A), e/2)
	} else {
		return mMul(A, mPow(A, e-1))
	}
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

type PriorityQueue []*Item

type Item struct {
	priority int
	value    int
}

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i].priority < pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	item := x.(*Item)
	*pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	item := old[n-1]
	*pq = old[0 : n-1]
	return item
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a ...int) int {
	res := a[0]
	for _, x := range a {
		if x > res {
			res = x
		}
	}
	return res
}

const INF = 1 << 60
const MOD = 1000000007

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	t := nextInt(sc)
	for i := 0; i < t; i++ {
		n := nextInt(sc)
		m := nextInt(sc)
		a := nextInt(sc)
		b := nextInt(sc)
		a--
		b--
		g := make(Graph, n)
		for j := 0; j < m; j++ {
			u := nextInt(sc)
			v := nextInt(sc)
			u--
			v--
			addEdge(g, u, v, 1, true, 1)
		}
		used := make([]int, n)
		st := make(map[int]bool)
		dfs(g, a, b, st, used, a)
		s := 0
		t := 0
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
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	i, _ := strconv.Atoi(sc.Text())
	return i
}
