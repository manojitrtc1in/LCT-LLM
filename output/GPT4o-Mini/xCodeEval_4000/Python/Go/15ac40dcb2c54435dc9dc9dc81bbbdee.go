package main

import (
	"fmt"
	"math"
)

func divisors(M int) []int {
	d := []int{}
	i := 1
	for M >= i*i {
		if M%i == 0 {
			d = append(d, i)
			if i*i != M {
				d = append(d, M/i)
			}
		}
		i++
	}
	return d
}

func popcount(x int) int {
	x = x - ((x >> 1) & 0x55555555)
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
	x = (x + (x >> 4)) & 0x0f0f0f0f
	x = x + (x >> 8)
	x = x + (x >> 16)
	return x & 0x0000007f
}

func eratosthenes(n int) map[int]struct{} {
	res := make([]int, n+1)
	prime := make(map[int]struct{})
	for i := 2; i <= n; i++ {
		if res[i] == 0 {
			prime[i] = struct{}{}
			for j := 1; j <= n/i; j++ {
				res[i*j] = 1
			}
		}
	}
	return prime
}

func factorization(n int, prime map[int]struct{}) []int {
	res := []int{}
	for p := range prime {
		if n%p == 0 {
			for n%p == 0 {
				n /= p
			}
			res = append(res, p)
		}
	}
	if n != 1 {
		res = append(res, n)
	}
	return res
}

func eulerPhi(n int) int {
	res := n
	for x := 2; x <= n; x++ {
		if x*x > n {
			break
		}
		if n%x == 0 {
			res = res / x * (x - 1)
			for n%x == 0 {
				n /= x
			}
		}
	}
	if n != 1 {
		res = res / n * (n - 1)
	}
	return res
}

func ind(b, n int) int {
	res := 0
	for n%b == 0 {
		res++
		n /= b
	}
	return res
}

func isPrimeMR(n int) int {
	d := n - 1
	d = d / (d & -d)
	L := []int{2, 3, 5, 7, 11, 13, 17}
	for _, a := range L {
		t := d
		y := pow(a, t, n)
		if y == 1 {
			continue
		}
		for y != n-1 {
			y = (y * y) % n
			if y == 1 || t == n-1 {
				return 0
			}
			t <<= 1
		}
	}
	return 1
}

func findFactorRho(n int) int {
	m := 1 << (int(math.Log2(float64(n))) / 8)
	for c := 1; c < 99; c++ {
		f := func(x int) int {
			return (x*x + c) % n
		}
		y, r, q, g := 2, 1, 1, 1
		for g == 1 {
			x := y
			for i := 0; i < r; i++ {
				y = f(y)
			}
			k := 0
			for k < r && g == 1 {
				ys := y
				for i := 0; i < min(m, r-k); i++ {
					y = f(y)
					q = q * abs(x-y) % n
				}
				g = gcd(q, n)
				k += m
			}
			r <<= 1
		}
		if g == n {
			g = 1
			for g == 1 {
				ys = f(ys)
				g = gcd(abs(x-ys), n)
			}
		}
		if g < n {
			if isPrimeMR(g) == 1 {
				return g
			} else if isPrimeMR(n/g) == 1 {
				return n / g
			}
			return findFactorRho(g)
		}
	}
	return -1
}

func primeFactor(n int) map[int]int {
	i := 2
	ret := make(map[int]int)
	rhoFlg := 0
	for i*i <= n {
		k := 0
		for n%i == 0 {
			n /= i
			k++
		}
		if k > 0 {
			ret[i] = k
		}
		i += 1 + i%2
		if i == 101 && n >= 1<<20 {
			for n > 1 {
				if isPrimeMR(n) == 1 {
					ret[n] = 1
					n = 1
				} else {
					rhoFlg = 1
					j := findFactorRho(n)
					k = 0
					for n%j == 0 {
						n /= j
						k++
					}
					ret[j] = k
				}
			}
		}
	}
	if n > 1 {
		ret[n] = 1
	}
	if rhoFlg == 1 {
		sortedRet := make([]int, 0, len(ret))
		for k := range ret {
			sortedRet = append(sortedRet, k)
		}
		sort.Ints(sortedRet)
		newRet := make(map[int]int)
		for _, k := range sortedRet {
			newRet[k] = ret[k]
		}
		ret = newRet
	}
	return ret
}

func divisors(n int) []int {
	res := []int{1}
	prime := primeFactor(n)
	for p, count := range prime {
		newres := []int{}
		for _, d := range res {
			for j := 0; j <= count; j++ {
				newres = append(newres, d*int(math.Pow(float64(p), float64(j))))
			}
		}
		res = newres
	}
	sort.Ints(res)
	return res
}

func xorFactorial(num int) int {
	if num == 0 {
		return 0
	} else if num == 1 {
		return 1
	} else if num == 2 {
		return 3
	} else if num == 3 {
		return 0
	} else {
		x := baseOrder(num)
		return (1 << x) * ((num - (1 << x) + 1) % 2) + function(num - (1 << x))
	}
}

func xorConv(n int, X, Y []int) []int {
	if n == 0 {
		return []int{(X[0] * Y[0]) % mod}
	}
	x := make([]int, 1<<uint(n-1))
	y := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		x[i] = X[i] + X[i+1<<(n-1)]
		y[i] = Y[i] + Y[i+1<<(n-1)]
	}
	z := make([]int, 1<<uint(n-1))
	w := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		z[i] = X[i] - X[i+1<<(n-1)]
		w[i] = Y[i] - Y[i+1<<(n-1)]
	}
	res1 := xorConv(n-1, x, y)
	res2 := xorConv(n-1, z, w)
	former := make([]int, 1<<uint(n-1))
	latter := make([]int, 1<<uint(n-1))
	for i := 0; i < 1<<uint(n-1); i++ {
		former[i] = (res1[i] + res2[i]) * inv
		latter[i] = (res1[i] - res2[i]) * inv
	}
	for i := range former {
		former[i] %= mod
		latter[i] %= mod
	}
	return append(former, latter...)
}

func mergeSort(A, B []int) []int {
	posA, posB := 0, 0
	n, m := len(A), len(B)
	res := []int{}
	for posA < n && posB < m {
		a, b := A[posA], B[posB]
		if a < b {
			res = append(res, a)
			posA++
		} else {
			res = append(res, b)
			posB++
		}
	}
	res = append(res, A[posA:]...)
	res = append(res, B[posB:]...)
	return res
}

type UnionFindVerSize struct {
	parent []int
	size   []int
	group  int
}

func NewUnionFindVerSize(N int) *UnionFindVerSize {
	uf := &UnionFindVerSize{
		parent: make([]int, N),
		size:   make([]int, N),
		group:  N,
	}
	for i := range uf.parent {
		uf.parent[i] = i
		uf.size[i] = 1
	}
	return uf
}

func (uf *UnionFindVerSize) findRoot(x int) int {
	if uf.parent[x] == x {
		return x
	}
	uf.parent[x] = uf.findRoot(uf.parent[x])
	stack := []int{x}
	for uf.parent[stack[len(stack)-1]] != stack[len(stack)-1] {
		stack = append(stack, uf.parent[stack[len(stack)-1]])
	}
	for _, v := range stack {
		uf.parent[v] = stack[len(stack)-1]
	}
	return uf.parent[x]
}

func (uf *UnionFindVerSize) unite(x, y int) {
	gx := uf.findRoot(x)
	gy := uf.findRoot(y)
	if gx == gy {
		return
	}
	uf.group--
	if uf.size[gx] < uf.size[gy] {
		uf.parent[gx] = gy
		uf.size[gy] += uf.size[gx]
	} else {
		uf.parent[gy] = gx
		uf.size[gx] += uf.size[gy]
	}
}

func (uf *UnionFindVerSize) getSize(x int) int {
	return uf.size[uf.findRoot(x)]
}

func (uf *UnionFindVerSize) isSameGroup(x, y int) bool {
	return uf.findRoot(x) == uf.findRoot(y)
}

type WeightedUnionFind struct {
	parent []int
	size   []int
	val    []int
	flag   bool
	edge   [][][2]int
}

func NewWeightedUnionFind(N int) *WeightedUnionFind {
	wuf := &WeightedUnionFind{
		parent: make([]int, N),
		size:   make([]int, N),
		val:    make([]int, N),
		flag:   true,
		edge:   make([][][2]int, N),
	}
	for i := range wuf.parent {
		wuf.parent[i] = i
		wuf.size[i] = 1
	}
	return wuf
}

func (wuf *WeightedUnionFind) dfs(v, pv int) {
	stack := [][2]int{{v, pv}}
	newParent := wuf.parent[pv]
	for len(stack) > 0 {
		v, pv := stack[len(stack)-1][0], stack[len(stack)-1][1]
		stack = stack[:len(stack)-1]
		wuf.parent[v] = newParent
		for _, edge := range wuf.edge[v] {
			nv, w := edge[0], edge[1]
			if nv != pv {
				wuf.val[nv] = wuf.val[v] + w
				stack = append(stack, [2]int{nv, v})
			}
		}
	}
}

func (wuf *WeightedUnionFind) unite(x, y, w int) {
	if !wuf.flag {
		return
	}
	if wuf.parent[x] == wuf.parent[y] {
		wuf.flag = (wuf.val[x] - wuf.val[y] == w)
		return
	}
	if wuf.size[wuf.parent[x]] > wuf.size[wuf.parent[y]] {
		wuf.edge[x] = append(wuf.edge[x], [2]int{y, -w})
		wuf.edge[y] = append(wuf.edge[y], [2]int{x, w})
		wuf.size[x] += wuf.size[y]
		wuf.val[y] = wuf.val[x] - w
		wuf.dfs(y, x)
	} else {
		wuf.edge[x] = append(wuf.edge[x], [2]int{y, -w})
		wuf.edge[y] = append(wuf.edge[y], [2]int{x, w})
		wuf.size[y] += wuf.size[x]
		wuf.val[x] = wuf.val[y] + w
		wuf.dfs(x, y)
	}
}

type Dijkstra struct {
	G   [][]Edge
	E   int
	V   int
}

type Edge struct {
	to   int
	cost int
}

func NewDijkstra(V int) *Dijkstra {
	return &Dijkstra{
		G: make([][]Edge, V),
		E: 0,
		V: V,
	}
}

func (d *Dijkstra) addEdge(from, to, cost int) {
	d.G[from] = append(d.G[from], Edge{to: to, cost: cost})
	d.E++
}

func (d *Dijkstra) shortestPath(s int) []int {
	que := []struct {
		cost int
		v    int
	}{{0, s}}
	distance := make([]int, d.V)
	for i := range distance {
		distance[i] = 1e15
	}
	distance[s] = 0
	for len(que) > 0 {
		cost, v := que[0].cost, que[0].v
		que = que[1:]
		if distance[v] < cost {
			continue
		}
		for _, e := range d.G[v] {
			if distance[e.to] > distance[v]+e.cost {
				distance[e.to] = distance[v] + e.cost
				que = append(que, struct {
					cost int
					v    int
				}{distance[e.to], e.to})
			}
		}
	}
	return distance
}

func ZAlgorithm(s string) []int {
	N := len(s)
	ZAlg := make([]int, N)
	ZAlg[0] = N
	i, j := 1, 0
	for i < N {
		for i+j < N && s[j] == s[i+j] {
			j++
		}
		ZAlg[i] = j
		if j == 0 {
			i++
			continue
		}
		k := 1
		for i+k < N && k+ZAlg[k] < j {
			ZAlg[i+k] = ZAlg[k]
			k++
		}
		i += k
		j -= k
	}
	return ZAlg
}

type BIT struct {
	BIT []int
	num int
	mod int
}

func NewBIT(n, mod int) *BIT {
	return &BIT{
		BIT: make([]int, n+1),
		num: n,
		mod: mod,
	}
}

func (bit *BIT) query(idx int) int {
	resSum := 0
	mod := bit.mod
	for idx > 0 {
		resSum += bit.BIT[idx]
		if mod != 0 {
			resSum %= mod
		}
		idx -= idx & (-idx)
	}
	return resSum
}

func (bit *BIT) update(idx, x int) {
	mod := bit.mod
	for idx <= bit.num {
		bit.BIT[idx] += x
		if mod != 0 {
			bit.BIT[idx] %= mod
		}
		idx += idx & (-idx)
	}
}

type DancingLink struct {
	n      int
	debug  bool
	left   []int
	right  []int
	exist  []bool
}

func NewDancingLink(n int, debug bool) *DancingLink {
	dl := &DancingLink{
		n:     n,
		debug: debug,
		left:  make([]int, n),
		right: make([]int, n),
		exist: make([]bool, n),
	}
	for i := range dl.left {
		dl.left[i] = i - 1
		dl.right[i] = i + 1
		dl.exist[i] = true
	}
	return dl
}

func (dl *DancingLink) pop(k int) {
	if dl.debug {
		if !dl.exist[k] {
			panic("assertion failed")
		}
	}
	L := dl.left[k]
	R := dl.right[k]
	if L != -1 {
		if R != dl.n {
			dl.right[L] = R
			dl.left[R] = L
		} else {
			dl.right[L] = dl.n
		}
	} else if R != dl.n {
		dl.left[R] = -1
	}
	dl.exist[k] = false
}

func (dl *DancingLink) left(idx, k int) int {
	if dl.debug {
		if !dl.exist[idx] {
			panic("assertion failed")
		}
	}
	res := idx
	for k > 0 {
		res = dl.left[res]
		if res == -1 {
			break
		}
		k--
	}
	return res
}

func (dl *DancingLink) right(idx, k int) int {
	if dl.debug {
		if !dl.exist[idx] {
			panic("assertion failed")
		}
	}
	res := idx
	for k > 0 {
		res = dl.right[res]
		if res == dl.n {
			break
		}
		k--
	}
	return res
}

type SparseTable struct {
	table      [][]int
	mergeFunc  func(int, int) int
	ideEle     int
	size       int
}

func NewSparseTable(A []int, mergeFunc func(int, int) int, ideEle int) *SparseTable {
	N := len(A)
	n := int(math.Log2(float64(N))) + 1
	table := make([][]int, N)
	for i := range table {
		table[i] = make([]int, n)
	}
	for i := range A {
		table[i][0] = A[i]
	}
	for j := 1; j < n; j++ {
		for i := 0; i <= N-(1<<j); i++ {
			f := table[i][j-1]
			s := table[i+(1<<(j-1))][j-1]
			table[i][j] = mergeFunc(f, s)
		}
	}
	return &SparseTable{table: table, mergeFunc: mergeFunc, ideEle: ideEle, size: N}
}

func (st *SparseTable) query(s, t int) int {
	b := t - s + 1
	m := int(math.Log2(float64(b)))
	return st.mergeFunc(st.table[s][m], st.table[t-(1<<m)+1][m])
}

type BinaryTrie struct {
	root *node
}

type node struct {
	left  *node
	right *node
	max   int
}

func NewBinaryTrie() *BinaryTrie {
	return &BinaryTrie{root: &node{max: -1e15}}
}

func (bt *BinaryTrie) append(key, val int) {
	pos := bt.root
	for i := 29; i >= 0; i-- {
		pos.max = max(pos.max, val)
		if (key>>i)&1 == 1 {
			if pos.right == nil {
				pos.right = &node{max: val}
				pos = pos.right
			} else {
				pos = pos.right
			}
		} else {
			if pos.left == nil {
				pos.left = &node{max: val}
				pos = pos.left
			} else {
				pos = pos.left
			}
		}
	}
	pos.max = max(pos.max, val)
}

func (bt *BinaryTrie) search(M, xor int) int {
	res := -1e15
	pos := bt.root
	for i := 29; i >= 0; i-- {
		if pos == nil {
			break
		}
		if (M>>i)&1 == 1 {
			if (xor>>i)&1 == 1 {
				if pos.right != nil {
					res = max(res, pos.right.max)
				}
				pos = pos.left
			} else {
				if pos.left != nil {
					res = max(res, pos.left.max)
				}
				pos = pos.right
			}
		} else {
			if (xor>>i)&1 == 1 {
				pos = pos.right
			} else {
				pos = pos.left
			}
		}
	}
	if pos != nil {
		res = max(res, pos.max)
	}
	return res
}

func solveEquation(edge [][][3]int, ans []int, n, m int) []int {
	x := make([]int, m)
	used := make([]bool, n)
	for v := 0; v < n; v++ {
		if used[v] {
			continue
		}
		y := dfs(v)
		if y != 0 {
			return nil
		}
	}
	return x
}

func dfs(v int) int {
	used[v] = true
	r := ans[v]
	for _, to := range edge[v] {
		if used[to[0]] {
			continue
		}
		y := dfs(to[0])
		if to[1] == -1 {
			x[to[2]] = y
		} else {
			x[to[2]] = -y
		}
		r += y
	}
	return r
}

type SegmentTree struct {
	tree     []int
	segFunc  func(int, int) int
	ideEle   int
	num      int
	size     int
}

func NewSegmentTree(initVal []int, segFunc func(int, int) int, ideEle int) *SegmentTree {
	n := len(initVal)
	segTree := &SegmentTree{
		segFunc: segFunc,
		ideEle:  ideEle,
		num:     1 << (n - 1).bitLength(),
		tree:    make([]int, 2*(1<<(n-1).bitLength())),
		size:    n,
	}
	for i := 0; i < n; i++ {
		segTree.tree[segTree.num+i] = initVal[i]
	}
	for i := segTree.num - 1; i > 0; i-- {
		segTree.tree[i] = segTree.segFunc(segTree.tree[2*i], segTree.tree[2*i+1])
	}
	return segTree
}

func (st *SegmentTree) update(k, x int) {
	k += st.num
	st.tree[k] = x
	for k > 1 {
		st.tree[k>>1] = st.segFunc(st.tree[k], st.tree[k^1])
		k >>= 1
	}
}

func (st *SegmentTree) query(l, r int) int {
	if r == st.size {
		r = st.num
	}
	res := st.ideEle
	l += st.num
	r += st.num
	for l < r {
		if l&1 == 1 {
			res = st.segFunc(res, st.tree[l])
			l++
		}
		if r&1 == 1 {
			r--
			res = st.segFunc(res, st.tree[r])
		}
		l >>= 1
		r >>= 1
	}
	return res
}

func (st *SegmentTree) bisectL(l, r, x int) int {
	l += st.num
	r += st.num
	Lmin, Rmin := -1, -1
	for l < r {
		if l&1 == 1 {
			if st.tree[l] <= x && Lmin == -1 {
				Lmin = l
			}
			l++
		}
		if r&1 == 1 {
			if st.tree[r-1] <= x {
				Rmin = r - 1
			}
		}
		l >>= 1
		r >>= 1
	}
	if Lmin != -1 {
		pos := Lmin
		for pos < st.num {
			if st.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - st.num
	} else if Rmin != -1 {
		pos := Rmin
		for pos < st.num {
			if st.tree[2*pos] <= x {
				pos = 2 * pos
			} else {
				pos = 2*pos + 1
			}
		}
		return pos - st.num
	} else {
		return -1
	}
}

func main() {
	var n, mod int
	fmt.Scan(&n, &mod)

	M := int(math.Sqrt(float64(n))) + 10

	dp := make([]int, n+1)
	imos := make([]int, n+1)
	dp[1] = 1
	for i := 1; i < n; i++ {
		imos[i] = (imos[i] + imos[i-1]) % mod
		dp[i] = (dp[i] + imos[i]) % mod

		imos[i+1] = (imos[i+1] + dp[i]) % mod

		for j := 2; i*j <= n; j++ {
			imos[i*j] = (imos[i*j] + dp[i]) % mod
			if (i+1)*j <= n {
				imos[(i+1)*j] = (imos[(i+1)*j] - dp[i] + mod) % mod
			}
		}
	}

	res := (dp[n] + imos[n] + imos[n-1]) % mod
	fmt.Println(res)
}
